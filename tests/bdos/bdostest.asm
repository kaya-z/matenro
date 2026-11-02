* SPDX-License-Identifier: MIT
* bdostest - an OS-9 program that calls the CP/M BDOS through the module bdos (os9/bdos): console, make, write, close,
* rename, open, read, delete.  Prints "BDOS LIB OK" or "BDOS LIB FAIL n".  Run after `load bdos`.

         nam   bdostest
         ttl   Test of the module bdos

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

         use   bdos.d

         mod   eom,name,tylg,atrv,start,size

         org   0
bdosent  rmb   2
step     rmb   1
fcba     rmb   36
fcbb     rmb   36
rfcb     rmb   36
buf      rmb   128
buf2     rmb   128
bdoswk   rmb   BDOSSZ
         rmb   200               stack
size     equ   .

name     fcs   /bdostest/
         fcb   edition
bdosname fcs   /bdos/
msg      fcc   "BDOS lib: BDOS 9"
         fcb   13
         fcc   "$"
nmold    fcc   "BT      TMP"
nmnew    fcc   "BU      TMP"
tdata    fcc   "BDOS-TEST"
okmsg    fcc   "BDOS LIB OK"
         fcb   C$CR
badmsg   fcc   "BDOS LIB FAIL "
crmsg    fcb   C$CR

* call the BDOS: A = function, X = DE
bd       leay  bdoswk,u
         jsr   [bdosent,u]
         rts

* FCB at Y: cleared, the 11 bytes at X are the name
mkfcb    pshs  y
         ldb   #36
mf1      clr   ,y+
         decb
         bne   mf1
         puls  y
         leay  1,y
         ldb   #11
mf2      lda   ,x+
         sta   ,y+
         decb
         bne   mf2
         rts

start    lda   #Sbrtn+Objct
         clrb
         leax  bdosname,pcr
         pshs  u                 (F$Link returns the address of the module in U)
         os9   F$Link
         puls  u
         lbcs  nolink
         sty   bdosent,u
         lda   #BDOSINIT
         lbsr  bd
         lda   #9                console: a string ending in $
         leax  msg,pcr
         lbsr  bd
         lda   #12               the version
         ldx   #0
         lbsr  bd
         cmpx  #$0022
         lbne  f1
         lda   #2                console output of one character
         ldx   #'!
         lbsr  bd
* the FCBs
         leay  fcba,u
         leax  nmold,pcr
         lbsr  mkfcb
         leay  fcbb,u
         leax  nmnew,pcr
         lbsr  mkfcb
         leay  rfcb,u            rename: the old name at +1, the new one at +17
         leax  nmold,pcr
         lbsr  mkfcb
         leax  nmnew,pcr
         leay  rfcb+17,u
         ldb   #11
rn1      lda   ,x+
         sta   ,y+
         decb
         bne   rn1
* the data of the record
         leax  tdata,pcr
         leay  buf,u
         ldb   #9
dt1      lda   ,x+
         sta   ,y+
         decb
         bne   dt1
         lda   #'R
         ldb   #119
dt2      sta   ,y+
         decb
         bne   dt2
* leftovers of an earlier run
         lda   #19
         leax  fcba,u
         lbsr  bd
         lda   #19
         leax  fcbb,u
         lbsr  bd
* make, write, close
         lda   #22
         leax  fcba,u
         lbsr  bd
         cmpa  #$FF
         lbeq  f2
         lda   #26               the DMA address
         leax  buf,u
         lbsr  bd
         lda   #21
         leax  fcba,u
         lbsr  bd
         tsta
         lbne  f3
         lda   #16
         leax  fcba,u
         lbsr  bd
* rename
         lda   #23
         leax  rfcb,u
         lbsr  bd
         tsta
         lbne  f4
* open the new name, read the record
         lda   #15
         leax  fcbb,u
         lbsr  bd
         cmpa  #$FF
         lbeq  f5
         lda   #26
         leax  buf2,u
         lbsr  bd
         lda   #20
         leax  fcbb,u
         lbsr  bd
         tsta
         lbne  f6
         leax  tdata,pcr
         leay  buf2,u
         ldb   #9
cmp1     lda   ,x+
         cmpa  ,y+
         lbne  f7
         decb
         bne   cmp1
         lda   buf2+127,u
         cmpa  #'R
         lbne  f7
* the old name is gone
         lda   #15
         leax  fcba,u
         lbsr  bd
         cmpa  #$FF
         lbne  f8
* close, delete
         lda   #16
         leax  fcbb,u
         lbsr  bd
         lda   #19
         leax  fcbb,u
         lbsr  bd
         lda   #BDOSEXIT
         lbsr  bd
         leax  okmsg,pcr
         bra   say
f1       lda   #'1
         bra   fail
f2       lda   #'2
         bra   fail
f3       lda   #'3
         bra   fail
f4       lda   #'4
         bra   fail
f5       lda   #'5
         bra   fail
f6       lda   #'6
         bra   fail
f7       lda   #'7
         bra   fail
f8       lda   #'8
         bra   fail
nolink   lda   #'0
fail     sta   step,u
         leax  badmsg,pcr
         lda   #1
         ldy   #14
         os9   I$Write
         leax  step,u
         lda   #1
         ldy   #1
         os9   I$Write
         leax  crmsg,pcr
         bra   say
say      lda   #1
         ldy   #40
         os9   I$WritLn
         clrb
         os9   F$Exit

         emod
eom      equ   *
         end
