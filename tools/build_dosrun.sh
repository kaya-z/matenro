#!/bin/sh
# SPDX-License-Identifier: MIT
# The disk images for the run mode of the OS-9 command `dos` (`dos [-v=2] program arguments`, docs/MANUAL.md 6.8):
#   tools/build_dosrun.sh OUTDIR [DOSBIN [DOS2BIN]]
#     DOSBIN  = the output directory of tools/build_dosbin.sh  (MS-DOS 1.25: command.com)   -> OUTDIR/dosrun.img  (160 KB)
#     DOS2BIN = the output directory of tools/build_dosbin2.sh (MS-DOS 2.0: command.com)    -> OUTDIR/dosrun2.img (360 KB)
#   and OUTDIR/hostin.com, OUTDIR/hostout.com (the DOS side of the file transfer, os9/dos/host/, nasm)
set -e
ROOT=$(cd "$(dirname "$0")/.." && pwd)
OUT=${1:?output directory}
mkdir -p "$OUT"
for n in hostin hostout; do
    nasm -f bin "$ROOT/os9/dos/host/$n.asm" -I "$ROOT/os9/dos/host/" -o "$OUT/$n.com"
done
if [ -n "$2" ]; then
    python3 -I "$ROOT/tools/mkdosimg.py" "$OUT/dosrun.img" 160 "$2/command.com" "$OUT/hostin.com" "$OUT/hostout.com"
fi
if [ -n "$3" ]; then
    python3 -I "$ROOT/tools/mkdosimg.py" "$OUT/dosrun2.img" 360 "$3/command.com" "$OUT/hostin.com" "$OUT/hostout.com"
fi
ls -l "$OUT"
