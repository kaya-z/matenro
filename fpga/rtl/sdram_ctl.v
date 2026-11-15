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
    output reg  [15:0] dout,
    output reg  [31:0] dout32,          // the whole 32 bit word of the last read (addr[21:2]), valid when busy is low
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
    reg [3:0]  cyc;                         // clocks since the ACTIVE / REFRESH / first command of the sequence
    reg        is_wr;
    reg        req_pend;                    // a request that has not been started
    reg        req_wr, req_bw;
    reg [21:0] req_addr;
    reg [15:0] req_din;
    reg [1:0]  lane_a;                      // addr[1:0] of the access that is under way

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
        cyc <= (cyc == 4'd15) ? 4'd15 : cyc + 4'd1;
        rcnt <= (rcnt == 10'd1023) ? rcnt : rcnt + 10'd1;
        if (read || write) begin
            req_pend <= 1'b1; req_wr <= write; req_bw <= byte_write; req_addr <= addr; req_din <= din;
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
                    is_wr <= req_wr; lane_a <= req_addr[1:0];
                    req_pend <= 1'b0; st <= S_RW; cyc <= 4'd1;
                end
            end
            S_RW: begin                     // cyc 1 = the clock after ACTIVE; READ / WRITE at cyc 3 (tRCD = 2 clocks)
                if (cyc == 4'd3) begin
                    {O_sdram_ras_n, O_sdram_cas_n, O_sdram_wen_n} <= is_wr ? C_WR : C_RD;
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
                    end else O_sdram_dqm <= 4'b0000;
                end
                if (cyc == 4'd4) dq_oe <= 1'b0;
                if (!is_wr && cyc == 4'd6) begin                      // READ at 3: taken 3 clocks later
                    dout   <= lane_a[1] ? IO_sdram_dq[31:16] : IO_sdram_dq[15:0];
                    dout32 <= IO_sdram_dq;                              // the whole 32 bit word (the frame buffer reads 4 pixels at once)
                end
                if (cyc == 4'd9) st <= S_IDLE;                         // auto precharge done (tWR + tRP for a write)
            end
            S_REF: begin
                if (cyc == 4'd7) st <= S_IDLE;                         // tRC
            end
            default: st <= S_INIT;
            endcase
        end
    end
endmodule
