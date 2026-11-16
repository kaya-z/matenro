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
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module sim_top -Mdir build_kj/obj -DSUB8088 -DHCTL -DDUMPKJ $(KJDEF) '-DUCODE_FILE="$(abspath ../../vendor/mcl86/mcl86_ucode.hex)"' \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-CASEX -Wno-VARHIDDEN -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -GROM_BASE=65280 -GROM_AW=8 -GROM_FILE='"$(abspath build_kj/rom.hex)"' -GFREERUN=0 -GPH_DIV=$(PH) -GC88_DIV=$(D88) -GCLK_HZ=$(HZ) -GMEMTEST=0 \
	  -CFLAGS "-O2" $(SOCSRC) $(SIM09)/sim/tb.cpp -o Vsim_top >/dev/null
.PHONY: kjboot

# The frame buffer of the HDMI screen: 320 x 240 x 8 bit in the SDRAM model at $300000 (fb32.hex: a test pattern), the screen (hdmi_screen20 + hdmi_fb)
# shows it doubled with the default palette and the entry 7; check_fb.py compares the whole picture.   make hdmig
HDMIG_SRC = $(SIM09)/rtl/hdmi_decode.v $(SIM09)/rtl/hdmi_glyph.v $(SIM09)/rtl/psram_xfer.v $(SIM09)/rtl/hdmi_term.v $(SIM09)/rtl/hdmi_video.v \
            $(SIM09)/rtl/tmds_enc.v ../../rtl/hdmi_screen20.v ../../rtl/hdmi_fb.v ../../tn9k/rtl/psram_arb4.v ../../rtl/sdram_ctl.v sdram_model.v hdmig_top.v
hdmig: build_hdmig/obj/Vhdmi_top
	cd build_hdmig && obj/Vhdmi_top -i $(abspath hdmig_in.txt) -o screen.ppm -f 3
	python3 check_fb.py build_hdmig/screen.ppm $(SIM09)/rtl/font8x16.hex
build_hdmig/obj/Vhdmi_top: $(HDMIG_SRC) $(SIM09)/sim/tb_hdmi.cpp fb32.hex
	mkdir -p build_hdmig
	cp $(SIM09)/rtl/font8x16.hex build_hdmig/
	python3 -c "import struct; b=open('$(KANJI_BIN)','rb').read(); b+=bytes(-len(b)%4); open('build_hdmig/kanji32.hex','w').write(chr(10).join('%08x'%struct.unpack('<I',b[k:k+4])[0] for k in range(0,len(b),4))+chr(10))"
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl $(HDMIG_DEF) --top-module hdmi_top -Mdir build_hdmig/obj \
	  -GFB_FILE='"$(abspath fb32.hex)"' -GKANJI_FILE='"$(abspath build_hdmig/kanji32.hex)"' \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -CFLAGS "-O2" $(HDMIG_SRC) $(SIM09)/sim/tb_hdmi.cpp -o Vhdmi_top >/dev/null
.PHONY: hdmig

# The OS-9 command gfx: `gfx test` writes the test picture through the window (HCTL.1) into the SDRAM; at the end the testbench dumps the 76,800 bytes at
# $300000 (fbdump.bin) and check_gfx.py compares them with the picture that the command should draw.   make gfxboot
GFX_DISK = build_gfx/gd.dsk
gfxboot: build_gfx/obj/Vsim_top $(GFX_DISK)
	cd build_gfx && rm -f fbdump.bin && obj/Vsim_top -d gd.dsk -s $(abspath gfx.txt) -c 1500000000 | tr -d '\r' | grep -E "gfx|FBDUMP|OS9:|HDMI"
	python3 check_gfx.py build_gfx/fbdump.bin
build_gfx/rom.hex:
	mkdir -p build_gfx
	python3 $(SIM09)/scripts/bin2hex.py $(SIM09)/../../fuzix/images/bootrom.bin > $@
$(GFX_DISK): gfx.txt ../../../tools/build_cpm.sh ../../../os9/gfx/gfx.asm
	mkdir -p build_gfx/b build_gfx/v0
	../../../tools/build_cpm.sh $(CURDIR)/build_gfx/b > /dev/null
	cp $(SIM09)/../../os9/OS9L2.dsk $@
	cp -r $(SIM09)/../../os9/level2/cmds build_gfx/v0/cmds
	cp build_gfx/b/gfx build_gfx/v0/cmds/
	printf 'timeout 3000000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\nsend "copy /v0/cmds/gfx /d0/cmds/gfx\\r"\nexpect "OS9:"\nsend "attr /d0/cmds/gfx e pe r pr\\r"\nexpect "OS9:"\nquit\n' > build_gfx/prep.txt
	cd build_gfx && ../../../../matenro -max -rom $(SIM09)/../../os9/os9v2.rom -0 gd.dsk -v v0 -script prep.txt > prep.log 2>&1
