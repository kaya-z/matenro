; SPDX-License-Identifier: MIT
; bios88.asm - the BIOS (IO.SYS) of MS-DOS 1.25 on the 8088 of 摩天楼 (Matenro); nasm -f bin
; Credits: the BIOS entries (a table of far call entries at the start of the BIOS segment, their registers) are those of
; 86-DOS / MS-DOS 1.25 (the source that Microsoft published, MIT license: MSDOS.ASM, and IO.ASM of Seattle Computer
; Products as the example).  The code is original.
;
; The BIOS segment is 0040h (linear 0400h), 500h bytes.  The kernel (msdos.sys) is loaded at DOSSEG = 0090h.  A call of
; the kernel enters the table at offset 3 * n; the stub copies the registers into the request block RQ, rings the 6809
; (OS-9 command `dos`) and waits for the done flag, like the CP/M-86 stub (os9/cpm/i8088shim.asm):
;   RQ+0 function  +1 AX  +4 BX  +6 CX  +8 DX  +10 DS      (request)
;   RQ+16 AL  +17 AH  +18 BX  +20 CX  +22 DX  +24 flags (CF)  +26 time (year-1900 month day hour minute second)  +32 done
; Functions: 1 status, 2 input, 3 output, 4 printer, 5 aux in, 6 aux out, 7 disk read, 8 disk write, 12 get time, 13 flush.
;
        bits 16
        cpu     8086
RQ      equ     0x400
LB      equ     0x440                   ; +0 memory size (paragraphs), +4 INITTAB (the loader writes both)
FCB     equ     0x480                   ; the file control block of COMMAND.COM
BIOSLEN equ     0x500
DOSSEG  equ     0x40 + BIOSLEN/16
        org     0

        jmp     near init               ; the table of the entries: 3 bytes each
        jmp     near status
        jmp     near inp
        jmp     near outp
        jmp     near print
        jmp     near auxin
        jmp     near auxout
        jmp     near read
        jmp     near write
        jmp     near dskchg
        jmp     near setdate
        jmp     near settime
        jmp     near gettime
        jmp     near flush
        jmp     near mapdev

; register block -> request, ring the bell, wait.  AX is kept.
%macro req 1
        mov     byte [cs:RQ+0], %1
        call    sendreq
%endmacro

sendreq:
        mov     [cs:RQ+1], ax
        mov     [cs:RQ+4], bx
        mov     [cs:RQ+6], cx
        mov     [cs:RQ+8], dx
        mov     [cs:RQ+10], ds
sendrq: push    ax
        mov     byte [cs:RQ+32], 0
        xor     al, al
        out     2, al                   ; ring the 6809
.wait:  cmp     byte [cs:RQ+32], 0
        je      .wait
        pop     ax
        ret

; console input status: ZF = 1 no character, ZF = 0 AL = the character (not removed)
status: req     1
        mov     al, [cs:RQ+16]
        mov     ah, [cs:RQ+17]
        or      ah, ah
        retf

inp:    req     2
        mov     al, [cs:RQ+16]
        retf

outp:   req     3
        retf

; printer, auxiliary port: AL = the character.  The 6809 writes it to the file or device of the option -p= / -o= (nothing
; if there is none); AUXIN returns the next character of the file of -i=, or 1Ah (end of file) if there is none
print:  req     4
        retf
auxin:  req     5
        mov     al, [cs:RQ+16]
        retf
auxout: req     6
        retf

; disk read / write.  AL = drive, BX = transfer address in DS, CX = sectors, DX = record number.
; CF = 1: error, AL = error code, CX = sectors not done
read:   req     7
        jmp     short diskend
write:  req     8
diskend:
        mov     al, [cs:RQ+16]
        mov     cx, [cs:RQ+20]
        cmp     byte [cs:RQ+24], 1      ; CF = 1 if the flag is 0 ...
        cmc                             ; ... so that CF = 1 only if the 6809 reported an error
        retf

dskchg: mov     ah, 1                   ; the disk has not been changed
        clc
        retf

