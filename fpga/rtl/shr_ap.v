// SPDX-License-Identifier: MIT
// shr_ap.v - a shared RAM of 8 KB in a block RAM (BSRAM) with two ports: the Z80 on port A, the window of the XLINK (the 6809)
// on port B.  One physical block of 8 KB (the block number BLK, bits 20:13 of the physical address) is served from here
// instead of the PSRAM: no arbiter, no waiting for the other CPU.  Nothing else changes: the SMMU of the XLINK maps a block of
// the Z80 to the physical block BLK like to any other.
//
// The 6809 reaches it only through the window (XC_SHR does not show it: the MMU of the 6809 goes to the PSRAM).
// Both CPUs write the same byte at the same clock: the result is undefined (the doorbell orders the accesses).
//
//   port A (the request / acknowledge port of the Z80): zm_req is held until a_ack; the data are valid in the clock of a_ack.
//   port B (the window): w_req is held until the acknowledge of the SoC; w_ack is one clock, w_rdata is valid then and stays.
module shr_ap #(
    parameter [7:0] BLK = 8'hff
) (
    input  wire        clk,
    input  wire        rst,
    // port A: the Z80
    input  wire        a_req,
    input  wire        a_wr,
    input  wire [20:0] a_addr,
    input  wire [7:0]  a_wdata,
    output wire        a_hit,                // the address is in the block: the arbiter does not get the request
    output wire        a_ack,
    output wire [7:0]  a_rdata,
    // port B: the window of the XLINK
    input  wire        w_req,
    input  wire        w_wr,
    input  wire [20:0] w_addr,
    input  wire [7:0]  w_wdata,
    output wire        w_hit,
    output reg         w_ack,
    output reg  [7:0]  w_rdata
);
    (* ram_style = "block_ram" *) reg [7:0] mem [0:8191];

    assign a_hit = (a_addr[20:13] == BLK);
    assign w_hit = (w_addr[20:13] == BLK);

    // ---- port A: the access in the clock of the start, the data in the next clock (= the acknowledge)
    reg        a_p = 1'b0;
    reg  [7:0] a_q;
    wire       a_go = a_req && a_hit && !a_p;
    always @(posedge clk) begin
        if (a_go && a_wr) begin mem[a_addr[12:0]] <= a_wdata; a_q <= a_wdata; end    // (write-through: the DPB of the GW1NR has no read-before-write)
        else              a_q <= mem[a_addr[12:0]];
    end
    reg a_done = 1'b0;
    always @(posedge clk) begin
        if (rst) begin a_p <= 1'b0; a_done <= 1'b0; end
        else begin
            a_p <= a_go && !a_done;
            if (a_p) a_done <= 1'b1;
            else if (!a_req) a_done <= 1'b0;
        end
    end
    assign a_ack   = a_p;
    assign a_rdata = a_q;

    // ---- port B: start, access (the address is read a clock after the start), data, acknowledge
    reg        b_p = 1'b0, b_q = 1'b0, b_done = 1'b0;
    reg  [7:0] b_d;
    wire       b_go = w_req && w_hit && !b_p && !b_q && !w_ack && !b_done;
    always @(posedge clk) begin
        if (b_p && w_wr) begin mem[w_addr[12:0]] <= w_wdata; b_d <= w_wdata; end
        else             b_d <= mem[w_addr[12:0]];
    end
    always @(posedge clk) begin
        w_ack <= 1'b0;
        if (rst) begin b_p <= 1'b0; b_q <= 1'b0; b_done <= 1'b0; end
        else begin
            b_p <= b_go;
            b_q <= b_p;
            if (b_q) begin w_rdata <= b_d; w_ack <= 1'b1; b_done <= 1'b1; end
            else if (!w_req) b_done <= 1'b0;
        end
    end
endmodule
