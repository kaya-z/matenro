#!/bin/sh
# SPDX-License-Identifier: MIT
# Assemble the OS-9 command `cpm` (and the shims it embeds).
#   tools/build_cpm.sh OUTDIR          -> OUTDIR/cpm, OUTDIR/xrun, OUTDIR/reboot, OUTDIR/cpp, OUTDIR/cc80, OUTDIR/xlink (driver), OUTDIR/x0 (descriptor)
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
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -I "$OUT/" -l "$OUT/cpm.lst" -o "$OUT/cpm" cpm/cpm.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/xrun.lst" -o "$OUT/xrun" xrun.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/reboot.lst" -o "$OUT/reboot" reboot/reboot.asm
cd "$ROOT/os9"
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/cpp.lst" -o "$OUT/cpp" cpp/cpp.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/cc80.lst" -o "$OUT/cc80" cc80/cc80.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/xlink.lst" -o "$OUT/xlink" xlink/xlink.asm
echo n | "$A09" -I "$OS9DIR/nitros9-code/defs/" -l "$OUT/x0.lst" -o "$OUT/x0" xlink/x0.asm
