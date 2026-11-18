* SPDX-License-Identifier: MIT
********************************************************************
* mand09 - the 6809 half of the Mandelbrot race of the demo (the 8088 half is demo/mand88.asm, an
* MS-DOS program)
*
*   subsel 8088 ; mand09 s ; xrun -l=400 mand88.bin ; mand09 r      (the file race of /d0)
*
* The picture of the HDMI screen (320 x 240) is the Mandelbrot set, upside down mirror symmetric:
* the 8088 draws the 120 rows above the middle (from the
* middle up), this program the 120 rows below it (from the middle down); both have the same work.
* The two start together (a handshake through the
* pixel 0 of the picture: the 8088 writes 254 = ready, this program 253 = go); the picture is 255
* until it is drawn.  When both have finished, the time
* of each is written on the picture (the time of the 8088 is the moment when this program sees
* the last pixel of the 8088: the pixel 319 of the row 0).
* Fixed point with 8 fraction bits like duo.  Credits: the module layout follows the sample
* commands of the NitrOS-9 project (GPL v2), as in os9/xrun.asm.
********************************************************************

         nam   mand09
         ttl   Mandelbrot race, the 6809 half

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
MAXIT    equ   24

         mod   eom,name,tylg,atrv,start,size

         org   0
         use   gfxvars.inc
pp       rmb   2
qq       rmb   2
sg       rmb   1
acc      rmb   2
ca       rmb   2
cb       rmb   2
aa       rmb   2
bb       rmb   2
a2       rmb   2
b2       rmb   2
it       rmb   1
xc       rmb   2
k        rmb   1
done8    rmb   1                 the 8088 has been seen to be ready: 1
t0       rmb   4                 the microsecond counter: start, end of the 6809, end of the 8088
t1       rmb   4
t8       rmb   4
tenth    rmb   2
num      rmb   4
rem      rmb   1
dbuf     rmb   12
xp       rmb   2
dig      rmb   12
buf      rmb   320
         rmb   200               stack
size     equ   .

name     fcs   /mand09/
         fcb   edition

msgnoreg fcc   "mand09: no frame buffer (Tang Nano 20K only)"
         fcb   C$CR
msgwait  fcc   "mand09: waiting for the 8088"
         fcb   C$CR
msgrun   fcc   "mand09: go"
         fcb   C$CR
s8       fcc   "8088 "
         fcb   0
s6       fcc   "6809 "
         fcb   0

err      lda   #2
         ldy   #80
         os9   I$WritLn
         ldb   #1
         os9   F$Exit

start    pshs  x
         lbsr  g_probe
         puls  x
         lbne  noreg
         lbsr  skipsp
         lda   ,x
         anda  #$DF
         cmpa  #'S'
         beq   setup
         cmpa  #'R'
         lbeq  wr2
         leax  msguse,pcr
         lbra  err
* mand09 s: the palette, the picture 255 (not drawn yet), shown;
* the blocks $50-$54 of the 8088 memory become the first five blocks of the picture
setup    lbsr  setpal
         lda   #255
         sta   vc,u
         lbsr  g_fill
         lda   #1
         lbsr  g_mode
         leax  mapblk,pcr
         ldb   #5
mp1      pshs  b,x
         lbsr  g_run
         puls  b,x
         leax  14,x
         decb
         bne   mp1
         clrb
         os9   F$Exit
* mand09 r: the 8088 is running (it waits for 253 in the pixel 0)
skipsp   lda   ,x+
         cmpa  #' '
         beq   skipsp
         leax  -1,x
         rts
mapblk   fcb   9,0,$50,0,0,0,0,0,0,0,0,0,0,0
         fcb   9,0,$51,0,1,0,0,0,0,0,0,0,0,0
         fcb   9,0,$52,0,2,0,0,0,0,0,0,0,0,0
         fcb   9,0,$53,0,3,0,0,0,0,0,0,0,0,0
         fcb   9,0,$54,0,4,0,0,0,0,0,0,0,0,0
msguse   fcc   "usage: mand09 s | r  (see the header)"
         fcb   C$CR
wr2      ldd   #0
         std   vx,u
         std   vy,u
         lda   #253                go
         lbsr  wrpix
         lbsr  rdus0
         clr   done8,u
         leax  msgrun,pcr
         lda   #1
         ldy   #80
         os9   I$WritLn
         clr   k,u
