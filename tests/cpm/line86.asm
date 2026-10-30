; line86.asm - CP/M-86 test, 8080 model: BDOS 10 (read console buffer), 1 (console input), 6 (direct output)
        bits 16
        cpu     8086
        org     0x100
%macro  bdos 1
        mov     cl, %1
        int     0xe0
%endmacro
        mov     dx, prompt
        bdos    9
        mov     dx, buf
        bdos    10
        mov     dx, open
        bdos    9
        mov     al, [buf+1]
        xor     bh, bh
        mov     bl, al
        or      bl, bl
        jz      shown
        mov     si, buf+2
show:   mov     dl, [si]
        push    si
        push    bx
        bdos    2
        pop     bx
        pop     si
        inc     si
        dec     bx
        jnz     show
shown:  mov     dx, closem
        bdos    9
        bdos    1                       ; one character
        mov     [keych], al
        mov     dx, got
        bdos    9
        mov     dl, [keych]
        bdos    6                       ; direct console output
        mov     dx, crlf
        bdos    9
        ret
prompt: db      "Name? $"
open:   db      13, 10, "[$"
closem: db      "]", 13, 10, "$"
got:    db      "key=$"
crlf:   db      13, 10, "$"
keych: db      0
buf:    db      40, 0
        times   42 db 0
