* gfxlib.inc - the drawing of the frame buffer of the HDMI screen of the Tang Nano 20K
* (os9/gfx/gfx.asm, the BDOS of cpm and the BIOS of dos use it)
*
* The picture (320 x 240 bytes) is in the SDRAM at physical $300000: written through the
* window of the cross link with HCTL.1 set.  The caller
* has U = the data area with the variables of gfxvars.inc and the definitions XIDX XDAT
* XE_WA XE_WD of the cross link.  Every g_ routine sets the
* window itself (and takes it away); X is used.  A pixel outside of the picture is not
* drawn.
*   g_probe          Z set if the registers are there (the machines without them: plain RAM)
*   g_pix            (vx, vy) in vc
*   g_line           (vx, vy) to (vx1, vy1) in vc  (Bresenham)
*   g_rect / g_box   the outline / the filled rectangle at (ox, oy) of ow x oh in vc
*   g_text           X = the text (up to CR or 0) at (ox, oy): the dots in vc, the rest
* of the cells in vbg
*   g_fill           the whole picture in vc
*   g_mode           A = 0 text, 1 picture, 3 picture with the text over it
*   g_pal            the palette entry vx (the low byte) = the red vy, the green vx1, the
* blue vy1 (the low bytes)
*   g_beg / g_end    the window on / off (for a caller that writes XDAT itself)

HCTL     equ   $FFC8
GCTL     equ   $FFB8
PIDX     equ   $FFB9
PDAT     equ   $FFBA

g_probe  lda   >HCTL               is there a register?  after $FE a read of HCTL gives 2 (plain RAM gives $FE)
         pshs  a                   (bit 0 of HCTL says that the kanji image is loaded: it stays)
         lda   #$FE
         sta   >HCTL
         lda   >HCTL
         cmpa  #2
         pshs  cc
         lda   1,s
         anda  #1
         sta   >HCTL
         puls  cc
         leas  1,s
         rts

* the window on the picture (HCTL.1 on, window address $100000 = physical $300000)
g_beg    lda   >HCTL
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
g_end    lda   >HCTL
         anda  #$FD
         sta   >HCTL
         rts

* D = - D
g_negd   coma
         comb
         addd  #1
         rts

* the window at the pixel (vx, vy): offset = vy * 320 + vx, window address $100000 + offset
g_seta   ldb   vy+1,u
         lda   #64
         mul
         std   gtmp,u              vy * 64
         lda   vy+1,u
         clrb                      vy * 256
         clr   ghi,u
         addd  gtmp,u
         bcc   zgs1
         inc   ghi,u
zgs1      addd  vx,u
         bcc   zgs2
         inc   ghi,u
zgs2      std   gtmp,u
         lda   ghi,u
         ora   #$10
         ldb   #XE_WA+$80
         stb   >XIDX
         sta   >XDAT
         lda   gtmp,u
         sta   >XDAT
         lda   gtmp+1,u
         sta   >XDAT
         ldb   #XE_WD
         stb   >XIDX
         rts

* one pixel (vx, vy) in the colour vc; outside of the picture: nothing (the window must
* be on)
g_plot   ldd   vx,u
         cmpd  #320
         bhs   zgp9
         ldd   vy,u
         cmpd  #240
         bhs   zgp9
         lbsr  g_seta
         lda   vc,u
         sta   >XDAT
zgp9      rts

* gln pixels from (vx, vy) to the right, in vc (the window must be on)
g_hline  ldd   vy,u
         cmpd  #240
         bhs   zgh9
         ldd   vx,u
         cmpd  #320
         bhs   zgh9
         ldd   #320
         subd  vx,u                the room until the right edge
         cmpd  gln,u
         bhs   zgh1
         std   gln,u
zgh1      ldy   gln,u
         beq   zgh9
         lbsr  g_seta
         lda   vc,u
zgh2      sta   >XDAT
         leay  -1,y
         bne   zgh2
zgh9      rts

* gln pixels from (vx, vy) downwards, in vc (the window must be on)
g_vline  ldy   gln,u
         beq   zgv9
zgv1      pshs  y
         lbsr  g_plot
         puls  y
         ldd   vy,u
         addd  #1
         std   vy,u
         leay  -1,y
         bne   zgv1
zgv9      rts

g_pix    lbsr  g_beg
         lbsr  g_plot
         lbra  g_end

g_line   lbsr  g_beg
* dx = |x1 - x0|, sx = +1 / -1;  dy = - |y1 - y0|, sy = +1 / -1;  err = dx + dy
         ldd   vx1,u
         subd  vx,u
         bpl   zgl1
         lbsr  g_negd
         std   gdx,u
         ldd   #-1
         bra   zgl2
