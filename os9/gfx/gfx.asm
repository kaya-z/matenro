* SPDX-License-Identifier: MIT
********************************************************************
* gfx - the frame buffer of the HDMI screen of the Tang Nano 20K: 320 x 240 pixels of 8
* bits, shown doubled (640 x 480)
*
*   gfx on                show the frame buffer (instead of the text)
*   gfx over              show the frame buffer with the text of the console over it
* (where the text is not black)
*   gfx off               show the text again
*   gfx fill n            fill the picture with the byte n (0 .. 255; 0 = black)
*   gfx test              draw a test picture (blocks of the 3-3-2 colours)
*   gfx load file         read 76,800 bytes (a raw 320 x 240 picture, one byte per pixel)
* into the picture
*   gfx pal file          read 768 bytes (red, green, blue of the 256 entries; 0 .. 255
* each) as the palette
*   gfx pix x y c         one pixel of the colour byte c (x 0 .. 319, y 0 .. 239;
* outside: nothing)
*   gfx line x0 y0 x1 y1 c    a line (Bresenham)
*   gfx rect x y w h c    the outline of a rectangle;  gfx box x y w h c    a filled
* rectangle
*   gfx text x y fg bg string    the text (the 8 x 16 font of the HDMI screen, ASCII $20
* - $7E) at x y:
* the dots in fg, the rest of the cell in bg (numbers: decimal; a pixel takes about 60 us)
*
* The picture is in the SDRAM at physical $300000: above the 2 MB of OS-9, so it is written
* through the window of the cross link with
* HCTL.1 set ($FFC8: the window looks at the memory above 2 MB; the window address $100000
* is physical $300000).  The registers:
* GCTL $FFB8 (bit 0: show the frame buffer, bit 1: the text over it), PIDX $FFB9 (the
* palette entry), PDAT $FFBA
* (red, green, blue, one byte after the other;
* the third write sets the entry and the index goes on).  Without a palette the byte is a
* colour of the form rrrgggbb (3-3-2).
* Only the Tang Nano 20K machine has the registers: the simulator and the 9K say "no frame
* buffer".
*
* Credits: the module layout follows the sample commands of the NitrOS-9 project (GPL v2),
* as in os9/xrun.asm.
* The code is original.
********************************************************************

         nam   gfx
         ttl   The frame buffer of the HDMI screen

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

HCTL     equ   $FFC8
GCTL     equ   $FFB8
PIDX     equ   $FFB9
PDAT     equ   $FFBA
XIDX     equ   $FFCD
XDAT     equ   $FFCE
XE_WA    equ   $0A
XE_WD    equ   $0D

         mod   eom,name,tylg,atrv,start,size

         org   0
path     rmb   1
rows     rmb   1
gb       rmb   1                 the green band (0 .. 7), a band is 30 rows
gc       rmb   1
rb       rmb   1                 the red band, a band is 40 columns
rc       rmb   1
yy       rmb   1
vx       rmb   2                 the drawing: the position, the second point, the colours
vy       rmb   2
vx1      rmb   2
vy1      rmb   2
vc       rmb   1
vbg      rmb   1
acc      rmb   2
tmp      rmb   2
dig      rmb   1
hi       rmb   1
dx       rmb   2
dy       rmb   2
sx       rmb   2
sy       rmb   2
errv     rmb   2
ln       rmb   2
ox       rmb   2
oy       rmb   2
ow       rmb   2
oh       rmb   2
nx       rmb   1
bits     rmb   1
buf      rmb   256
         rmb   200               stack
size     equ   .

name     fcs   /gfx/
         fcb   edition

msgnoreg fcc   "gfx: no frame buffer (this machine has no HDMI frame buffer)"
         fcb   C$CR
msgfile  fcc   "gfx: cannot read the file"
         fcb   C$CR
msguse   fcc   "usage: gfx on|over|off|fill|test|load|pal|pix|line|rect|box|text (MANUAL 6.8.3)"
         fcb   C$CR

start    lda   #$FE                is there a register?  after $FE a read of HCTL gives 2 (plain RAM gives $FE)
         sta   >HCTL
         lda   >HCTL
         cmpa  #2
         lbne  noreg
         clr   >HCTL
         lbsr  skipsp
         lda   ,x+
         anda  #$DF
         cmpa  #'O'
         beq   cmdo
         cmpa  #'F'
         lbeq  cmdfill
         cmpa  #'T'
         lbeq  cmdt
         cmpa  #'L'
         lbeq  cmdl
         cmpa  #'P'
         lbeq  cmdp
         cmpa  #'B'
         lbeq  cmdbox
         cmpa  #'R'
         lbeq  cmdrect
