#!/bin/sh
# SPDX-License-Identifier: MIT
# Build a bitstream of the Matenro SoC (6809 + Z80 and 8088, chosen with the OS-9 command subsel) for the Tang Nano 20K with the
# Gowin IDE (command line), up to the .fs file.  SUBS=8088 builds the 8088 alone (no Z80 core).
# Written to the board with:  openFPGALoader -m FILE  (SRAM; -f writes the flash)
#   fpga/tn20k/scripts/build.sh [xltest88|boot] [IDE_DIR]
#
# xltest88  the test ROM fpga/tn20k/test/xltest88.asm: the 6809 loads the self test of the 8088 (tests/i8088/core.asm) into the 8088 memory,
#           runs it and prints "A5 00 12D5" on the UART of the board (115200 baud, 8N1; the USB port), then switches itself off.
# boot      the 256 byte boot ROM of sim09 (at $FF00): it loads the Level 2 loader from the SD card (image: fpga/tn9k/scripts/mkdisk.sh)
# CLKMHZ=54|60|67.5  the system clock (PLL setting, PH_DIV of the 6809, the divider of the 8088); default 54. The microcode ROM of MCL86 (EU4Kx32 -> the
#           execution unit in one clock) is the longest path of the design: at 67.5 MHz the timing is not met (66.7 MHz), at 60 MHz by 0.6 MHz, at 54 MHz by 2.6 MHz
# MEMTEST=0  leave out the power-on memory test (it tests 2 MB of the SDRAM: "Matenro Memory >>>> OK 2048K" on the console); on by default
#
# The parts of sim09 that are not changed (UART, timer, SD disk, 6809 core) are read from SIM09 (default
# /export/nas/archives/MC6809/new-sbc09/fpga/tn9k), not copied.
set -e
HERE=$(cd "$(dirname "$0")/.." && pwd)
SIM09=${SIM09:-/export/nas/archives/MC6809/new-sbc09/fpga/tn9k}
ROM=${1:-xltest88}
IDE=${2:-${GOWIN_IDE:-/usr/local/IDE}}
case $ROM in
xltest88) BASE="16'hF000"; AW=12 ;;
boot)     BASE="16'hFF00"; AW=8 ;;
*) echo "unknown ROM $ROM"; exit 1 ;;
esac
case ${CLKMHZ:-54} in
67.5) CLK_HZ=67500000; PH=9; D88=14; DZ=9; IDIV=1; FBDIV=4;  ODIV=8;  MUL=5;  DIV=2 ;;
60)   CLK_HZ=60000000; PH=8; D88=12; DZ=8; IDIV=8; FBDIV=19; ODIV=16; MUL=20; DIV=9 ;;
54)   CLK_HZ=54000000; PH=7; D88=11; DZ=7; IDIV=0; FBDIV=1;  ODIV=16; MUL=2;  DIV=1 ;;
*) echo "CLKMHZ is 67.5, 60 or 54"; exit 1 ;;
esac
B=$HERE/build/$ROM${TAG}
mkdir -p "$B"
A09=${A09:-$SIM09/../../tools/a09}
if [ "$ROM" = xltest88 ]; then
    nasm -f bin -DHWPORTS "$HERE/../../tests/i8088/core.asm" -o "$B/core_hw.bin"
    python3 -c "b=open('$B/core_hw.bin','rb').read(); open('$HERE/test/core88.inc','w').write(chr(10).join('         fcb   '+','.join('\$%02X'%x for x in b[k:k+16]) for k in range(0,len(b),16))+chr(10))"
    # a09 exits with 0 even when it reports errors: look at its report
    A09OUT=$(cd "$HERE/test" && echo n | "$A09" -o xltest88.bin -l xltest88.lst xltest88.asm 2>&1)
    echo "$A09OUT"
    echo "$A09OUT" | grep -q '^0 Pass 2 errors' || { echo "ERROR: xltest88.asm does not assemble"; exit 1; }
    python3 "$SIM09/scripts/bin2hex.py" "$HERE/test/xltest88.bin" > "$B/rom.hex"
else
    python3 "$SIM09/scripts/bin2hex.py" "$SIM09/../../fuzix/images/bootrom.bin" > "$B/rom.hex"
