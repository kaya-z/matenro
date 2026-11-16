#!/bin/sh
# SPDX-License-Identifier: MIT
# The SD card image of the Tang Nano 20K (6809 + 8088): the /d0 of the 9K card (fpga/tn9k/scripts/mkdisk.sh: OS-9 Level 2 and the
# Matenro commands) plus the command dos, CP/M-86 test programs (hello86.cmd fileio86.cmd line86.cmd), the 8088 demo sum8088.bin
# and the directory /d0/dos for MS-DOS 2.0 (msdos.sys bios2.bin dosrun2.img tbasic.com):  cd /d0/dos; dos -v=2 -a=dosrun2.img tbasic
#   MSDOS2_SRC=<.../MS-DOS/v2.0/source> UASM=<uasm> fpga/tn20k/scripts/mkdisk.sh OUT_D0.dsk [BASE_CARD.img OUT_CARD.img]
# With BASE_CARD (a card image of the 9K: fpga/tn9k/build/matenro_card_async.img) the first megabyte (/d0) is replaced, the kanji image
# (KANJI_BIN, default sim09's fpga/tn9k/images/kanji.bin) goes to /d1/kanji.bin, and the
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
CMDS="cpm xrun reboot etime duo bdos bdostest xlink x0 cpp80 cc80 dos subsel kanjild gfx"
for n in $CMDS; do cp "$T/b/$n" "$T/v0/cmds/$n"; done
python3 "$ROOT/tools/z80asm.py" "$ROOT/tests/cpm/hello.asm" -o "$T/v0/hello.com" > /dev/null
for n in hello86 fileio86 line86; do
  nasm -f bin "$ROOT/tests/cpm/$n.asm" -o "$T/$n.bin"
  python3 "$ROOT/tools/mkcmd.py" 8080 "$T/$n.bin" "$T/v0/$n.cmd"
done
nasm -f bin "$ROOT/os9/sub/sum8088.asm" -o "$T/v0/sum8088.bin"
python3 "$ROOT/tools/z80asm.py" "$ROOT/tests/cpm/gdemo.asm" -o "$T/v0/gdemo.com" > /dev/null
python3 "$ROOT/tools/z80asm.py" "$ROOT/tests/cpm/gdirect.asm" -o "$T/v0/gdirect.com" > /dev/null
nasm -f bin "$ROOT/tests/cpm/gdirect86.asm" -o "$T/gdirect86.bin"
python3 "$ROOT/tools/mkcmd.py" 8080 "$T/gdirect86.bin" "$T/v0/gdirect86.cmd"
nasm -f bin "$ROOT/tests/cpm/gdemo86.asm" -o "$T/gdemo86.bin"
python3 "$ROOT/tools/mkcmd.py" 8080 "$T/gdemo86.bin" "$T/v0/gdemo86.cmd"
nasm -f bin "$ROOT/tests/dos/tbasic.asm" -o "$T/v0/dos/tbasic.com"
nasm -f bin "$ROOT/tests/dos/gdemo.asm" -o "$T/v0/dos/gdemo.com"
nasm -f bin "$ROOT/tests/dos/gdirect.asm" -o "$T/v0/dos/gdirect.com"
cp "$T/d2/msdos.sys" "$T/d2/bios2.bin" "$T/dr/dosrun2.img" "$T/v0/dos/"
cp "$SIM09/os9/OS9L2.dsk" "$OUT"
# the boot message says "Tang Nano 9K": the name is in the INIT module of the ROM image of the Level 2 machine (LSN 1100, 112 sectors of the
# disk).  Make that module again from init.asm of sim09 (only the name changed: a copy in the work directory, sim09 stays as it is), make the ROM
# image again with the modules that sim09 has built (make9rom), and put it in place.
mkdir -p "$T/rom"
sed 's/Tang Nano 9K/Tang Nano 20K/' "$SIM09/os9/level2/init.asm" > "$T/rom/init.asm"
( cd "$T/rom" && "$SIM09/tools/a09" -I "$SIM09/os9/nitros9-code/defs/" -I "$SIM09/os9/level2/" -D TN9K init.asm -o init_tn20k 2>&1 | grep -q '^0 Pass 2 errors' )
( cd "$SIM09/os9" && ../tools/make9rom -o "$T/rom/os9v2_tn20k.rom" -2 level2/shell level2/dir level2/d1 level2/ioman level2/os9p3_perr \
    level2/os9p4_regdump level2/pipe level2/piper level2/pipeman level2/v0 level2/vrbf level2/scf level2/rbf level2/os9p2 level2/sysgo_tn9k \
    level2/clock level2/pdisk level2/d0 level2/pty level2/term "$T/rom/init_tn20k" level2/boot level2/npty level2/n1 level2/n2 level2/n3 \
    level2/os9p1 > /dev/null )
