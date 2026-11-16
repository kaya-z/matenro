# SPDX-License-Identifier: MIT
# 摩天楼 (Matenro) simulator - MC6809 (OS-9 Level 2) + pluggable Z80 / 8088 sub CPU, CP/M-80 and CP/M-86 under OS-9
# Debian 12: gcc, make, python3 (tests), nasm (8088 test programs; prebuilt binaries are in tests/bin)
CC      ?= gcc
CFLAGS  ?= -O2 -g -Wall -Wextra -Wno-unused-parameter
SRC      = src/m6809.c src/machine.c src/console.c src/net.c src/vdisk.c src/dbg.c src/dis6809.c \
           src/xlink.c src/z80.c src/i8088.c src/memtest.c src/main.c
OBJ      = $(SRC:.c=.o)

all: matenro

matenro: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

src/%.o: src/%.c src/*.h
	$(CC) $(CFLAGS) -c -o $@ $<

tests/z80_test: tests/z80_test.c src/z80.c src/subcpu.h
	$(CC) $(CFLAGS) -o $@ tests/z80_test.c src/z80.c

test-z80: tests/z80_test
	tests/z80_test

tests/i8088/core.bin: tests/i8088/core.asm
	nasm -f bin tests/i8088/core.asm -o $@

tests/i8088_test: tests/i8088_test.c src/i8088.c src/subcpu.h
	$(CC) $(CFLAGS) -o $@ tests/i8088_test.c src/i8088.c

test-8088: tests/i8088/core.bin tests/i8088_test
	tests/i8088_test

test-mh: all
	python3 tests/matenro_test.py

test-asm:
	PYTHONUTF8=1 python3 tests/z80asm_test.py

os9cmds: all
	tools/build_cpm.sh build/os9

test: all test-asm test-z80 test-8088 test-mh

clean:
	rm -f src/*.o matenro tests/z80_test tests/i8088_test

.PHONY: all clean test test-asm test-z80 test-8088 test-mh os9cmds test-fpga test-tn20k

# RTL tests (Verilator): XLINK; with TV80=<dir with tv80s.v ...> also the Z80 SoC and the whole Matenro SoC
# Tang Nano 20K machine (6809 + 8088 / MCL86 + SDRAM): the 8088 self test on rtl/i8088_soc.v, the SDRAM controller against its model, and the
# whole SoC (6809 test ROM that runs the 8088 self test).  Needs verilator, nasm and a09.
test-tn20k:
	make -C fpga/sim i8088
	make -C fpga/tn20k/sim sdram
	make -C fpga/tn20k/sim soc PH=7 D88=11 HZ=54000000
	make -C fpga/tn20k/sim hdmi
	make -C fpga/tn20k/sim hdmik
	make -C fpga/tn20k/sim hdmig
	make -C fpga/tn20k/sim fbsoc FBFIX=1 PH=7 D88=11 HZ=54000000 | grep -q FBALIVE
	make -C fpga/tn20k/sim gfxboot PH=7 D88=11 HZ=54000000
	make -C fpga/tn20k/sim gfxdraw PH=7 D88=11 HZ=54000000
	make -C fpga/tn20k/sim gfxsub PH=7 D88=11 HZ=54000000 CZ=7

test-fpga:
	make -C fpga/sim
	@if [ -n "$(TV80)" ]; then make -C fpga/sim soc TV80=$(TV80) && make -C fpga/tn9k/sim TV80=$(TV80); else echo "set TV80=<directory> for the Z80 tests"; fi
