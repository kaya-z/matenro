* SPDX-License-Identifier: MIT
********************************************************************
* bdos - the BDOS of `cpm` as a subroutine module for OS-9 programs
*
* A 6809 program can call the CP/M BDOS functions by number (console, files with FCBs, 128 byte records) without a
* sub CPU: the same engine as `cpm` (cpmengine.asm), but the "guest memory" is the memory of the calling program.
* How to call it: bdos.d.
*
* Credits: the BDOS function numbers, FCB layout and result conventions are those of Digital Research's CP/M 2.2 (the
* CP/M 2.2 Interface Guide).  The code is original.
********************************************************************

         nam   bdos
         ttl   CP/M BDOS for OS-9 programs

         ifp1
         use   defsfile
         endc

tylg     set   Sbrtn+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

         use   cpmdefs.asm
         use   bdos.d

         mod   eom,name,tylg,atrv,entry,size

         use   cpmdata.asm

name     fcs   /bdos/
         fcb   edition

* ---------------------------------------------------------------- the entry: A = function, X = DE, Y = work area
entry    pshs  u
         tfr   y,u
         cmpa  #BDOSINIT
         beq   init
         cmpa  #BDOSEXIT
         beq   exit
         sta   func,u
         stx   parh,u                (big endian: parh = D, parl = E)
         clr   rds,u
         clr   rds+1,u
         lbsr  dispatch
         ldb   r_bl,u                X = HL
         lda   r_bh,u
         tfr   d,x
         ldb   r_bh,u                B = H
         lda   r_al,u                A = the result
         andcc #$FE
         puls  u,pc

* clear the work area and set the paths of the caller
init     leax  ,u
         ldy   #size
in1      clr   ,x+
         leay  -1,y
         bne   in1
         lda   #1                    the version of a Z80 system (0022h)
         sta   subty,u
         sta   islib,u
         clra
         sta   stdi,u
         inca
         sta   stdo,u
         inca
         sta   stde,u
         puls  u,pc

* close what the caller has left open (text files are converted back and written)
exit     lbsr  cleanup
         lda   srchdir,u
         beq   ex9
         os9   I$Close
         clr   srchdir,u
ex9      puls  u,pc

* ---------------------------------------------------------------- the memory of the caller is the guest memory
* read Y bytes from the memory of the caller at lin (16 bit pointer in lin+1) to ,X ; lin advances
rdsub    cmpy  #0
         beq   rds9
rds1     pshs  x
         ldx   lin+1,u
         lda   ,x+
         stx   lin+1,u
         puls  x
         sta   ,x+
         leay  -1,y
         bne   rds1
rds9     rts

* write Y bytes from ,X to the memory of the caller at lin ; lin advances
wrsub    cmpy  #0
         beq   wrs9
wrs1     lda   ,x+
         pshs  x
         ldx   lin+1,u
         sta   ,x+
         stx   lin+1,u
         puls  x
         leay  -1,y
         bne   wrs1
wrs9     rts

         use   cpmengine.asm
f_gfx    rts                       (the graphics of cpm: not in this module)

         emod
eom      equ   *
         end
