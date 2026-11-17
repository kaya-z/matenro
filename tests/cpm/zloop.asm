; zloop.asm - CP/M-80 test program: a Z80 loop that is bound by the CPU (40 times 65,536 turns of DEC HL / LD A,H / OR L / JR NZ, about 9 s at 7.7 MHz):
; the time of the run says how fast the Z80 really is with the memory of the board (time it with the wall clock: cpm zloop.com).
        ORG     100H
        LD      B,40
OUTER:  LD      HL,0
LOOP:   DEC     HL
        LD      A,H
        OR      L
        JR      NZ,LOOP
        DJNZ    OUTER
        JP      0