build_gfx/obj/Vsim_top: $(SOCSRC) build_gfx/rom.hex $(SIM09)/sim/tb.cpp sim_top.v
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module sim_top -Mdir build_gfx/obj -DSUB8088 -DHCTL -DDUMPFB '-DUCODE_FILE="$(abspath ../../vendor/mcl86/mcl86_ucode.hex)"' \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-CASEX -Wno-VARHIDDEN -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -GROM_BASE=65280 -GROM_AW=8 -GROM_FILE='"$(abspath build_gfx/rom.hex)"' -GFREERUN=0 -GPH_DIV=$(PH) -GC88_DIV=$(D88) -GCLK_HZ=$(HZ) -GMEMTEST=0 \
	  -CFLAGS "-O2" $(SOCSRC) $(SIM09)/sim/tb.cpp -o Vsim_top >/dev/null
.PHONY: gfxboot

# The whole SoC with the HDMI screen and the frame buffer (FBSOC): `gfx test` and `gfx on`, then the console must go on (the read of the frame buffer
# goes between the requests of the SoC; FBFIX=1: the arbiter's c_issue keeps it from slipping in between the decision and the pulse).   make fbsoc FBFIX=1
FBSRC = $(SOCSRC) $(SIM09)/rtl/hdmi_decode.v $(SIM09)/rtl/hdmi_glyph.v $(SIM09)/rtl/psram_xfer.v $(SIM09)/rtl/hdmi_term.v $(SIM09)/rtl/hdmi_video.v \
        $(SIM09)/rtl/tmds_enc.v ../../rtl/hdmi_screen20.v ../../rtl/hdmi_fb.v
FBDIR = build_fbsoc$(if $(FBFIX),,_nofix)
fbsoc: $(FBDIR)/obj/Vsim_top $(GFX_DISK)
	cd $(FBDIR) && cp $(SIM09)/rtl/font8x16.hex . && obj/Vsim_top -d ../build_gfx/gd.dsk -s $(abspath fbsoc.txt) -c 1500000000 | tr -d '\r' | grep -E "FBALIVE|OS9:|time out"
$(FBDIR)/rom.hex:
	mkdir -p $(FBDIR)
	python3 $(SIM09)/scripts/bin2hex.py $(SIM09)/../../fuzix/images/bootrom.bin > $@
$(FBDIR)/obj/Vsim_top: $(FBSRC) $(FBDIR)/rom.hex $(SIM09)/sim/tb.cpp sim_top.v
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module sim_top -Mdir $(FBDIR)/obj -DSUB8088 -DHCTL -DFBSOC $(if $(FBFIX),-DFBFIX) $(KJDEF) '-DUCODE_FILE="$(abspath ../../vendor/mcl86/mcl86_ucode.hex)"' \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-CASEX -Wno-VARHIDDEN -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -GROM_BASE=65280 -GROM_AW=8 -GROM_FILE='"$(abspath $(FBDIR)/rom.hex)"' -GFREERUN=0 -GPH_DIV=$(PH) -GC88_DIV=$(D88) -GCLK_HZ=$(HZ) -GMEMTEST=0 \
	  -CFLAGS "-O2" $(FBSRC) $(SIM09)/sim/tb.cpp -o Vsim_top >/dev/null
.PHONY: fbsoc

# The drawing commands of gfx (pix, line, rect, box, text) on the whole SoC: the dump of the SDRAM at $300000 against the picture that check_gfxdraw.py draws again.   make gfxdraw
gfxdraw: build_gfx/obj/Vsim_top $(GFX_DISK)
	cd build_gfx && rm -f fbdump.bin && obj/Vsim_top -d gd.dsk -s $(abspath gfxdraw.txt) -c 3000000000 | tr -d '\r' | grep -E "gfx|FBDUMP|OS9:" | tail -3
	python3 check_gfxdraw.py build_gfx/fbdump.bin $(SIM09)/rtl/font8x16.hex
.PHONY: gfxdraw

