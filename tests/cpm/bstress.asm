; SPDX-License-Identifier: MIT
; bstress.asm - stress test of the Z80 <-> 6809 link of 摩天楼 (Matenro): the Z80 works on its memory (fill and check 256 bytes)
; and calls the BDOS (console output) in between, again and again.  A dot per round, E if the memory check fails.
; The number of rounds is COUNT.  It prints "DONE" at the end.  (Written to find out why ZEXDOC stopped on the board.)
COUNT   EQU     3000
        ORG     100H
START:  LD      HL,0
        LD      (CNT),HL
ROUND:  LD      HL,BUF
        LD      B,0
        LD      A,(CNT)
        LD      C,A
FILL:   LD      (HL),C
        INC     HL
        INC     C
        DJNZ    FILL
        LD      HL,BUF
        LD      B,0
        LD      A,(CNT)
        LD      C,A
CHK:    LD      A,(HL)
        CP      C
        JR      NZ,BAD
        INC     HL
        INC     C
        DJNZ    CHK
        LD      E,'.'
        JR      OUT
BAD:    LD      E,'E'
OUT:    LD      C,2
        CALL    5
        LD      HL,(CNT)
        INC     HL
        LD      (CNT),HL
        LD      DE,COUNT
        OR      A
        SBC     HL,DE
        JR      C,ROUND
        LD      DE,MSG
        LD      C,9
        CALL    5
        RET
MSG:    DB      13,10,'DONE',13,10,'$'
CNT:    DW      0
BUF:    DS      256
