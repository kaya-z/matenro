// Tang Nano 20K copy: made from fpga/tn9k/rtl/matenro_soc.v (as of commit d56829d, 2026-11-19).  From here on this file belongs to the 20K only; the 9K keeps its own (frozen) one.
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 sim09 contributors
//
// MATENRO: sbc09_soc.v of sim09 with the Z80 sub CPU of the Matenro machine added (docs/FPGA.md).  The changes:
//   * the cross link (XLINK, rtl/xlink.v) at offsets $4A-$4E of the I/O page ($FFCA-$FFCE in the Level 2 mode, $E04A-$E04E
//     in the Level 1 mode), the same registers as the simulator (docs/DESIGN.md chapter 6)
//   * the Z80 (rtl/z80_sub.v: TV80 + XLINK + SMMU) at CZ_DIV system clocks per Z80 clock, its memory in the PSRAM through a
//     fourth master of the arbiter (psram_arb4.v); the 6809 reaches the physical memory through the window of the XLINK,
//     which uses the port of master 0 (the CPU is waiting then)
//   * the IRQ of the 6809 is the OR of the timer and the XLINK
//   * the memory test states are guarded by MEMTEST, so that with MEMTEST = 0 the synthesis drops the test and its messages
// Everything else is the file of sim09.
//
// The sim09 / sbc09 "v09" machine (Level 1: 64 KB flat memory, I/O page at $E000) as a system on a chip:
//
//   CPU       Greg Miller's cycle accurate MC6809 (vendor/mc6809, BSD-3-Clause), E = clk / (4 * PH_DIV)
//   RAM       64 KB in the PSRAM of the Tang Nano 9K, through the controller of Feng Zhou (vendor/psram);
//             cleared (byte by byte) after every reset, like the memory of the simulator
//   ROM       a read-only image in block RAM, from ROM_BASE up to $FFFF, over the RAM
//   $E000/01  console ACIA on the UART (acia_uart.v); its interrupt request is on the IRQ line (with the timer and the cross link)
//   $E00F     power control: $A5 stops the machine (until the reset button)
//   $E030-36  timer and clock (timer_rtc.v)
//   $E040-47  disk port on the microSD card (sd_disk.v)
//   $E080-1FF plain RAM
//
// The memory map and the registers are those of the simulator (see docs/FPGA.md and README.md).
//
// The machine has two modes.  It starts as the Level 1 machine above (the 256 byte boot ROM of FUZIX / MK09 reads
// the image of the OS from the card).  An image (the Level 2 loader, tools/mkl2disk.py) can switch it to the other machine of
// the simulator (sim09 -2): CoCo 3 style, 2 MB of physical memory in the PSRAM behind a MMU (two tasks of eight 8 KB
// blocks: the system map at $FFA0-A7, the user map at $FFA8-AF, the task register at $FF91), the I/O registers at $FF80
// (the same offsets as at $E000), a fixed page $FE00-$FFFF = physical $7FE00, no ROM, all of it RAM.  The switch is a write
// to the mode register (offset $0E of the I/O page): $A2 = go to the Level 2 mode (the system map is the identity for the
// blocks 0-6 and block 7 = $3F, so that the loader goes on running), $A3 = reset the CPU in the Level 2 mode (the maps as the
// simulator has them at the reset), after the loader has put the ROM image of the Level 2 machine at physical $7E000.
// The PSRAM is cleared (2 MB) after every reset of the board.

// Bus timing: one bus cycle of the CPU is four phases of PH_DIV clocks (E falls, Q rises, E rises, Q falls).
// Shortly after E has risen, the address, the direction, the data and the "valid" flag of the cycle are
// stable and the access is made.  The CPU's clock is held (before E falls) while a memory access or the
// disk is still busy, so the access time of the PSRAM or of the card never matters for the result.

`ifndef CIDX_DEF
`define CIDX_DEF 10
`endif
`ifndef SIDX_DEF
`define SIDX_DEF 10
`endif
module matenro_soc #(
    parameter CLK_HZ     = 67500000,
    parameter CIDX       = `CIDX_DEF,                      // the read cache of the 6809: 2 ** CIDX lines of 4 bytes (10: 4 KB)
    parameter SIDX       = `SIDX_DEF,                      // the read cache of the sub CPU (10: 4 KB)
    parameter PH_DIV     = 9,                       // clks per phase; E = CLK_HZ / (4 * PH_DIV) = 1.875 MHz
    parameter BAUD_DIV   = 586,                     // 115200 baud
    parameter [15:0] ROM_BASE = 16'hC000,
    parameter ROM_AW     = 14,                      // the ROM is 2**ROM_AW bytes, up to $FFFF
    parameter ROM_FILE   = "rom.hex",
    parameter FREERUN    = 0,                       // 1: the monitor ROM v09.rom (FIRQ timer from the reset)
    parameter [23:0] DRIVE1_BLK = 24'h040000,
    parameter RTC_YEAR   = 126,
    parameter RTC_MONTH  = 1,
    parameter RTC_DAY    = 1,
    parameter RTC_HOUR   = 0,
    parameter RTC_MIN    = 0,
    parameter RTC_SEC    = 0,
    parameter MEMTEST    = 1,                       // test the PSRAM (55, AA, the address as the data) after the reset: Memory >>>> on the console
    parameter [21:0] MT_LAST = 22'h1fffff,          // the last byte to test (2 MB)
    parameter SHR_BLK    = 8'hff,                   // the physical block (8 KB, bits 20:13) that is served from the BSRAM
    parameter CZ_DIV     = 9,                       // Z80 clock = CLK_HZ / CZ_DIV (7.5 MHz)
    parameter C88_DIV    = 14,                      // `define SUB8088 / SUBBOTH: the 8088 clock = CLK_HZ / C88_DIV (4.82 MHz)
    parameter SUB_DEF8   = 1'b1                     // `define SUBBOTH: the sub CPU after the reset: 1 = 8088, 0 = Z80
) (
    input  wire        clk,
    input  wire        resetn,
    input  wire        rxd,
    output wire        txd,
    output wire        sd_clk,
    output wire        sd_mosi,
    input  wire        sd_miso,
    output wire        sd_cs,
    // PSRAM controller
    output wire        ps_rd,
    output wire        ps_wr,
    output wire        ps_issue,            // the arbiter has decided a request: the controller must not take another one in this clock (tn20k_top.v)
    output wire [21:0] ps_addr,
    output wire [15:0] ps_din,
    output wire        ps_bw,
    input  wire [15:0] ps_dout,
    input  wire [31:0] ps_dout32,       // `define CACHE: the 32 bit word of the last wide read (sdram_ctl.v dout32)
    input  wire        ps_dv,           // `define CACHE: dout32 has a new word in this clock (sdram_ctl.v dv)
    output wire        ps_wide,         // `define CACHE: the read that the arbiter issues is a wide one (a line of the read cache)
    input  wire        ps_busy,
    // LEDs (active low), and the CPU for the test bench
    output wire [5:0]  led,
    input  wire        led_mode,            // 0: heartbeat / running / card / power;  1: LED0 = the sub CPU is enabled, LED1-5 off (reserved); SUBBOTH: LED0 = the Z80 is enabled, LED1 = the 8088 is enabled
    input  wire        term_busy,           // the HDMI screen has no room for more characters now
    // two more PSRAM masters (word reads) for a screen: not used on the 9K
    input  wire        x1_req,
    input  wire [21:0] x1_addr,
    output wire        x1_ack,
    output wire [15:0] x1_rdata,
    input  wire        x2_req,
    input  wire [21:0] x2_addr,
    output wire        x2_ack,
    output wire [15:0] x2_rdata,
    output wire        reboot_req,          // the guest wrote $A6 or $A7 to the power register: the top level does what the reset button does
    output wire        kanji_ok,            // `define HCTL: the kanji image is in the memory ($FFC8 bit 0)
    input  wire        hdmi_hpd,            // the HDMI connector's HPD (hot plug detect: high = a monitor is connected); read at $FFB8 bit 7 (0 on the 9K: not wired)
    output wire        gfx_on,              // `define HCTL: the frame buffer is shown instead of the text ($FFB8 bit 0)
    output wire        gfx_ov,              // the text is shown over the picture ($FFB8 bit 1)
    output wire        pc_on,               // `define HCTL: the text screen shows the text memory of the PC ($FFBB bit 0); its cursor: pc_col, pc_row ($FFBC, $FFBD)
    output wire [6:0]  pc_col,
    output wire [4:0]  pc_row,
    output wire        pal_we,              // a palette entry is written (one clock): pal_idx, pal_rgb
    output wire [7:0]  pal_idx,
    output wire [23:0] pal_rgb,
    output wire        term_stb,            // a byte the guest wrote to the console (for the HDMI screen)
    output wire [7:0]  term_byte,
    output wire [111:0] dbg_regs,
    output wire        dbg_lic,
    output wire [39:0] dbg_z80,             // the Z80 for the debug UART
    output wire        dbg_stall,           // the CPU is held (any reason): the watchdog of the board looks at it
    output wire [15:0] dbg_addr,
    output wire        dbg_acc,
    output wire [15:0] dbg_status,
    output wire [15:0] dbg_disk,
    output wire [7:0]  dbg_din,
    output wire        dbg_rnw,
    output wire        dbg_vma,
    output wire [7:0]  dbg_dbus             // the data bus of the 6809: the byte read (RnW high) or written
);

    // The timer and the clock run on the system clock, not on the E cycles of the CPU: a pulse every RT_DIV clocks (a power of two: the low bits
    // of the free running counter hb).  The E cycle is longer than 4 * PH_DIV clocks when the CPU waits for the PSRAM (a CPU that runs from the PSRAM
    // got about 70 % of the nominal E rate), and a timer that counted E cycles lost that time.  While a synchronous disk command holds the CPU the pulses
    // stop (as before: the CPU cannot take the interrupt, a tick would be lost).
    localparam RT_DIV        = 32;
    localparam ECYC_PER_SEC  = CLK_HZ / RT_DIV;
    localparam ECYC_PER_TICK = (ECYC_PER_SEC + 25) / 50;
    reg [23:0] hb;                              // free running (the LEDs, the pulse of the timer)
    always @(posedge clk) hb <= hb + 1'b1;

    reg rst = 1'b1;
    always @(posedge clk) rst <= ~resetn;

    // ---------------------------------------------------------------- the CPU and its bus
    wire [7:0]  cpu_d_out;
    wire [15:0] cpu_a;
    wire        cpu_rnw, cpu_bs, cpu_ba, cpu_avma, cpu_lic;
    reg  [7:0]  cpu_d_in;
    reg         e, q;
    reg         nreset_cpu;
    wire        timer_irq;
    wire        disk_irq;               // an asynchronous disk command has finished (and the guest asked for the interrupt)
    wire        acia_irq;               // the console ACIA (OS-9 uses its receive and transmit interrupts)
    // MATENRO (declared here: they are used before the XLINK section)
    wire        xl_irq, xl_firq, xl_wait, xl_win, xl_on;
