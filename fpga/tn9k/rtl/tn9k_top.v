// SPDX-License-Identifier: MIT
// Copyright (c) 2026 sim09 contributors
// Changed for Matenro: the SoC is matenro_soc (the Z80 sub CPU and the cross link); the module keeps its name tn9k_top.
//
// The sim09 / sbc09 machine on the Sipeed Tang Nano 9K (Gowin GW1NR-LV9QN88PC6/I5).
//
//   27 MHz crystal -> PLL -> 67.5 MHz (and 67.5 MHz shifted by 90 degrees for the PSRAM clock)
//   S1 (pin 4)     reset
//   UART           the USB serial port of the board (BL702): 115200 baud, 8N1 - the console
//   microSD slot   the disks (raw: drive 0 from block 0, drive 1 from 128 MB)
//   LEDs           0 heartbeat, 1 running (PSRAM up and cleared), 2 card ready, 3 card busy, 4 card failed, 5 powered off
//
//   HDMI (if `HDMI is defined in tn9k_cfg.vh)  the console on a monitor: 640x480, 80 x 25 characters (hdmi_*.v)
//
// The configuration (ROM image, its address, the clock) comes from tn9k_cfg.vh, which scripts/build.sh writes.

`include "tn9k_cfg.vh"

module tn9k_top (
    input  wire        sys_clk,                 // 27 MHz
    input  wire        sys_resetn,              // S1
    input  wire        uart_rx,
    output wire        uart_tx,
    output wire [5:0]  led,
    output wire        sd_clk,
    output wire        sd_mosi,
    input  wire        sd_miso,
    output wire        sd_cs,
    // the PSRAM inside the package (the names are those the tools look for)
    output wire [1:0]  O_psram_ck,
    output wire [1:0]  O_psram_ck_n,
    inout  wire [1:0]  IO_psram_rwds,
    inout  wire [15:0] IO_psram_dq,
    output wire [1:0]  O_psram_reset_n,
    output wire [1:0]  O_psram_cs_n,
    // the SPI flash of the board: not used (the pins stay in the constraints file of sim09; they are held idle)
    output wire        flash_csb,
    output wire        flash_clk,
    output wire        flash_mosi,
    input  wire        flash_miso
`ifdef HDMI
    ,
    output wire        tmds_clk_p,
    output wire        tmds_clk_n,
    output wire [2:0]  tmds_d_p,
    output wire [2:0]  tmds_d_n
`endif
);

    wire clk, clk_p, locked;
    tn9k_pll pll (.clkin(sys_clk), .clkout(clk), .clkoutp(clk_p), .lock(locked));

    // reset: the button, and a short time after the PLL has locked
    reg [2:0]  btn;
    reg [15:0] por = 16'd0;
    always @(posedge clk) begin
        btn <= {btn[1:0], sys_resetn};
        if (!locked) por <= 16'd0;
        else if (por != 16'hffff) por <= por + 1'b1;
    end
    reg  resetn = 1'b0;
    always @(posedge clk) resetn <= btn[2] && por == 16'hffff;

    assign O_psram_reset_n = {2{resetn}};

    wire [111:0] dbg_regs;
    wire [15:0]  dbg_status, dbg_disk;
    wire         dbg_stall;
    wire [39:0]  dbg_z80;
    wire        uart_tx_soc;
    wire        term_stb, term_busy;
    wire        x1_ack, x2_ack;
    wire        x1_req, x2_req;
    wire [21:0] x1_addr, x2_addr;
    wire [15:0] x1_rdata, x2_rdata;
    wire [7:0]  term_byte;
    wire        ps_rd, ps_wr, ps_bw, ps_busy;
    wire [21:0] ps_addr;
    wire [15:0] ps_din, ps_dout;

    PsramController #(.FREQ(`CLK_HZ), .LATENCY(3)) psram (
        .clk(clk), .clk_p(clk_p), .resetn(resetn),
        .read(ps_rd), .write(ps_wr), .addr(ps_addr), .din(ps_din), .byte_write(ps_bw),
        .dout(ps_dout), .busy(ps_busy),
        .O_psram_ck(O_psram_ck), .IO_psram_rwds(IO_psram_rwds), .IO_psram_dq(IO_psram_dq),
        .O_psram_cs_n(O_psram_cs_n)
    );

