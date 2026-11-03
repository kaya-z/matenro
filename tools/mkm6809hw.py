#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""Make src/m6809hw.h, the bus cycle patterns of the 6809 instructions, from the RTL trace.

  python3 tools/mkm6809hw.py fpga/tn9k/test/m6809_patterns.txt src/m6809hw.h

The input has one line per instruction as the RTL (Verilator, fpga/tn9k/sim) executed it while OS-9 ran `duo -1`:
  OPCODE:PATTERN COUNT        (OPCODE: two hex digits, with the second byte for the prefixes 10 and 11)
The letters of the pattern are the bus cycles in the order of the instruction: F fetch of the opcode (a RAM read),
r a read, w a write, d no access (VMA = 0), i an I/O read, j an I/O write.
The output is a table sorted by (opcode, number of cycles) with the most frequent pattern of each.
"""
import collections
import re
import sys

best = collections.defaultdict(dict)
for line in open(sys.argv[1]):
    m = re.match(r'(\w+):(\w+) (\d+)', line)
    if not m:
        continue
    op, pat, n = m.group(1), m.group(2), int(m.group(3))
    if len(pat) > 24 or len(op) not in (2, 4):                     # not an instruction: the reset, the lines before LIC
        continue
    key = int(op, 16) if len(op) == 2 else int(op, 16)
    best[(key, len(pat))][pat] = best[(key, len(pat))].get(pat, 0) + n
rows = []
for (key, ln), pats in sorted(best.items()):
    pat = max(pats.items(), key=lambda kv: kv[1])[0]
    rows.append((key, ln, pat))
out = ['/* SPDX-License-Identifier: MIT */',
       '/* m6809hw.h - the bus cycles of the instructions of the 6809, from the RTL (tools/mkm6809hw.py, fpga/tn9k/test/m6809_patterns.txt) */',
       'static const struct { uint16_t op; uint8_t n; const char *pat; } m6809_pat[] = {']
for key, ln, pat in rows:
    out.append('    { 0x%04X, %d, "%s" },' % (key, ln, pat))
out.append('};')
out.append('#define M6809_NPAT (sizeof m6809_pat / sizeof m6809_pat[0])')
open(sys.argv[2], 'w').write('\n'.join(out) + '\n')
print(len(rows), 'patterns')
