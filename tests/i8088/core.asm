; SPDX-License-Identifier: MIT
; core.asm - self checking test of the 8088 core (src/i8088.c)
; Expected values were derived by hand from the Intel 8086 family manual.
; Build: nasm -f bin core.asm -o core.bin     (run by tests/i8088_test.c)
; The EQ* checks preserve the flags, so they can sit between an instruction and its FLAGS check.
; A failing check puts its id on port 0x0E and powers off with $A6; success powers off with $A5.
        bits 16
        cpu     8086
        org  0x400

%macro EQAX 2                   ; EQAX value, id
        pushf
        cmp  ax, %1
        je   %%ok
        mov  al, %2
        jmp  fail
%%ok:
        popf
%endmacro
%macro EQAL 2
        pushf
        cmp  al, %1
        je   %%ok
        mov  al, %2
        jmp  fail
%%ok:
        popf
%endmacro
%macro EQMEMB 3                 ; EQMEMB address, value, id
        pushf
        cmp  byte [%1], %2
        je   %%ok
        mov  al, %3
        jmp  fail
%%ok:
        popf
%endmacro
%macro EQMEMW 3
        pushf
        cmp  word [%1], %2
        je   %%ok
        mov  al, %3
        jmp  fail
%%ok:
        popf
%endmacro
%macro FLAGS 3                  ; FLAGS mask, value, id  (does not touch registers)
        pushf
        pop  word [tmp]
        and  word [tmp], %1
        cmp  word [tmp], %2
        je   %%ok
        mov  al, %3
        jmp  fail
%%ok:
%endmacro
CF equ 0x001
PF equ 0x004
AF equ 0x010
ZF equ 0x040
SF  equ 0x080
OF  equ 0x800
ALLF equ 0x8d5

tmp     equ 0x3000
buf     equ 0x3100
src     equ 0x3200
dst     equ 0x3300
derr    equ 0x3400
tbl     equ 0x3500

start:
        xor  ax, ax
        mov  ds, ax
        mov  es, ax
        mov  ss, ax
        mov  sp, 0xf000
        ; vector 0 (divide error) and vector 0x40 (test INT)
        mov  word [0*4], div_handler
        mov  word [0*4+2], cs
        mov  word [0x40*4], int_handler
        mov  word [0x40*4+2], cs
        mov  word [4*4], into_handler
        mov  word [4*4+2], cs

; ---------------- ALU flags ----------------
        mov  al, 0x7f
        add  al, 1
        EQAL 0x80, 1
        FLAGS ALLF, OF|SF|AF, 2
        mov  al, 0xff
        add  al, 1
        EQAL 0, 3
        FLAGS ALLF, CF|ZF|AF|PF, 4
        mov  ax, 0x8000
        sub  ax, 1
        EQAX 0x7fff, 5
        FLAGS ALLF, OF|AF|PF, 6
        stc
        mov  al, 5
        adc  al, 3
        EQAL 9, 7
        FLAGS ALLF, PF, 8
        stc
        mov  al, 0
        sbb  al, 0
        EQAL 0xff, 9
        FLAGS ALLF, CF|SF|AF|PF, 10
        mov  al, 0x80
        neg  al
        EQAL 0x80, 11
        FLAGS ALLF, OF|CF|SF, 12
        stc
        mov  ax, 0xffff
        inc  ax
        EQAX 0, 13
        FLAGS ALLF, CF|ZF|AF|PF, 14             ; INC keeps CF
        mov  al, 0x7f
        inc  al
        FLAGS OF|SF, OF|SF, 15
        mov  al, 0x80
        dec  al
        FLAGS OF|SF, OF, 16
        mov  al, 0xf0
        and  al, 0x0f
        FLAGS ALLF, ZF|PF, 17
        mov  al, 5
        mov  bl, 7
        cmp  al, bl
        FLAGS ALLF, CF|SF|AF, 18
        mov  ax, 0x1234
        xor  ax, ax
        FLAGS ALLF, ZF|PF, 19
        mov  al, 0x80
        test al, 0x80
        FLAGS ALLF, SF, 20
        mov  ax, 0xffff
        add  ax, 0xffff
        EQAX 0xfffe, 21
        FLAGS ALLF, CF|SF|AF, 22
        mov  bx, 0x1234
        add  bx, byte -1                         ; 83 /0 sign extended imm8
        mov  ax, bx
        EQAX 0x1233, 23

