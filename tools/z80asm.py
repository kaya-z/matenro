#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""z80asm - a small two pass Z80 assembler (Zilog mnemonics) for the test programs of 摩天楼 (Matenro).

  python3 tools/z80asm.py prog.asm -o prog.com [-l prog.lst]

Supported: all documented Z80 instructions and the common undocumented ones (IXH/IXL/IYH/IYL, SLL),
labels (with or without ':'), ORG EQU DB/DEFB DW/DEFW DS/DEFS/DEFM END, '$' for the current address,
expressions with + - * / % & | ^ ~ << >> ( ), HIGH() LOW(), numbers 123 0x7F 7FH $7F 1010B 'c' "str".
The output is the image from the lowest ORG to the highest address written (like a .COM file when ORG 100H).

Credits: the encodings follow the Zilog "Z80 CPU User Manual" (UM0080) and Sean Young's "The Undocumented
Z80 Documented".  The assembler itself is original (no code of another assembler was used).
"""
import re
import sys

R8 = {'B': 0, 'C': 1, 'D': 2, 'E': 3, 'H': 4, 'L': 5, 'A': 7}
RP = {'BC': 0, 'DE': 1, 'HL': 2, 'SP': 3}
RP2 = {'BC': 0, 'DE': 1, 'HL': 2, 'AF': 3}
CC = {'NZ': 0, 'Z': 1, 'NC': 2, 'C': 3, 'PO': 4, 'PE': 5, 'P': 6, 'M': 7}
ALU = {'ADD': 0, 'ADC': 1, 'SUB': 2, 'SBC': 3, 'AND': 4, 'XOR': 5, 'OR': 6, 'CP': 7}
ROT = {'RLC': 0, 'RRC': 1, 'RL': 2, 'RR': 3, 'SLA': 4, 'SRA': 5, 'SLL': 6, 'SRL': 7}
SIMPLE = {'NOP': [0x00], 'HALT': [0x76], 'DI': [0xF3], 'EI': [0xFB], 'EXX': [0xD9], 'DAA': [0x27], 'CPL': [0x2F],
          'SCF': [0x37], 'CCF': [0x3F], 'RLCA': [0x07], 'RRCA': [0x0F], 'RLA': [0x17], 'RRA': [0x1F],
          'NEG': [0xED, 0x44], 'RETN': [0xED, 0x45], 'RETI': [0xED, 0x4D], 'RRD': [0xED, 0x67], 'RLD': [0xED, 0x6F],
          'LDI': [0xED, 0xA0], 'LDIR': [0xED, 0xB0], 'LDD': [0xED, 0xA8], 'LDDR': [0xED, 0xB8],
          'CPI': [0xED, 0xA1], 'CPIR': [0xED, 0xB1], 'CPD': [0xED, 0xA9], 'CPDR': [0xED, 0xB9],
          'INI': [0xED, 0xA2], 'INIR': [0xED, 0xB2], 'IND': [0xED, 0xAA], 'INDR': [0xED, 0xBA],
          'OUTI': [0xED, 0xA3], 'OTIR': [0xED, 0xB3], 'OUTD': [0xED, 0xAB], 'OTDR': [0xED, 0xBB]}


class AsmError(Exception):
    pass


def split_operands(s):
    out, cur, depth, q = [], '', 0, None
    for ch in s:
        if q:
            cur += ch
            if ch == q:
                q = None
        elif ch in '\'"':
            q = ch
            cur += ch
        elif ch == '(':
            depth += 1
            cur += ch
        elif ch == ')':
            depth -= 1
            cur += ch
        elif ch == ',' and depth == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


class Asm:
    def __init__(self):
        self.sym = {}
        self.pc = 0
        self.image = {}
        self.pass_no = 1
        self.lst = []

    # ---------------------------------------------------------------- expressions
    def num(self, tok):
        t = tok.upper()
        if re.fullmatch(r'0X[0-9A-F]+', t):
            return int(t, 16)
        if re.fullmatch(r'\$[0-9A-F]+', t):
            return int(t[1:], 16)
        if re.fullmatch(r'[0-9][0-9A-F]*H', t):
            return int(t[:-1], 16)
        if re.fullmatch(r'[01]+B', t):
            return int(t[:-1], 2)
        if re.fullmatch(r'[0-9]+', t):
            return int(t)
        raise AsmError('bad number ' + tok)

    def expr(self, s):
        s = s.strip()
        toks = re.findall(r"'(?:[^'\\]|\\.)'|0[xX][0-9A-Fa-f]+|\$[0-9A-Fa-f]+|[0-9][0-9A-Fa-f]*[Hh]|[01]+[Bb]\b|[0-9]+|<<|>>|[A-Za-z_.@?][A-Za-z_0-9.@?]*|\$|[-+*/%&|^~()]|\S", s)
        if ''.join(toks).replace(' ', '') != s.replace(' ', ''):
            raise AsmError('bad expression ' + s)
        py = []
        for t in toks:
            if t[0] == "'":
                c = t[1:-1].encode().decode('unicode_escape')
                py.append(str(ord(c)))
            elif t == '$' and not re.match(r'\$[0-9A-Fa-f]', t):
                py.append(str(self.pc))
            elif re.fullmatch(r'0[xX][0-9A-Fa-f]+|\$[0-9A-Fa-f]+', t) or re.fullmatch(r'[0-9][0-9A-Fa-f]*[Hh]', t) \
                    or re.fullmatch(r'[01]+[Bb]', t) or re.fullmatch(r'[0-9]+', t):
                py.append(str(self.num(t)))
            elif re.fullmatch(r'[A-Za-z_.@?][A-Za-z_0-9.@?]*', t):
                u = t.upper()
                if u in ('HIGH', 'LOW'):
                    py.append('_' + u)
                else:
                    if u not in self.sym:
                        if self.pass_no == 1:
                            py.append('0')
                            continue
                        raise AsmError('undefined symbol ' + t)
                    py.append(str(self.sym[u]))
            elif t == '/':
                py.append('//')
            else:
                py.append(t)
        try:
            return int(eval(''.join(py), {'__builtins__': {}}, {'_HIGH': lambda v: (v >> 8) & 255, '_LOW': lambda v: v & 255}))
        except Exception as e:
            raise AsmError('cannot evaluate %s (%s)' % (s, e))

    # ---------------------------------------------------------------- operands
    def classify(self, op):
        o = op.strip()
        u = o.upper()
        if u in R8:
            return ('r', R8[u])
        if u in ('IXH', 'IYH', 'IXL', 'IYL'):
            return ('xr', u)
        if u == '(HL)':
            return ('mhl', 6)
        if u in RP:
            return ('rp', u)
        if u in ('IX', 'IY'):
            return ('ix', u)
        if u in ('AF', "AF'"):
            return (u, 0)
        if u in ('I', 'R'):
            return ('ir', u)
        if u in ('(BC)', '(DE)', '(SP)', '(C)'):
            return ('m' + u[1:-1].lower(), 0)
        m = re.fullmatch(r'\(\s*(IX|IY)\s*([+-].*)?\)', u)
        if m:
            d = self.expr(o[o.upper().index(m.group(1)) + 2:-1]) if m.group(2) else 0
            return ('idx', m.group(1), d)
        if u in CC:
            return ('cc', CC[u])
        if o.startswith('(') and o.endswith(')') and self.balanced(o[1:-1]):
            return ('mem', self.expr(o[1:-1]))
        return ('imm', self.expr(o))

    @staticmethod
    def balanced(s):
        d = 0
        for ch in s:
            d += (ch == '(') - (ch == ')')
            if d < 0:
                return False
        return d == 0

    # ---------------------------------------------------------------- encoding
    def pfx(self, which):
        return 0xDD if which in ('IX', 'IXH', 'IXL') else 0xFD

    def xr_info(self, name):
        return self.pfx(name), (4 if name[2] == 'H' else 5)

    def enc(self, mn, ops):
        c = [self.classify(o) for o in ops]
        k = [x[0] for x in c]
        b = []
        if mn in SIMPLE and not ops:
            return SIMPLE[mn]
        if mn == 'LD':
            return self.enc_ld(c, k)
        if mn in ALU:
            if mn in ('ADD', 'ADC', 'SBC') and len(c) == 2 and k[0] == 'rp' and c[0][1] == 'HL':
                if k[1] == 'rp':
                    if mn == 'ADD':
                        return [0x09 | RP[c[1][1]] << 4]
                    return [0xED, (0x4A if mn == 'ADC' else 0x42) | RP[c[1][1]] << 4]
            if mn == 'ADD' and len(c) == 2 and k[0] == 'ix':
                p = self.pfx(c[0][1])
                src = c[1]
                if src[0] == 'rp' and src[1] != 'HL':
                    return [p, 0x09 | RP[src[1]] << 4]
                if src[0] == 'ix' and src[1] == c[0][1]:
                    return [p, 0x29]
                raise AsmError('bad ADD IX')
            if len(c) == 2:
                if k[0] != 'r' or c[0][1] != 7:
                    raise AsmError('ALU destination must be A')
                c, k = c[1:], k[1:]
            if len(c) != 1:
                raise AsmError('bad operands')
            return self.enc_alu(ALU[mn], c[0])
        if mn in ('INC', 'DEC'):
            d = 1 if mn == 'DEC' else 0
            x = c[0]
            if x[0] == 'r' or x[0] == 'mhl':
                return [0x04 | x[1] << 3 | d]
            if x[0] == 'rp':
                return [0x03 | RP[x[1]] << 4 | d << 3]
            if x[0] == 'ix':
                return [self.pfx(x[1]), 0x23 | d << 3]
            if x[0] == 'xr':
                p, r = self.xr_info(x[1])
                return [p, 0x04 | r << 3 | d]
            if x[0] == 'idx':
                return [self.pfx(x[1]), 0x34 | d, x[2] & 255]
        if mn in ROT:
            x = c[0]
            n = ROT[mn]
            if x[0] in ('r', 'mhl'):
                return [0xCB, n << 3 | x[1]]
            if x[0] == 'idx':
                last = [n << 3 | (6 if len(c) == 1 else R8[ops[1].strip().upper()])]
                return [self.pfx(x[1]), 0xCB, x[2] & 255] + last
        if mn in ('BIT', 'RES', 'SET'):
            n = self.expr(ops[0])
            base = {'BIT': 0x40, 'RES': 0x80, 'SET': 0xC0}[mn] | n << 3
            x = c[1]
            if x[0] in ('r', 'mhl'):
                return [0xCB, base | x[1]]
            if x[0] == 'idx':
                return [self.pfx(x[1]), 0xCB, x[2] & 255, base | (6 if len(c) == 2 else R8[ops[2].strip().upper()])]
        if mn == 'PUSH' or mn == 'POP':
            x = c[0]
            op = 0xC5 if mn == 'PUSH' else 0xC1
            if x[0] == 'rp' and x[1] in RP2 or x[0] == 'AF':
                return [op | RP2[x[1] if x[0] == 'rp' else 'AF'] << 4]
            if x[0] == 'ix':
                return [self.pfx(x[1]), op | 2 << 4]
        if mn in ('JP', 'JR', 'CALL', 'RET') and ops and ops[0].upper() in CC and (len(ops) == 2 or mn == 'RET'):
            c[0] = ('cc', CC[ops[0].upper()])
            k[0] = 'cc'
        if mn == 'JP':
            if len(c) == 1:
                x = c[0]
                if x[0] == 'mhl':
                    return [0xE9]
                if x[0] == 'mem' and False:
                    pass
                if x[0] == 'ix' or (x[0] == 'idx' and x[2] == 0):
                    return [self.pfx(x[1]), 0xE9]
                return [0xC3, x[1] & 255, (x[1] >> 8) & 255]
            return [0xC2 | c[0][1] << 3, c[1][1] & 255, (c[1][1] >> 8) & 255]
        if mn == 'JR' or mn == 'DJNZ':
            cc = None
            if mn == 'JR' and len(c) == 2:
                cc = c[0][1]
                if cc > 3:
                    raise AsmError('JR condition')
                tgt = c[1][1]
            else:
                tgt = c[0][1]
            d = tgt - (self.pc + 2)
            if self.pass_no == 2 and not -128 <= d <= 127:
                raise AsmError('relative jump out of range (%d)' % d)
            op = 0x10 if mn == 'DJNZ' else (0x18 if cc is None else 0x20 | cc << 3)
            return [op, d & 255]
        if mn == 'CALL':
            if len(c) == 1:
                return [0xCD, c[0][1] & 255, (c[0][1] >> 8) & 255]
            return [0xC4 | c[0][1] << 3, c[1][1] & 255, (c[1][1] >> 8) & 255]
        if mn == 'RET':
            return [0xC9] if not c else [0xC0 | c[0][1] << 3]
        if mn == 'RST':
            return [0xC7 | (c[0][1] & 0x38)]
        if mn == 'EX':
            a, b2 = ops[0].upper().replace(' ', ''), ops[1].upper().replace(' ', '')
            if (a, b2) == ('DE', 'HL'):
                return [0xEB]
            if (a, b2) == ('AF', "AF'"):
                return [0x08]
            if a == '(SP)' and b2 == 'HL':
                return [0xE3]
            if a == '(SP)' and b2 in ('IX', 'IY'):
                return [self.pfx(b2), 0xE3]
        if mn == 'IN':
            if k == ['r', 'mem']:
                return [0xDB, c[1][1] & 255]
            if k[1] == 'mc':
                return [0xED, 0x40 | (c[0][1] if k[0] == 'r' else 6) << 3]
            if k == ['imm', 'mc'] and c[0][1] == 0:
                return [0xED, 0x70]
        if mn == 'OUT':
            if k == ['mem', 'r']:
                return [0xD3, c[0][1] & 255]
            if k[0] == 'mc':
                if k[1] == 'r':
                    return [0xED, 0x41 | c[1][1] << 3]
                if c[1][1] == 0:
                    return [0xED, 0x71]
        if mn == 'IM':
            return [0xED, {0: 0x46, 1: 0x56, 2: 0x5E}[c[0][1]]]
        raise AsmError('cannot assemble: %s %s' % (mn, ', '.join(ops)))

    def enc_alu(self, n, x):
        if x[0] in ('r', 'mhl'):
            return [0x80 | n << 3 | x[1]]
        if x[0] == 'imm':
            return [0xC6 | n << 3, x[1] & 255]
        if x[0] == 'xr':
            p, r = self.xr_info(x[1])
            return [p, 0x80 | n << 3 | r]
        if x[0] == 'idx':
            return [self.pfx(x[1]), 0x86 | n << 3, x[2] & 255]
        raise AsmError('bad ALU operand')

    def enc_ld(self, c, k):
        d, s = c
        kd, ks = k
        if kd in ('r', 'mhl') and ks in ('r', 'mhl') and not (kd == 'mhl' and ks == 'mhl'):
            return [0x40 | d[1] << 3 | s[1]]
        if kd in ('r', 'mhl') and ks == 'imm':
            return [0x06 | d[1] << 3, s[1] & 255]
        if kd == 'xr' or ks == 'xr':
            x = d if kd == 'xr' else s
            p, r = self.xr_info(x[1])
            o = s if kd == 'xr' else d
            if kd == 'xr' and ks == 'imm':
                return [p, 0x06 | r << 3, o[1] & 255]
            if o[0] == 'xr':
                if self.pfx(o[1]) != p:
                    raise AsmError('mixed IX/IY')
                ro = 4 if o[1][2] == 'H' else 5
                return [p, 0x40 | (r if kd == 'xr' else ro) << 3 | (ro if kd == 'xr' else r)]
            if o[0] == 'r' and o[1] not in (4, 5):
                return [p, 0x40 | (r << 3 | o[1] if kd == 'xr' else o[1] << 3 | r)]
        if kd == 'r' and ks == 'idx':
            return [self.pfx(s[1]), 0x46 | d[1] << 3, s[2] & 255]
        if kd == 'idx' and ks == 'r':
            return [self.pfx(d[1]), 0x70 | s[1], d[2] & 255]
        if kd == 'idx' and ks == 'imm':
            return [self.pfx(d[1]), 0x36, d[2] & 255, s[1] & 255]
        if kd == 'r' and d[1] == 7:
            if ks == 'mbc':
                return [0x0A]
            if ks == 'mde':
                return [0x1A]
            if ks == 'mem':
                return [0x3A, s[1] & 255, (s[1] >> 8) & 255]
            if ks == 'ir':
                return [0xED, 0x57 if s[1] == 'I' else 0x5F]
        if ks == 'r' and s[1] == 7:
            if kd == 'mbc':
                return [0x02]
            if kd == 'mde':
                return [0x12]
            if kd == 'mem':
                return [0x32, d[1] & 255, (d[1] >> 8) & 255]
            if kd == 'ir':
                return [0xED, 0x47 if d[1] == 'I' else 0x4F]
        if kd == 'rp' and ks == 'imm':
            return [0x01 | RP[d[1]] << 4, s[1] & 255, (s[1] >> 8) & 255]
        if kd == 'ix' and ks == 'imm':
            return [self.pfx(d[1]), 0x21, s[1] & 255, (s[1] >> 8) & 255]
        if kd == 'rp' and ks == 'mem':
            if d[1] == 'HL':
                return [0x2A, s[1] & 255, (s[1] >> 8) & 255]
            return [0xED, 0x4B | RP[d[1]] << 4, s[1] & 255, (s[1] >> 8) & 255]
        if kd == 'mem' and ks == 'rp':
            if s[1] == 'HL':
                return [0x22, d[1] & 255, (d[1] >> 8) & 255]
            return [0xED, 0x43 | RP[s[1]] << 4, d[1] & 255, (d[1] >> 8) & 255]
        if kd == 'ix' and ks == 'mem':
            return [self.pfx(d[1]), 0x2A, s[1] & 255, (s[1] >> 8) & 255]
        if kd == 'mem' and ks == 'ix':
            return [self.pfx(s[1]), 0x22, d[1] & 255, (d[1] >> 8) & 255]
        if kd == 'rp' and d[1] == 'SP':
            if ks == 'rp' and s[1] == 'HL':
                return [0xF9]
            if ks == 'ix':
                return [self.pfx(s[1]), 0xF9]
        raise AsmError('cannot assemble LD')

    # ---------------------------------------------------------------- driver
    def emit(self, bs):
        for x in bs:
            self.image[self.pc] = x & 255
            self.pc += 1

    def line(self, text, no):
        orig = text
        # strip comments outside quotes
        out, q = '', None
        for ch in text:
            if q:
                out += ch
                if ch == q:
                    q = None
            elif ch in '\'"':
                q = ch
                out += ch
            elif ch == ';':
                break
            else:
                out += ch
        text = out.rstrip()
        if not text.strip():
            return
        m = re.match(r'^([A-Za-z_.@?][A-Za-z_0-9.@?]*)\s*(:|\s+EQU\b|\s+equ\b)?\s*(.*)$', text)
        label = None
        rest = text.strip()
        if text[0] not in ' \t':
            m = re.match(r'^([A-Za-z_.@?][A-Za-z_0-9.@?]*)(:?)\s*(.*)$', text)
            label, rest = m.group(1).upper(), m.group(3)
            m2 = re.match(r'^(?i:equ)\s+(.*)$', rest)
            if m2:
                self.sym[label] = self.expr(m2.group(1))
                return
            self.sym[label] = self.pc
        rest = rest.strip()
        if not rest:
            return
        parts = rest.split(None, 1)
        mn = parts[0].upper()
        args = parts[1] if len(parts) > 1 else ''
        if mn == 'EQU':
            self.sym[label] = self.expr(args)
            return
        start = self.pc
        if mn == 'ORG':
            self.pc = self.expr(args)
            return
        if mn == 'END':
            return
        ops = split_operands(args)
        if mn in ('DB', 'DEFB', 'DEFM', 'DM'):
            bs = []
            for o in ops:
                if len(o) >= 2 and o[0] in '"\'' and o[-1] == o[0] and len(o) != 3 or (len(o) >= 2 and o[0] == '"'):
                    bs += list(o[1:-1].encode().decode('unicode_escape').encode('latin-1'))
                else:
                    bs.append(self.expr(o))
            self.emit(bs)
        elif mn in ('DW', 'DEFW'):
            for o in ops:
                v = self.expr(o)
                self.emit([v & 255, (v >> 8) & 255])
        elif mn in ('DS', 'DEFS'):
            n = self.expr(ops[0])
            fill = self.expr(ops[1]) if len(ops) > 1 else 0
            self.emit([fill] * n)
        else:
            try:
                bs = self.enc(mn, ops)
            except (KeyError, IndexError):
                raise AsmError('bad operands for ' + mn)
            self.emit(bs)
        self.lst.append((start, self.pc))

    def assemble(self, src):
        lines = src.split('\n')
        for p in (1, 2):
            self.pass_no = p
            self.pc = 0
            self.image = {}
            self.lst = []
            for i, l in enumerate(lines, 1):
                try:
                    self.line(l, i)
                except AsmError as e:
                    raise AsmError('line %d: %s\n    %s' % (i, e, l))
        if not self.image:
            return 0, b''
        lo, hi = min(self.image), max(self.image)
        return lo, bytes(self.image.get(a, 0) for a in range(lo, hi + 1))


def assemble(src):
    return Asm().assemble(src)


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    out = None
    src = None
    i = 1
    while i < len(argv):
        if argv[i] == '-o':
            out = argv[i + 1]
            i += 2
        elif argv[i] == '-l':
            i += 2
        else:
            src = argv[i]
            i += 1
    a = Asm()
    try:
        lo, img = a.assemble(open(src, encoding='utf-8').read())
    except AsmError as e:
        print('z80asm: %s' % e, file=sys.stderr)
        return 1
    open(out or 'a.out', 'wb').write(img)
    print('%s: %d bytes at %04X' % (out or 'a.out', len(img), lo))
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
