// SPDX-License-Identifier: MIT
// hdmi_text20.v - the HDMI text screen of the Tang Nano 20K: the console bytes of the guest -> 80 x 25 characters on a 640x480
// monitor.  The terminal (hdmi_term.v: ESC sequences, colours, scrolling), the display (hdmi_video.v) and the TMDS encoder
// (tmds_enc.v) are those of sim09 (new-sbc09/fpga/tn9k/rtl, MIT, the same author; read from there by build.sh and the
// simulation, not copied).  What the 9K has more is left out here: the character decoder (UTF-8, EUC-JP, Shift_JIS) and the
// kanji engine that read tables from the PSRAM.  A byte is one glyph of the 8x16 font (font8x16.hex: ASCII, and the upper
// half of the font); the cells have no wide characters, so the line buffer of the display is not used.
// The terminal and the display run on the pixel clock (25.2 MHz); the bytes cross over with a toggle, and "queue nearly full"
// crosses back (the CPU waits for it, so no character is lost).  The video RAM has two copies: the display and the scroll.
module hdmi_text20 #(
    parameter ROWS = 25,
    parameter FONT_FILE = "font8x16.hex"
) (
    input  wire        clk,                 // system clock (the console bytes come in here)
    input  wire        rst,
    input  wire        stb,                 // a byte written to the console
    input  wire [7:0]  din,
    output wire        busy,                // the screen cannot take more characters now: hold them back
    input  wire        clk_pix,             // pixel clock 25.2 MHz
    input  wire        rst_pix,
    output wire [9:0]  tmds_b,
    output wire [9:0]  tmds_g,
    output wire [9:0]  tmds_r
);
    // ---------------------------------------------------------------- the console bytes, across the clock domains
    reg        tog = 1'b0;
    reg [7:0]  dreg;
    always @(posedge clk) if (stb) begin tog <= ~tog; dreg <= din; end       // one byte per 87 us at most
    reg [2:0]  ts;
    reg        stb_p;
    reg [7:0]  din_p;
    always @(posedge clk_pix) begin
        ts    <= {ts[1:0], tog};
        stb_p <= (ts[2] != ts[1]);
        din_p <= dreg;
    end

    // the terminal cannot take more characters (back to the system clock domain); a byte has just come in: busy, until the
    // pixel clock domain has taken it and says so itself
    wire busy_p;
    reg [1:0] bs;
    always @(posedge clk) bs <= {bs[0], busy_p};
    reg [4:0] hold = 5'd0;
    always @(posedge clk) hold <= stb ? 5'd31 : (hold != 5'd0) ? hold - 1'b1 : 5'd0;
    assign busy = bs[1] | (hold != 5'd0);

    // ---------------------------------------------------------------- video RAM (two copies) and font ROM
    wire        vw_en;
    wire [10:0] vw_addr, vr_addr, va;
    wire [23:0] vw_data;
    reg  [23:0] vr_data, vq;
    reg  [23:0] vram_a [0:2047];
    reg  [23:0] vram_b [0:2047];
    always @(posedge clk_pix) begin
        if (vw_en) begin vram_a[vw_addr] <= vw_data; vram_b[vw_addr] <= vw_data; end
        vr_data <= vram_b[vr_addr];
        vq      <= vram_a[va];
    end
    reg [7:0]  font [0:4095];
    reg [7:0]  fq;
    wire [11:0] fa;
    initial $readmemh(FONT_FILE, font);
    always @(posedge clk_pix) fq <= font[fa];

    // ---------------------------------------------------------------- terminal, display, TMDS
    wire [6:0] cur_col;
    wire [4:0] cur_row;
    hdmi_term #(.ROWS(ROWS)) term (
        .clk(clk_pix), .rst(rst_pix), .stb(stb_p), .din({4'd0, din_p}), .wide(1'b0),
        .vw_en(vw_en), .vw_addr(vw_addr), .vw_data(vw_data), .vr_addr(vr_addr), .vr_data(vr_data),
        .cur_col(cur_col), .cur_row(cur_row), .busy(busy_p)
    );

    wire [23:0] rgb;
    wire        de, hs, vs, ls_tog, nl_valid;
    wire [10:0] nl_base;
    wire [3:0]  nl_fl;
    wire [7:0]  lb_raddr;
    hdmi_video #(.ROWS(ROWS)) video (
        .clk(clk_pix), .rst(rst_pix), .va(va), .vq(vq), .fa(fa), .fq(fq),
        .cur_col(cur_col), .cur_row(cur_row), .rgb(rgb), .de(de), .hs(hs), .vs(vs),
        .lbq(8'h00), .lb_raddr(lb_raddr), .ls_tog(ls_tog), .nl_base(nl_base), .nl_fl(nl_fl), .nl_valid(nl_valid)
    );

    tmds_enc enc_b (.clk(clk_pix), .rst(rst_pix), .de(de), .c({vs, hs}), .d(rgb[7:0]),   .q(tmds_b));
    tmds_enc enc_g (.clk(clk_pix), .rst(rst_pix), .de(de), .c(2'b00),    .d(rgb[15:8]),  .q(tmds_g));
    tmds_enc enc_r (.clk(clk_pix), .rst(rst_pix), .de(de), .c(2'b00),    .d(rgb[23:16]), .q(tmds_r));
endmodule
