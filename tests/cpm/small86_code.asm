; small86_code.asm / small86_data.asm - CP/M-86 test program, small model: separate code group (CS) and data
; group (DS = ES = SS).  The code is assembled at 0, the data at 0100h.  Ends with RETF to the loader.
        bits 16
        cpu     8086
        org     0
MSG     equ     0x100
        mov     dx, MSG
        mov     cl, 9
        int     0xe0
        mov     cl, 12              ; BDOS 12: version number
        int     0xe0
        cmp     bx, 0x1022
        jne     bad
        mov     dx, MSG2
        mov     cl, 9
        int     0xe0
        retf
bad:    mov     dx, MSG3
        mov     cl, 9
        int     0xe0
        retf
MSG2    equ     0x100+0x24
MSG3    equ     0x100+0x3f