; The clock: the date and time of DOS are the clock of OS-9 plus an offset TOFF (seconds, 32 bits, modulo 2^32) that DATE
; and TIME change.  The offset is kept here only: the clock of OS-9 is not set, and the offset is gone when dos ends.
; set the date: the kernel passes the day count in AX (days since 1 January 1980)
setdate:
        push    ax
        push    bx
        push    cx
        push    dx
        push    si
        mov     bx, ax
        call    effsec
        call    splitsec                ; SI = the days of the clock of DOS
        sub     bx, si                  ; the difference in days (signed)
        mov     ax, bx
        mov     dx, 21600
        imul    dx                      ; DX:AX = days * 21600 (signed: 43200 would be negative)
        shl     ax, 1
        rcl     dx, 1
        shl     ax, 1
        rcl     dx, 1                   ; * 86400
        add     [cs:toff], ax
        adc     [cs:toff+2], dx
        jmp     short timeend

; set the time: CH:CL = hours:minutes, DH = seconds
settime:
        push    ax
        push    bx
        push    cx
        push    dx
        push    si
        call    todsec                  ; DX:AX = the new seconds of the day
        push    dx
        push    ax
        call    effsec
        call    splitsec                ; DX:AX = the seconds of the day now
        pop     bx
        pop     cx                      ; CX:BX = the new seconds of the day
        sub     bx, ax
        sbb     cx, dx                  ; the difference
        add     [cs:toff], bx
        adc     [cs:toff+2], cx
timeend:
        pop     si
        pop     dx
        pop     cx
        pop     bx
        pop     ax
        retf

toff:   dw      0, 0

; CH:CL:DH -> DX:AX = h * 3600 + m * 60 + s
todsec: push    bx
        mov     bl, dh
        xor     bh, bh
        mov     al, cl
        mov     dl, 60
        mul     dl                      ; AX = m * 60
        add     bx, ax
        mov     al, ch
        xor     ah, ah
        mov     dx, 3600
        mul     dx                      ; DX:AX = h * 3600
        add     ax, bx
        adc     dx, 0
        pop     bx
        ret

; DX:AX = the seconds since 1 January 1980 of the clock of OS-9
hostsec:
        push    bx
        push    cx
        push    si
        call    rawtime                 ; AX = days, CH:CL:DH = the time
        push    cx
        push    dx
        mov     bx, 43200
        mul     bx                      ; DX:AX = days * 43200
        shl     ax, 1
        rcl     dx, 1                   ; * 86400
        mov     bx, ax
        mov     si, dx
        pop     dx
        pop     cx
        call    todsec
        add     ax, bx
        adc     dx, si
        pop     si
        pop     cx
        pop     bx
        ret

; DX:AX = the seconds of the clock of DOS
effsec: call    hostsec
        add     ax, [cs:toff]
        adc     dx, [cs:toff+2]
        ret

; DX:AX = seconds -> SI = days, DX:AX = the seconds of the day
splitsec:
        push    bx
        push    cx
        xor     bx, bx
        shr     dx, 1
        rcr     ax, 1
        rcl     bx, 1                   ; BX = the bit that was lost
        mov     cx, 43200
        div     cx                      ; AX = days, DX = the half seconds of the day (the quotient is below 49711)
        mov     si, ax
        mov     ax, dx
        xor     dx, dx
        shl     ax, 1
        rcl     dx, 1
        add     ax, bx
        adc     dx, 0
        pop     cx
        pop     bx
        ret

mapdev: retf                            ; AL stays the physical unit

flush:  req     13
        retf

; time and date: AX = days since 1 January 1980, CH:CL = hours:minutes, DH = seconds, DL = 1/100 seconds
gettime:
        push    bx
        push    si
        call    effsec
        call    splitsec                ; SI = days, DX:AX = seconds of the day
        mov     cx, 3600
        div     cx                      ; AX = hours, DX = seconds of the hour
        mov     ch, al
        mov     ax, dx
        mov     cl, 60
        div     cl                      ; AL = minutes, AH = seconds
        mov     dh, ah
        mov     cl, al
        xor     dl, dl
        mov     ax, si
        pop     si
        pop     bx
        retf

; the clock of OS-9: AX = days since 1 January 1980, CH:CL = hours:minutes, DH = seconds
rawtime:
        req     12
        push    bx
        push    si
        mov     al, [cs:RQ+26]          ; year - 1900
        sub     al, 80
        jae     .y80
        xor     al, al
