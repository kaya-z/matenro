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

# The HDMI text screen alone (hdmi_text20 + the terminal, display and TMDS encoder of sim09), with the test bench tb_hdmi.cpp of sim09:
# the TMDS symbols are decoded like a monitor does (DC balance, valid symbols) and a frame is written as a PPM; check_hdmi.py compares
# the picture with the 8x16 font.   make hdmi
HDMI_SRC = ../../rtl/hdmi_text20.v $(SIM09)/rtl/hdmi_term.v $(SIM09)/rtl/hdmi_video.v $(SIM09)/rtl/tmds_enc.v hdmi_top.v
hdmi: build_hdmi/obj/Vhdmi_top
	cd build_hdmi && obj/Vhdmi_top -i $(abspath hdmi_in.txt) -o screen.ppm -f 3
	python3 check_hdmi.py build_hdmi/screen.ppm $(SIM09)/rtl/font8x16.hex
build_hdmi/obj/Vhdmi_top: $(HDMI_SRC) $(SIM09)/sim/tb_hdmi.cpp
	mkdir -p build_hdmi
	cp $(SIM09)/rtl/font8x16.hex build_hdmi/
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module hdmi_top -Mdir build_hdmi/obj \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -CFLAGS "-O2" $(HDMI_SRC) $(SIM09)/sim/tb_hdmi.cpp -o Vhdmi_top >/dev/null
.PHONY: hdmi

# The HDMI screen with kanji: the screen of sim09 (decoder UTF-8, glyph engine) on the SDRAM with the kanji image at $200000 (the model is
# loaded with it), behind psram_arb4 and sdram_ctl; the picture against the glyphs of the image (check_kanji.py).   make hdmik
KANJI_BIN ?= $(SIM09)/images/kanji.bin
HDMIK_SRC = $(SIM09)/rtl/hdmi_text.v $(SIM09)/rtl/hdmi_decode.v $(SIM09)/rtl/hdmi_glyph.v $(SIM09)/rtl/psram_xfer.v $(SIM09)/rtl/hdmi_term.v \
            $(SIM09)/rtl/hdmi_video.v $(SIM09)/rtl/tmds_enc.v ../../tn9k/rtl/psram_arb4.v ../../rtl/sdram_ctl.v sdram_model.v hdmik_top.v
hdmik: build_hdmik/obj/Vhdmi_top
	cd build_hdmik && obj/Vhdmi_top -i $(abspath hdmik_in.txt) -o screen.ppm -f 3
	python3 check_kanji.py build_hdmik/screen.ppm $(KANJI_BIN) $(SIM09)/rtl/font8x16.hex
build_hdmik/obj/Vhdmi_top: $(HDMIK_SRC) $(SIM09)/sim/tb_hdmi.cpp $(KANJI_BIN)
	mkdir -p build_hdmik
	cp $(SIM09)/rtl/font8x16.hex build_hdmik/
	python3 -c "import struct,sys; b=open('$(KANJI_BIN)','rb').read(); b+=bytes(-len(b)%4); open('build_hdmik/kanji32.hex','w').write(chr(10).join('%08x'%struct.unpack('<I',b[k:k+4])[0] for k in range(0,len(b),4))+chr(10))"
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module hdmi_top -Mdir build_hdmik/obj \
	  -GKANJI_FILE='"$(abspath build_hdmik/kanji32.hex)"' \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -CFLAGS "-O2" $(HDMIK_SRC) $(SIM09)/sim/tb_hdmi.cpp -o Vhdmi_top >/dev/null
.PHONY: hdmik

# The loader of the kanji image: the OS-9 command kanjild writes kanji.bin through the window of the XLINK (HCTL bit 1: above 2 MB) into the SDRAM;
# at HCTL bit 0 the testbench dumps the model at $200000 (kjdump.bin) and check_kjload.py compares it with the file.   make kjboot
KJ_DISK = build_kj/kd.dsk
kjboot: build_kj/obj/Vsim_top $(KJ_DISK)
	cd build_kj && rm -f kjdump.bin && obj/Vsim_top -d kd.dsk -s $(abspath kj.txt) -c 1500000000 | tr -d '\r' | grep -E "kanjild|KJDUMP|OS9:"
	cmp build_kj/kjdump.bin $(KANJI_BIN) && echo "kanjild: the image in the SDRAM equals kanji.bin (185856 bytes)"
build_kj/rom.hex:
	mkdir -p build_kj
	python3 $(SIM09)/scripts/bin2hex.py $(SIM09)/../../fuzix/images/bootrom.bin > $@
$(KJ_DISK): kj.txt ../../../tools/build_cpm.sh ../../../os9/kanjild/kanjild.asm
	mkdir -p build_kj/b build_kj/v0
	../../../tools/build_cpm.sh $(CURDIR)/build_kj/b > /dev/null
	cp $(SIM09)/../../os9/OS9L2.dsk $@
	cp $(KANJI_BIN) build_kj/v0/kanji.bin
	cp -r $(SIM09)/../../os9/level2/cmds build_kj/v0/cmds
	cp build_kj/b/kanjild build_kj/v0/cmds/
	printf 'timeout 3000000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\nsend "copy /v0/kanji.bin /d0/kanji.bin\\r"\nexpect "OS9:"\nsend "copy /v0/cmds/kanjild /d0/cmds/kanjild\\r"\nexpect "OS9:"\nsend "attr /d0/cmds/kanjild e pe r pr\\r"\nexpect "OS9:"\nquit\n' > build_kj/prep.txt
	cd build_kj && ../../../../matenro -max -rom $(SIM09)/../../os9/os9v2.rom -0 kd.dsk -v v0 -script prep.txt > prep.log 2>&1
build_kj/obj/Vsim_top: $(SOCSRC) build_kj/rom.hex $(SIM09)/sim/tb.cpp sim_top.v
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module sim_top -Mdir build_kj/obj -DSUB8088 -DHCTL -DDUMPKJ '-DUCODE_FILE="$(abspath ../../vendor/mcl86/mcl86_ucode.hex)"' \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-CASEX -Wno-VARHIDDEN -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -GROM_BASE=65280 -GROM_AW=8 -GROM_FILE='"$(abspath build_kj/rom.hex)"' -GFREERUN=0 -GPH_DIV=$(PH) -GC88_DIV=$(D88) -GCLK_HZ=$(HZ) -GMEMTEST=0 \
	  -CFLAGS "-O2" $(SOCSRC) $(SIM09)/sim/tb.cpp -o Vsim_top >/dev/null
.PHONY: kjboot
