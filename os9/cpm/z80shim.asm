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
        ORG     0FC30H
WBOOT:  XOR     A               ; function 0: system reset (program end)
        LD      (RQ),A
        JR      CALLIT
        ORG     0FC40H
START:  LD      HL,WBOOT        ; the loader wrote JP START at 0 (the Z80 starts there); now 0 becomes JP WBOOT
        LD      (1),HL
        LD      SP,0FC00H
        LD      HL,0
        PUSH    HL              ; a RET at the end of the program goes to 0 = warm boot
        JP      0100H
