* SPDX-License-Identifier: MIT
* timing6809.asm - test ROM for the Matenro SoC (Level 1 mode, ROM at $FC00): loads zbench.bin into the Z80 memory, runs it
* and prints how many microseconds (XE_US, real time) each of its six loops took, four hex digits each.
ACIA     equ   $E001
POWER    equ   $E00F
XCTL     equ   $E04A
XSTAT    equ   $E04B
XIDX     equ   $E04D
XDAT     equ   $E04E
TAB      equ   $0100

         org   $FC00
start    lds   #$0F00
         ldb   #$0A              window address = physical $100000 (Z80 block 0)
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
         lda   #1
         sta   XCTL              run
         ldy   #TAB
         ldb   #7                the ready bell and six loops
nb       lbsr  waitbell
         lbsr  rdus
         decb
         bne   nb
         ldx   #TAB
         ldb   #6
pl       ldd   2,x
         subd  ,x++
         pshs  b,x
         lbsr  hex2
         puls  a,x
         pshs  x
         lbsr  hex2
         lda   #13
         sta   ACIA
         lda   #10
         sta   ACIA
         puls  x
         decb
         bne   pl
         lda   #$A5
         sta   POWER
halt     bra   halt

waitbell lda   XSTAT
         bita  #1
         beq   waitbell
         sta   XSTAT
         rts

* the low 16 bits of XE_US -> ,y++
rdus     pshs  b
         ldb   #$94
         stb   XIDX
         lda   XDAT
         lda   XDAT
         lda   XDAT
         ldb   XDAT
         std   ,y++
         puls  b
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
         fcb   $31,$00,$40,$21,$00,$02,$AF,$D3,$03,$D3,$02,$11,$D0,$07,$1B,$7A
         fcb   $B3,$20,$FB,$D3,$02,$11,$D0,$07,$00,$00,$00,$00,$00,$00,$00,$00
         fcb   $1B,$7A,$B3,$20,$F3,$D3,$02,$11,$D0,$07,$7E,$7E,$7E,$7E,$7E,$7E
         fcb   $7E,$7E,$1B,$7A,$B3,$20,$F3,$D3,$02,$11,$D0,$07,$77,$77,$77,$77
         fcb   $77,$77,$77,$77,$1B,$7A,$B3,$20,$F3,$D3,$02,$11,$D0,$07,$34,$34
         fcb   $34,$34,$34,$34,$34,$34,$1B,$7A,$B3,$20,$F3,$D3,$02,$11,$D0,$07
         fcb   $3E,$01,$3E,$01,$3E,$01,$3E,$01,$3E,$01,$3E,$01,$3E,$01,$3E,$01
         fcb   $1B,$7A,$B3,$20,$EB,$D3,$02,$76,$18,$FD
imgend   equ   *

         org   $FFFE
         fdb   start
