#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""check_kanji.py PPM KANJI_BIN FONT: the lines of the picture (UTF-8 text: ASCII and kanji) against the 8x16 font and the 16x16 glyphs of
the kanji image (layout: sim09 rtl/kanji.vh: directory of pages at +$100, pages at +$300, glyphs at +$10000)."""
import struct, sys
def ppm(p):
    d = open(p, 'rb').read()
    parts = d.split(None, 4)
    w, h = int(parts[1]), int(parts[2])
    return w, h, parts[4][-w * h * 3:]
def main():
    w, h, px = ppm(sys.argv[1])
    kj = open(sys.argv[2], 'rb').read()
    font = [int(x, 16) for x in open(sys.argv[3]).read().split()]
    def glyph(u):
        page = struct.unpack_from('<H', kj, 0x100 + 2 * (u >> 8))[0]
        if page == 0xFFFF: return None
        g = struct.unpack_from('<H', kj, 0x300 + 512 * page + 2 * (u & 255))[0]
        return None if g == 0xFFFF else g
    Y0 = (480 - 16 * 25) // 2
    bad = 0
    fg, bg = (170, 170, 170), (0, 0, 0)
    def px_at(x, y):
        o = (y * w + x) * 3
        return tuple(px[o:o + 3])
    def check_row(row, text):
        nonlocal bad
        col = 0
        for ch in text:
            u = ord(ch)
            if u < 0x80:
                for y in range(16):
                    for x in range(8):
                        on = (font[u * 16 + y] >> (7 - x)) & 1
                        if px_at(col * 8 + x, Y0 + row * 16 + y) != (fg if on else bg): bad += 1
                col += 1
            else:
                g = glyph(u)
                assert g is not None, hex(u)
                for y in range(16):
                    l, r = kj[0x10000 + 32 * g + 2 * y], kj[0x10000 + 32 * g + 2 * y + 1]
                    for x in range(16):
                        on = ((l if x < 8 else r) >> (7 - (x & 7))) & 1
                        if px_at(col * 8 + x, Y0 + row * 16 + y) != (fg if on else bg): bad += 1
                col += 2
    check_row(0, 'ASCII 日本語 abc')
    check_row(1, 'ひらがな カタカナ 漢字')
    print('hdmi kanji: %d wrong pixels' % bad)
    sys.exit(1 if bad else 0)
main()
