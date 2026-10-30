; SPDX-License-Identifier: MIT
; hello8088.asm - standalone 8088 test (no 6809 involvement): print through the debug console port, power off
        bits 16
        cpu     8086
        org  0x400
        cld
        mov  si, msg
.l:     lodsb
        or   al, al
        jz   .e
        out  0x0e, al
        jmp  .l
.e:     mov  al, 0xa5
        out  0x0f, al
        hlt
msg:    db   "hello from the 8088", 10, 0
