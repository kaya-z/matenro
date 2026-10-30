; fileio.asm - CP/M-80 test: delete, make, write seq (3 records), close, open, read seq, EOF, random read,
; compute file size, search first / next, delete.  Prints "FILEIO OK" or "FILEIO FAIL n".
BDOS    EQU     5
        ORG     100H
        LD      DE,FCB
        LD      C,19            ; delete (the result is ignored)
        CALL    BDOS
        LD      DE,FCB
        LD      C,22            ; make
        CALL    BDOS
        INC     A
        LD      B,1
        JP      Z,FAIL
        XOR     A
        LD      (REC),A
WLOOP:  LD      HL,BUF
        LD      A,(REC)
        INC     A
        LD      B,128
FILL:   LD      (HL),A
        INC     HL
        DJNZ    FILL
        LD      DE,BUF
        LD      C,26            ; set DMA
        CALL    BDOS
        LD      DE,FCB
        LD      C,21            ; write sequential
        CALL    BDOS
        OR      A
        LD      B,2
        JP      NZ,FAIL
        LD      A,(REC)
        INC     A
        LD      (REC),A
        CP      3
        JR      NZ,WLOOP
        LD      DE,FCB
        LD      C,16            ; close
        CALL    BDOS
        XOR     A               ; reopen from the start
        LD      (FCB+12),A
        LD      (FCB+32),A
        LD      DE,FCB
        LD      C,15            ; open
        CALL    BDOS
        INC     A
        LD      B,3
        JP      Z,FAIL
        XOR     A
        LD      (REC),A
RLOOP:  LD      HL,BUF          ; clear the buffer
        LD      B,128
        XOR     A
CLR:    LD      (HL),A
        INC     HL
        DJNZ    CLR
        LD      DE,BUF
        LD      C,26
        CALL    BDOS
        LD      DE,FCB
        LD      C,20            ; read sequential
        CALL    BDOS
        OR      A
        LD      B,4
        JP      NZ,FAIL
        LD      A,(REC)
        INC     A
        LD      HL,BUF
        CP      (HL)
        LD      B,5
        JP      NZ,FAIL
        LD      HL,BUF+127
        CP      (HL)
        LD      B,6
        JP      NZ,FAIL
        LD      (REC),A
        CP      3
        JR      NZ,RLOOP
        LD      DE,FCB          ; the 4th read: end of file
        LD      C,20
        CALL    BDOS
        CP      1
        LD      B,7
        JP      NZ,FAIL
        LD      A,1             ; random read of record 1
        LD      (FCB+33),A
        XOR     A
        LD      (FCB+34),A
        LD      (FCB+35),A
        LD      DE,FCB
        LD      C,33
        CALL    BDOS
        OR      A
        LD      B,8
        JP      NZ,FAIL
        LD      A,(BUF)
        CP      2
        LD      B,9
        JP      NZ,FAIL
        LD      A,2             ; random write of record 3 (extends the file)
        LD      (FCB+33),A
        LD      HL,BUF
        LD      B,128
        LD      A,9
FILL9:  LD      (HL),A
        INC     HL
        DJNZ    FILL9
        LD      DE,FCB
        LD      C,34
        CALL    BDOS
        OR      A
        LD      B,10
        JP      NZ,FAIL
        LD      DE,FCB
        LD      C,16
        CALL    BDOS
        LD      DE,FCB          ; compute file size: 3 records
        LD      C,35
        CALL    BDOS
        LD      A,(FCB+33)
        CP      3
        LD      B,11
        JP      NZ,FAIL
        LD      DE,PAT          ; search for TEST*.*
        LD      C,17
        CALL    BDOS
        CP      0FFH
        LD      B,12
        JP      Z,FAIL
        LD      DE,BUF
        LD      C,26
        CALL    BDOS
        LD      DE,PAT
        LD      C,17
        CALL    BDOS
        OR      A
        LD      B,13
        JP      NZ,FAIL
        LD      HL,BUF+1        ; the name in the directory entry
        LD      DE,FCB+1
        LD      B,11
CMPN:   LD      A,(DE)
        CP      (HL)
        PUSH    BC
        LD      B,14
        JP      NZ,FAIL
        POP     BC
        INC     HL
        INC     DE
        DJNZ    CMPN
        LD      DE,FCB          ; delete the file again
        LD      C,19
        CALL    BDOS
        OR      A
        LD      B,15
        JP      NZ,FAIL
        LD      DE,OKMSG
        LD      C,9
        CALL    BDOS
        RET
FAIL:   LD      A,B
        ADD     A,'0'
        CP      '9'+1
        JR      C,DIGIT
        ADD     A,7
DIGIT:  LD      (NUM),A
        LD      DE,FAILMSG
        LD      C,9
        CALL    BDOS
        RET
OKMSG:  DB      "FILEIO OK",13,10,"$"
FAILMSG: DB     "FILEIO FAIL "
NUM:    DB      "0",13,10,"$"
REC:    DB      0
FCB:    DB      0,"TEST    DAT",0,0,0,0
        DS      16
        DB      0,0,0,0
PAT:    DB      0,"TEST????","???",0,0,0,0
        DS      16
        DB      0,0,0,0
BUF:    DS      128
