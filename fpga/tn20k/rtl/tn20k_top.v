// SPDX-License-Identifier: MIT
// tn20k_top.v - the Matenro machine on the Sipeed Tang Nano 20K (Gowin GW2AR-18C): 6809 (OS-9 Level 2) + 8088 (MCL86) sub CPU
//
//   27 MHz crystal (pin 4) -> PLL -> 67.5 MHz, and the same shifted by 180 degrees for the SDRAM clock
//   S1 (pin 88)    reset (the buttons of the 20K are high when pressed)
//   S2 (pin 87)    toggles the LED display (as on the 9K): the second one has LED0 = the Z80 is enabled, LED1 = the 8088 is enabled (subsel)
//   UART           the USB serial port of the board (BL616): 115200 baud, 8N1 - the console (FPGA pins 69 = TX, 70 = RX)
//   microSD slot   the disks (raw SPI mode: drive 0 from block 0, drive 1 from 128 MB), pins 83 CLK, 82 MOSI, 84 MISO, 81 CS
//   SDRAM          the 64 Mbit SDR SDRAM in the package (4 MB used), through sdram_ctl.v
//   LEDs           pins 15-20, low active: 0 heartbeat, 1 running, 2 card ready, 3 card busy, 4 card failed, 5 powered off
//
// With `define HDMI (build.sh, HDMI=0 leaves it out) the console is shown on the HDMI connector too (hdmi_text20.v, hdmi_phy20.v).
// The SoC is matenro_soc.v of the Tang Nano 9K machine, with `define SUB8088 (the 8088 instead of the Z80) and the SDRAM controller in
// place of the PSRAM controller (the same request interface: psram_arb4.v and everything behind it are unchanged).  No HDMI screen yet.
// The configuration (ROM image and address, clock, date) comes from tn20k_cfg.vh, which scripts/build.sh writes.

`include "tn20k_cfg.vh"

module tn20k_top (
    input  wire        sys_clk,                 // 27 MHz
    input  wire        s1,                      // reset (high when pressed)
    input  wire        s2,                      // toggles the LED display (high when pressed)
    input  wire        uart_rx,
    output wire        uart_tx,
    output wire [5:0]  led,
    output wire        sd_clk,
    output wire        sd_mosi,
    input  wire        sd_miso,
    output wire        sd_cs,
    // the SDRAM in the package (the names are those the tools look for)
    output wire        O_sdram_clk,
    output wire        O_sdram_cke,
    output wire        O_sdram_cs_n,
    output wire        O_sdram_cas_n,
    output wire        O_sdram_ras_n,
    output wire        O_sdram_wen_n,
    output wire [3:0]  O_sdram_dqm,
    output wire [10:0] O_sdram_addr,
    output wire [1:0]  O_sdram_ba,
    inout  wire [31:0] IO_sdram_dq
`ifdef HDMI
    ,
    // the HDMI connector (TMDS): the console on a monitor, 640x480, 80 x 25 characters (hdmi_text20.v)
    output wire        tmds_clk_p,
    output wire        tmds_clk_n,
    output wire [2:0]  tmds_d_p,
    output wire [2:0]  tmds_d_n,
    input  wire        hdmi_hpd             // HPD of the connector (pin 26): high = a monitor is connected
`endif
);
`ifdef HDMI
    wire hpd = hdmi_hpd;
