* SPDX-License-Identifier: MIT
********************************************************************
* subsel - choose the sub CPU of the Matenro machine: the Z80 or the 8088
*
*   subsel            shows the sub CPU that is on the cross link
*   subsel z80        the Z80 (CP/M-80: cpm file.com)
*   subsel 8088       the 8088 (CP/M-86 and MS-DOS: cpm file.cmd, dos ...)
*
* The FPGA of the Tang Nano 20K has both cores; the register SUBSEL ($FFCF: 1 = Z80, 2 = 8088) says which one is on the
* cross link (XID, $FFCC, then returns 1 or 2).  The other one is held in reset.  The chosen sub CPU starts from its reset
* (its memory is the same RAM, the SMMU is the one of the reset): load again what it is to run.  The simulator has both
* CPUs too (`matenro -sub z80`, the register works there as well).  The machines with one sub CPU only (the Tang Nano 9K:
* the Z80) do not have the register: `subsel` says so.
*
* Credits: the module layout follows the sample commands of the NitrOS-9 project (GPL v2), as in os9/xrun.asm.
* The code is original.
********************************************************************

         nam   subsel
         ttl   Choose the Z80 or the 8088

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

XCTL     equ   $FFCA
SUBSEL   equ   $FFCF

         mod   eom,name,tylg,atrv,start,size

         org   0
cur      rmb   1
         rmb   200               stack
size     equ   .

name     fcs   /subsel/
         fcb   edition

msgz     fcc   "subsel: Z80"
         fcb   C$CR
msg8     fcc   "subsel: 8088"
         fcb   C$CR
msgno    fcc   "subsel: this machine has one sub CPU only"
         fcb   C$CR
msguse   fcc   "usage: subsel [z80|8088]"
         fcb   C$CR

start    lda   >SUBSEL
         cmpa  #1
         beq   s1
         cmpa  #2
         bne   nochoice
s1       sta   cur,u
sk       lda   ,x+
         cmpa  #' '
         beq   sk
         cmpa  #C$CR
         beq   show
         ldb   #2
         cmpa  #'8'
         beq   set
         anda  #$DF
         ldb   #1
         cmpa  #'Z'
         bne   usage
set      clr   >XCTL             hold the sub CPU in reset
         pshs  b
         ldx   #2                two ticks: a bus cycle of the old one is over
         os9   F$Sleep
         puls  b
         stb   >SUBSEL
         lda   >SUBSEL
         sta   cur,u
show     lda   cur,u
         leax  msgz,pcr
         cmpa  #1
         beq   say
         leax  msg8,pcr
say      lda   #1
         ldy   #80
         os9   I$WritLn
         clrb
         os9   F$Exit
nochoice leax  msgno,pcr
         bra   bad
usage    leax  msguse,pcr
bad      lda   #2
         ldy   #80
         os9   I$WritLn
         ldb   #1
         os9   F$Exit

         emod
eom      equ   *
         end
