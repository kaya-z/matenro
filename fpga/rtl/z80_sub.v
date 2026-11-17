// SPDX-License-Identifier: MIT
// z80_sub.v - the Z80 sub CPU of the Matenro machine without a memory: Z80 core + XLINK + SMMU + clock enable
//
// The Z80 memory goes out through a request / acknowledge port (mem_*), which the SoC connects to the PSRAM arbiter
// (rtl/z80_soc.v for a simulation RAM, tn9k/rtl/matenro_soc.v for the PSRAM), so that a memory access may take any
// number of clocks: the Z80 clock enable is held meanwhile.  The 6809 side is the register port m_* of the XLINK and
// the window port win_* (the 6809 reads and writes the physical memory through it; the SoC serves it).
//
// Z80 bus cycles (TV80, tv80s_cen): a read is requested when MREQ+RD start (the address is valid then) and the byte is
// kept until the next cycle; a write is done when WR ends, with the address and data of its last clock (with a slow
// cen the data is not valid in the first clock of the cycle).  I/O cycles go to the XLINK ports $00-$0F the same way
// (reads: the port data comes combinationally; writes: at the end of the cycle).
//
// Credits: the TV80 core (Guy Hutchison, after T80 by Daniel Wallner, MIT) is not part of this repository
// (see CREDITS.md).  Bus cycles follow the Z80 User Manual (UM0080).
module z80_sub #(
    parameter CLKDIV = 9,                    // Z80 clock = clk / CLKDIV, 2 or more (67.5 MHz / 9 = 7.5 MHz)
    parameter [16:0] CLK_KHZ = 17'd67500     // clk in kHz (XE_US of the XLINK counts microseconds)
) (
    input  wire        clk,
    input  wire        rst,                  // synchronous, high
    // ---- 6809 side (XLINK registers)
    input  wire [2:0]  m_addr,
    input  wire        m_re,
    input  wire        m_we,
    input  wire [7:0]  m_wdata,
    output reg  [7:0]  m_rdata,              // one clock late (the register read mux of the XLINK is a long path)
    output wire        m_wait,
    output wire        m_win,
    output wire        sub_on,               // the Z80 is enabled: out of reset and not held (LED0 in the second LED mode)
    output wire        irq_o,
    output wire        firq_o,
    // ---- window to the physical memory (served by the SoC)
    output wire        win_req,
    output wire        win_wr,
    output wire [20:0] win_addr,
    output wire [7:0]  win_wdata,
    input  wire        win_ack,
    input  wire [7:0]  win_rdata,
    // ---- memory port of the Z80 (physical addresses)
    output reg         mem_req,              // held until mem_ack
    output reg         mem_wr,
    output reg  [20:0] mem_addr,
    output wire [20:0] mem_lk,               // the physical address of the Z80's address bus, in every clock (valid well before mem_req: for a cache look-up)
    output reg  [7:0]  mem_wdata,
    input  wire        mem_ack,              // one clock
    input  wire [7:0]  mem_rdata,
    // ---- debug / power
    output wire        con_we,
    output wire [7:0]  con_data,
    output wire        pwr_we,
    output wire [7:0]  pwr_data,
    output wire        z80_halted,
    output wire [39:0] dbg_z                 // debug: last M1 address, address bus, flags (tn9k/rtl/dbg_uart_z.v)
);
    // ------------------------------------------------------------ clock enable and stall
    reg  [7:0] cnt;
    (* syn_maxfan = 32 *) reg cen_raw = 1'b0;                // cnt == CLKDIV - 1, decided a clock earlier (a register: it fans out to the whole core)
    // The registers of the bus wrapper (RD, WR, MREQ, IORQ, the data latch) take their new value from the core once in a
    // Z80 clock, UPD clocks after the clock enable, when the logic of the core has settled (the paths are multicycle paths
    // for the timing tool, fpga/tn9k/constraints/matenro.sdc).
    localparam UPD = (CLKDIV >= 7) ? 4 : (CLKDIV - 1);
    wire       upd = (cnt == UPD);
    always @(posedge clk) begin
        cnt     <= (rst || cen_raw) ? 8'd0 : cnt + 8'd1;
        cen_raw <= !rst && !cen_raw && (cnt == CLKDIV - 2);
    end
    (* syn_maxfan = 32 *) reg zstall;                       // a memory access of the Z80 is under way
    wire       rd_start, wr_end;
    // rd_start / wr_end come one clock after the outputs of the core changed (UPD clocks after the enable); with CLKDIV >= 7
    // they are over before the next enable (zstall is set by then), so they are left out of cen: it fans out to every register
    // of the core and was on the slowest paths of the design.
    wire       cen = cen_raw & ~zstall & ((CLKDIV >= 7) ? 1'b1 : (~rd_start & ~wr_end));

    // ------------------------------------------------------------ Z80
    wire        sub_rst_n, sub_hold, sub_int, sub_nmi;
    wire        m1_n, mreq_n, iorq_n, rd_n, wr_n, rfsh_n, halt_n, busak_n;
    wire [15:0] A;
    wire [7:0]  dout;
    reg  [7:0]  di;
    reg  [7:0]  di_q;                        // di, one clock late: a multicycle path into the core (matenro.sdc)
    always @(posedge clk) di_q <= di;
    reg         nmi_n;

    tv80s_cen #(.Mode(0), .T2Write(1), .IOWait(1)) cpu (
        .reset_n(sub_rst_n), .clk(clk), .cen_i(cen), .upd_i(upd), .wait_n(1'b1), .int_n(~sub_int), .nmi_n(nmi_n), .busrq_n(~sub_hold),
        .m1_n(m1_n), .mreq_n(mreq_n), .iorq_n(iorq_n), .rd_n(rd_n), .wr_n(wr_n), .rfsh_n(rfsh_n),
        .halt_n(halt_n), .busak_n(busak_n), .A(A), .di(di_q), .dout(dout));

    assign z80_halted = ~halt_n;
    assign sub_on     = sub_rst_n & ~sub_hold;

    reg [15:0] pc_m1;                        // the address of the last instruction fetch (debug)
    always @(posedge clk) if (~m1_n & ~mreq_n) pc_m1 <= A;
    assign dbg_z = {pc_m1, A, zstall, z80_halted, mem_req, mem_wr, ~m1_n, ~mreq_n, ~rd_n, ~wr_n};

    // NMI: the XLINK gives a one-clock pulse, the core looks at nmi_n only when cen is set: keep it until then
    reg nmi_pend;
    always @(posedge clk) begin
        if (sub_nmi) nmi_pend <= 1'b1;
        else if (cen) nmi_pend <= 1'b0;
        nmi_n <= ~nmi_pend;
    end

    // ------------------------------------------------------------ cycle decode
    wire io_cycle = ~iorq_n;
    wire int_ack  = io_cycle & ~m1_n;
    wire io_rd    = io_cycle &  m1_n & ~rd_n;
    wire io_wr    = io_cycle & ~wr_n;
    wire mem_rd   = ~mreq_n & ~rd_n;
    wire mem_wrc  = ~mreq_n & ~wr_n;
    reg  mem_rd_q, mem_wr_q, io_wr_q;
    always @(posedge clk) begin mem_rd_q <= mem_rd; mem_wr_q <= mem_wrc; io_wr_q <= io_wr; end
    assign rd_start = mem_rd & ~mem_rd_q;
    assign wr_end   = mem_wr_q & ~mem_wrc;

    reg [7:0]  dout_q;
    reg [7:0]  a_q;
    always @(posedge clk) if (io_wr) begin dout_q <= dout; a_q <= A[7:0]; end
    // the I/O write strobe for the XLINK, one clock after the end of the write (s_we: a register, so IORQ of the core is not in
    // front of the port mux and of the read data register s_rdata_q)
    reg  s_we = 1'b0;
    always @(posedge clk) s_we <= io_wr_q & ~io_wr;
    wire [3:0] s_port = s_we ? a_q[3:0] : A[3:0];
    wire port_ok = s_we ? (a_q[7:4] == 4'h0) : (A[7:4] == 4'h0);   // only $00-$0F are decoded

    // ------------------------------------------------------------ XLINK
    wire [7:0]  s_rdata, s_vec;
    wire [20:0] sub_phys;
    assign mem_lk = sub_phys;

    wire [7:0] xl_rdata;
    always @(posedge clk) m_rdata <= xl_rdata;

    xlink #(.SUB_ID(8'd1), .SUB_KHZ(CLK_KHZ / CLKDIV), .CLK_KHZ(CLK_KHZ)) xl (
        .clk(clk), .rst(rst),
        .m_addr(m_addr), .m_re(m_re), .m_we(m_we), .m_wdata(m_wdata), .m_rdata(xl_rdata), .m_wait(m_wait), .m_win(m_win),
        .irq_n_o(irq_o), .firq_o(firq_o), .shr_o(),
        .sub_rst_n(sub_rst_n), .sub_hold(sub_hold), .sub_int(sub_int), .sub_nmi(sub_nmi),
        .sub_halted(z80_halted), .sub_clk_en(cen),
        .s_port(s_port), .s_re(1'b0), .s_we(s_we & port_ok), .s_wdata(dout_q),
        .s_rdata(s_rdata), .s_vec(s_vec),
        .con_we(con_we), .con_data(con_data), .pwr_we(pwr_we), .pwr_data(pwr_data),
        .sub_addr({4'b0, A}), .sub_is_z80(1'b1), .sub_phys(sub_phys),
        .win_req(win_req), .win_wr(win_wr), .win_addr(win_addr), .win_wdata(win_wdata),
        .win_ack(win_ack), .win_rdata(win_rdata));

    // ------------------------------------------------------------ memory port
    reg [20:0] rd_phys;
    reg [20:0] wr_phys;
    reg [7:0]  wr_data;
    reg        req_is_wr;
    reg [7:0]  zdat;
    reg [2:0]  zrel;                         // clocks until the Z80 clock enable is released after an access (di_q settles)
    always @(posedge clk) if (mem_wrc) begin wr_phys <= sub_phys; wr_data <= dout; end

    always @(posedge clk) begin
        if (rst) begin
            mem_req <= 1'b0; zstall <= 1'b0; zrel <= 3'd0; mem_wr <= 1'b0; mem_addr <= 21'd0; mem_wdata <= 8'd0; zdat <= 8'hff;
        end else begin
            if (rd_start) begin
                mem_req <= 1'b1; mem_wr <= 1'b0; mem_addr <= sub_phys; zstall <= 1'b1;
            end else if (wr_end) begin
                mem_req <= 1'b1; mem_wr <= 1'b1; mem_addr <= wr_phys; mem_wdata <= wr_data; zstall <= 1'b1;
            end
            if (mem_ack) begin
                mem_req <= 1'b0; zrel <= 3'd5;
                if (!mem_wr) zdat <= mem_rdata;
            end else if (zrel != 3'd0) begin
                zrel <= zrel - 3'd1;
                if (zrel == 3'd1) zstall <= 1'b0;
            end
        end
    end

    // The core latches di during the whole T2 (many clocks when cen is slow), after RD/IORQ have gone high again, so
    // what di shows is chosen when the cycle starts and kept until the next cycle starts.
    reg sel_io, sel_ack;
    always @(posedge clk) begin
        if (mem_rd | mem_wrc | io_wr) begin sel_io <= 1'b0; sel_ack <= 1'b0; end
        else if (int_ack)             begin sel_io <= 1'b0; sel_ack <= 1'b1; end
        else if (io_rd)               begin sel_io <= 1'b1; sel_ack <= 1'b0; end
    end
    // The port data go through a register first (the address of the port, the read mux of the XLINK and the choice of
    // di were one long path); the cycle starts at least eight clocks before the core takes di, so one clock more is no problem.
    reg [7:0] s_rdata_q;
    reg       port_ok_q;
    always @(posedge clk) begin s_rdata_q <= s_rdata; port_ok_q <= port_ok; end
    always @* begin
        if (int_ack | sel_ack)     di = s_vec;
        else if (io_rd | sel_io)   di = port_ok_q ? s_rdata_q : 8'hff;
        else                       di = zdat;
    end
endmodule