usage    leax  msguse,pcr
         bra   err
cmdo     lda   ,x+
         anda  #$DF
         cmpa  #'N'
         beq   on
         cmpa  #'V'
         beq   over
         cmpa  #'F'
         lbne  usage
         clra
         sta   >GCTL
         bra   done
on       lda   #1
         bra   setg
over     lda   #3                  the picture and the text over it
setg     sta   >GCTL
done     clrb
         os9   F$Exit
noreg    clr   >HCTL
         leax  msgnoreg,pcr
         bra   err
nofile   leax  msgfile,pcr
err      lda   #2
         ldy   #80
         os9   I$WritLn
         ldb   #1
         os9   F$Exit

* X = behind the word: skip to the next word
skipsp   lda   ,x+
         cmpa  #' '
         beq   skipsp
         leax  -1,x
         rts
skipw    lda   ,x+
         cmpa  #' '
         beq   skipsp
         cmpa  #C$CR
         bne   skipw
         leax  -1,x
         rts

* the window at the picture (physical $300000): HCTL.1 on, window address $100000
fbbeg    lda   >HCTL
         ora   #2
         sta   >HCTL
         ldb   #XE_WA+$80
         stb   >XIDX
         lda   #$10
         sta   >XDAT
         clra
         sta   >XDAT
         sta   >XDAT
         ldb   #XE_WD
         stb   >XIDX
         rts
fbend    lda   >HCTL
         anda  #$FD
         sta   >HCTL
         rts

* fill n
cmdfill  lbsr  skipw
         clrb                      the number
fn1      lda   ,x+
         suba  #'0'
         cmpa  #9
         bhi   fn9
         pshs  a
         lda   #10
         mul                       B * 10 (the number stays below 256)
         addb  ,s+
         bra   fn1
fn9      pshs  b
         lbsr  fbbeg
         puls  b
         ldx   #300                300 * 256 = 76,800
fl1      clra
fl2      stb   >XDAT
         deca
         bne   fl2
         leax  -1,x
         bne   fl1
         lbsr  fbend
         lbra  done

* test: the blocks of 3-3-2 colours: the red band every 40 columns, the green band every 30
* rows, the blue is (x + y) mod 4
cmdtest  lbsr  fbbeg
         clr   gb,u
         clr   gc,u
         clr   yy,u
         lda   #240
         sta   rows,u
ty1      clr   rb,u
         clr   rc,u
         ldx   #320
         lda   yy,u                the blue of the first pixel: y mod 4
         anda  #3
         sta   buf,u
tx1      lda   rb,u                rrr ggg bb
         lsla
         lsla
         lsla
         ora   gb,u
         lsla
         lsla
         ora   buf,u
         sta   >XDAT
         lda   buf,u               the blue: +1, mod 4
         inca
         anda  #3
         sta   buf,u
         inc   rc,u
         lda   rc,u
         cmpa  #40
         bne   tx2
         clr   rc,u
         inc   rb,u
tx2      leax  -1,x
         bne   tx1
         inc   yy,u
         inc   gc,u
         lda   gc,u
         cmpa  #30
         bne   ty2
         clr   gc,u
         inc   gb,u
ty2      dec   rows,u
         bne   ty1
         lbsr  fbend
         lbra  done

* load file
cmdload  lbsr  skipw
         lda   #READ.
         os9   I$Open
         lbcs  nofile
         sta   path,u
         lbsr  fbbeg
ld1      lda   path,u
         leax  buf,u
         ldy   #256
         os9   I$Read
         bcs   ld9
         leax  buf,u
ld2      lda   ,x+
         sta   >XDAT
         leay  -1,y
         bne   ld2
         bra   ld1
ld9      lbsr  fbend
         lda   path,u
         os9   I$Close
         lbra  done

* pal file
cmdpal   lbsr  skipw
         lda   #READ.
         os9   I$Open
         lbcs  nofile
         sta   path,u
         clra
         sta   >PIDX
pl1      lda   path,u
         leax  buf,u
         ldy   #256
         os9   I$Read
         bcs   pl9
         leax  buf,u
pl2      lda   ,x+
         sta   >PDAT
         leay  -1,y
         bne   pl2
         bra   pl1
