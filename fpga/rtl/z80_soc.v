// SPDX-License-Identifier: MIT
// z80_soc.v - z80_sub.v with a simulation RAM (2MB, behind the request / acknowledge port) for the Verilator test
// (fpga/sim/tb_z80_soc.cpp, which runs the same Z80 binary as the C simulator).  RAMLAT = clocks an access of the Z80
// takes (to test the stall of the Z80 clock enable).  The window of the XLINK has a port of its own.
module z80_soc #(
    parameter CLKDIV  = 9,
    parameter RAMBITS = 21,
    parameter RAMLAT  = 12
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
    reg         mem_ack;
    reg  [7:0]  mem_rdata;
    wire [39:0] dbg_z;

    z80_sub #(.CLKDIV(CLKDIV)) sub (.*);

    reg [7:0] ram [0:(1<<RAMBITS)-1];
    wire [RAMBITS-1:0] zadr = mem_addr[RAMBITS-1:0];
    wire [RAMBITS-1:0] wadr = win_addr[RAMBITS-1:0];

    // Z80 port: the access is made RAMLAT clocks after the request
    reg [7:0] lat;
    always @(posedge clk) begin
        mem_ack <= 1'b0;
        if (!mem_req) lat <= 8'd0;
        else if (!mem_ack) begin
            lat <= lat + 8'd1;
            if (lat == RAMLAT) begin
                if (mem_wr) ram[zadr] <= mem_wdata;
                else        mem_rdata <= ram[zadr];
                mem_ack <= 1'b1;
            end
        end
    end
    // window port: one clock
    reg win_ack_r;
    always @(posedge clk) begin
        win_ack_r <= 1'b0;
        if (win_req && !win_ack_r) begin
            if (win_wr) ram[wadr] <= win_wdata;
            win_rdata <= ram[wadr];
            win_ack_r <= 1'b1;
        end
    end
    assign win_ack = win_ack_r;
endmodule
