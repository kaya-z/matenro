// SPDX-License-Identifier: MIT
// sim_top.v - the test bench's top level of the Tang Nano 20K machine for Verilator (sim09's tb.cpp): matenro_soc with `define SUB8088
// (6809 + 8088 / MCL86), the SDRAM controller (sdram_ctl.v) and the SDRAM model, no HDMI.  The SDRAM clock is the system clock inverted
// (on the board: the PLL output 180 degrees off).
module sim_top #(
    parameter PH_DIV = 9,
    parameter C88_DIV = 14,
    parameter CZ_DIV = 9,
    parameter CLK_HZ = 67_500_000,
    parameter [15:0] ROM_BASE = 16'hF000,
    parameter ROM_AW = 12,
    parameter ROM_FILE = "rom.hex",
    parameter FREERUN = 0,
    parameter MEMTEST = 0,
    parameter [21:0] MT_LAST = 22'h3fff
) (
    input  wire        clk,
    input  wire        resetn,
    input  wire        rxd,
    output wire        txd,
    output wire        sd_clk,
    output wire        sd_mosi,
    input  wire        sd_miso,
    output wire        sd_cs,
    output wire [5:0]  led,
    output wire        fl_cs, fl_clk, fl_mosi,
    input  wire        fl_miso,
    output wire        kanji_ok,
    output wire        term_stb,
    output wire [7:0]  term_byte,
    output wire [111:0] dbg_regs,
    output wire        dbg_lic,
    output wire [15:0] dbg_addr,
    output wire        dbg_acc,
    output wire [7:0]  dbg_din,
    output wire        dbg_rnw,
    output wire        dbg_vma,
    output wire        dbg_ps_rd,
    output wire        dbg_ps_wr,
    output wire [21:0] dbg_ps_addr
);
    assign fl_cs = 1'b1, fl_clk = 1'b0, fl_mosi = 1'b0, kanji_ok = 1'b0;
    wire        ps_rd, ps_wr, ps_bw, ps_busy;
    wire [21:0] ps_addr;
    wire [15:0] ps_din, ps_dout;
    wire        clk_sdram = ~clk;

    matenro_soc #(.CLK_HZ(CLK_HZ), .C88_DIV(C88_DIV), .CZ_DIV(CZ_DIV), .PH_DIV(PH_DIV), .ROM_BASE(ROM_BASE), .ROM_AW(ROM_AW), .ROM_FILE(ROM_FILE), .FREERUN(FREERUN), .MEMTEST(MEMTEST), .MT_LAST(MT_LAST)) soc (
        .clk(clk), .resetn(resetn), .rxd(rxd), .txd(txd),
        .sd_clk(sd_clk), .sd_mosi(sd_mosi), .sd_miso(sd_miso), .sd_cs(sd_cs),
        .ps_rd(ps_rd), .ps_wr(ps_wr), .ps_addr(ps_addr), .ps_din(ps_din), .ps_bw(ps_bw),
        .ps_dout(ps_dout), .ps_busy(ps_busy),
        .led(led), .led_mode(1'b0), .reboot_req(), .dbg_status(), .dbg_disk(), .term_busy(1'b0),
        .x1_req(1'b0), .x1_addr(22'd0), .x1_ack(), .x1_rdata(),
        .x2_req(1'b0), .x2_addr(22'd0), .x2_ack(), .x2_rdata(),
        .term_stb(term_stb), .term_byte(term_byte), .dbg_regs(dbg_regs), .dbg_lic(dbg_lic), .dbg_addr(dbg_addr), .dbg_acc(dbg_acc), .dbg_din(dbg_din),
        .dbg_rnw(dbg_rnw), .dbg_vma(dbg_vma), .dbg_z80(), .dbg_stall(), .dbg_dbus()
    );

    assign dbg_ps_rd = ps_rd, dbg_ps_wr = ps_wr, dbg_ps_addr = ps_addr;

    wire sd_ck, sd_cke, sd_cs_n, sd_cas_n, sd_ras_n, sd_we_n, mdl_init;
    wire [3:0]  sd_dqm;
    wire [10:0] sd_a;
    wire [1:0]  sd_ba;
    wire [31:0] sd_dq, mdl_err;
    sdram_ctl #(.FREQ(CLK_HZ), .REFRESH_CLKS(CLK_HZ / 1000 * 74 / 10000)) sdram (
        .clk(clk), .clk_sdram(clk_sdram), .resetn(resetn),
        .read(ps_rd), .write(ps_wr), .addr(ps_addr), .din(ps_din), .byte_write(ps_bw), .dout(ps_dout), .busy(ps_busy),
        .O_sdram_clk(sd_ck), .O_sdram_cke(sd_cke), .O_sdram_cs_n(sd_cs_n), .O_sdram_cas_n(sd_cas_n), .O_sdram_ras_n(sd_ras_n),
        .O_sdram_wen_n(sd_we_n), .O_sdram_dqm(sd_dqm), .O_sdram_addr(sd_a), .O_sdram_ba(sd_ba), .IO_sdram_dq(sd_dq)
    );
    sdram_model mdl (.clk(sd_ck), .cke(sd_cke), .cs_n(sd_cs_n), .ras_n(sd_ras_n), .cas_n(sd_cas_n), .we_n(sd_we_n), .dqm(sd_dqm), .a(sd_a), .ba(sd_ba),
        .dq(sd_dq), .errors(mdl_err), .init_done(mdl_init));
    always @(posedge clk) if (mdl_err != 32'd0 && mdl_err[3:0] == 4'd1) $display("SDRAM model: rule violations = %0d", mdl_err);

`ifdef TRACE88
    always @(posedge clk) if (soc.zm_ack) $display("%s %h %h", soc.zm_wr ? "W" : "R", soc.zm_addr, soc.zm_wr ? soc.zm_wdata : soc.zm_rdata);
`endif
`ifdef DUMPKJ
    // when the kanji image is declared valid (HCTL bit 0 set by the OS-9 command kanjild): the first 185,856 bytes at $200000 of the SDRAM model
    integer kfd, kk;
    reg [21:0] kba;
    reg [19:0] kw;
    reg [31:0] kdw;
    always @(negedge soc.win_hi) begin
        kfd = $fopen("kjdump.bin", "wb");
        for (kk = 0; kk < 185856; kk = kk + 1) begin
            kba = 22'h200000 + kk;
            kw = kba[21:2];
            kdw = mdl.mem[{kw[9:8], 1'b0, kw[19:10], kw[7:0]}];
            $fwrite(kfd, "%c", kdw[8 * kba[1:0] +: 8]);
        end
        $fclose(kfd);
        $display("KJDUMP written");
    end
`endif
`ifdef DUMPMEM
    always @(posedge clk) if (ps_wr && ps_addr >= 22'h100404 && ps_addr < 22'h10040c) $display("WR %h din=%h bw=%b", ps_addr, ps_din, ps_bw);
    // at the end: the bytes 0x100400 ... of the SDRAM model, to compare with the image that the 6809 loaded
    integer fd, k;
    reg [21:0] ba_;
    reg [19:0] w_;
    reg [31:0] dw_;
    always @(posedge soc.pwroff) begin
        fd = $fopen("memdump.txt", "w");
        for (k = 0; k < 3072; k = k + 1) begin
            ba_ = 22'h100400 + k;
            w_ = ba_[21:2];
            dw_ = mdl.mem[{w_[9:8], 1'b0, w_[19:10], w_[7:0]}];
            $fwrite(fd, "%02x\n", (dw_ >> (8 * ba_[1:0])) & 8'hff);
        end
        $fclose(fd);
    end
`endif
endmodule
