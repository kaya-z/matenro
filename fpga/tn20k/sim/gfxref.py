# SPDX-License-Identifier: MIT
"""gfxref.py - the drawing of os9/gfx/gfxlib.inc again, in Python, with the same rules, for the checks (check_gfxdraw.py, check_gdemo.py): the picture is
320 x 240 bytes (fb); what is outside is not drawn; a text cell that does not fit on the line is left out; the line is Bresenham."""
W, H = 320, 240
fb = bytearray(W * H)
font = []
def load_font(path):
    font[:] = [int(x, 16) for x in open(path).read().split()]
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
