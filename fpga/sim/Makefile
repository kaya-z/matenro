# Verilator test of rtl/xlink.v   (make -C fpga/sim).  The test benches are pure Verilog (tb_*.v, run with --binary --timing).
all: build/Vxlink build_btn/Vbtn
	@ulimit -c 0; build/Vxlink
	@ulimit -c 0; build_btn/Vbtn
build/Vxlink: ../rtl/xlink.v tb_xlink.v
	verilator --binary --timing -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-WIDTH -Wno-fatal --top-module tb_xlink -Mdir build ../rtl/xlink.v tb_xlink.v -o Vxlink
build_btn/Vbtn: ../tn9k/rtl/btn_toggle.v tb_btn.v
	verilator --binary --timing -Wall -Wno-DECLFILENAME -Wno-fatal --top-module tb_btn -Mdir build_btn ../tn9k/rtl/btn_toggle.v tb_btn.v -o Vbtn
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
build_soc/Vz80_soc: ../rtl/z80_soc.v ../rtl/z80_sub.v ../rtl/xlink.v ../rtl/shr_ap.v tb_z80_soc.v
	@test -f $(TV80)/tv80s.v || { echo "set TV80=<directory with tv80s.v tv80_core.v tv80_mcode.v tv80_alu.v tv80_reg.v>"; exit 1; }
	mkdir -p build_soc
	sh mk_tv80s_cen.sh $(TV80) build_soc/tv80s_cen.v
	verilator -Wall -Wno-fatal -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-WIDTH -Wno-PINMISSING -Wno-UNDRIVEN -Wno-CASEINCOMPLETE \
	  -Wno-LATCH -Wno-INITIALDLY -Wno-BLKSEQ -Wno-SYNCASYNCNET -Wno-MULTIDRIVEN -Wno-IMPLICIT -Wno-CASEOVERLAP -Wno-UNOPTFLAT \
	  --binary --timing -Mdir build_soc --top-module tb_z80_soc ../rtl/z80_soc.v ../rtl/z80_sub.v ../rtl/xlink.v ../rtl/shr_ap.v \
	  -GCLKDIV=$(CLKDIV) -GRAMLAT=$(RAMLAT) build_soc/tv80s_cen.v $(TV80)/tv80_core.v $(TV80)/tv80_mcode.v $(TV80)/tv80_alu.v $(TV80)/tv80_reg.v tb_z80_soc.v -o Vz80_soc
.PHONY: soc

# 8088 (MCL86, fpga/vendor/mcl86) + XLINK + RAM (rtl/i8088_soc.v) running the self test of the C simulator (tests/i8088/core.asm,
# without the two checks of the port RAM).  nasm is needed.
I8088CLKDIV ?= 14
I8088RAMLAT ?= 12
i8088: build_i8088/Vi8088_soc
	cd ../../tests/i8088 && nasm -f bin -DHWPORTS core.asm -o $(CURDIR)/build_i8088/core_hw.bin
	@ulimit -c 0; build_i8088/Vi8088_soc +img=build_i8088/core_hw.bin
build_i8088/Vi8088_soc: ../rtl/i8088_soc.v ../rtl/i8088_sub.v ../rtl/eu4kx32.v ../vendor/mcl86/eu.v ../vendor/mcl86/biu_min.v ../rtl/xlink.v ../rtl/shr_ap.v tb_i8088_soc.v
	mkdir -p build_i8088
	verilator -Wno-fatal -Wno-lint -Wno-style -Wno-DECLFILENAME -Wno-WIDTH -Wno-PINMISSING -Wno-UNDRIVEN -Wno-CASEINCOMPLETE -Wno-LATCH \
	  -Wno-INITIALDLY -Wno-BLKSEQ -Wno-SYNCASYNCNET -Wno-MULTIDRIVEN -Wno-IMPLICIT -Wno-CASEOVERLAP -Wno-UNOPTFLAT -Wno-TIMESCALEMOD \
	  --binary --timing $(EXTRA_V) -Mdir build_i8088 --top-module tb_i8088_soc '-DUCODE_FILE="$(abspath ../vendor/mcl86/mcl86_ucode.hex)"' \
	  -GCLKDIV=$(I8088CLKDIV) -GRAMLAT=$(I8088RAMLAT) ../rtl/i8088_soc.v ../rtl/i8088_sub.v ../rtl/eu4kx32.v ../vendor/mcl86/eu.v ../vendor/mcl86/biu_min.v ../rtl/xlink.v ../rtl/shr_ap.v tb_i8088_soc.v -o Vi8088_soc
.PHONY: i8088