`ifdef HCTL
    // HCTL ($FFC8): bit 0 = the kanji image is in the memory (the HDMI screen shows kanji), bit 1 = the window of the XLINK looks at
    // the memory above 2 MB (physical bit 21 = 1): the loader of the image (OS-9 command kanjild) writes it there
    reg         kj_ok = 1'b0, win_hi = 1'b0;
`else
    wire        kj_ok = 1'b0, win_hi = 1'b0;
`endif
    assign      kanji_ok = kj_ok;
    // the frame buffer of the HDMI screen: GCTL $FFB8 (bit 0: show it), PIDX $FFB9 (the palette entry), PDAT $FFBA (the red, green, blue bytes of
    // the entry, one after the other; the third write sets it, the index goes on)
`ifdef HCTL
    reg         pc_r = 1'b0;                        // PTXT $FFBB bit 0: the HDMI text screen shows the text memory of the PC (B800h of the sub CPU)
    reg  [6:0]  pcol_r = 7'd0;
    reg  [4:0]  prow_r = 5'd0;
    reg         gfx_r = 1'b0, ov_r = 1'b0, sv_r = 1'b0, pal_we_r = 1'b0;   // sv_r: GCTL bit 2, the blocks $70-$7F of the sub CPU memory are the picture
    reg  [7:0]  pidx_r = 8'd0, pal_ix_r = 8'd0, pred_r, pgrn_r;
    reg  [1:0]  pcnt_r = 2'd0;
    reg  [7:0]  pblu_r;
    reg [1:0]   hpd_q = 2'b00;
    always @(posedge clk) hpd_q <= {hpd_q[0], hdmi_hpd};
    assign      gfx_on = gfx_r;
    assign      gfx_ov = ov_r;
    assign      pc_on  = pc_r;
    assign      pc_col = pcol_r;
    assign      pc_row = prow_r;
    assign      pal_we = pal_we_r;
    assign      pal_idx = pal_ix_r;
    assign      pal_rgb = {pred_r, pgrn_r, pblu_r};
