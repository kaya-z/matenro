#!/bin/sh
# SPDX-License-Identifier: MIT
# Assemble the OS-9 command `cpm` (and the shims it embeds).
#   tools/build_cpm.sh OUTDIR          -> OUTDIR/cpm, OUTDIR/xrun, OUTDIR/reboot, OUTDIR/etime, OUTDIR/bdos, OUTDIR/bdostest (a sample program that calls it), OUTDIR/cpp, OUTDIR/cc80, OUTDIR/xlink (driver), OUTDIR/x0 (descriptor)
# Needs a09 (A09=...), the NitrOS-9 definition files (OS9DIR=.../os9, used read only), nasm and python3.
set -e
ROOT=$(cd "$(dirname "$0")/.." && pwd)
OUT=${1:?output directory}
A09=${A09:-/export/nas/archives/MC6809/new-sbc09/tools/a09}
OS9DIR=${OS9DIR:-/export/nas/archives/MC6809/new-sbc09/os9}
mkdir -p "$OUT"
OUT=$(cd "$OUT" && pwd)
PYTHONUTF8=1 python3 "$ROOT/os9/cpm/mkshims.py" "$OUT/shims.inc"
cd "$ROOT/os9"
# a09 asks "Continue?" after errors and waits for a key: answer no
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$OUT/" -I "$ROOT/os9/cpm/" -l "$OUT/cpm.lst" -o "$OUT/cpm" cpm/cpm.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/xrun.lst" -o "$OUT/xrun" xrun.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$ROOT/os9/cpm/" -I "$ROOT/os9/bdos/" -l "$OUT/bdos.lst" -o "$OUT/bdos" bdos/bdos.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$ROOT/os9/bdos/" -l "$OUT/bdostest.lst" -o "$OUT/bdostest" ../tests/bdos/bdostest.asm
# the work area of the bdos module (the size of the data area) must fit in BDOSSZ (bdos/bdos.d)
SZ=$(grep -E "^[0-9A-F]{4}: +size +equ" "$OUT/bdos.lst" | head -1 | cut -c1-4)
BS=$(sed -n 's/^BDOSSZ *equ *\([0-9]*\).*/\1/p' bdos/bdos.d)
[ "$((0x$SZ))" -le "$BS" ] || { echo "bdos: the data area ($((0x$SZ)) bytes) is bigger than BDOSSZ ($BS)"; exit 1; }
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/reboot.lst" -o "$OUT/reboot" reboot/reboot.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/etime.lst" -o "$OUT/etime" etime/etime.asm
cd "$ROOT/os9"
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/cpp.lst" -o "$OUT/cpp" cpp/cpp.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/cc80.lst" -o "$OUT/cc80" cc80/cc80.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/xlink.lst" -o "$OUT/xlink" xlink/xlink.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/x0.lst" -o "$OUT/x0" xlink/x0.asm
