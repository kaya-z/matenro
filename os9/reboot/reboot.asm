* SPDX-License-Identifier: MIT
********************************************************************
* reboot - restart the Matenro machine
*
*   reboot
*
* Writes $A7 to the power register ($FF8F, in the I/O page that every task sees).  The machine starts again as if
* the power had been switched on: the simulator clears the RAM and loads the ROM image again; the FPGA board does what
* its reset button does (the memory test, the boot ROM, the Level 2 loader from the card).  The disks are not
* touched, and nothing is written back: OS-9 does not keep file data in the RAM, but a program that still has a
* file open loses what it has not written.  There is no "are you sure".
*
* Credits: the module layout follows the sample commands of the NitrOS-9 project (GPL v2), as in os9/xrun.asm.
* The code is original.
********************************************************************

         nam   reboot
         ttl   Restart the machine

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

POWER    equ   $FF8F

         mod   eom,name,tylg,atrv,start,size

         org   0
         rmb   200               stack
size     equ   .

name     fcs   /reboot/
         fcb   edition

msg      fcc   "Rebooting..."
         fcb   C$CR

start    leax  msg,pcr
         lda   #1
         ldy   #80
         os9   I$WritLn
         ldx   #2                two clock ticks: the serial line sends the text before the reset
         os9   F$Sleep
         orcc  #$50              nothing may come between the write and the reset
         lda   #$A7
         sta   >POWER
hang     bra   hang

         emod
eom      equ   *
         end
