#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""check_fb.py PPM FONT: the frame buffer picture of the HDMI screen: 320 x 240 pixels of the test pattern (make hdmig), doubled to 640 x 480, the
default palette (rrrgggbb) and the entry 7 = (255, 0, 255); the text over it (gfx_ov): the character 'x' in the first cell of the text (white where the
dots of the font are, the picture elsewhere); the cell of the cursor (the next one) is not compared (it blinks)."""
import sys
def pattern(x, y):
    if x < 8 and y < 8: return 7
    return ((x * 3 + y * 5) ^ (x >> 3)) & 0xFF
def pal(i):
    if i == 7: return (255, 0, 255)
    r, g, b = i >> 5, (i >> 2) & 7, i & 3
    return ((r << 5) | (r << 2) | (r >> 1), (g << 5) | (g << 2) | (g >> 1), (b << 6) | (b << 4) | (b << 2) | b)
d = open(sys.argv[1], 'rb').read()
parts = d.split(None, 4)
w, h = int(parts[1]), int(parts[2])
px = parts[4][-w * h * 3:]
font = [int(v, 16) for v in open(sys.argv[2]).read().split()]
Y0 = (480 - 16 * 25) // 2
bad = 0
first = None
for Y in range(480):
    for X in range(640):
        o = (Y * w + X) * 3
        want = pal(pattern(X // 2, Y // 2))
        if Y0 <= Y < Y0 + 16:                      # the first row of the text: the cell 0 shows 'x' over the picture, the cell 1 is the cursor
            if X < 8 and (font[ord('x') * 16 + (Y - Y0)] >> (7 - X)) & 1: want = (170, 170, 170)
            elif 8 <= X < 16: continue
        if tuple(px[o:o + 3]) != want:
            bad += 1
            if first is None: first = (X, Y, tuple(px[o:o + 3]), want)
print('frame buffer: %d wrong pixels of %d%s' % (bad, 640 * 480, '' if first is None else ' (the first: %s)' % (first,)))
sys.exit(1 if bad else 0)
