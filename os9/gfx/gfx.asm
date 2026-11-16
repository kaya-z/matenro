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
dig      rmb   1
         use   gfxvars.inc
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
fn9      stb   vc,u
         lbsr  g_fill
         lbra  done

cmdtest  lbsr  g_beg
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
         lbsr  g_end
         lbra  done

* load file
cmdload  lbsr  skipw
         lda   #READ.
         os9   I$Open
         lbcs  nofile
         sta   path,u
         lbsr  g_beg
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
ld9      lbsr  g_end
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


* ---------------------------------------------------------------- the drawing: the
* numbers, then gfxlib.inc
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
         std   gacc,u
gn1      lda   ,x
         suba  #'0'
         cmpa  #9
         bhi   gn9
         sta   dig,u
         leax  1,x
         ldd   gacc,u
         lslb
         rola                      x2
         std   gtmp,u
         lslb
         rola
         lslb
         rola                      x8
         addd  gtmp,u              x10
         addb  dig,u
         adca  #0
         std   gacc,u
         bra   gn1
gn9      ldd   gacc,u
         rts

cmdpix   lbsr  skipw
         lbsr  getnum
         std   vx,u
         lbsr  getnum
         std   vy,u
         lbsr  getnum
         stb   vc,u
         lbsr  g_pix
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
         lbsr  g_line
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
         lbsr  g_box
         lbra  done
cmdrect  lbsr  getrect
         lbsr  g_rect
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
         lbsr  g_text
         lbra  done

         use   gfxlib.inc

         emod
eom      equ   *
         end