; ---------------- shifts and rotates ----------------
        mov  al, 0x81
        shl  al, 1
        EQAL 0x02, 24
        FLAGS CF|OF|ZF|SF|PF, CF|OF, 25
        mov  al, 0x81
        shr  al, 1
        EQAL 0x40, 26
        FLAGS CF|OF|ZF|SF|PF, CF|OF, 27
        mov  al, 0x81
        sar  al, 1
        EQAL 0xc0, 28
        FLAGS CF|OF|ZF|SF|PF, CF|SF|PF, 29
        mov  al, 0x81
        rol  al, 1
        EQAL 0x03, 30
        FLAGS CF|OF, CF|OF, 31
        mov  al, 0x01
        ror  al, 1
        EQAL 0x80, 32
        FLAGS CF|OF, CF|OF, 33
        clc
        mov  al, 0x80
        rcl  al, 1
        EQAL 0, 34
        FLAGS CF, CF, 35
        stc
        mov  al, 0
        rcr  al, 1
        EQAL 0x80, 36
        FLAGS CF, 0, 37
        mov  cl, 4
        mov  ax, 0x1234
        shl  ax, cl
        EQAX 0x2340, 38
        mov  cl, 9
        mov  ax, 0x1234
        shr  ax, cl
        EQAX 0x0009, 39
        mov  cl, 12
        mov  ax, 0x8001
        rol  ax, cl
        EQAX 0x1800, 40
        stc
        mov  cl, 0
        mov  ax, 0x1234
        shl  ax, cl                              ; count 0: nothing changes
        FLAGS CF, CF, 41
        mov  bx, 0x8000
        sar  bx, 1
        mov  ax, bx
        EQAX 0xc000, 42

; ---------------- multiply / divide ----------------
        mov  al, 0x10
        mov  bl, 0x10
        mul  bl
        EQAX 0x0100, 43
        FLAGS CF|OF, CF|OF, 44
        mov  al, 0x7f
        mov  bl, 2
        mul  bl
        EQAX 0x00fe, 45
        FLAGS CF|OF, 0, 46
        mov  ax, 0x1234
        mov  bx, 0x100
        mul  bx
        EQAX 0x3400, 47
        cmp  dx, 0x0012
        je   .m1
        mov  al, 48
        jmp  fail
.m1:    mov  al, 0xff
        mov  bl, 2
        imul bl
        EQAX 0xfffe, 49
        FLAGS CF|OF, 0, 50
        mov  al, 0x80
        mov  bl, 0x80
        imul bl
        EQAX 0x4000, 51
        FLAGS CF|OF, CF|OF, 52
        mov  ax, 100
        mov  bl, 7
        div  bl
        EQAX 0x020e, 53                          ; AL=14 AH=2
        mov  dx, 1
        xor  ax, ax
        mov  bx, 3
        div  bx
        EQAX 0x5555, 54
        cmp  dx, 1
        je   .m2
        mov  al, 55
        jmp  fail
.m2:    mov  ax, 0xff9c                          ; -100
        mov  bl, 7
        idiv bl
        EQAX 0xfef2, 56                          ; AL=-14 AH=-2
        mov  ax, -1000
        cwd
        mov  bx, 30
        idiv bx
        EQAX 0xffdf, 57                          ; -33
        cmp  dx, 0xfff6                          ; -10
        je   .m3
        mov  al, 58
        jmp  fail
.m3:    mov  byte [derr], 0
        mov  ax, 1
        mov  bl, 0
        div  bl                                  ; divide by zero -> INT 0, returns after the DIV
        EQMEMB derr, 1, 59
        mov  byte [derr], 0
        mov  ax, 0x1000
        mov  bl, 2
        div  bl                                  ; quotient does not fit
        EQMEMB derr, 1, 60

; ---------------- BCD ----------------
        mov  al, 0x15
        add  al, 0x27
        daa
        EQAL 0x42, 61
        mov  al, 0x99
        add  al, 1
        daa
        EQAL 0, 62
        FLAGS CF, CF, 63
        mov  al, 0x42
        sub  al, 0x15
        das
        EQAL 0x27, 64
        mov  ax, 9
        add  al, 1
        aaa
        EQAX 0x0100, 65
        FLAGS CF|AF, CF|AF, 66
        mov  ax, 0x0305
        aas
        EQAX 0x0305, 67
        mov  al, 47
        aam
        EQAX 0x0407, 68
        mov  ax, 0x0407
        aad
        EQAX 0x002f, 69

