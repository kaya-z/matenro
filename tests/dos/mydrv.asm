; SPDX-License-Identifier: MIT
; a character device driver for MS-DOS 2.0 (DEVICE=MYDRV.SYS in CONFIG.SYS): prints a message at INIT, accepts and throws away
; what is written to MYDEV.  nasm -f bin
        bits 16
        dd      -1                      ; link (SYSINIT fills it in)
        dw      0x8000                  ; character device
        dw      strat
        dw      intr
        db      "MYDEV   "
ptr     dd      0
strat:  mov     [cs:ptr], bx
        mov     [cs:ptr+2], es
        retf
intr:   push    ax
        push    bx
        push    dx
        push    ds
        lds     bx, [cs:ptr]
        cmp     byte [bx+2], 0          ; command 0 = INIT
        jne     .done
        push    cs
        pop      ds
        mov     dx, msg
        mov     ah, 9
        int     0x21
        lds     bx, [cs:ptr]
        mov     word [bx+14], end       ; break address
        mov     [bx+16], cs
.done:  mov     word [bx+3], 0x0100     ; done
        pop     ds
        pop     dx
        pop     bx
        pop     ax
        retf
msg     db      "MYDRV loaded", 13, 10, "$"
end:
