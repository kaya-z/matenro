#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""check_hdmi.py PPM FONT: the picture of the HDMI text screen against the 8x16 font: the cells of the first line
('Hello, Matenro!'), the colours of the second line (Red, Green, Blue) and the third line ('OS9:')."""
import sys
def ppm(p):
    d = open(p, 'rb').read()
    parts = d.split(None, 4)
    w, h = int(parts[1]), int(parts[2])
    return w, h, parts[4][-w * h * 3:]
def main():
    w, h, px = ppm(sys.argv[1])
    font = [int(x, 16) for x in open(sys.argv[2]).read().split()]
    Y0 = (480 - 16 * 25) // 2
    bad = 0
    def cell(row, col):
        return [[tuple(px[((Y0 + row * 16 + y) * w + col * 8 + x) * 3:((Y0 + row * 16 + y) * w + col * 8 + x) * 3 + 3]) for x in range(8)] for y in range(16)]
    def check(row, col, ch, fg):
        nonlocal bad
        c = cell(row, col)
        for y in range(16):
            for x in range(8):
                on = (font[ch * 16 + y] >> (7 - x)) & 1
                want = fg if on else (0, 0, 0)
                got = c[y][x]
                # the cursor (inverted cell) is where the text ends: not tested there
                if got != want:
                    bad += 1
    for i, ch in enumerate('Hello, Matenro!'):
        check(0, i, ord(ch), (170, 170, 170))
    for i, ch in enumerate('Red'):
        check(1, i, ord(ch), (170, 0, 0))
    for i, ch in enumerate(' Green'):
        check(1, 3 + i, ord(ch), (0, 170, 0))
    for i, ch in enumerate(' Blue'):
        check(1, 9 + i, ord(ch), (0, 0, 170))
    for i, ch in enumerate('OS9:'):
        check(2, i, ord(ch), (170, 170, 170))
    print('hdmi_text20: %d wrong pixels (cells: 15 + 3 + 6 + 5 + 4 characters)' % bad)
    sys.exit(1 if bad else 0)
main()
