* SPDX-License-Identifier: MIT
* xlshr.asm - xltest.asm with the shared RAM in the BSRAM (rtl/shr_ap.v, physical block $FF = $1FE000-$1FFFFF): the SMMU maps the
*   Z80 block 0 there, the 6809 loads the demo through the window into the BSRAM, so the Z80 runs from the BSRAM; the result is
*   read back from the shared RAM through the window.  Expected output:  13BA 0037  BA13 1D4C
* (xltest.asm - test ROM for the Matenro SoC (fpga/tn9k, Level 1 mode, ROM at $FC00): the 6809 plays the part of xrun
*   load the Z80 demo (os9/sub/sumz80.py, the same binary as in the C simulator) through the window of the XLINK,
*   release the Z80, wait for "ready", send n = 100 and 10, wait for the reply, print S2M[0..1] in hex, power off ($A5).
*   then read XE_KHZ (the Z80 clock in kHz) with the auto increment of the index and print it: the SoC once took the
*   byte of the next register (it read the byte again after the access, which is right for the window only).
* Expected output:  13BA 0037  1D4C (7500 kHz)
* Registers: XCTL=$E049 XSTAT=$E04A XID/BELL=$E04B XIDX=$E04C XDAT=$E04D

ACIA     equ   $E001
POWER    equ   $E00F
XCTL     equ   $E049
XSTAT    equ   $E04A
XBELL    equ   $E04B
XIDX     equ   $E04C
XDAT     equ   $E04D

         org   $FC00
start    lds   #$0F00
         lda   #'S
         sta   ACIA
* SMMU entry 0 (Z80 $0000-$1FFF) -> physical block $FF (the BSRAM)
         ldb   #$08
         stb   XIDX
         clr   XDAT
         ldb   #$09
         stb   XIDX
         lda   #$FF
         sta   XDAT
* window address = physical $1FE000
         ldb   #$0A
         stb   XIDX
         lda   #$1F
         sta   XDAT
         ldb   #$0B
         stb   XIDX
         lda   #$E0
         sta   XDAT
         ldb   #$0C
         stb   XIDX
         clr   XDAT
         ldb   #$0D
         stb   XIDX
         ldx   #image
ld1      lda   ,x+
         sta   XDAT
         cmpx  #imgend
         bne   ld1
         lda   #'L
         sta   ACIA
* run
         lda   #$01
         sta   XCTL
         lbsr  waitbell
         sta   XSTAT             acknowledge "ready"
         lda   #'R
         sta   ACIA
         lda   #100
         lbsr  ask
         lda   #10
         lbsr  ask
* the result in the shared RAM: window address $1FE100, two bytes
         ldb   #$0B
         stb   XIDX
         lda   #$E1
         sta   XDAT
         ldb   #$0C
         stb   XIDX
         clr   XDAT              (the low byte moved on while the image was written)
         ldb   #$0D
         stb   XIDX
         lda   XDAT
         lbsr  hex2
         lda   XDAT
         lbsr  hex2
         lda   #' 
         sta   ACIA
         ldb   #$8E              XE_KHZ, auto increment
         stb   XIDX
         lda   XDAT
         lbsr  hex2
         lda   XDAT
         lbsr  hex2
         lda   #13
         sta   ACIA
         lda   #10
         sta   ACIA
         lda   #$A5
         sta   POWER
halt     bra   halt

* A = n: send it, wait for the reply, print S2M[0..1] as hex (high byte first), CR LF
ask      ldb   #$00
         stb   XIDX              M2S[0]
         sta   XDAT
         clr   XBELL             ring the Z80
         lbsr  waitbell
         ldb   #$05
         stb   XIDX
         lda   XDAT              S2M[1] = high
         lbsr  hex2
         ldb   #$04
         stb   XIDX
         lda   XDAT              S2M[0] = low
         lbsr  hex2
         clr   XSTAT
         lda   #13
         sta   ACIA
         lda   #10
         sta   ACIA
         rts

waitbell ldb   XSTAT
         bitb  #$01
         beq   waitbell
         rts

hex2     pshs  a
         lsra
         lsra
         lsra
         lsra
         lbsr  hex1
         puls  a
         anda  #$0F
hex1     cmpa  #10
         blo   h1
         adda  #7
h1       adda  #'0
         sta   ACIA
         rts

image
         use   sumz80.inc
imgend   equ   *

         org   $FFFE
         fdb   start
