# SPDX-License-Identifier: MIT
# Verilator simulation of the Matenro SoC (6809 + PSRAM + XLINK + Z80), with the test bench and the PSRAM model of sim09.
#   make TV80=<dir with tv80s.v tv80_core.v tv80_mcode.v tv80_alu.v tv80_reg.v>    build and run the test ROM (xltest)
SIM09 ?= /export/nas/archives/MC6809/new-sbc09/fpga/tn9k
TV80  ?= tv80
CZDIV ?= 9
B     := build
RTL    = ../rtl/matenro_soc.v ../rtl/psram_arb4.v ../../rtl/z80_sub.v ../../rtl/xlink.v ../../rtl/shr_ap.v \
         $(SIM09)/rtl/acia_uart.v $(SIM09)/rtl/timer_rtc.v $(SIM09)/rtl/sd_disk.v \
         $(SIM09)/vendor/mc6809/mc6809i.v $(SIM09)/sim/psram_model.v sim_top.v
TV80V  = $(B)/tv80s_cen.v $(TV80)/tv80_core.v $(TV80)/tv80_mcode.v $(TV80)/tv80_alu.v $(TV80)/tv80_reg.v

# ROM=boot: the 256 byte boot ROM of sim09 (loads the Level 2 loader from the SD image, LSN 2): make boot DISK=... SCRIPT=...
ROM ?= xltest
ifeq ($(ROM),aciirq)
B := build_aciirq
ROMBASE = 64512
ROMAW = 10
else ifeq ($(ROM),disktest)
B := build_disktest
ROMBASE = 64512
ROMAW = 10
else ifeq ($(ROM),boot)
B := build_boot
ROMBASE = 65280
ROMAW = 8
else
ROMBASE = 64512
ROMAW = 10
endif

# make ROM=aciirq TV80=...: the interrupt of the console ACIA (test/aciirq.asm)
ifeq ($(ROM),disktest)
run: $(B)/obj/Vsim_top $(B)/card.img
	$(B)/obj/Vsim_top -d $(B)/card.img -s ../test/disktest_wait.txt -c 900000000 | tee $(B)/out.txt
	@for t in "1 sync read: PASS" "2 async read, CPU runs: PASS" "3 CPU and DMA share the memory: PASS" "4 interrupt: PASS" "5 async write: PASS" DONE; do grep -q "$$t" $(B)/out.txt || { echo "matenro_soc disk port: FAILED ($$t)"; exit 1; }; done; echo "matenro_soc disk port: OK (5 tests)"
else ifeq ($(ROM),aciirq)
run: $(B)/obj/Vsim_top
	$(B)/obj/Vsim_top -nosd -c 40000000 | tee $(B)/out.txt
	@tr -d '\r\n' < $(B)/out.txt | grep -q "SBIRP" && echo "matenro_soc ACIA interrupt: OK (S B I R P)" || { echo "matenro_soc ACIA interrupt: FAILED"; exit 1; }
else
run: $(B)/obj/Vsim_top
	$(B)/obj/Vsim_top -nosd -c 40000000 | tee $(B)/out.txt
	@grep -q "13BA" $(B)/out.txt && grep -q "0037" $(B)/out.txt && grep -q "1D4C" $(B)/out.txt && echo "matenro_soc: OK (13BA 0037 1D4C)" || { echo "matenro_soc: FAILED"; exit 1; }
endif

ifeq ($(ROM),disktest)
# make ROM=disktest TV80=...: the disk port in its asynchronous mode (sim09's scripts/disktest.s, assembled with a09 without the long comments); the card: byte i of sector n is (n*37 + 3*i + 1) & $FF
$(B)/rom.hex: $(SIM09)/scripts/disktest.s
	@mkdir -p $(B)
	grep -v '^;' $(SIM09)/scripts/disktest.s | awk '{ if (length($$0)>100) sub(/[ \t]*;.*/,""); print }' > $(B)/disktest_a09.s
	cd $(B) && echo n | $(SIM09)/../../tools/a09 -o disktest.bin -l disktest.lst disktest_a09.s && grep -q '^0 Pass 2 errors' disktest.lst
	python3 $(SIM09)/scripts/bin2hex.py $(B)/disktest.bin > $@
$(B)/card.img:
	@mkdir -p $(B)
	python3 -c "open('$@','wb').write(b''.join(bytes((n*37+3*i+1)&255 for i in range(256)) for n in range(256)))"
else ifeq ($(ROM),aciirq)
$(B)/rom.hex: ../test/aciirq.asm
	@mkdir -p $(B)
	cd ../test && echo n | $(SIM09)/../../tools/a09 -o aciirq.bin -l aciirq.lst aciirq.asm
	python3 $(SIM09)/scripts/bin2hex.py ../test/aciirq.bin > $@
else ifeq ($(ROM),boot)
$(B)/rom.hex:
	@mkdir -p $(B)
	python3 $(SIM09)/scripts/bin2hex.py $(SIM09)/../../fuzix/images/bootrom.bin > $@
else
$(B)/rom.hex: ../test/xltest.asm ../../../os9/sub/sumz80.py
	@mkdir -p $(B)
	python3 -c "import sys; sys.path.insert(0,'../../../os9/sub'); import sumz80; i=sumz80.image(); open('../test/sumz80.inc','w').write(chr(10).join('         fcb   '+','.join('\$$%02X'%b for b in i[k:k+16]) for k in range(0,len(i),16))+chr(10))"
	cd ../test && echo n | $(SIM09)/../../tools/a09 -o xltest.bin -l xltest.lst xltest.asm
	python3 $(SIM09)/scripts/bin2hex.py ../test/xltest.bin > $@
endif

$(B)/obj/Vsim_top: $(RTL) $(B)/rom.hex $(SIM09)/sim/tb.cpp
	@test -f $(TV80)/tv80s.v || { echo "set TV80=<directory with tv80s.v ...>"; exit 1; }
	sh ../../sim/mk_tv80s_cen.sh $(TV80) $(B)/tv80s_cen.v
	verilator --cc --exe --build -O2 -j 8 -I$(SIM09)/rtl --top-module sim_top -Mdir $(B)/obj \
	  -Wno-fatal -Wno-lint -Wno-style -Wno-TIMESCALEMOD -Wno-UNOPTFLAT -Wno-CASEX -Wno-VARHIDDEN \
	  -GROM_BASE=$(ROMBASE) -GROM_AW=$(ROMAW) -GROM_FILE='"$(abspath $(B)/rom.hex)"' -GFREERUN=0 -GPH_DIV=9 -GMEMTEST=0 \
	  -CFLAGS "-O2" $(RTL) $(TV80V) $(SIM09)/sim/tb.cpp -o Vsim_top >/dev/null
boot: $(B)/obj/Vsim_top
	$(B)/obj/Vsim_top -d $(DISK) -s $(SCRIPT) -c $(CLKS)
.PHONY: run boot
