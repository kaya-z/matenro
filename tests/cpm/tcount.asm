; tcount.asm - CP/M-80: count the CR and LF bytes the program sees when it reads IN.TXT (a text file) with
; sequential reads.  Prints "CR=nn LF=nn".
BDOS    EQU     5
        ORG     100H
        LD      DE,FIN
        LD      C,15
        CALL    BDOS
        INC     A
        JP      Z,NOFILE
        LD      DE,BUF
        LD      C,26
        CALL    BDOS
LOOP:   LD      DE,FIN
        LD      C,20
        CALL    BDOS
        OR      A
        JR      NZ,DONE
        LD      HL,BUF
        LD      B,128
SCAN:   LD      A,(HL)
        CP      13
        JR      NZ,NOTCR
        LD      A,(NCR)
        INC     A
        LD      (NCR),A
        JR      NEXT
NOTCR:  CP      10
        JR      NZ,NEXT
        LD      A,(NLF)
        INC     A
        LD      (NLF),A
NEXT:   INC     HL
        DJNZ    SCAN
        JR      LOOP
DONE:   LD      A,(NCR)
        CALL    TWO
        LD      (CRTXT),DE      ; two digits
        LD      A,(NLF)
        CALL    TWO
        LD      (LFTXT),DE
        LD      DE,MSG
        LD      C,9
        CALL    BDOS
        RET
NOFILE: LD      DE,NOMSG
        LD      C,9
        CALL    BDOS
        RET
; A (0..99) -> DE = two ASCII digits (tens in E, units in D so that LD (nn),DE stores tens first)
TWO:    LD      B,'0'
T10:    CP      10
        JR      C,TDONE
        SUB     10
        INC     B
        JR      T10
TDONE:  ADD     A,'0'
        LD      D,A
        LD      E,B
        RET
MSG:    DB      "CR="
CRTXT:  DB      "00 LF="
LFTXT:  DB      "00",13,10,"$"
NOMSG:  DB      "no IN.TXT",13,10,"$"
NCR:    DB      0
NLF:    DB      0
FIN:    DB      0,"IN      TXT",0,0,0,0
        DS      16
        DB      0,0,0,0
BUF:    DS      128