pl9      lda   path,u
         os9   I$Close
         lbra  done


* ---------------------------------------------------------------- the drawing
* the second letter decides: TEST or TEXT, LOAD or LINE, PAL or PIX
cmdt     lda   1,x
         anda  #$DF
         cmpa  #'X'
         lbeq  cmdtext
         lbra  cmdtest
cmdl     lda   ,x
         anda  #$DF
         cmpa  #'I'
         lbeq  cmdline
         lbra  cmdload
cmdp     lda   ,x
         anda  #$DF
         cmpa  #'I'
         lbeq  cmdpix
         lbra  cmdpal

* a decimal number at X (spaces in front) -> D; X behind it
getnum   lbsr  skipsp
         clra
         clrb
         std   acc,u
gn1      lda   ,x
         suba  #'0'
         cmpa  #9
         bhi   gn9
         sta   dig,u
         leax  1,x
         ldd   acc,u
         lslb
         rola                      x2
         std   tmp,u
         lslb
         rola
         lslb
         rola                      x8
         addd  tmp,u               x10
         addb  dig,u
         adca  #0
         std   acc,u
         bra   gn1
gn9      ldd   acc,u
         rts

* D = - D
negd     coma
         comb
         addd  #1
         rts

* the window at the pixel (vx, vy): offset = vy * 320 + vx, window address $100000 + offset
seta     ldb   vy+1,u
         lda   #64
         mul
         std   tmp,u               vy * 64
         lda   vy+1,u
         clrb                      vy * 256
         clr   hi,u
         addd  tmp,u
         bcc   sa1
         inc   hi,u
sa1      addd  vx,u
         bcc   sa2
         inc   hi,u
sa2      std   tmp,u
         lda   hi,u
         ora   #$10
         ldb   #XE_WA+$80
         stb   >XIDX
         sta   >XDAT
         lda   tmp,u
         sta   >XDAT
         lda   tmp+1,u
         sta   >XDAT
         ldb   #XE_WD
         stb   >XIDX
         rts

* one pixel (vx, vy) in the colour vc; outside of the picture: nothing
plot     ldd   vx,u
         cmpd  #320
         bhs   plx
         ldd   vy,u
         cmpd  #240
         bhs   plx
         lbsr  seta
         lda   vc,u
         sta   >XDAT
plx      rts

* ln pixels from (vx, vy) to the right, in vc
hline    ldd   vy,u
         cmpd  #240
         bhs   hl9
         ldd   vx,u
         cmpd  #320
         bhs   hl9
         ldd   #320
         subd  vx,u                the room until the right edge
         cmpd  ln,u
         bhs   hl1
         std   ln,u
hl1      ldy   ln,u
         beq   hl9
         lbsr  seta
         lda   vc,u
hl2      sta   >XDAT
         leay  -1,y
         bne   hl2
hl9      rts

* ln pixels from (vx, vy) downwards, in vc
vline    ldy   ln,u
         beq   vl9
vl1      pshs  y
         lbsr  plot
         puls  y
         ldd   vy,u
         addd  #1
         std   vy,u
         leay  -1,y
         bne   vl1
vl9      rts

* the numbers x y c  /  x0 y0 x1 y1 c  /  x y w h c  into the variables
cmdpix   lbsr  skipw
         lbsr  getnum
         std   vx,u
         lbsr  getnum
         std   vy,u
         lbsr  getnum
         stb   vc,u
         lbsr  fbbeg
         lbsr  plot
         lbsr  fbend
         lbra  done

cmdline  lbsr  skipw
         lbsr  getnum
         std   vx,u
         lbsr  getnum
         std   vy,u
         lbsr  getnum
         std   vx1,u
         lbsr  getnum
         std   vy1,u
         lbsr  getnum
         stb   vc,u
         lbsr  fbbeg
* dx = |x1 - x0|, sx = +1 / -1;  dy = - |y1 - y0|, sy = +1 / -1;  err = dx + dy
         ldd   vx1,u
         subd  vx,u
         bpl   ln1
         lbsr  negd
         std   dx,u
         ldd   #-1
         bra   ln2
ln1      std   dx,u
         ldd   #1
ln2      std   sx,u
         ldd   vy1,u
         subd  vy,u
         bpl   ln3
         lbsr  negd
         std   dy,u
         ldd   #-1
         bra   ln4
ln3      std   dy,u
         ldd   #1