`ifdef WATCHDOG
    // watchdog (build.sh WDOG=1): when the CPU has been held for about a second the UART pin carries, instead of the console,
    // the line of dbg_uart every 31 ms (the 6809 registers and what holds the CPU: see dbg_status of matenro_soc.v)
    wire dbg_tx;
    reg [26:0] wd_cnt = 27'd0;
    always @(posedge clk) wd_cnt <= dbg_stall ? (wd_cnt[26] ? wd_cnt : wd_cnt + 1'b1) : 27'd0;
    dbg_uart_z #(.BAUD_DIV(`CLK_HZ / 115200)) dbg (.clk(clk), .regs(dbg_regs), .status(dbg_status), .zdbg(dbg_z80), .txd(dbg_tx));
    // the same lines on request, whatever the 6809 does: three bytes $1F in a row on the serial line switch them on,
    // three bytes $1E switch them off (a receiver of its own listens to the pin; the console sees the bytes too)
    localparam [9:0] RX_DIV = `CLK_HZ / 115200;
    reg         rx_q1 = 1'b1, rx_q2 = 1'b1, rx_act = 1'b0, dbg_on = 1'b0;
    reg  [9:0]  rx_cnt = 10'd0;
    reg  [3:0]  rx_n = 4'd0;
    reg  [7:0]  rx_sh = 8'd0, rx_prev = 8'd0;
    reg  [1:0]  rx_rep = 2'd0;
    always @(posedge clk) begin
        rx_q1 <= uart_rx; rx_q2 <= rx_q1;
        if (!rx_act) begin
            if (!rx_q2) begin rx_act <= 1'b1; rx_cnt <= RX_DIV + (RX_DIV >> 1); rx_n <= 4'd0; end
        end else if (rx_cnt != 10'd0) rx_cnt <= rx_cnt - 1'b1;
        else if (rx_n < 4'd8) begin
            rx_sh <= {rx_q2, rx_sh[7:1]}; rx_n <= rx_n + 1'b1; rx_cnt <= RX_DIV - 1'b1;
        end else begin
            rx_act <= 1'b0;
            if ((rx_sh == 8'h1F || rx_sh == 8'h1E) && rx_sh == rx_prev) begin
                if (rx_rep == 2'd1) begin dbg_on <= (rx_sh == 8'h1F); rx_rep <= 2'd0; end
                else rx_rep <= rx_rep + 1'b1;
            end else rx_rep <= 2'd0;
            rx_prev <= rx_sh;
        end
    end
    assign uart_tx = (wd_cnt[26] | dbg_on) ? dbg_tx : uart_tx_soc;
`elsif DEBUG_TX
    wire dbg_tx;
    dbg_uart #(.BAUD_DIV(`CLK_HZ / 115200)) dbg (.clk(clk), .regs(dbg_regs), .status(`ifdef DEBUG_DISK dbg_disk `else dbg_status `endif), .txd(dbg_tx));
    assign uart_tx = dbg_tx;
`else
    assign uart_tx = uart_tx_soc;
`endif

    matenro_soc #(
        .CLK_HZ(`CLK_HZ), .PH_DIV(`PH_DIV), .BAUD_DIV(`CLK_HZ / 115200),
        .ROM_BASE(`ROM_BASE), .ROM_AW(`ROM_AW), .ROM_FILE("rom.hex"), .FREERUN(`FREERUN),
        .RTC_YEAR(`RTC_YEAR), .RTC_MONTH(`RTC_MONTH), .RTC_DAY(`RTC_DAY),
        .RTC_HOUR(`RTC_HOUR), .RTC_MIN(`RTC_MIN), .RTC_SEC(`RTC_SEC), .MEMTEST(`MEMTEST_EN)
    ) soc (
        .clk(clk), .resetn(resetn), .rxd(uart_rx), .txd(uart_tx_soc),
        .sd_clk(sd_clk), .sd_mosi(sd_mosi), .sd_miso(sd_miso), .sd_cs(sd_cs),
        .ps_rd(ps_rd), .ps_wr(ps_wr), .ps_addr(ps_addr), .ps_din(ps_din), .ps_bw(ps_bw),
        .ps_dout(ps_dout), .ps_busy(ps_busy),
        .led(led), .term_busy(term_busy),
        .x1_req(x1_req), .x1_addr(x1_addr), .x1_ack(x1_ack), .x1_rdata(x1_rdata),
        .x2_req(x2_req), .x2_addr(x2_addr), .x2_ack(x2_ack), .x2_rdata(x2_rdata),
        .term_stb(term_stb), .term_byte(term_byte), .dbg_regs(dbg_regs), .dbg_status(dbg_status), .dbg_disk(dbg_disk), .dbg_lic(), .dbg_stall(dbg_stall), .dbg_z80(dbg_z80), .dbg_addr(), .dbg_acc(), .dbg_din(), .dbg_rnw(), .dbg_vma()
    );

    assign flash_csb = 1'b1, flash_clk = 1'b0, flash_mosi = 1'b0;     // (flash_miso is not read)

`ifndef HDMI
    assign term_busy = 1'b0;
    assign x1_req = 1'b0, x1_addr = 22'd0, x2_req = 1'b0, x2_addr = 22'd0;
`endif
`ifdef HDMI
    wire clk_pix, hlocked;
    wire [9:0] tmds_b, tmds_g, tmds_r;
    reg  [3:0] rpx = 4'hf;
    always @(posedge clk_pix or negedge hlocked) begin
        if (!hlocked) rpx <= 4'hf;
        else          rpx <= {rpx[2:0], 1'b0};
    end
    wire rst_pix = rpx[3];

    hdmi_text #(.ROWS(`HDMI_ROWS), .CHARSET(`HDMI_CHARSET), .FONT_FILE("font8x16.hex")) screen (
        .clk(clk), .rst(~resetn), .stb(term_stb), .din(term_byte), .busy(term_busy), .kanji_ok(1'b0),
        .x1_req(x1_req), .x1_addr(x1_addr), .x1_ack(x1_ack), .x1_rdata(x1_rdata),
        .x2_req(x2_req), .x2_addr(x2_addr), .x2_ack(x2_ack), .x2_rdata(x2_rdata),
        .clk_pix(clk_pix), .rst_pix(rst_pix), .tmds_b(tmds_b), .tmds_g(tmds_g), .tmds_r(tmds_r)
    );
    hdmi_phy phy (
        .clkin(sys_clk), .clk_pix(clk_pix), .locked(hlocked), .rst_pix(rst_pix),
        .tmds_b(tmds_b), .tmds_g(tmds_g), .tmds_r(tmds_r),
        .tmds_clk_p(tmds_clk_p), .tmds_clk_n(tmds_clk_n), .tmds_d_p(tmds_d_p), .tmds_d_n(tmds_d_n)
    );
`endif

endmodule
