; hello.asm - CP/M-80 test program: BDOS 9 (print string) and 2 (console output), command tail
        ORG     100H
        LD      DE,MSG
        LD      C,9
        CALL    5
        LD      E,'!'
        LD      C,2
        CALL    5
        LD      E,13
        LD      C,2
        CALL    5
        LD      E,10
        LD      C,2
        CALL    5
        LD      HL,80H          ; echo the command tail
        LD      A,(HL)
        OR      A
        JR      Z,DONE
        LD      B,A
        INC     HL
ECHO:   LD      E,(HL)
        PUSH    HL
        PUSH    BC
        LD      C,2
        CALL    5
        POP     BC
        POP     HL
        INC     HL
        DJNZ    ECHO
        LD      DE,CRLF
        LD      C,9
        CALL    5
DONE:   RET
MSG:    DB      "Hello from CP/M-80 on the Z80",13,10,"$"
CRLF:   DB      13,10,"$"