.y80:   xor     ah, ah                  ; AX = years since 1980
        mov     si, ax
        mov     bx, 365
        mul     bx                      ; AX = years * 365
        mov     bx, ax
        mov     ax, si
        add     ax, 3
        shr     ax, 1
        shr     ax, 1                   ; leap days of the years before: (years + 3) / 4
        add     bx, ax
        mov     al, [cs:RQ+27]          ; month 1..12
        xor     ah, ah
        dec     ax
        cmp     ax, 11
        jbe     .mok
        xor     ax, ax
.mok:   shl     ax, 1
        mov     si, ax
        add     bx, [cs:monthdays+si]
        mov     al, [cs:RQ+26]
        sub     al, 80
        and     al, 3
        jnz     .noleap
        cmp     byte [cs:RQ+27], 2
        jbe     .noleap
        inc     bx                      ; 29 February of this year has passed
.noleap:
        mov     al, [cs:RQ+28]          ; day 1..31
        xor     ah, ah
        dec     ax
        add     ax, bx
        mov     ch, [cs:RQ+29]
        mov     cl, [cs:RQ+30]
        mov     dh, [cs:RQ+31]
        xor     dl, dl
        pop     si
        pop     bx
        ret

monthdays:
        dw      0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334

; INT 10h, the video BIOS of the IBM PC that the programs of PC DOS (DEBUG) ask for the screen: get the mode (80 columns,
; mode 3, page 0) and teletype output; everything else is ignored
int10:  cmp     ah, 0x0F
        jne     .n1
        mov     ax, 0x5003
        xor     bh, bh
        iret
.n1:    cmp     ah, 0x0E
        jne     .n2
        req     3
.n2:    iret

; INT E2h: the graphics of the HDMI screen of the Tang Nano 20K (the 6809 draws: os9/cpm/cpmgfx.asm, the block of DS:BX), AL = 0 done, FFh no frame buffer
gfxint: req     30
        mov     al, [cs:RQ+16]
        iret

; ------------------------------------------------------------------ start (the reset vector jumps here)
init:   cli
        xor     ax, ax
        mov     ss, ax
        mov     sp, 0x400               ; the stack is just below the BIOS
        mov     es, ax
        mov     word [es:0x40], int10   ; INT 10h
        mov     [es:0x42], cs
        mov     word [es:0x388], gfxint ; INT E2h
        mov     [es:0x38a], cs
        push    cs
        pop     ds
        mov     dx, [LB]                ; memory size in paragraphs
        mov     si, LB+4                ; INITTAB: the 6809 has written it
        call    far [dosentry]          ; initialize the kernel
        mov     dx, 0x100
        mov     ah, 26                  ; set the DMA address
        int     0x21
        mov     cx, [6]                 ; size of the segment
        mov     bx, ds                  ; the program segment
        push    cs
        pop     ds                      ; DS must be CS to point to the FCB
        mov     dx, FCB
        mov     ah, 15
        int     0x21                    ; open COMMAND.COM (drive A)
        or      al, al
        jnz     .error
        xor     ax, ax
        mov     [FCB+33], ax            ; random record: the start of the file
        mov     [FCB+35], ax
        inc     ax
        mov     [FCB+14], ax            ; record length 1
        mov     ah, 39                  ; block read (CX is set)
        int     0x21
        jcxz    .error
        test    al, 1
        jz      .error                  ; the end of the file must have been reached
        mov     ds, bx
        mov     es, bx
        mov     ss, bx
        mov     sp, 0x5C
        xor     ax, ax
        push    ax                      ; zero on top of the stack for the return
        mov     dx, 0x80
        mov     ah, 26
        int     0x21                    ; the default transfer address (DS:0080)
        push    bx
        mov     ax, 0x100
        push    ax
        retf                            ; to COMMAND
.error: push    cs
        pop     ds
        mov     dx, badcom
        mov     ah, 9
        int     0x21
        sti
.stall: jmp     short .stall

dosentry:
        dw      0, DOSSEG
badcom: db      13, 10, "Error in loading Command Interpreter", 13, 10, "$"

        times   FCB-($-$$) db 0
        db      0, 'COMMAND COM'        ; drive A
        times   BIOSLEN-($-$$) db 0
