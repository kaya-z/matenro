; line.asm - CP/M-80 test: BDOS 10 (read console buffer), BDOS 1 (console input) and 6 (direct I/O)
BDOS    EQU     5
        ORG     100H
        LD      DE,PROMPT
        LD      C,9
        CALL    BDOS
        LD      DE,BUF          ; read console buffer
        LD      C,10
        CALL    BDOS
        LD      DE,OPEN
        LD      C,9
        CALL    BDOS
        LD      A,(BUF+1)       ; length
        LD      B,A
        OR      A
        JR      Z,SHOWN
        LD      HL,BUF+2
SHOW:   LD      E,(HL)
        PUSH    HL
        PUSH    BC
        LD      C,2
        CALL    BDOS
        POP     BC
        POP     HL
        INC     HL
        DJNZ    SHOW
SHOWN:  LD      DE,CLOSE
        LD      C,9
        CALL    BDOS
        LD      C,1             ; one character
        CALL    BDOS
        LD      (CH),A
        LD      DE,GOT
        LD      C,9
        CALL    BDOS
        LD      A,(CH)
        LD      E,A
        LD      C,6             ; direct console output
        CALL    BDOS
        LD      DE,CRLF
        LD      C,9
        CALL    BDOS
        RET
PROMPT: DB      "Name? $"
OPEN:   DB      13,10,"[$"
CLOSE:  DB      "]",13,10,"$"
GOT:    DB      "key=$"
CRLF:   DB      13,10,"$"
CH:     DB      0
BUF:    DB      40,0
        DS      42
