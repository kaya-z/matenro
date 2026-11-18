; stars88.asm (a bare 8088 program, no DOS) - the 8088 half of the star field demo: 128 stars in three layers (speeds 1, 2, 3 pixels per frame) fly
; to the left through the upper 204 rows of the picture of the HDMI screen.  Only the pixels of the stars are written (erased, moved, drawn), not the whole
; picture.  The 6809 (ball09, os9/demo) draws the bouncing ball and the text.  The 8088 writes the picture itself: "ball09 s" has mapped the blocks $50-$57 of
; its memory (the segment A000h, 64 KB = 204 rows) to the first eight blocks of the picture.  Pixel 0 is the command: the 6809 writes 254 to stop it.
;   subsel 8088 ; ball09 s ; xrun -l=400 stars88.bin ; ball09 r
        bits 16
        cpu     8086
        org     0x400
NST     equ     128
DELAY   equ     3000
        cli
        xor     ax, ax
        mov     ds, ax
        mov     ss, ax
        mov     sp, 0x7000
        mov     ax, 0xa000
        mov     es, ax
        mov     word [seed], 0x1234
        xor     si, si                  ; the tables of the stars: x, y * 320 (words), the speed (byte)
        xor     di, di
        mov     cx, NST
init:   call    rnd
        xor     dx, dx
        mov     bx, 320
        div     bx
        mov     [sx+si], dx
        call    rnd
        xor     dx, dx
        mov     bx, 203
        div     bx
        inc     dx                      ; the rows 1 ... 203 (pixel 0 is the command)
        mov     ax, dx
        mov     bx, 320
        mul     bx
        mov     [soff+si], ax
        call    rnd
        xor     dx, dx
        mov     bx, 3
        div     bx
        inc     dx
        mov     [ssp+di], dl
        add     si, 2
        inc     di
        dec     cx
        jnz     init
frame:  cmp     byte [es:0], 254
        je      halt
        xor     si, si
        xor     di, di
        mov     cx, NST
star:   mov     bx, [soff+si]           ; erase
        add     bx, [sx+si]
        mov     byte [es:bx], 0
        mov     al, [ssp+di]
        xor     ah, ah
        mov     dx, [sx+si]             ; move to the left, round again from the right
        sub     dx, ax
        jns     ok
        add     dx, 320
ok:     mov     [sx+si], dx
        add     dx, [soff+si]
        mov     bx, dx
        add     al, 199                 ; the colours 200 ... 202
        mov     [es:bx], al
        add     si, 2
        inc     di
        dec     cx
        jnz     star
        mov     cx, DELAY
wt:     loop    wt
        jmp     frame
halt:   hlt
        jmp     halt
rnd:    push    cx
        mov     ax, [seed]
        mov     cx, 25173
        mul     cx
        add     ax, 13849
        mov     [seed], ax
        mov     cl, 3
        shr     ax, cl
        pop     cx
        ret
seed:   dw      0
sx:     times   NST dw 0
soff:   times   NST dw 0
ssp:    times   NST db 0