fi
cp "$HERE/../vendor/mcl86/mcl86_ucode.hex" "$B/mcl86_ucode.hex"
TV80=${TV80:-$HERE/../../private/tv80src/rtl/core}
sh "$HERE/../sim/mk_tv80s_cen.sh" "$TV80" "$B/tv80s_cen.v"
set -- $(date +"%Y %m %d %H %M %S")
cat > "$B/tn20k_cfg.vh" <<EOT
\`define CLK_HZ $CLK_HZ
\`define PH_DIV $PH
\`define C88_DIV $D88
\`define CZ_DIV $DZ
\`define PLL_IDIV $IDIV
\`define PLL_FBDIV $FBDIV
\`define PLL_ODIV $ODIV
\`define ROM_BASE $BASE
\`define ROM_AW $AW
\`define FREERUN 0
\`define RTC_YEAR $(( $1 - 1900 ))
\`define RTC_MONTH $(echo $2 | sed 's/^0//')
\`define RTC_DAY $(echo $3 | sed 's/^0//')
\`define RTC_HOUR $(echo $4 | sed 's/^0//')
\`define RTC_MIN $(echo $5 | sed 's/^0//')
\`define RTC_SEC $(echo $6 | sed 's/^0//')
\`define MEMTEST_EN ${MEMTEST:-1}
$( [ "${SUBS:-both}" = 8088 ] && echo '`define SUB8088 1' || echo '`define SUBBOTH 1' )
\`define UCODE_FILE "$B/mcl86_ucode.hex"
EOT
HDMI=${HDMI:-1}
KANJI=${KANJI:-1}
[ "$HDMI" = 0 ] && KANJI=0
if [ "$HDMI" != 0 ]; then echo '`define HDMI 1' >> "$B/tn20k_cfg.vh"; cp "$SIM09/rtl/font8x16.hex" "$B/font8x16.hex"; fi
# KANJI=1 (default with HDMI): the screen of sim09 with the decoder and the kanji glyphs (the image: the OS-9 command kanjild); the register HCTL ($FFC8)
if [ "$KANJI" != 0 ]; then printf '`define KANJI 1\n`define HCTL 1\n`define HDMI_CHARSET %s\n' "${HDMI_CHARSET:-1}" >> "$B/tn20k_cfg.vh"; fi
cp "$HERE/constraints/tn20k.cst" "$B/pins.cst"
if [ "$HDMI" != 0 ]; then cat "$HERE/constraints/hdmi.cst" >> "$B/pins.cst"; fi
python3 - "$HERE/constraints/tn20k.sdc" "$B/timing.sdc" "$MUL" "$DIV" "$PH" "$CLK_HZ" <<'PYEOF'
import sys
src, dst, mul, div, ph, hz = sys.argv[1:7]
per = 4 * int(ph) * 1e9 / int(hz)               # one 6809 bus cycle in ns
s = open(src).read().replace("-multiply_by 5 -divide_by 2", "-multiply_by %s -divide_by %s" % (mul, div))
for k, v in (("@PER@", per), ("@HALF@", per / 2), ("@Q1@", per / 4), ("@Q3@", per * 3 / 4)):
    s = s.replace(k, "%.2f" % v)
open(dst, "w").write(s)
PYEOF
if [ "$HDMI" != 0 ]; then cat "$HERE/constraints/hdmi.sdc" >> "$B/timing.sdc"; fi
cat > "$B/build.tcl" <<EOT
set_device -name GW2AR-18C GW2AR-LV18QN88C8/I7
add_file -type verilog $HERE/rtl/tn20k_top.v
add_file -type verilog $HERE/rtl/tn20k_pll.v
$( [ "$HDMI" != 0 ] && { echo "add_file -type verilog $HERE/rtl/hdmi_phy20.v"; echo "add_file -type verilog $HERE/../rtl/hdmi_text20.v"; for f in hdmi_term hdmi_video tmds_enc; do echo "add_file -type verilog $SIM09/rtl/$f.v"; done; } )
$( [ "$KANJI" != 0 ] && for f in hdmi_text hdmi_decode hdmi_glyph psram_xfer; do echo "add_file -type verilog $SIM09/rtl/$f.v"; done )
add_file -type verilog $HERE/../rtl/sdram_ctl.v
add_file -type verilog $HERE/../tn9k/rtl/matenro_soc.v
add_file -type verilog $HERE/../tn9k/rtl/psram_arb4.v
add_file -type verilog $HERE/../tn9k/rtl/btn_toggle.v
add_file -type verilog $HERE/../rtl/shr_ap.v
add_file -type verilog $HERE/../rtl/i8088_sub.v
add_file -type verilog $HERE/../rtl/z80_sub.v
add_file -type verilog $B/tv80s_cen.v
add_file -type verilog $TV80/tv80_core.v
add_file -type verilog $TV80/tv80_mcode.v
add_file -type verilog $TV80/tv80_alu.v
add_file -type verilog $TV80/tv80_reg.v
add_file -type verilog $HERE/../rtl/xlink.v
add_file -type verilog $HERE/../rtl/eu4kx32.v
add_file -type verilog $HERE/../vendor/mcl86/eu.v
add_file -type verilog $HERE/../vendor/mcl86/biu_min.v
add_file -type verilog $SIM09/rtl/acia_uart.v
add_file -type verilog $SIM09/rtl/timer_rtc.v
add_file -type verilog $SIM09/rtl/sd_disk.v
add_file -type verilog $SIM09/vendor/mc6809/mc6809i.v
add_file -type cst $B/pins.cst
add_file -type sdc $B/timing.sdc
set_option -top_module tn20k_top
set_option -verilog_std sysv2017
set_option -include_path "$B;$SIM09/rtl"
set_option -output_base_name matenro20k_$ROM
set_option -use_sspi_as_gpio 1
set_option -use_mspi_as_gpio 1
set_option -use_ready_as_gpio 1
set_option -use_done_as_gpio 1
set_option -use_cpu_as_gpio 1
set_option -rw_check_on_ram 1
set_option -place_option ${PLACE:-1}
${RETIME:+set_option -retiming 1}
run all
exit
EOT
cd "$B"
env -u DISPLAY QT_QPA_PLATFORM=offscreen "$IDE/bin/gw_sh" build.tcl 2>&1 | tee build.log | grep -v "^qt\."
if grep -E "^ERROR" build.log; then echo "ERROR in the build (build.log): the bitstream is not new"; exit 1; fi
if grep -E "Undeclared symbol|does not have a driver" build.log; then echo "WARNING: see the lines above (build.log)"; fi
ls -l "$B"/impl/pnr/*.fs
