; gdirect.asm (MS-DOS .COM): the program writes the picture of the HDMI screen itself.  INT E2h (the BIOS, request 30: the same blocks as gdemo.asm) operation 9
; makes the blocks $50 and $51 of its memory (8 KB each: the segment $A000, offsets 0-$3FFF) the first two blocks of the picture; every byte of it gets the
; low byte of its offset (a gradient), then the picture is shown.   dos -v=2 -a=dosrun2.img -t=/d1/dostmp.img gdirect
        bits 16
        cpu     8086
        org     0x100
        mov     bx, m1
        int     0xe2
        mov     bx, m2
        int     0xe2
        mov     ax, 0xa000
        mov     es, ax
        xor     di, di
        mov     cx, 0x4000
fill:   mov     ax, di
        stosb
        loop    fill
        mov     bx, show
        int     0xe2
        mov     bx, u1
        int     0xe2
        mov     bx, u2
        int     0xe2
        int     0x20
m1:     dw      9, 0x50, 0, 0, 0, 0, 0
m2:     dw      9, 0x51, 1, 0, 0, 0, 0
show:   dw      7, 1, 0, 0, 0, 0, 0
u1:     dw      9, 0x50, 0xffff, 0, 0, 0, 0
u2:     dw      9, 0x51, 0xffff, 0, 0, 0, 0
