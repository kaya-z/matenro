; SPDX-License-Identifier: MIT
; HOSTIN.COM - run mode of `dos`: copy the files of the OS-9 directory to the disk, write RUNJOB.BAT (docs/MANUAL.md 6.8)
;   nasm -f bin hostin.asm -o hostin.com
        bits    16
        cpu     8086
        org     0x100
        jmp     start
%include "hostcom.inc"

start:  cld
        call    getver
        mov     al, 26                  ; the command line
        mov     bx, cmdbuf
        xor     cx, cx
        xor     dx, dx
        call    req
        mov     al, 20                  ; start the directory
        mov     bx, dirbuf
        xor     cx, cx
        call    req
next:   mov     al, 20
        mov     bx, dirbuf
        mov     cx, 1
        call    req
        cmp     al, 1
        je      jobfile
        mov     si, dirbuf
        call    isskip
        test    al, al
        jnz     next
        mov     al, 21                  ; open for reading
        mov     bx, dirbuf
        xor     dx, dx
        call    req
        test    al, al
        jnz     next
        mov     di, fcb                 ; the file on the disk
        mov     cx, 37
        xor     al, al
        push    ds
        pop     es
        rep     stosb
        mov     si, dirbuf
        mov     di, fcb+1
        mov     cx, 11
        rep     movsb
        mov     dx, fcb
        mov     ah, 0x16
        int     0x21
        test    al, al
        jnz     full
        mov     word [fcb+0x0e], 1      ; record size 1: the sizes are exact
        mov     word [off], 0
        mov     word [off+2], 0
copy:   mov     al, 22
        mov     bx, databuf
        mov     cx, 512
        call    req
        test    cx, cx
        jz      endf
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
        mov     ah, 0x28
        int     0x21
        test    al, al
        jnz     full
        mov     ax, [cnt]
        add     [off], ax
        adc     word [off+2], 0
        jmp     copy
full:   mov     dx, msgfull
        call    puts
endf:   mov     dx, fcb
        mov     ah, 0x10
        int     0x21
        mov     al, 24
        call    req
        jmp     next

; RUNJOB.BAT: the command line, then HOSTOUT
jobfile: mov    di, fcb
        mov     cx, 37
        xor     al, al
        push    ds
        pop     es
        rep     stosb
        mov     si, jobnm
        mov     di, fcb+1
        mov     cx, 11
        rep     movsb
        mov     dx, fcb
        mov     ah, 0x16
        int     0x21
        mov     word [fcb+0x0e], 1
        mov     si, cmdbuf              ; the batch text: the command line (up to the CR), CR LF, HOSTOUT CR LF
        mov     di, jobbuf
.c:     lodsb
        cmp     al, 13
        je      .e
        stosb
        jmp     .c
.e:     mov     al, 13
        stosb
        mov     al, 10
        stosb
        mov     si, hostout
        mov     cx, hostoutn
        rep     movsb
        mov     cx, di
        sub     cx, jobbuf
        mov     word [fcb+0x21], 0
        mov     word [fcb+0x23], 0
        mov     dx, jobbuf
        mov     ah, 0x1a
        int     0x21
        mov     dx, fcb
        mov     ah, 0x28
        int     0x21
        mov     dx, fcb
        mov     ah, 0x10
        int     0x21
        int     0x20

jobnm:  db      'RUNJOB  BAT'
hostout: db     'HOSTOUT', 13, 10
hostoutn equ    $ - hostout
msgfull: db     'HOSTIN: the disk is full', 13, 10, '$'
cnt:    dw      0
off:    dw      0, 0
fcb:    times 37 db 0
dirbuf: times 16 db 0
cmdbuf: times 130 db 0
jobbuf: times 160 db 0
databuf: times 512 db 0
