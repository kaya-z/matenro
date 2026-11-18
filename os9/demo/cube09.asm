* SPDX-License-Identifier: MIT
********************************************************************
* cube09 - the 6809 half of the 3D demo (the 8088 half is demo/cube88.asm, a bare 8088 program
* that draws a turning wire frame cube)
*
*   subsel 8088 ; cube09 s ; xrun -l=400 cube88.bin ; cube09 r      (the file demo3 of /d0)
*
* s: the palette, the picture black with the text of the console over it, the blocks $50-$57 of
* the 8088 memory become the first eight blocks of
* the picture.  r: the title; every second the number of frames of the 8088 (pixels 1 and 2 of
* the picture) is read and the frames per second
* are written on the text screen; a key ends it (it stops the 8088, too: pixel 0 = 254).  gfx off
* shows the console again.
* Credits: the module layout follows the sample commands of the NitrOS-9 project (GPL v2), as in
* os9/xrun.asm.  The code is original.
********************************************************************

         nam   cube09
         ttl   3D demo, the 6809 half

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
XE_US    equ   $14

         mod   eom,name,tylg,atrv,start,size

         org   0
         use   gfxvars.inc
kpath    rmb   1
t0       rmb   4
t1       rmb   4
tenth    rmb   2
frcur    rmb   2
lastfr   rmb   2
df       rmb   2
acc      rmb   2
quo      rmb   2
out      rmb   16
         rmb   200               stack
size     equ   .

name     fcs   /cube09/
         fcb   edition

msgnoreg fcc   "cube09: no frame buffer (Tang Nano 20K only)"
         fcb   C$CR
msguse   fcc   "usage: cube09 s | r  (see the header)"
         fcb   C$CR
termn    fcc   "/term"
         fcb   C$CR
title
         fcb   $1b,$25,$47,$1b,$5b,$32,$4a,$1b,$5b,$48,$0d,$0a
         fcb   $1b,$5b,$31,$3b,$33,$37,$6d,$20,$20,$e6,$91,$a9
         fcb   $e5,$a4,$a9,$e6,$a5,$bc,$20,$20,$4d,$41,$54,$45
         fcb   $4e,$52,$4f,$0d,$0a,$1b,$5b,$30,$3b,$33,$36,$6d
         fcb   $20,$20,$38,$30,$38,$38,$3a,$20,$e7,$ab,$8b,$e4
         fcb   $bd,$93,$20,$28,$33,$44,$29,$20,$20,$20,$36,$38
         fcb   $30,$39,$3a,$20,$46,$50,$53,$0d,$0a,$0d,$0a,$0d
         fcb   $0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d
         fcb   $0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d
         fcb   $0a,$0d,$0a,$0d,$0a,$0d,$0a,$0d,$0a,$1b,$5b,$30
         fcb   $3b,$33,$33,$6d,$20,$20,$e3,$82,$ad,$e3,$83,$bc
         fcb   $e3,$82,$92,$e6,$8a,$bc,$e3,$81,$99,$e3,$81,$a8
         fcb   $e7,$b5,$82,$e4,$ba,$86,$0d,$0a,$1b,$5b,$31,$3b
         fcb   $33,$32,$6d
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

* s: the palette, black, picture and text, the map of the blocks
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

* r: the title, then every second the frames per second
run      lda   #READ.
         leax  termn,pcr
         os9   I$Open
         lbcs  noreg
         sta   kpath,u
         lda   #1
         leax  title,pcr
         ldy   #titlee-title
         os9   I$Write
         lbsr  rdus0
         lbsr  getfr
         ldd   frcur,u
         std   lastfr,u
lp       ldx   #20
         os9   F$Sleep
         lda   kpath,u             a key?
         ldb   #SS.Ready
         os9   I$GetStt
         bcs   nokey
         lda   kpath,u
         leax  out,u
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
nokey    lbsr  rdus1
         leax  t1,u
         lbsr  elapsed
         ldd   tenth,u
         cmpd  #10                 at least a second
         blo   lp
         lbsr  getfr
         ldd   frcur,u
         subd  lastfr,u
         std   df,u
         ldd   frcur,u
         std   lastfr,u
         lbsr  rdus0               a new interval
* quo = df * 100 / tenth  (tenths of a frame per second)
         ldd   df,u
         lslb
         rola
         lslb
         rola
         std   quo,u               df * 4
         lslb
         rola
         lslb
         rola
         lslb
         rola
         std   acc,u               df * 32
         lslb
         rola                      df * 64
         addd  acc,u
         addd  quo,u               df * 100
         std   acc,u
         ldd   #0
         std   quo,u
