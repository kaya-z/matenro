; bios.asm - CP/M-80 test: the console through the BIOS jump table at the address in 0001h (the warm boot entry; CONST is
; the next entry, CONIN the one after, CONOUT the one after that), as Turbo Pascal does.  Prints "BIOS " and "0" (CONST:
; no key), waits for a key (CONIN) and prints the next character and CR LF: "BIOS 0 y" for the key x; then a second key,
; which must be ESC: "ESC ok".
        ORG     100H
        LD      C,'B'
        CALL    CONOUT
        LD      C,'I'
        CALL    CONOUT
        LD      C,'O'
        CALL    CONOUT
        LD      C,'S'
        CALL    CONOUT
        LD      C,' '
        CALL    CONOUT
        CALL    CONST
        OR      A
        LD      C,'0'
        JR      Z,NOKEY
        LD      C,'1'
NOKEY:  CALL    CONOUT
        LD      C,' '
        CALL    CONOUT
        CALL    CONIN
        INC     A
        LD      C,A
        CALL    CONOUT
        LD      C,13
        CALL    CONOUT
        LD      C,10
        CALL    CONOUT
        CALL    CONIN           ; the second key is ESC (1Bh): the terminal must pass it (it is the end of file character of OS-9)
        CP      1BH
        LD      HL,ESCOK
        JR      Z,ESCOUT
        LD      HL,ESCBAD
ESCOUT: LD      C,(HL)
        INC     HL
        LD      A,C
        OR      A
        JR      Z,ESCEND
        PUSH    HL              ; (CONOUT below uses HL)
        CALL    CONOUT
        POP     HL
        JR      ESCOUT
ESCEND: RET
ESCOK:  DB      'ESC ok',13,10,0
ESCBAD: DB      'ESC lost',13,10,0
CONST:  LD      HL,(1)
        LD      DE,3
        ADD     HL,DE
        JP      (HL)
CONIN:  LD      HL,(1)
        LD      DE,6
        ADD     HL,DE
        JP      (HL)
CONOUT: LD      HL,(1)
        LD      DE,9
        ADD     HL,DE
        JP      (HL)
