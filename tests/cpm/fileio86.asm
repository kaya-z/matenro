; fileio86.asm - CP/M-86 test, 8080 model: make, write seq (3 records), close, open, read seq, EOF, random read,
; compute file size, search first/next, delete.  Prints "FILEIO86 OK" or "FILEIO86 FAIL n".
        bits 16
        cpu     8086
        org     0x100
; conditional jumps to a far label: the 8086 has only 8 bit displacements
%macro  jzf 1
        jnz     %%skip
        jmp     %1
%%skip:
%endmacro
%macro  jnzf 1
        jz      %%skip
        jmp     %1
%%skip:
%endmacro
%macro  jnef 1
        je      %%skip
        jmp     %1
%%skip:
%endmacro
%macro  jef 1
        jne     %%skip
        jmp     %1
%%skip:
%endmacro
%macro  bdos 1
        mov     cl, %1
        int     0xe0
%endmacro
        mov     dx, fcb
        bdos    19                      ; delete (result ignored)
        mov     dx, fcb
        bdos    22                      ; make
        mov     bl, 1
        inc     al
        jzf     fail
        mov     byte [rec], 0
wloop:  mov     di, buf
        mov     al, [rec]
        inc     al
        mov     cx, 128
        rep stosb
        mov     dx, buf
        bdos    26                      ; set DMA offset
        mov     dx, fcb
        bdos    21                      ; write sequential
        mov     bl, 2
        or      al, al
        jnzf    fail
        inc     byte [rec]
        cmp     byte [rec], 3
        jne     wloop
        mov     dx, fcb
        bdos    16                      ; close
        mov     byte [fcb+12], 0
        mov     byte [fcb+32], 0
        mov     dx, fcb
        bdos    15                      ; open
        mov     bl, 3
        inc     al
        jzf     fail
        mov     byte [rec], 0
rloop:  mov     di, buf
        xor     al, al
        mov     cx, 128
        rep stosb
        mov     dx, buf
        bdos    26
        mov     dx, fcb
        bdos    20                      ; read sequential
        mov     bl, 4
        or      al, al
        jnzf    fail
        mov     al, [rec]
        inc     al
        mov     bl, 5
        cmp     al, [buf]
        jnef    fail
        mov     bl, 6
        cmp     al, [buf+127]
        jnef    fail
        mov     [rec], al
        cmp     al, 3
        jne     rloop
        mov     dx, fcb                 ; the 4th read: end of file
        bdos    20
        mov     bl, 7
        cmp     al, 1
        jnef    fail
        mov     byte [fcb+33], 1        ; random read of record 1
        mov     byte [fcb+34], 0
        mov     byte [fcb+35], 0
        mov     dx, fcb
        bdos    33
        mov     bl, 8
        or      al, al
        jnzf    fail
        mov     bl, 9
        cmp     byte [buf], 2
        jnef    fail
        mov     dx, fcb
        bdos    16
        mov     dx, fcb                 ; compute file size: 3 records
        bdos    35
        mov     bl, 11
        cmp     byte [fcb+33], 3
        jnef    fail
        mov     dx, buf
        bdos    26
        mov     dx, pat                 ; search for TEST*.*
        bdos    17
        mov     bl, 12
        cmp     al, 0xff
        jef     fail
        mov     si, buf+1
        mov     di, fcb+1
        mov     cx, 11
        mov     bl, 14
        repe cmpsb
        jnef    fail
        mov     dx, fcb                 ; delete
        bdos    19
        mov     bl, 15
        or      al, al
        jnzf    fail
        mov     dx, okmsg
        bdos    9
        ret
fail:   add     bl, '0'
        cmp     bl, '9'
        jbe     digit
        add     bl, 7
digit:  mov     [num], bl
        mov     dx, failmsg
        bdos    9
        ret
okmsg:  db      "FILEIO86 OK", 13, 10, "$"
failmsg: db     "FILEIO86 FAIL "
num:    db      "0", 13, 10, "$"
rec:    db      0
fcb:    db      0, "TEST    DAT", 0, 0, 0, 0
        times   16 db 0
        db      0, 0, 0, 0
pat:    db      0, "TEST????", "???", 0, 0, 0, 0
        times   16 db 0
        db      0, 0, 0, 0
buf:    times   128 db 0