rowlp    lbsr  row
         ldx   #1                  one tick for the others: the console must answer while the picture is drawn
         os9   F$Sleep
         inc   k,u
         lda   k,u
         cmpa  #120
         blo   rowlp
         lbsr  rdus1
* the 8088: it has finished when the pixel 319 of the row 0 is not 255
wt1      tst   done8,u
         bne   wt3
         lbsr  chk8
         tst   done8,u
         bne   wt3
         ldx   #10
         os9   F$Sleep
         bra   wt1
wt3      lbsr  texts
         leax  t8,u
         lbsr  pdiff
         leax  t1,u
         lbsr  pdiff
         clrb
         os9   F$Exit
noreg    leax  msgnoreg,pcr
         lbra  err

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
* the pixel (vx, vy) = A
wrpix    pshs  cc,a
         orcc  #$50
         lbsr  g_beg
         lbsr  g_seta
         lda   1,s                 (the stack: CC, then the value)
         sta   >XDAT
         lbsr  g_end
         puls  a,cc
         rts

* has the 8088 finished? (pixel 319 of the row 0 is not 255): done8 = 1 and the time t8
chk8     ldd   #319
         std   vx,u
         ldd   #0
         std   vy,u
         lbsr  rdpix
         cmpa  #255
         beq   ck9
         lda   #1
         sta   done8,u
         leay  t8,u
         lbsr  rdus
ck9      rts

* the row 120 + k: the 320 pixels into buf, then to the picture; after it a look at the 8088
row      lda   k,u
         ldb   #3
         mul
         addd  #1
         std   cb,u                cb = 3 k + 1
         ldd   #-576
         std   ca,u
         leax  buf,u
         stx   xp,u
         ldd   #320
         std   xc,u
pix      ldd   ca,u
         std   aa,u
         tfr   d,x
         lbsr  mulq
         std   a2,u
         ldd   cb,u
         std   bb,u
         tfr   d,x
         lbsr  mulq
         std   b2,u
         clr   it,u
iter     ldd   a2,u                t = a2 - b2 + ca
         subd  b2,u
         addd  ca,u
         pshs  d
         ldd   aa,u                b = 2*a*b + cb
         ldx   bb,u
         lbsr  mulq
         lslb
         rola
         addd  cb,u
         std   bb,u
         puls  d
         std   aa,u                a = t
         tfr   d,x
         lbsr  mulq
         std   a2,u
         ldd   bb,u
         tfr   d,x
         lbsr  mulq
         std   b2,u
         ldd   a2,u
         addd  b2,u
         cmpd  #1025               a*a+b*b > 4
         bhs   esc
         inc   it,u
         lda   it,u
         cmpa  #MAXIT
         blo   iter
         clra                      inside: colour 0
         bra   put
esc      lda   it,u
         inca
put      ldx   xp,u
         sta   ,x+
         stx   xp,u
         ldd   ca,u
         addd  #3
         std   ca,u
         ldd   xc,u
         subd  #1
         std   xc,u
         lbne  pix
* the row to the picture
         clra
         ldb   k,u
         addd  #120
         std   vy,u
         ldd   #0
         std   vx,u
         lbsr  g_beg
         lbsr  g_seta
         leax  buf,u
         ldy   #320
rw1      lda   ,x+
         sta   >XDAT
         leay  -1,y
         bne   rw1
         lbsr  g_end
         tst   done8,u
         bne   rw9
         lbsr  chk8
rw9      rts

* D = D*X >> 8, signed Q8 (the values are below 4096 in magnitude)
mulq     std   pp,u
         stx   qq,u
         lda   pp,u
         eora  qq,u
         anda  #$80
         sta   sg,u
         tst   pp,u
         bpl   mq1
         ldd   pp,u
         coma
         comb
         addd  #1
         std   pp,u
mq1      tst   qq,u
         bpl   mq2
         ldd   qq,u
         coma
         comb
         addd  #1
         std   qq,u
mq2      lda   pp+1,u
         ldb   qq+1,u
         mul
         tfr   a,b
         clra
         std   acc,u
         lda   pp,u
         ldb   qq+1,u
         mul
         addd  acc,u
         std   acc,u
         lda   pp+1,u
         ldb   qq,u
         mul
         addd  acc,u
         std   acc,u
         lda   pp,u
         ldb   qq,u
         mul
         tfr   b,a
         clrb
         addd  acc,u
         tst   sg,u
         beq   mq3
         coma
         comb
         addd  #1
