// SPDX-License-Identifier: MIT
// tb_sdram.v - sdram_ctl.v against sdram_model.v: random reads and writes (bytes and words) at random gaps, compared with a reference array;
// the gaps are long enough for refreshes, and some requests are made during a refresh.
`timescale 1ns/1ps
module tb_sdram;
    reg clk = 0, resetn = 0;
    wire clk_sdram = ~clk;
    reg rd = 0, wr = 0, bw = 0;
    reg [21:0] addr = 0;
    reg [15:0] din = 0;
    wire [15:0] dout;
    wire busy;
    wire cke, cs_n, cas_n, ras_n, wen_n, sdclk;
    wire [3:0] dqm;
    wire [10:0] sa;
    wire [1:0] sba;
    wire [31:0] dq;
    wire [31:0] errors;
    wire init_done;

    sdram_ctl #(.FREQ(67_500_000)) dut (.clk(clk), .clk_sdram(clk_sdram), .resetn(resetn), .read(rd), .write(wr), .addr(addr), .din(din), .byte_write(bw), .wide(wide), .dout32(dout32),
        .dout(dout), .busy(busy), .O_sdram_clk(sdclk), .O_sdram_cke(cke), .O_sdram_cs_n(cs_n), .O_sdram_cas_n(cas_n), .O_sdram_ras_n(ras_n),
        .O_sdram_wen_n(wen_n), .O_sdram_dqm(dqm), .O_sdram_addr(sa), .O_sdram_ba(sba), .IO_sdram_dq(dq));
    sdram_model mdl (.clk(sdclk), .cke(cke), .cs_n(cs_n), .ras_n(ras_n), .cas_n(cas_n), .we_n(wen_n), .dqm(dqm), .a(sa), .ba(sba), .dq(dq),
        .errors(errors), .init_done(init_done));

    always #7.4 clk = ~clk;

    reg [7:0] ref_mem [0:(1<<16)-1];            // reference of the first 64 KB and of a window at 2 MB
    integer fails = 0, checks = 0, i, n, gap;
    reg [21:0] a;
    reg [15:0] expw;
    reg [7:0]  b;
    reg        wide = 1'b0;
    wire [31:0] dout32;

    task do_write_byte(input [21:0] ad, input [7:0] v);
        begin
            while (busy) @(posedge clk);
            @(posedge clk); addr <= ad; din <= {v, v}; bw <= 1; wr <= 1; @(posedge clk); wr <= 0;
            ref_mem[ad[15:0]] = v;
        end
    endtask
    task do_write_word(input [21:0] ad, input [15:0] v);
        begin
            while (busy) @(posedge clk);
            @(posedge clk); addr <= {ad[21:1], 1'b0}; din <= v; bw <= 0; wr <= 1; @(posedge clk); wr <= 0;
            ref_mem[{ad[15:1], 1'b0}] = v[7:0]; ref_mem[{ad[15:1], 1'b1}] = v[15:8];
        end
    endtask
    task do_read_check(input [21:0] ad);
        reg [15:0] e;
        begin
            while (busy) @(posedge clk);
            @(posedge clk); addr <= ad; rd <= 1; @(posedge clk); rd <= 0;
            @(posedge clk); @(posedge clk);
            while (busy) @(posedge clk);
            e = {ref_mem[{ad[15:1], 1'b1}], ref_mem[{ad[15:1], 1'b0}]};
            checks = checks + 1;
            if (dout !== e) begin fails = fails + 1; if (fails < 10) $display("FAIL read %06X got %04X want %04X", ad, dout, e); end
        end
    endtask

    task do_wide_check(input [21:0] ad);               // a wide read (the frame buffer): dout32 is the 32 bit word, dout is not touched
        reg [31:0] e;
        reg [15:0] keep;
        integer k;
        begin
            while (busy) @(posedge clk);
            keep = dout;
            @(posedge clk); addr <= {ad[21:2], 2'd0}; wide <= 1; rd <= 1; @(posedge clk); rd <= 0; wide <= 0;
            @(posedge clk); @(posedge clk);
            while (busy) @(posedge clk);
            for (k = 0; k < 4; k = k + 1) e[8 * k +: 8] = ref_mem[{ad[15:2], 2'd0} + k];
            checks = checks + 2;
            if (dout32 !== e) begin fails = fails + 1; if (fails < 10) $display("FAIL wide read %06X got %08X want %08X", ad, dout32, e); end
            if (dout !== keep) begin fails = fails + 1; if (fails < 10) $display("FAIL a wide read changed dout %04X -> %04X", keep, dout); end
        end
    endtask

    initial begin
        for (i = 0; i < (1<<16); i = i + 1) ref_mem[i] = 8'h00;
        repeat (4) @(posedge clk);
        resetn = 1;
        wait (init_done);
        repeat (4) @(posedge clk);
        check_busy: begin end
        // fill the first 64 KB with bytes, in a scrambled order and with a few words
        for (i = 0; i < 4096; i = i + 1) begin
            a = ($urandom % 65536);
            if (i % 5 == 0) do_write_word(a, $urandom); else do_write_byte(a, $urandom);
            if (i % 97 == 0) repeat ($urandom % 1500) @(posedge clk);   // a gap: refreshes happen, and requests arrive during them
        end
        for (i = 0; i < 4096; i = i + 1) begin
            do_read_check($urandom % 65536);
            if (i % 131 == 0) repeat ($urandom % 900) @(posedge clk);
        end
        // a request at every clock the controller is idle (back to back), including the refresh moments
        for (i = 0; i < 20000; i = i + 1) begin
            a = $urandom % 65536;
            if (i & 1) do_write_byte(a, i[7:0]); else do_read_check(a);
        end
        // wide reads (the frame buffer), in between writes and single reads, back to back, with refreshes
        for (i = 0; i < 6000; i = i + 1) begin
            a = $urandom % 65536;
            case (i % 4)
            0: do_wide_check(a);
            1: do_wide_check(a);
            2: do_write_byte(a, i[7:0]);
            default: do_read_check(a);
            endcase
            if (i % 211 == 0) repeat ($urandom % 800) @(posedge clk);
        end
        // the upper part of the 4 MB window: the address bits of the bank and the row
        do_write_byte(22'h3fffff, 8'h5a); do_write_byte(22'h200001, 8'ha5); do_write_byte(22'h100000, 8'h11);
        do_write_byte(22'h0ffffe, 8'h22);
        n = 0;
        begin : hi
            reg [15:0] w;
            while (busy) @(posedge clk);
            @(posedge clk); addr <= 22'h3ffffe; rd <= 1; @(posedge clk); rd <= 0; @(posedge clk); @(posedge clk); while (busy) @(posedge clk);
            checks = checks + 1; if (dout[15:8] !== 8'h5a) begin fails = fails + 1; $display("FAIL high address read %04X", dout); end
            @(posedge clk); addr <= 22'h200000; rd <= 1; @(posedge clk); rd <= 0; @(posedge clk); @(posedge clk); while (busy) @(posedge clk);
            checks = checks + 1; if (dout[15:8] !== 8'ha5) begin fails = fails + 1; $display("FAIL 2 MB read %04X", dout); end
            @(posedge clk); addr <= 22'h100000; rd <= 1; @(posedge clk); rd <= 0; @(posedge clk); @(posedge clk); while (busy) @(posedge clk);
            checks = checks + 1; if (dout[7:0] !== 8'h11) begin fails = fails + 1; $display("FAIL 1 MB read %04X", dout); end
        end
        checks = checks + 1;
        if (errors != 0) begin fails = fails + 1; $display("FAIL the model found %0d rule violations", errors); end
        $display("sdram_ctl: %0d checks, %0d failed, %0d model errors", checks, fails, errors);
        if (fails != 0) $fatal(1, "sdram test failed");
        $finish;
    end
endmodule
