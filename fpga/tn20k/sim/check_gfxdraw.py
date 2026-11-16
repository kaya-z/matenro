#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""check_gfxdraw.py FBDUMP FONT: the picture after the commands of gfxdraw.txt (os9/gfx/gfx.asm: pix, line, rect, box, text), drawn here again (gfxref.py)."""
import sys
from gfxref import *
load_font(sys.argv[2])
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
