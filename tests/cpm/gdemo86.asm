; gdemo86.asm - CP/M-86 test program, 8080 model: the graphics of the HDMI screen of the Tang Nano 20K (BDOS 112, see os9/cpm/cpmgfx.asm):
; the same picture as gdemo.asm
        bits 16
        cpu     8086
        org     0x100
        mov     si, tab
        mov     bx, 8
loop:   mov     dx, [si]
        add     si, 2
        push    si
        push    bx
        mov     cl, 112
        int     0xe0
        pop     bx
        pop     si
        dec     bx
        jnz     loop
        ret
tab:    dw      b1, b2, b3, b4, b5, b6, b7, b8
b1:     dw      6, 0, 0, 0, 0, 0, 0
b2:     dw      4, 10, 10, 50, 30, 28, 0
b3:     dw      3, 5, 5, 100, 60, 255, 0
b4:     dw      2, 0, 0, 319, 239, 7, 0
b5:     dw      2, 319, 0, 0, 239, 224, 0
b6:     dw      1, 160, 120, 0, 0, 255, 0
b7:     dw      5, 8, 160, 0, 0, 255, 16
        db      'Hello from CP/M-86', 0
b8:     dw      7, 3, 0, 0, 0, 0, 0
