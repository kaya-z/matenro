; SPDX-License-Identifier: MIT
; duoz80.asm - the Z80 worker of the OS-9 command `duo` (Mandelbrot on both CPUs of 摩天楼), assembled with tools/z80asm.py
; Protocol (the doorbell of os9/sub/sumz80.py, but polled, no interrupt): after the start it rings the 6809 ("ready").
; Then, for each row the 6809 gives it (M2S[0] = 0..24, doorbell): computes the 79 characters of the row into the shared RAM
; at 0200h and rings the 6809 again.  Fixed point with 8 fraction bits (Q8), the same arithmetic as the 6809 part (duo.asm):
;   ca = x*12 (x = -39..39)   cb = y*21 (y = -12..12)   a,b := a*a-b*b+ca, 2*a*b+cb   escape when a*a+b*b > 4
; The characters are "0123456789ABCDEF " [iteration count].  The code is original.
OUTB    EQU     0200H
CA      EQU     0300H
CB      EQU     0302H
AA      EQU     0304H
BB      EQU     0306H
A2      EQU     0308H
B2      EQU     030AH
OP      EQU     030CH
XC      EQU     030EH
IT      EQU     030FH
SGN     EQU     0310H
PH      EQU     0311H
PL      EQU     0312H
QH      EQU     0313H
QL      EQU     0314H
ACC     EQU     0315H
        ORG     0
        LD      SP,4000H
        XOR     A
        OUT     (03H),A
        OUT     (02H),A         ; ready
WAITR:  IN      A,(01H)
        AND     1
        JR      Z,WAITR
        IN      A,(04H)         ; the row 0..24
        LD      B,A
        XOR     A
        OUT     (03H),A         ; acknowledge
        LD      HL,0            ; cb = row*21 - 252
        LD      DE,21
        LD      A,B
        OR      A
        JR      Z,NOROW
ADDR:   ADD     HL,DE
        DJNZ    ADDR
NOROW:  LD      DE,-252
        ADD     HL,DE
        LD      (CB),HL
        LD      HL,-468         ; ca = -39*12
        LD      (CA),HL
        LD      HL,OUTB
        LD      (OP),HL
        LD      A,79
        LD      (XC),A
PIX:    LD      HL,(CA)
        LD      (AA),HL
        CALL    SQ
        LD      (A2),HL
        LD      HL,(CB)
        LD      (BB),HL
        CALL    SQ
        LD      (B2),HL
        XOR     A
        LD      (IT),A
ITER:   LD      HL,(A2)         ; t = a2 - b2 + ca
        LD      DE,(B2)
        OR      A
        SBC     HL,DE
        LD      DE,(CA)
        ADD     HL,DE
        PUSH    HL
        LD      HL,(AA)         ; b = 2*a*b + cb
        LD      DE,(BB)
        CALL    MULQ
        ADD     HL,HL
        LD      DE,(CB)
        ADD     HL,DE
        LD      (BB),HL
        POP     HL
        LD      (AA),HL         ; a = t
        CALL    SQ
        LD      (A2),HL
        LD      HL,(BB)
        CALL    SQ
        LD      (B2),HL
        LD      HL,(A2)
        LD      DE,(B2)
        ADD     HL,DE
        LD      DE,1025         ; a*a+b*b > 4  (4 = 1024 in Q8)
        OR      A
        SBC     HL,DE
        JR      NC,ESC
        LD      A,(IT)
        INC     A
        LD      (IT),A
        CP      16
        JR      C,ITER
ESC:    LD      A,(IT)
        CP      10
        JR      C,DIGIT
        CP      16
        JR      Z,BLANK
        ADD     A,'A'-10
        JR      PUT
DIGIT:  ADD     A,'0'
        JR      PUT
BLANK:  LD      A,' '
PUT:    LD      HL,(OP)
        LD      (HL),A
        INC     HL
        LD      (OP),HL
        LD      HL,(CA)
        LD      DE,12
        ADD     HL,DE
        LD      (CA),HL
        LD      A,(XC)
        DEC     A
        LD      (XC),A
        JP      NZ,PIX
        OUT     (02H),A         ; the row is ready
        JP      WAITR

; HL = HL*HL (Q8)
SQ:     LD      D,H
        LD      E,L
        ; fall into MULQ
; HL = HL*DE >> 8 (signed Q8, |values| < 4096)
MULQ:   LD      A,H
        XOR     D
        AND     80H
        LD      (SGN),A
        BIT     7,H
        JR      Z,P1
        LD      A,L
        CPL
        LD      L,A
        LD      A,H
        CPL
        LD      H,A
        INC     HL
P1:     BIT     7,D
        JR      Z,P2
        LD      A,E
        CPL
        LD      E,A
        LD      A,D
        CPL
        LD      D,A
        INC     DE
P2:     LD      A,H
        LD      (PH),A
        LD      A,L
        LD      (PL),A
        LD      A,D
        LD      (QH),A
        LD      A,E
        LD      (QL),A
        LD      A,(QL)          ; pl*ql >> 8
        LD      E,A
        LD      A,(PL)
        CALL    MUL8
        LD      L,H
        LD      H,0
        LD      (ACC),HL
        LD      A,(QL)          ; + ph*ql
        LD      E,A
        LD      A,(PH)
        CALL    MUL8
        LD      DE,(ACC)
        ADD     HL,DE
        LD      (ACC),HL
        LD      A,(QH)          ; + pl*qh
        LD      E,A
        LD      A,(PL)
        CALL    MUL8
        LD      DE,(ACC)
        ADD     HL,DE
        LD      (ACC),HL
        LD      A,(QH)          ; + (ph*qh << 8)
        LD      E,A
        LD      A,(PH)
        CALL    MUL8
        LD      H,L
        LD      L,0
        LD      DE,(ACC)
        ADD     HL,DE
        LD      A,(SGN)
        OR      A
        RET     Z
        LD      A,L
        CPL
        LD      L,A
        LD      A,H
        CPL
        LD      H,A
        INC     HL
        RET

; HL = A*E (unsigned 8 x 8)
MUL8:   LD      HL,0
        LD      D,0
        LD      B,8
M8L:    ADD     HL,HL
        RLCA
        JR      NC,M8N
        ADD     HL,DE
M8N:    DJNZ    M8L
        RET