zgl1      std   gdx,u
         ldd   #1
zgl2      std   gsx,u
         ldd   vy1,u
         subd  vy,u
         bpl   zgl3
         lbsr  g_negd
         std   gdy,u
         ldd   #-1
         bra   zgl4
zgl3      std   gdy,u
         ldd   #1
zgl4      std   gsy,u
         ldd   gdy,u
         lbsr  g_negd
         std   gdy,u               dy = -|y1 - y0|
         addd  gdx,u
         std   gerr,u
zgl5      lbsr  g_plot
         ldd   vx,u
         cmpd  vx1,u
         bne   zgl6
         ldd   vy,u
         cmpd  vy1,u
         lbeq  zgl9
zgl6      ldd   gerr,u
         lslb
         rola                      e2 = 2 * err
         std   gtmp,u
         cmpd  gdy,u
         blt   zgl7                 e2 < dy: no step in x
         ldd   gerr,u
         addd  gdy,u
         std   gerr,u
         ldd   vx,u
         addd  gsx,u
         std   vx,u
zgl7      ldd   gtmp,u
         cmpd  gdx,u
         bgt   zgl8                 e2 > dx: no step in y
         ldd   gerr,u
         addd  gdx,u
         std   gerr,u
         ldd   vy,u
         addd  gsy,u
         std   vy,u
zgl8      lbra  zgl5
zgl9      lbra  g_end

g_box    lbsr  g_beg
         ldd   oy,u
         std   vy,u
         ldy   oh,u
         lbeq  zgb9
zgb1      pshs  y
         ldd   ox,u
         std   vx,u
         ldd   ow,u
         std   gln,u
         lbsr  g_hline
         ldd   vy,u
         addd  #1
         std   vy,u
         puls  y
         leay  -1,y
         bne   zgb1
zgb9      lbra  g_end

g_rect   lbsr  g_beg
         ldd   ox,u                top: the row oy
         std   vx,u
         ldd   oy,u
         std   vy,u
         ldd   ow,u
         std   gln,u
         lbsr  g_hline
         ldd   ox,u                bottom: the row oy + h - 1
         std   vx,u
         ldd   oy,u
         addd  oh,u
         subd  #1
         std   vy,u
         ldd   ow,u
         std   gln,u
         lbsr  g_hline
         ldd   ox,u                left: the column ox
         std   vx,u
         ldd   oy,u
         std   vy,u
         ldd   oh,u
         std   gln,u
         lbsr  g_vline
         ldd   ox,u                right: the column ox + w - 1
         addd  ow,u
         subd  #1
         std   vx,u
         ldd   oy,u
         std   vy,u
         ldd   oh,u
         std   gln,u
         lbsr  g_vline
         lbra  g_end

g_text   lbsr  g_beg
zgt1      lda   ,x+                 the next character
         cmpa  #C$CR
         lbeq  zgt9
         tsta
         lbeq  zgt9
         cmpa  #' '
         bhs   zgt2
         lda   #' '
zgt2      cmpa  #$7E
         bls   zgt3
         lda   #' '
zgt3      pshs  x
         suba  #' '
         ldb   #16
         mul                       the glyph: (c - $20) * 16
         leax  gfont,pcr
         leax  d,x
         ldd   ox,u
         cmpd  #312
         lbhi  zgt8                 not even a cell is left: the end
         clr   gnx,u               the line of the glyph
zgt4      ldd   ox,u
         std   vx,u
         ldb   gnx,u
         clra
         addd  oy,u
         std   vy,u
         cmpd  #240
         bhs   zgt7                 below the picture
         lbsr  g_seta
         lda   ,x
         sta   gbits,u
         ldb   #8
zgt5      lda   vc,u
         lsl   gbits,u
         bcs   zgt6
         lda   vbg,u
zgt6      sta   >XDAT
         decb
         bne   zgt5
zgt7      leax  1,x
         inc   gnx,u
         lda   gnx,u
         cmpa  #16
         bne   zgt4
         ldd   ox,u                the next cell
         addd  #8
         std   ox,u
         puls  x
         lbra  zgt1
zgt8      puls  x
zgt9      lbra  g_end

g_fill   lbsr  g_beg
         ldx   #300                300 * 256 = 76,800
         ldb   vc,u
zgf1      clra
zgf2      stb   >XDAT
         deca
         bne   zgf2
         leax  -1,x
         bne   zgf1
         lbra  g_end

