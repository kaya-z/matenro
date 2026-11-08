* SPDX-License-Identifier: MIT
* timing.asm - test ROM for the Matenro SoC (fpga/tn9k, Level 1 mode, ROM at $FC00): how long does the 6809 take for loops of 2000
* rounds, from XE_US (the microsecond counter, real time).  Four hex digits per loop, in microseconds:
*   A  ROM only (leax, bne)                B  one RAM read per round (lda $0200)
*   C  one RAM write per round (sta $0200)  D  the same loop as A, but in RAM ($0300)
* Registers: XIDX=$E04D XDAT=$E04E ACIA=$E001 POWER=$E00F

ACIA     equ   $E001
POWER    equ   $E00F
XIDX     equ   $E04D
XDAT     equ   $E04E
N        equ   2000
u0       equ   $0100
u1       equ   $0102

         org   $FC00
start    lds   #$0F00
* A
         lbsr  rdus
         ldx   #N
la       leax  -1,x
         bne   la
         lbsr  rdus2
         lda   #'A
         lbsr  report
* B
         lbsr  rdus
         ldx   #N
lb       lda   $0200
         leax  -1,x
         bne   lb
         lbsr  rdus2
         lda   #'B
         lbsr  report
* C
         lbsr  rdus
         ldx   #N
lc       sta   $0200
         leax  -1,x
         bne   lc
         lbsr  rdus2
         lda   #'C
         lbsr  report
* D: the loop of A in RAM
         ldx   #dcode
         ldy   #$0300
cp       lda   ,x+
         sta   ,y+
         cmpx  #dend
         bne   cp
         lbsr  rdus
         ldx   #N
         jsr   $0300
         lbsr  rdus2
         lda   #'D
         lbsr  report
* fill RAM blocks: $0400 100 NOPs + RTS, $0500 100 x LDA #0 + RTS
         ldx   #$0400
         lda   #100
         ldb   #$12
fe       stb   ,x+
         deca
         bne   fe
         lda   #$39
         sta   ,x
         ldx   #$0500
         lda   #100
fg       ldb   #$86
         stb   ,x+
         clr   ,x+
         deca
         bne   fg
         lda   #$39
         sta   ,x
         lbsr  rdus
         ldy   #20
lE       jsr   $0400
         leay  -1,y
         bne   lE
         lbsr  rdus2
         lda   #'E
         lbsr  report
         lbsr  rdus
         ldy   #20
lF       jsr   $0500
         leay  -1,y
         bne   lF
         lbsr  rdus2
         lda   #'F
         lbsr  report
         lbsr  rdus
         ldy   #20
lG       jsr   gblock
         leay  -1,y
         bne   lG
         lbsr  rdus2
         lda   #'G
         lbsr  report
         lda   #$A5
         sta   POWER
halt     bra   halt

gblock           fcb   $12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12
         fcb   $12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12
         fcb   $12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12
         fcb   $12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12
         fcb   $12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12
         fcb   $39
dcode    fcb   $30,$1F,$26,$FC,$39
dend     equ   *

* t0 (low 16 bits of XE_US) -> u0, t1 -> u1
rdus     ldb   #$94
         stb   XIDX
         lda   XDAT
         lda   XDAT
         lda   XDAT
         ldb   XDAT
         stb   u0+1
         sta   u0
         rts
rdus2    ldb   #$94
         stb   XIDX
         lda   XDAT
         lda   XDAT
         lda   XDAT
         ldb   XDAT
         stb   u1+1
         sta   u1
         rts

* A = the letter; prints "x: tttt" with t = u1 - u0 (microseconds)
report   sta   ACIA
         lda   #':
         sta   ACIA
         ldd   u1
         subd  u0
         pshs  b
         bsr   hex2
         puls  a
         bsr   hex2
         lda   #13
         sta   ACIA
         lda   #10
         sta   ACIA
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


         org   $FFFE
         fdb   start
