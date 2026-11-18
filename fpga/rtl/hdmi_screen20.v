// SPDX-License-Identifier: MIT
// hdmi_screen20.v - the HDMI screen of the Tang Nano 20K: hdmi_text.v of sim09 (sim09/fpga/tn9k/rtl, MIT, the same author: the same
// parts, the same connections) with the frame buffer (hdmi_fb.v) between the display (hdmi_video) and the TMDS encoders.  With gfx_on the picture
// of the frame buffer replaces the text.  The ports of the frame buffer: the palette write, and the read of the SDRAM (rq / go / busy / dout32:
// the top level connects them to sdram_ctl).
module hdmi_screen20 #(
    parameter ROWS = 25,
    parameter CHARSET = 1,
    parameter FONT_FILE = "font8x16.hex"
) (
    input  wire        clk,                 // system clock (the console bytes come in here)
    input  wire        rst,
    input  wire        stb,                 // a byte written to the console
    input  wire [7:0]  din,
    output wire        busy,                // the screen cannot take more characters now: hold them back
    input  wire        kanji_ok,            // the kanji image is in the PSRAM
    // PSRAM word reads (arbiter masters 1 and 2)
    output wire        x1_req,
    output wire [21:0] x1_addr,
    input  wire        x1_ack,
    input  wire [15:0] x1_rdata,
    output wire        x2_req,
    output wire [21:0] x2_addr,
    input  wire        x2_ack,
    input  wire [15:0] x2_rdata,
    input  wire        clk_pix,             // pixel clock 25.2 MHz (the terminal runs on it, too)
    input  wire        rst_pix,
    output wire [9:0]  tmds_b,
    output wire [9:0]  tmds_g,
    output wire [9:0]  tmds_r,
    // the frame buffer
    input  wire        gfx_on,
    input  wire        gfx_ov,
    input  wire        pc_on,               // the text screen shows the text memory of the PC (B800h of the sub CPU: hdmi_pctext.v)
    input  wire [6:0]  pc_col,              // its cursor
    input  wire [4:0]  pc_row,
    input  wire        pal_we,
    input  wire [7:0]  pal_idx,
    input  wire [23:0] pal_rgb,
    output wire        fb_rq,
    output wire [21:0] fb_addr,
    output wire [6:0]  fb_n,
    input  wire        fb_go,
    input  wire        fb_busy,
    input  wire        fb_dv,
    input  wire [31:0] fb_dout32
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

    // ---------------------------------------------------------------- the text memory of the PC: the switch and the cursor, in the pixel clock domain
    reg [1:0]   pq = 2'b00;
    always @(posedge clk_pix) pq <= {pq[0], pc_on};
    wire        pc_p = pq[1];
    reg [11:0]  pcs, pcs2;                            // the cursor of the PC, sampled twice (it changes rarely)
    always @(posedge clk_pix) begin pcs <= {pc_row, pc_col}; pcs2 <= pcs; end

    // ---------------------------------------------------------------- the decoder (pixel clock), PSRAM look-ups through psram_xfer
    wire        dec_busy, sym_stb, sym_wide;
    wire [11:0] sym;
    wire        xp_req, xp_ack;
    wire [21:0] xp_addr;
    wire [15:0] xp_rdata;
    // (declared before its use: a net used in a port connection before its declaration is an implicit net, and the Gowin
    // tool then leaves the later declaration without a driver: kanji_ok_p stayed 0 on the board)
    reg [1:0] kq;
    always @(posedge clk_pix) kq <= {kq[0], kanji_ok};
    wire kanji_ok_p = kq[1];
    hdmi_decode #(.CHARSET(CHARSET)) decode (
        .clk(clk_pix), .rst(rst_pix), .kanji_ok(kanji_ok_p), .stb(stb_p), .din(din_p), .busy(dec_busy),
        .sym_stb(sym_stb), .sym_wide(sym_wide), .sym(sym),
        .x_req(xp_req), .x_addr(xp_addr), .x_ack(xp_ack && !pc_p), .x_rdata(xp_rdata)
    );
    // the text memory of the PC: the engine uses the request port of the decoder (the decoder gets no bytes while the PC text is shown)
    wire        pc_req, pc_we;
    wire [21:0] pc_addr;
    wire [10:0] pc_wa;
    wire [23:0] pc_wd;
    hdmi_pctext pctext (.clk(clk_pix), .rst(rst_pix), .on(pc_p), .req(pc_req), .addr(pc_addr), .ack(xp_ack && pc_p), .rdata(xp_rdata),
                        .we(pc_we), .wa(pc_wa), .wd(pc_wd));
    wire        xr_req  = pc_p ? pc_req : xp_req;
    wire [21:0] xr_addr = pc_p ? pc_addr : xp_addr;
    psram_xfer xfer (
        .clk_a(clk_pix), .req_a(xr_req), .addr_a(xr_addr), .ack_a(xp_ack), .rdata_a(xp_rdata),
        .clk_b(clk), .req_b(x1_req), .addr_b(x1_addr), .ack_b(x1_ack), .rdata_b(x1_rdata)
    );

    // the screen cannot take more characters: the decoder or the terminal queue is busy (back to the system clock domain)
    wire busy_p;
    reg [1:0] bs;
    always @(posedge clk) bs <= {bs[0], busy_p | dec_busy};
    reg [4:0] hold = 5'd0;                      // a byte has just come in: busy, until the pixel clock domain has taken it and says so itself
    always @(posedge clk) hold <= stb ? 5'd31 : (hold != 5'd0) ? hold - 1'b1 : 5'd0;
    assign busy = bs[1] | (hold != 5'd0);

    // ---------------------------------------------------------------- video RAM (three copies) and line buffer
    wire        vw_en_t;
    wire [10:0] vw_addr_t, vr_addr, va, vc_addr;
    wire [23:0] vw_data_t;
    // the terminal writes the cells, or (PC text) the engine does
    wire        vw_en   = pc_p ? pc_we : vw_en_t;
    wire [10:0] vw_addr = pc_p ? pc_wa : vw_addr_t;
    wire [23:0] vw_data = pc_p ? pc_wd : vw_data_t;
    reg  [23:0] vr_data, vq, vc_data;
    reg  [23:0] vram_a [0:2047];
    reg  [23:0] vram_b [0:2047];
    reg  [23:0] vram_c [0:2047];
    always @(posedge clk_pix) begin
        if (vw_en) begin vram_a[vw_addr] <= vw_data; vram_b[vw_addr] <= vw_data; vram_c[vw_addr] <= vw_data; end
        vr_data <= vram_b[vr_addr];
        vq      <= vram_a[va];
    end
    always @(posedge clk) vc_data <= vram_c[vc_addr];

    wire        lb_we;
    wire [7:0]  lb_addr, lb_data, lb_raddr;
    reg  [7:0]  lbram [0:255];
    reg  [7:0]  lbq;
    always @(posedge clk)     if (lb_we) lbram[lb_addr] <= lb_data;
    always @(posedge clk_pix) lbq <= lbram[lb_raddr];

    // ---------------------------------------------------------------- font ROM
    reg [7:0]  font [0:4095];
    reg [7:0]  fq;
    wire [11:0] fa;
    initial $readmemh(FONT_FILE, font);
    always @(posedge clk_pix) fq <= font[fa];

    // ---------------------------------------------------------------- terminal, display, glyph engine, TMDS
    wire [6:0] cur_col_t;
    wire [4:0] cur_row_t;
    wire [6:0] cur_col = pc_p ? pcs2[6:0] : cur_col_t;
    wire [4:0] cur_row = pc_p ? pcs2[11:7] : cur_row_t;
    hdmi_term #(.ROWS(ROWS)) term (
        .clk(clk_pix), .rst(rst_pix), .stb(sym_stb), .din(sym), .wide(sym_wide),
        .vw_en(vw_en_t), .vw_addr(vw_addr_t), .vw_data(vw_data_t), .vr_addr(vr_addr), .vr_data(vr_data),
        .cur_col(cur_col_t), .cur_row(cur_row_t), .busy(busy_p)
    );

    wire [23:0] rgb;
    wire        de, hs, vs, ls_tog, nl_valid;
    wire [10:0] nl_base;
    wire [3:0]  nl_fl;
    hdmi_video #(.ROWS(ROWS)) video (
        .clk(clk_pix), .rst(rst_pix), .va(va), .vq(vq), .fa(fa), .fq(fq),
        .cur_col(cur_col), .cur_row(cur_row), .rgb(rgb), .de(de), .hs(hs), .vs(vs),
        .lbq(lbq), .lb_raddr(lb_raddr), .ls_tog(ls_tog), .nl_base(nl_base), .nl_fl(nl_fl), .nl_valid(nl_valid)
    );

    hdmi_glyph glyph (
        .clk(clk), .rst(rst), .ls_tog(ls_tog), .nl_base(nl_base), .nl_fl(nl_fl), .nl_valid(nl_valid),
        .vc_addr(vc_addr), .vc_data(vc_data), .lb_we(lb_we), .lb_addr(lb_addr), .lb_data(lb_data),
        .x_req(x2_req), .x_addr(x2_addr), .x_ack(x2_ack), .x_rdata(x2_rdata)
    );

    wire        de_f, hs_f, vs_f;
    wire [23:0] rgb_f;
    hdmi_fb fb (
        .clk(clk), .rst(rst), .gfx_on(gfx_on), .gfx_ov(gfx_ov), .pal_we(pal_we), .pal_idx(pal_idx), .pal_rgb(pal_rgb),
        .rq(fb_rq), .rq_addr(fb_addr), .rq_n(fb_n), .go(fb_go), .busy(fb_busy), .dv(fb_dv), .dout32(fb_dout32),
        .clk_pix(clk_pix), .rst_pix(rst_pix), .de_i(de), .hs_i(hs), .vs_i(vs), .rgb_i(rgb),
        .de_o(de_f), .hs_o(hs_f), .vs_o(vs_f), .rgb_o(rgb_f)
    );

    tmds_enc enc_b (.clk(clk_pix), .rst(rst_pix), .de(de_f), .c({vs_f, hs_f}), .d(rgb_f[7:0]),   .q(tmds_b));
    tmds_enc enc_g (.clk(clk_pix), .rst(rst_pix), .de(de_f), .c(2'b00),        .d(rgb_f[15:8]),  .q(tmds_g));
    tmds_enc enc_r (.clk(clk_pix), .rst(rst_pix), .de(de_f), .c(2'b00),        .d(rgb_f[23:16]), .q(tmds_r));
endmodule
