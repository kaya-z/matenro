#!/bin/sh
# SPDX-License-Identifier: MIT
# The SD card image of the Tang Nano 20K (6809 + 8088): the /d0 of the 9K card (fpga/tn9k/scripts/mkdisk.sh: OS-9 Level 2 and the
# Matenro commands) plus the command dos, CP/M-86 test programs (hello86.cmd fileio86.cmd line86.cmd), the 8088 demo sum8088.bin
# and the directory /d0/dos for MS-DOS 2.0 (msdos.sys bios2.bin dosrun2.img tbasic.com):  cd /d0/dos; dos -v=2 -a=dosrun2.img tbasic
#   MSDOS2_SRC=<.../MS-DOS/v2.0/source> UASM=<uasm> fpga/tn20k/scripts/mkdisk.sh OUT_D0.dsk [BASE_CARD.img OUT_CARD.img]
# With BASE_CARD (a card image of the 9K: fpga/tn9k/build/matenro_card_async.img) the first megabyte (/d0) is replaced and the
# result is written to OUT_CARD:  sudo dd if=OUT_CARD of=/dev/sdX bs=1M conv=fsync   (the whole card is overwritten)
set -e
HERE=$(cd "$(dirname "$0")/.." && pwd)
ROOT=$(cd "$HERE/../.." && pwd)
SIM09=${SIM09:-/export/nas/archives/MC6809/new-sbc09}
OUT=${1:?output /d0 image}
T=$(mktemp -d)
"$ROOT/tools/build_cpm.sh" "$T/b" > /dev/null
MSDOS2_SRC=${MSDOS2_SRC:?} UASM=${UASM:?} sh "$ROOT/tools/build_dosbin2.sh" "$T/d2" > /dev/null
sh "$ROOT/tools/build_dosrun.sh" "$T/dr" "" "$T/d2" > /dev/null
mkdir -p "$T/v0/dos"
cp -r "$SIM09/os9/level2/cmds" "$T/v0/cmds"
CMDS="cpm xrun reboot etime duo bdos bdostest xlink x0 cpp80 cc80 dos subsel"
for n in $CMDS; do cp "$T/b/$n" "$T/v0/cmds/$n"; done
python3 "$ROOT/tools/z80asm.py" "$ROOT/tests/cpm/hello.asm" -o "$T/v0/hello.com" > /dev/null
for n in hello86 fileio86 line86; do
  nasm -f bin "$ROOT/tests/cpm/$n.asm" -o "$T/$n.bin"
  python3 "$ROOT/tools/mkcmd.py" 8080 "$T/$n.bin" "$T/v0/$n.cmd"
done
nasm -f bin "$ROOT/os9/sub/sum8088.asm" -o "$T/v0/sum8088.bin"
nasm -f bin "$ROOT/tests/dos/tbasic.asm" -o "$T/v0/dos/tbasic.com"
cp "$T/d2/msdos.sys" "$T/d2/bios2.bin" "$T/dr/dosrun2.img" "$T/v0/dos/"
cp "$SIM09/os9/OS9L2.dsk" "$OUT"
{
  echo 'timeout 30000000'; echo 'expect "OS9:"'; echo 'send "chx /v0/cmds\r"'; echo 'expect "OS9:"'
  for n in $CMDS; do
    echo "send \"del /d0/cmds/$n\\r\""; echo 'expect "OS9:"'
    echo "send \"copy /v0/cmds/$n /d0/cmds/$n\\r\""; echo 'expect "OS9:"'
    echo "send \"attr /d0/cmds/$n e pe r pr\\r\""; echo 'expect "OS9:"'
  done
  for f in hello.com hello86.cmd fileio86.cmd line86.cmd sum8088.bin; do
    echo "send \"del /d0/$f\\r\""; echo 'expect "OS9:"'
    echo "send \"copy /v0/$f /d0/$f\\r\""; echo 'expect "OS9:"'
  done
  echo 'send "makdir /d0/dos\r"'; echo 'expect "OS9:"'
  for f in msdos.sys bios2.bin tbasic.com dosrun2.img; do
    echo "send \"copy /v0/dos/$f /d0/dos/$f\\r\""; echo 'expect "OS9:"'
  done
  echo 'send "free /d0\r"'; echo 'expect "OS9:"'; echo 'quit'
} > "$T/s.txt"
"$ROOT/matenro" -max -rom "$SIM09/os9/os9v2.rom" -0 "$OUT" -v "$T/v0" -script "$T/s.txt" 2>&1 | tr '\r' '\n' | grep -i "error\|free\|can't" || true
rm -rf "$T"
if [ -n "$2" ]; then
  cp "$2" "$3"
  dd if="$OUT" of="$3" bs=1M count=1 conv=notrunc status=none
  ls -l "$3"
fi
