* SPDX-License-Identifier: MIT
********************************************************************
* xrun - load a program into the sub CPU of the Matenro machine and run it
*
*   xrun [-l=hex] file [n]
*
*   file   raw binary image of the sub CPU program
*   -l=    load address in the sub CPU address space (hex, multiple of $100).
*          Default 0 for the Z80, $400 for the 8088.  A Z80 program that is not loaded at 0
*          gets a JP at 0; an 8088 program gets a JMP FAR 0000:load at the reset vector FFFF0.
*   n      (decimal 0-255) after the start: wait for the "ready" doorbell of the sub CPU, put n
*          into mailbox byte 0, ring the doorbell, wait for the reply and print the mailbox
*          bytes S2M[0..3] in hex.  This is the protocol of os9/sub/sum8088.asm and sumz80.bin.
*
* The program runs in user state: the cross link registers sit in the I/O page ($FFC9-$FFCD of
* the Level 2 machine), which is visible in every task, so no driver is needed.  The sub CPU
* memory is reached through the window port (physical RAM, not through the OS-9 memory map);
* run the simulator with -m 1M so that OS-9 leaves the upper 1MB (the sub CPU pool) alone.
*
* Register interface: see docs/DESIGN.md.
*
* Credits: the module layout (mod/emod, os9 calls, data area) follows the sample commands of the
* NitrOS-9 project (GPL v2) as used in sim09's misc/shutdown.asm; the definition files are
* NitrOS-9's (read with a09 -I, not copied).  The code is original.
********************************************************************

         nam   xrun
         ttl   Load and run the sub CPU program

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

XCTL     equ   $FFC9
XSTAT    equ   $FFCA
XID      equ   $FFCB
XIDX     equ   $FFCC
XDAT     equ   $FFCD
XE_M2S   equ   $00
XE_S2M   equ   $04
XE_MI    equ   $08
XE_MD    equ   $09
XE_WA    equ   $0A
XE_WD    equ   $0D

         mod   eom,name,tylg,atrv,start,size

         org   0
path     rmb   1
subtype  rmb   1
haven    rmb   1
nval     rmb   1
entry    rmb   2
loadad   rmb   2
cnt      rmb   2
blk      rmb   1
tmp      rmb   1
fname    rmb   2
out      rmb   40
buf      rmb   256
         rmb   200
size     equ   .

name     fcs   /xrun/
         fcb   edition

msgnosub fcc   "xrun: no sub CPU"
         fcb   C$CR
msgerr   fcc   "xrun: cannot read the file"
         fcb   C$CR
msgtmo   fcc   "xrun: the sub CPU did not answer"
         fcb   C$CR
msgrun   fcc   "sub CPU started"
         fcb   C$CR
msgrep   fcc   "reply: "
msgrepn  equ   *-msgrep

* ------------------------------------------------------------------
start    clr   haven,u
         clr   nval,u
         clr   entry,u
         clr   entry+1,u
         lda   >XID
         lbeq  nosub
         sta   subtype,u
         cmpa  #2
         bne   skip
         lda   #$04
         sta   entry,u             8088: default load address $0400
skip     lda   ,x+
         cmpa  #' '
         beq   skip
         cmpa  #'-'
         bne   getname
         lda   ,x+                 'l'
         lda   ,x+                 '='
         clr   entry,u
         clr   entry+1,u
hexloop  lda   ,x+
         lbsr  hexval
         bcs   hexend
         stb   tmp,u
         ldd   entry,u
         lslb
         rola
         lslb
         rola
         lslb
         rola
         lslb
         rola
         orb   tmp,u
         std   entry,u
         bra   hexloop
hexend   lda   ,x+
         cmpa  #' '
         beq   hexend
getname  leax  -1,x
         stx   fname,u
* --- open the file
         lda   #READ.
         os9   I$Open
         lbcs  rderr
         sta   path,u
* --- optional decimal argument behind the file name (X points behind the name)
numskip  lda   ,x+
         cmpa  #' '
         beq   numskip
         suba  #'0'
         cmpa  #9
         bhi   numdone
         lda   -1,x
numloop  suba  #'0'
         cmpa  #9
         bhi   numend
         sta   tmp,u
         lda   nval,u
         ldb   #10
         mul
         addb  tmp,u
         stb   nval,u
         lda   ,x+
         bra   numloop
numend   lda   #1
         sta   haven,u
numdone  equ   *
* --- hold the sub CPU in reset and copy the file into its memory
         clr   >XCTL
         ldd   entry,u
         std   loadad,u
rdloop   lda   path,u
         leax  buf,u
         ldy   #256
         os9   I$Read
         bcs   rdend
         sty   cnt,u
         ldd   loadad,u
         lbsr  setwinD
         ldy   cnt,u
         leax  buf,u