mq3      rts

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

* the palette: 0 black, 1 ... MAXIT a gradient, 250 white, 255 (not drawn yet) dark grey
setpal   clr   vx+1,u
         clr   vx,u
sp1      lda   vx+1,u
         clr   vy,u
         clr   vx1,u
         clr   vy1,u
         clr   vy1+1,u
         clr   vy+1,u
         clr   vx1+1,u
         cmpa  #0
         beq   sp9
         cmpa  #MAXIT
         bhi   sp2
         ldb   #10                 red = 10 n, green = 8 n, blue = 255 - 10 n
         mul
         stb   vy+1,u
         lda   vx+1,u
         ldb   #8
         mul
         stb   vx1+1,u
         lda   vx+1,u
         ldb   #10
         mul
         negb
         stb   vy1+1,u
         bra   sp9
sp2      cmpa  #250
         bne   sp3
         lda   #255
         sta   vy+1,u
         sta   vx1+1,u
         sta   vy1+1,u
         bra   sp9
sp3      cmpa  #255
         bne   sp9
         lda   #40
         sta   vy+1,u
         sta   vx1+1,u
         sta   vy1+1,u
sp9      lbsr  g_pal
         inc   vx+1,u
         bne   sp1
         rts

* the microseconds t(X) - t0 on the console, in decimal (the check of the times)
pdiff    ldd   2,x
         subd  t0+2,u
         std   num+2,u
         ldd   ,x
         sbcb  t0+1,u
         sbca  t0,u
         std   num,u
         lbsr  u32dec
         leax  dig,u
         lda   #C$CR
         sta   10,x
         lda   #1
         ldy   #12
         os9   I$WritLn
         rts
* the 32 bit number num -> 10 decimal digits at dig (ASCII with leading zeros); num is used up
u32dec   leax  dig+10,u
         ldb   #10
ud1      pshs  b,x
         clr   rem,u
         ldb   #32
ud2      asl   num+3,u
         rol   num+2,u
         rol   num+1,u
         rol   num,u
         rol   rem,u
         lda   rem,u
         cmpa  #10
         blo   ud3
         suba  #10
         sta   rem,u
         inc   num+3,u
ud3      decb
         bne   ud2
         puls  b,x
         lda   rem,u
         adda  #'0'
         sta   ,-x
         decb
         bne   ud1
         rts

* the two times on the picture: "8088 12.3 s" at the top, "6809 45.6 s" at the bottom
texts    leax  t8,u
         lbsr  elapsed
         lbsr  fmt
         ldd   #8
         std   ox,u
         ldd   #4
         std   oy,u
         leax  s8,pcr
         lbsr  puts
         ldd   #218
         std   oy,u
         ldd   #8
         std   ox,u
         leax  t1,u
         lbsr  elapsed
         lbsr  fmt
         leax  s6,pcr
         lbsr  puts
         rts
puts     lda   #250
         sta   vc,u
         clr   vbg,u
         pshs  x
         lbsr  g_text
         puls  x
         leax  dig,u
         lda   #250
         sta   vc,u
         clr   vbg,u
         lbra  g_text

* tenth = (the number of tenths of a second between t0 and the counter at X) (the 32 bit
* difference divided by 100,000)
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

* dig = "ttt.t s" from tenth (0 ... 9999)
fmt      leay  dig,u
         ldd   tenth,u
         ldx   #0
f1       cmpd  #1000
         blo   f2
         subd  #1000
         leax  1,x
         bra   f1
f2       pshs  d
         tfr   x,d
         lbsr  digit
         puls  d
         ldx   #0
f3       cmpd  #100
         blo   f4
         subd  #100
         leax  1,x
         bra   f3
f4       pshs  d
         tfr   x,d
         lbsr  digit
         puls  d
         ldx   #0
f5       cmpd  #10
         blo   f6
         subd  #10
         leax  1,x
         bra   f5
f6       pshs  d
         tfr   x,d
         lbsr  digit
         lda   #'.'
         sta   ,y+
         puls  d
         addb  #'0'
         stb   ,y+
         lda   #' '
         sta   ,y+
         lda   #'s'
         sta   ,y+
         clr   ,y
         rts
digit    tfr   b,a
         adda  #'0'
         sta   ,y+
         rts

         use   gfxlib.inc

         emod
eom      equ   *
         end
