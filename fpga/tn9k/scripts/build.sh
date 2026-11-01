#!/bin/sh
# SPDX-License-Identifier: MIT
# Build a bitstream of the Matenro SoC for the Tang Nano 9K with the Gowin IDE (command line), without HDMI.
#   TV80=<dir with tv80s.v ...> fpga/tn9k/scripts/build.sh [xltest] [IDE_DIR]
#
# xltest  the test ROM fpga/tn9k/test/xltest.asm: the 6809 loads the Z80 demo into the Z80 memory, runs it and prints
#         "13BA" and "0037" on the UART of the board (115200 baud, 8N1; the USB port), then switches itself off.
# boot    the 256 byte boot ROM of sim09 (at $FF00): it loads the Level 2 loader from the SD card (image: scripts/mkdisk.sh)
# MEMTEST=0  leave out the power-on memory test of the PSRAM (it takes about 4.5 s: "Memory >>>> OK 2048K" on the console); on by default
# Result: fpga/tn9k/build/xltest/impl/pnr/matenro_xltest.fs   (program it with: openFPGALoader -b tangnano9k FILE)
#
# The parts of sim09 that are not changed (UART, timer, SD disk, PSRAM controller, 6809 core, PLL, pins and timing
# constraints) are read from SIM09 (default /export/nas/archives/MC6809/new-sbc09/fpga/tn9k), not copied.
set -e
HERE=$(cd "$(dirname "$0")/.." && pwd)
SIM09=${SIM09:-/export/nas/archives/MC6809/new-sbc09/fpga/tn9k}
TV80=${TV80:?set TV80 to the directory with tv80s.v tv80_core.v tv80_mcode.v tv80_alu.v tv80_reg.v}
ROM=${1:-xltest}
IDE=${2:-${GOWIN_IDE:-/usr/local/IDE}}
case $ROM in
xltest) BASE="16'hFC00"; AW=10 ;;
boot)   BASE="16'hFF00"; AW=8 ;;
*) echo "unknown ROM $ROM"; exit 1 ;;
esac
B=$HERE/build/$ROM${TAG}
mkdir -p "$B"
A09=${A09:-$SIM09/../../tools/a09}
python3 -c "import sys; sys.path.insert(0,'$HERE/../../os9/sub'); import sumz80; i=sumz80.image(); open('$HERE/test/sumz80.inc','w').write(chr(10).join('         fcb   '+','.join('\$%02X'%b for b in i[k:k+16]) for k in range(0,len(i),16))+chr(10))"
[ "$ROM" = boot ] || (cd "$HERE/test" && echo n | "$A09" -o xltest.bin -l xltest.lst xltest.asm)
if [ "$ROM" = boot ]; then
    python3 "$SIM09/scripts/bin2hex.py" "$SIM09/../../fuzix/images/bootrom.bin" > "$B/rom.hex"
else
    python3 "$SIM09/scripts/bin2hex.py" "$HERE/test/xltest.bin" > "$B/rom.hex"
fi
sh "$HERE/../sim/mk_tv80s_cen.sh" "$TV80" "$B/tv80s_cen.v"
set -- $(date +"%Y %m %d %H %M %S")
cat > "$B/tn9k_cfg.vh" <<EOT
\`define CLK_HZ ${CLK_HZ:-67500000}
\`define PH_DIV 9
\`define ROM_BASE $BASE
\`define ROM_AW $AW
\`define FREERUN 0
\`define RTC_YEAR $(( $1 - 1900 ))
\`define RTC_MONTH $(echo $2 | sed 's/^0//')
\`define RTC_DAY $(echo $3 | sed 's/^0//')
\`define RTC_HOUR $(echo $4 | sed 's/^0//')
\`define RTC_MIN $(echo $5 | sed 's/^0//')
\`define RTC_SEC $(echo $6 | sed 's/^0//')
\`define HDMI_ROWS 25
\`define HDMI_CHARSET 0
\`define MEMTEST_EN ${MEMTEST:-1}
$( [ -n "$WDOG" ] && echo "\`define WATCHDOG 1" )
EOT
cat "$SIM09/constraints/tn9k.cst" > "$B/pins.cst"
cat "$SIM09/constraints/tn9k.sdc" "$HERE/constraints/matenro.sdc" > "$B/timing.sdc"
# SDC_SED="s/-multiply_by 5 -divide_by 2/-multiply_by 3 -divide_by 1/": constrain the system clock harder (81 MHz) to see how fast the design really can go
# (the PLL is not changed: such a bitstream is for the timing report only)
[ -z "$SDC_SED" ] || sed -i "$SDC_SED" "$B/timing.sdc"
cat > "$B/build.tcl" <<EOT
set_device -name GW1NR-9C GW1NR-LV9QN88PC6/I5
add_file -type verilog $HERE/rtl/tn9k_top.v
add_file -type verilog ${PLL:-$SIM09/rtl/tn9k_pll.v}
add_file -type verilog $HERE/rtl/matenro_soc.v
add_file -type verilog $HERE/rtl/psram_arb4.v
add_file -type verilog $HERE/../rtl/z80_sub.v
add_file -type verilog $HERE/../rtl/xlink.v
add_file -type verilog $B/tv80s_cen.v
add_file -type verilog $TV80/tv80_core.v
add_file -type verilog $TV80/tv80_mcode.v
add_file -type verilog $TV80/tv80_alu.v
add_file -type verilog $TV80/tv80_reg.v
add_file -type verilog $SIM09/rtl/acia_uart.v
add_file -type verilog $SIM09/rtl/timer_rtc.v
add_file -type verilog $SIM09/rtl/sd_disk.v
add_file -type verilog $SIM09/rtl/dbg_uart.v
add_file -type verilog $HERE/rtl/dbg_uart_z.v
add_file -type verilog $SIM09/vendor/mc6809/mc6809i.v
add_file -type verilog $SIM09/vendor/psram/psram_controller.v
add_file -type cst $B/pins.cst
add_file -type sdc $B/timing.sdc
set_option -top_module tn9k_top
set_option -verilog_std sysv2017
set_option -include_path "$B;$SIM09/rtl"
set_option -output_base_name matenro_$ROM
set_option -use_sspi_as_gpio 1
set_option -use_mspi_as_gpio 1
set_option -use_ready_as_gpio 1
set_option -use_done_as_gpio 1
set_option -use_cpu_as_gpio 1
set_option -rw_check_on_ram 1
set_option -place_option ${PLACE:-1}
run all
exit
EOT
cd "$B"
env -u DISPLAY QT_QPA_PLATFORM=offscreen "$IDE/bin/gw_sh" build.tcl 2>&1 | tee build.log | grep -v "^qt\."
if grep -E "^ERROR" build.log; then echo "ERROR in the build (build.log): the bitstream is not new"; exit 1; fi
if grep -E "Undeclared symbol|does not have a driver" build.log | grep -v "O_psram_ck_n\|psram_controller"; then echo "WARNING: see the lines above (build.log)"; fi
ls -l "$B"/impl/pnr/*.fs