g_mode   ldb   >GCTL               (bit 2, the sub CPU window, stays)
         andb  #4
         pshs  b
         ora   ,s+
         sta   >GCTL
         rts

g_pal    lda   vx+1,u
         sta   >PIDX
         lda   vy+1,u
         sta   >PDAT
         lda   vx1+1,u
         sta   >PDAT
         lda   vy1+1,u
         sta   >PDAT
         rts

* g_run: X = a block of the sub CPU that is read into the memory (words, the low byte first; os9/cpm/cpmgfx.asm describes it):
* the operation is done; A = 0 done, $FE the operation is not known
g_run    stx   gblk,u
         ldb   ,x                  the operation
         cmpb  #1
         lbeq  gr_pix
         cmpb  #2
         lbeq  gr_lin
         cmpb  #3
         lbeq  gr_rec
         cmpb  #4
         lbeq  gr_box
         cmpb  #5
         lbeq  gr_txt
         cmpb  #6
         lbeq  gr_fil
         cmpb  #7
         lbeq  gr_mod
         cmpb  #8
         lbeq  gr_pal
         cmpb  #9
         lbeq  gr_map
         lda   #$FE
         rts
* D = the word B (1 ... 6) of the block
g_word   ldx   gblk,u
         lslb
         abx
         lda   1,x
         ldb   ,x
         rts
gr_pix   ldb   #1
         lbsr  g_word
         std   vx,u
         ldb   #2
         lbsr  g_word
         std   vy,u
         ldb   #5
         lbsr  g_word
         stb   vc,u
         lbsr  g_pix
         lbra  gr_ok
gr_lin   ldb   #1
         lbsr  g_word
         std   vx,u
         ldb   #2
         lbsr  g_word
         std   vy,u
         ldb   #3
         lbsr  g_word
         std   vx1,u
         ldb   #4
         lbsr  g_word
         std   vy1,u
         ldb   #5
         lbsr  g_word
         stb   vc,u
         lbsr  g_line
         lbra  gr_ok
gr_rec   lbsr  gr_getr
         lbsr  g_rect
         lbra  gr_ok
gr_box   lbsr  gr_getr
         lbsr  g_box
         lbra  gr_ok
gr_txt   ldb   #1
         lbsr  g_word
         std   ox,u
         ldb   #2
         lbsr  g_word
         std   oy,u
         ldb   #5
         lbsr  g_word
         stb   vc,u
         ldb   #6
         lbsr  g_word
         stb   vbg,u
         ldx   gblk,u
         leax  14,x                the text
         lbsr  g_text
         lbra  gr_ok
gr_fil   ldb   #5
         lbsr  g_word
         stb   vc,u
         lbsr  g_fill
         lbra  gr_ok
gr_mod   ldb   #1
         lbsr  g_word
         tfr   b,a
         lbsr  g_mode
         lbra  gr_ok
gr_pal   ldb   #1
         lbsr  g_word
         std   vx,u
         ldb   #2
         lbsr  g_word
         std   vy,u
         ldb   #3
         lbsr  g_word
         std   vx1,u
         ldb   #4
         lbsr  g_word
         std   vy1,u
         lbsr  g_pal
gr_ok    clra
         rts
* map: the block w1 of the sub CPU memory (8 KB) is the block w2 (0 ... 9, 8 KB of the picture each) of the frame buffer, or w2 = $FFFF: its
* own memory again.  The physical blocks $70-$7F of the SMMU are the picture (GCTL bit 2, set here)
gr_map   ldb   #1
         lbsr  g_word
         tfr   b,a                 the SMMU index
         pshs  a
         ldb   #2
         lbsr  g_word
         cmpd  #$FFFF
         bne   grm1
         lda   ,s
         ora   #$80                its own memory: $80 + index
         bra   grm2
grm1     tfr   b,a
         ora   #$70
grm2     ldb   #XE_MI
         stb   >XIDX
         ldb   ,s+
         stb   >XDAT
         ldb   #XE_MD
         stb   >XIDX
         sta   >XDAT
         lda   >GCTL
         ora   #4
         sta   >GCTL
         bra   gr_ok
* the rectangle: x y w h c
gr_getr  ldb   #1
         lbsr  g_word
         std   ox,u
         ldb   #2
         lbsr  g_word
         std   oy,u
         ldb   #3
         lbsr  g_word
         std   ow,u
         ldb   #4
         lbsr  g_word
         std   oh,u
         ldb   #5
         lbsr  g_word
         stb   vc,u
         rts

         use   gfxfont.inc
