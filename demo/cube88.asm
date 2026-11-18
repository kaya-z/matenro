; cube88.asm (a bare 8088 program, no DOS) - the 8088 half of the 3D demo: a wire frame cube turns in the upper 204 rows of the picture of the HDMI
; screen.  Each frame the 8 corners are turned about two axes (integer sine table, 7 bits), projected with perspective (x * 150 / (z + 170)) and the
; 12 edges are drawn as Bresenham lines (colour per edge), each after the old line has been erased.  The 8088 writes the picture itself: "cube09 s" has
; mapped the blocks $50-$57 of its memory (the segment A000h) to the first eight blocks of the picture.  Pixel 0 is the command (the 6809 writes 254 to stop it),
; the pixels 1 and 2 are the number of frames (a word) that the 6809 reads to show the frames per second.
;   subsel 8088 ; cube09 s ; xrun -l=400 cube88.bin ; cube09 r
        bits 16
        cpu     8086
        org     0x400
        cli
        xor     ax, ax
        mov     ds, ax
        mov     ss, ax
        mov     sp, 0x7000
        mov     ax, 0xa000
        mov     es, ax
        mov     cx, 8                   ; the old corners: all in the middle (the first erase is a point)
        xor     si, si
oi:     mov     word [opx+si], 160
        mov     word [opy+si], 100
        add     si, 2
        loop    oi
frame:  cmp     byte [es:0], 254
        jne     run
        jmp     halt
run:    xor     bh, bh                  ; sin, cos of the two angles (signed words)
        mov     bl, [angy]
        mov     al, [sint+bx]
        cbw
        mov     [vsy], ax
        add     bl, 64
        mov     al, [sint+bx]
        cbw
        mov     [vcy], ax
        mov     bl, [angx]
        mov     al, [sint+bx]
        cbw
        mov     [vsx], ax
        add     bl, 64
        mov     al, [sint+bx]
        cbw
        mov     [vcx], ax
        add     byte [angy], 4
        add     byte [angx], 3
        xor     si, si                  ; the corners
        xor     di, di
        mov     cl, 7
vl:     mov     ax, [v+si]              ; x1 = (x cy + z sy) >> 7
        imul    word [vcy]
        mov     bx, ax
        mov     ax, [v+4+si]
        imul    word [vsy]
        add     bx, ax
        sar     bx, cl
        mov     [tx1], bx
        mov     ax, [v+4+si]            ; z1 = (z cy - x sy) >> 7
        imul    word [vcy]
        mov     bx, ax
        mov     ax, [v+si]
        imul    word [vsy]
        sub     bx, ax
        sar     bx, cl
        mov     [tz1], bx
        mov     ax, [v+2+si]            ; y1 = (y cx - z1 sx) >> 7
        imul    word [vcx]
        mov     bx, ax
        mov     ax, [tz1]
        imul    word [vsx]
        sub     bx, ax
        sar     bx, cl
        mov     [ty1], bx
        mov     ax, [v+2+si]            ; z2 = (y sx + z1 cx) >> 7, d = z2 + 170
        imul    word [vsx]
        mov     bx, ax
        mov     ax, [tz1]
        imul    word [vcx]
        add     bx, ax
        sar     bx, cl
        add     bx, 170
        mov     [td], bx
        mov     ax, [tx1]               ; px = 160 + x1 * 140 / d
        mov     bx, 150
        imul    bx
        idiv    word [td]
        add     ax, 160
        mov     [npx+di], ax
        mov     ax, [ty1]               ; py = 100 + y1 * 140 / d
        mov     bx, 150
        imul    bx
        idiv    word [td]
        add     ax, 100
        mov     [npy+di], ax
        add     si, 6
        add     di, 2
        cmp     si, 48
        jb      vl
        xor     si, si                  ; the edges: erase the old one, draw the new one
el:     mov     [ei], si
        mov     bl, [edges+si]
        xor     bh, bh
        shl     bx, 1
        mov     al, [edges+1+si]
        xor     ah, ah
        mov     di, ax
        shl     di, 1
        mov     ax, [opx+bx]
        mov     [lx0], ax
        mov     ax, [opy+bx]
        mov     [ly0], ax
        mov     ax, [opx+di]
        mov     [lx1], ax
        mov     ax, [opy+di]
        mov     [ly1], ax
        mov     byte [lcol], 0
        push    bx
        push    di
        call    line
        pop     di
        pop     bx
        mov     si, [ei]
        mov     ax, [npx+bx]
        mov     [lx0], ax
        mov     ax, [npy+bx]
        mov     [ly0], ax
        mov     ax, [npx+di]
        mov     [lx1], ax
        mov     ax, [npy+di]
        mov     [ly1], ax
        mov     ax, si
        shr     ax, 1
        add     al, 101
        mov     [lcol], al
        call    line
        mov     si, [ei]
        add     si, 2
        cmp     si, 24
        jb      el
        mov     cx, 8                   ; the new corners are the old ones
        xor     si, si
