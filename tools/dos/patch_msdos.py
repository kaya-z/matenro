# Make MSDOS.ASM of 86-DOS 1.25 assemble with UASM (a MASM-compatible assembler).  The original is not changed.
import re, sys
SRC, OUT = sys.argv[1], sys.argv[2]
src = open(SRC + '/MSDOS.ASM', 'rb').read().decode('latin-1').split('\n')
out = []
for n, l in enumerate(src, 1):
    code, sep, com = l.partition(';')
    if n in (162, 163):                       # the empty SEGBIOS: it is defined (AT BIOSSEG) below
        out.append(';' + l); continue
    if n in (275, 3952, 3953):                # label IRET (the instruction IRET stays)
        code = re.sub(r'^IRET:', 'IRETLBL:', code) if n == 275 else code.replace('DOSGROUP:IRET', 'DOSGROUP:IRETLBL')
    else:
        code = re.sub(r'\bIN\b', 'DOSIN', code)   # IN, OUT, LEAVE, FSAVE are used as labels only
        code = re.sub(r'\bOUT\b', 'DOSOUT', code)
        code = re.sub(r'\bLEAVE\b', 'DOSLEAVE', code)
        code = re.sub(r'\bFSAVE\b', 'FLAGSAVE', code)
    if n == 2694:
        code = code.replace('[DI.RECSIZ],64', 'WORD PTR [DI.RECSIZ],64')
    if re.match(r'\s*(MUL|DIV)\s+(ES:)?\[BP\.SECSIZ\]', code):
        code = code.replace('MUL ', 'MUL WORD PTR ').replace('DIV ', 'DIV WORD PTR ')
    m = re.match(r'(\s*)(J[A-Z]+)(\s+)NEAR PTR (\w+)\s*$', code)
    if m:                                     # no near conditional jumps on the 8086: inverted jump over a JMP
        inv = {'JC':'JNC','JNC':'JC','JS':'JNS','JNS':'JS','JZ':'JNZ','JNZ':'JZ','JE':'JNE','JNE':'JE'}[m.group(2)]
        out.append('%s%s     SKIPJ%d' % (m.group(1), inv, n)); out.append('%sJMP     %s' % (m.group(1), m.group(4)))
        out.append('SKIPJ%d:' % n)
        continue
    out.append(code + sep + com)
open(OUT + '/MSDOS.ASM', 'wb').write('\n'.join(out).encode('latin-1'))
