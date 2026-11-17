// SPDX-License-Identifier: MIT
// hdmi_pctext.v - the text memory of the IBM PC (80 x 25 cells of {character, attribute}, B800:0000 of the sub CPU) as the HDMI text screen.
//
// The sub CPU (the 8088 of the DOS programs) writes the cells into its memory at B800h; that memory is in the SDRAM (physical PC_BASE, the physical
// address of the logical B8000 with the default SMMU: 1 MB + B8000 = $1B8000).  This engine (pixel clock domain) reads the 2,000 cells one 16 bit word
// at a time, through psram_xfer.v (the request port of the arbiter's master 1, as the UTF-8 decoder uses it), and writes them into the video RAM of
// the text screen: the cell {attr8, 8'h00, char}.  A pass is made once in 2^19 pixel clocks (about 21 ms), so that the memory of the SDRAM and the master
// 1 are free the rest of the time.  The colours of the PC (bit 0 blue, 1 green, 2 red, 3 intensity) are turned into the order of the terminal
// (ANSI: 1 red, 2 green, 4 blue); bit 7 of the attribute (blink) makes the background bright.
//
// Used by hdmi_screen20.v when the register PTXT of the SoC ($FFBB bit 0) is set.
module hdmi_pctext #(
    parameter [21:0] PC_BASE = 22'h1B8000
) (
    input  wire        clk,                 // pixel clock
    input  wire        rst,
    input  wire        on,                  // in the pixel clock domain
    output reg         req,                 // psram_xfer: a read of the word at addr, held until ack
    output reg  [21:0] addr,
    input  wire        ack,
    input  wire [15:0] rdata,               // {attribute, character}
    output reg         we,                  // video RAM write
    output reg  [10:0] wa,
    output reg  [23:0] wd
);
    // the colours of the PC to the terminal's order: 0 black, 1 blue -> 4, 2 green -> 2, 3 cyan -> 6, 4 red -> 1, 5 magenta -> 5, 6 brown -> 3, 7 -> 7
    function [2:0] ansi(input [2:0] c);
        case (c)
        3'd1: ansi = 3'd4;
        3'd3: ansi = 3'd6;
        3'd4: ansi = 3'd1;
        3'd6: ansi = 3'd3;
        default: ansi = c;
        endcase
    endfunction
    reg [18:0] tick = 19'd0;
    reg [10:0] i;
    reg [1:0]  st;
    localparam [1:0] P_IDLE = 2'd0, P_REQ = 2'd1, P_PUT = 2'd2;
    always @(posedge clk) begin
        we <= 1'b0;
        tick <= tick + 19'd1;
        if (rst || !on) begin st <= P_IDLE; req <= 1'b0; i <= 11'd0; end
        else case (st)
        P_IDLE: if (tick == 19'd0) begin i <= 11'd0; addr <= PC_BASE; req <= 1'b1; st <= P_REQ; end
        P_REQ: if (ack) begin
            req <= 1'b0;
            we <= 1'b1; wa <= i;
            wd <= {rdata[15], ansi(rdata[14:12]), rdata[11], ansi(rdata[10:8]), 8'h00, rdata[7:0]};      // {background, foreground}, 8'h00, the character
            st <= P_PUT;
        end
        P_PUT: begin
            if (i == 11'd1999) st <= P_IDLE;
            else begin i <= i + 11'd1; addr <= PC_BASE + {10'd0, i + 11'd1, 1'b0}; req <= 1'b1; st <= P_REQ; end
        end
        default: st <= P_IDLE;
        endcase
    end
endmodule
