; tcat.asm - CP/M-80 filter: copy STDIN to STDOUT through FCBs named STDIN / STDOUT (text mode: the OS-9 side
; turns CR into CR LF on the way in and CR LF into CR on the way out), and to the text file OUT.TXT as well.
BDOS    EQU     5
        ORG     100H
        LD      DE,FIN
        LD      C,15            ; open STDIN
        CALL    BDOS
        LD      DE,FOUT
        LD      C,22            ; make STDOUT
        CALL    BDOS
        LD      DE,FTXT
        LD      C,22            ; make OUT.TXT
        CALL    BDOS
        LD      DE,BUF
        LD      C,26
        CALL    BDOS
LOOP:   LD      DE,FIN
        LD      C,20            ; read sequential
        CALL    BDOS
        OR      A
        JR      NZ,DONE
        LD      DE,FOUT
        LD      C,21
        CALL    BDOS
        LD      DE,FTXT
        LD      C,21
        CALL    BDOS
        JR      LOOP
DONE:   LD      DE,FTXT
        LD      C,16
        CALL    BDOS
        LD      DE,FOUT
        LD      C,16
        CALL    BDOS
        RET
FIN:    DB      0,"STDIN   ","   ",0,0,0,0
        DS      16
        DB      0,0,0,0
FOUT:   DB      0,"STDOUT  ","   ",0,0,0,0
        DS      16
        DB      0,0,0,0
FTXT:   DB      0,"OUT     TXT",0,0,0,0
        DS      16
        DB      0,0,0,0
BUF:    DS      128
