// SPDX-License-Identifier: MIT
// tb_z80_soc.v - the 6809 side of the Matenro machine in a test bench: runs the Z80 demo (os9/sub/sumz80.py, the
// binary that the C simulator runs too) on rtl/z80_soc.v the way the OS-9 command xrun does:
//   load through the window port, release the Z80, wait for "ready", send n in M2S[0], ring, read S2M[0..1].
// Pure Verilog (run with Verilator --binary --timing, see the Makefile); the image file is given as +img=file.
`timescale 1ns/1ps
module tb_z80_soc #(
    parameter CLKDIV = 9,
    parameter RAMLAT = 12
);
    reg         clk = 1'b0;
    reg         rst = 1'b1;
    reg  [2:0]  m_addr = 3'd0;
    reg         m_re = 1'b0, m_we = 1'b0;
    reg  [7:0]  m_wdata = 8'd0;
    wire [7:0]  m_rdata;
    wire        m_wait, irq_o, firq_o, con_we, pwr_we, z80_halted;
    wire [7:0]  con_data, pwr_data;

    z80_soc #(.CLKDIV(CLKDIV), .RAMLAT(RAMLAT)) dut (.*);

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

    task waitbell(input integer clocks, output integer got);
        integer i;
        begin
            got = 0;
            for (i = 0; i < clocks && !got; i = i + 1) begin
                m_addr = 3'd1; #1; tick;
                if (m_rdata & 8'h01) got = 1;
            end
        end
    endtask

    task s2m(input integer i, output [7:0] v);
        begin
            ext(8'd4 + i); mr(3'd4, v);
        end
    endtask

    task run_n(input integer n, input integer want);
        integer g;
        reg [7:0] lo, hi, rl, rh;
        begin
            ext(8'd0); mw(3'd4, n);                     // M2S[0] = n
            mw(3'd2, 8'd0);                             // ring the Z80 (maskable interrupt, IM 1 -> RST 38h)
            waitbell(4000000, g);
            check($sformatf("reply for n=%0d", n), g, 1);
            s2m(0, lo); s2m(1, hi);
            check($sformatf("1+..+%0d in S2M[0..1]", n), {hi, lo}, want);
            setwin(21'h100100);                         // the result is also in the shared RAM at sub CPU address $0100
            mr(3'd4, rl); mr(3'd4, rh);
            check($sformatf("1+..+%0d in the shared RAM", n), {rh, rl}, want);
            mw(3'd1, 8'd0);
        end
    endtask

    reg [7:0] img [0:255];
    reg [7:0] v;
    string    fname;
    integer   f, n, i, bad, g;

    initial begin
        if (!$value$plusargs("img=%s", fname)) begin
            $display("usage: Vz80_soc +img=sumz80.bin");
            $fatal(2, "no image");
        end
        f = $fopen(fname, "rb");
        if (f == 0) $fatal(2, "cannot open %s", fname);
        n = $fread(img, f);
        $fclose(f);

        for (i = 0; i < 3; i = i + 1) tick;
        rst = 1'b0; tick;
        m_addr = 3'd2; #1; tick; tick;
        check("XID", m_rdata, 1);
        check("Z80 held in reset", z80_halted, 0);

        setwin(21'h100000);                             // sub CPU address 0 = physical block $80
        for (i = 0; i < n; i = i + 1) mw(3'd4, img[i]);
        setwin(21'h100000);                             // read the image back through the window
        bad = 0;
        for (i = 0; i < n; i = i + 1) begin
            mr(3'd4, v);
            if (v != img[i]) bad = bad + 1;
        end
        check("image written and read back by the window", bad, 0);

        mw(3'd0, 8'h11);                                // RUN | IEN
        waitbell(400000, g);
        check("ready doorbell from the Z80", g, 1);
        for (i = 0; i < 1000; i = i + 1) tick;          // the Z80 rings, then executes HALT
        check("Z80 halted, waiting for the interrupt", z80_halted, 1);
        mw(3'd1, 8'd0);                                 // acknowledge

        run_n(100, 5050);
        run_n(10, 55);

        $display("z80_soc: %0d checks, %0d failed", checks, fails);
        if (fails != 0) $fatal(1, "z80_soc test failed");
        $finish;
    end
endmodule