dv1      ldd   acc,u
         subd  tenth,u
         bcs   dv2
         std   acc,u
         ldd   quo,u
         addd  #1
         std   quo,u
         bra   dv1
dv2      leay  out,u               "CR  FPS ttt.t  "
         lda   #C$CR
         sta   ,y+
         lda   #' '
         sta   ,y+
         sta   ,y+
         lda   #'F'
         sta   ,y+
         lda   #'P'
         sta   ,y+
         lda   #'S'
         sta   ,y+
         lda   #' '
         sta   ,y+
         ldd   quo,u
         ldx   #0
d3       cmpd  #100
         blo   d4
         subd  #100
         leax  1,x
         bra   d3
d4       pshs  d
         tfr   x,d
         addb  #'0'
         stb   ,y+
         puls  d
         ldx   #0
d5       cmpd  #10
         blo   d6
         subd  #10
         leax  1,x
         bra   d5
d6       pshs  d
         tfr   x,d
         addb  #'0'
         stb   ,y+
         lda   #'.'
         sta   ,y+
         puls  d
         addb  #'0'
         stb   ,y+
         lda   #' '
         sta   ,y+
         sta   ,y+
         lda   #1
         leax  out,u
         ldy   #13
         os9   I$Write
         lbra  lp

* the number of frames of the 8088 (pixels 1 and 2 of the picture) into frcur
getfr    ldd   #1
         std   vx,u
         clr   vy,u
         clr   vy+1,u
         lbsr  rdpix
         sta   frcur+1,u
         ldd   #2
         std   vx,u
         lbsr  rdpix
         sta   frcur,u
         rts

* A = the pixel (vx, vy), with the interrupts off (the window is shared with the other processes)
rdpix    pshs  cc
         orcc  #$50
         lbsr  g_beg
         lbsr  g_seta
         lda   >XDAT
         pshs  a
         lbsr  g_end
         puls  a
         puls  cc
         rts

* the microsecond counter (byte 0 latches the value)
rdus0    leay  t0,u
         bra   rdus
rdus1    leay  t1,u
rdus     pshs  cc
         orcc  #$50
         lda   #$80+XE_US
         sta   >XIDX
         lda   >XDAT
         sta   ,y
         lda   >XDAT
         sta   1,y
         lda   >XDAT
         sta   2,y
         lda   >XDAT
         sta   3,y
         puls  cc
         rts

* tenth = the number of tenths of a second between t0 and the counter at X (the difference
* divided by 100,000)
elapsed  ldd   2,x
         subd  t0+2,u
         std   gtmp,u
         ldd   ,x
         sbcb  t0+1,u
         sbca  t0,u
         std   gdx,u
         ldd   #0
         std   tenth,u
el1      ldd   gtmp,u
         subd  #$86A0
         std   gsx,u
         ldd   gdx,u
         sbcb  #1                  100,000 = $0001 86A0: the high word is the 16 bit D
         sbca  #0
         bcs   el9
         std   gdx,u
         ldd   gsx,u
         std   gtmp,u
         ldd   tenth,u
         addd  #1
         std   tenth,u
         bra   el1
el9      rts

* the palette: 0 black, 101 ... 112 the twelve edges (a colour wheel)
setpal   clr   vx,u
         clr   vx+1,u
sp1      clr   vy,u
         clr   vx1,u
         clr   vy1,u
         clr   vy+1,u
         clr   vx1+1,u
         clr   vy1+1,u
         lda   vx+1,u
         cmpa  #101
         blo   sp9
         cmpa  #112
         bhi   sp9
         suba  #101
         lsla
         lsla
         leax  wheel,pcr
         leax  a,x
         ldb   ,x
         stb   vy+1,u
         ldb   1,x
         stb   vx1+1,u
         ldb   2,x
         stb   vy1+1,u
sp9      lbsr  g_pal
         inc   vx+1,u
         bne   sp1
         rts
* red, green, blue (and a filler) of the colours 101 ... 112
wheel    fcb   255,64,64,0,   255,160,64,0,  255,255,64,0,  160,255,64,0
         fcb   64,255,64,0,   64,255,160,0,  64,255,255,0,  64,160,255,0
         fcb   64,64,255,0,   160,64,255,0,  255,64,255,0,  255,64,160,0

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
