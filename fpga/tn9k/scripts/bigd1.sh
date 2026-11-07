#!/bin/sh
# SPDX-License-Identifier: MIT
# Make /d1 of the SD card bigger: the files (and their attributes) of an old /d1 image go into a new, empty RBF volume
# (tools/mkrbf.py) of D1SECTORS sectors (default 262144 = 64 MB, 1 sector per cluster), and with CARD=<file> the whole card image.
#   [D1SECTORS=262144] [CARD=card.img D0=d0.dsk] fpga/tn9k/scripts/bigd1.sh OLD_D1.dsk NEW_D1.dsk
# The files are copied by the simulator (the host directory /v0 is the way between two volumes of OS-9: only two drives).
# HI-TECH C, ZEXDOC and Turbo Pascal are not part of this repository: the old /d1 image (fpga/tn9k/scripts/mkdisk_d1.sh)
# has them; with the sources, mkdisk_d1.sh makes the big volume directly.
set -e
HERE=$(cd "$(dirname "$0")/.." && pwd)
ROOT=$(cd "$HERE/../.." && pwd)
SIM09=${SIM09:-/export/nas/archives/MC6809/new-sbc09}
OLD=${1:?old /d1 image}; NEW=${2:?new /d1 image}
D0=${D0:-}
T=$(mktemp -d)
BOOT=$T/boot.dsk
if [ -n "$D0" ]; then cp "$D0" "$BOOT"; else cp "$SIM09/os9/OS9L2.dsk" "$BOOT"; fi
mkdir -p "$T/v0/x"
python3 - "$ROOT" "$OLD" "$T" <<'PY'
import sys
sys.path.insert(0, sys.argv[1] + '/tools')
import os
import rbfwalk
root, old, t = sys.argv[1:4]
tree = rbfwalk.walk(old)
a = ['timeout 20000000', 'expect "OS9:"', 'send "chx /d0/cmds\\r"', 'expect "OS9:"']
b = list(a)
for p, isdir, size, att in tree:
    if isdir:
        os.makedirs('%s/v0/x/%s' % (t, p), exist_ok=True)
        b += ['send "makdir /d1/%s\\r"' % p, 'expect "OS9:"']
for p, isdir, size, att in tree:
    if not isdir:
        a += ['send "copy /d1/%s /v0/x/%s\\r"' % (p, p), 'expect "OS9:"']
        flags = ' '.join(n if att & bit else '-' + n for bit, n in ((0x40, 's'), (0x20, 'pe'), (0x10, 'pw'), (0x08, 'pr'), (0x04, 'e'), (0x02, 'w'), (0x01, 'r')))
        b += ['send "copy /v0/x/%s /d1/%s\\r"' % (p, p), 'expect "OS9:"', 'send "attr /d1/%s %s\\r"' % (p, flags), 'expect "OS9:"']
tail = ['send "echo FIN\\r"', 'expect "FIN"', 'quit']
open(t + '/a.txt', 'w').write('\n'.join(a + tail) + '\n')
open(t + '/b.txt', 'w').write('\n'.join(b + ['send "free /d1\\r"', 'expect "OS9:"'] + tail) + '\n')
PY
cp "$OLD" "$T/old.dsk"
"$ROOT/matenro" -max -rom "$SIM09/os9/os9v2.rom" -0 "$BOOT" -1 "$T/old.dsk" -v "$T/v0" -script "$T/a.txt" > /dev/null 2>&1
python3 "$ROOT/tools/mkrbf.py" "$NEW" "${D1SECTORS:-262144}" 1 d1
"$ROOT/matenro" -max -rom "$SIM09/os9/os9v2.rom" -0 "$BOOT" -1 "$NEW" -v "$T/v0" -script "$T/b.txt" 2>&1 | tr '\r' '\n' | grep -i "error\|free sectors\|can't" || true
if [ -n "${CARD:-}" ]; then
  [ -n "$D0" ] || { echo "CARD needs D0=<drive 0 image>"; exit 1; }
  python3 - "$D0" "$NEW" "$CARD" <<'PY'
import sys
d0 = open(sys.argv[1], 'rb').read(); d1 = open(sys.argv[2], 'rb').read()
off = 0x040000 * 512
with open(sys.argv[3], 'wb') as f:
    f.write(d0); f.seek(off); f.write(d1)
print('%s: %d bytes (drive 0: %d, drive 1 at %d: %d)' % (sys.argv[3], off + len(d1), len(d0), off, len(d1)))
PY
fi
rm -rf "$T"
