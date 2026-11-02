; SPDX-License-Identifier: MIT
; z80shim.asm - guest side of the CP/M-80 service of 摩天楼 (Matenro), assembled with tools/z80asm.py
; Credits: the CP/M 2.2 memory layout (JP WBOOT at 0, JP BDOS at 5, BDOS entry at xx06, TPA at 0100h) and the register
; conventions of CALL 5 (C = function, DE = parameter, A / HL = result) are those of Digital Research's CP/M 2.2
; (CP/M 2.2 Interface Guide).  The code is original.
;
; The Z80 runs the CP/M program unchanged.  CALL 5 (BDOS) and a jump to 0 (warm boot) land here; the stub
; puts the function number and the parameter into the request block, rings the 6809 (OS-9 command `cpm`)
; with the doorbell and waits until the 6809 has filled in the reply.  The 6809 does the console I/O and
; the file I/O through OS-9.  Layout of the request block RQ (shared RAM):
;   +0 function (C)   +1 parameter DE (lo, hi)   +8 A   +9 L   +10 H   +12 done flag (written last by the 6809)
; BDOS sits at FC06h like in a 64K CP/M system with the BDOS at FC00h, so programs find the top of the TPA
; with LD HL,(6).  The six bytes below it belong to the program (a stack that starts at (6) uses them).
RQ      EQU     0FC80H
; FC00h..FC05h is left free: a program that starts its stack at (6) = FC06h (HI-TECH C does) pushes into it
        ORG     0FC00H
        DB      0,0,0,0,0,0
        ORG     0FC06H
BDOS:   LD      (RQ+1),DE
        LD      A,C
        LD      (RQ),A
CALLIT: XOR     A
        LD      (RQ+12),A       ; no reply yet
        OUT     (02H),A         ; ring the 6809
WAIT:   LD      A,(RQ+12)
        OR      A
        JR      Z,WAIT
        LD      HL,(RQ+9)       ; HL = result, A = low byte, B = high byte
        LD      A,(RQ+8)
        LD      B,H
        RET
; The BIOS: a jump table like the one of a CP/M 2.2 BIOS, found through the address at 0001h (the warm boot entry).
; Turbo Pascal calls CONST / CONIN / CONOUT this way instead of CALL 5.  Only the console is real; the disk
; entries do nothing (SELDSK gives HL = 0: no such disk).  Each entry asks the 6809 for the function 80h + its number
; (BC is the parameter, as DE is for CALL 5); the 6809 side is cpm.asm (bios).
        ORG     0FC2DH
        JP      WBOOT           ; 0 BOOT (the address at 1 is the next entry)
        JP      WBOOT           ; 1 WBOOT
        JP      BCONST          ; 2 CONST
        JP      BCONIN          ; 3 CONIN
        JP      BCONOUT         ; 4 CONOUT
        JP      BNULL           ; 5 LIST
        JP      BNULL           ; 6 PUNCH
        JP      BREADER         ; 7 READER
        JP      BNULL           ; 8 HOME
        JP      BNULL           ; 9 SELDSK
        JP      BNULL           ; 10 SETTRK
        JP      BNULL           ; 11 SETSEC
        JP      BNULL           ; 12 SETDMA
        JP      BNULL           ; 13 READ
        JP      BNULL           ; 14 WRITE
        JP      BNULL           ; 15 LISTST
        JP      BNULL           ; 16 SECTRAN
; (RQ, the request block, is at FC80h..FC8Ch)
        ORG     0FC90H
WBOOT:  XOR     A               ; function 0: system reset (program end)
        LD      (RQ),A
        JP      CALLIT
BCONST: LD      A,82H
        JR      BIOSF
BCONIN: LD      A,83H
        JR      BIOSF
BCONOUT: LD     A,84H
        JR      BIOSF
BREADER: LD     A,87H
BIOSF:  LD      (RQ),A
        LD      (RQ+1),BC
        JP      CALLIT
BNULL:  XOR     A
        LD      H,A
        LD      L,A
        RET
        ORG     0FCC0H
START:  LD      HL,BIOS1        ; the loader wrote JP START at 0 (the Z80 starts there); now 0 becomes JP (1)
        LD      (1),HL
        LD      SP,0FC00H
        LD      HL,0
        PUSH    HL              ; a RET at the end of the program goes to 0 = warm boot
        JP      0100H
BIOS1   EQU     0FC30H
