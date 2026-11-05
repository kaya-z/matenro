# Make COMMAND.ASM of 86-DOS 1.25 assemble with UASM.  The original is not changed.
import re, sys
SRC, OUT = sys.argv[1], sys.argv[2]
src = open(SRC + '/COMMAND.ASM', 'rb').read().decode('latin-1').split('\n')
def outside_strings(code, f):
    parts = re.split(r'("[^"]*")', code)             # odd items are the strings
    return ''.join(p if i % 2 else f(p) for i, p in enumerate(parts))
out = []
for n, l in enumerate(src, 1):
    code, sep, com = l.partition(';') if '"' not in l.partition(';')[0] or l.partition(';')[0].count('"') % 2 == 0 else (l, '', '')
    if re.match(r'\s*ORG\s+100H', code):   # UASM gets the offsets of the groups wrong with ORG 100H in a segment: really 256 bytes
        code = '        DB      256 DUP (0)       '
    if n == 156:
        code = code.replace('ZERO    EQU', 'ZERO    =  ')
    code = outside_strings(code, lambda p: re.sub(r'\bPAUSE\b', 'CMDPAUSE', re.sub(r'\bOUT\b', 'CMDOUT', p)))
    out.append(code + sep + com)
open(OUT + '/COMMAND.ASM', 'wb').write('\n'.join(out).encode('latin-1'))