cp:     mov     ax, [npx+si]
        mov     [opx+si], ax
        mov     ax, [npy+si]
        mov     [opy+si], ax
        add     si, 2
        loop    cp
        mov     ax, [fcnt]              ; the number of frames
        inc     ax
        mov     [fcnt], ax
        mov     [es:1], al
        mov     [es:2], ah
        jmp     frame
halt:   hlt
        jmp     halt
; the Bresenham line (lx0, ly0) - (lx1, ly1) in the colour lcol, with the registers in the loop (no clipping: the corners stay inside of the rows 0 ... 203)
line:   mov     ax, [lx1]
        sub     ax, [lx0]
        mov     si, 1
        jge     la
        neg     ax
        mov     si, -1                  ; si = the step in x
la:     mov     bx, ax                  ; bx = |dx|
        mov     ax, [ly1]
        sub     ax, [ly0]
        mov     cx, 320
        jge     lb
        neg     ax
        neg     cx
lb:     mov     dx, ax                  ; dx = |dy|
        mov     [stepy], cx             ; the step in y: +-320
        mov     ax, [ly0]               ; di = ly0 * 320 + lx0
        mov     di, ax
        mov     cl, 8
        shl     ax, cl
        mov     cl, 6
        shl     di, cl
        add     di, ax
        add     di, [lx0]
        mov     al, [lcol]
        cmp     bx, dx
        jb      ymaj
        mov     cx, bx                  ; x is the long side
        inc     cx
        mov     bp, bx
        shr     bp, 1
xl:     mov     [es:di], al
        add     di, si
        sub     bp, dx
        jge     xn
        add     di, [stepy]
        add     bp, bx
xn:     loop    xl
        ret
ymaj:   mov     [stepx], si             ; y is the long side
        mov     si, [stepy]
        mov     cx, dx
        inc     cx
        mov     bp, dx
        shr     bp, 1
yl:     mov     [es:di], al
        add     di, si
        sub     bp, bx
        jge     yn
        add     di, [stepx]
        add     bp, dx
yn:     loop    yl
        ret
; the corners (x, y, z), the edges (pairs of corners)
v:      dw      -35,-35,-35,  35,-35,-35,  -35,35,-35,  35,35,-35,  -35,-35,35,  35,-35,35,  -35,35,35,  35,35,35
edges:  db      0,1, 2,3, 4,5, 6,7, 0,2, 1,3, 4,6, 5,7, 0,4, 1,5, 2,6, 3,7
angx:   db      0
angy:   db      0
fcnt:   dw      0
vsy:    dw      0
vcy:    dw      0
vsx:    dw      0
vcx:    dw      0
tx1:    dw      0
ty1:    dw      0
tz1:    dw      0
td:     dw      0
lx0:    dw      0
ly0:    dw      0
lx1:    dw      0
ly1:    dw      0
lcol:   db      0
ldx:    dw      0
ldy:    dw      0
lsx:    dw      0
stepx:  dw      0
ei:     dw      0
stepy:  dw      0
lerr:   dw      0
le2:    dw      0
opx:    times 8 dw 0
opy:    times 8 dw 0
npx:    times 8 dw 0
npy:    times 8 dw 0
sint:
        db      0,3,6,9,12,16,19,22,25,28,31,34,37,40,43,46
        db      49,51,54,57,60,63,65,68,71,73,76,78,81,83,85,88
        db      90,92,94,96,98,100,102,104,106,107,109,111,112,113,115,116
        db      117,118,120,121,122,122,123,124,125,125,126,126,126,127,127,127
        db      127,127,127,127,126,126,126,125,125,124,123,122,122,121,120,118
        db      117,116,115,113,112,111,109,107,106,104,102,100,98,96,94,92
        db      90,88,85,83,81,78,76,73,71,68,65,63,60,57,54,51
        db      49,46,43,40,37,34,31,28,25,22,19,16,12,9,6,3
        db      0,-3,-6,-9,-12,-16,-19,-22,-25,-28,-31,-34,-37,-40,-43,-46
        db      -49,-51,-54,-57,-60,-63,-65,-68,-71,-73,-76,-78,-81,-83,-85,-88
        db      -90,-92,-94,-96,-98,-100,-102,-104,-106,-107,-109,-111,-112,-113,-115,-116
        db      -117,-118,-120,-121,-122,-122,-123,-124,-125,-125,-126,-126,-126,-127,-127,-127
        db      -127,-127,-127,-127,-126,-126,-126,-125,-125,-124,-123,-122,-122,-121,-120,-118
        db      -117,-116,-115,-113,-112,-111,-109,-107,-106,-104,-102,-100,-98,-96,-94,-92
        db      -90,-88,-85,-83,-81,-78,-76,-73,-71,-68,-65,-63,-60,-57,-54,-51
        db      -49,-46,-43,-40,-37,-34,-31,-28,-25,-22,-19,-16,-12,-9,-6,-3
