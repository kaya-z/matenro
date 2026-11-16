; gdirect86.asm - CP/M-86 test program, 8080 model: the 8088 writes the picture of the HDMI screen itself (see gdirect.asm for the Z80).  BDOS 112
; operation 9 makes the blocks $50 and $51 of its memory (8 KB each: the segment $A000, offsets 0-$3FFF) the first two blocks of the picture;
; every byte of it gets the low byte of its offset (a gradient), then the picture is shown.
        bits 16
        cpu     8086
        org     0x100
        mov     dx, m1
        mov     cl, 112
        int     0xe0
        mov     dx, m2
        mov     cl, 112
        int     0xe0
        mov     ax, 0xa000
        mov     es, ax
        xor     di, di
        mov     cx, 0x4000
fill:   mov     ax, di
        stosb
        loop    fill
        mov     dx, show
        mov     cl, 112
        int     0xe0
        mov     dx, u1
        mov     cl, 112
        int     0xe0
        mov     dx, u2
        mov     cl, 112
        int     0xe0
        push    ds
        pop     es
        ret
m1:     dw      9, 0x50, 0, 0, 0, 0, 0
m2:     dw      9, 0x51, 1, 0, 0, 0, 0
show:   dw      7, 1, 0, 0, 0, 0, 0
u1:     dw      9, 0x50, 0xffff, 0, 0, 0, 0
u2:     dw      9, 0x51, 0xffff, 0, 0, 0, 0
