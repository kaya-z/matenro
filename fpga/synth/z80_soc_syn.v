// SPDX-License-Identifier: MIT
// z80_soc with a 1KB RAM: only to count the LUTs of the logic (Z80 + XLINK + glue) with fpga/synth/run.sh
module z80_soc_syn (
    input  wire clk, input wire rst,
    input  wire [2:0] m_addr, input wire m_re, input wire m_we, input wire [7:0] m_wdata,
    output wire [7:0] m_rdata, output wire m_wait, output wire irq_o, output wire firq_o,
    output wire con_we, output wire [7:0] con_data, output wire pwr_we, output wire [7:0] pwr_data, output wire z80_halted);
    z80_soc #(.RAMBITS(10), .CLKDIV(9)) u (.*);
endmodule
