// SPDX-License-Identifier: MIT
// Timing constraints of the Matenro machine on the Tang Nano 20K (GW2AR-18C).
// 27 MHz crystal, and the PLL's outputs: 67.5 MHz (the system clock) and the same shifted by 180 degrees (the SDRAM clock).
create_clock -name sys_clk -period 37.037 -waveform {0 18.518} [get_ports {sys_clk}]
create_generated_clock -name clk81 -source [get_ports {sys_clk}] -master_clock sys_clk -multiply_by 5 -divide_by 2 [get_pins {pll/rpll_inst/CLKOUT}]
create_generated_clock -name clk81p -source [get_ports {sys_clk}] -master_clock sys_clk -multiply_by 5 -divide_by 2 -phase 180 [get_pins {pll/rpll_inst/CLKOUTP}]

// The 6809 (vendor/mc6809) is clocked by E and Q, which matenro_soc.v makes from the 67.5 MHz clock:
// one bus cycle = 4 phases of PH_DIV clocks (9 at 67.5 MHz = 533.3 ns); build.sh fills in @PER@ etc. for the clock that it builds.
create_clock -name E -period @PER@ -waveform {@HALF@ @PER@} [get_nets {soc/e}]
create_clock -name Q -period @PER@ -waveform {@Q1@ @Q3@} [get_nets {soc/q}]
set_false_path -from [get_clocks {clk81}] -to [get_clocks {E Q}]
set_false_path -from [get_clocks {E Q}] -to [get_clocks {clk81}]
