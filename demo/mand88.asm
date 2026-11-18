; mand88.asm (a bare 8088 program, no DOS) - the 8088 half of the Mandelbrot race (demo): the upper 120 rows of the picture of the HDMI screen, from
; the middle up.  The other half is drawn by the 6809 (mand09, os9/demo): the lower 120 rows, from the middle down.  The picture is the mirror image,
; so both have the same work.  xrun loads this at $400 and starts it; before that "mand09 s" has mapped the blocks $50-$54 of the 8088 memory (the
; segment A000h) to the first five blocks of the frame buffer (the 8088 writes the picture itself).  The 8088 waits until the 6809 writes 253 (go)
; into pixel 0; pixel 319 (the last of the row 0, the last thing that is drawn) shows the 6809 that the 8088 has finished (it was 255 before).
;   subsel 8088 ; mand09 s ; xrun -l=400 mand88.bin ; mand09 r
; Fixed point with 8 fraction bits like duo (os9/duo): z = x + yi, c = ca + cb i, ca = -2.25 + 3/256 per column, cb = +-(3 k + 1)/256 per row k from the middle.
        bits 16
        cpu     8086
        org     0x400
MAXIT   equ     24
        cli
        xor     ax, ax
        mov     ds, ax
        mov     ss, ax
        mov     sp, 0x7000
        mov     ax, 0xa000
        mov     es, ax
wgo:    cmp     byte [es:0], 253        ; go
        jne     wgo
        mov     word [k], 0
rowlp:  mov     ax, [k]
        mov     bx, ax
        shl     ax, 1
        add     ax, bx
        inc     ax
        neg     ax                      ; cb = -(3 k + 1)
        mov     [cb], ax
        mov     ax, 119
        sub     ax, bx                  ; the row y = 119 - k
        mov     cx, 320
        mul     cx
        mov     [dst], ax
        mov     word [ca], -576
        mov     word [cols], 320
pixlp:  mov     si, [ca]
        mov     di, [cb]
        xor     cl, cl
iter:   mov     ax, si                  ; a2 = a * a
        imul    ax
        mov     al, ah
        mov     ah, dl
        mov     bx, ax
        mov     ax, di                  ; b2 = b * b
        imul    ax
        mov     al, ah
        mov     ah, dl
        mov     bp, ax
        mov     ax, bx
        add     ax, bp
        cmp     ax, 1025                ; a2 + b2 > 4
        jge     esc
        mov     ax, si                  ; b = 2 a b + cb
        imul    di
        mov     al, ah
        mov     ah, dl
        shl     ax, 1
        add     ax, [cb]
        mov     di, ax
        mov     ax, bx                  ; a = a2 - b2 + ca
        sub     ax, bp
        add     ax, [ca]
        mov     si, ax
        inc     cl
        cmp     cl, MAXIT
        jb      iter
        xor     al, al                  ; inside: colour 0
        jmp     put
esc:    mov     al, cl
        inc     al
put:    mov     bx, [dst]
        mov     [es:bx], al
        inc     word [dst]
        add     word [ca], 3
        dec     word [cols]
        jnz     pixlp
        inc     word [k]
        cmp     word [k], 120
        jb      rowlp
halt:   hlt
        jmp     halt
k:      dw      0
ca:     dw      0
cb:     dw      0
dst:    dw      0
cols:   dw      0
