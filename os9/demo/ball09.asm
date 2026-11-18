* SPDX-License-Identifier: MIT
********************************************************************
* ball09 - the 6809 half of the star field demo (the 8088 half is demo/stars88.asm, a bare 8088
* program)
*
*   subsel 8088 ; ball09 s ; xrun -l=400 stars88.bin ; ball09 r      (the file demo2 of /d0)
*
* s: the palette, the picture black with the text of the console over it, the blocks $50-$57 of
* the 8088 memory become the first eight blocks of the
* picture (the 8088 draws its stars there),   r: a ball
* (a filled circle, a few shades) bounces over the
* picture, drawn by the 6809 through the window of the cross link; a key ends it (it stops the
* 8088, too: pixel 0 = 254).  gfx off shows the console again.
* Credits: the module layout follows the sample commands of the NitrOS-9 project (GPL v2), as in
* os9/xrun.asm.  The code is original.
********************************************************************

         nam   ball09
         ttl   Star field demo, the 6809 half

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

XIDX     equ   $FFCD
XDAT     equ   $FFCE
XE_MI    equ   $08
XE_MD    equ   $09
XE_WA    equ   $0A
XE_WD    equ   $0D

         mod   eom,name,tylg,atrv,start,size

         org   0
         use   gfxvars.inc
bxp      rmb   2                 the centre of the ball
byp      rmb   2
dxp      rmb   2                 the step
dyp      rmb   2
pxp      rmb   2                 where it was drawn last
pyp      rmb   2
xlo      rmb   2
xro      rmb   2
xln      rmb   2
xrn      rmb   2
seg1     rmb   2
seg2     rmb   2
tyy      rmb   2
dyy      rmb   1
ady      rmb   1
kpath    rmb   1                 the keyboard (/term: the standard input may be a file)
hw16     rmb   2
         rmb   200               stack
size     equ   .

name     fcs   /ball09/
         fcb   edition

msgnoreg fcc   "ball09: no frame buffer (Tang Nano 20K only)"
         fcb   C$CR
msguse   fcc   "usage: ball09 s | r  (see the header)"
         fcb   C$CR
* half widths of the circle of the radius 14 for |dy| = 0 ... 14
termn    fcc   "/term"
         fcb   C$CR
hwtab    fcb   14,13,13,13,13,13,12,12,11,10,9,8,7,5,0
* the title (ANSI sequences and UTF-8)
title
         fcb   $1b,$25,$47,$1b,$5b,$32,$4a,$1b,$5b,$48,$0d,$0a
         fcb   $1b,$5b,$31,$3b,$33,$37,$6d,$20,$20,$e6,$91,$a9
         fcb   $e5,$a4,$a9,$e6,$a5,$bc,$20,$20,$4d,$41,$54,$45
         fcb   $4e,$52,$4f,$0d,$0a,$1b,$5b,$30,$3b,$33,$36,$6d
         fcb   $20,$20,$38,$30,$38,$38,$3a,$20,$e6,$98,$9f,$e7
         fcb   $a9,$ba,$20,$20,$20,$36,$38,$30,$39,$3a,$20,$e7
         fcb   $90,$83,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a
         fcb   $0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a
         fcb   $0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a
         fcb   $0d,$0a,$0d,$0a,$1b,$5b,$30,$3b,$33,$33,$6d,$20
         fcb   $20,$e3,$82,$ad,$e3,$83,$bc,$e3,$82,$92,$e6,$8a
         fcb   $bc,$e3,$81,$99,$e3,$81,$a8,$e7,$b5,$82,$e4,$ba
         fcb   $86,$1b,$5b,$30,$6d
titlee   equ   *

err      lda   #2
         ldy   #80
         os9   I$WritLn
         ldb   #1
         os9   F$Exit

start    pshs  x
         lbsr  g_probe
         puls  x
         lbne  noreg
skp      lda   ,x+
         cmpa  #' '
         beq   skp
         anda  #$DF
         cmpa  #'S'
         beq   setup
         cmpa  #'R'
         lbeq  run
         leax  msguse,pcr
         lbra  err
noreg    leax  msgnoreg,pcr
         lbra  err

* s: the palette, black, picture and text, the map of the blocks, the title
setup    lbsr  setpal
         clr   vc,u
         lbsr  g_fill
         lda   #3
         lbsr  g_mode
         leax  mapblk,pcr
         ldb   #8
mp1      pshs  b,x
         lbsr  g_run
         puls  b,x
         leax  14,x
         decb
         bne   mp1
         clrb
         os9   F$Exit

* r: the ball
run      lda   #READ.
         leax  termn,pcr
         os9   I$Open
         lbcs  noreg
         sta   kpath,u
         lda   #1
         leax  title,pcr
         ldy   #titlee-title
         os9   I$Write
         ldd   #100
         std   bxp,u
         std   pxp,u
         ldd   #120
         std   byp,u
         std   pyp,u
         ldd   #3
         std   dxp,u
         ldd   #2
         std   dyp,u
fr       ldd   pxp,u               the new place (the step reverses at the edges)
         addd  dxp,u
         std   bxp,u
         cmpd  #18
         bge   r1
         ldd   #3
         std   dxp,u
         bra   r2
r1       cmpd  #301
         ble   r2
         ldd   #-3
         std   dxp,u
r2       ldd   pyp,u
         addd  dyp,u
         std   byp,u
         cmpd  #18
         bge   r3
         ldd   #2
         std   dyp,u
         bra   r4
r3       cmpd  #221
         ble   r4
         ldd   #-2
         std   dyp,u
