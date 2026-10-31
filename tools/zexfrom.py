#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""zexfrom - make a ZEXDOC / ZEXALL (Frank D. Cringle, Cringle's zexall test suite; its own license) that starts at the Nth test.

  python3 tools/zexfrom.py N zexdoc.com out.com

The program has a table of 67 pointers to the descriptions of the tests (at 013Ah in the .COM, 0 ends the table).  The new
file has only the tests N .. N (the table is  [N-th pointer, 0]), so that the one test runs alone.  Used to repeat a place
where the whole run stopped on the board.  (The table position is checked: 67 ascending pointers and the 0.)
"""
import struct
import sys

n, src, dst = int(sys.argv[1]), sys.argv[2], sys.argv[3]
d = bytearray(open(src, 'rb').read())
off = 0x13A - 0x100
w = struct.unpack_from('<68H', d, off)
assert w[67] == 0 and all(w[i] < w[i + 1] for i in range(66)), 'this is not ZEXDOC / ZEXALL (test table not found)'
assert 1 <= n <= 67
struct.pack_into('<2H', d, off, w[n - 1], 0)
open(dst, 'wb').write(d)
print('%s: test %d only (descriptor at %04Xh)' % (dst, n, w[n - 1]))
