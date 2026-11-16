* cpmgfx.asm - BDOS function 112 of `cpm`: the graphics of the HDMI screen of the Tang
* Nano 20K for CP/M-80 (CALL 5, C = 112) and CP/M-86 (INT E0h, CL = 112)
*
* DE (DX) points to a block of 16 bit words (the low byte first) in the memory of the sub
* CPU:
*     +0 op   +2 w1   +4 w2   +6 w3   +8 w4   +10 c (the colour byte)   +12 bg (the
* background colour of the text)   +14 the text (up to a 0 byte, 96 characters)
*   op 1 pix   w1 = x, w2 = y                        op 2 line  w1 = x0, w2 = y0, w3 =
* x1, w4 = y1
*   op 3 rect  w1 = x, w2 = y, w3 = width, w4 = height    op 4 box  the same, filled
*   op 5 text  w1 = x, w2 = y, c = the colour of the dots, bg = the colour of the rest of
* the cell, the text at +14
*   op 6 fill  c = the colour of the whole picture    op 7 mode  w1 = 0 text, 1 picture,
* 3 picture with the text over it
*   op 8 palette  w1 = the entry (0 .. 255), w2 = red, w3 = green, w4 = blue (0 .. 255)
* The result in A: 0 done, $FF this machine has no frame buffer (or the operation is
* unknown: $FE).  The picture is 320 x 240 pixels of a byte; what is
* outside of it is not drawn.  The drawing is done by the code of os9/gfx/gfxlib.inc
* (through the window of the cross link, about 60 us a pixel).
f_gfx    lbsr  g_probe
         beq   fg0
         lda   #$FF
         sta   r_al,u
         lbra  retA
fg0      lbsr  ptrparm
         leax  sect,u
         ldy   #112
         lbsr  rdsub
         clr   sect+111,u          the end of the text
         leax  sect,u
         lbsr  g_run
         sta   r_al,u
         lbra  retA

         use   gfxlib.inc
