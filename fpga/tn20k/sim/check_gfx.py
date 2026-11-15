#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""check_gfx.py FBDUMP: the 76,800 bytes at $300000 of the SDRAM after `gfx test` (os9/gfx/gfx.asm): rrr ggg bb with the red band every 40
columns, the green band every 30 rows and the blue (x + y) mod 4."""
import sys
d = open(sys.argv[1], 'rb').read()
exp = bytes(((x // 40) << 5) | ((y // 30) << 2) | ((x + y) & 3) for y in range(240) for x in range(320))
bad = sum(1 for a, b in zip(d, exp) if a != b) + abs(len(d) - len(exp))
print('gfx test picture: %d wrong bytes of %d' % (bad, len(exp)))
sys.exit(1 if bad else 0)
