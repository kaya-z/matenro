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
    wire        ps_issue, gfx_on, gfx_ov, pal_we, term_busy;
    wire [7:0]  pal_idx;
    wire [23:0] pal_rgb;
    wire        x1_req, x1_ack, x2_req, x2_ack;
    wire [21:0] x1_addr, x2_addr;
    wire [15:0] x1_rdata, x2_rdata;
    wire        ctl_busy;
    wire [31:0] fb_dout32;
`ifdef FBSOC
    // the HDMI screen with the frame buffer on the SoC (as in tn20k_top.v): to try the read of the frame buffer against the requests of the SoC.
    // The pixel clock is the system clock divided by two here (the timing of the picture is of no interest, the traffic on the SDRAM is)
    wire        fb_rq, fb_go;
    wire [21:0] fb_addr;
    reg         clk_pix = 1'b0;
    always @(posedge clk) clk_pix <= ~clk_pix;
    reg [3:0]   rpx = 4'hf;
    always @(posedge clk_pix) rpx <= {rpx[2:0], ~resetn};
    wire [9:0]  tmds_b, tmds_g, tmds_r;
`ifdef FBFIX
    assign      fb_go = fb_rq && !ctl_busy && !ps_rd && !ps_wr && !ps_issue;
`else
    assign      fb_go = fb_rq && !ctl_busy && !ps_rd && !ps_wr;               // (the first version: it can slip in between the decision and the pulse of the arbiter)
`endif
    assign      ps_busy = ctl_busy || fb_go;
    hdmi_screen20 #(.ROWS(25), .CHARSET(0), .FONT_FILE("font8x16.hex")) screen (
        .clk(clk), .rst(~resetn), .stb(term_stb), .din(term_byte), .busy(term_busy), .kanji_ok(1'b0),
        .x1_req(x1_req), .x1_addr(x1_addr), .x1_ack(x1_ack), .x1_rdata(x1_rdata),
        .x2_req(x2_req), .x2_addr(x2_addr), .x2_ack(x2_ack), .x2_rdata(x2_rdata),
        .clk_pix(clk_pix), .rst_pix(rpx[3]), .tmds_b(tmds_b), .tmds_g(tmds_g), .tmds_r(tmds_r),
        .gfx_on(gfx_on), .gfx_ov(gfx_ov), .pal_we(pal_we), .pal_idx(pal_idx), .pal_rgb(pal_rgb),
        .fb_rq(fb_rq), .fb_addr(fb_addr), .fb_go(fb_go), .fb_busy(ctl_busy), .fb_dout32(fb_dout32)
    );
`else
    wire        fb_go = 1'b0;
    wire [21:0] fb_addr = 22'd0;
    assign      ps_busy = ctl_busy;
    assign      term_busy = 1'b0, x1_req = 1'b0, x1_addr = 22'd0, x2_req = 1'b0, x2_addr = 22'd0;
`endif

    matenro_soc #(.CLK_HZ(CLK_HZ), .C88_DIV(C88_DIV), .CZ_DIV(CZ_DIV), .PH_DIV(PH_DIV), .ROM_BASE(ROM_BASE), .ROM_AW(ROM_AW), .ROM_FILE(ROM_FILE), .FREERUN(FREERUN), .MEMTEST(MEMTEST), .MT_LAST(MT_LAST)) soc (
        .clk(clk), .resetn(resetn), .rxd(rxd), .txd(txd),
        .sd_clk(sd_clk), .sd_mosi(sd_mosi), .sd_miso(sd_miso), .sd_cs(sd_cs),
        .ps_rd(ps_rd), .ps_wr(ps_wr), .ps_addr(ps_addr), .ps_din(ps_din), .ps_bw(ps_bw),
        .ps_dout(ps_dout), .ps_busy(ps_busy),
        .led(led), .led_mode(1'b0), .reboot_req(), .dbg_status(), .dbg_disk(), .term_busy(term_busy), .ps_issue(ps_issue),
        .gfx_on(gfx_on), .gfx_ov(gfx_ov), .pal_we(pal_we), .pal_idx(pal_idx), .pal_rgb(pal_rgb),
        .x1_req(x1_req), .x1_addr(x1_addr), .x1_ack(x1_ack), .x1_rdata(x1_rdata),
        .x2_req(x2_req), .x2_addr(x2_addr), .x2_ack(x2_ack), .x2_rdata(x2_rdata),
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
        .read(ps_rd || fb_go), .write(ps_wr), .addr(fb_go ? fb_addr : ps_addr), .din(ps_din), .byte_write(ps_bw), .wide(fb_go), .dout(ps_dout), .dout32(fb_dout32), .busy(ctl_busy),
        .O_sdram_clk(sd_ck), .O_sdram_cke(sd_cke), .O_sdram_cs_n(sd_cs_n), .O_sdram_cas_n(sd_cas_n), .O_sdram_ras_n(sd_ras_n),
        .O_sdram_wen_n(sd_we_n), .O_sdram_dqm(sd_dqm), .O_sdram_addr(sd_a), .O_sdram_ba(sd_ba), .IO_sdram_dq(sd_dq)
    );
    sdram_model mdl (.clk(sd_ck), .cke(sd_cke), .cs_n(sd_cs_n), .ras_n(sd_ras_n), .cas_n(sd_cas_n), .we_n(sd_we_n), .dqm(sd_dqm), .a(sd_a), .ba(sd_ba),
        .dq(sd_dq), .errors(mdl_err), .init_done(mdl_init));
    always @(posedge clk) if (mdl_err != 32'd0 && mdl_err[3:0] == 4'd1) $display("SDRAM model: rule violations = %0d", mdl_err);

