* SPDX-License-Identifier: MIT
********************************************************************
* xlink - OS-9 Level 2 device driver of the cross link of 摩天楼 (Matenro)
*
* Device descriptor: x0 (x0.asm), file manager SCF, hardware address $FFC9 (XCTL).
*
* What the driver does (docs/DESIGN.md, chapter 14):
*   Init   asks OS-9 for the memory of the sub CPU (F$AlHRAM: 8 blocks of 8KB for a Z80, 32 for an 8088), maps it
*          into the address space of the sub CPU (SMMU), and (IRQMODE 1) puts its service routine into the IRQ polling table.
*          The sub CPU memory is therefore taken from OS-9's own free RAM (no more `-m 1M`).
*   Term   stops the sub CPU, (takes the service routine out and) gives the memory back.
*   GetStat $B0 (SS.XInfo)  R$A = XID, R$X = first physical block, R$Y = number of blocks
*           $B1 (SS.XWait)  wait for the doorbell of the sub CPU: R$X = time-out in ticks (0 = 100); the process sleeps
*                           2 ticks at a time (IRQMODE 1: the doorbell interrupt wakes it at once).
*                           R$A = 1 doorbell pending, 0 time-out.
*   Read / Write / SetStat are not used (the commands `xrun` and `cpm` use the registers directly, they are visible
*   in every task).
*
* Credits: the module layout (driver entry table, SCF static storage, IRQ polling packet) follows the NitrOS-9
* project (GPL v2) as used in sim09's level1/pty.asm and the joystick drivers; definition files are read with a09 -I,
* not copied.  The code is original.
********************************************************************

         nam   xlink
         ttl   Cross link driver

         ifp1
         use   defsfile
         endc

Revision equ   1
SS.XInfo equ   $B0
SS.XWait equ   $B1
* IRQMODE 1: the doorbell interrupt wakes the waiting process (needs a Clock module that calls the IRQ polling table,
* D.Poll; sim09's clock.asm does not, so the interrupt would never be serviced).  0: SS.XWait sleeps 2 ticks at a time
* and looks at the doorbell flag.
IRQMODE  equ   0
XE_MI    equ   $08
XE_MD    equ   $09

         org   V.SCF
sbase    rmb   1                 first physical block of the sub CPU memory
nblk     rmb   1
waitpid  rmb   1                 process that sleeps in SS.XWait (0 = none)
xid      rmb   1
tmp      rmb   2
PST      equ   .

         mod   PEND,PNAM,Drivr+Objct,Reent+Revision,PENT,PST
         fcb   READ.+WRITE.
PNAM     fcs   /xlink/
         fcb   Revision

PENT     lbra  INIT
         lbra  READ
         lbra  WRITE
         lbra  GETSTA
         lbra  PUTSTA
         lbra  TERM

         ifne  IRQMODE
IRQPckt  fcb   0                 flip
         fcb   1                 mask: XSTAT bit 0 = doorbell of the sub CPU pending
         fcb   $05               priority
         endc

* ------------------------------------------------------------------
INIT     clr   waitpid,u
         ldx   V.PORT,u
         lda   2,x               XID
         beq   noxlink
         cmpa  #$FF
         beq   noxlink
         sta   xid,u
         ldb   #8
         cmpa  #2
         bne   in1
         ldb   #32
in1      stb   nblk,u
         clr   ,x                hold the sub CPU in reset, no interrupt
         pshs  u
         os9   F$AlHRAM          B = blocks -> D = first block (from the top of RAM)
         puls  u
         bcs   in_err
         stb   sbase,u
* SMMU: block i of the sub CPU -> sbase + i; the blocks behind the last one all go to the last block (an 8088
* has its reset vector in block 127)
         ldx   V.PORT,u
         clr   tmp,u
smm1     ldb   tmp,u
         cmpb  nblk,u
         blo   smm2
         ldb   nblk,u
         decb
smm2     addb  sbase,u
         pshs  b
         lda   #XE_MI
         sta   3,x
         lda   tmp,u
         sta   4,x
         lda   #XE_MD
         sta   3,x
         puls  a
         sta   4,x
         inc   tmp,u
         lda   tmp,u
         cmpa  #128
         bne   smm1
* IRQ
         ifne  IRQMODE
         ldd   V.PORT,u
         addd  #1                XSTAT
         leax  IRQPckt,pcr
         leay  IRQSvc,pcr
         os9   F$IRQ
         bcs   in_err2
         endc
         clrb
         rts
in_err2  coma
         clr   nblk,u
         rts
in_err   coma
         clr   nblk,u
         rts
noxlink  comb
         ldb   #E$Unit
         rts

* ------------------------------------------------------------------
         ifne  IRQMODE
* the doorbell of the sub CPU: switch the interrupt off (the process that waits re-enables it), wake the process
IRQSvc   ldx   V.PORT,u
         lda   ,x
         bita  #$10              interrupt enabled?
         beq   notmine           (the doorbell may stay pending without an enable: not our interrupt)
         anda  #$EF
         sta   ,x
         lda   waitpid,u
         beq   mine
         clr   waitpid,u
         ldb   #1                S$Wake
         os9   F$Send
mine     clrb
         rts
notmine  comb
         rts

         endc

* ------------------------------------------------------------------
READ     comb
         ldb   #E$UnkSVC
         rts
WRITE    comb
         ldb   #E$UnkSVC
         rts
PUTSTA   comb
         ldb   #E$UnkSVC
         rts

GETSTA   ldx   PD.Rgs,y
         lda   R$B,x
         cmpa  #SS.EOF
         beq   gs_ok
         cmpa  #SS.XInfo
         beq   gs_info
         cmpa  #SS.XWait
         beq   gs_wait
         comb
         ldb   #E$UnkSVC
         rts
gs_ok    clrb
         rts
gs_info  lda   xid,u
         sta   R$A,x
         clra
         ldb   sbase,u
         std   R$X,x
         ldb   nblk,u
         std   R$Y,x
         clrb
         rts
gs_wait  ldd   R$X,x
         bne   gw0
         ldd   #100
gw0      std   tmp,u             ticks left
gw1      ldx   V.PORT,u
         lda   1,x
         bita  #1
         bne   gw_got
         ifne  IRQMODE
         lda   ,x                enable the interrupt, then sleep (2 ticks at most: a lost wake-up costs only that)
         ora   #$10
         sta   ,x
         lda   PD.CPR,y
         sta   waitpid,u
         endc
         pshs  y
         ldx   #2
         os9   F$Sleep
         puls  y
         clr   waitpid,u
         ldd   tmp,u
         subd  #2
         bls   gw_to
         std   tmp,u
         bra   gw1
gw_got   lda   #1
         bra   gw_ret
gw_to    clra
gw_ret   ldx   PD.Rgs,y
         sta   R$A,x
         clrb
         rts

* ------------------------------------------------------------------
TERM     ldx   V.PORT,u
         clr   ,x                stop the sub CPU, no interrupt
         ifne  IRQMODE
         ldd   V.PORT,u
         addd  #1
         ldx   #0
         leay  IRQSvc,pcr
         os9   F$IRQ
         endc
         ldb   nblk,u
         beq   tm9
         clra
         ldb   sbase,u
         tfr   d,x
         ldb   nblk,u
         os9   F$DelRAM
tm9      clrb
         rts

         emod
PEND     equ   *
         end
