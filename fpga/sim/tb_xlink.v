// SPDX-License-Identifier: MIT
// tb_xlink.v - self-checking test bench of rtl/xlink.v against the behaviour of the C simulator (src/xlink.c)
// Run with Verilator (--binary --timing), see the Makefile.  Pure Verilog: there is no C++ in this repository.
`timescale 1ns/1ps
module tb_xlink;
    reg         clk = 1'b0;
    reg         rst = 1'b1;
    reg  [2:0]  m_addr = 3'd0;
    reg         m_re = 1'b0, m_we = 1'b0;
    reg  [7:0]  m_wdata = 8'd0;
    wire [7:0]  m_rdata;
    wire        m_wait, m_win, irq_n_o, firq_o, shr_o, sub_rst_n, sub_hold, sub_int, sub_nmi;
    reg         sub_halted = 1'b0, sub_clk_en = 1'b0;
    reg  [3:0]  s_port = 4'd0;
    reg         s_re = 1'b0, s_we = 1'b0;
    reg  [7:0]  s_wdata = 8'd0;
    wire [7:0]  s_rdata, s_vec;
    wire        con_we, pwr_we;
    wire [7:0]  con_data, pwr_data;
    reg  [19:0] sub_addr = 20'd0;
    reg         sub_is_z80 = 1'b1;
    wire [20:0] sub_phys;
    wire        win_req, win_wr;
    wire [20:0] win_addr;
    wire [7:0]  win_wdata;
    reg         win_ack = 1'b0;
    reg  [7:0]  win_rdata = 8'd0;

    xlink dut (.*);

    integer fails = 0, checks = 0;
    integer ack_delay = 0;
    integer cur_idx = 0;
    reg [7:0] ram [0:(1<<21)-1];

    task check(input string what, input [31:0] got, input [31:0] want);
        begin
            checks = checks + 1;
            if (got !== want) begin
                fails = fails + 1;
                $display("FAIL %-40s got %0X want %0X (check %0d)", what, got, want, checks);
            end
        end
    endtask

    // one clock; the window memory model acknowledges 2 clocks after the request, data valid with the ack
    task tick;
        begin
            win_ack = 1'b0;
            if (win_req) begin
                ack_delay = ack_delay + 1;
                if (ack_delay == 2) begin
                    win_ack = 1'b1;
                    if (win_wr) ram[win_addr] = win_wdata;
                    win_rdata = ram[win_addr];
                    ack_delay = 0;
                end
            end else ack_delay = 0;
            clk = 1'b0; #5;
            clk = 1'b1; #1;
            m_re = 1'b0; m_we = 1'b0; s_re = 1'b0; s_we = 1'b0;
            #4;
        end
    endtask

    task mw0(input [2:0] a, input [7:0] v);    // a write, without the pause after it (to see the one-clock pulses)
        begin
            m_addr = a; m_wdata = v; m_we = 1'b1; #1;
            tick;
            while (m_wait) tick;
        end
    endtask

    task mw(input [2:0] a, input [7:0] v);
        begin
            mw0(a, v);
            tick;                                  // the 6809 never makes two accesses in two clocks (XLINK decodes the index a clock late)
        end
    endtask

    task mr(input [2:0] a, output [7:0] v);
        reg [7:0] v0;
        reg       win;
        begin
            m_addr = a; #1;
            v0 = m_rdata;
            m_re = 1'b1; #1;
            tick;
            win = (a == 3'd4) && ((cur_idx & 32'h7f) == 32'h0d);
            while (m_wait) tick;
            tick;
            v = win ? win_rdata : v0;
        end
    endtask

    task mpeek(input [2:0] a, output [7:0] v);
        begin
            m_addr = a; #1;
            v = m_rdata;
        end
    endtask

    task sw(input [3:0] p, input [7:0] v);
        begin
            s_port = p; s_wdata = v; s_we = 1'b1; #1;
            tick;
        end
    endtask

    task sr(input [3:0] p, output [7:0] v);
        begin
            s_port = p; #1;
            v = s_rdata;
        end
    endtask

    task ext(input [7:0] i, input autoinc);
        begin
            cur_idx = i;
            mw(3'd3, i | (autoinc ? 8'h80 : 8'h00));
        end
    endtask

    integer k;
    reg [7:0] v, b0, b1, b2, b3;
    reg [31:0] t1, t2;

    initial begin
        for (k = 0; k < 3; k = k + 1) tick;
        rst = 1'b0; tick;

        mpeek(3'd2, v);
        check("XID", v, 1);
        check("sub in reset", sub_rst_n, 0);
        mw(3'd0, 8'h19);                                   // RUN | FIRQ | IEN
        check("sub released", sub_rst_n, 1);
        mpeek(3'd0, v); check("XCTL read", v, 8'h19);

        // mailbox with auto increment
        ext(0, 1);
        for (k = 0; k < 4; k = k + 1) mw(3'd4, 8'h10 + k);
        sr(4'd4, v); check("M2S[0] seen by sub", v, 8'h10);
        sr(4'd7, v); check("M2S[3] seen by sub", v, 8'h13);
        mpeek(3'd3, v); check("index after 4 accesses", v, 8'h84);

        // doorbell main -> sub
        mw(3'd2, 8'h00);
        check("sub INT asserted", sub_int, 1);
        sr(4'd1, v); check("sub stat bit0", v, 8'h81);
        sw(4'd3, 8'h00);
        check("sub INT cleared by ACK", sub_int, 0);
        mw0(3'd2, 8'h80);
        check("NMI pulse", sub_nmi, 1); tick; check("NMI pulse is one clock", sub_nmi, 0);

        // doorbell sub -> main (FIRQ)
        sw(4'd8, 8'hBA); sw(4'd9, 8'h13);
        check("no FIRQ yet", firq_o, 0);
        sw(4'd2, 8'h00);
        check("FIRQ after the bell", firq_o, 1); check("IRQ not used", irq_n_o, 0);
        mpeek(3'd1, v); check("XSTAT S2M", v & 8'h01, 1);
        ext(4, 1);
        mr(3'd4, v); check("S2M[0] read by 6809", v, 8'hBA);
        mr(3'd4, v); check("S2M[1] read by 6809 (auto inc)", v, 8'h13);
        mw(3'd1, 8'h00);
        check("FIRQ cleared by ACK", firq_o, 0);
        mw(3'd0, 8'h01);                                   // IRQ mode, IEN off
        sw(4'd2, 8'h00); check("no interrupt with IEN=0", firq_o | irq_n_o, 0);
        mw(3'd0, 8'h11); check("IRQ with IEN=1", irq_n_o, 1);
        mw(3'd1, 8'h00);

        // vector byte, id, console, power
        sw(4'hc, 8'h20); check("svec", s_vec, 8'h20); sr(4'hc, v); check("svec readback", v, 8'h20);
        sr(4'd0, v); check("sub id port", v, 1);
        sw(4'he, "A"); check("console strobe", con_we, 1); check("console data", con_data, "A");
        tick; check("console strobe one clock", con_we, 0);
        sw(4'hf, 8'ha5); check("power strobe", pwr_we, 1); check("power data", pwr_data, 8'ha5);

        // SMMU
        sub_addr = 20'h0123; #1;
        check("reset map block 0 -> $80", sub_phys, (32'h80 << 13) | 32'h123);
        ext(8, 0); mw(3'd4, 8'h05); ext(9, 0); mw(3'd4, 8'h42);
        sub_addr = 20'hA123; #1;
        check("block 5 -> $42", sub_phys, (32'h42 << 13) | 32'h123);
        ext(9, 0); mr(3'd4, v); check("XE_MD read", v, 8'h42);
        sub_is_z80 = 1'b0; sub_addr = 20'hFFFF0; #1;
        check("8088 reset vector in block 127 -> $FF", sub_phys, (32'hFF << 13) | 32'h1FF0);
        sub_is_z80 = 1'b1;

        // window
        ext(8'h0a, 1); mw(3'd4, 8'h10); mw(3'd4, 8'h01); mw(3'd4, 8'h00);   // physical $100100
        ext(8'h0d, 0);
        for (k = 0; k < 4; k = k + 1) mw(3'd4, 8'hC0 + k);
        check("window wrote RAM", ram[21'h100100], 8'hC0); check("window wrote RAM +3", ram[21'h100103], 8'hC3);
        ext(8'h0a, 1); mw(3'd4, 8'h10); mw(3'd4, 8'h01); mw(3'd4, 8'h00);
        ext(8'h0d, 0);
        mr(3'd4, v); check("window read 0", v, 8'hC0);
        mr(3'd4, v); check("window read 1", v, 8'hC1);
        ext(8'h0a, 1);
        mr(3'd4, b2); mr(3'd4, b1); mr(3'd4, b0);
        check("window address after 2 reads", {b2, b1, b0}, 32'h100102);

        // clock info and counter
        ext(8'h0e, 1); mr(3'd4, b1); mr(3'd4, b0);
        check("XE_KHZ", {b1, b0}, 7500);
        for (k = 0; k < 1000; k = k + 1) begin sub_clk_en = 1'b1; tick; end
        sub_clk_en = 1'b0; tick;
        ext(8'h10, 1); mr(3'd4, b3); mr(3'd4, b2); mr(3'd4, b1); mr(3'd4, b0);
        check("clock counter", {b3, b2, b1, b0}, 1000);

        // microsecond counter: 1 per 67.5 clocks (CLK_KHZ = 67500), latched on the read of byte 0
        ext(8'h14, 1); mr(3'd4, b3); mr(3'd4, b2); mr(3'd4, b1); mr(3'd4, b0);
        t1 = {b3, b2, b1, b0};
        for (k = 0; k < 2000; k = k + 1) tick;
        ext(8'h14, 1); mr(3'd4, b3); mr(3'd4, b2); mr(3'd4, b1); mr(3'd4, b0);
        t2 = {b3, b2, b1, b0};
        check("XE_US: about 30 microseconds in 2000+ clocks", (t2 - t1 >= 29) && (t2 - t1 <= 31), 1);

        // reset pulse
        mw0(3'd0, 8'h99);
        check("XC_RESET pulse", sub_rst_n, 0); tick; tick;
        check("reset released again", sub_rst_n, 1);
        // halted / status
        sub_halted = 1'b1; mpeek(3'd1, v);
        check("XSTAT run+halt", v & 8'h0c, 8'h0c);

        $display("xlink RTL: %0d checks, %0d failed", checks, fails);
        if (fails != 0) $fatal(1, "xlink RTL test failed");
        $finish;
    end
endmodule
