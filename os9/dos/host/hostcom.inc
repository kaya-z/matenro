; SPDX-License-Identifier: MIT
; hostcom.inc - shared by HOSTIN.COM and HOSTOUT.COM (run mode of the OS-9 command `dos`, docs/MANUAL.md 6.8)
; The DOS tools talk to the 6809 through the request block of the BIOS, like the BIOS itself (os9/dos/bios88.asm,
; bios2.asm): the function number at RQ+0, BX CX DX DS at RQ+4 +6 +8 +10, then the doorbell (port 2); the reply is AL
; at RQ+16 and CX at RQ+20, and RQ+32 is the done flag.  RQ is at 0040:0400 in MS-DOS 1.25 and at 0040:0010 in 2.0.
;   20 directory (CX = 0 start, 1 next: 11 bytes name + 4 bytes size at DS:BX; AL = 1 at the end)
;   21 open (DS:BX the name, DX = 0 read, 1 create)   22 read CX bytes to DS:BX   23 write CX bytes from DS:BX
;   24 close   25 done (leave DOS)   26 the command line to DS:BX

RQSEG   equ     0x40

; find where the request block is
getver: mov     ah, 0x30
        int     0x21
        mov     word [rqofs], 0x400
        cmp     al, 2
        jb      .r
        mov     word [rqofs], 0x10
.r:     ret

; AL = function, BX CX DX = the registers; the reply: AL, CX
req:    push    si
        push    es
        mov     si, RQSEG
        mov     es, si
        mov     si, [rqofs]
        mov     [es:si], al
        mov     [es:si+4], bx
        mov     [es:si+6], cx
        mov     [es:si+8], dx
        mov     [es:si+10], ds
        mov     byte [es:si+32], 0
        xor     al, al
        out     2, al
.w:     cmp     byte [es:si+32], 0
        je      .w
        mov     al, [es:si+16]
        mov     cx, [es:si+20]
        pop     es
        pop     si
        ret

; print the $ terminated string at DX
puts:   mov     ah, 9
        int     0x21
        ret

; AL = 1 if the name at SI (11 bytes) is one of ours or an image (it is not copied), else 0
isskip: push    si
        push    di
        push    cx
        push    bx
        push    es
        push    ds
        pop     es
        cld
        cmp     word [si+8], 'IM'
        jne     .l
        cmp     byte [si+10], 'G'
        je      .yes
.l:     mov     bx, skiptab
.n:     cmp     byte [bx], 0
        je      .no
        mov     di, bx
        push    si
        mov     cx, 11
        repe    cmpsb
        pop     si
        je      .yes
        add     bx, 11
        jmp     .n
.no:    xor     al, al
        jmp     short .o
.yes:   mov     al, 1
.o:     pop     es
        pop     bx
        pop     cx
        pop     di
        pop     si
        ret

skiptab: db     'COMMAND COM'
        db      'HOSTIN  COM'
        db      'HOSTOUT COM'
        db      'RUNJOB  BAT'
        db      'MSDOS   SYS'
        db      'BIOS2   BIN'
        db      0
rqofs:  dw      0
