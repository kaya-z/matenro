# SPDX-License-Identifier: MIT
# Verilator tests of the Tang Nano 20K machine (make -C fpga/tn20k/sim sdram | soc)
RTL = ../../rtl
sdram: build_sdram/Vtb_sdram
	@ulimit -c 0; build_sdram/Vtb_sdram
build_sdram/Vtb_sdram: $(RTL)/sdram_ctl.v sdram_model.v tb_sdram.v
	mkdir -p build_sdram
	verilator -Wno-fatal -Wno-lint -Wno-style -Wno-DECLFILENAME -Wno-WIDTH -Wno-TIMESCALEMOD -Wno-INITIALDLY -Wno-BLKSEQ -Wno-UNOPTFLAT -Wno-CASEINCOMPLETE \
	  --binary --timing -Mdir build_sdram --top-module tb_sdram $(RTL)/sdram_ctl.v sdram_model.v tb_sdram.v -o Vtb_sdram
.PHONY: sdram

# The whole SoC (6809 + 8088 + SDRAM controller + SDRAM model) with the 6809 test ROM test/xltest88.asm (the 8088 self test of the C simulator):
#   make soc TV80=unused   needs a09 (SIM09/tools/a09) and nasm.  Expected output: S L R A5 00 12D5 (67.5 MHz / 14 = 4821 kHz); make soc PH=8 D88=12 HZ=60000000 (5000 kHz = 1388), PH=7 D88=11 HZ=54000000 (4909 kHz = 132D)
KHZHEX = $(shell python3 -c 'print("%04X" % ($(HZ) // 1000 // $(D88)))')
PH ?= 9
D88 ?= 14
HZ ?= 67500000
SIM09 ?= /export/nas/archives/MC6809/new-sbc09/fpga/tn9k
A09   ?= $(SIM09)/../../tools/a09
SOCSRC = ../../tn9k/rtl/matenro_soc.v ../../tn9k/rtl/psram_arb4.v ../../rtl/i8088_sub.v ../../rtl/eu4kx32.v ../../vendor/mcl86/eu.v ../../vendor/mcl86/biu_min.v \
         ../../rtl/xlink.v ../../rtl/shr_ap.v ../../rtl/sdram_ctl.v sdram_model.v sim_top.v \
         $(SIM09)/rtl/acia_uart.v $(SIM09)/rtl/timer_rtc.v $(SIM09)/rtl/sd_disk.v $(SIM09)/vendor/mc6809/mc6809i.v
soc: build_soc/obj/Vsim_top
	build_soc/obj/Vsim_top -nosd -c 400000000 | tee build_soc/out.txt
	@tr -d '\r\n' < build_soc/out.txt | grep -q "SLRA5 00 $(KHZHEX)" && echo "tn20k soc (6809 + 8088 + SDRAM): OK (SLR A5 00 $(KHZHEX), $(HZ) Hz)" || { echo "tn20k soc: FAILED"; exit 1; }
build_soc/rom.hex: ../test/xltest88.asm ../../../tests/i8088/core.asm
	mkdir -p build_soc
	cd ../../../tests/i8088 && nasm -f bin -DHWPORTS core.asm -o $(CURDIR)/build_soc/core_hw.bin
	python3 -c "b=open('build_soc/core_hw.bin','rb').read(); open('../test/core88.inc','w').write(chr(10).join('         fcb   '+','.join('\$$%02X'%x for x in b[k:k+16]) for k in range(0,len(b),16))+chr(10))"
	cd ../test && echo n | $(A09) -o xltest88.bin -l xltest88.lst xltest88.asm 2>&1 | tee ../sim/build_soc/a09.txt
	grep -q '^0 Pass 2 errors' ../sim/build_soc/a09.txt
	python3 $(SIM09)/scripts/bin2hex.py ../test/xltest88.bin > $@
