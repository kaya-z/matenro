* SPDX-License-Identifier: MIT
* xltest88.asm - test ROM for the Matenro SoC of the Tang Nano 20K
* (Level 1 mode, ROM at $F000, 4 KB): the 6809 plays the part of xrun for the 8088.
*   Load the 8088 self test (tests/i8088/core.asm, nasm -DHWPORTS: core88.inc)
*   through the window of the XLINK to the 8088 address $0400, put the reset
*   vector JMP 0000:0400 at FFFF0, release the 8088 and wait for its doorbell
*   (the program writes the result to S2M[0] and rings). Print S2M[0] in hex
*   ($A5 = all checks passed, $A6 = one failed), then XE_KHZ, power off.
* Expected output:  S L R A5 00 12D5   (4821 kHz = $12D5 = 67.5 MHz / 14)
* Registers: XCTL=$E04A XSTAT=$E04B XID/BELL=$E04C XIDX=$E04D XDAT=$E04E

ACIA     equ   $E001
POWER    equ   $E00F
XCTL     equ   $E04A
XSTAT    equ   $E04B
XBELL    equ   $E04C
XIDX     equ   $E04D
XDAT     equ   $E04E

         org   $F000
start    lds   #$0F00
         lda   #'S
         sta   ACIA
* window address = physical $100400 (8088 address $0400 with the default SMMU: block 0 -> $80)
         ldb   #$0A
         stb   XIDX
         lda   #$10
         sta   XDAT
         ldb   #$0B
         lda   #$04
         stb   XIDX
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
* the reset vector at FFFF0 (8088 block 127 -> physical block $FF, address $1FFFF0): JMP FAR 0000:0400
         ldb   #$0A
         stb   XIDX
         lda   #$1F
         sta   XDAT
         ldb   #$0B
         stb   XIDX
         lda   #$FF
         sta   XDAT
         ldb   #$0C
         stb   XIDX
         lda   #$F0
         sta   XDAT
         ldb   #$0D
         stb   XIDX
         lda   #$EA              (no CLR on XDAT: it reads first, and the read advances the window)
         sta   XDAT
         clra
         sta   XDAT
         lda   #$04
         sta   XDAT
         clra
         sta   XDAT
         sta   XDAT
         lda   #'L
         sta   ACIA
* run
         lda   #$01
         sta   XCTL
         bsr   waitbell
         lda   #'R
         sta   ACIA
         ldb   #$04
         stb   XIDX
         lda   XDAT              S2M[0]
         bsr   hex2
         lda   #' 
         sta   ACIA
         ldb   #$05
         stb   XIDX
         lda   XDAT              S2M[1] = the id of the failing check (0 if none)
         bsr   hex2
         lda   #' 
         sta   ACIA
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
         use   core88.inc
imgend   equ   *

         org   $FFFE
         fdb   start
