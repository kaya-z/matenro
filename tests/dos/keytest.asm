; keytest.com - reads 5 keys with INT 16h AH=0 and prints "AAKK " (AH = scan code, AL = character, hex) for each, then "." (the check of the extended keys on the board)
        bits 16
        cpu     8086
        org     0x100
        mov     cx, 5
kl:     push    cx
        xor     ah, ah
        int     0x16
        mov     bx, ax
        mov     al, bh
        call    hex
        mov     al, bl
        call    hex
        mov     ah, 2
        mov     dl, ' '
        int     0x21
        pop     cx
        loop    kl
        mov     ah, 2
        mov     dl, '.'
        int     0x21
        int     0x20
hex:    push    ax
        mov     cl, 4
        shr     al, cl
        call    nib
        pop     ax
        and     al, 15
nib:    add     al, '0'
        cmp     al, '9'
        jbe     nb
        add     al, 7
nb:     mov     dl, al
        mov     ah, 2
        int     0x21
        ret