ln4      std   sy,u
         ldd   dy,u
         lbsr  negd
         std   dy,u                dy = -|y1 - y0|
         addd  dx,u
         std   errv,u
ln5      lbsr  plot
         ldd   vx,u
         cmpd  vx1,u
         bne   ln6
         ldd   vy,u
         cmpd  vy1,u
         lbeq  ln9
ln6      ldd   errv,u
         lslb
         rola                      e2 = 2 * err
         std   tmp,u
         cmpd  dy,u
         blt   ln7                 e2 < dy: no step in x
         ldd   errv,u
         addd  dy,u
         std   errv,u
         ldd   vx,u
         addd  sx,u
         std   vx,u
ln7      ldd   tmp,u
         cmpd  dx,u
         bgt   ln8                 e2 > dx: no step in y
         ldd   errv,u
         addd  dx,u
         std   errv,u
         ldd   vy,u
         addd  sy,u
         std   vy,u
ln8      lbra  ln5
ln9      lbsr  fbend
         lbra  done

* x y w h c -> ox oy ow oh vc
getrect  lbsr  skipw
         lbsr  getnum
         std   ox,u
         lbsr  getnum
         std   oy,u
         lbsr  getnum
         std   ow,u
         lbsr  getnum
         std   oh,u
         lbsr  getnum
         stb   vc,u
         rts

cmdbox   lbsr  getrect
         lbsr  fbbeg
         ldd   oy,u
         std   vy,u
         ldy   oh,u
         lbeq  bx9
bx1      pshs  y
         ldd   ox,u
         std   vx,u
         ldd   ow,u
         std   ln,u
         lbsr  hline
         ldd   vy,u
         addd  #1
         std   vy,u
         puls  y
         leay  -1,y
         bne   bx1
bx9      lbsr  fbend
         lbra  done

cmdrect  lbsr  getrect
         lbsr  fbbeg
         ldd   ox,u                top: the row oy
         std   vx,u
         ldd   oy,u
         std   vy,u
         ldd   ow,u
         std   ln,u
         lbsr  hline
         ldd   ox,u                bottom: the row oy + h - 1
         std   vx,u
         ldd   oy,u
         addd  oh,u
         subd  #1
         std   vy,u
         ldd   ow,u
         std   ln,u
         lbsr  hline
         ldd   ox,u                left: the column ox
         std   vx,u
         ldd   oy,u
         std   vy,u
         ldd   oh,u
         std   ln,u
         lbsr  vline
         ldd   ox,u                right: the column ox + w - 1
         addd  ow,u
         subd  #1
         std   vx,u
         ldd   oy,u
         std   vy,u
         ldd   oh,u
         std   ln,u
         lbsr  vline
         lbsr  fbend
         lbra  done

* text x y fg bg string
cmdtext  lbsr  skipw
         lbsr  getnum
         std   ox,u
         lbsr  getnum
         std   oy,u
         lbsr  getnum
         stb   vc,u
         lbsr  getnum
         stb   vbg,u
         lbsr  skipsp
         lbsr  fbbeg
tt1      lda   ,x+                 the next character
         cmpa  #C$CR
         lbeq  tt9
         cmpa  #' '
         bhs   tt2
         lda   #' '
tt2      cmpa  #$7E
         bls   tt3
         lda   #' '
tt3      pshs  x
         suba  #' '
         ldb   #16
         mul                       the glyph: (c - $20) * 16
         leax  gfont,pcr
         leax  d,x
         ldd   ox,u
         cmpd  #312
         lbhi  tt8                 not even a cell is left: the end
         clr   nx,u                the line of the glyph
tt4      ldd   ox,u
         std   vx,u
         ldb   nx,u
         clra
         addd  oy,u
         std   vy,u
         cmpd  #240
         bhs   tt7                 below the picture
         lbsr  seta
         lda   ,x
         sta   bits,u
         ldb   #8
tt5      lda   vc,u
         lsl   bits,u
         bcs   tt6
         lda   vbg,u
tt6      sta   >XDAT
         decb
         bne   tt5
tt7      leax  1,x
         inc   nx,u
         lda   nx,u
         cmpa  #16
         bne   tt4
         ldd   ox,u                the next cell
         addd  #8
         std   ox,u
         puls  x
         lbra  tt1
tt8      puls  x
tt9      lbsr  fbend
         lbra  done

         use   gfxfont.inc

         emod
eom      equ   *
         end