r4       lbsr  ball                draw the new ball first, then erase what is left of the old one
         lbsr  ediff
         ldd   bxp,u
         std   pxp,u
         ldd   byp,u
         std   pyp,u
         ldx   #1
         os9   F$Sleep
         lda   kpath,u             a key?
         ldb   #SS.Ready
         os9   I$GetStt
         lbcs  fr
         lda   kpath,u
         leax  hw16,u
         ldy   #1
         os9   I$Read
         ldd   #0                  stop the 8088: pixel 0 = 254
         std   vx,u
         std   vy,u
         lbsr  g_beg
         lbsr  g_seta
         lda   #254
         sta   >XDAT
         lbsr  g_end
         clrb
         os9   F$Exit

* the ball (bxp, byp): 29 rows, shaded
ball     lbsr  g_beg
         lda   #-14
         sta   dyy,u
bl1      lda   dyy,u
         bpl   bl2
         nega
bl2      sta   ady,u
         leax  hwtab,pcr
         ldb   ady,u
         ldb   b,x
         clra
         std   hw16,u
         ldd   bxp,u
         subd  hw16,u
         std   vx,u
         ldb   dyy,u
         sex
         addd  byp,u
         std   vy,u
         ldd   hw16,u
         lslb
         rola
         addd  #1
         std   gln,u
         lda   ady,u
         asla
         adda  #100
         sta   vc,u
         lbsr  g_hline
         inc   dyy,u
         lda   dyy,u
         cmpa  #15
         bne   bl1
         lbra  g_end

* black where the old ball (pxp, pyp) was and the new one (bxp, byp) is not: per row the old span without the new span
ediff    lbsr  g_beg
         lda   #-14
         sta   dyy,u
ed1      lda   dyy,u
         bpl   ed2
         nega
ed2      sta   ady,u
         leax  hwtab,pcr
         ldb   ady,u
         ldb   b,x
         clra
         std   hw16,u
         ldd   pxp,u               the old span xlo ... xro in the row tyy
         subd  hw16,u
         std   xlo,u
         ldd   pxp,u
         addd  hw16,u
         std   xro,u
         ldb   dyy,u
         sex
         addd  pyp,u
         std   tyy,u
         subd  byp,u               the row in the new ball
         bpl   ed3
         coma
         comb
         addd  #1
ed3      cmpd  #14
         bhi   edw                 not in the new ball: all of the old span
         leax  hwtab,pcr
         tfr   b,a
         tfr   a,b
         ldb   b,x
         clra
         std   hw16,u
         ldd   bxp,u               the new span xln ... xrn
         subd  hw16,u
         std   xln,u
         ldd   bxp,u
         addd  hw16,u
         std   xrn,u
         ldd   xln,u               left: xlo ... min(xro, xln - 1)
         subd  #1
         cmpd  xro,u
         ble   ed4
         ldd   xro,u
ed4      std   seg2,u
         ldd   xlo,u
         cmpd  seg2,u
         bgt   ed5
         ldd   xlo,u
         lbsr  seg
ed5      ldd   xrn,u               right: max(xlo, xrn + 1) ... xro
         addd  #1
         cmpd  xlo,u
         bge   ed6
         ldd   xlo,u
ed6      std   seg1,u
         ldd   xro,u
         std   seg2,u
         ldd   seg1,u
         cmpd  seg2,u
         bgt   ed9
         lbsr  seg
         bra   ed9
edw      ldd   xro,u
         std   seg2,u
         ldd   xlo,u
         lbsr  seg
ed9      inc   dyy,u
         lda   dyy,u
         cmpa  #15
         lbne  ed1
         lbra  g_end
* black from D to seg2 in the row tyy
seg      std   vx,u
         ldd   seg2,u
         subd  vx,u
         addd  #1
         std   gln,u
         ldd   tyy,u
         std   vy,u
         clr   vc,u
         lbra  g_hline

* the palette: 0 black, 100 ... 128 the ball (orange to dark red), 200 ... 202 the stars (grey,
* light grey, white)
setpal   clr   vx,u
         clr   vx+1,u
sp1      clr   vy,u
         clr   vx1,u
         clr   vy1,u
         clr   vy+1,u
         clr   vx1+1,u
         clr   vy1+1,u
         lda   vx+1,u
         cmpa  #100
         blo   sp9
         cmpa  #128
         bhi   sp2
         suba  #100
         pshs  a
         ldb   #8
         mul
         negb
         stb   vy+1,u              red = 255 - 8 k
         ldb   ,s
         lda   #6
         mul
         negb
         addb  #190
         stb   vx1+1,u             green = 190 - 6 k
         lda   #50
         sta   vy1+1,u
         leas  1,s
         bra   sp9
sp2      cmpa  #200
         blo   sp9
         cmpa  #202
         bhi   sp9
         suba  #200
         ldb   #80
         mul
         addb  #90
         stb   vy+1,u
         stb   vx1+1,u
         stb   vy1+1,u
sp9      lbsr  g_pal
         inc   vx+1,u
         bne   sp1
         rts

mapblk   fcb   9,0,$50,0,0,0,0,0,0,0,0,0,0,0
         fcb   9,0,$51,0,1,0,0,0,0,0,0,0,0,0
         fcb   9,0,$52,0,2,0,0,0,0,0,0,0,0,0
         fcb   9,0,$53,0,3,0,0,0,0,0,0,0,0,0
         fcb   9,0,$54,0,4,0,0,0,0,0,0,0,0,0
         fcb   9,0,$55,0,5,0,0,0,0,0,0,0,0,0
         fcb   9,0,$56,0,6,0,0,0,0,0,0,0,0,0
         fcb   9,0,$57,0,7,0,0,0,0,0,0,0,0,0

         use   gfxlib.inc

         emod
eom      equ   *
         end
