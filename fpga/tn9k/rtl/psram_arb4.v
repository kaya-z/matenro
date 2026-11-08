// SPDX-License-Identifier: MIT
// Copyright (c) 2026 sim09 contributors
// Changed for Matenro (fpga/tn9k): see CREDITS.md.
//
// (psram_arb.v of sim09 with a fourth master for the Z80 of Matenro.)
// Three masters share the PSRAM controller (vendor/psram), which does one access at a time.  A master
// raises its request (with the address and, for master 0, the data) and holds it until the arbiter pulses
// ack; with the ack, rdata (the 16 bit word at the address) is valid and stays until the next ack.
//
//   master 0   byte reads / writes: the CPU, the disk, the start-up (memory test, clear)      lowest priority
//   master 1   word reads: the HDMI decoder (UTF-8 table look-ups)
//   master 2   word reads: the HDMI display (the glyph lines of the next scan line)             highest: it has a deadline
//   master 3   byte reads / writes: the Z80 of Matenro (above master 0, below the HDMI)
//   master 4   byte reads / writes: the disk in the asynchronous mode (the DMA of the sectors while the 6809 goes on)   lowest
//
// The access of one request takes about 15 clocks (the controller) and 4 more here.

module psram_arb4 (
    input  wire        clk,
    input  wire        rst,
    // the controller
    output reg         c_rd,
    output reg         c_wr,
    output reg  [21:0] c_addr,
    output reg  [15:0] c_din,
    output wire        c_bw,
    input  wire [15:0] c_dout,
    input  wire        c_busy,
    // master 0
    input  wire        m0_req,
    input  wire        m0_wr,               // 1: write the byte m0_din
    input  wire [21:0] m0_addr,
    input  wire [7:0]  m0_din,
    output reg         m0_ack,
    output reg  [15:0] m0_rdata,
    // master 1
    input  wire        m1_req,
    input  wire [21:0] m1_addr,
    output reg         m1_ack,
    output reg  [15:0] m1_rdata,
    // master 2
    input  wire        m2_req,
    input  wire [21:0] m2_addr,
    output reg         m2_ack,
    output reg  [15:0] m2_rdata,
    // master 3 (the Z80 of Matenro): byte reads / writes
    input  wire        m3_req,
    input  wire        m3_wr,
    input  wire [21:0] m3_addr,
    input  wire [7:0]  m3_din,
    output reg         m3_ack,
    output reg  [15:0] m3_rdata,
    // master 4 (the disk, asynchronous mode): byte reads / writes, the lowest priority
    input  wire        m4_req,
    input  wire        m4_wr,
    input  wire [21:0] m4_addr,
    input  wire [7:0]  m4_din,
    output reg         m4_ack,
    output reg  [15:0] m4_rdata
);
    localparam [2:0] S_IDLE = 3'd0, S_ISSUE = 3'd1, S_W1 = 3'd2, S_WAIT = 3'd3, S_ACK = 3'd4, S_GAP = 3'd5;
    reg [2:0] st;
    reg [2:0] sel;

    assign c_bw = 1'b1;

    always @(posedge clk) begin
        c_rd   <= 1'b0;
        c_wr   <= 1'b0;
        m0_ack <= 1'b0;
        m1_ack <= 1'b0;
        m2_ack <= 1'b0;
        m3_ack <= 1'b0;
        m4_ack <= 1'b0;
        if (rst) begin
            st <= S_IDLE;
        end else case (st)
        S_IDLE: if (!c_busy) begin
            if (m2_req)      begin sel <= 3'd2; c_addr <= m2_addr; c_din <= 16'd0; st <= S_ISSUE; end
            else if (m1_req) begin sel <= 3'd1; c_addr <= m1_addr; c_din <= 16'd0; st <= S_ISSUE; end
            else if (m3_req) begin sel <= 3'd3; c_addr <= m3_addr; c_din <= {m3_din, m3_din}; st <= S_ISSUE; end
            else if (m0_req) begin sel <= 3'd0; c_addr <= m0_addr; c_din <= {m0_din, m0_din}; st <= S_ISSUE; end
            else if (m4_req) begin sel <= 3'd4; c_addr <= m4_addr; c_din <= {m4_din, m4_din}; st <= S_ISSUE; end
        end
        S_ISSUE: begin
            c_rd <= (sel == 3'd1) || (sel == 3'd2) || (sel == 3'd0 && !m0_wr) || (sel == 3'd3 && !m3_wr) || (sel == 3'd4 && !m4_wr);
            c_wr <= (sel == 3'd0 && m0_wr) || (sel == 3'd3 && m3_wr) || (sel == 3'd4 && m4_wr);
            st   <= S_W1;
        end
        S_W1:   st <= S_WAIT;                       // the request is visible to the controller
        S_WAIT: if (!c_busy) st <= S_ACK;           // busy has risen by now, and falls when the access is done
        S_ACK: begin
            case (sel)
                3'd0: begin m0_rdata <= c_dout; m0_ack <= 1'b1; end
                3'd1: begin m1_rdata <= c_dout; m1_ack <= 1'b1; end
                3'd3: begin m3_rdata <= c_dout; m3_ack <= 1'b1; end
                3'd4: begin m4_rdata <= c_dout; m4_ack <= 1'b1; end
                default: begin m2_rdata <= c_dout; m2_ack <= 1'b1; end
            endcase
            st <= S_GAP;
        end
        S_GAP: st <= S_IDLE;                        // the master takes its request down
        default: st <= S_IDLE;
        endcase
    end
endmodule
