# Verilator test of rtl/xlink.v   (make -C fpga/sim)
all: build/Vxlink
	build/Vxlink
build/Vxlink: ../rtl/xlink.v tb_xlink.cpp
	verilator -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-WIDTH --cc --exe --build -Mdir build ../rtl/xlink.v tb_xlink.cpp -o Vxlink
.PHONY: all

# Z80 + XLINK + RAM (rtl/z80_soc.v) running the same Z80 demo as the C simulator.
# The TV80 core is not part of this repository: get rtl/core/{tv80_core,tv80_mcode,tv80_alu,tv80_reg,tv80s}.v from
# github.com/hutch31/tv80 and set TV80=that directory.
TV80 ?= tv80
soc: build_soc/Vz80_soc
	python3 ../../os9/sub/sumz80.py build_soc/sumz80.bin
	build_soc/Vz80_soc build_soc/sumz80.bin
build_soc/Vz80_soc: ../rtl/z80_soc.v ../rtl/xlink.v tb_z80_soc.cpp
	@test -f $(TV80)/tv80s.v || { echo "set TV80=<directory with tv80s.v tv80_core.v tv80_mcode.v tv80_alu.v tv80_reg.v>"; exit 1; }
	mkdir -p build_soc
	verilator -Wall -Wno-fatal -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-WIDTH -Wno-PINMISSING -Wno-UNDRIVEN -Wno-CASEINCOMPLETE \
	  -Wno-LATCH -Wno-INITIALDLY -Wno-BLKSEQ -Wno-SYNCASYNCNET -Wno-MULTIDRIVEN -Wno-IMPLICIT -Wno-CASEOVERLAP -Wno-UNOPTFLAT \
	  --cc --exe --build -Mdir build_soc --top-module z80_soc ../rtl/z80_soc.v ../rtl/xlink.v \
	  $(TV80)/tv80s.v $(TV80)/tv80_core.v $(TV80)/tv80_mcode.v $(TV80)/tv80_alu.v $(TV80)/tv80_reg.v tb_z80_soc.cpp -o Vz80_soc
.PHONY: soc
