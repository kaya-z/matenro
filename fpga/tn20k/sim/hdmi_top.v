// SPDX-License-Identifier: MIT
// Test bench top for the HDMI text screen of the 20K alone (tb_hdmi.cpp of sim09): console bytes in, TMDS symbols out.
module hdmi_top #(
    parameter FONT_FILE = "font8x16.hex",
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
    hdmi_text20 #(.ROWS(ROWS), .FONT_FILE(FONT_FILE)) t (
        .clk(clk), .rst(rst), .stb(stb), .din(din), .busy(busy),
        .clk_pix(clk_pix), .rst_pix(rp[3]), .tmds_b(tmds_b), .tmds_g(tmds_g), .tmds_r(tmds_r)
    );
endmodule
