; kbpoll.asm - CP/M-80 test: ask for a key with BDOS 6 (E = 0FFH) and with BDOS 11, as the HI-TECH programs do.  When the
; standard input is a procedure file (shell <file) the program must not eat the lines of the file.  Prints "KBPOLL ok".
BDOS    EQU     5
        ORG     100H
        LD      E,0FFH
        LD      C,6
        CALL    BDOS
        LD      C,11
        CALL    BDOS
        LD      DE,OK
        LD      C,9
        CALL    BDOS
        RET
OK:     DB      'KBPOLL ok',13,10,'$'
