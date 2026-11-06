* SPDX-License-Identifier: MIT
* aciirq.asm - test ROM for the console ACIA interrupt of the Matenro SoC (fpga/tn9k, Level 1 mode, ROM at $FC00):
*   the control register ($E000: bit7 RIE, bits6-5 = 01 TIE, bits1-0 = 11 master reset), status bit 7 (IRQ), the IRQ line.
* Expected output:  S B I R P   (a character each, in this order)
*   S  start
*   B  status bit 7 is set with TIE on (the transmitter has room)
*   I  the IRQ handler ran once (it switches TIE off with a master reset)
*   R  after the master reset the status bit 7 is clear and no second interrupt came
*   P  power off ($A5)
ACIAC    equ   $E000
ACIA     equ   $E001
POWER    equ   $E00F
count    equ   $0010

         org   $FC00
start    lds   #$0F00
         clr   count
         lda   #'S
         sta   ACIA
         lda   #$20             TIE: an interrupt while the transmitter has room
         sta   ACIAC
         lda   ACIAC
         bpl   nob
         lda   #'B
         sta   ACIA
nob      andcc #$EF             I flag clear: the IRQ line is taken
         ldx   #20000
wt       lda   count
         bne   got
         leax  -1,x
         bne   wt
got      lda   count
         cmpa  #1
         bne   noi
         lda   #'I
         sta   ACIA
noi      ldx   #2000            some time: a second interrupt would raise count
wt2      leax  -1,x
         bne   wt2
         lda   ACIAC
         bmi   nor
         lda   count
         cmpa  #1
         bne   nor
         lda   #'R
         sta   ACIA
nor      lda   #'P
         sta   ACIA
         lda   #$A5
         sta   POWER
halt     bra   halt

irq      inc   count
         lda   #$03             master reset: the interrupt request goes away
         sta   ACIAC
         rti

         org   $FFF8
         fdb   irq
         org   $FFFE
         fdb   start
