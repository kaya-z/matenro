; twrite.asm - CP/M-80: write the text "ab CR LF cd CR LF ^Z" as one record into the text file NEW.TXT.
; The OS-9 side stores it as "ab CR cd CR" (the host sees LF for CR).
BDOS    EQU     5
        ORG     100H
        LD      DE,FCB
        LD      C,19            ; delete an old NEW.TXT
        CALL    BDOS
        LD      DE,FCB
        LD      C,22            ; make
        CALL    BDOS
        LD      HL,TEXT         ; fill the record buffer with ^Z, then the text
        LD      DE,BUF
        LD      BC,TEXTLEN
        LDIR
        LD      DE,BUF
        LD      C,26
        CALL    BDOS
        LD      DE,FCB
        LD      C,21
        CALL    BDOS
        LD      DE,FCB
        LD      C,16
        CALL    BDOS
        RET
TEXT:   DB      "ab",13,10,"cd",13,10,1AH
TEXTLEN EQU     $-TEXT
FCB:    DB      0,"NEW     TXT",0,0,0,0
        DS      16
        DB      0,0,0,0
BUF:    DS      128
