#!/bin/sh
# SPDX-License-Identifier: MIT
# Assemble the OS-9 command `cpm` (and the shims it embeds).
#   tools/build_cpm.sh OUTDIR          -> OUTDIR/cpm, OUTDIR/xrun, OUTDIR/reboot, OUTDIR/etime, OUTDIR/subsel, OUTDIR/kanjild, OUTDIR/gfx, OUTDIR/duo (Mandelbrot on both CPUs), OUTDIR/bdos, OUTDIR/bdostest (a sample program that calls it), OUTDIR/cpp80, OUTDIR/cc80, OUTDIR/xlink (driver), OUTDIR/x0 (descriptor), OUTDIR/dos (MS-DOS on the 8088)
# Needs a09 (A09=...), the NitrOS-9 definition files (OS9DIR=.../os9, used read only), nasm and python3.
set -e
ROOT=$(cd "$(dirname "$0")/.." && pwd)
OUT=${1:?output directory}
A09=${A09:-$ROOT/../sim09/tools/a09}
OS9DIR=${OS9DIR:-$ROOT/../sim09/os9}
mkdir -p "$OUT"
OUT=$(cd "$OUT" && pwd)
PYTHONUTF8=1 python3 "$ROOT/os9/cpm/mkshims.py" "$OUT/shims.inc"
python3 "$ROOT/os9/gfx/mkfont.py" "$OS9DIR/../fpga/tn9k/rtl/font8x16.hex" "$OUT/gfxfont.inc"
cd "$ROOT/os9"
# a09 asks "Continue?" after errors and waits for a key: answer no
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$OUT/" -I "$ROOT/os9/cpm/" -I "$ROOT/os9/gfx/" -l "$OUT/cpm.lst" -o "$OUT/cpm" cpm/cpm.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/xrun.lst" -o "$OUT/xrun" xrun.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$ROOT/os9/cpm/" -I "$ROOT/os9/bdos/" -l "$OUT/bdos.lst" -o "$OUT/bdos" bdos/bdos.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$ROOT/os9/bdos/" -l "$OUT/bdostest.lst" -o "$OUT/bdostest" ../tests/bdos/bdostest.asm
# the work area of the bdos module (the size of the data area) must fit in BDOSSZ (bdos/bdos.d)
SZ=$(grep -E "^[0-9A-F]{4}: +size +equ" "$OUT/bdos.lst" | head -1 | cut -c1-4)
BS=$(sed -n 's/^BDOSSZ *equ *\([0-9]*\).*/\1/p' bdos/bdos.d)
[ "$((0x$SZ))" -le "$BS" ] || { echo "bdos: the data area ($((0x$SZ)) bytes) is bigger than BDOSSZ ($BS)"; exit 1; }
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/reboot.lst" -o "$OUT/reboot" reboot/reboot.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/etime.lst" -o "$OUT/etime" etime/etime.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/subsel.lst" -o "$OUT/subsel" subsel/subsel.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/kanjild.lst" -o "$OUT/kanjild" kanjild/kanjild.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$OUT/" -l "$OUT/gfx.lst" -o "$OUT/gfx" gfx/gfx.asm
python3 "$ROOT/os9/duo/mkduoz80.py" "$OUT/duoz80.inc"
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$OUT/" -l "$OUT/duo.lst" -o "$OUT/duo" duo/duo.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$OUT/" -I "$ROOT/os9/gfx/" -l "$OUT/mand09.lst" -o "$OUT/mand09" demo/mand09.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$OUT/" -I "$ROOT/os9/gfx/" -l "$OUT/ball09.lst" -o "$OUT/ball09" demo/ball09.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$OUT/" -I "$ROOT/os9/gfx/" -l "$OUT/cube09.lst" -o "$OUT/cube09" demo/cube09.asm
cd "$ROOT/os9"
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/cpp80.lst" -o "$OUT/cpp80" cpp/cpp.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/cc80.lst" -o "$OUT/cc80" cc80/cc80.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/xlink.lst" -o "$OUT/xlink" xlink/xlink.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/x0.lst" -o "$OUT/x0" xlink/x0.asm
PYTHONUTF8=1 python3 "$ROOT/os9/dos/mkbios.py" "$OUT/bios.inc"
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$OUT/" -I "$ROOT/os9/cpm/" -I "$ROOT/os9/gfx/" -l "$OUT/dos.lst" -o "$OUT/dos" dos/dos.asm
