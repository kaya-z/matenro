// SPDX-License-Identifier: MIT
// rcache.v - the read cache of the 6809 on the SDRAM of the Tang Nano 20K: direct mapped, a line is one 32 bit word of the SDRAM (4 bytes, the unit
// of a `wide` read of sdram_ctl.v), LINES lines (2,048 = 8 KB), write-through.  The data is four RAMs of 8 bits (a byte of a line is written alone),
// the tags are one RAM of {tag, valid}.  Design: docs/TN20K.md 2.4 A.
//
//   lookup   a[21:0] is the byte address of the 6809's access (it is stable many clocks before the result is wanted: the RAMs are read in every
//            clock); hit and hbyte are valid two clocks after a changes.
//   fill     fill_we (one clock): the line fill_a[21:2] gets the 32 bit word fill_d and becomes valid (a read miss, when the SDRAM has answered).
//   update   upd_we (one clock): if the line of a is in the cache (hit), its byte a[1:0] becomes upd_d (a write of the 6809: write-through, no allocate).
//   inv      inv_we (one clock): the line of inv_a[21:2] becomes invalid (a write of another master of the SDRAM: the sub CPU, the disk, the window).
//            It is applied in the next clock if the tags are busy with a fill in this one (at most one is waiting).
//
// The caller makes sure that a fill never comes from a read that was started before a write to the same word was made by another master (the
// arbiter does one access at a time, and the fill is taken with the acknowledge of the read, before the next access starts).
module rcache #(
    parameter IDX = 11                          // 2 ** IDX lines
) (
    input  wire        clk,
    input  wire        rst,
    input  wire [21:0] a,                       // lookup address
    output wire        hit,
    output wire [7:0]  hbyte,
    input  wire        fill_we,
    input  wire [19:0] fill_a,                  // word address (byte address >> 2)
    input  wire [31:0] fill_d,
    input  wire        upd_we,
    input  wire [7:0]  upd_d,
    input  wire        inv_we,
    input  wire [19:0] inv_a
);
    localparam TAGW = 20 - IDX;                 // tag bits: word address bits above the index
    wire [IDX-1:0]  ridx = a[IDX+1:2];
    wire [TAGW-1:0] rtag = a[21:IDX+2];

    reg [7:0]      d0 [0:(1<<IDX)-1];
    reg [7:0]      d1 [0:(1<<IDX)-1];
    reg [7:0]      d2 [0:(1<<IDX)-1];
    reg [7:0]      d3 [0:(1<<IDX)-1];
    reg [TAGW:0]   tg [0:(1<<IDX)-1];           // {tag, valid}
    // (the RAMs of the FPGA start with 0: all lines invalid; the synthesis tool takes at most 2000 passes of a loop)
`ifdef VERILATOR
    integer ii;
    initial for (ii = 0; ii < (1<<IDX); ii = ii + 1) begin d0[ii] = 8'd0; d1[ii] = 8'd0; d2[ii] = 8'd0; d3[ii] = 8'd0; tg[ii] = {(TAGW+1){1'b0}}; end
`endif

    // the read side: every clock, the result a clock later
    reg [31:0]     qd;
    reg [TAGW:0]   qt;
    reg [1:0]      qlane;
    always @(posedge clk) begin
        qd    <= {d3[ridx], d2[ridx], d1[ridx], d0[ridx]};
        qt    <= tg[ridx];
        qlane <= a[1:0];
    end
    assign hit   = qt[0] && (qt[TAGW:1] == rtag_q);
    reg [TAGW-1:0] rtag_q;
    always @(posedge clk) rtag_q <= rtag;
    assign hbyte = qlane == 2'd0 ? qd[7:0] : qlane == 2'd1 ? qd[15:8] : qlane == 2'd2 ? qd[23:16] : qd[31:24];

    // the tags: a fill (valid), or an invalidation (valid = 0); a fill goes first, an invalidation waits one clock
    reg            inv_pend;
    reg [IDX-1:0]  inv_idx;
    wire [IDX-1:0] fidx = fill_a[IDX-1:0];
    always @(posedge clk) begin
        if (rst) inv_pend <= 1'b0;
        else begin
            if (inv_we) begin inv_pend <= 1'b1; inv_idx <= inv_a[IDX-1:0]; end
            if (fill_we) tg[fidx] <= {fill_a[19:IDX], 1'b1};
            else if (inv_pend) begin tg[inv_idx] <= {(TAGW+1){1'b0}}; if (!inv_we) inv_pend <= 1'b0; end
        end
    end

    // the data: a fill writes the four bytes, an update one byte (they do not meet: the fill comes while the 6809 waits for the read)
    wire [IDX-1:0] uidx = ridx;
    wire           do_upd = upd_we && hit;
    always @(posedge clk) begin
        if (fill_we) begin
            d0[fidx] <= fill_d[7:0];  d1[fidx] <= fill_d[15:8];
            d2[fidx] <= fill_d[23:16]; d3[fidx] <= fill_d[31:24];
        end else if (do_upd) begin
            case (a[1:0])
            2'd0: d0[uidx] <= upd_d;
            2'd1: d1[uidx] <= upd_d;
            2'd2: d2[uidx] <= upd_d;
            default: d3[uidx] <= upd_d;
            endcase
        end
    end
endmodule
