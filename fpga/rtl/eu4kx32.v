// SPDX-License-Identifier: MIT
// eu4kx32.v - the microcode ROM of the MCL86 execution unit (4096 x 32 bit, synchronous read).
//
// eu.v of MCL86 (fpga/vendor/mcl86) instantiates a memory with this name and these ports (a Xilinx / Lattice IP in the
// original project).  The contents are the microcode of MCL86 (MCL86_Microcode_Xilinx_Version_4.coe, one word per line in
// fpga/vendor/mcl86/mcl86_ucode.hex); the build scripts define UCODE_FILE as the path of that file.
`ifndef UCODE_FILE
`define UCODE_FILE "mcl86_ucode.hex"
`endif
module EU4Kx32 (
    input  wire        clka,
    input  wire [11:0] addra,
    output reg  [31:0] douta
);
    reg [31:0] mem [0:4095];
    initial $readmemh(`UCODE_FILE, mem);
    always @(posedge clka) douta <= mem[addra];
endmodule
