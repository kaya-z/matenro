; ren.asm - CP/M-80 test: BDOS 23 (rename).  Makes A.TMP with one record, renames it to B.TMP, checks that B.TMP has the
; record and A.TMP is gone, and that a second rename of A.TMP fails.  Prints "REN OK" or "REN FAIL n".
BDOS    EQU     5
        ORG     100H
        LD      DE,F1           ; leftovers of an earlier run
        LD      C,19
        CALL    BDOS
        LD      DE,F2
        LD      C,19
        CALL    BDOS
        LD      DE,F1
        LD      C,22            ; make A.TMP
        CALL    BDOS
        INC     A
        LD      B,1
        JP      Z,FAIL
        LD      DE,DATA
        LD      C,26
        CALL    BDOS
        LD      DE,F1
        LD      C,21            ; write one record
        CALL    BDOS
        OR      A
        LD      B,2
        JP      NZ,FAIL
        LD      DE,F1
        LD      C,16
        CALL    BDOS
        LD      DE,RF           ; rename A.TMP B.TMP
        LD      C,23
        CALL    BDOS
        OR      A
        LD      B,3
        JP      NZ,FAIL
        LD      DE,F2
        LD      C,15            ; open B.TMP
        CALL    BDOS
        INC     A
        LD      B,4
        JP      Z,FAIL
        LD      DE,BUF
        LD      C,26
        CALL    BDOS
        LD      DE,F2
        LD      C,20            ; read the record
        CALL    BDOS
        OR      A
        LD      B,5
        JP      NZ,FAIL
        LD      A,(BUF)
        CP      'R'
        LD      B,6
        JP      NZ,FAIL
        LD      DE,F2
        LD      C,16
        CALL    BDOS
        LD      DE,F1
        LD      C,15            ; A.TMP must not be there
        CALL    BDOS
        INC     A
        LD      B,7
        JP      NZ,FAIL
        LD      DE,RF           ; so a second rename fails
        LD      C,23
        CALL    BDOS
        INC     A
        LD      B,8
        JP      NZ,FAIL
        LD      DE,F2
        LD      C,19
        CALL    BDOS
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
OK:     DB      'REN OK',13,10,'$'
BAD:    DB      'REN FAIL '
NUM:    DB      '0',13,10,'$'
F1:     DB      0,'A       ','TMP',0,0,0,0
        DS      20
F2:     DB      0,'B       ','TMP',0,0,0,0
        DS      20
RF:     DB      0,'A       ','TMP',0,0,0,0
        DB      0,'B       ','TMP',0,0,0,0
        DS      8
DATA:   DB      'RENAME TEST',0
        DS      116
BUF:    DS      128
