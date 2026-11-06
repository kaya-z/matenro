#!/bin/sh
# SPDX-License-Identifier: MIT
# MS-DOS 2.0 for the OS-9 command `dos -v=2`: the BIOS (os9/dos/bios2.asm) with SYSINIT of Microsoft in one flat binary
# (UASM, a MASM compatible assembler), and the kernel and COMMAND as Microsoft published them (github.com/microsoft/MS-DOS,
# MIT license; the source is not part of this repository):
#   MSDOS2_SRC=<.../MS-DOS/v2.0/source> UASM=<uasm> tools/build_dosbin2.sh OUTDIR
#       -> OUTDIR/bios2.bin, OUTDIR/msdos.sys, OUTDIR/command.com   (the last two are the published ../bin/MSDOS.SYS and COMMAND.COM)
# The source is not changed: tools/dos/patch_sysinit.py writes a copy with the changes for UASM (docs/DESIGN.md 18.8).
set -e
ROOT=$(cd "$(dirname "$0")/.." && pwd)
SRC=${MSDOS2_SRC:?set MSDOS2_SRC to the directory with SYSINIT.ASM (MS-DOS/v2.0/source)}
UASM=${UASM:-uasm}
OUT=${1:?output directory}
mkdir -p "$OUT"
OUT=$(cd "$OUT" && pwd)
BIN="$SRC/../bin"
T=$(mktemp -d)
python3 -I "$ROOT/tools/dos/patch_sysinit.py" "$SRC" "$T"
cp "$ROOT/os9/dos/bios2.asm" "$T/"
(cd "$T" && "$UASM" -nologo -bin -Fo "$OUT/bios2.bin" bios2.asm) | sed 's/\x1b\[[0-9;]*m//g'
cp "$BIN/MSDOS.SYS" "$OUT/msdos.sys"
cp "$BIN/COMMAND.COM" "$OUT/command.com"
rm -rf "$T"
ls -l "$OUT/bios2.bin" "$OUT/msdos.sys" "$OUT/command.com"