`else
    wire        sv_r = 1'b0;
    assign      pc_on = 1'b0, pc_col = 7'd0, pc_row = 5'd0;
    assign      gfx_on = 1'b0, gfx_ov = 1'b0, pal_we = 1'b0, pal_idx = 8'd0, pal_rgb = 24'd0;
`endif
`ifdef SUBBOTH
    reg         sel8 = SUB_DEF8;                    // SUBSEL: 1 = the 8088 is on the cross link, 0 = the Z80
`endif
    wire [7:0]  xl_rdata;
    reg         xl_rcap = 1'b0;
    reg  [2:0]  xl_cnt  = 3'd0;
    wire        xl_cap = xl_rcap && (xl_cnt == 3'd0) && !xl_wait;
    reg         xw_act = 1'b0, xw_rdp = 1'b0, xw_wrp = 1'b0;
    wire [20:0] win_addr;
    wire [7:0]  win_wdata;
    wire        zm_req, zm_wr, zm_ack, zm_ack_ps;
    wire        zb_hit, zb_ack, win_hit, wb_ack;      // the shared RAM in the BSRAM (shr_ap.v)
    wire [7:0]  zb_rdata, wb_rdata;
    wire [20:0] zm_addr, zm_lk;                         // zm_lk: the address of the bus of the sub CPU in every clock (the look-up of the read cache)
    wire        zm_vram;                                // the sub CPU access is to the picture (SDRAM $300000): the blocks $70-$7F, if GCTL bit 2 is set
    assign      zm_vram = sv_r && (zm_addr[20:17] == 4'b0111);
    wire [7:0]  zm_wdata;
    wire        m3_go, m3_wide;                         // the request of the sub CPU that goes to the arbiter (master 3), and whether it is a wide read
    wire [15:0] zm_rdata_w;

    mc6809i #(.ILLEGAL_INSTRUCTIONS("GHOST")) cpu (
        .D(cpu_d_in), .DOut(cpu_d_out), .ADDR(cpu_a), .RnW(cpu_rnw),
        .E(e), .Q(q), .BS(cpu_bs), .BA(cpu_ba),
        .nIRQ(FREERUN ? ~(acia_irq | disk_irq) : ~(timer_irq | xl_irq | acia_irq | disk_irq)), .nFIRQ((FREERUN ? ~timer_irq : 1'b1) & ~xl_firq), .nNMI(1'b1),
        .AVMA(cpu_avma), .BUSY(), .LIC(cpu_lic),
        .nHALT(1'b1), .nRESET(nreset_cpu), .nDMABREQ(1'b1),
        .RegData(dbg_regs)
    );
    // DEBUG=5: the number of disk commands since the reset, and the low byte of the sector number of the last one
    reg [7:0] dsk_cnt = 8'd0;
    reg [7:0] dsk_lsn = 8'd0;
    always @(posedge clk) if (dgo) begin dsk_cnt <= dsk_cnt + 1'b1; dsk_lsn <= d_lsn0; end
    assign dbg_disk = {dsk_cnt, dsk_lsn};
    assign dbg_lic = cpu_lic;
    assign dbg_addr = cpu_a;
    assign dbg_acc = acc2;
    assign dbg_din = cpu_d_in;
    assign dbg_rnw = cpu_rnw;
    assign dbg_vma = vma_pend;
    assign dbg_dbus = cpu_rnw ? cpu_d_in : cpu_d_out;

    // ---------------------------------------------------------------- clock phases
    reg [7:0] div;
    reg [1:0] ph;
    reg       ecyc;                 // E has fallen: a bus cycle has ended
    reg       acc_go;               // E has risen: the cycle's access
    reg       acc2;                 // and one clock later (the access itself: it needs the decoded address)
    reg       mem_pend;             // a PSRAM access of the CPU is under way
    wire      disk_busy;
    reg        d_async, d_ien;          // $E049 bit 0: the asynchronous mode, bit 7: the interrupt at the end of a command
    reg        d_arun;                  // the command that is under way is an asynchronous one
    reg        d_done;                  // an asynchronous command has finished and its result has not been read ($E049 bit 7)
    reg [7:0]  dm_blk0, dm_blk1;        // the map at the command (the guest may switch the task while the disk transfers)
    reg [2:0]  dm_idx;
    reg        m4_req = 1'b0, m4_wrr = 1'b0;       // the PSRAM master 4: the disk
    reg [21:0] m4_addr;
    reg [7:0]  m4_din;
    wire       m4_ack;
    wire [15:0] m4_rdata;
    wire      acia_tx_full;         // the transmitter cannot take a character now
    wire      ps_busy_m;
    wire      ps_wide_i;
    wire [2:0] ps_sel;
    wire [15:0] ps_dout_m;           // the word the arbiter read for master 0 (the CPU, the disk)
    reg       pwroff;
    reg       reboot_r;             // $A6 (the reboot command of sim09) or $A7 in the power register (cleared by the reset it causes)
    reg       osrun;                // the boot ROM wrote $A4 to the power register: the OS has been started (LED4)
    reg       acia_pend;            // a character for a busy transmitter: the CPU waits
    // The byte read from the PSRAM lands in rd_reg on the clock where mem_pend falls.  The core takes its
    // inputs when E falls, so the stall is held for six more clocks (89 ns): the data has to run through the ALU
    // (the carry chain, 49 ns in the timing report) of the core before that (on the board this was a wrong result of ADDB with an operand
    // from the PSRAM, +-$10).
    reg [5:0] settle = 6'd0;
    wire      disk_hold = disk_busy & ~d_arun;     // a disk command holds the 6809, unless the guest asked for the asynchronous mode
    always @(posedge clk) settle <= {settle[4:0], mem_pend | disk_hold};
    wire      stall = mem_pend | disk_hold | pwroff | acia_pend | (|settle) | xl_wait | xl_rcap;
    // The phase counter looks at the window of the XLINK through a register: xl_wait / xl_rcap start at acc2, two phases before
    // the clock of ph 0 that is held (a clock late is still in time), and come from the deep logic of the XLINK (they were on
    // the slowest paths into the counter); their release is a clock later.  The PSRAM and the others act at once (the 6809 runs
    // from the PSRAM: a clock more on each access would make it 6 % slower).
    // The disk, the ACIA and the power-off are slow sources too (registered the same way: they start at acc2 or later by a few clocks).
    reg       xlst_q = 1'b0;
    always @(posedge clk) xlst_q <= xl_wait | xl_rcap | disk_hold | acia_pend | pwroff;
    reg       m0_req = 1'b0, m0_wrr = 1'b0;   // master 0 of the PSRAM arbiter (below)
    wire      stall_ph = mem_pend | (|settle) | xlst_q;
`ifdef POSTW
    wire      wr_hold = m0_req;                 // a posted write (or the window) is still under way: the next access waits
`else
    wire      wr_hold = 1'b0;
`endif

    always @(posedge clk) begin
        ecyc   <= 1'b0;
        acc_go <= 1'b0;
        acc2   <= acc_go;
        if (rst) begin
            div <= 0; ph <= 0; e <= 1'b1; q <= 1'b0;
        end else if (div != PH_DIV - 1) begin
            div <= div + 1'b1;
        end else if (!(ph == 2'd0 && stall_ph) && !(ph == 2'd2 && wr_hold)) begin
            div <= 0;
            ph  <= ph + 1'b1;
            case (ph)
                2'd0: begin e <= 1'b0; ecyc <= 1'b1; end
                2'd1: q <= 1'b1;
                2'd2: begin e <= 1'b1; acc_go <= 1'b1; end
                2'd3: q <= 1'b0;
            endcase
        end
    end

    // ---------------------------------------------------------------- start-up: PSRAM, clear, reset of the CPU
    localparam [3:0] C_WAIT = 4'd0, C_CLR = 4'd1, C_WAIT2 = 4'd2, C_RUN = 4'd3,
                     M_HDR = 4'd6, M_W = 4'd7, M_WW = 4'd8, M_R = 4'd9, M_RW = 4'd10, M_RC = 4'd11, M_FIN = 4'd12, M_CRED = 4'd13;
    localparam [21:0] CLR_LAST = 22'h1fffff;                              // the last byte to clear: 2 MB (the Level 2 mode)
    reg [3:0]  cs_;
    reg [21:0] cw;
    reg        c_wr, t_rd;
    reg [3:0]  rcnt;
    reg        go_req = 1'b0;           // a one clock pulse: the guest wrote $A3 to the mode register
    reg        l2 = 1'b0;               // the Level 2 mode
    reg [3:0]  bsy_d;               // busy low for a while: the PSRAM is up

    // The memory test (before the clear): three passes over 0 ... MT_LAST, each one writes all, then reads all back:
    // 0 = $55, 1 = $AA, 2 = the address as the data (folded to 8 bits).  tp = 3 is the clear (zero bytes).
    reg [1:0]  tp;
    wire [7:0] tdata = (tp == 2'd0) ? 8'h55 : (tp == 2'd1) ? 8'hAA : (tp == 2'd2) ? (cw[7:0] ^ cw[15:8] ^ {2'b00, cw[21:16]}) : 8'h00;
    reg        t_fail;
    reg [21:0] t_faddr;
    reg [4:0]  mi;                                   // the index in the message
    reg [7:0]  msg_q;                                // msg(), registered (see M_FIN)
    // the console output of the test: one character at a time (the ACIA and the screen)
    reg        p_go, st_wr, st_d, st_d2;
    reg [7:0]  p_ch, st_byte;
    // the credit line: a small ROM with a registered read (a block RAM / ROM, not LUTs: the design is nearly full, 97% of the CLS)
    reg [7:0] crom [0:31];
    reg [7:0] cred_q;
    integer ck;
    initial begin
        for (ck = 0; ck < 32; ck = ck + 1) crom[ck] = 8'h0a;
        crom[0] = "Y"; crom[1] = "U"; crom[2] = "K"; crom[3] = "A"; crom[4] = "R"; crom[5] = "I"; crom[6] = " ";
        crom[7] = "S"; crom[8] = "e"; crom[9] = "m"; crom[10] = "i"; crom[11] = "c"; crom[12] = "o"; crom[13] = "n";
        crom[14] = "d"; crom[15] = "u"; crom[16] = "c"; crom[17] = "t"; crom[18] = "o"; crom[19] = "r"; crom[20] = " ";
        crom[21] = "D"; crom[22] = "e"; crom[23] = "v"; crom[24] = "i"; crom[25] = "c"; crom[26] = "e"; crom[27] = "s";
        crom[28] = 8'h0d;
    end
    always @(posedge clk) cred_q <= crom[mi];          // mi is stable for many clocks before p_ch takes cred_q
    function [7:0] hexc(input [3:0] n); hexc = (n < 4'd10) ? (8'h30 + n) : (8'h37 + n); endfunction
    function [7:0] msg(input [4:0] i5, input fail, input [21:0] fa);
        reg [3:0] i;
        begin
        i = i5[3:0] - 4'd4;                                // the first four characters are ESC [ 0 m (the > were green)
        if (i5 < 5'd4) case (i5[1:0])
            2'd0: msg = 8'h1b; 2'd1: msg = "["; 2'd2: msg = "0"; default: msg = "m";
        endcase else if (!fail) case (i)
            4'd0: msg = " "; 4'd1: msg = "O"; 4'd2: msg = "K"; 4'd3: msg = " "; 4'd4: msg = "2"; 4'd5: msg = "0";
            4'd6: msg = "4"; 4'd7: msg = "8"; 4'd8: msg = "K"; 4'd9: msg = 8'h0d; 4'd10: msg = 8'h0a; default: msg = 8'h00;
        endcase else case (i)
            4'd0: msg = " "; 4'd1: msg = "N"; 4'd2: msg = "G"; 4'd3: msg = "@";
            4'd4: msg = hexc({2'b00, fa[21:20]}); 4'd5: msg = hexc(fa[19:16]); 4'd6: msg = hexc(fa[15:12]);
            4'd7: msg = hexc(fa[11:8]); 4'd8: msg = hexc(fa[7:4]); 4'd9: msg = hexc(fa[3:0]);
            4'd10: msg = 8'h0d; 4'd11: msg = 8'h0a; default: msg = 8'h00;
        endcase
        end
    endfunction
    // registered (the address and the pass are stable for several clocks before the values are used)
    reg [7:0]  td_r, t_got_r;
    reg [21:0] cw_n;                                 // cw + 1, registered (the carry chain of the counter was the critical path)
    reg        cw_last, cw_pg;
    always @(posedge clk) begin
        msg_q   <= msg(mi, t_fail, t_faddr);
        td_r    <= tdata;
        cw_n    <= cw + 1'b1;
        t_got_r <= cw[0] ? ps_dout_m[15:8] : ps_dout_m[7:0];
        cw_last <= (cw == MT_LAST);
        cw_pg   <= (cw[17:0] == 18'h3ffff);
    end

    always @(posedge clk) begin
        c_wr <= 1'b0;
        t_rd <= 1'b0;
        st_wr <= 1'b0; st_d <= st_wr; st_d2 <= st_d;
        if (p_go && !st_wr && !st_d && !st_d2 && !acia_tx_full && !term_busy) begin st_wr <= 1'b1; st_byte <= p_ch; p_go <= 1'b0; end
        if (rst) begin
            cs_ <= C_WAIT; cw <= 0; bsy_d <= 0; rcnt <= 0; nreset_cpu <= 1'b0;
            tp <= MEMTEST ? 2'd0 : 2'd3; t_fail <= 1'b0; t_faddr <= 22'd0; mi <= 5'd0; p_go <= 1'b0; p_ch <= 8'h00;
        end else begin
            bsy_d <= {bsy_d[2:0], ps_busy_m};
            if (go_req) begin nreset_cpu <= 1'b0; rcnt <= 4'd0; end      // the mode register: reset the CPU (in the Level 2 mode)
            case (cs_)
                C_WAIT:  if (bsy_d == 4'b0000 && !ps_busy) cs_ <= MEMTEST ? M_CRED : C_CLR;
                M_CRED: if (MEMTEST && !p_go && !st_wr && !st_d) begin                   // the credit line first: "YUKARI Semiconductor Devices"
                    p_ch <= cred_q;
                    p_go <= 1'b1;
                    if (mi == 5'd29) begin mi <= 5'd0; cs_ <= M_HDR; end else mi <= mi + 1'b1;
                end
                M_HDR: if (MEMTEST && !p_go && !st_wr && !st_d) begin                    // "Matenro Memory " (tells this system from a plain sim09 board)
                    case (mi)
                        4'd0: p_ch <= "M"; 4'd1: p_ch <= "a"; 4'd2: p_ch <= "t"; 4'd3: p_ch <= "e";
                        4'd4: p_ch <= "n"; 4'd5: p_ch <= "r"; 4'd6: p_ch <= "o"; 4'd7: p_ch <= " ";
                        4'd8: p_ch <= "M"; 4'd9: p_ch <= "e"; 4'd10: p_ch <= "m"; 4'd11: p_ch <= "o";
                        4'd12: p_ch <= "r"; 4'd13: p_ch <= "y"; 4'd14: p_ch <= " ";
                        4'd15: p_ch <= 8'h1b; 5'd16: p_ch <= "["; 5'd17: p_ch <= "3"; 5'd18: p_ch <= "2"; default: p_ch <= "m";   // ESC [ 3 2 m: the > in green
                    endcase
                    p_go <= 1'b1;
                    if (mi == 5'd19) begin mi <= 5'd0; cs_ <= M_W; end else mi <= mi + 1'b1;
                end
                M_W: if (MEMTEST) begin c_wr <= 1'b1; cs_ <= M_WW; end
                M_WW: if (MEMTEST && !c_wr && !ps_busy_m && !bsy_d[0] && !bsy_d[1]) begin
                    if (cw_last) begin cw <= 0; cs_ <= M_R; end
                    else begin cw <= cw_n; cs_ <= M_W; end
                end
                M_R: if (MEMTEST) begin t_rd <= 1'b1; cs_ <= M_RW; end
                M_RW: if (MEMTEST && !t_rd && !ps_busy_m && !bsy_d[0] && !bsy_d[1]) cs_ <= M_RC;
                M_RC: if (MEMTEST && !p_go) begin
                    if (t_got_r != td_r && !t_fail) begin t_fail <= 1'b1; t_faddr <= cw; end
                    if (cw_pg || cw_last) begin p_ch <= ">"; p_go <= 1'b1; end   // one > for 256 KB
                    if (cw_last) begin
                        cw <= 0; tp <= tp + 1'b1;
                        cs_ <= (tp == 2'd2) ? M_FIN : M_W;
                    end else begin cw <= cw_n; cs_ <= M_R; end
                end
                M_FIN: if (MEMTEST && !p_go && !st_wr && !st_d) begin                    // " OK 2048K" or " NG @address"
                    // msg_q is one clock behind its inputs; mi changes only together with p_go, and p_go is up for several clocks
                    // (and the first character is a blank, ok or not), so it is always current when it is looked at
                    if (msg_q == 8'h00) cs_ <= C_CLR;                          // then clear (tp = 3: zero bytes)
                    else begin p_ch <= msg_q; p_go <= 1'b1; mi <= mi + 1'b1; end
                end
                C_CLR: begin                            // write zero bytes 0, 1, 2 ... 65535 (2 MB - 1 for Level 2; the access the controller was tested with)
                    c_wr <= 1'b1;
                    cs_  <= C_WAIT2;
                end
                C_WAIT2: if (!c_wr && !ps_busy_m && !bsy_d[0] && !bsy_d[1]) begin
                    if (cw == CLR_LAST) cs_ <= C_RUN;
                    else begin cw <= cw_n; cs_ <= C_CLR; end
                end
                C_RUN: if (ecyc) begin
                    if (rcnt == 4'd15) nreset_cpu <= 1'b1;
                    else rcnt <= rcnt + 1'b1;
                end
                default: cs_ <= C_WAIT;
            endcase
        end
    end
    reg run = 1'b0;                             // the start-up is over (a register of its own: it selects the PSRAM path)
    always @(posedge clk) run <= !rst && (cs_ == C_RUN);

    // ---------------------------------------------------------------- the access of a cycle
    reg        vma_pend;            // AVMA of the previous cycle = "valid" of this one
    reg [7:0]  rd_reg;
    reg        c_rd, c_cwr;
    reg [21:0] c_addr;
    reg [7:0]  c_wdata;
    reg        c_rsel;
    reg        c_isrd;              // the access under way is a read
    reg        mp_wait;             // one clk for the busy flag of the controller to show up
`ifdef CACHE
`ifdef CSTAT
    integer cs_hit = 0, cs_miss = 0, cs_wr = 0, cs_ecyc = 0, cs_hold = 0, cs_hold2 = 0;     // statistics of the simulation
    always @(posedge clk) begin
        if (ecyc) cs_ecyc = cs_ecyc + 1;
        if (ph == 2'd0 && div == PH_DIV - 1 && stall_ph) cs_hold = cs_hold + 1;
        if (ph == 2'd2 && div == PH_DIV - 1 && wr_hold) cs_hold2 = cs_hold2 + 1;
    end
`endif
    wire        cc_hit;             // the read cache: the access of c_addr is in it
`ifdef CCHIT0
    wire        cc_hit_use = 1'b0;  // diagnosis: the cache works but its hits are not used
`else
    wire        cc_hit_use = cc_hit;
`endif
    wire [7:0]  cc_hbyte, cf_byte;  // its byte; the byte of the line that a wide read has brought
`endif

    // I/O page decode
    wire [15:0] a      = cpu_a;
    wire [21:0] pa;
    // The address is stable for two phases before it is used, so its decoding is registered (one clock late).
    // Level 1: the registers are at $E000 (the page $E000-$E1FF); Level 2: at $FF80 (the same offsets), in the fixed page.
    wire        in_io  = l2 ? (a[15:7] == 9'h1ff) : (a[15:9] == 7'b1110000);
    wire [8:0]  off    = l2 ? {2'b00, a[6:0]} : a[8:0];
    reg io_acia, io_power, io_timer, io_disk, io_dctl, io_hit, io_quiet, rom_sel, io_mmu, io_map, io_ta, io_modr, io_xl, io_ssel, io_hctl, io_gfx;
`ifdef HCTL
    localparam HAS_H = 1;
`else
    localparam HAS_H = 0;
`endif
`ifdef SUBBOTH
    localparam [8:0] XL_LAST = 9'h04f;       // + $FFCF: the choice of the sub CPU (Z80 or 8088)
`else
    localparam [8:0] XL_LAST = 9'h04e;
`endif
    // Level 2: the registers of the clock are in the fixed page, and the OS reads the time with F$Move, i.e. through another
    // window of the same physical page ($7FFB1-B6).  In the simulator the registers live in that RAM; here a read of that
    // physical address gives the registers of the clock too.  (pa is declared below: it is the physical address of a.)
    reg  [21:0] pa_r;                                          // pa, a clock late: the decode of the alias is a clock later than the others (the address is stable long before it is used)
    always @(posedge clk) pa_r <= pa;
    wire        ta     = l2 && !in_io_q && (pa_r[21:3] == 19'h0fff6) && (pa_r[2:0] <= 3'd6);
    // the page and the offset, a clock late too: the decode below is then a second stage (two clocks after the address,
    // which is stable for more than 15 clocks before acc2)
    reg         in_io_q;
    reg  [8:0]  off_q;
    always @(posedge clk) begin in_io_q <= in_io; off_q <= off; end
    always @(posedge clk) begin
        io_ta    <= ta;
        io_modr  <= in_io_q && off_q == 9'h00e;                        // the mode register
        io_acia  <= in_io_q && off_q[8:1] == 8'd0;                   // $E000, $E001
        io_power <= in_io_q && off_q == 9'h00f;
        io_timer <= in_io_q && off_q >= 9'h030 && off_q <= 9'h036;
        io_disk  <= in_io_q && off_q >= 9'h040 && off_q <= 9'h047;
        io_dctl  <= in_io_q && off_q == 9'h049;                 // control / status of the asynchronous mode of the disk
        io_xl    <= in_io_q && off_q >= 9'h04a && off_q <= 9'h04e;                 // the cross link
        io_ssel  <= in_io_q && off_q == 9'h04f;                            // SUBSEL (SUBBOTH only)
        io_hctl  <= HAS_H && in_io_q && off_q == 9'h048;                    // HCTL (`define HCTL)
        io_gfx   <= HAS_H && in_io_q && off_q >= 9'h038 && off_q <= 9'h03d;  // GCTL PIDX PDAT PTXT PCOL PROW
        io_mmu   <= l2 && in_io_q && off_q == 9'h011;            // the task register
        io_map   <= l2 && in_io_q && off_q >= 9'h020 && off_q <= 9'h02f;   // the system map, the user map
        io_hit   <= (in_io_q && ((off_q[8:1] == 8'd0) || off_q == 9'h00f || off_q == 9'h00e || (off_q >= 9'h030 && off_q <= 9'h036) || (off_q >= 9'h040 && off_q <= 9'h047) || off_q == 9'h049
                              || (off_q >= 9'h04a && off_q <= XL_LAST) || (HAS_H && (off_q == 9'h048 || (off_q >= 9'h038 && off_q <= 9'h03d)))
                              || (l2 && (off_q == 9'h011 || (off_q >= 9'h020 && off_q <= 9'h02f))))) || ta;
        io_quiet <= !l2 && in_io_q && off_q < 9'h080 && !((off_q[8:1] == 8'd0) || off_q == 9'h00f || off_q == 9'h00e || (off_q >= 9'h030 && off_q <= 9'h036) || (off_q >= 9'h040 && off_q <= 9'h047) || off_q == 9'h049 || (off_q >= 9'h04a && off_q <= XL_LAST) || (HAS_H && (off_q == 9'h048 || (off_q >= 9'h038 && off_q <= 9'h03d))));
        rom_sel  <= !l2 && (a >= ROM_BASE);
    end

    // The MMU of the Level 2 machine: eight 8 KB blocks per task, the block numbers (up to 2 MB); the fixed page $FE00-$FFFF
    // is always physical $7FE00.  After the reset the system map is the one of the simulator: blocks 0-6 = $FF, block 7 = $3F.
    reg [7:0] map_s [0:7];
    reg [7:0] map_u [0:7];
    reg       tr;                                                // the task: 0 = the system map, 1 = the user map
    reg [7:0] tr_raw;                                            // what the guest wrote to $FF91
    wire [7:0]  blk    = (a[15:9] == 7'b1111111) ? 8'h3f : (tr ? map_u[a[15:13]] : map_s[a[15:13]]);
    assign      pa     = {1'b0, blk, a[12:0]};                   // the physical address of the CPU's address
    integer     mk;

    // ROM
    reg [7:0] rom [0:(1 << ROM_AW) - 1];
    reg [7:0] rom_q;
    initial $readmemh(ROM_FILE, rom);
    always @(posedge clk) rom_q <= rom[a[ROM_AW-1:0]];

    // devices
    wire [7:0] acia_status, acia_rdata;
    wire [7:0] timer_rdata;
    reg        acia_rd;                 // a clock after the read: rd_reg has taken the character by then
    always @(posedge clk) acia_rd <= acc2 && vma_pend && cpu_rnw && io_acia && off[0];
    reg  [7:0] acia_byte;
    reg        acia_cwr;                // one clock: a write to the control register
    reg  [7:0] acia_cbyte;
    wire       acia_wr = acia_pend && !acia_tx_full && !term_busy;    // the screen can also hold a character back
    assign term_stb  = acia_wr | st_wr;
    assign term_byte = st_wr ? st_byte : acia_byte;
    wire       timer_wr = acc2 && vma_pend && !cpu_rnw && io_timer;
    wire       iack     = acc2 && cpu_bs && !cpu_ba;

    acia_uart #(.BAUD_DIV(BAUD_DIV)) acia (
        .clk(clk), .rst(rst), .rxd(rxd), .txd(txd),
        .rd_data(acia_rd), .wr_data(acia_wr | st_wr), .wdata(st_wr ? st_byte : acia_byte),
        .wr_ctl(acia_cwr), .cdata(acia_cbyte),
        .tx_full(acia_tx_full), .status(acia_status), .rdata(acia_rdata), .irq(acia_irq)
    );

    reg rt_ecyc = 1'b0;
    always @(posedge clk) rt_ecyc <= (hb[4:0] == 5'd31) && !disk_hold;

    timer_rtc #(
        .FREERUN(FREERUN), .ECYC_PER_TICK(ECYC_PER_TICK), .ECYC_PER_SEC(ECYC_PER_SEC),
        .START_YEAR(RTC_YEAR), .START_MONTH(RTC_MONTH), .START_DAY(RTC_DAY),
        .START_HOUR(RTC_HOUR), .START_MIN(RTC_MIN), .START_SEC(RTC_SEC)
    ) timer (
        .clk(clk), .rst(rst), .ecyc(rt_ecyc),
        .wr(timer_wr), .off(off[2:0]), .wdata(cpu_d_out), .iack(iack),
        .rdata(timer_rdata), .irq(timer_irq)
    );

    // disk registers
    reg [7:0]  d_drive, d_lsn2, d_lsn1, d_lsn0, d_bufh, d_bufl, d_47;
    reg [7:0]  e040;
    reg        dgo, dwr;
    wire [7:0] disk_result;
    wire       d_rd, d_wr;
    wire [21:0] d_addr;
    wire [7:0]  d_din;
    wire        sd_ready, sd_fail, sd_active;
    wire [5:0]  sd_st;
    reg         disk_busy_d;
    assign disk_irq = d_ien & d_done;
    reg         disk_rd;                // a clock after the read of $E040, the result of the disk command
    always @(posedge clk) disk_rd <= acc2 && vma_pend && cpu_rnw && io_disk && off[2:0] == 3'd0;

    sd_disk #(.DRIVE1_BLK(DRIVE1_BLK)) disk (
        .clk(clk), .rst(rst),
        .go(dgo), .wr(dwr), .drive(d_drive), .lsn({d_lsn2, d_lsn1, d_lsn0}), .buf_addr({d_bufh, d_bufl}),
        .busy(disk_busy), .result(disk_result),
        .m_rd(d_rd), .m_wr(d_wr), .m_addr(d_addr), .m_din(d_din), .m_dout(m4_rdata), .m_busy(m4_req),
        .sd_clk(sd_clk), .sd_mosi(sd_mosi), .sd_miso(sd_miso), .sd_cs(sd_cs),
        .ready(sd_ready), .fail(sd_fail), .active(sd_active), .dbg_st(sd_st)
    );

    // io read data
    reg [7:0] io_rdata, io_rdata_d;
    always @(*) begin
        io_rdata = 8'h00;
        if (io_acia)       io_rdata = off[0] ? acia_rdata : acia_status;
        else if (io_timer || io_ta) io_rdata = timer_rdata;
        else if (io_xl)    io_rdata = xl_rdata;
        else if (io_hctl)  io_rdata = {6'b000000, win_hi, kj_ok};          // $FFC8
`ifdef HCTL
        else if (io_gfx)   io_rdata = (off[2:0] == 3'd0) ? {hpd_q[1], 4'd0, sv_r, ov_r, gfx_r} : (off[2:0] == 3'd1) ? pidx_r : (off[2:0] == 3'd3) ? {7'd0, pc_r} : (off[2:0] == 3'd4) ? {1'b0, pcol_r} : (off[2:0] == 3'd5) ? {3'd0, prow_r} : 8'd0;
`endif
`ifdef SUBBOTH
        else if (io_ssel)  io_rdata = {6'b000000, sel8, ~sel8};            // $FFCF: 1 = Z80, 2 = 8088
`endif
        else if (io_dctl)  io_rdata = {d_done, d_ien, 4'b0000, d_async, disk_busy};      // $E049: the status
        else if (io_mmu)   io_rdata = tr_raw;
        else if (io_map)   io_rdata = off[3] ? map_u[off[2:0]] : map_s[off[2:0]];
    end
    always @(*)
        case (off[2:0])
            3'd0: io_rdata_d = e040;
            3'd1: io_rdata_d = d_drive;
            3'd2: io_rdata_d = d_lsn2;
            3'd3: io_rdata_d = d_lsn1;
            3'd4: io_rdata_d = d_lsn0;
            3'd5: io_rdata_d = d_bufh;
            3'd6: io_rdata_d = d_bufl;
            default: io_rdata_d = d_47;
        endcase

    // The address is stable long before the access (see above), so the read data of the registers are registered first:
    // the mux (the maps are RAM, the clock, the XLINK) and the choice of rd_reg were one long path.
    // (two stages: the disk registers and the others are chosen a clock before the last choice; the data at acc2 is then two
    // clocks old, which is right for all of them: none changes in the clocks before a read of it by the CPU)
    reg [7:0] io_rdata_q, io_rd_o, io_rd_dk;
    reg       io_rd_isdk;
    always @(posedge clk) begin
        io_rd_o    <= io_rdata;
        io_rd_dk   <= io_rdata_d;
        io_rd_isdk <= io_disk;
        io_rdata_q <= io_rd_isdk ? io_rd_dk : io_rd_o;
    end

    // a write to the disk registers: noted at the access, done one clock later (c_wdata holds the byte)
    reg       w_disk = 1'b0;
    reg [2:0] w_off;
    always @(posedge clk) begin
        w_disk <= acc2 && vma_pend && !cpu_rnw && io_disk;
        w_off  <= off[2:0];
    end

    // A write of the 6809 to the map ($FFA0-$FFAF) or to the mode register ($A2 / $A3), decided at acc_go (one clock before
    // acc2, when the access is done): vma_pend, the decoded address and the data are stable by then.
    reg        mw_s = 1'b0, mw_u = 1'b0, mo_a2 = 1'b0, mo_a3 = 1'b0;
    reg [2:0]  mw_i;
    reg [7:0]  mw_d;
    always @(posedge clk) begin
        mw_s  <= acc_go && vma_pend && !cpu_rnw && io_map && !off[3];
        mw_u  <= acc_go && vma_pend && !cpu_rnw && io_map &&  off[3];
        mo_a2 <= acc_go && vma_pend && !cpu_rnw && io_modr && cpu_d_out == 8'ha2;
        mo_a3 <= acc_go && vma_pend && !cpu_rnw && io_modr && cpu_d_out == 8'ha3;
        mw_i  <= off[2:0];
        mw_d  <= cpu_d_out;
    end

    always @(posedge clk) begin
        dgo  <= 1'b0;
        acia_cwr <= 1'b0;
        go_req <= 1'b0;
        c_rd <= 1'b0;
        c_cwr <= 1'b0;
`ifdef HCTL
        pal_we_r <= 1'b0;
`endif
        disk_busy_d <= disk_busy;
        if (disk_busy_d && !disk_busy) begin e040 <= disk_result; if (d_arun) d_done <= 1'b1; end
        if (disk_rd) d_done <= 1'b0;                                    // the guest has read the result
        if (rst) begin
            mem_pend <= 1'b0; mp_wait <= 1'b0; vma_pend <= 1'b1; pwroff <= 1'b0; reboot_r <= 1'b0; osrun <= 1'b0; acia_pend <= 1'b0;
`ifdef HCTL
            kj_ok <= 1'b0; win_hi <= 1'b0; gfx_r <= 1'b0; ov_r <= 1'b0; sv_r <= 1'b0; pc_r <= 1'b0; pcol_r <= 7'd0; prow_r <= 5'd0; pcnt_r <= 2'd0; pidx_r <= 8'd0;
`endif
`ifdef SUBBOTH
            sel8 <= SUB_DEF8;
`endif
            for (mk = 0; mk < 8; mk = mk + 1) begin map_s[mk] <= 8'hff; map_u[mk] <= 8'hff; end
            map_s[7] <= 8'h3f; tr <= 1'b0; tr_raw <= 8'hff; l2 <= 1'b0;
            rd_reg <= 8'h00; e040 <= 8'h00; d_drive <= 0; d_lsn2 <= 0; d_lsn1 <= 0; d_lsn0 <= 0;
            d_bufh <= 0; d_bufl <= 0; d_47 <= 0; d_async <= 0; d_ien <= 0; d_arun <= 0; d_done <= 0;
        end else begin
            c_addr  <= l2 ? pa : {6'd0, a};
            c_wdata <= cpu_d_out;
            c_rsel  <= a[0];
            if (acc2) begin
                vma_pend <= cpu_avma;
                if (vma_pend) begin
                    if (io_hit) begin
                        if (cpu_rnw) rd_reg <= io_rdata_q;
                        else begin
                            if (io_power && cpu_d_out == 8'ha5) begin pwroff <= 1'b1; osrun <= 1'b0; end      // shutdown: LED5 on, LED4 off
                            if (io_power && cpu_d_out == 8'ha4) osrun <= 1'b1;
                            if (io_power && (cpu_d_out == 8'ha7 || cpu_d_out == 8'ha6)) reboot_r <= 1'b1;      // reboot: the same as the reset button
                            if (io_dctl) begin d_async <= cpu_d_out[0]; d_ien <= cpu_d_out[7]; end      // $E049
`ifdef HCTL
                            if (io_hctl) begin kj_ok <= cpu_d_out[0]; win_hi <= cpu_d_out[1]; end      // $FFC8
                            if (io_gfx && off[2:0] == 3'd0) begin gfx_r <= cpu_d_out[0]; ov_r <= cpu_d_out[1]; sv_r <= cpu_d_out[2]; end                       // $FFB8
                            if (io_gfx && off[2:0] == 3'd1) begin pidx_r <= cpu_d_out; pcnt_r <= 2'd0; end      // $FFB9
                            if (io_gfx && off[2:0] == 3'd3) pc_r <= cpu_d_out[0];                                                          // $FFBB: the text screen of the PC (B800h)
                            if (io_gfx && off[2:0] == 3'd4) pcol_r <= cpu_d_out[6:0];                                                    // $FFBC: its cursor column
                            if (io_gfx && off[2:0] == 3'd5) prow_r <= cpu_d_out[4:0];                                                    // $FFBD: its cursor row
                            if (io_gfx && off[2:0] == 3'd2) begin                                            // $FFBA
                                if (pcnt_r == 2'd0) begin pred_r <= cpu_d_out; pcnt_r <= 2'd1; end
                                else if (pcnt_r == 2'd1) begin pgrn_r <= cpu_d_out; pcnt_r <= 2'd2; end
                                else begin pblu_r <= cpu_d_out; pcnt_r <= 2'd0; pal_we_r <= 1'b1; pal_ix_r <= pidx_r; pidx_r <= pidx_r + 8'd1; end
                            end
`endif
`ifdef SUBBOTH
                            if (io_ssel && (cpu_d_out == 8'd1 || cpu_d_out == 8'd2)) sel8 <= cpu_d_out[1];      // $FFCF
`endif
                            if (io_mmu) begin tr_raw <= cpu_d_out; tr <= cpu_d_out[0]; end
                            if (io_modr) begin acia_cwr <= 1'b1; acia_cbyte <= 8'h03; d_async <= 1'b0; d_ien <= 1'b0; end      // a new machine mode: the ACIA interrupts are off
                            if (io_acia && !off[0]) begin
                                acia_cwr <= 1'b1;                   // the control register: interrupt enables, master reset
                                acia_cbyte <= cpu_d_out;
                            end
                            if (io_acia && off[0]) begin
                                acia_pend <= 1'b1;                  // the guest does not look at TDRE: wait for it here
                                acia_byte <= cpu_d_out;
                            end
                        end
                    end else if (cpu_rnw && rom_sel) begin
                        rd_reg <= rom_q;
                    end else if (!cpu_rnw && (rom_sel || io_quiet)) begin
                        // read-only memory, or an unused register: the write is lost
                    end else begin                                    // RAM
`ifdef CACHE
`ifdef CSTAT
                        if (cpu_rnw) begin if (cc_hit) cs_hit = cs_hit + 1; else cs_miss = cs_miss + 1; end else cs_wr = cs_wr + 1;
`endif
                        if (cpu_rnw && cc_hit_use) rd_reg <= cc_hbyte;       // a hit of the read cache: no access of the SDRAM, the CPU does not wait
                        else begin
`endif
                        c_rd    <= cpu_rnw;
                        c_cwr   <= ~cpu_rnw;
                        c_isrd  <= cpu_rnw;
`ifdef POSTW
                        // a write is posted: the CPU does not wait for it (ph 2 of the next cycle waits until master 0 is free again)
                        if (cpu_rnw) begin mem_pend <= 1'b1; mp_wait <= 1'b1; end
`else
                        mem_pend <= 1'b1;
                        mp_wait  <= 1'b1;
`endif
`ifdef CACHE
                        end
`endif
                    end
                end
            end
            if (w_disk)
                case (w_off)
                    3'd0: begin
                        if (c_wdata == 8'h81 || c_wdata == 8'h55) begin
                            if (!disk_busy) begin                         // (a command that is under way is not disturbed)
                                dgo <= 1'b1; dwr <= (c_wdata == 8'h55);
                                d_arun <= d_async; d_done <= 1'b0;
                                if (d_async) e040 <= 8'hfe;              // not finished: the result comes at the end
                                dm_idx  <= d_bufh[7:5];
                                dm_blk0 <= tr ? map_u[d_bufh[7:5]] : map_s[d_bufh[7:5]];
                                dm_blk1 <= tr ? map_u[d_bufh[7:5] + 3'd1] : map_s[d_bufh[7:5] + 3'd1];
                            end
                        end else e040 <= 8'hff;                       // no VRBF (host files) on the FPGA
                    end
                    3'd1: d_drive <= c_wdata;
                    3'd2: d_lsn2  <= c_wdata;
                    3'd3: d_lsn1  <= c_wdata;
                    3'd4: d_lsn0  <= c_wdata;
                    3'd5: d_bufh  <= c_wdata;
                    3'd6: d_bufl  <= c_wdata;
                    default: d_47 <= c_wdata;
                endcase
            // the map registers and the mode register: written with the strobes of the clock before (mw_*, mo_*: registered at
            // acc_go, so the long decode of the access is not in front of the 32 map registers)
            if (mw_s) map_s[mw_i] <= mw_d;
            if (mw_u) map_u[mw_i] <= mw_d;
            if (mo_a2 && !l2) begin                                   // to the Level 2 mode: the identity map for the blocks 0-6
                l2 <= 1'b1; tr <= 1'b0; tr_raw <= 8'hff;
                for (mk = 0; mk < 7; mk = mk + 1) map_s[mk] <= mk[7:0];
                map_s[7] <= 8'h3f;
            end
            if (mo_a3 && l2) begin                                    // reset the CPU with the maps of the reset
                go_req <= 1'b1; tr <= 1'b0; tr_raw <= 8'hff;
                for (mk = 0; mk < 8; mk = mk + 1) begin map_s[mk] <= 8'hff; map_u[mk] <= 8'hff; end
                map_s[7] <= 8'h3f;
            end
            if (acia_wr) acia_pend <= 1'b0;
            if (xl_cap) rd_reg <= xl_rdata;                           // MATENRO: after a window read
            if (mem_pend) begin
                if (mp_wait) mp_wait <= 1'b0;                          // the request is on its way
                else if (!ps_busy_m) begin
                    mem_pend <= 1'b0;
`ifdef CACHE
                    if (c_isrd) rd_reg <= cf_byte;                       // the byte of the line that the wide read brought
`else
                    if (c_isrd) rd_reg <= c_rsel ? ps_dout_m[15:8] : ps_dout_m[7:0];
`endif
                end
            end
        end
    end

    // master 0 of the PSRAM arbiter: the start-up (memory test, clear), the disk and the CPU.  Their pulses
    // become a request that is held until the arbiter has done it; ps_busy_m is high from the clock of the pulse
    // until then (so no master has to count clocks).
    // the buffer address of the disk port is a logical address: it goes through the map that is active (like the simulator)
    wire [15:0] dl     = d_addr[15:0];
    wire [7:0]  dblk   = (dl[15:9] == 7'b1111111) ? 8'h3f : (dl[15:13] == dm_idx) ? dm_blk0 : dm_blk1;
    wire [21:0] d_pa   = {1'b0, dblk, dl[12:0]};
    wire use_clr  = !run;
    wire m_rd_s   = use_clr ? t_rd : xw_act ? xw_rdp : c_rd;
    wire m_wr_s   = use_clr ? c_wr : xw_act ? xw_wrp : c_cwr;
    wire m0_pulse = m_rd_s | m_wr_s;
    reg  [21:0] m0_addr;
    reg  [7:0]  m0_din;
    wire        m0_ack;
    reg         m0_wide = 1'b0, m0_cpuw = 1'b0;
    always @(posedge clk) begin
        if (m0_ack) m0_req <= 1'b0;
        if (m0_pulse) begin
            m0_req  <= 1'b1;
            m0_wrr  <= m_wr_s;
            m0_wide <= !use_clr && !xw_act && c_rd;                 // a read of the CPU: a whole line for the read cache (CACHE)
            m0_cpuw <= !use_clr && !xw_act && c_cwr;                // a write of the CPU: the cache is updated, not invalidated
            m0_addr <= use_clr ? cw : xw_act ? {win_hi, win_addr} : c_addr;
            m0_din  <= use_clr ? td_r : xw_act ? win_wdata : c_wdata;
        end
    end
    assign ps_busy_m = m0_req;                  // (high from the clock after the pulse: nobody looks at the clock of the pulse itself)

    // master 4 of the arbiter: the disk (byte reads / writes of the sector; a request held until the ack), the lowest priority:
    // it gets the gaps between the accesses, so that the 6809 goes on while the sector is transferred.
    always @(posedge clk) begin
        if (m4_ack || rst) m4_req <= 1'b0;
        if ((d_rd | d_wr) && !rst) begin
            m4_req  <= 1'b1;
            m4_wrr  <= d_wr;
            m4_addr <= l2 ? d_pa : d_addr;
            m4_din  <= d_din;
        end
    end

    psram_arb4 arb (
        .clk(clk), .rst(rst),
        .c_rd(ps_rd), .c_wr(ps_wr), .c_addr(ps_addr), .c_din(ps_din), .c_bw(ps_bw), .c_dout(ps_dout), .c_busy(ps_busy), .c_issue(ps_issue), .c_wide(ps_wide_i), .c_sel(ps_sel),
        .m0_req(m0_req), .m0_wr(m0_wrr), .m0_wide(m0_wide), .m0_addr(m0_addr), .m0_din(m0_din), .m0_ack(m0_ack), .m0_rdata(ps_dout_m),
        .m1_req(x1_req), .m1_addr(x1_addr), .m1_ack(x1_ack), .m1_rdata(x1_rdata),
        .m2_req(x2_req), .m2_addr(x2_addr), .m2_ack(x2_ack), .m2_rdata(x2_rdata),
        .m3_req(m3_go), .m3_wr(zm_wr), .m3_wide(m3_wide), .m3_addr(zm_vram ? {2'b11, 3'b000, zm_addr[16:0]} : {1'b0, zm_addr}), .m3_din(zm_wdata), .m3_ack(zm_ack_ps), .m3_rdata(zm_rdata_w),
        .m4_req(m4_req), .m4_wr(m4_wrr), .m4_addr(m4_addr), .m4_din(m4_din), .m4_ack(m4_ack), .m4_rdata(m4_rdata)
    );

`ifdef CACHE
    assign ps_wide = ps_wide_i;
    // ---------------------------------------------------------------- the read cache of the 6809 (rcache.v, docs/TN20K.md 2.4 A)
    // lookup with c_addr (stable long before acc2); a miss reads the whole 32 bit word (wide) and fills the line with the acknowledge; writes of the CPU
    // update the line (write-through), writes of every other master of the SDRAM (and the window, the start-up clear) invalidate it.
    reg         cf_we = 1'b0, cu_we = 1'b0;
    reg  [19:0] cf_a;
    reg  [31:0] cf_d;
    wire        ci_we = ps_wr && !(ps_sel == 3'd0 && m0_cpuw);
    // The word is taken with dv, the clock in which the controller has it (not with the acknowledge of the arbiter: the arbiter sees ps_busy = ctl_busy
    // || fb_go, so when the frame buffer starts its burst in the clock that the controller is free, the acknowledge comes after the whole burst and
    // dout32 holds a pixel word by then).  cf_arm: the wide read of the CPU has been issued and its word has not come yet.
    reg         cf_arm = 1'b0;
    always @(posedge clk) begin
`ifdef CFACK
        // the first version (only for the experiment of docs/TN20K.md 2.4 A: the simulator does not show the failure of the board)
        cf_we <= m0_ack && m0_wide && !m0_wrr;
        if (m0_ack) begin cf_a <= m0_addr[21:2]; cf_d <= ps_dout32; end
`else
        cf_we <= 1'b0;
        if (ps_rd && ps_wide_i && ps_sel == 3'd0) cf_arm <= 1'b1;
        if (cf_arm && ps_dv) begin cf_arm <= 1'b0; cf_we <= 1'b1; cf_a <= m0_addr[21:2]; cf_d <= ps_dout32; end
`endif
        cu_we <= c_cwr;
    end
    assign      cf_byte = c_addr[1:0] == 2'd0 ? cf_d[7:0] : c_addr[1:0] == 2'd1 ? cf_d[15:8] : c_addr[1:0] == 2'd2 ? cf_d[23:16] : cf_d[31:24];
    rcache #(.IDX(CIDX)) cache (
        .clk(clk), .rst(rst), .a(c_addr), .hit(cc_hit), .hbyte(cc_hbyte),
        .fill_we(cf_we), .fill_a(cf_a), .fill_d(cf_d),
        .upd_we(cu_we), .upd_d(c_wdata),
        .inv_we(ci_we), .inv_a(ps_addr[21:2])
    );
`else
    assign ps_wide = 1'b0;
`endif

    // ---------------------------------------------------------------- MATENRO: the cross link and the Z80
    // 6809 side: a read or a write of $4A-$4E is one clock pulse at the access (acc2); after a read the data are taken
    // again when the window (if it was a read of XDAT) is done, so the CPU waits (xl_rcap) until then.
    wire [2:0]  xl_a   = off[2:0] - 3'd2;                         // $4A..$4E -> 0..4
    // the read / write strobes of the XLINK at acc2, decided at acc_go (registers: vma_pend and the decode were in front of the
    // window address counter); the register number and the data stay live (stable long before)
    reg         xl_re = 1'b0, xl_we = 1'b0;
    always @(posedge clk) begin
        xl_re <= acc_go && vma_pend && io_xl &&  cpu_rnw;
        xl_we <= acc_go && vma_pend && io_xl && !cpu_rnw;
    end
    always @(posedge clk) begin
        if (rst) begin xl_rcap <= 1'b0; xl_cnt <= 3'd0; end
        else begin
            if (xl_re && xl_win) begin xl_rcap <= 1'b1; xl_cnt <= 3'd4; end      // (only a window read comes late; the others are right at the access)
            else if (xl_cnt != 3'd0) xl_cnt <= xl_cnt - 1'b1;
            else if (xl_cap) xl_rcap <= 1'b0;                          // (rd_reg takes the byte in the main block)
        end
    end

    // window: the XLINK asks for a physical byte; the port of master 0 serves it (nobody else uses it: the CPU waits)
    wire        win_req, win_wr, win_ack;
    reg  [7:0]  win_rdata;
    reg         xw_go = 1'b0, win_ack_r = 1'b0;
    reg         win_wr_q;
    always @(posedge clk) begin
        xw_rdp <= 1'b0; xw_wrp <= 1'b0; win_ack_r <= 1'b0;
        if (rst) begin xw_act <= 1'b0; xw_go <= 1'b0; end
        else begin
            if (win_req && !win_hit && !xw_act && !win_ack_r && !xw_go) begin       // start: choose the source, then pulse
                xw_act <= 1'b1; xw_go <= 1'b1; win_wr_q <= win_wr;
            end else if (xw_go) begin
                xw_go <= 1'b0;
                xw_rdp <= !win_wr_q; xw_wrp <= win_wr_q;
            end
            if (xw_act && !xw_go && !xw_rdp && !xw_wrp && m0_ack) begin
                xw_act <= 1'b0; win_ack_r <= 1'b1;
                win_rdata <= win_addr[0] ? ps_dout_m[15:8] : ps_dout_m[7:0];
            end
            if (wb_ack) win_rdata <= wb_rdata;
        end
    end
    // the shared RAM in the BSRAM (shr_ap.v): the block SHR_BLK is served there, for the window and for the Z80
    reg         wb_ack_q = 1'b0;
    assign win_ack = win_ack_r | wb_ack_q;
    always @(posedge clk) wb_ack_q <= wb_ack;

    // the Z80 and its memory port (master 3 of the arbiter)
`ifdef CACHE
    // the read cache of the sub CPU (a second rcache.v, 4 KB, the same 4 byte lines): a read that is in it is acknowledged from it at once and does not
    // go to the arbiter; a read that is not (and is not in the shared RAM or the picture) is a wide read, whose word goes into the cache and gives the byte.
    wire [20:0] sc_a     = zm_req ? zm_addr : zm_lk;                    // the look-up: the address of the bus, then (a write has its own) of the request
    wire        sc_nc    = sv_r && (sc_a[20:17] == 4'b0111);            // the picture (the blocks $70-$7F): not cached
    wire        sc_hit;
    wire [7:0]  sc_hbyte;
    reg         sc_done = 1'b0, sc_ack = 1'b0;                          // this request has been acknowledged by the cache
    reg         sc_sent = 1'b0;                                         // this request has been offered to the arbiter: no hit any more (an acknowledge of the arbiter would follow)
    reg  [7:0]  sc_byte;
    wire        sc_use   = zm_req && !zm_wr && !zb_hit && !sc_nc && sc_hit && !sc_done && !sc_sent;
    always @(posedge clk) begin
        sc_ack <= 1'b0;
        if (!zm_req) begin sc_done <= 1'b0; sc_sent <= 1'b0; end
        else begin
            if (sc_use) begin sc_done <= 1'b1; sc_ack <= 1'b1; sc_byte <= sc_hbyte; end
            if (m3_go) sc_sent <= 1'b1;
        end
    end
    assign      m3_go    = zm_req && !zb_hit && !sc_use && !sc_done;
`ifdef CSTAT
    // statistics of the simulation: the reads of the sub CPU by where they are served (the request is counted once, at its first clock)
    integer ss_hit = 0, ss_miss = 0, ss_shr = 0, ss_nc = 0, ss_wr = 0;
    integer ss_wrd = 0, ss_wwr = 0, ss_wrdmiss = 0;                 // clocks of the sub CPU's access that wait for the acknowledge: reads, writes (all reads, and the reads that miss)
    reg zm_req_q = 1'b0;
    always @(posedge clk) begin
        zm_req_q <= zm_req;
        if (zm_req && !zm_req_q) begin
            if (zm_wr) ss_wr = ss_wr + 1;
            else if (zb_hit) ss_shr = ss_shr + 1;
            else if (sc_nc) ss_nc = ss_nc + 1;
        end
        if (sc_use && !sc_done) ss_hit = ss_hit + 1;
        if (zm_req && !zm_ack) begin
            if (zm_wr) ss_wwr = ss_wwr + 1; else ss_wrd = ss_wrd + 1;
            if (!zm_wr && !zb_hit && !sc_nc) ss_wrdmiss = ss_wrdmiss + 1;
        end
        if (m3_go && m3_wide && !zm_wr && !sc_sent) ss_miss = ss_miss + 1;
    end
`endif
    assign      m3_wide  = !zm_wr && !sc_nc;
    // fills: the word of a wide read of master 3 is taken with dv (like the 6809's: the acknowledge of the arbiter may come after a burst of the frame buffer)
    reg         sf_arm = 1'b0, sf_we = 1'b0, su_we = 1'b0;
    reg  [19:0] sf_a;
    reg  [31:0] sf_d;
    reg  [2:0]  su_cnt = 3'd0;
    always @(posedge clk) begin
        sf_we <= 1'b0; su_we <= 1'b0;
        if (ps_rd && ps_wide_i && ps_sel == 3'd3) sf_arm <= 1'b1;
        if (sf_arm && ps_dv) begin sf_arm <= 1'b0; sf_we <= 1'b1; sf_a <= ps_addr[21:2]; sf_d <= ps_dout32; end
        // an own write updates the line, once, some clocks after the request (the look-up address of a write is wr_phys: it needs to settle)
        if (!zm_req || !zm_wr) su_cnt <= 3'd0;
        else if (su_cnt != 3'd7) begin su_cnt <= su_cnt + 3'd1; if (su_cnt == 3'd3 && !zb_hit && !sc_nc) su_we <= 1'b1; end
    end
    wire [7:0]  sf_byte = zm_addr[1:0] == 2'd0 ? sf_d[7:0] : zm_addr[1:0] == 2'd1 ? sf_d[15:8] : zm_addr[1:0] == 2'd2 ? sf_d[23:16] : sf_d[31:24];
    rcache #(.IDX(SIDX)) scache (
        .clk(clk), .rst(rst), .a(sc_a), .hit(sc_hit), .hbyte(sc_hbyte),
        .fill_we(sf_we), .fill_a(sf_a), .fill_d(sf_d),
        .upd_we(su_we), .upd_d(zm_wdata),
        .inv_we(ps_wr && ps_sel != 3'd3), .inv_a(ps_addr[21:2])
    );
    wire [7:0]  zm_rdata = zb_ack ? zb_rdata : sc_ack ? sc_byte : sc_nc ? (zm_addr[0] ? zm_rdata_w[15:8] : zm_rdata_w[7:0]) : sf_byte;
    assign zm_ack = zm_ack_ps | zb_ack | sc_ack;
`else
    assign      m3_go    = zm_req && !zb_hit;
    assign      m3_wide  = 1'b0;
    wire [7:0]  zm_rdata = zb_ack ? zb_rdata : zm_addr[0] ? zm_rdata_w[15:8] : zm_rdata_w[7:0];
    assign zm_ack = zm_ack_ps | zb_ack;
`endif
    shr_ap #(.BLK(SHR_BLK)) shr (
        .clk(clk), .rst(rst),
        .a_req(zm_req), .a_wr(zm_wr), .a_addr(zm_addr), .a_wdata(zm_wdata), .a_hit(zb_hit), .a_ack(zb_ack), .a_rdata(zb_rdata),
        .w_req(win_req && !win_hi), .w_wr(win_wr), .w_addr(win_addr), .w_wdata(win_wdata), .w_hit(win_hit), .w_ack(wb_ack), .w_rdata(wb_rdata)
    );
`ifdef SUBBOTH
    // the Z80 and the 8088 both are in the FPGA; the register SUBSEL ($FFCF: 1 = Z80, 2 = 8088) says which one is on the cross link.
    // The other one is held in reset (it has no state: after a change the chosen one starts from its reset like after the power on).
    wire        z_irq, z_firq, z_wait, z_win, z_on, e_irq, e_firq, e_wait, e_win, e_on;
    wire [7:0]  z_rdata, e_rdata;
    wire        z_wreq, z_wwr, e_wreq, e_wwr, z_mreq, z_mwr, e_mreq, e_mwr;
    wire [20:0] z_wadr, e_wadr, z_madr, e_madr, z_lk, e_lk;
    wire [7:0]  z_wdat, e_wdat, z_mdat, e_mdat;
    wire [39:0] z_dbg, e_dbg;
    z80_sub #(.CLKDIV(CZ_DIV), .CLK_KHZ(CLK_HZ / 1000)) subz (
        .clk(clk), .rst(rst || sel8),
        .m_addr(xl_a), .m_re(xl_re && !sel8), .m_we(xl_we && !sel8), .m_wdata(cpu_d_out), .m_rdata(z_rdata), .m_wait(z_wait), .m_win(z_win), .sub_on(z_on),
        .irq_o(z_irq), .firq_o(z_firq),
        .win_req(z_wreq), .win_wr(z_wwr), .win_addr(z_wadr), .win_wdata(z_wdat), .win_ack(win_ack), .win_rdata(win_rdata),
        .mem_req(z_mreq), .mem_wr(z_mwr), .mem_addr(z_madr), .mem_lk(z_lk), .mem_wdata(z_mdat), .mem_ack(zm_ack), .mem_rdata(zm_rdata),
        .con_we(), .con_data(), .pwr_we(), .pwr_data(), .z80_halted(), .dbg_z(z_dbg)
    );
    i8088_sub #(.CLKDIV(C88_DIV), .CLK_KHZ(CLK_HZ / 1000)) sube (
        .clk(clk), .rst(rst || !sel8),
        .m_addr(xl_a), .m_re(xl_re && sel8), .m_we(xl_we && sel8), .m_wdata(cpu_d_out), .m_rdata(e_rdata), .m_wait(e_wait), .m_win(e_win), .sub_on(e_on),
        .irq_o(e_irq), .firq_o(e_firq),
        .win_req(e_wreq), .win_wr(e_wwr), .win_addr(e_wadr), .win_wdata(e_wdat), .win_ack(win_ack), .win_rdata(win_rdata),
        .mem_req(e_mreq), .mem_wr(e_mwr), .mem_addr(e_madr), .mem_lk(e_lk), .mem_wdata(e_mdat), .mem_ack(zm_ack), .mem_rdata(zm_rdata),
        .con_we(), .con_data(), .pwr_we(), .pwr_data(), .z80_halted(), .dbg_z(e_dbg)
    );
    assign xl_rdata  = sel8 ? e_rdata : z_rdata;
    assign xl_wait   = sel8 ? e_wait  : z_wait;
    assign xl_win    = sel8 ? e_win   : z_win;
    assign xl_on     = sel8 ? e_on    : z_on;
    assign xl_irq    = sel8 ? e_irq   : z_irq;
    assign xl_firq   = sel8 ? e_firq  : z_firq;
    assign win_req   = sel8 ? e_wreq  : z_wreq;
    assign win_wr    = sel8 ? e_wwr   : z_wwr;
    assign win_addr  = sel8 ? e_wadr  : z_wadr;
    assign win_wdata = sel8 ? e_wdat  : z_wdat;
    assign zm_req    = sel8 ? e_mreq  : z_mreq;
    assign zm_wr     = sel8 ? e_mwr   : z_mwr;
    assign zm_addr   = sel8 ? e_madr  : z_madr;
    assign zm_lk     = sel8 ? e_lk    : z_lk;
    assign zm_wdata  = sel8 ? e_mdat  : z_mdat;
    assign dbg_z80   = sel8 ? e_dbg   : z_dbg;
`elsif SUB8088
    // the 8088 (MCL86) instead of the Z80: the Tang Nano 20K machine (fpga/tn20k)
    i8088_sub #(.CLKDIV(C88_DIV), .CLK_KHZ(CLK_HZ / 1000)) sub (
        .clk(clk), .rst(rst),
        .m_addr(xl_a), .m_re(xl_re), .m_we(xl_we), .m_wdata(cpu_d_out), .m_rdata(xl_rdata), .m_wait(xl_wait), .m_win(xl_win), .sub_on(xl_on),
        .irq_o(xl_irq), .firq_o(xl_firq),
        .win_req(win_req), .win_wr(win_wr), .win_addr(win_addr), .win_wdata(win_wdata), .win_ack(win_ack), .win_rdata(win_rdata),
        .mem_req(zm_req), .mem_wr(zm_wr), .mem_addr(zm_addr), .mem_lk(zm_lk), .mem_wdata(zm_wdata), .mem_ack(zm_ack), .mem_rdata(zm_rdata),
        .con_we(), .con_data(), .pwr_we(), .pwr_data(), .z80_halted(), .dbg_z(dbg_z80)
    );
`else
    z80_sub #(.CLKDIV(CZ_DIV), .CLK_KHZ(CLK_HZ / 1000)) sub (
        .clk(clk), .rst(rst),
        .m_addr(xl_a), .m_re(xl_re), .m_we(xl_we), .m_wdata(cpu_d_out), .m_rdata(xl_rdata), .m_wait(xl_wait), .m_win(xl_win), .sub_on(xl_on),
        .irq_o(xl_irq), .firq_o(xl_firq),
        .win_req(win_req), .win_wr(win_wr), .win_addr(win_addr), .win_wdata(win_wdata), .win_ack(win_ack), .win_rdata(win_rdata),
        .mem_req(zm_req), .mem_wr(zm_wr), .mem_addr(zm_addr), .mem_lk(zm_lk), .mem_wdata(zm_wdata), .mem_ack(zm_ack), .mem_rdata(zm_rdata),
        .con_we(), .con_data(), .pwr_we(), .pwr_data(), .z80_halted(), .dbg_z(dbg_z80)
    );
`endif

    // ---------------------------------------------------------------- feed the CPU
    always @(*) cpu_d_in = rd_reg;

    // ---------------------------------------------------------------- the LEDs (active low)
    // LED2: card ready (steady) / card failed (blinking); LED4: the OS has been started
    assign reboot_req = reboot_r;
`ifdef SUBBOTH
    // the second display (S2): LED0 = the Z80 is enabled, LED1 = the 8088 is enabled (SUBBOTH: only one of them is on the cross link)
    assign led = led_mode ? ~{4'b0000, xl_on && sel8, xl_on && !sel8}
`else
    assign led = led_mode ? ~{5'b00000, xl_on}
`endif
                          : ~{pwroff, osrun, sd_active, sd_fail ? hb[22] : sd_ready, run, hb[23]};

    // the status word of the debug UART (dbg_uart, DEBUG=1) and the watchdog of the board: what holds the CPU
    //   15 xl_wait  14 xl_rcap  13 xw_act  12 m0_req  11 zm_req  10 ps_busy  9 mem_pend  8 acia_pend
    //    7 disk_busy 6 pwroff   5 settle    4 stall    3 win_req  2:0 cs_
    assign dbg_status = {xl_wait, xl_rcap, xw_act, m0_req, zm_req, ps_busy, mem_pend, acia_pend,
                         disk_busy, pwroff, |settle, stall, win_req, cs_[2:0]};
    assign dbg_stall  = stall;

endmodule
