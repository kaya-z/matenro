; hello86.asm - CP/M-86 test program, 8080 model (one group, CS = DS = ES = SS, loaded at 0100h)
; BDOS 9 (print string), 2 (console output), the command tail at DS:0080, ends with a near RET
        bits 16
        cpu     8086
        org     0x100
        mov     dx, msg
        mov     cl, 9
        int     0xe0
        mov     dl, '!'
        mov     cl, 2
        int     0xe0
        mov     dx, crlf
        mov     cl, 9
        int     0xe0
        mov     si, 0x80
        mov     al, [si]
        or      al, al
        jz      done
        xor     ch, ch
        mov     bl, al
        xor     bh, bh
        inc     si
again:  mov     dl, [si]
        mov     cl, 2
        push    si
        push    bx
        int     0xe0
        pop     bx
        pop     si
        inc     si
        dec     bx
        jnz     again
        mov     dx, crlf
        mov     cl, 9
        int     0xe0
done:   ret
msg:    db      "Hello from CP/M-86 on the 8088", 13, 10, "$"
crlf:   db      13, 10, "$"