; ---------------- data movement and addressing ----------------
        mov  word [buf+0], 0x1111
        mov  word [buf+2], 0x2222
        mov  word [buf+4], 0x3333
        mov  bx, buf
        mov  si, 2
        mov  di, 4
        mov  ax, [bx+si]
        EQAX 0x2222, 70
        mov  ax, [bx+di]
        EQAX 0x3333, 71
        mov  ax, [bx+si-2]
        EQAX 0x1111, 72
        mov  ax, [si+buf]
        EQAX 0x2222, 73
        mov  ax, [buf+4]
        EQAX 0x3333, 74
        mov  bp, buf
        mov  ax, [bp]                            ; BP base: SS segment (= 0 here)
        EQAX 0x1111, 75
        mov  ax, [bp+si+2]
        EQAX 0x3333, 76
        mov  ax, 0x0200
        mov  es, ax
        mov  word [es:0x10], 0x5a5a              ; ES override: linear 0x2010
        mov  ax, [0x2010]
        EQAX 0x5a5a, 77
        mov  ax, 0xffff
        mov  es, ax
        mov  word [es:0x2010], 0xbeef            ; wraps at 1MB: linear 0xFFFF0+0x2010 = 0x02000
        mov  ax, [0x2000]
        EQAX 0xbeef, 78
        xor  ax, ax
        mov  es, ax
        lea  ax, [bx+si+7]
        EQAX buf+9, 79
        mov  bx, 0x1111
        mov  cx, 0x2222
        xchg bx, cx
        mov  ax, bx
        EQAX 0x2222, 80
        mov  word [tmp], 0x1234
        mov  ax, 0x5678
        xchg ax, [tmp]
        EQAX 0x1234, 81
        EQMEMW tmp, 0x5678, 82
        mov  bx, tbl
        mov  byte [tbl+5], 0x99
        mov  al, 5
        xlatb
        EQAL 0x99, 83
        mov  al, 0x80
        cbw
        EQAX 0xff80, 84
        cwd
        cmp  dx, 0xffff
        je   .d1
        mov  al, 85
        jmp  fail
.d1:    mov  ax, 0x7fff
        cwd
        cmp  dx, 0
        je   .d2
        mov  al, 86
        jmp  fail
.d2:    stc
        lahf
        mov  al, ah
        and  al, 0x03
        EQAL 0x03, 87                            ; bit1 always set, CF
        mov  ah, 0xd5
        sahf
        FLAGS ALLF&0xd5, 0xd5, 88
        mov  bp, sp
        push sp
        pop  ax
        mov  bx, bp
        sub  bx, 2
        cmp  ax, bx                              ; 8086: PUSH SP pushes the new value
        je   .d3
        mov  al, 89
        jmp  fail
.d3:    mov  word [tbl], 0x1234
        mov  word [tbl+2], 0x5678
        les  bx, [tbl]
        mov  ax, es
        EQAX 0x5678, 90
        cmp  bx, 0x1234
        je   .d4
        mov  al, 91
        jmp  fail
.d4:    xor  ax, ax
        mov  es, ax
        mov  ax, 0x0123
        mov  bx, 0xabcd
        push ax
        push bx
        pop  cx
        pop  dx
        cmp  cx, 0xabcd
        jne  .df
        cmp  dx, 0x0123
        je   .d5
.df:    mov  al, 92
        jmp  fail
.d5:

; ---------------- strings ----------------
        cld
        mov  si, src
        mov  cx, 6
        mov  al, 1
.f1:    mov  [si], al
        inc  si
        inc  al
        loop .f1                                 ; src = 1 2 3 4 5 6
        mov  si, src
        mov  di, dst
        mov  cx, 6
        rep movsb
        EQMEMB dst, 1, 93
        EQMEMB dst+5, 6, 94
        cmp  cx, 0
        je   .s1
        mov  al, 95
        jmp  fail
.s1:    mov  di, dst
        mov  ax, 0xa5a5
        mov  cx, 4
        rep stosw
        EQMEMW dst+6, 0xa5a5, 96
        mov  si, src
        mov  di, dst
        mov  ax, 0x3333
        mov  [dst+3], al
        mov  byte [dst], 1
        mov  byte [dst+1], 2
        mov  byte [dst+2], 3
        mov  byte [dst+3], 9                     ; src = 1 2 3 4 ..., dst = 1 2 3 9 ...
        mov  cx, 6
        repe cmpsb                               ; stops after comparing the 4th byte
        FLAGS ZF, 0, 98
        cmp  cx, 2
        je   .s2
        mov  al, 97
        jmp  fail
.s2:
        mov  di, src
        mov  al, 5
        mov  cx, 10
        repne scasb
        cmp  di, src+5                           ; found at index 4 -> DI points behind it
        je   .s3
        mov  al, 99
        jmp  fail
