; pctest.asm (MS-DOS .COM): the text screen of the PC (dos -v=2 -w=2 ...: the BIOS's INT 10h and the console on the text memory B800h).  The program checks the
; memory and the functions 00, 02, 03, 06, 07, 08, 09, 0Eh and the console output of DOS, and writes PASS or FAIL n (n = the number of checks that failed)
; into the file PCRES.TXT (the run mode of dos copies it back to the OS-9 directory).
        bits 16
        cpu     8086
        org     0x100
        xor     bp, bp                  ; the failures
        mov     ah, 0x0f                ; the mode
        int     0x10
        cmp     al, 3
        jz      m1
        inc     bp
m1:     mov     ax, 0x0003              ; set mode 3: the screen is cleared
        int     0x10
        mov     ax, 0xb800
        mov     es, ax
        cmp     word [es:0], 0x0720
        jz      m2
        inc     bp
m2:     cmp     word [es:3998], 0x0720
        jz      m3
        inc     bp
m3:     mov     word [es:0], 0x1e41     ; direct writes, as Turbo Pascal does: (0,0) = 'A' and (24,79) = 'Z'
        mov     word [es:3998], 0x2f5a
        mov     ah, 2                   ; the cursor to (5,10)
        xor     bh, bh
        mov     dx, 0x050a
        int     0x10
        mov     ah, 3
        xor     bh, bh
        int     0x10
        cmp     dx, 0x050a
        jz      m4
        inc     bp
m4:     mov     ax, 0x0958              ; 09: 'X', attribute 4Fh, 3 times
        xor     bh, bh
        mov     bl, 0x4f
        mov     cx, 3
        int     0x10
        cmp     word [es:(5*80+10)*2], 0x4f58
        jz      m5
        inc     bp
m5:     cmp     word [es:(5*80+12)*2], 0x4f58
        jz      m6
        inc     bp
m6:     mov     ax, 0x0e48              ; 0Eh teletype 'H' and 'i': the attribute stays
        xor     bh, bh
        int     0x10
        mov     ax, 0x0e69
        int     0x10
        cmp     word [es:(5*80+10)*2], 0x4f48
        jz      m7
        inc     bp
m7:     cmp     word [es:(5*80+11)*2], 0x4f69
        jz      m8
        inc     bp
m8:     mov     ah, 3                   ; the cursor is at (5,12)
        xor     bh, bh
        int     0x10
        cmp     dx, 0x050c
        jz      m9
        inc     bp
m9:     mov     ax, 0x0601              ; scroll the whole screen up by one line
        mov     bh, 0x07
        xor     cx, cx
        mov     dx, 0x184f
        int     0x10
        cmp     word [es:(4*80+10)*2], 0x4f48
        jz      m10
        inc     bp
m10:    cmp     word [es:0], 0x0720     ; (0,0) is the old (1,0)
        jz      m11
        inc     bp
m11:    cmp     word [es:(23*80+79)*2], 0x2f5a
        jz      m12
        inc     bp
m12:    cmp     word [es:(24*80+5)*2], 0x0720
        jz      m13
        inc     bp
m13:    mov     ax, 0x0701              ; down by one line: back
        mov     bh, 0x07
        xor     cx, cx
        mov     dx, 0x184f
        int     0x10
        cmp     word [es:(5*80+10)*2], 0x4f48
        jz      m14
        inc     bp
m14:    cmp     word [es:(24*80+79)*2], 0x2f5a
        jz      m15
        inc     bp
m15:    mov     ah, 2                   ; 08: read the cell at the cursor (5,10)
        xor     bh, bh
        mov     dx, 0x050a
        int     0x10
        mov     ah, 8
        xor     bh, bh
        int     0x10
        cmp     ax, 0x4f48
        jz      m16
        inc     bp
m16:    mov     ax, 0x0602              ; scroll a window (rows 4-6, columns 8-12) up by two lines with the attribute 1Fh
        mov     bh, 0x1f
        mov     cx, 0x0408
        mov     dx, 0x060c
        int     0x10
        cmp     word [es:(4*80+10)*2], 0x0720   ; row 4 got the old row 6 (blank), rows 5 and 6 are filled with the attribute 1Fh
        jz      m16a
        inc     bp
m16a:   cmp     word [es:(5*80+10)*2], 0x1f20
        jz      m16b
        inc     bp
m16b:   cmp     word [es:(6*80+12)*2], 0x1f20
        jz      m16c
        inc     bp
m16c:   cmp     word [es:(5*80+7)*2], 0x0720    ; outside the window: not touched
        jz      m17
        inc     bp
m17:    mov     ah, 2                   ; the console of DOS (INT 21h AH=2) goes to the text memory, too
        xor     bh, bh
        mov     dx, 0x0a00
        int     0x10
        mov     ah, 2
        mov     dl, 'Q'
        int     0x21
        cmp     byte [es:(10*80)*2], 'Q'
        jz      m18
        inc     bp
m18:    mov     ah, 1                   ; INT 16h AH=1: no key is waiting: ZF = 1
        int     0x16
        jz      m19
        inc     bp
m19:    xor     ah, ah                  ; INT 1Ah AH=0: the ticks since midnight (less than 1800B0h), AL = 0
        int     0x1a
        test    al, al
        jz      m20
        inc     bp
m20:    cmp     cx, 0x18
        jb      m21
        inc     bp
m21:    ; the result file
        mov     ah, 0x3c
        xor     cx, cx
        mov     dx, fname
        int     0x21
        jc      done
        mov     bx, ax
        mov     si, msg
        mov     cx, 6
        test    bp, bp
        jz      w1
        mov     si, msgf
        mov     cx, 8
        mov     ax, bp
        add     al, '0'                 ; one digit is enough
        mov     [msgf+5], al
w1:     mov     dx, si
        mov     ah, 0x40
        int     0x21
        mov     ah, 0x3e
        int     0x21
done:   int     0x20
fname:  db      'PCRES.TXT', 0
msg:    db      'PASS', 13, 10
msgf:   db      'FAIL ', '0', 13, 10
