; stk6.asm - CP/M-80 test program: the stack starts at (6) like in HI-TECH C (the first pushes go below the BDOS
; entry), the program ends with JP 0.  Two runs in a row check that nothing of the first run disturbs the second.
        ORG     100H
        LD      HL,(6)
        LD      SP,HL
        LD      HL,1234H
        PUSH    HL
        PUSH    HL
        PUSH    HL
        POP     HL
        POP     HL
        POP     HL
        LD      DE,MSG
        LD      C,9
        CALL    5
        JP      0
MSG:    DEFB    'stack at (6) ok',13,10,'$'
