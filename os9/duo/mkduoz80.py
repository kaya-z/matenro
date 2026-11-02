#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""Assemble the Z80 worker of `duo` and write it as a09 `fcb` data (included by duo.asm).

  python3 os9/duo/mkduoz80.py OUT.inc
"""
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', '..', 'tools'))
import z80asm


def main():
    base, data = z80asm.assemble(open(os.path.join(HERE, 'duoz80.asm'), encoding='utf-8').read())
    assert base == 0, hex(base)
    lines = ['duoz80   equ *']
    for i in range(0, len(data), 16):
        lines.append('         fcb ' + ','.join('$%02X' % b for b in data[i:i + 16]))
    lines.append('duoz80n  equ *-duoz80')
    open(sys.argv[1], 'w').write('\n'.join(lines) + '\n')


if __name__ == '__main__':
    main()
