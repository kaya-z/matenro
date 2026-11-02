; alloc.asm - CP/M-80 test (run in /d1, an RBF disk): BDOS 31 (the disk parameter block: 2048 blocks of 2K) and BDOS 27 (the
; allocation vector: a file of 40 records = 5120 bytes takes 3 blocks).  Prints "ALLOC OK" or "ALLOC FAIL n".
BDOS    EQU     5
        ORG     100H
        LD      DE,DMA
        LD      C,26
        CALL    BDOS
        LD      C,31
        CALL    BDOS
        LD      A,H
        CP      0FDH
        LD      B,1
        JP      NZ,FAIL
        LD      DE,5            ; DSM
        ADD     HL,DE
        LD      A,(HL)
        CP      0FFH
        LD      B,2
        JP      NZ,FAIL
        INC     HL
        LD      A,(HL)
        CP      07H
        LD      B,3
        JP      NZ,FAIL
        CALL    COUNT           ; the blocks that are used
        LD      (N1),DE
        LD      DE,FCB          ; a file of 40 records
        CALL    SETFCB
        LD      DE,FCB
        LD      C,19
        CALL    BDOS
        LD      DE,FCB
        LD      C,22
        CALL    BDOS
        INC     A
        LD      B,4
        JP      Z,FAIL
        LD      B,40
W1:     PUSH    BC
        LD      DE,FCB
        LD      C,21
        CALL    BDOS
        POP     BC
        DJNZ    W1
        LD      DE,FCB
        LD      C,16
        CALL    BDOS
        CALL    COUNT
        LD      (N2),DE
        LD      DE,FCB
        LD      C,19
        CALL    BDOS
        LD      HL,(N2)
        LD      DE,(N1)
        OR      A
        SBC     HL,DE
        LD      A,L
        CP      3
        LD      B,5
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
; DE = the number of bits that are set in the allocation vector
COUNT:  LD      C,27
        CALL    BDOS
        LD      B,0             ; 256 bytes
        LD      DE,0
CO1:    LD      A,(HL)
        LD      C,8
CO2:    RRCA
        JR      NC,CO3
        INC     DE
CO3:    DEC     C
        JR      NZ,CO2
        INC     HL
        DJNZ    CO1
        RET
SETFCB: LD      HL,FCB
        LD      B,36
SF1:    LD      (HL),0
        INC     HL
        DJNZ    SF1
        LD      HL,NAME
        LD      DE,FCB+1
        LD      BC,11
        LDIR
        RET
NAME:   DB      'ALC     WLD'
N1:     DW      0
N2:     DW      0
OK:     DB      'ALLOC OK',13,10,'$'
BAD:    DB      'ALLOC FAIL '
NUM:    DB      '0',13,10,'$'
FCB:    DS      36
DMA:    DS      128
