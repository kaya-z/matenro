#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""check_gdemo.py FBDUMP FONT TEXT: the picture of gdemo.com / gdemo86.cmd (tests/cpm: BDOS 112): fill, box, frame, two lines, a point, the text TEXT."""
import sys
from gfxref import *
load_font(sys.argv[2])
fb[:] = bytes(W * H)
box(10, 10, 50, 30, 28)
rect(5, 5, 100, 60, 255)
line(0, 0, 319, 239, 7)
line(319, 0, 0, 239, 224)
plot(160, 120, 255)
text(8, 160, 255, 16, sys.argv[3])
d = open(sys.argv[1], 'rb').read()
bad = sum(1 for a, b in zip(d, fb) if a != b) + abs(len(d) - len(fb))
print('%s: %d wrong bytes of %d' % (sys.argv[3], bad, len(fb)))
sys.exit(1 if bad else 0)
