// SPDX-License-Identifier: MIT
// z80_soc.v - the Z80 side of the Matenro machine: Z80 core + XLINK + SMMU + shared RAM
//
// This is the sub CPU half of docs/FPGA.md (step 2): a Z80 (TV80, Mode 0) whose memory goes through the SMMU of the
// XLINK to a physical RAM and whose I/O ports $00-$0F are the XLINK ports (docs/DESIGN.md chapter 7).  The 6809 side is
// the register port m_* of the XLINK; the test bench (fpga/sim/tb_z80_soc.cpp) plays the 6809 and runs the same Z80
// binary as the C simulator (os9/sub/sumz80.py).
//
// The RAM here is a plain array (2MB, simulation only).  On the board it becomes the arbiter and PSRAM / BSRAM of
// docs/FPGA.md chapter 5; the interface to the rest (mem port of the Z80 through sub_phys, window port) does not change.
// The Z80 runs at the system clock (clk) here; on the board a clock enable divides the system clock (not done yet).
//
// Credits: the TV80 core (Guy Hutchison, after T80 by Daniel Wallner, MIT) is not part of this repository
// (see CREDITS.md).  Bus cycles follow the Z80 User Manual (UM0080): memory cycles with MREQ/RD/WR, I/O cycles with
// IORQ, interrupt acknowledge = IORQ with M1.
module z80_soc #(
    parameter RAMBITS = 21                   // physical address bits of the simulation RAM (21 = 2MB; small for a synthesis estimate)
) (
    input  wire        clk,
    input  wire        rst,                  // synchronous, high
    // ---- 6809 side (XLINK registers)
    input  wire [2:0]  m_addr,
    input  wire        m_re,
    input  wire        m_we,
    input  wire [7:0]  m_wdata,
    output wire [7:0]  m_rdata,
    output wire        m_wait,
    output wire        irq_o,
    output wire        firq_o,
    // ---- debug / power
    output wire        con_we,
    output wire [7:0]  con_data,
    output wire        pwr_we,
    output wire [7:0]  pwr_data,
    output wire        z80_halted
);
    // ------------------------------------------------------------ Z80
    wire        sub_rst_n, sub_hold, sub_int, sub_nmi;
    wire        m1_n, mreq_n, iorq_n, rd_n, wr_n, rfsh_n, halt_n, busak_n;
    wire [15:0] A;
    wire [7:0]  dout;
    reg  [7:0]  di;
    reg         nmi_n;

    tv80s #(.Mode(0), .T2Write(1), .IOWait(1)) cpu (
        .reset_n(sub_rst_n), .clk(clk), .wait_n(1'b1), .int_n(~sub_int), .nmi_n(nmi_n), .busrq_n(~sub_hold),
        .m1_n(m1_n), .mreq_n(mreq_n), .iorq_n(iorq_n), .rd_n(rd_n), .wr_n(wr_n), .rfsh_n(rfsh_n),
        .halt_n(halt_n), .busak_n(busak_n), .A(A), .di(di), .dout(dout));

    assign z80_halted = ~halt_n;

    // NMI: the XLINK gives a one-clock pulse; the core wants a falling edge
    always @(posedge clk) nmi_n <= ~sub_nmi;

    // ------------------------------------------------------------ cycle decode and strobes
    wire io_cycle  = ~iorq_n;
    wire int_ack   = io_cycle & ~m1_n;
    wire io_rd     = io_cycle &  m1_n & ~rd_n;
    wire io_wr     = io_cycle & ~wr_n;
    wire mem_rd    = ~mreq_n & ~rd_n;
    wire mem_wr    = ~mreq_n & ~wr_n;
    reg  io_rd_q, io_wr_q;
    always @(posedge clk) begin io_rd_q <= io_rd; io_wr_q <= io_wr; end
    wire s_re = io_rd & ~io_rd_q;                 // one clock at the start of the cycle
    wire s_we = io_wr & ~io_wr_q;
    wire [3:0] s_port = A[3:0];
    wire port_ok = (A[7:4] == 4'h0);              // only $00-$0F are decoded

    // ------------------------------------------------------------ XLINK
    wire [7:0]  s_rdata, s_vec;
    wire [20:0] sub_phys;
    wire        win_req, win_wr, win_ack;
    wire [20:0] win_addr;
    wire [7:0]  win_wdata;
    reg  [7:0]  win_rdata;

    xlink #(.SUB_ID(8'd1), .SUB_KHZ(16'd7500)) xl (
        .clk(clk), .rst(rst),
        .m_addr(m_addr), .m_re(m_re), .m_we(m_we), .m_wdata(m_wdata), .m_rdata(m_rdata), .m_wait(m_wait),
        .irq_n_o(irq_o), .firq_o(firq_o), .shr_o(),
        .sub_rst_n(sub_rst_n), .sub_hold(sub_hold), .sub_int(sub_int), .sub_nmi(sub_nmi),
        .sub_halted(z80_halted), .sub_clk_en(1'b1),
        .s_port(s_port), .s_re(s_re & port_ok), .s_we(s_we & port_ok), .s_wdata(dout),
        .s_rdata(s_rdata), .s_vec(s_vec),
        .con_we(con_we), .con_data(con_data), .pwr_we(pwr_we), .pwr_data(pwr_data),
        .sub_addr({4'b0, A}), .sub_is_z80(1'b1), .sub_phys(sub_phys),
        .win_req(win_req), .win_wr(win_wr), .win_addr(win_addr), .win_wdata(win_wdata),
        .win_ack(win_ack), .win_rdata(win_rdata));

    // ------------------------------------------------------------ RAM (simulation): Z80 first, the window gets the free clocks
    reg [7:0] ram [0:(1<<RAMBITS)-1];
    wire [RAMBITS-1:0] zadr = sub_phys[RAMBITS-1:0];
    wire [RAMBITS-1:0] wadr = win_addr[RAMBITS-1:0];
    wire z80_ram = mem_rd | mem_wr;
    always @(posedge clk) begin
        if (mem_wr) ram[zadr] <= dout;
        else if (win_req && win_wr) ram[wadr] <= win_wdata;
        win_rdata <= ram[wadr];
    end
    assign win_ack = win_req & ~mem_wr & ~mem_rd;     // an access of the Z80 in this clock blocks the window

    always @* begin
        if (int_ack)      di = s_vec;
        else if (io_rd)   di = port_ok ? s_rdata : 8'hff;
        else              di = ram[zadr];
    end
endmodule
