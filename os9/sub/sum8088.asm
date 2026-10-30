; SPDX-License-Identifier: MIT
; sub8088.asm - 8088 program of the Matenro integration test (runs at 0000:0400, entered from the reset vector)
        bits 16
        cpu     8086
        org  0x400
        cli
        xor  ax, ax
        mov  ds, ax
        mov  es, ax
        mov  ss, ax
        mov  sp, 0x4000
        mov  al, 0x20
        out  0x0c, al            ; interrupt vector byte
        mov  word [0x80], isr
        mov  word [0x82], 0
        sti
        xor  al, al
        out  0x03, al
        out  0x02, al            ; "ready" to the 6809
idle:   hlt
        jmp  idle
isr:    push ax
        push bx
        push cx
        in   al, 0x04            ; n from the mailbox
        xor  ah, ah
        mov  cx, ax
        xor  bx, bx
sum:    add  bx, cx
        loop sum
        mov  [0x100], bx         ; result into the shared RAM
        mov  al, bl
        out  0x08, al
        mov  al, bh
        out  0x09, al
        xor  al, al
        out  0x03, al            ; acknowledge the doorbell of the 6809
        out  0x02, al            ; ring the 6809
        pop  cx
        pop  bx
        pop  ax
        iret