# The graphics of the sub CPUs (BDOS 112 of cpm): gdemo.com on the Z80 and gdemo86.cmd on the 8088 draw a picture through the OS-9 command cpm (the drawing
# is done by the 6809); the SDRAM dump against check_gdemo.py.  Both CPUs are in this FPGA (SUBBOTH): subsel chooses.   make gfxsub
SUBSRC = $(SOCSRC) ../../rtl/z80_sub.v build_gfxsub/tv80s_cen.v $(TV80)/tv80_core.v $(TV80)/tv80_mcode.v $(TV80)/tv80_alu.v $(TV80)/tv80_reg.v
SUB_DISK = build_gfxsub/gs.dsk
gfxsub: build_gfxsub/obj/Vsim_top $(SUB_DISK)
	cd build_gfxsub && rm -f fbdump.bin && obj/Vsim_top -d gs.dsk -s $(abspath gfxz80.txt) -c 3500000000 | tr -d '\r' | grep -E "FBDUMP|OS9:" | tail -2
	python3 check_gdemo.py build_gfxsub/fbdump.bin $(SIM09)/rtl/font8x16.hex "Hello from CP/M-80"
	cd build_gfxsub && rm -f fbdump.bin && obj/Vsim_top -d gs.dsk -s $(abspath gfx88.txt) -c 3500000000 | tr -d '\r' | grep -E "FBDUMP|OS9:" | tail -2
	python3 check_gdemo.py build_gfxsub/fbdump.bin $(SIM09)/rtl/font8x16.hex "Hello from CP/M-86"
	cd build_gfxsub && rm -f fbdump.bin && obj/Vsim_top -d gs.dsk -s $(abspath gfxdirect.txt) -c 3500000000 | tr -d '\r' | grep -E "FBDUMP|OS9:" | tail -2
	python3 check_gdirect.py build_gfxsub/fbdump.bin
	cd build_gfxsub && rm -f fbdump.bin && obj/Vsim_top -d gs.dsk -s $(abspath gfxdirect88.txt) -c 3500000000 | tr -d '\r' | grep -E "FBDUMP|OS9:" | tail -2
	python3 check_gdirect.py build_gfxsub/fbdump.bin
build_gfxsub/rom.hex:
	mkdir -p build_gfxsub
	python3 $(SIM09)/scripts/bin2hex.py $(SIM09)/../../fuzix/images/bootrom.bin > $@
build_gfxsub/tv80s_cen.v: ../../sim/mk_tv80s_cen.sh
	mkdir -p build_gfxsub
	sh ../../sim/mk_tv80s_cen.sh $(TV80) $@
$(SUB_DISK): gfxz80.txt gfx88.txt gfxdirect.txt gfxdirect88.txt ../../../tests/cpm/gdirect.asm ../../../tests/cpm/gdirect86.asm ../../../tools/build_cpm.sh ../../../os9/gfx/gfxlib.inc ../../../os9/cpm/cpmgfx.asm ../../../tests/cpm/gdemo.asm ../../../tests/cpm/gdemo86.asm
	mkdir -p build_gfxsub/b build_gfxsub/v0
	../../../tools/build_cpm.sh $(CURDIR)/build_gfxsub/b > /dev/null
	cp $(SIM09)/../../os9/OS9L2.dsk $@
	cp -r $(SIM09)/../../os9/level2/cmds build_gfxsub/v0/cmds
	cp build_gfxsub/b/cpm build_gfxsub/b/subsel build_gfxsub/v0/cmds/
	python3 ../../../tools/z80asm.py ../../../tests/cpm/gdemo.asm -o build_gfxsub/v0/gdemo.com > /dev/null
	python3 ../../../tools/z80asm.py ../../../tests/cpm/gdirect.asm -o build_gfxsub/v0/gdirect.com > /dev/null
	nasm -f bin ../../../tests/cpm/gdirect86.asm -o build_gfxsub/gdr86.bin
	python3 ../../../tools/mkcmd.py 8080 build_gfxsub/gdr86.bin build_gfxsub/v0/gdirect86.cmd
	nasm -f bin ../../../tests/cpm/gdemo86.asm -o build_gfxsub/gd86.bin
	python3 ../../../tools/mkcmd.py 8080 build_gfxsub/gd86.bin build_gfxsub/v0/gdemo86.cmd
	printf 'timeout 3000000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\nsend "copy /v0/cmds/cpm /d0/cmds/cpm\\r"\nexpect "OS9:"\nsend "copy /v0/cmds/subsel /d0/cmds/subsel\\r"\nexpect "OS9:"\nsend "attr /d0/cmds/cpm e pe r pr\\r"\nexpect "OS9:"\nsend "attr /d0/cmds/subsel e pe r pr\\r"\nexpect "OS9:"\nsend "copy /v0/gdemo.com /d0/gdemo.com\\r"\nexpect "OS9:"\nsend "copy /v0/gdemo86.cmd /d0/gdemo86.cmd\\r"\nexpect "OS9:"\nsend "copy /v0/gdirect.com /d0/gdirect.com\\r"\nexpect "OS9:"\nsend "copy /v0/gdirect86.cmd /d0/gdirect86.cmd\\r"\nexpect "OS9:"\nquit\n' > build_gfxsub/prep.txt
	cd build_gfxsub && ../../../../matenro -max -rom $(SIM09)/../../os9/os9v2.rom -0 gs.dsk -v v0 -script prep.txt > prep.log 2>&1
build_gfxsub/obj/Vsim_top: $(SUBSRC) build_gfxsub/rom.hex $(SIM09)/sim/tb.cpp sim_top.v
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module sim_top -Mdir build_gfxsub/obj -DSUBBOTH -DHCTL -DPOSTW -DDUMPFB '-DUCODE_FILE="$(abspath ../../vendor/mcl86/mcl86_ucode.hex)"' \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-CASEX -Wno-VARHIDDEN -Wno-WIDTH -Wno-INITIALDLY -Wno-BLKSEQ \
	  -GROM_BASE=65280 -GROM_AW=8 -GROM_FILE='"$(abspath build_gfxsub/rom.hex)"' -GFREERUN=0 -GPH_DIV=$(PH) -GC88_DIV=$(D88) -GCZ_DIV=$(CZ) -GCLK_HZ=$(HZ) -GMEMTEST=0 \
	  -CFLAGS "-O2" $(SUBSRC) $(SIM09)/sim/tb.cpp -o Vsim_top >/dev/null
.PHONY: gfxsub

# MS-DOS 1.25 (run mode of dos) on the whole SoC: tests/dos/gdemo.asm draws through INT E2h of the BIOS and BDOS-like request 30 of dos.asm.   make gfxdos
DOSOUT ?= /export/nas/archives/matenro/private/dosout
DOS_DISK = build_gfxsub/gdos.dsk
gfxdos: build_gfxsub/obj/Vsim_top $(DOS_DISK)
	cd build_gfxsub && rm -f fbdump.bin && obj/Vsim_top -d gdos.dsk -s $(abspath gfxdos.txt) -c 12000000000 | tr -d '\r' | grep -E "FBDUMP|OS9:|A:|A>|time out" | tail -6
	python3 check_gdemo.py build_gfxsub/fbdump.bin $(SIM09)/rtl/font8x16.hex "Hello from MS-DOS"
	cd build_gfxsub && rm -f fbdump.bin && obj/Vsim_top -d gdos.dsk -s $(abspath gfxdosdirect.txt) -c 12000000000 | tr -d '\r' | grep -E "FBDUMP|OS9:|A:|A>|time out" | tail -6
	python3 check_gdirect.py build_gfxsub/fbdump.bin
$(DOS_DISK): gfxdos.txt gfxdosdirect.txt ../../../tests/dos/gdirect.asm ../../../tools/build_cpm.sh ../../../os9/dos/dos.asm ../../../os9/dos/bios88.asm ../../../tests/dos/gdemo.asm
	mkdir -p build_gfxsub/b build_gfxsub/v1/dos
	../../../tools/build_cpm.sh $(CURDIR)/build_gfxsub/b > /dev/null
	sh ../../../tools/build_dosrun.sh $(CURDIR)/build_gfxsub/dr $(DOSOUT) > /dev/null
	cp $(SIM09)/../../os9/OS9L2.dsk $@
	cp -r $(SIM09)/../../os9/level2/cmds build_gfxsub/v1/cmds
	cp build_gfxsub/b/dos build_gfxsub/v1/cmds/
	cp $(DOSOUT)/msdos.sys build_gfxsub/dr/dosrun.img build_gfxsub/v1/dos/
	nasm -f bin ../../../tests/dos/gdemo.asm -o build_gfxsub/v1/dos/gdemo.com
	nasm -f bin ../../../tests/dos/gdirect.asm -o build_gfxsub/v1/dos/gdirect.com
	printf 'timeout 3000000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\nsend "copy /v0/cmds/dos /d0/cmds/dos\\r"\nexpect "OS9:"\nsend "attr /d0/cmds/dos e pe r pr\\r"\nexpect "OS9:"\nsend "makdir /d0/dos\\r"\nexpect "OS9:"\nsend "copy /v0/dos/msdos.sys /d0/dos/msdos.sys\\r"\nexpect "OS9:"\nsend "copy /v0/dos/dosrun.img /d0/dos/dosrun.img\\r"\nexpect "OS9:"\nsend "copy /v0/dos/gdemo.com /d0/dos/gdemo.com\\r"\nexpect "OS9:"\nsend "copy /v0/dos/gdirect.com /d0/dos/gdirect.com\\r"\nexpect "OS9:"\nsend "free /d0\\r"\nexpect "OS9:"\nquit\n' > build_gfxsub/prepd.txt
	cd build_gfxsub && ../../../../matenro -max -rom $(SIM09)/../../os9/os9v2.rom -0 gdos.dsk -v v1 -script prepd.txt > prepd.log 2>&1
.PHONY: gfxdos
