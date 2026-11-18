#!/bin/sh
# SPDX-License-Identifier: MIT
# Start Matenro with OS-9 Level 2 and a CP/M test program ready to run with `cpm`.
#   tools/try_cpm.sh [z80|8088] [extra options of matenro, e.g. -script file]
# Work directory: $WORK (default /tmp/matenro_try).  The disk images are copied, the originals stay untouched.
# Host files you put into $WORK/v0 appear as /v0 in OS-9 (CP/M programs: *.com for the Z80, *.cmd for the 8088).
set -e
ROOT=$(cd "$(dirname "$0")/.." && pwd)
SBC=${SBC:-/export/nas/archives/MC6809/new-sbc09/os9}
WORK=${WORK:-/tmp/matenro_try}
CPU=${1:-z80}
[ $# -gt 0 ] && shift
make -C "$ROOT" all os9cmds >/dev/null
mkdir -p "$WORK/v0"
[ -f "$WORK/OS9.dsk" ] || cp "$SBC/OS9.dsk" "$SBC/WORK.dsk" "$WORK/"
rm -rf "$WORK/v0/cmds"
cp -r "$SBC/level2/cmds" "$WORK/v0/cmds"
cp "$ROOT"/build/os9/cpm "$ROOT"/build/os9/cpp80 "$ROOT"/build/os9/cc80 "$ROOT"/build/os9/xrun "$WORK/v0/cmds/"
cp "$ROOT"/build/os9/duo "$WORK/v0/cmds/"
if [ "$CPU" = z80 ]; then
    for n in hello fileio line tcat tcount twrite; do
        python3 "$ROOT/tools/z80asm.py" "$ROOT/tests/cpm/$n.asm" -o "$WORK/v0/$n.com"
    done
else
    for n in hello86 fileio86 line86; do
        nasm -f bin "$ROOT/tests/cpm/$n.asm" -o "$WORK/$n.bin"
        python3 "$ROOT/tools/mkcmd.py" 8080 "$WORK/$n.bin" "$WORK/v0/$n.cmd"
    done
fi
echo "(Mandelbrot on both CPUs: duo, duo -1, duo -z, duo -n)"
echo "OS-9 starts.  Type:  chx /v0/cmds   then   chd /v0   then   cpm hello.com abc   (exit: Ctrl-] then q)"
exec "$ROOT/matenro" -m 1M -sub "$CPU" -rom "$SBC/os9v2.rom" -0 "$WORK/OS9.dsk" -1 "$WORK/WORK.dsk" -v "$WORK/v0" "$@"
