#!/bin/sh
# SPDX-License-Identifier: MIT
# Assemble the MS-DOS 1.25 kernel and COMMAND from the source that Microsoft published (github.com/microsoft/MS-DOS, MIT
# license; the source is not part of this repository) with UASM (a MASM compatible assembler):
#   MSDOS_SRC=<.../MS-DOS/v1.25/source> UASM=<uasm> tools/build_dosbin.sh OUTDIR     -> OUTDIR/msdos.sys, OUTDIR/command.com
# The source is not changed: tools/dos/patch_*.py write a copy with the changes for UASM (docs/DESIGN.md chapter 18).
set -e
ROOT=$(cd "$(dirname "$0")/.." && pwd)
SRC=${MSDOS_SRC:?set MSDOS_SRC to the directory with MSDOS.ASM COMMAND.ASM STDDOS.ASM}
UASM=${UASM:-uasm}
OUT=${1:?output directory}
mkdir -p "$OUT"
OUT=$(cd "$OUT" && pwd)
T=$(mktemp -d)
python3 -I "$ROOT/tools/dos/patch_msdos.py" "$SRC" "$T"
python3 -I "$ROOT/tools/dos/patch_command.py" "$SRC" "$T"
(printf '\t.8086\n\tOPTION\tOLDSTRUCTS\n'; cat "$SRC/STDDOS.ASM") > "$T/STDDOS.ASM"
(printf '\t.8086\n\tOPTION\tOLDSTRUCTS\n'; cat "$T/COMMAND.ASM") > "$T/CMD2.ASM"
(cd "$T" && "$UASM" -nologo -bin -Fo "$OUT/msdos.sys" STDDOS.ASM && "$UASM" -nologo -bin -Fo "$T/command.bin" CMD2.ASM) | sed 's/\x1b\[[0-9;]*m//g'
# the first 256 bytes of the image are the 100H of the program segment (ORG 100H of the source): not part of the .COM file
tail -c +257 "$T/command.bin" > "$OUT/command.com"
rm -rf "$T"
ls -l "$OUT/msdos.sys" "$OUT/command.com"
