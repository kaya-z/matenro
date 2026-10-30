#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""mkcmd - wrap flat binaries into a CP/M-86 .CMD file (128 byte header with group descriptors).

  python3 tools/mkcmd.py 8080 prog.bin prog.cmd          8080 model: one code group, loaded at CS:0100 (assemble with org 0x100;
                                                          nasm -f bin writes the bytes from 0x100 on)
  python3 tools/mkcmd.py small code.bin data.bin out.cmd  small model: code group at CS:0000 (org 0), data group at DS:0100 (org 0x100)

Header layout (CP/M-86 System Guide): eight group descriptors of 9 bytes: form (1 code, 2 data, ...), length in
paragraphs (word), absolute base (word), minimum size in paragraphs (word), maximum size in paragraphs (word).
The groups follow the header in the file, each padded to a multiple of 16 bytes.
"""
import struct
import sys


def paras(n):
    return (n + 15) // 16


def pad16(b):
    return b + bytes(-len(b) % 16)


def descriptor(form, data, minimum=None, maximum=0x1000):
    p = paras(len(data))
    return struct.pack('<BHHHH', form, p, 0, minimum if minimum is not None else p, maximum)


def main(a):
    if len(a) >= 4 and a[1] == '8080':
        code = open(a[2], 'rb').read()
        hdr = descriptor(1, code)
        out = a[3]
        body = pad16(code)
    elif len(a) >= 5 and a[1] == 'small':
        code, data = open(a[2], 'rb').read(), open(a[3], 'rb').read()
        hdr = descriptor(1, code) + descriptor(2, data, maximum=0x1000)
        out = a[4]
        body = pad16(code) + pad16(data)
    else:
        print(__doc__)
        return 2
    open(out, 'wb').write(hdr.ljust(128, b'\0') + body)
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
