#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""Copy SYSINIT.ASM, SYSIMES.ASM and what they include from the published MS-DOS 2.0 source with the changes that UASM needs
(docs/DESIGN.md 18.8).  The source is not changed.

  python3 -I tools/dos/patch_sysinit.py SRC OUT       SRC = .../MS-DOS/v2.0/source
"""
import os
import sys


def rd(p):
    return open(p, 'rb').read().decode('latin1')


def wr(p, s):
    open(p, 'wb').write(s.encode('latin1'))


def once(s, a, b):
    assert s.count(a) == 1, a
    return s.replace(a, b)


def main():
    src, out = sys.argv[1], sys.argv[2]
    os.makedirs(out, exist_ok=True)
    head = '\t.8086\r\n\tOPTION\tOLDSTRUCTS\r\n'
    # the macros of DOSMAC.ASM (EXTRN chains with `&`, a macro called invoke) are for the kernel only: SYSINIT uses BREAK
    wr(os.path.join(out, 'DOSMAC.ASM'), 'BREAK   MACRO   subtitle\r\nENDM\r\n')
    d = rd(os.path.join(src, 'DOSSYM.ASM'))
    d = once(d, 'IF2\r\n    %OUT    DOSSYM in Pass 2\r\nENDIF\r\n', '')    # a single pass assembler
    d = once(d, '\r\nWAIT   ', '\r\nDOSWAIT')                                # WAIT is an instruction
    wr(os.path.join(out, 'DOSSYM.ASM'), d)
    wr(os.path.join(out, 'DEVSYM.ASM'), rd(os.path.join(src, 'DEVSYM.ASM')))
    s = rd(os.path.join(src, 'SYSINIT.ASM'))
    s = once(s, 'AAA     PROC    FAR', 'AAAP    PROC    FAR')                  # AAA is an instruction
    s = once(s, 'AAA     ENDP', 'AAAP    ENDP')
    wr(os.path.join(out, 'SYSINIT.ASM'), head + s)
    wr(os.path.join(out, 'SYSIMES.ASM'), head + rd(os.path.join(src, 'SYSIMES.ASM')))


if __name__ == '__main__':
    main()