[ "$(stat -c %s "$T/rom/os9v2_tn20k.rom")" -le 28672 ]
dd if="$T/rom/os9v2_tn20k.rom" of="$OUT" bs=256 seek=1100 conv=notrunc status=none
{
  echo 'timeout 30000000'; echo 'expect "OS9:"'; echo 'send "chx /v0/cmds\r"'; echo 'expect "OS9:"'
  for n in $CMDS; do
    echo "send \"del /d0/cmds/$n\\r\""; echo 'expect "OS9:"'
    echo "send \"copy /v0/cmds/$n /d0/cmds/$n\\r\""; echo 'expect "OS9:"'
    echo "send \"attr /d0/cmds/$n e pe r pr\\r\""; echo 'expect "OS9:"'
  done
  for f in hello.com hello86.cmd fileio86.cmd line86.cmd sum8088.bin gdemo.com gdemo86.cmd gdirect.com gdirect86.cmd; do
    echo "send \"del /d0/$f\\r\""; echo 'expect "OS9:"'
    echo "send \"copy /v0/$f /d0/$f\\r\""; echo 'expect "OS9:"'
  done
  echo 'send "makdir /d0/dos\r"'; echo 'expect "OS9:"'
  for f in msdos.sys bios2.bin tbasic.com gdemo.com gdirect.com dosrun2.img; do
    echo "send \"copy /v0/dos/$f /d0/dos/$f\\r\""; echo 'expect "OS9:"'
  done
  echo 'send "free /d0\r"'; echo 'expect "OS9:"'; echo 'quit'
} > "$T/s.txt"
"$ROOT/matenro" -max -rom "$SIM09/os9/os9v2.rom" -0 "$OUT" -v "$T/v0" -script "$T/s.txt" 2>&1 | tr '\r' '\n' | grep -i "error\|free\|can't" || true
rm -rf "$T"
if [ -n "$2" ]; then
  cp "$2" "$3"
  dd if="$OUT" of="$3" bs=1M count=1 conv=notrunc status=none
  # the kanji image of the HDMI screen goes to /d1 (the OS-9 command kanjild loads it): /d1 of the card starts at 128 MB (64 MB)
  KJ=${KANJI_BIN:-$SIM09/fpga/tn9k/images/kanji.bin}
  # the SKK dictionary of jwp (/d1/skk.dic, UTF-8) is made from SKK-JISYO.L (apt install skkdic)
  SKKJISYO=${SKKJISYO:-/usr/share/skk/SKK-JISYO.L}
  if [ -f "$KJ" ]; then
    T=$(mktemp -d)
    mkdir -p "$T/v0"
    cp "$KJ" "$T/v0/kanji.bin"
    CPSKK=
    if [ -f "$SKKJISYO" ]; then
      python3 "$SIM09/tools/mkskkdic.py" -e utf8 -o "$T/v0/skk.dic" "$SKKJISYO" > /dev/null && CPSKK='send "copy /v0/skk.dic /d1/skk.dic\\r"\nexpect "OS9:"\n'
    fi
    dd if="$3" of="$T/d1.dsk" bs=1M skip=128 count=64 status=none
    printf 'timeout 60000000\nexpect "OS9:"\nsend "chx /d0/cmds\\r"\nexpect "OS9:"\nsend "copy /v0/kanji.bin /d1/kanji.bin\\r"\nexpect "OS9:"\n%bsend "dir /d1\\r"\nexpect "OS9:"\nquit\n' "$CPSKK" > "$T/s.txt"
    "$ROOT/matenro" -max -rom "$SIM09/os9/os9v2.rom" -0 "$OUT" -1 "$T/d1.dsk" -v "$T/v0" -script "$T/s.txt" 2>&1 | tr '\r' '\n' | grep -i "kanji\|skk\|error" || true
    dd if="$T/d1.dsk" of="$3" bs=1M seek=128 conv=notrunc status=none
    rm -rf "$T"
  fi
  ls -l "$3"
fi
