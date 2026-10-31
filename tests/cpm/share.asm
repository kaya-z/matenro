; share.asm - CP/M-80 test: the same file open through two FCBs (cpm gives them one OS-9 path), each with its own position.
; Makes SHARE.DAT (records 1, 2), opens it with FCB1 and FCB2, reads FCB1 (1), FCB2 (1), FCB1 (2), closes FCB2, reads FCB1
; (end of file), closes FCB1, deletes the file.  Prints "SHARE OK" or "SHARE FAIL n".
BDOS    EQU     5
        ORG     100H
        LD      DE,FCB1
        LD      C,19            ; delete (the result is ignored)
        CALL    BDOS
        LD      DE,FCB1
        LD      C,22            ; make
        CALL    BDOS
        INC     A
        LD      B,1
        JP      Z,FAIL
        LD      A,1
        LD      (REC),A
W1:     LD      HL,BUF
        LD      A,(REC)
        LD      B,128
W2:     LD      (HL),A
        INC     HL
        DJNZ    W2
        LD      DE,BUF
        LD      C,26
        CALL    BDOS
        LD      DE,FCB1
        LD      C,21            ; write sequential
        CALL    BDOS
        OR      A
        LD      B,2
        JP      NZ,FAIL
        LD      A,(REC)
        INC     A
        LD      (REC),A
        CP      3
        JR      NZ,W1
        LD      DE,FCB1
        LD      C,16            ; close
        CALL    BDOS
        XOR     A
        LD      (FCB1+12),A
        LD      (FCB1+32),A
        LD      DE,FCB1
        LD      C,15            ; open FCB1
        CALL    BDOS
        INC     A
        LD      B,3
        JP      Z,FAIL
        LD      HL,FCB1         ; FCB2 = a copy of the name, nothing else
        LD      DE,FCB2
        LD      BC,12
        LDIR
        LD      DE,FCB2
        LD      C,15            ; open FCB2 (the same file)
        CALL    BDOS
        INC     A
        LD      B,4
        JP      Z,FAIL
        LD      DE,FCB1
        LD      B,1             ; expect record 1
        CALL    RDREC
        LD      DE,FCB2
        LD      B,1             ; FCB2 has its own position: record 1 again
        CALL    RDREC
        LD      DE,FCB1
        LD      B,2             ; record 2
        CALL    RDREC
        LD      DE,FCB2
        LD      C,16            ; close FCB2: the path stays open for FCB1
        CALL    BDOS
        LD      DE,FCB1
        LD      C,20            ; read: end of file
        CALL    BDOS
        CP      1
        LD      B,5
        JP      NZ,FAIL
        LD      DE,FCB1
        LD      C,16
        CALL    BDOS
        LD      DE,FCB1
        LD      C,19
        CALL    BDOS
        LD      DE,OK
        LD      C,9
        CALL    BDOS
        RET
; read one record with the FCB in DE, expect all bytes = B (fails with 10 + B)
RDREC:  PUSH    BC
        PUSH    DE
        LD      DE,BUF
        LD      C,26
        CALL    BDOS
        POP     DE
        LD      C,20
        CALL    BDOS
        POP     BC
        OR      A
        JR      NZ,RDBAD
        LD      A,(BUF)
        CP      B
        JR      NZ,RDBAD
        LD      A,(BUF+127)
        CP      B
        RET     Z
RDBAD:  LD      A,B
        ADD     A,10
        LD      B,A
FAIL:   PUSH    BC
        LD      DE,BAD
        LD      C,9
        CALL    BDOS
        POP     BC
        LD      A,B
        ADD     A,'0'
        LD      E,A
        LD      C,2
        CALL    BDOS
        RET
OK:     DB      'SHARE OK',13,10,'$'
BAD:    DB      'SHARE FAIL ','$'
REC:    DB      0
FCB1:   DB      0,'SHARE   DAT',0,0,0,0
        DS      20
FCB2:   DS      36
BUF:    DS      128
