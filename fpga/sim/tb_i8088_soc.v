// SPDX-License-Identifier: MIT
// tb_i8088_soc.v - the 6809 side of the Matenro machine in a test bench: runs the self checking 8088 program tests/i8088/core.asm
// (built with nasm -DHWPORTS) on rtl/i8088_soc.v (MCL86): load it through the window port at the 8088 address $0400 (physical $100400 with
// the default SMMU), put the reset vector JMP 0000:0400 at FFFF0 (physical $1FFFF0), release the 8088 and wait for the power-off write:
//   $A5 = all checks passed, $A6 = failed (the id of the check was written to port $0E).
// Pure Verilog (run with Verilator --binary --timing, see the Makefile); the image file is given as +img=file.
`timescale 1ns/1ps
module tb_i8088_soc #(
    parameter CLKDIV = 14,
    parameter RAMLAT = 12
);
    reg         clk = 1'b0;
    reg         rst = 1'b1;
    reg  [2:0]  m_addr = 3'd0;
    reg         m_re = 1'b0, m_we = 1'b0;
    reg  [7:0]  m_wdata = 8'd0;
    wire [7:0]  m_rdata;
    wire        m_wait, m_win, sub_on, irq_o, firq_o, con_we, pwr_we, z80_halted;
    wire [7:0]  con_data, pwr_data;

    i8088_soc #(.CLKDIV(CLKDIV), .RAMLAT(RAMLAT)) dut (.*);

    integer fails = 0, checks = 0;

    task check(input string what, input [31:0] got, input [31:0] want);
        begin
            checks = checks + 1;
            if (got !== want) begin
                fails = fails + 1;
                $display("FAIL %-44s got %0X want %0X (check %0d)", what, got, want, checks);
            end
        end
    endtask

    task tick;
        begin
            clk = 1'b0; #5;
            clk = 1'b1; #1;
            m_re = 1'b0; m_we = 1'b0;
            #4;
        end
    endtask

    task mw(input [2:0] a, input [7:0] v);
        begin
            m_addr = a; m_wdata = v; m_we = 1'b1; #1;
            tick;
            while (m_wait) tick;
            tick;                                  // the 6809 never makes two accesses in two clocks (XLINK decodes the index a clock late)
        end
    endtask

    task mr(input [2:0] a, output [7:0] v);
        begin
            m_addr = a; m_re = 1'b1; #1;
            tick;
            while (m_wait) tick;
            m_addr = a; #1;
            tick; tick;
            v = m_rdata;
            tick;                       // after the stall of a window read the data is there
        end
    endtask

    task ext(input [7:0] i);
        begin
            mw(3'd3, i);
        end
    endtask

    task setwin(input [20:0] a);
        begin
            ext(8'h0a); mw(3'd4, {3'b0, a[20:16]});
            ext(8'h0b); mw(3'd4, a[15:8]);
            ext(8'h0c); mw(3'd4, a[7:0]);
            ext(8'h0d);
        end
    endtask


    // watch the console / power ports of the 8088 (ports $0E, $0F)
    reg [7:0] con_id = 8'd0;
    reg       con_seen = 1'b0, pwr_seen = 1'b0;
    reg [7:0] pwr_val = 8'd0;
    always @(posedge clk) begin
        if (con_we) begin con_id <= con_data; con_seen <= 1'b1; end
        if (pwr_we) begin pwr_val <= pwr_data; pwr_seen <= 1'b1; end
    end

    reg [7:0] img [0:4095];
    reg [7:0] v;
    string    fname;
    integer   f, n, i, bad, w;

    initial begin
        if (!$value$plusargs("img=%s", fname)) begin
            $display("usage: Vi8088_soc +img=core_hw.bin");
            $fatal(2, "no image");
        end
        f = $fopen(fname, "rb");
        if (f == 0) $fatal(2, "cannot open %s", fname);
        n = $fread(img, f);
        $fclose(f);

        for (i = 0; i < 3; i = i + 1) tick;
        rst = 1'b0; tick;
        m_addr = 3'd2; #1; tick; tick;
        check("XID is 2 (8088)", m_rdata, 2);
        check("8088 held in reset", sub_on, 0);

        setwin(21'h100400);                             // 8088 address $0400
        for (i = 0; i < n; i = i + 1) mw(3'd4, img[i]);
        setwin(21'h100400);
        bad = 0;
        for (i = 0; i < n; i = i + 1) begin
            mr(3'd4, v);
            if (v != img[i]) bad = bad + 1;
        end
        check("image written and read back by the window", bad, 0);

        setwin(21'h1ffff0);                             // the reset vector, FFFF:0000 = $FFFF0
        mw(3'd4, 8'hEA); mw(3'd4, 8'h00); mw(3'd4, 8'h04); mw(3'd4, 8'h00); mw(3'd4, 8'h00);     // JMP FAR 0000:0400

        mw(3'd0, 8'h01);                                // RUN
        w = 0;
        // (like the 6809 of the machine, which reads XSTAT in a loop meanwhile; +nopoll: only wait)
        while (!pwr_seen && w < 60000000) begin
            if ($test$plusargs("nopoll")) begin tick; w = w + 1; end
            else begin mr(3'd1, v); w = w + 20; end
        end
        check("the 8088 powered off", pwr_seen, 1);
        check("no failing check reported on port $0E", con_seen, 0);
        check("power-off byte $A5 (all checks passed)", pwr_val, 8'ha5);
        if (con_seen) $display("failing check id = %0d", con_id);
        $display("i8088_soc: %0d checks, %0d failed, %0d clocks", checks, fails, w);
        if (fails != 0) $fatal(1, "i8088_soc test failed");
        $finish;
    end
endmodule