.s3:    mov  si, src
        lodsb
        EQAL 1, 100
        std
        mov  si, src+5
        mov  di, dst+5
        mov  cx, 3
        rep movsb                                ; backwards copy of 6 5 4
        cld
        EQMEMB dst+5, 6, 101
        EQMEMB dst+3, 4, 102
        mov  si, src
        mov  di, dst
        mov  cx, 0
        rep movsb                                ; CX = 0 : nothing happens
        EQMEMB dst, 1, 103
        mov  ax, 0x0300
        mov  es, ax
        mov  di, 0
        mov  al, 0x77
        mov  cx, 3
        rep stosb                                ; stores to ES:DI = 0x3000..
        xor  ax, ax
        mov  es, ax
        EQMEMB tmp, 0x77, 104
        mov  word [0x3600], 0x1122
        mov  ax, 0x0360
        mov  es, ax
        mov  ax, 0
        mov  si, 0
        mov  bx, 0
        mov  al, [es:0]                          ; override on a plain mov
        EQAL 0x22, 105
        xor  ax, ax
        mov  es, ax

; ---------------- control flow ----------------
        xor  ax, ax                              ; ZF=1
        jz   .c1
        mov  al, 106
        jmp  fail
.c1:    mov  al, 1
        cmp  al, 2                               ; 1<2 signed and unsigned
        jl   .c2
        mov  al, 107
        jmp  fail
.c2:    jb   .c3
        mov  al, 108
        jmp  fail
.c3:    mov  al, 0x80
        cmp  al, 1                               ; -128 < 1 signed, 128 > 1 unsigned
        jl   .c4
        mov  al, 109
        jmp  fail
.c4:    ja   .c5
        mov  al, 110
        jmp  fail
.c5:    xor  ax, ax
        db   0x64, 0x02                          ; alias of JZ +2 (0x74) : skips the next 2 bytes
        mov  al, 1
        EQAL 0, 111
        mov  cx, 5
        xor  ax, ax
.lp:    inc  ax
        loop .lp
        EQAX 5, 112
        xor  cx, cx
        jcxz .c6
        mov  al, 113
        jmp  fail
.c6:    call near sub1
        EQAX 0x1111, 114
        call 0x0000:sub2                     ; far call: pushes CS:IP
        EQAX 0x2222, 115
        mov  bx, sub3tbl
        call [bx]                                ; indirect near call through memory
        EQAX 0x3333, 116
        xor  ax, ax
        push ax
        call sub4                                ; RET 2 pops the argument
        cmp  sp, 0xf000-0                        ; stack is balanced again
        je   .c7
        mov  al, 117
        jmp  fail
.c7:    mov  bx, jtab
        jmp  [bx]
        mov  al, 118
        jmp  fail
.j1:    int  0x40
        EQMEMB derr, 0x40, 119
        mov  byte [derr], 0
        mov  al, 0x7f
        add  al, 1                               ; OF=1
        into
        EQMEMB derr, 4, 120
        mov  byte [derr], 0
        mov  al, 1
        add  al, 1                               ; OF=0 : INTO does nothing
        into
        EQMEMB derr, 0, 121
        mov  ax, 0xf000
        push ax
        popf                                     ; flags <- F000: only defined bits survive
        pushf
        pop  ax
        and  ax, 0xfd5|0x200|0x100
        cmp  ax, 0
        je   .c8
        mov  al, 122
        jmp  fail
.c8:    stc
        db   0xd6                                ; SALC
        EQAL 0xff, 123
        clc
        db   0xd6
        EQAL 0x00, 124
        mov  ax, 0x1234
        mov  [buf], ax
        push ax
        xor  ax, ax
        pop  ax
        EQAX 0x1234, 125
        ; I/O
        mov  al, 0x5c
        out  0x77, al
        xor  al, al
        in   al, 0x77
        EQAL 0x5c, 126
        mov  dx, 0x78
        mov  al, 0x3d
        out  dx, al
        xor  al, al
        in   al, dx
        EQAL 0x3d, 127

        mov  al, 0xa5
        out  0x0f, al
        hlt

fail:   out  0x0e, al
        mov  al, 0xa6
        out  0x0f, al
        hlt

div_handler:
        mov  byte [derr], 1
        iret
int_handler:
        mov  byte [derr], 0x40
        iret
into_handler:
        mov  byte [derr], 4
        iret
sub1:   mov  ax, 0x1111
        ret
sub2:   mov  ax, 0x2222
        retf
sub3:   mov  ax, 0x3333
        ret
sub3tbl: dw  sub3
sub4:   ret  2
jtab:   dw   start.j1
