; wild.asm - CP/M-80 test: ? in the name for BDOS 15 (open: the first file that matches) and 19 (delete: all that match).
; Makes W1.WLD W2.WLD X1.WLD, deletes W?.WLD (A = 0), W?.WLD is gone (open fails), X?.WLD opens as X1.WLD, deletes X1.WLD,
; and ????????.WLD finds nothing (A = 255).  Prints "WILD OK" or "WILD FAIL n".
BDOS    EQU     5
        ORG     100H
        LD      DE,NW1
        CALL    MKFILE
        LD      DE,NW2
        CALL    MKFILE
        LD      DE,NX1
        CALL    MKFILE
        LD      DE,NWQ          ; delete W?.WLD
        CALL    SETFCB
        LD      DE,FCB
        LD      C,19
        CALL    BDOS
        OR      A
        LD      B,1
        JP      NZ,FAIL
        LD      DE,NWQ          ; open W?.WLD: none left
        CALL    SETFCB
        LD      DE,FCB
        LD      C,15
        CALL    BDOS
        INC     A
        LD      B,2
        JP      NZ,FAIL
        LD      DE,NXQ          ; open X?.WLD: X1
        CALL    SETFCB
        LD      DE,FCB
        LD      C,15
        CALL    BDOS
        INC     A
        LD      B,3
        JP      Z,FAIL
        LD      A,(FCB+2)       ; the name is X1 now
        CP      '1'
        LD      B,4
        JP      NZ,FAIL
        LD      DE,FCB
        LD      C,16
        CALL    BDOS
        LD      DE,NX1          ; delete X1.WLD
        CALL    SETFCB
        LD      DE,FCB
        LD      C,19
        CALL    BDOS
        OR      A
        LD      B,5
        JP      NZ,FAIL
        LD      DE,NALL         ; ????????.WLD: nothing
        CALL    SETFCB
        LD      DE,FCB
        LD      C,19
        CALL    BDOS
        INC     A
        LD      B,6
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
; the FCB with the name at DE (11 characters)
SETFCB: LD      HL,FCB
        LD      B,36
SF1:    LD      (HL),0
        INC     HL
        DJNZ    SF1
        LD      HL,FCB+1
        EX      DE,HL
        LD      BC,11
        LDIR
        RET
; make the file with the name at DE and close it
MKFILE: CALL    SETFCB
        LD      DE,FCB
        LD      C,22
        CALL    BDOS
        LD      DE,FCB
        LD      C,16
        CALL    BDOS
        RET
NW1:    DB      'W1      WLD'
NW2:    DB      'W2      WLD'
NX1:    DB      'X1      WLD'
NWQ:    DB      'W???????WLD'
NXQ:    DB      'X???????WLD'
NALL:   DB      '????????WLD'
OK:     DB      'WILD OK',13,10,'$'
BAD:    DB      'WILD FAIL '
NUM:    DB      '0',13,10,'$'
FCB:    DS      36
