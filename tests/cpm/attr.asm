; attr.asm - CP/M-80 test (run in /d1, an RBF disk): BDOS 30 (read only attribute) and its display by BDOS 17, BDOS 3 / 7 / 8.
;   makes ATT.WLD; BDOS 30 with the high bit of the type: R/O; BDOS 17 shows the bit; BDOS 30 without it: R/W; the bit is gone;
;   BDOS 3 gives 1Ah; the IOBYTE set by BDOS 8 comes back from BDOS 7.  Prints "ATTR OK" or "ATTR FAIL n".
BDOS    EQU     5
        ORG     100H
        LD      DE,DMA
        LD      C,26
        CALL    BDOS
        LD      A,0
        CALL    SETFCB
        LD      DE,FCB
        LD      C,19            ; (an old one)
        CALL    BDOS
        LD      A,0
        CALL    SETFCB
        LD      DE,FCB
        LD      C,22
        CALL    BDOS
        INC     A
        LD      B,1
        JP      Z,FAIL
        LD      DE,FCB
        LD      C,16
        CALL    BDOS
        LD      A,80H           ; read only
        CALL    SETFCB
        LD      DE,FCB
        LD      C,30
        CALL    BDOS
        LD      A,0
        CALL    SETFCB
        LD      DE,FCB
        LD      C,17            ; search first
        CALL    BDOS
        CP      0FFH
        LD      B,2
        JP      Z,FAIL
        LD      A,(DMA+9)       ; t1' set?
        AND     80H
        LD      B,3
        JP      Z,FAIL
        XOR     A               ; read / write again
        CALL    SETFCB
        LD      DE,FCB
        LD      C,30
        CALL    BDOS
        LD      A,0
        CALL    SETFCB
        LD      DE,FCB
        LD      C,17
        CALL    BDOS
        CP      0FFH
        LD      B,4
        JP      Z,FAIL
        LD      A,(DMA+9)
        AND     80H
        LD      B,5
        JP      NZ,FAIL
        LD      A,0
        CALL    SETFCB
        LD      DE,FCB
        LD      C,19
        CALL    BDOS
        LD      C,3             ; reader input: end of file
        CALL    BDOS
        CP      1AH
        LD      B,6
        JP      NZ,FAIL
        LD      E,55H           ; the IOBYTE
        LD      C,8
        CALL    BDOS
        LD      C,7
        CALL    BDOS
        CP      55H
        LD      B,7
        JP      NZ,FAIL
        LD      DE,OK
        LD      C,9
        CALL    BDOS
        RET
FAIL:   LD      A,'0'
        ADD     A,B
        LD      (NUM),A
        LD      DE,BAD
        LD      C,9
        CALL    BDOS
        RET
; the FCB for ATT.WLD; A = the high bit for the first character of the type
SETFCB: LD      (HI),A
        LD      HL,FCB
        LD      B,36
SF1:    LD      (HL),0
        INC     HL
        DJNZ    SF1
        LD      HL,NAME
        LD      DE,FCB+1
        LD      BC,11
        LDIR
        LD      A,(HI)
        LD      B,A
        LD      A,(FCB+9)
        OR      B
        LD      (FCB+9),A
        RET
NAME:   DB      'ATT     WLD'
HI:     DB      0
OK:     DB      'ATTR OK',13,10,'$'
BAD:    DB      'ATTR FAIL '
NUM:    DB      '0',13,10,'$'
FCB:    DS      36
DMA:    DS      128
