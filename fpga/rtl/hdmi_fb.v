// SPDX-License-Identifier: MIT
// hdmi_fb.v - the frame buffer of the HDMI screen of the Tang Nano 20K: 320 x 240 pixels of 8 bits (an index into a palette of 256 colours),
// shown doubled on the 640 x 480 screen.  The picture is in the SDRAM at FB_BASE (default $300000, 76,800 bytes); the 6809 writes it through the
// window of the XLINK (HCTL bit 1), and sets the palette and the mode with the registers GCTL / PIDX / PDAT of the SoC.
//
// The SDRAM is read by this module itself, 4 pixels (32 bits) at a time (dout32 of sdram_ctl), 80 reads per picture line, into a line buffer of
// two halves; the line of the next pair of screen lines is fetched while the pair before it is shown.  The top level lets these reads go before
// the requests of the SoC (as the SDRAM is free: go = rq && !busy && no request of the SoC in this clock).  The picture lines are read
// when y >> 1 + 2 lines are needed: 0 and 1 at the start of a frame, then one more each time the screen line pair changes.
//
// The pixels come in the pixel clock domain: the text screen (rgb_i with de_i, hs_i, vs_i, from hdmi_video) goes through here, delayed by three
// clocks; with gfx_on the picture replaces the text.
module hdmi_fb #(
    parameter [21:0] FB_BASE = 22'h300000
) (
    input  wire        clk,                 // system clock
    input  wire        rst,
    input  wire        gfx_on,
    input  wire        gfx_ov,              // the text over the picture: where the text pixel is not black, the text is shown
    input  wire        pal_we,              // palette write (system clock): entry pal_idx = pal_rgb {r, g, b}
    input  wire [7:0]  pal_idx,
    input  wire [23:0] pal_rgb,
    // the SDRAM, through the top level (the controller's interface)
    output reg         rq,                  // a read is wanted at rq_addr (kept until go)
    output reg  [21:0] rq_addr,
    input  wire        go,                  // the read was started in this clock
    input  wire        busy,                // sdram_ctl busy
    input  wire [31:0] dout32,
    // the display (pixel clock)
    input  wire        clk_pix,
    input  wire        rst_pix,
    input  wire        de_i, hs_i, vs_i,
    input  wire [23:0] rgb_i,
    output reg         de_o, hs_o, vs_o,
    output reg  [23:0] rgb_o
);
    // ---------------------------------------------------------------- the position on the screen (pixel clock)
    reg [9:0] x;
    reg [8:0] y;
    reg       de_q, vs_q;
    always @(posedge clk_pix) begin
        de_q <= de_i; vs_q <= vs_i;
        x <= de_i ? x + 1'b1 : 10'd0;                    // the pixel of this clock (x of the first pixel is 0)
        if (vs_q && !vs_i) y <= 9'd0;                    // vsync (active low) begins: the first line follows the vertical blanking
        else if (de_q && !de_i) y <= y + 1'b1;           // end of a line
    end

    // ---------------------------------------------------------------- palette (written in the system clock, read in the pixel clock)
    reg [23:0] pal [0:255];
    integer pi;
    initial for (pi = 0; pi < 256; pi = pi + 1)           // the start: the byte is rrrgggbb (3-3-2)
        pal[pi] = {pi[7:5], pi[7:5], pi[7:6], pi[4:2], pi[4:2], pi[4:3], pi[1:0], pi[1:0], pi[1:0], pi[1:0]};
    always @(posedge clk) if (pal_we) pal[pal_idx] <= pal_rgb;
    reg [23:0] pq;
    reg [7:0]  pxa;

    // ---------------------------------------------------------------- the line buffer: 2 halves of 80 words
    reg [31:0] lbuf [0:255];
    reg        lb_we;
    reg [7:0]  lb_wa;
    reg [31:0] lb_wd;
    always @(posedge clk) if (lb_we) lbuf[lb_wa] <= lb_wd;
    reg [31:0] lw;
    reg [1:0]  lane1;
    wire [7:0] ra = {y[1], x[9:3]};                      // the half (the parity of the picture line y >> 1) and the word 0 .. 79 (the second half starts at 128)
    always @(posedge clk_pix) begin
        lw    <= lbuf[ra];                               // stage 1
        lane1 <= x[2:1];
        pxa   <= lane1[1] ? (lane1[0] ? lw[31:24] : lw[23:16]) : (lane1[0] ? lw[15:8] : lw[7:0]);        // stage 2: the byte
        pq    <= pal[pxa];                               // (pxa is the byte of stage 2: read the palette in stage 3)
    end

    // the text pixels, delayed to the same stage: the byte is chosen in stage 2, the palette read in stage 3: four clocks in all
    reg        de1, hs1, vs1, de2, hs2, vs2, de3, hs3, vs3;
    reg [23:0] t1, t2, t3;
    reg [2:0]  gs;
    reg [1:0]  ovs;
    always @(posedge clk_pix) begin gs <= {gs[1:0], gfx_on}; ovs <= {ovs[0], gfx_ov}; end
    always @(posedge clk_pix) begin
        de1 <= de_i; hs1 <= hs_i; vs1 <= vs_i; t1 <= rgb_i;
        de2 <= de1;  hs2 <= hs1;  vs2 <= vs1;  t2 <= t1;
        de3 <= de2;  hs3 <= hs2;  vs3 <= vs2;  t3 <= t2;
        de_o <= de3; hs_o <= hs3; vs_o <= vs3;
        rgb_o <= gs[2] ? ((ovs[1] && t3 != 24'd0) ? t3 : pq) : t3;
    end

    // ---------------------------------------------------------------- the fetch of the lines (system clock)
    reg [8:0] y1, y2, y3;                                // y, sampled (it changes once per line); y2 is the newest, y3 the one before
    always @(posedge clk) begin y1 <= y; y2 <= y1; y3 <= y2; end
    wire [8:0] yh   = {1'b0, y2[8:1]};                   // the picture line that is shown (0 .. 239; 240 in the blanking)
    wire [8:0] need = (yh + 9'd2 > 9'd240) ? 9'd240 : yh + 9'd2;
    reg [8:0]  got;                                      // the lines fetched in this frame
    reg [6:0]  wi;                                       // the word of the line
    reg [1:0]  st;
    localparam [1:0] F_IDLE = 2'd0, F_REQ = 2'd1, F_WAIT = 2'd2, F_PUT = 2'd3;
    reg        seen;
    wire [21:0] line_base = FB_BASE + {5'd0, got, 8'd0} + {7'd0, got, 6'd0};         // got * 320 (= got * 256 + got * 64)
    always @(posedge clk) begin
        lb_we <= 1'b0;
        if (rst) begin st <= F_IDLE; rq <= 1'b0; got <= 9'd240; end
        else begin
            if (y2 < y3) got <= 9'd0;                    // a new frame (y wrapped to 0)
            case (st)
            F_IDLE: if (gfx_on && got < need && got < 9'd240) begin wi <= 7'd0; rq <= 1'b1; rq_addr <= line_base; st <= F_REQ; end
            F_REQ:  if (go) begin rq <= 1'b0; seen <= 1'b0; st <= F_WAIT; end
            F_WAIT: begin
                if (busy) seen <= 1'b1;
                if (seen && !busy) begin lb_we <= 1'b1; lb_wa <= {got[0], wi}; lb_wd <= dout32; st <= F_PUT; end
            end
            F_PUT: begin
                if (wi == 7'd79) begin got <= got + 1'b1; st <= F_IDLE; end
                else begin wi <= wi + 1'b1; rq <= 1'b1; rq_addr <= line_base + {13'd0, wi + 7'd1, 2'b00}; st <= F_REQ; end
            end
            endcase
        end
    end
`ifdef FBDBG
    always @(posedge clk_pix) if (!de_q && de_i && y < 6) $display("line start y=%0d half=%0d first word=%h second=%h t=%0t", y, y[1], lbuf[{y[1],7'd0}], lbuf[{y[1],7'd1}], $time);
    always @(posedge clk) if (st == F_PUT && wi == 7'd79) $display("fetched %0d (need %0d, y2 %0d, y %0d)", got, need, y2, y);
`endif
endmodule
