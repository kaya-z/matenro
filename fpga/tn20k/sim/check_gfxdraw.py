#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""check_gfxdraw.py FBDUMP FONT: the picture after the commands of gfxdraw.txt (os9/gfx/gfx.asm: pix, line, rect, box, text), drawn here again with the same
rules (the picture is 320 x 240; what is outside is not drawn; a text cell that does not fit on the line is left out; the line is Bresenham)."""
import sys
W, H = 320, 240
fb = bytearray(W * H)
font = [int(x, 16) for x in open(sys.argv[2]).read().split()]
def plot(x, y, c):
    if 0 <= x < W and 0 <= y < H: fb[y * W + x] = c
def hline(x, y, n, c):
    if y >= H or x >= W: return
    n = min(n, W - x)
    for i in range(n): fb[y * W + x + i] = c
def vline(x, y, n, c):
    for i in range(n): plot(x, y + i, c)
def box(x, y, w, h, c):
    for r in range(h): hline(x, y + r, w, c)
def rect(x, y, w, h, c):
    hline(x, y, w, c); hline(x, y + h - 1, w, c); vline(x, y, h, c); vline(x + w - 1, y, h, c)
def line(x0, y0, x1, y1, c):
    dx = abs(x1 - x0); sx = 1 if x0 < x1 else -1
    dy = -abs(y1 - y0); sy = 1 if y0 < y1 else -1
    err = dx + dy
    while True:
        plot(x0, y0, c)
        if x0 == x1 and y0 == y1: break
        e2 = 2 * err
        if e2 >= dy: err += dy; x0 += sx
        if e2 <= dx: err += dx; y0 += sy
def text(x, y, fg, bg, s):
    for ch in s:
        o = ord(ch)
        if o < 32 or o > 126: o = 32
        if x > 312: break
        for r in range(16):
            if y + r >= H: continue
            for b in range(8):
                fb[(y + r) * W + x + b] = fg if (font[o * 16 + r] >> (7 - b)) & 1 else bg
        x += 8
# the commands of gfxdraw.txt, in the order
box(10, 10, 50, 30, 28)
rect(5, 5, 100, 60, 255)
line(0, 0, 319, 239, 7)
line(319, 0, 0, 239, 224)
line(100, 200, 150, 200, 3)
line(40, 100, 40, 150, 5)
plot(160, 120, 255)
plot(400, 10, 255)
text(8, 160, 255, 16, 'Hello Matenro 20K.')
text(290, 230, 255, 0, 'Clipped text')
box(300, 220, 40, 40, 12)
d = open(sys.argv[1], 'rb').read()
bad = sum(1 for a, b in zip(d, fb) if a != b) + abs(len(d) - len(fb))
print('gfx drawing (pix, line, rect, box, text): %d wrong bytes of %d' % (bad, len(fb)))
sys.exit(1 if bad else 0)