build_soc/obj/Vsim_top: $(SOCSRC) build_soc/rom.hex $(SIM09)/sim/tb.cpp
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module sim_top -Mdir build_soc/obj -DSUB8088 $(EXTRA_V) '-DUCODE_FILE="$(abspath ../../vendor/mcl86/mcl86_ucode.hex)"' \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-CASEX -Wno-VARHIDDEN -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -GROM_BASE=61440 -GROM_AW=12 -GROM_FILE='"$(abspath build_soc/rom.hex)"' -GFREERUN=0 -GPH_DIV=$(PH) -GC88_DIV=$(D88) -GCLK_HZ=$(HZ) -GMEMTEST=0 \
	  -CFLAGS "-O2" $(SOCSRC) $(SIM09)/sim/tb.cpp -o Vsim_top >/dev/null
.PHONY: soc

# The boot ROM of sim09 ($FF00) and the card image of the machine: OS-9 Level 2 starts from the SD card (model in tb.cpp) on the whole SoC with the SDRAM.
#   make boot DISK=../../tn9k/build/matenro_l2_async.dsk SCRIPT=boot.txt CLKS=600000000 PH=7 D88=11 HZ=54000000
BOOTSRC = $(SOCSRC)
boot: build_boot/obj/Vsim_top
	build_boot/obj/Vsim_top -d $(DISK) -s $(SCRIPT) -c $(CLKS)
build_boot/rom.hex:
	mkdir -p build_boot
	python3 $(SIM09)/scripts/bin2hex.py $(SIM09)/../../fuzix/images/bootrom.bin > $@
build_boot/obj/Vsim_top: $(SOCSRC) build_boot/rom.hex $(SIM09)/sim/tb.cpp
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module sim_top -Mdir build_boot/obj -DSUB8088 '-DUCODE_FILE="$(abspath ../../vendor/mcl86/mcl86_ucode.hex)"' \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-CASEX -Wno-VARHIDDEN -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -GROM_BASE=65280 -GROM_AW=8 -GROM_FILE='"$(abspath build_boot/rom.hex)"' -GFREERUN=0 -GPH_DIV=$(PH) -GC88_DIV=$(D88) -GCLK_HZ=$(HZ) -GMEMTEST=0 \
	  -CFLAGS "-O2" $(SOCSRC) $(SIM09)/sim/tb.cpp -o Vsim_top >/dev/null
.PHONY: boot

# Both sub CPUs in the FPGA (`define SUBBOTH): the register SUBSEL ($FFCF, the OS-9 command subsel) chooses the Z80 or the 8088.
#   make bothboot TV80=<dir with tv80s.v ...> DISK=../build/matenro20k_l2.dsk SCRIPT=both.txt CLKS=900000000 PH=7 D88=11 HZ=54000000 CZ=7
TV80 ?= /export/nas/archives/matenro/private/tv80src/rtl/core
CZ ?= 7
BOTHSRC = $(SOCSRC) ../../rtl/z80_sub.v build_both/tv80s_cen.v $(TV80)/tv80_core.v $(TV80)/tv80_mcode.v $(TV80)/tv80_alu.v $(TV80)/tv80_reg.v
bothboot: build_both/obj/Vsim_top
	build_both/obj/Vsim_top -d $(DISK) -s $(SCRIPT) -c $(CLKS)
build_both/rom.hex:
	mkdir -p build_both
	python3 $(SIM09)/scripts/bin2hex.py $(SIM09)/../../fuzix/images/bootrom.bin > $@
build_both/tv80s_cen.v: ../../sim/mk_tv80s_cen.sh
	mkdir -p build_both
	sh ../../sim/mk_tv80s_cen.sh $(TV80) $@
build_both/obj/Vsim_top: $(BOTHSRC) build_both/rom.hex $(SIM09)/sim/tb.cpp
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module sim_top -Mdir build_both/obj -DSUBBOTH '-DUCODE_FILE="$(abspath ../../vendor/mcl86/mcl86_ucode.hex)"' \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-CASEX -Wno-VARHIDDEN -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -GROM_BASE=65280 -GROM_AW=8 -GROM_FILE='"$(abspath build_both/rom.hex)"' -GFREERUN=0 -GPH_DIV=$(PH) -GC88_DIV=$(D88) -GCZ_DIV=$(CZ) -GCLK_HZ=$(HZ) -GMEMTEST=0 \
	  -CFLAGS "-O2" $(BOTHSRC) $(SIM09)/sim/tb.cpp -o Vsim_top >/dev/null
.PHONY: bothboot
