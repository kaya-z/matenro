; SPDX-License-Identifier: MIT
; i8088shim.asm - guest side of the CP/M-86 service of 摩天楼 (Matenro); nasm -f bin
; Credits: the BDOS entry INT E0h (CL = function, DX = parameter, AL / BX = result) is that of Digital Research's
; CP/M-86 (CP/M-86 System Guide).  The code is original.
;
; INT E0h is the CP/M-86 BDOS entry (CL = function, DX = parameter).  The stub copies CL, DX, DS and ES into
; the request block, rings the 6809 (OS-9 command `cpm`) and waits for the reply:
;   RQ+0 function  +1 DX  +4 DS  +6 ES  |  +8 AL  +9 BL  +10 BH  +11 AH  +12 done flag (written last by the 6809)
; The loader writes the initial registers into the launch block LB, the start code loads them and jumps to
; the program.  A program that ends with RETF (or RET in the 8080 model) arrives at EXITSTUB.
        bits 16
        cpu     8086
RQ      equ     0x600
LB      equ     0x620
        org     0x500
int_e0: mov     [cs:RQ+0], cl
        mov     [cs:RQ+1], dx
        mov     [cs:RQ+4], ds
        mov     [cs:RQ+6], es
        mov     byte [cs:RQ+12], 0
        xor     al, al
        out     2, al                   ; ring the 6809
.wait:  cmp     byte [cs:RQ+12], 0
        je      .wait
        mov     al, [cs:RQ+8]
        mov     ah, [cs:RQ+11]
        mov     bx, [cs:RQ+9]
        iret
        times   0x40-($-$$) db 0
start:  cli
        mov     ax, [cs:LB+8]
        mov     ss, ax
        mov     sp, [cs:LB+10]
        mov     ax, [cs:LB+6]
        mov     es, ax
        mov     ax, [cs:LB+4]
        mov     ds, ax
        jmp     far [cs:LB+0]
        times   0x40-($-start) db 0
exitstub:
        mov     cl, 0
        int     0xe0
