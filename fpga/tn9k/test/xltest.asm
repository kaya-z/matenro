* SPDX-License-Identifier: MIT
* xltest.asm - test ROM for the Matenro SoC (fpga/tn9k, Level 1 mode, ROM at $FC00): the 6809 plays the part of xrun
*   load the Z80 demo (os9/sub/sumz80.py, the same binary as in the C simulator) through the window of the XLINK,
*   release the Z80, wait for "ready", send n = 100 and 10, wait for the reply, print S2M[0..1] in hex, power off ($A5).
*   then read XE_KHZ (the Z80 clock in kHz) with the auto increment of the index and print it: the SoC once took the
*   byte of the next register (it read the byte again after the access, which is right for the window only).
* Expected output:  13BA 0037  1D4C (7500 kHz)
* Registers: XCTL=$E04A XSTAT=$E04B XID/BELL=$E04C XIDX=$E04D XDAT=$E04E

ACIA     equ   $E001
POWER    equ   $E00F
XCTL     equ   $E04A
XSTAT    equ   $E04B
XBELL    equ   $E04C
XIDX     equ   $E04D
XDAT     equ   $E04E

         org   $FC00
start    lds   #$0F00
         lda   #'S
         sta   ACIA
* window address = physical $100000 (the SMMU maps the Z80 block 0 there)
         ldb   #$0A
         stb   XIDX
         lda   #$10
         sta   XDAT
         ldb   #$0B
         stb   XIDX
         clr   XDAT
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
         bsr   waitbell
         sta   XSTAT             acknowledge "ready"
         lda   #'R
         sta   ACIA
         lda   #100
         bsr   ask
         lda   #10
         bsr   ask
         ldb   #$8E              XE_KHZ, auto increment
         stb   XIDX
         lda   XDAT
         bsr   hex2
         lda   XDAT
         bsr   hex2
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
         bsr   waitbell
         ldb   #$05
         stb   XIDX
         lda   XDAT              S2M[1] = high
         bsr   hex2
         ldb   #$04
         stb   XIDX
         lda   XDAT              S2M[0] = low
         bsr   hex2
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
         bsr   hex1
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
