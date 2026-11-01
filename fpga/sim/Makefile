# Verilator test of rtl/xlink.v   (make -C fpga/sim).  The test benches are pure Verilog (tb_*.v, run with --binary --timing).
all: build/Vxlink
	@ulimit -c 0; build/Vxlink
build/Vxlink: ../rtl/xlink.v tb_xlink.v
	verilator --binary --timing -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-WIDTH -Wno-fatal --top-module tb_xlink -Mdir build ../rtl/xlink.v tb_xlink.v -o Vxlink
.PHONY: all

# Z80 + XLINK + RAM (rtl/z80_soc.v) running the same Z80 demo as the C simulator.
# The TV80 core is not part of this repository: get rtl/core/{tv80_core,tv80_mcode,tv80_alu,tv80_reg,tv80s}.v from
# github.com/hutch31/tv80 and set TV80=that directory.
TV80 ?= tv80
RAMLAT ?= 12
CLKDIV ?= 9   # Z80 clock = clk / CLKDIV; 2 or more (1 is not supported)
soc: build_soc/Vz80_soc
	python3 ../../os9/sub/sumz80.py build_soc/sumz80.bin
	@ulimit -c 0; build_soc/Vz80_soc +img=build_soc/sumz80.bin
build_soc/Vz80_soc: ../rtl/z80_soc.v ../rtl/z80_sub.v ../rtl/xlink.v tb_z80_soc.v
	@test -f $(TV80)/tv80s.v || { echo "set TV80=<directory with tv80s.v tv80_core.v tv80_mcode.v tv80_alu.v tv80_reg.v>"; exit 1; }
	mkdir -p build_soc
	sh mk_tv80s_cen.sh $(TV80) build_soc/tv80s_cen.v
	verilator -Wall -Wno-fatal -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-WIDTH -Wno-PINMISSING -Wno-UNDRIVEN -Wno-CASEINCOMPLETE \
	  -Wno-LATCH -Wno-INITIALDLY -Wno-BLKSEQ -Wno-SYNCASYNCNET -Wno-MULTIDRIVEN -Wno-IMPLICIT -Wno-CASEOVERLAP -Wno-UNOPTFLAT \
	  --binary --timing -Mdir build_soc --top-module tb_z80_soc ../rtl/z80_soc.v ../rtl/z80_sub.v ../rtl/xlink.v \
	  -GCLKDIV=$(CLKDIV) -GRAMLAT=$(RAMLAT) build_soc/tv80s_cen.v $(TV80)/tv80_core.v $(TV80)/tv80_mcode.v $(TV80)/tv80_alu.v $(TV80)/tv80_reg.v tb_z80_soc.v -o Vz80_soc
.PHONY: soc
