#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""Known encodings for tools/z80asm.py (values from the Zilog Z80 CPU User Manual) and the sumz80 demo."""
import os, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'tools'))
sys.path.insert(0, os.path.join(ROOT, 'os9', 'sub'))
import z80asm
import sumz80

CASES = [
    ('NOP', '00'), ('LD A,B', '78'), ('LD B,(HL)', '46'), ('LD (HL),C', '71'), ('LD A,5', '3E05'),
    ('LD (HL),7', '3607'), ('LD BC,1234H', '013412'), ('LD SP,0FFFFH', '31FFFF'), ('LD HL,(1234H)', '2A3412'),
    ('LD (1234H),HL', '223412'), ('LD A,(1234H)', '3A3412'), ('LD (1234H),A', '323412'), ('LD A,(BC)', '0A'),
    ('LD (DE),A', '12'), ('LD DE,(1234H)', 'ED5B3412'), ('LD (1234H),BC', 'ED433412'), ('LD SP,HL', 'F9'),
    ('LD A,I', 'ED57'), ('LD R,A', 'ED4F'), ('LD IX,1234H', 'DD213412'), ('LD (IX+5),A', 'DD7705'),
    ('LD A,(IX-1)', 'DD7EFF'), ('LD (IY+2),9', 'FD360209'), ('LD IXH,5', 'DD2605'), ('LD A,IXL', 'DD7D'),
    ('LD IY,(1234H)', 'FD2A3412'), ('ADD A,B', '80'), ('ADD A,5', 'C605'), ('ADC A,(HL)', '8E'), ('SUB C', '91'),
    ('SBC A,B', '98'), ('AND 0FH', 'E60F'), ('XOR A', 'AF'), ('OR (IX+3)', 'DDB603'), ('CP 0DH', 'FE0D'),
    ('ADD HL,DE', '19'), ('ADC HL,BC', 'ED4A'), ('SBC HL,DE', 'ED52'), ('ADD IX,BC', 'DD09'), ('ADD IY,IY', 'FD29'),
    ('INC B', '04'), ('DEC (HL)', '35'), ('INC HL', '23'), ('DEC SP', '3B'), ('INC IX', 'DD23'), ('INC (IX+1)', 'DD3401'),
    ('INC IXH', 'DD24'), ('PUSH BC', 'C5'), ('POP AF', 'F1'), ('PUSH IX', 'DDE5'), ('EX DE,HL', 'EB'), ("EX AF,AF'", '08'),
    ('EX (SP),HL', 'E3'), ('EXX', 'D9'), ('JP 1234H', 'C33412'), ('JP NZ,1234H', 'C23412'), ('JP (HL)', 'E9'),
    ('JP (IX)', 'DDE9'), ('CALL 1234H', 'CD3412'), ('CALL C,1234H', 'DC3412'), ('RET', 'C9'), ('RET Z', 'C8'),
    ('RST 38H', 'FF'), ('RST 8', 'CF'), ('IM 1', 'ED56'), ('IM 2', 'ED5E'), ('IN A,(5)', 'DB05'), ('OUT (5),A', 'D305'),
    ('IN B,(C)', 'ED40'), ('OUT (C),D', 'ED51'), ('RLC B', 'CB00'), ('SRL A', 'CB3F'), ('SLL C', 'CB31'),
    ('RR (HL)', 'CB1E'), ('RLC (IX+2)', 'DDCB0206'), ('RLC (IX+2),B', 'DDCB0200'), ('BIT 7,A', 'CB7F'),
    ('BIT 0,(HL)', 'CB46'), ('SET 3,(IX+4)', 'DDCB04DE'), ('RES 1,B', 'CB88'), ('LDIR', 'EDB0'), ('CPIR', 'EDB1'),
    ('OTIR', 'EDB3'), ('NEG', 'ED44'), ('RETI', 'ED4D'), ('DAA', '27'), ('HALT', '76'), ('DI', 'F3'),
]


def main():
    bad = 0
    for src, hexs in CASES:
        _, img = z80asm.assemble('\tORG 0\n\t' + src + '\n')
        if img.hex().upper() != hexs:
            bad += 1
            print('FAIL %-22s got %s want %s' % (src, img.hex().upper(), hexs))
    # relative jumps, labels, expressions, data
    _, img = z80asm.assemble('\tORG 100H\nL1:\tDJNZ L1\n\tJR NZ,L2\n\tNOP\nL2:\tJR $\n\tDB 1,"AB",\'C\'\n\tDW L1+1\n\tDS 2,0FFH\n')
    want = bytes.fromhex('10FE200100' + '18FE' + '01414243' + '0101' + 'FFFF')
    if img != want:
        bad += 1
        print('FAIL labels/data: got %s want %s' % (img.hex(), want.hex()))
    # the sumz80 demo: source form of the hand assembled bytes
    src = '''
        ORG 0
        LD SP,4000H
        IM 1
        EI
        XOR A
        OUT (03H),A
        OUT (02H),A
        HALT
        JR $-1
        ORG 38H
        PUSH AF
        PUSH BC
        PUSH HL
        IN A,(04H)
        LD C,A
        LD HL,0
        LD B,0
SUMLP:  ADD HL,BC
        DEC C
        JR NZ,SUMLP
        LD (0100H),HL
        LD A,L
        OUT (08H),A
        LD A,H
        OUT (09H),A
        LD A,0
        OUT (03H),A
        OUT (02H),A
        POP HL
        POP BC
        POP AF
        EI
        RETI
'''
    _, img = z80asm.assemble(src)
    if img != sumz80.image():
        bad += 1
        print('FAIL sumz80 source differs from the hand assembled image')
    print('z80asm: %d cases, %d failed' % (len(CASES) + 2, bad))
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