`ifdef TRACE88
    always @(posedge clk) if (soc.zm_ack) $display("%s %h %h", soc.zm_wr ? "W" : "R", soc.zm_addr, soc.zm_wr ? soc.zm_wdata : soc.zm_rdata);
`endif
`ifdef FBDBG
    integer fbc = 0, term_stb_n = 0;
    always @(posedge clk) if (term_stb) term_stb_n = term_stb_n + 1;
    integer n_fbgo = 0, n_soc = 0, n_idle = 0, n_fbrq = 0;
    always @(posedge clk) begin
        if (fb_go) n_fbgo = n_fbgo + 1;
        if (ps_rd || ps_wr) n_soc = n_soc + 1;
        if (!ctl_busy) n_idle = n_idle + 1;
        if (fb_rq) n_fbrq = n_fbrq + 1;
    end
    always @(posedge clk) begin
        fbc = fbc + 1;
        if (fbc % 20000000 == 0 || fbc == 900000000)
            $display("[%0d] arb st=%0d sel=%0d ctl st=%0d busy=%b pend=%b fb: st=%0d rq=%b got=%0d need=%0d y2=%0d gfx=%b m3=%b m1=%b m2=%b m0=%b",
                fbc, soc.arb.st, soc.arb.sel, sdram.st, ctl_busy, sdram.req_pend, screen.fb.st, screen.fb.rq, screen.fb.got, screen.fb.need, screen.fb.y2, gfx_on,
                soc.zm_req, x1_req, x2_req, soc.m0_req);
        if (fbc % 20000000 == 0) begin
            $display("      counts: fb reads=%0d soc accesses=%0d ctl idle clocks=%0d fb_rq clocks=%0d", n_fbgo, n_soc, n_idle, n_fbrq);
            n_fbgo = 0; n_soc = 0; n_idle = 0; n_fbrq = 0;
        end
        if (fbc % 20000000 == 0 || fbc == 900000000)
            $display("      term_busy=%b hold=%0d bs=%b busy_p=%b dec_busy=%b acia_pend=%b stb_count=%0d mem_pend=%b mp_wait=%b stall=%b xl_wait=%b xw_act=%b win_req=%b disk_busy=%b a=%h rnw=%b vma_pend=%b acia_irq=%b timer_irq=%b xl_irq=%b disk_irq=%b tx_full=%b", term_busy, screen.hold, screen.bs, screen.busy_p, screen.dec_busy, soc.acia_pend, term_stb_n, soc.mem_pend, soc.mp_wait, soc.stall, soc.xl_wait, soc.xw_act, soc.win_req, soc.disk_busy, soc.a, soc.cpu_rnw, soc.vma_pend, soc.acia_irq, soc.timer_irq, soc.xl_irq, soc.disk_irq, soc.acia_tx_full);
    end
`endif
`ifdef DBGIO
    integer dbgn = 0;
    always @(posedge clk) if (soc.acc2 && soc.vma_pend && soc.in_io_q && soc.off_q >= 9'h060 && soc.off_q <= 9'h062 && dbgn < 12) begin
        dbgn = dbgn + 1;
        $display("IO %h rnw=%b d=%h a=%h l2=%b", soc.off_q, soc.cpu_rnw, soc.cpu_d_out, soc.a, soc.l2);
    end
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
`ifdef DUMPFB
    // when the window goes back below 2 MB (the OS-9 command gfx has written the picture): the 76,800 bytes at $300000 of the SDRAM model
    integer ffd, fk;
    reg [21:0] fba;
    reg [19:0] fw;
    reg [31:0] fdw;
    always @(negedge soc.win_hi) begin
        ffd = $fopen("fbdump.bin", "wb");
        for (fk = 0; fk < 76800; fk = fk + 1) begin
            fba = 22'h300000 + fk;
            fw = fba[21:2];
            fdw = mdl.mem[{fw[9:8], 1'b0, fw[19:10], fw[7:0]}];
            $fwrite(ffd, "%c", fdw[8 * fba[1:0] +: 8]);
        end
        $fclose(ffd);
        $display("FBDUMP written");
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
