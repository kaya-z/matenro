; SPDX-License-Identifier: MIT
; HOSTOUT.COM - run mode of `dos`: copy the files of the disk back to the OS-9 directory, then leave DOS
;   nasm -f bin hostout.asm -o hostout.com
        bits    16
        cpu     8086
        org     0x100
        jmp     start
%include "hostcom.inc"

start:  cld
        call    getver
        push    ds
        pop     es
        mov     di, sfcb                ; the search FCB: all files of the root directory
        mov     cx, 37
        xor     al, al
        rep     stosb
        mov     di, sfcb+1
        mov     cx, 11
        mov     al, '?'
        rep     stosb
        mov     dx, dta
        mov     ah, 0x1a
        int     0x21
        mov     dx, sfcb
        mov     ah, 0x11
        int     0x21
more:   test    al, al
        jnz     finish
        test    byte [dta+12], 0x18     ; a directory or the volume label
        jnz     again
        mov     si, dta+1
        call    isskip
        test    al, al
        jnz     again
        mov     si, dta+1               ; remember name and size, the search goes on afterwards
        mov     di, nm
        mov     cx, 11
        rep     movsb
        mov     ax, [dta+29]
        mov     [size], ax
        mov     ax, [dta+31]
        mov     [size+2], ax
        call    export
        mov     dx, dta
        mov     ah, 0x1a
        int     0x21
again:  mov     dx, sfcb
        mov     ah, 0x12
        int     0x21
        jmp     more
finish: mov     al, 25
        call    req
        jmp     $

export: mov     al, 21                  ; create the OS-9 file
        mov     bx, nm
        mov     dx, 1
        call    req
        test    al, al
        jnz     .r
        mov     di, fcb
        mov     cx, 37
        xor     al, al
        push    ds
        pop     es
        rep     stosb
        mov     si, nm
        mov     di, fcb+1
        mov     cx, 11
        rep     movsb
        mov     dx, fcb
        mov     ah, 0x0f
        int     0x21
        test    al, al
        jnz     .c
        mov     word [fcb+0x0e], 1
        mov     word [off], 0
        mov     word [off+2], 0
.l:     mov     ax, [size]              ; remaining = size - off
        mov     dx, [size+2]
        sub     ax, [off]
        sbb     dx, [off+2]
        mov     cx, 512
        test    dx, dx
        jnz     .go
        cmp     ax, 512
        jae     .go
        mov     cx, ax
.go:    test    cx, cx
        jz      .c
        mov     [cnt], cx
        mov     ax, [off]
        mov     [fcb+0x21], ax
        mov     ax, [off+2]
        mov     [fcb+0x23], ax
        mov     dx, databuf
        mov     ah, 0x1a
        int     0x21
        mov     dx, fcb
        mov     cx, [cnt]
        mov     ah, 0x27
        int     0x21
        cmp     al, 1
        je      .c
        mov     al, 23
        mov     bx, databuf
        mov     cx, [cnt]
        call    req
        mov     ax, [cnt]
        add     [off], ax
        adc     word [off+2], 0
        jmp     .l
.c:     mov     dx, fcb
        mov     ah, 0x10
        int     0x21
        mov     al, 24
        call    req
.r:     ret

cnt:    dw      0
off:    dw      0, 0
size:   dw      0, 0
nm:     times 11 db 0
sfcb:   times 37 db 0
fcb:    times 37 db 0
dta:    times 48 db 0
databuf: times 512 db 0
