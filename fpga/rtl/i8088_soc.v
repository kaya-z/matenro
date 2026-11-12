// SPDX-License-Identifier: MIT
// i8088_soc.v - i8088_sub.v (MCL86) with a simulation RAM (2MB, behind the request / acknowledge port) for the Verilator test
// (fpga/sim/tb_i8088_soc.v, which runs the 8088 self test of tests/i8088/core.asm).  RAMLAT = clocks an access of the 8088
// takes (to test the stall of the Z80 clock enable).  The window of the XLINK has a port of its own.
module i8088_soc #(
    parameter CLKDIV  = 14,
    parameter RAMBITS = 21,
    parameter RAMLAT  = 12,
    parameter [7:0] SHR_BLK = 8'hff          // the block that is served by shr_ap.v (BSRAM, two ports)
) (
    input  wire        clk,
    input  wire        rst,
    input  wire [2:0]  m_addr,
    input  wire        m_re,
    input  wire        m_we,
    input  wire [7:0]  m_wdata,
    output wire [7:0]  m_rdata,              // one clock late
    output wire        m_wait,
    output wire        m_win,
    output wire        sub_on,
    output wire        irq_o,
    output wire        firq_o,
    output wire        con_we,
    output wire [7:0]  con_data,
    output wire        pwr_we,
    output wire [7:0]  pwr_data,
    output wire        z80_halted
);
    wire        win_req, win_wr, win_ack;
    wire [20:0] win_addr;
    wire [7:0]  win_wdata;
    reg  [7:0]  win_rdata;
    wire        mem_req, mem_wr;
    wire [20:0] mem_addr;
    wire [7:0]  mem_wdata;
    wire        mem_ack;
    wire [7:0]  mem_rdata;
    reg         mem_ack_r;
    reg  [7:0]  mem_rdata_r;
    wire        zb_hit, zb_ack, wb_hit, wb_ack;
    wire [7:0]  zb_rdata, wb_rdata;
    wire [39:0] dbg_z;

    i8088_sub #(.CLKDIV(CLKDIV)) sub (.*);

    reg [7:0] ram [0:(1<<RAMBITS)-1];
    wire [RAMBITS-1:0] zadr = mem_addr[RAMBITS-1:0];
    wire [RAMBITS-1:0] wadr = win_addr[RAMBITS-1:0];

    // 8088 port: the access is made RAMLAT clocks after the request
    integer latcfg;
    initial if (!$value$plusargs("lat=%d", latcfg)) latcfg = RAMLAT;      // +lat=n: the latency of the RAM in clocks (a test bench option)
    reg [7:0] lat;
    always @(posedge clk) begin
        mem_ack_r <= 1'b0;
        if (!mem_req || zb_hit) lat <= 8'd0;
        else if (!mem_ack_r) begin
            lat <= lat + 8'd1;
            if (lat == latcfg[7:0]) begin
                if (mem_wr) ram[zadr] <= mem_wdata;
                else        mem_rdata_r <= ram[zadr];
                mem_ack_r <= 1'b1;
            end
        end
    end
    // window port: one clock
    reg win_ack_r;
    always @(posedge clk) begin
        win_ack_r <= 1'b0;
        if (wb_ack) win_rdata <= wb_rdata;
        if (win_req && !win_ack_r && !wb_hit) begin
            if (win_wr) ram[wadr] <= win_wdata;
            win_rdata <= ram[wadr];
            win_ack_r <= 1'b1;
        end
    end
    reg wb_ack_q = 1'b0;
    always @(posedge clk) wb_ack_q <= wb_ack;
    assign win_ack = win_ack_r | wb_ack_q;

    // the shared RAM of 8 KB in the BSRAM
    shr_ap #(.BLK(SHR_BLK)) shr (
        .clk(clk), .rst(rst),
        .a_req(mem_req), .a_wr(mem_wr), .a_addr(mem_addr), .a_wdata(mem_wdata), .a_hit(zb_hit), .a_ack(zb_ack), .a_rdata(zb_rdata),
        .w_req(win_req), .w_wr(win_wr), .w_addr(win_addr), .w_wdata(win_wdata), .w_hit(wb_hit), .w_ack(wb_ack), .w_rdata(wb_rdata)
    );
`ifdef TRACE88
    always @(posedge clk) if (mem_ack) $display("%s %h %h", mem_wr ? "W" : "R", mem_addr, mem_wr ? mem_wdata : mem_rdata);
`endif
    assign mem_ack   = mem_ack_r | zb_ack;
    assign mem_rdata = zb_ack ? zb_rdata : mem_rdata_r;
endmodule
