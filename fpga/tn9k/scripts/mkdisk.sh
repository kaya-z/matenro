#!/bin/sh
# SPDX-License-Identifier: MIT
# Make the SD card image of the Matenro SoC: the Level 2 disk of sim09 (os9/OS9L2.dsk: the loader at LSN 2, the Level 2
# ROM image, the commands) plus the Matenro commands (cpm xrun reboot etime xlink x0 cpp cc80) in /d0/cmds and a CP/M test program
# (hello.com) in /d0.   fpga/tn9k/scripts/mkdisk.sh OUT.dsk
# The image is written to the card with:  sudo dd if=OUT.dsk of=/dev/sdX bs=512 conv=fsync   (the whole card is overwritten:
# check the device name; sim09 reads the card from block 0 as the disk /d0, see new-sbc09/docs/FPGA.md)
set -e
HERE=$(cd "$(dirname "$0")/.." && pwd)
ROOT=$(cd "$HERE/../.." && pwd)
SIM09=${SIM09:-/export/nas/archives/MC6809/new-sbc09}
OUT=${1:?output image}
T=$(mktemp -d)
"$ROOT/tools/build_cpm.sh" "$T/b" > /dev/null
mkdir -p "$T/v0"
cp -r "$SIM09/os9/level2/cmds" "$T/v0/cmds"      # the commands of the boot system (copy, attr, del) and ours in one directory
for n in cpm xrun reboot etime xlink x0 cpp cc80; do cp "$T/b/$n" "$T/v0/cmds/$n"; done
python3 "$ROOT/tools/z80asm.py" "$ROOT/tests/cpm/hello.asm" -o "$T/v0/hello.com" > /dev/null
cp "$SIM09/os9/OS9L2.dsk" "$OUT"
{
  echo 'timeout 3000000'; echo 'expect "OS9:"'; echo 'send "chx /v0/cmds\r"'; echo 'expect "OS9:"'
  for n in cpm xrun reboot etime xlink x0 cpp cc80; do
    echo "send \"del /d0/cmds/$n\\r\""; echo 'expect "OS9:"'
    echo "send \"copy /v0/cmds/$n /d0/cmds/$n\\r\""; echo 'expect "OS9:"'
    echo "send \"attr /d0/cmds/$n e pe r pr\\r\""; echo 'expect "OS9:"'
  done
  echo 'send "del /d0/hello.com\r"'; echo 'expect "OS9:"'
  echo 'send "copy /v0/hello.com /d0/hello.com\r"'; echo 'expect "OS9:"'
  echo 'send "free /d0\r"'; echo 'expect "OS9:"'; echo 'quit'
} > "$T/s.txt"
"$ROOT/matenro" -max -rom "$SIM09/os9/os9v2.rom" -0 "$OUT" -v "$T/v0" -script "$T/s.txt" 2>&1 | tr '\r' '\n' | grep -i "error\|free\|can't" || true
rm -rf "$T"
