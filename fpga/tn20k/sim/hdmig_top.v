// SPDX-License-Identifier: MIT
// Test bench top for the frame buffer of the HDMI screen (tb_hdmi.cpp of sim09): the screen with the frame buffer (hdmi_screen20) on the SDRAM
// (the picture is in the model at $300000, loaded from a file), the read of the frame buffer goes before the SoC as in tn20k_top.v, gfx_on = 1,
// and the palette entry 7 is written by a small sequence after the reset.
module hdmi_top #(
    parameter FONT_FILE = "font8x16.hex",
    parameter KANJI_FILE = "kanji32.hex",
    parameter FB_FILE = "fb32.hex",
    parameter CHARSET = 1,
    parameter ROWS = 25
) (
    input  wire        clk,
    input  wire        clk_pix,
    input  wire        rst,
    input  wire        stb,
    input  wire [7:0]  din,
    output wire        busy,
    output wire [9:0]  tmds_b,
    output wire [9:0]  tmds_g,
    output wire [9:0]  tmds_r
);
    reg [3:0] rp = 4'hf;
    always @(posedge clk_pix) rp <= {rp[2:0], rst};

    wire        x1_req, x1_ack, x2_req, x2_ack;
    wire [21:0] x1_addr, x2_addr;
    wire [15:0] x1_rdata, x2_rdata;
    wire        ctl_busy, fb_rq, fb_go, ps_rd, ps_wr, ps_bw, ps_busy;
    wire [21:0] fb_addr, ps_addr;
    wire [31:0] fb_dout32;
    wire [15:0] ps_din, ps_dout;
    wire   ps_issue;
    assign fb_go   = fb_rq && !ctl_busy && !ps_rd && !ps_wr && !ps_issue;
    assign ps_busy = ctl_busy || fb_go;

    // the palette: entry 7 = (255, 0, 255), written a little after the reset
    reg [15:0] pc = 16'd0;
    reg        pal_we = 1'b0;
    reg [7:0]  pal_idx = 8'd0;
    reg [23:0] pal_rgb = 24'd0;
    always @(posedge clk) begin
        pal_we <= 1'b0;
        if (rst) pc <= 16'd0;
        else begin
            if (pc != 16'hffff) pc <= pc + 1'b1;
            if (pc == 16'd100) begin pal_we <= 1'b1; pal_idx <= 8'd7; pal_rgb <= 24'hff00ff; end
        end
    end

    hdmi_screen20 #(.ROWS(ROWS), .CHARSET(CHARSET), .FONT_FILE(FONT_FILE)) t (
        .clk(clk), .rst(rst), .stb(stb), .din(din), .busy(busy), .kanji_ok(1'b1),
        .x1_req(x1_req), .x1_addr(x1_addr), .x1_ack(x1_ack), .x1_rdata(x1_rdata),
        .x2_req(x2_req), .x2_addr(x2_addr), .x2_ack(x2_ack), .x2_rdata(x2_rdata),
        .clk_pix(clk_pix), .rst_pix(rp[3]), .tmds_b(tmds_b), .tmds_g(tmds_g), .tmds_r(tmds_r),
        .gfx_on(1'b1), .gfx_ov(1'b1), .pal_we(pal_we), .pal_idx(pal_idx), .pal_rgb(pal_rgb),
        .fb_rq(fb_rq), .fb_addr(fb_addr), .fb_go(fb_go), .fb_busy(ctl_busy), .fb_dout32(fb_dout32)
    );
    psram_arb4 arb (
        .clk(clk), .rst(rst),
        .c_rd(ps_rd), .c_wr(ps_wr), .c_addr(ps_addr), .c_din(ps_din), .c_bw(ps_bw), .c_dout(ps_dout), .c_busy(ps_busy), .c_issue(ps_issue),
        .m0_req(1'b0), .m0_wr(1'b0), .m0_addr(22'd0), .m0_din(8'd0), .m0_ack(), .m0_rdata(),
        .m1_req(x1_req), .m1_addr(x1_addr), .m1_ack(x1_ack), .m1_rdata(x1_rdata),
        .m2_req(x2_req), .m2_addr(x2_addr), .m2_ack(x2_ack), .m2_rdata(x2_rdata),
        .m3_req(1'b0), .m3_wr(1'b0), .m3_addr(22'd0), .m3_din(8'd0), .m3_ack(), .m3_rdata(),
        .m4_req(1'b0), .m4_wr(1'b0), .m4_addr(22'd0), .m4_din(8'd0), .m4_ack(), .m4_rdata()
    );
    wire        clk_sdram = ~clk;
    wire        sd_clk, sd_cke, sd_cs_n, sd_cas_n, sd_ras_n, sd_wen_n;
    wire [3:0]  sd_dqm;
    wire [10:0] sd_a;
    wire [1:0]  sd_ba;
    wire [31:0] sd_dq;
    sdram_ctl #(.FREQ(67500000), .REFRESH_CLKS(67500000 / 1000 * 74 / 10000)) ctl (
        .clk(clk), .clk_sdram(clk_sdram), .resetn(~rst),
        .read(ps_rd || fb_go), .write(ps_wr), .addr(fb_go ? fb_addr : ps_addr), .din(ps_din), .byte_write(ps_bw), .wide(fb_go), .dout(ps_dout),
        .dout32(fb_dout32), .busy(ctl_busy),
        .O_sdram_clk(sd_clk), .O_sdram_cke(sd_cke), .O_sdram_cs_n(sd_cs_n), .O_sdram_cas_n(sd_cas_n), .O_sdram_ras_n(sd_ras_n),
        .O_sdram_wen_n(sd_wen_n), .O_sdram_dqm(sd_dqm), .O_sdram_addr(sd_a), .O_sdram_ba(sd_ba), .IO_sdram_dq(sd_dq)
    );
    wire [31:0] errors;
    wire        init_done;
    sdram_model #(.INIT_FILE(FB_FILE), .INIT_WORD(20'hC0000)) mem (
        .clk(sd_clk), .cke(sd_cke), .cs_n(sd_cs_n), .ras_n(sd_ras_n), .cas_n(sd_cas_n), .we_n(sd_wen_n),
        .dqm(sd_dqm), .a(sd_a), .ba(sd_ba), .dq(sd_dq), .errors(errors), .init_done(init_done)
    );
endmodule
