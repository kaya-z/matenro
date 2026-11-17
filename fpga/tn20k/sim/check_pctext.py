#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""check_pctext.py PPM FONT: the HDMI text screen that shows the text memory of the IBM PC (hdmi_pctext.v): 80 x 25 cells {character, attribute} that
`check_pctext.py --make FILE` writes for the SDRAM model ($1B8000), the colours of the PC (bit 0 blue, 1 green, 2 red, 3 intensity) turned into the
terminal's (ANSI) order, the background bright with the blink bit.  The cursor (row 3, column 5) blinks and is not compared.
`--make FILE`: the 32 bit words of the 2,000 cells."""
import sys
def cell(i):
    return (32 + (i * 7) % 95) | (((i * 13 + 5) & 0xFF) << 8)
if sys.argv[1] == '--make':
    w = []
    for k in range(1000):
        w.append(cell(2 * k) | (cell(2 * k + 1) << 16))
    open(sys.argv[2], 'w').write('\n'.join('%08x' % x for x in w) + '\n')
    sys.exit(0)
ANSI = [0, 4, 2, 6, 1, 5, 3, 7]
def pal(k):
    on, off = (0xff, 0x55) if k & 8 else (0xaa, 0x00)
    return ((on if k & 1 else off), (on if k & 2 else off), (on if k & 4 else off))
d = open(sys.argv[1], 'rb').read()
parts = d.split(None, 4)
w, h = int(parts[1]), int(parts[2])
px = parts[4][-w * h * 3:]
font = [int(v, 16) for v in open(sys.argv[2]).read().split()]
Y0 = (480 - 16 * 25) // 2
bad = 0
first = None
for row in range(25):
    for col in range(80):
        if (row, col) == (3, 5): continue
        c = cell(row * 80 + col)
        ch, at = c & 0xFF, c >> 8
        fg = pal(((at >> 3) & 1) << 3 | ANSI[at & 7])
        bg = pal(((at >> 7) & 1) << 3 | ANSI[(at >> 4) & 7])
        for y in range(16):
            for x in range(8):
                want = fg if (font[ch * 16 + y] >> (7 - x)) & 1 else bg
                o = ((Y0 + row * 16 + y) * w + col * 8 + x) * 3
                got = tuple(px[o:o + 3])
                if got != want:
                    bad += 1
                    if first is None: first = (row, col, y, x, got, want)
print('pc text: %d wrong pixels of %d%s' % (bad, 80 * 25 * 128, '' if first is None else ' (the first: %s)' % (first,)))
sys.exit(1 if bad else 0)