cp       lda   ,x+
         sta   >XDAT
         leay  -1,y
         bne   cp
         ldd   loadad,u
         addd  cnt,u
         std   loadad,u
         bra   rdloop
rdend    cmpb  #E$EOF
         lbne  rderr
         lda   path,u
         os9   I$Close
* --- entry stub
         lda   subtype,u
         cmpa  #1
         bne   is8088
         ldd   entry,u
         beq   go                  Z80 starts at 0 anyway
         clra
         ldx   #0
         lbsr  setwin
         lda   #$C3                JP entry
         sta   >XDAT
         lda   entry+1,u
         sta   >XDAT
         lda   entry,u
         sta   >XDAT
         bra   go
is8088   lda   #127                the block with the reset vector FFFF0
         ldx   #$1FF0
         lbsr  setwin
         lda   #$EA                JMP FAR 0000:entry
         sta   >XDAT
         lda   entry+1,u
         sta   >XDAT
         lda   entry,u
         sta   >XDAT
         clra
         sta   >XDAT
         sta   >XDAT
go       lda   #1
         sta   >XCTL               release the sub CPU
         tst   haven,u
         bne   talk
         leax  msgrun,pcr
         bra   say
talk     bsr   waitrx
         bcs   timeout
         lda   #XE_M2S
         sta   >XIDX
         lda   nval,u
         sta   >XDAT
         clra
         sta   >XID                ring the sub CPU
         lbsr  waitrx
         bcs   timeout
         lda   #XE_S2M+$80
         sta   >XIDX
         leax  out,u
         lda   #'r'
         sta   ,x+
         lda   #'e'
         sta   ,x+
         lda   #'p'
         sta   ,x+
         lda   #'l'
         sta   ,x+
         lda   #'y'
         sta   ,x+
         lda   #':'
         sta   ,x+
         ldb   #4
hexout   lda   #' '
         sta   ,x+
         lda   >XDAT
         lbsr  puthex
         decb
         bne   hexout
         lda   #C$CR
         sta   ,x
         leax  out,u
         bra   say
timeout  leax  msgtmo,pcr
         bra   say
nosub    leax  msgnosub,pcr
         bra   say
rderr    leax  msgerr,pcr
say      lda   #1
         ldy   #60
         os9   I$WritLn
         clrb
         os9   F$Exit

* wait until the sub CPU rang the doorbell (S2M), acknowledge it.  C set on timeout.
waitrx   ldy   #1500
w1       lda   >XSTAT
         bita  #1
         bne   w2
         pshs  y
         ldx   #1
         os9   F$Sleep
         puls  y
         leay  -1,y
         bne   w1
         orcc  #1
         rts
w2       sta   >XSTAT
         andcc #$FE
         rts

* ASCII hex digit in A -> value in B, C clear; C set when not a hex digit
hexval   cmpa  #'0'
         blo   nothex
         cmpa  #'9'
         bhi   hexalpha
         suba  #'0'
         bra   hexok
hexalpha anda  #$DF
         cmpa  #'A'
         blo   nothex
         cmpa  #'F'
         bhi   nothex
         suba  #'A'-10
hexok    tfr   a,b
         andcc #$FE
         rts
nothex   orcc  #1
         rts

* A -> two hex digits at ,X+
puthex   pshs  a
         lsra
         lsra
         lsra
         lsra
         bsr   nib
         puls  a
         anda  #$0F
nib      adda  #'0'
         cmpa  #'9'
         bls   nib2
         adda  #7
nib2     sta   ,x+
         rts

* D = sub CPU address (16 bit) -> window
setwinD  pshs  d
         anda  #$1F
         tfr   d,x
         puls  d
         lsra
         lsra
         lsra
         lsra
         lsra
* in: A = sub CPU 8KB block (0..127), X = offset in the block ($0000-$1FFF).  Sets the window
* address to the physical address of that byte and leaves the extended index at XE_WD.
setwin   pshs  x,a
         ldb   #XE_MI
         stb   >XIDX
         sta   >XDAT
         ldb   #XE_MD
         stb   >XIDX
         lda   >XDAT               physical block
         sta   blk,u
         ldb   #XE_WA+$80
         stb   >XIDX
         lda   blk,u
         lsra
         lsra
         lsra
         sta   >XDAT               physical address bits 20-16
         lda   blk,u
         anda  #7
         lsla
         lsla
         lsla
         lsla
         lsla
         ora   1,s                 offset bits 12-8
         sta   >XDAT
         lda   2,s                 offset bits 7-0
         sta   >XDAT
         ldb   #XE_WD
         stb   >XIDX
         puls  a,x
         rts

         emod
eom      equ   *
         end