`else
    wire hpd = 1'b0;
`endif
    wire clk, clk_p, locked;
    tn20k_pll #(.IDIV(`PLL_IDIV), .FBDIV(`PLL_FBDIV), .ODIV(`PLL_ODIV)) pll (.clkin(sys_clk), .clkout(clk), .clkoutp(clk_p), .lock(locked));

    // reset: the button, and a short time after the PLL has locked
    wire       reboot_req;                  // from the SoC: the guest wrote $A6 / $A7 to the power register = the reset button
    wire       led_mode;
    reg [2:0]  btn;
    reg [15:0] por = 16'd0;
    always @(posedge clk) begin
        btn <= {btn[1:0], ~s1};             // (s1 is high when pressed; btn[2] is high when the button is up)
        if (!locked || reboot_req) por <= 16'd0;
        else if (por != 16'hffff) por <= por + 1'b1;
    end
    reg  resetn = 1'b0;
    always @(posedge clk) resetn <= btn[2] && por == 16'hffff;

    btn_toggle #(.DEB_BITS(20)) s2_toggle (.clk(clk), .rst_n(resetn), .btn_n(~s2), .state(led_mode));       // 15 ms debounce

    wire        ps_rd, ps_wr, ps_bw, ps_busy, ps_wide;
    // the frame buffer of the HDMI screen reads the SDRAM itself (32 bits at a time), before the requests of the SoC: it takes the clock in
    // which the controller is free and the SoC has no pulse; the SoC sees "busy" in that clock (the combinational fb_go), so it does not start
    wire        ctl_busy, fb_rq, fb_go, ps_issue;
    wire [21:0] fb_addr;
    wire [31:0] fb_dout32;
    wire [6:0]  fb_n;
    wire        fb_dv;
`ifdef KANJI
    assign      fb_go = fb_rq && !ctl_busy && !ps_rd && !ps_wr && !ps_issue;
`else
    assign      fb_go = 1'b0;
`endif
    assign      ps_busy = ctl_busy || fb_go;
    wire        gfx_on, gfx_ov, pal_we, pc_on;
    wire [6:0]  pc_col;
    wire [4:0]  pc_row;
    wire [7:0]  pal_idx;
    wire [23:0] pal_rgb;
    wire [21:0] ps_addr;
    wire [15:0] ps_din, ps_dout;
    wire [111:0] dbg_regs;
    wire [15:0]  dbg_status, dbg_disk;
    wire         dbg_stall;
    wire [39:0]  dbg_z80;

    sdram_ctl #(.FREQ(`CLK_HZ), .REFRESH_CLKS(`CLK_HZ / 1000 * 74 / 10000)) sdram (
        .clk(clk), .clk_sdram(clk_p), .resetn(resetn),
        .read(ps_rd || fb_go), .write(ps_wr), .addr(fb_go ? fb_addr : ps_addr), .din(fb_go ? {9'd0, fb_n} : ps_din), .byte_write(ps_bw), .wide(fb_go || ps_wide), .dout(ps_dout), .dout32(fb_dout32), .dv(fb_dv), .busy(ctl_busy),
        .O_sdram_clk(O_sdram_clk), .O_sdram_cke(O_sdram_cke), .O_sdram_cs_n(O_sdram_cs_n), .O_sdram_cas_n(O_sdram_cas_n),
        .O_sdram_ras_n(O_sdram_ras_n), .O_sdram_wen_n(O_sdram_wen_n), .O_sdram_dqm(O_sdram_dqm), .O_sdram_addr(O_sdram_addr),
        .O_sdram_ba(O_sdram_ba), .IO_sdram_dq(IO_sdram_dq)
    );

    wire        term_stb, term_busy, kanji_ok;
    wire        x1_req, x1_ack, x2_req, x2_ack;
    wire [21:0] x1_addr, x2_addr;
    wire [15:0] x1_rdata, x2_rdata;
    wire [7:0]  term_byte;
`ifdef HDMI
    wire clk_pix, hlocked;
    wire [9:0] tmds_b, tmds_g, tmds_r;
    reg  [3:0] rpx = 4'hf;
    always @(posedge clk_pix or negedge hlocked) begin
        if (!hlocked) rpx <= 4'hf;
        else          rpx <= {rpx[2:0], 1'b0};
    end
    wire rst_pix = rpx[3];
`ifdef KANJI
    // the screen of sim09 with the character decoder (UTF-8, EUC-JP, Shift_JIS) and the kanji glyphs: the image (OS-9 command
    // kanjild) is in the SDRAM at $200000, the tables and the glyph lines are read through the masters 1 and 2 of the arbiter
    hdmi_screen20 #(.ROWS(25), .CHARSET(`HDMI_CHARSET), .FONT_FILE("font8x16.hex")) screen (
        .clk(clk), .rst(~resetn), .stb(term_stb), .din(term_byte), .busy(term_busy), .kanji_ok(kanji_ok),
        .x1_req(x1_req), .x1_addr(x1_addr), .x1_ack(x1_ack), .x1_rdata(x1_rdata),
        .x2_req(x2_req), .x2_addr(x2_addr), .x2_ack(x2_ack), .x2_rdata(x2_rdata),
        .clk_pix(clk_pix), .rst_pix(rst_pix), .tmds_b(tmds_b), .tmds_g(tmds_g), .tmds_r(tmds_r),
        .gfx_on(gfx_on), .gfx_ov(gfx_ov), .pc_on(pc_on), .pc_col(pc_col), .pc_row(pc_row), .pal_we(pal_we), .pal_idx(pal_idx), .pal_rgb(pal_rgb),
        .fb_rq(fb_rq), .fb_addr(fb_addr), .fb_n(fb_n), .fb_go(fb_go), .fb_busy(ctl_busy), .fb_dv(fb_dv), .fb_dout32(fb_dout32)
    );
