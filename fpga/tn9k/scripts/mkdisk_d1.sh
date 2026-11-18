#!/bin/sh
# SPDX-License-Identifier: MIT
# Make the second disk (/d1) of the SD card: the HI-TECH C compiler (for `cc80`), ZEXDOC / ZEXALL and two C sources, and
# the whole card image (drive 0 from mkdisk.sh at byte 0, drive 1 at 128 MB: sd_disk.v, DRIVE1_BLK).
#   HTC=<dir with P1.COM CGEN.COM ZAS.COM LINQ.COM CRTCPM.OBJ LIBC.LIB LIBF.LIB *.H> ZEX=<dir with zexdoc.com zexall.com> \
#     fpga/tn9k/scripts/mkdisk_d1.sh D0.dsk D1.dsk CARD.img
# D0.dsk is the output of mkdisk.sh.  D1.dsk (D1SECTORS=262144 sectors = 64 MB by default, tools/mkrbf.py) is made here,
# CARD.img (about 192 MB, mostly empty) is both of them in place: write it with dd to the whole card.
# TP=<dir with TURBO.COM TURBO.MSG TURBO.OVR> (Turbo Pascal 3.0 for CP/M-80, optional): /d1/tp, with hello.pas in /d1; run it with
#   chd /d1 ; cpm -p=/d1/tp /d1/tp/turbo.com   (TURBO.COM is installed for the ANSI terminal here: see below)
# HI-TECH C, ZEXDOC, ZEXALL and Turbo Pascal are not part of this repository (their own licenses: LICENSE files go with them).
set -e
HERE=$(cd "$(dirname "$0")/.." && pwd)
ROOT=$(cd "$HERE/../.." && pwd)
SIM09=${SIM09:-$ROOT/../sim09}
HTC=${HTC:?set HTC}
ZEX=${ZEX:?set ZEX}
D0=${1:?D0.dsk}; D1=${2:?D1.dsk}; CARD=${3:?CARD.img}
T=$(mktemp -d)
mkdir -p "$T/v0/htc"
cp -r "$SIM09/os9/level2/cmds" "$T/v0/cmds"
for n in P1.COM CGEN.COM ZAS.COM LINQ.COM CRTCPM.OBJ LIBC.LIB LIBF.LIB LICENSE; do cp "$HTC/$n" "$T/v0/htc/"; done
cp "$HTC"/*.H "$T/v0/htc/"
cp "$ZEX/zexdoc.com" "$ZEX/zexall.com" "$T/v0/"
cp "$ZEX/LICENSE" "$T/v0/ZEX_LICENSE"
# zexdoc8.com / zexall8.com: the same programs, but the table of the tests starts at the 8th test (aluop a,(<ix,iy>+1)): to repeat
# the place where ZEXDOC stopped on the board without the 2.5 hours before it (tools/zexfrom.py)
python3 "$ROOT/tools/zexfrom.py" 8 "$ZEX/zexdoc.com" "$T/v0/zexdoc8.com"
python3 "$ROOT/tools/zexfrom.py" 8 "$ZEX/zexall.com" "$T/v0/zexall8.com"
# bstress.com: the stress test of the link (tests/cpm/bstress.asm)
python3 "$ROOT/tools/z80asm.py" "$ROOT/tests/cpm/bstress.asm" -o "$T/v0/bstress.com" > /dev/null
cp "$ROOT/tests/cpp/demo.c" "$T/v0/demo.c"
cp "$ROOT/tests/cpp/mandel.c" "$T/v0/mandel.c"      # floating point (cc80 links libf.lib)
TPFILES=
if [ -n "${TP:-}" ]; then
  mkdir -p "$T/v0/tp"
  for n in TURBO.COM TURBO.MSG TURBO.OVR TINST.COM TINST.DTA TINST.MSG; do cp "$TP/$n" "$T/v0/tp/"; done
  cp "$ROOT/tests/cpm/hello.pas" "$T/v0/hello.pas"
  # install TURBO.COM for an ANSI terminal (TINST: screen installation, 6 = ANSI, no changes, 8 MHz) in the simulator
  printf 'timeout 8000000\nexpect "OS9:"\nsend "chx /d0/cmds\\r"\nexpect "OS9:"\nsend "chd /v0/tp\\r"\nexpect "OS9:"\nsend "cpm tinst.com\\r"\nexpect "[Q]uit"\nsend "s"\nexpect "exit):"\nsend "6\\r"\nexpect "(Y/N)?"\nsend "n"\nexpect "Change to:"\nsend "8\\r"\nexpect "[Q]uit"\nsleep 1000000\nsend "q"\nsleep 2000000\nquit\n' > "$T/tinst.txt"
  cp "$D0" "$T/d0tmp.dsk"
  "$ROOT/matenro" -max -m 1M -sub z80 -rom "$SIM09/os9/os9v2.rom" -0 "$T/d0tmp.dsk" -v "$T/v0" -script "$T/tinst.txt" > /dev/null 2>&1 || true
  cmp -s "$TP/TURBO.COM" "$T/v0/tp/TURBO.COM" && { echo "TINST did not change TURBO.COM"; exit 1; }
  rm -f "$T/v0/tp/TINST.COM" "$T/v0/tp/TINST.DTA" "$T/v0/tp/TINST.MSG"      # (the card has no room for them)
  TPFILES="hello.pas"
fi
printf '#include <stdio.h>\n\nmain()\n{\n\tprintf("Hello from Hi-Tech C on CP/M\\n");\n\treturn 0;\n}\n' > "$T/v0/hello.c"
cp "$D0" "$T/d0.dsk"
# drive 1 is a hard disk: an empty volume of D1SECTORS sectors (default 262144 = 64 MB, 1 sector per cluster; the allocation map
# fills 128 sectors: tools/mkrbf.py), the files are copied in below
python3 "$ROOT/tools/mkrbf.py" "$D1" "${D1SECTORS:-262144}" 1 d1 > /dev/null
{
  echo 'timeout 6000000'; echo 'expect "OS9:"'; echo 'send "chx /v0/cmds\r"'; echo 'expect "OS9:"'
  echo 'send "makdir /d1/htc\r"'; echo 'expect "OS9:"'
  # attr -s: a file with the "s" attribute (single user) can be open once; the HI-TECH linker opens its library twice
  for f in $(cd "$T/v0/htc" && ls); do echo "send \"copy /v0/htc/$f /d1/htc/$f\\r\""; echo 'expect "OS9:"'; echo "send \"attr /d1/htc/$f -s\\r\""; echo 'expect "OS9:"'; done
  if [ -n "$TPFILES" ]; then
    echo 'send "makdir /d1/tp\r"'; echo 'expect "OS9:"'
    for f in $(cd "$T/v0/tp" && ls); do echo "send \"copy /v0/tp/$f /d1/tp/$f\\r\""; echo 'expect "OS9:"'; echo "send \"attr /d1/tp/$f -s\\r\""; echo 'expect "OS9:"'; done
  fi
  for f in zexdoc.com zexall.com zexdoc8.com zexall8.com bstress.com ZEX_LICENSE demo.c mandel.c hello.c $TPFILES; do echo "send \"copy /v0/$f /d1/$f\\r\""; echo 'expect "OS9:"'; echo "send \"attr /d1/$f -s\\r\""; echo 'expect "OS9:"'; done
  echo 'send "dir /d1\r"'; echo 'expect "OS9:"'; echo 'send "free /d1\r"'; echo 'expect "OS9:"'; echo 'quit'
} > "$T/s.txt"
"$ROOT/matenro" -max -rom "$SIM09/os9/os9v2.rom" -0 "$T/d0.dsk" -1 "$D1" -v "$T/v0" -script "$T/s.txt" 2>&1 | tr '\r' '\n' | grep -i "error\|free\|can't\|zex\|hello.c" || true
python3 - "$D0" "$D1" "$CARD" <<'PY'
import sys
d0 = open(sys.argv[1], 'rb').read(); d1 = open(sys.argv[2], 'rb').read()
off = 0x040000 * 512
with open(sys.argv[3], 'wb') as f:
    f.write(d0); f.seek(off); f.write(d1)
print('%s: %d bytes (drive 0: %d, drive 1 at %d: %d)' % (sys.argv[3], off + len(d1), len(d0), off, len(d1)))
PY
rm -rf "$T"
