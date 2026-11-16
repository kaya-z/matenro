#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""check_gdirect.py FBDUMP: the picture of gdirect.com (tests/cpm): the first 16384 bytes are the gradient (i AND 255) the Z80 stored itself, the rest is 0."""
import sys
d = open(sys.argv[1], 'rb').read()
want = bytes(i & 255 for i in range(16384)) + bytes(320 * 240 - 16384)
bad = sum(1 for a, b in zip(d, want) if a != b) + abs(len(d) - len(want))
print('gdirect: %d wrong bytes of %d' % (bad, len(want)))
sys.exit(1 if bad else 0)
