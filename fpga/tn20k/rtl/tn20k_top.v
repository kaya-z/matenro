// SPDX-License-Identifier: MIT
// tn20k_top.v - the Matenro machine on the Sipeed Tang Nano 20K (Gowin GW2AR-18C): 6809 (OS-9 Level 2) + 8088 (MCL86) sub CPU
//
//   27 MHz crystal (pin 4) -> PLL -> 67.5 MHz, and the same shifted by 180 degrees for the SDRAM clock
//   S1 (pin 88)    reset (the buttons of the 20K are high when pressed)
//   S2 (pin 87)    toggles the LED display (as on the 9K): the second one has LED0 = the sub CPU (8088) is enabled
//   UART           the USB serial port of the board (BL616): 115200 baud, 8N1 - the console (FPGA pins 69 = TX, 70 = RX)
//   microSD slot   the disks (raw SPI mode: drive 0 from block 0, drive 1 from 128 MB), pins 83 CLK, 82 MOSI, 84 MISO, 81 CS
//   SDRAM          the 64 Mbit SDR SDRAM in the package (4 MB used), through sdram_ctl.v
//   LEDs           pins 15-20, low active: 0 heartbeat, 1 running, 2 card ready, 3 card busy, 4 card failed, 5 powered off
//
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
);
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

    wire        ps_rd, ps_wr, ps_bw, ps_busy;
    wire [21:0] ps_addr;
    wire [15:0] ps_din, ps_dout;
    wire [111:0] dbg_regs;
    wire [15:0]  dbg_status, dbg_disk;
    wire         dbg_stall;
    wire [39:0]  dbg_z80;

    sdram_ctl #(.FREQ(`CLK_HZ), .REFRESH_CLKS(`CLK_HZ / 1000 * 74 / 10000)) sdram (
        .clk(clk), .clk_sdram(clk_p), .resetn(resetn),
        .read(ps_rd), .write(ps_wr), .addr(ps_addr), .din(ps_din), .byte_write(ps_bw), .dout(ps_dout), .busy(ps_busy),
        .O_sdram_clk(O_sdram_clk), .O_sdram_cke(O_sdram_cke), .O_sdram_cs_n(O_sdram_cs_n), .O_sdram_cas_n(O_sdram_cas_n),
        .O_sdram_ras_n(O_sdram_ras_n), .O_sdram_wen_n(O_sdram_wen_n), .O_sdram_dqm(O_sdram_dqm), .O_sdram_addr(O_sdram_addr),
        .O_sdram_ba(O_sdram_ba), .IO_sdram_dq(IO_sdram_dq)
    );

    matenro_soc #(
        .CLK_HZ(`CLK_HZ), .PH_DIV(`PH_DIV), .BAUD_DIV(`CLK_HZ / 115200),
        .ROM_BASE(`ROM_BASE), .ROM_AW(`ROM_AW), .ROM_FILE("rom.hex"), .FREERUN(`FREERUN),
        .RTC_YEAR(`RTC_YEAR), .RTC_MONTH(`RTC_MONTH), .RTC_DAY(`RTC_DAY),
        .RTC_HOUR(`RTC_HOUR), .RTC_MIN(`RTC_MIN), .RTC_SEC(`RTC_SEC), .MEMTEST(`MEMTEST_EN), .C88_DIV(`C88_DIV), .CZ_DIV(`CZ_DIV)
    ) soc (
        .clk(clk), .resetn(resetn), .rxd(uart_rx), .txd(uart_tx),
        .sd_clk(sd_clk), .sd_mosi(sd_mosi), .sd_miso(sd_miso), .sd_cs(sd_cs),
        .ps_rd(ps_rd), .ps_wr(ps_wr), .ps_addr(ps_addr), .ps_din(ps_din), .ps_bw(ps_bw),
        .ps_dout(ps_dout), .ps_busy(ps_busy),
        .led(led), .led_mode(led_mode), .term_busy(1'b0), .reboot_req(reboot_req),
        .x1_req(1'b0), .x1_addr(22'd0), .x1_ack(), .x1_rdata(),
        .x2_req(1'b0), .x2_addr(22'd0), .x2_ack(), .x2_rdata(),
        .term_stb(), .term_byte(), .dbg_regs(dbg_regs), .dbg_status(dbg_status), .dbg_disk(dbg_disk), .dbg_lic(), .dbg_stall(dbg_stall),
        .dbg_z80(dbg_z80), .dbg_addr(), .dbg_acc(), .dbg_din(), .dbg_rnw(), .dbg_vma(), .dbg_dbus()
    );
endmodule
