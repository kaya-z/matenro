* SPDX-License-Identifier: MIT
********************************************************************
* kanjild - load the kanji image for the HDMI screen of the Tang Nano 20K from a file
*
*   kanjild [file]            (default /d1/kanji.bin)
*
* The file (185,856 bytes: scripts/mkkanji.py of sim09 makes it,
* fpga/tn9k/images/kanji.bin) is the image of the glyphs of JIS X 0208
* (levels 0 and 1) and the table Unicode -> glyph.  The HDMI screen reads it from the
* memory (SDRAM) at physical $200000,
* above the 2 MB of OS-9, so the program writes it through the window of the cross link
* with the bit HCTL.1 set ($FFC8: the
* window looks at the memory above 2 MB).  At the end HCTL.0 says to the HDMI screen that
* the image is there: from then on the
* characters of the console in UTF-8 / EUC-JP / Shift_JIS (ESC % G / E / S) are shown as
* kanji, before that as a box (the
* 8 bit characters of the font are shown at any time).  The image stays until the power is
* switched off: put the command
* into /d0/startup to load it at every start.
* Only the Tang Nano 20K machine has the register: the simulator and the 9K say "no kanji
* register".
*
* Credits: the module layout follows the sample commands of the NitrOS-9 project (GPL v2),
* as in os9/xrun.asm.
* The code is original.
********************************************************************

         nam   kanjild
         ttl   Load the kanji image of the HDMI screen

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

HCTL     equ   $FFC8
XIDX     equ   $FFCD
XDAT     equ   $FFCE
XE_WA    equ   $0A
XE_WD    equ   $0D

         mod   eom,name,tylg,atrv,start,size

         org   0
path     rmb   1
cnt      rmb   2
total    rmb   3
buf      rmb   256
         rmb   200               stack
size     equ   .

name     fcs   /kanjild/
         fcb   edition

defname  fcc   "/d1/kanji.bin"
         fcb   C$CR
msgok    fcc   "kanjild: the kanji image is loaded"
         fcb   C$CR
msgnoreg fcc   "kanjild: no kanji register (this machine has no HDMI screen with kanji)"
         fcb   C$CR
msgfile  fcc   "kanjild: cannot read the file"
         fcb   C$CR
msgbad   fcc   "kanjild: not a kanji image (it has to start with KJF1)"
         fcb   C$CR

start    lda   #$FE                is there a register?  it has two bits: after $FE a read gives 2 (plain RAM gives $FE)
         sta   >HCTL
         lda   >HCTL
         cmpa  #2
         lbne  nochoice
         clr   >HCTL
* the file name: the parameter, or the default
sk       lda   ,x+
         cmpa  #' '
         beq   sk
         leax  -1,x
         cmpa  #C$CR
         bne   op
         leax  defname,pcr
op       lda   #READ.
         os9   I$Open
         lbcs  nofile
         sta   path,u
         lda   #2                  the window above 2 MB; the image is not valid until the end
         sta   >HCTL
         lbsr  winz                the window at physical $200000
         clr   total,u
         clr   total+1,u
         clr   total+2,u
rd       lda   path,u
         leax  buf,u
         ldy   #256
         os9   I$Read
         bcs   eof
         sty   cnt,u
         leax  buf,u
wr       lda   ,x+
         sta   >XDAT
         leay  -1,y
         bne   wr
         ldd   total+1,u
         addd  cnt,u
         std   total+1,u
         bcc   rd
         inc   total,u
         bra   rd
eof      cmpb  #E$EOF
         lbne  bad
         lda   path,u
         os9   I$Close
* read back the first bytes: KJF1
         lbsr  winz
         lda   >XDAT
         cmpa  #'K'
         lbne  bad
         lda   >XDAT
         cmpa  #'J'
         lbne  bad
         lda   >XDAT
         cmpa  #'F'
         lbne  bad
         lda   >XDAT
         cmpa  #'1'
         lbne  bad
         lda   #1                  the window back below 2 MB, the image is there
         sta   >HCTL
         leax  msgok,pcr
         lda   #1
         ldy   #80
         os9   I$WritLn
         clrb
         os9   F$Exit
bad      clr   >HCTL
         leax  msgbad,pcr
         bra   err
nochoice clr   >HCTL
         leax  msgnoreg,pcr
         bra   err
nofile   leax  msgfile,pcr
err      lda   #2
         ldy   #80
         os9   I$WritLn
         ldb   #1
         os9   F$Exit

* the window address 0 (with HCTL.1: physical $200000), the data port to the window
winz     ldb   #XE_WA+$80
         stb   >XIDX
         clra                      (not CLR XDAT: it reads first, and a read advances the window)
         sta   >XDAT
         sta   >XDAT
         sta   >XDAT
         ldb   #XE_WD
         stb   >XIDX
         rts

         emod
eom      equ   *
         end
