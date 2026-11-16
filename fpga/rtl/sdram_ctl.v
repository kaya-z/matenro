// SPDX-License-Identifier: MIT
// sdram_ctl.v - controller of the SDR SDRAM in the package of the GW2AR-18 (Tang Nano 20K: 64 Mbit = 8 MB, 32 bit, 4 banks, 2K rows x 256 columns)
// with the interface of PsramController (the PSRAM controller of the Tang Nano 9K), so that psram_arb4.v and the SoC do not change:
//
//   read / write   one clock pulse, only when busy is low (or the request is kept until the access before it is done)
//   addr[21:0]     byte address (4 MB of the 8 MB; the pin addr[22] is for later)
//   din / byte_write / dout   as PsramController: a read gives the 16 bit word at addr[21:1] (even byte in dout[7:0]); a write with
//                  byte_write writes one byte (addr[0]=1: din[15:8]), without it the word
//   busy           high from the clock after the pulse until the access is done (and during a refresh)
//
// Written from the SDR SDRAM command set (JEDEC): every access is ACTIVE, READ/WRITE with auto precharge, wait; CAS latency 2, burst length 1.
// A `wide` read (the frame buffer) keeps the whole 32 bit word in dout32 and does not touch dout.  (Burst length 4 for 16 byte reads was tried: the
// memory test failed on the board with it.)
// No access overlaps another one.  Timing at the system clock of 67.5 MHz (14.8 ns): tRCD 2 clocks, tRP 2, tWR 2, tRC > 5; an access takes 9 clocks.
// The SDRAM clock (O_sdram_clk) is the system clock inverted (a PLL output 180 degrees off): the SDRAM takes the commands half a clock after
// they are registered here; the read data of a READ at clock n are taken at the clock n + 3.
//
// Refresh: AUTO REFRESH every REFRESH_CLKS clocks (7.4 us), as soon as the controller is idle (before a pending request: a stream of
// requests must not keep it off); a request that comes during a refresh is kept.
// This module is not derived from the SDRAM controller of the Sipeed nestang example (GPL v3).
module sdram_ctl #(
    parameter FREQ         = 67_500_000,
    parameter REFRESH_CLKS = 500            // 4096 refreshes in 64 ms need one every 15.6 us; 500 clocks = 7.4 us at 67.5 MHz
) (
    input  wire        clk,
    input  wire        clk_sdram,           // the SDRAM clock, 180 degrees from clk
    input  wire        resetn,
    input  wire        read,
    input  wire        write,
    input  wire [21:0] addr,
    input  wire [15:0] din,
    input  wire        byte_write,
    input  wire        wide,                // with read: the read is for dout32 (the whole 32 bit word of addr[21:2]), dout stays as it is (the frame buffer)
                                            // and din[6:0] is the number of words (0 or 1: one; more: that many words one after the other, dout32 and dv for each)
    output reg  [15:0] dout,
    output reg  [31:0] dout32,          // the whole 32 bit word of the last wide read, valid when busy is low
    output reg         dv,              // one clock: dout32 is a new word of a wide read
    output wire        busy,
    // the SDRAM (names of the Gowin primitives for the embedded SDRAM)
    output wire        O_sdram_clk,
    output wire        O_sdram_cke,
    output wire        O_sdram_cs_n,
    output reg         O_sdram_cas_n = 1'b1,    // (a command of 1 1 1 = NOP from the start: the flops would begin with 0 0 0 = a mode register set)
    output reg         O_sdram_ras_n = 1'b1,
    output reg         O_sdram_wen_n = 1'b1,
    output reg  [3:0]  O_sdram_dqm,
    output reg  [10:0] O_sdram_addr,
    output reg  [1:0]  O_sdram_ba,
    inout  wire [31:0] IO_sdram_dq
);
    assign O_sdram_clk  = clk_sdram;
    assign O_sdram_cke  = 1'b1;
    assign O_sdram_cs_n = 1'b0;

    // commands {RAS#, CAS#, WE#}
    localparam [2:0] C_MRS = 3'b000, C_REF = 3'b001, C_PRE = 3'b010, C_ACT = 3'b011, C_WR = 3'b100, C_RD = 3'b101, C_NOP = 3'b111;

    localparam [2:0] S_INIT = 3'd0, S_CFG = 3'd1, S_IDLE = 3'd2, S_RW = 3'd3, S_REF = 3'd4;
    reg [2:0]  st;
    reg [6:0]  cyc;                         // clocks since the ACTIVE / REFRESH / first command of the sequence (up to 87 for a read of 80 words)
    reg        is_wr;
    reg        req_pend;                    // a request that has not been started
    reg        req_wr, req_bw, req_bst, bst_a;
    reg [21:0] req_addr;
    reg [15:0] req_din;
    reg [1:0]  lane_a;                      // addr[1:0] of the access that is under way
    reg [6:0]  req_nw, nch_a, rest_a;       // the words wanted, the words of the access under way (up to the end of the row), the words left for the next one
    reg [7:0]  colc;                        // the column of the next READ
    wire [8:0] space = 9'd256 - {1'b0, col};            // words from col to the end of the row

    assign busy = (st != S_IDLE) | req_pend;

    // data bus
    reg        dq_oe;
    reg [31:0] dq_out;
    assign IO_sdram_dq = dq_oe ? dq_out : 32'bz;

    // power-up wait: 200 us
    localparam [15:0] WAIT200 = (FREQ / 1000) * 200 / 1000;
    reg [15:0] pcnt;
    reg        pdone;
    reg [9:0]  rcnt;                        // clocks since the last refresh
    wire       ref_due = (rcnt >= REFRESH_CLKS);

    wire [19:0] w   = req_addr[21:2];
    wire [7:0]  col = w[7:0];
    wire [1:0]  bnk = w[9:8];
    wire [10:0] row = {1'b0, w[19:10]};

    always @(posedge clk) begin
        {O_sdram_ras_n, O_sdram_cas_n, O_sdram_wen_n} <= C_NOP;
        dv  <= 1'b0;
        cyc <= (cyc == 7'd127) ? 7'd127 : cyc + 7'd1;
        rcnt <= (rcnt == 10'd1023) ? rcnt : rcnt + 10'd1;
        if (read || write) begin
            req_pend <= 1'b1; req_wr <= write; req_bst <= read && wide; req_bw <= byte_write; req_addr <= addr; req_din <= din;
            req_nw <= (read && wide && din[6:0] > 7'd1) ? din[6:0] : 7'd1;
        end
        if (!resetn) begin
            st <= S_INIT; cyc <= 4'd0; req_pend <= 1'b0; dq_oe <= 1'b0; pcnt <= 16'd0; pdone <= 1'b0; rcnt <= 10'd0;
            O_sdram_dqm <= 4'b0000; O_sdram_addr <= 11'd0; O_sdram_ba <= 2'd0;
        end else begin
            case (st)
            S_INIT: begin                   // wait 200 us, then PRECHARGE ALL
                if (pcnt != WAIT200) pcnt <= pcnt + 16'd1;
                else begin
                    st <= S_CFG; cyc <= 4'd0;
                    {O_sdram_ras_n, O_sdram_cas_n, O_sdram_wen_n} <= C_PRE;
                    O_sdram_addr <= 11'h400;           // A10: all banks
                end
            end
            S_CFG: begin                    // precharge (cyc 0), tRP, 2 x AUTO REFRESH (cyc 2 and 8), tRC, MODE REGISTER SET (cyc 14)
                case (cyc)
                4'd1:  {O_sdram_ras_n, O_sdram_cas_n, O_sdram_wen_n} <= C_REF;
                4'd7:  {O_sdram_ras_n, O_sdram_cas_n, O_sdram_wen_n} <= C_REF;
                4'd13: begin
                    {O_sdram_ras_n, O_sdram_cas_n, O_sdram_wen_n} <= C_MRS;
                    O_sdram_addr <= 11'h020;           // CAS latency 2, sequential, burst length 1
                    O_sdram_ba   <= 2'd0;
                end
                4'd15: begin st <= S_IDLE; rcnt <= 10'd0; end    // tMRD has passed
                default: ;
                endcase
            end
            S_IDLE: begin
                dq_oe <= 1'b0;
                if (ref_due) begin          // the refresh first: requests that come one after the other (the HDMI screen) must not keep it off
                    {O_sdram_ras_n, O_sdram_cas_n, O_sdram_wen_n} <= C_REF;
                    rcnt <= 10'd0; st <= S_REF; cyc <= 4'd1;
                end else if (req_pend) begin    // ACTIVE
                    {O_sdram_ras_n, O_sdram_cas_n, O_sdram_wen_n} <= C_ACT;
                    O_sdram_ba <= bnk; O_sdram_addr <= row; O_sdram_dqm <= 4'b0000;
                    is_wr <= req_wr; lane_a <= req_addr[1:0]; bst_a <= req_bst; colc <= col;
                    if (req_bst && req_nw > 7'd1 && !req_wr) begin       // several words: up to the end of the row, the rest in the next access
                        if ({2'b00, req_nw} <= space) begin nch_a <= req_nw; rest_a <= 7'd0; end
                        else begin nch_a <= space[6:0]; rest_a <= req_nw - space[6:0]; end
                    end else begin nch_a <= 7'd1; rest_a <= 7'd0; end
                    req_pend <= 1'b0; st <= S_RW; cyc <= 7'd1;
                end
            end
            S_RW: begin                     // cyc 1 = the clock after ACTIVE; READ / WRITE at cyc 3 (tRCD = 2 clocks)
                if (!is_wr && cyc >= 7'd3 && cyc < 7'd3 + nch_a) begin      // READs in consecutive clocks, the last one with auto precharge
                    {O_sdram_ras_n, O_sdram_cas_n, O_sdram_wen_n} <= C_RD;
                    O_sdram_addr <= {(cyc == 7'd2 + nch_a), 2'b00, colc};
                    colc <= colc + 8'd1;
                    O_sdram_dqm <= 4'b0000;
                end
                if (is_wr && cyc == 7'd3) begin
                    {O_sdram_ras_n, O_sdram_cas_n, O_sdram_wen_n} <= C_WR;
                    O_sdram_addr <= {1'b1, 2'b00, col[7:0]};            // A10 = 1: auto precharge
                    if (is_wr) begin
                        if (req_bw) begin
                            dq_out <= {4{req_addr[0] ? req_din[15:8] : req_din[7:0]}};
                            O_sdram_dqm <= ~(4'b0001 << lane_a);
                        end else begin
                            dq_out <= {req_din, req_din};
                            O_sdram_dqm <= lane_a[1] ? 4'b0011 : 4'b1100;
                        end
                        dq_oe <= 1'b1;
                    end
                end
                if (cyc == 7'd4) dq_oe <= 1'b0;
                // READ at 3: taken 3 clocks later.  A burst read (the frame buffer) leaves dout alone: the arbiter fetches the data of the access before it
                // when the controller is free again, which can be after a burst that started in between
                if (!is_wr && cyc >= 7'd6 && cyc < 7'd6 + nch_a) begin
                    if (bst_a) begin dout32 <= IO_sdram_dq; dv <= 1'b1; end
                    else       dout   <= lane_a[1] ? IO_sdram_dq[31:16] : IO_sdram_dq[15:0];
                end
                if (cyc == 7'd8 + nch_a) begin                         // auto precharge done (tWR + tRP for a write)
                    st <= S_IDLE;
                    if (rest_a != 7'd0) begin                          // the next row of a long read: the request goes on
                        req_pend <= 1'b1; req_addr <= req_addr + {13'd0, nch_a, 2'b00}; req_nw <= rest_a;
                    end
                end
            end
            S_REF: begin
                if (cyc == 4'd7) st <= S_IDLE;                         // tRC
            end
            default: st <= S_INIT;
            endcase
        end
    end
endmodule