`else
    hdmi_text20 #(.ROWS(25), .FONT_FILE("font8x16.hex")) screen (
        .clk(clk), .rst(~resetn), .stb(term_stb), .din(term_byte), .busy(term_busy),
        .clk_pix(clk_pix), .rst_pix(rst_pix), .tmds_b(tmds_b), .tmds_g(tmds_g), .tmds_r(tmds_r)
    );
`endif
    hdmi_phy20 phy (
        .clkin(sys_clk), .clk_pix(clk_pix), .locked(hlocked), .rst_pix(rst_pix),
        .tmds_b(tmds_b), .tmds_g(tmds_g), .tmds_r(tmds_r),
        .tmds_clk_p(tmds_clk_p), .tmds_clk_n(tmds_clk_n), .tmds_d_p(tmds_d_p), .tmds_d_n(tmds_d_n)
    );
`else
    assign term_busy = 1'b0;
`endif
`ifndef KANJI
    assign x1_req = 1'b0, x1_addr = 22'd0, x2_req = 1'b0, x2_addr = 22'd0;
    assign fb_rq = 1'b0, fb_addr = 22'd0, fb_n = 7'd0;
`endif

    matenro_soc #(
        .CLK_HZ(`CLK_HZ), .PH_DIV(`PH_DIV), .BAUD_DIV(`CLK_HZ / 115200),
        .ROM_BASE(`ROM_BASE), .ROM_AW(`ROM_AW), .ROM_FILE("rom.hex"), .FREERUN(`FREERUN),
        .RTC_YEAR(`RTC_YEAR), .RTC_MONTH(`RTC_MONTH), .RTC_DAY(`RTC_DAY),
        .RTC_HOUR(`RTC_HOUR), .RTC_MIN(`RTC_MIN), .RTC_SEC(`RTC_SEC), .MEMTEST(`MEMTEST_EN), .C88_DIV(`C88_DIV), .CZ_DIV(`CZ_DIV)
    ) soc (
        .clk(clk), .resetn(resetn), .hdmi_hpd(hpd), .rxd(uart_rx), .txd(uart_tx),
        .sd_clk(sd_clk), .sd_mosi(sd_mosi), .sd_miso(sd_miso), .sd_cs(sd_cs),
        .ps_rd(ps_rd), .ps_wr(ps_wr), .ps_addr(ps_addr), .ps_din(ps_din), .ps_bw(ps_bw),
        .ps_dout(ps_dout), .ps_dout32(fb_dout32), .ps_dv(fb_dv), .ps_wide(ps_wide), .ps_busy(ps_busy), .ps_issue(ps_issue),
        .led(led), .led_mode(led_mode), .term_busy(term_busy), .reboot_req(reboot_req),
        .x1_req(x1_req), .x1_addr(x1_addr), .x1_ack(x1_ack), .x1_rdata(x1_rdata),
        .x2_req(x2_req), .x2_addr(x2_addr), .x2_ack(x2_ack), .x2_rdata(x2_rdata),
        .kanji_ok(kanji_ok), .gfx_on(gfx_on), .gfx_ov(gfx_ov), .pc_on(pc_on), .pc_col(pc_col), .pc_row(pc_row), .pal_we(pal_we), .pal_idx(pal_idx), .pal_rgb(pal_rgb), .term_stb(term_stb), .term_byte(term_byte), .dbg_regs(dbg_regs), .dbg_status(dbg_status), .dbg_disk(dbg_disk), .dbg_lic(), .dbg_stall(dbg_stall),
        .dbg_z80(dbg_z80), .dbg_addr(), .dbg_acc(), .dbg_din(), .dbg_rnw(), .dbg_vma(), .dbg_dbus()
    );
endmodule
