* SPDX-License-Identifier: MIT
********************************************************************
* cpm - run a CP/M-80 or CP/M-86 program on the sub CPU of 摩天楼 (Matenro) from OS-9 Level 2
*
*   cpm [-b] [-p=dir] file [arguments]
*
*   -d      debug: log every BDOS call (function, parameter, FCB name) on the error path
*   -b      treat all files as binary (default: files with a text extension such as .C .H .I .ASM .TXT are text)
*   -p=dir  tool directory: a file that is not in the current data directory is also looked for in dir (read only)
*           (the program itself too: `cpm -p=/dd/htc c309 prog.i`)
*
*   sub CPU Z80   file is a CP/M-80 program (.COM), loaded at 0100h of the Z80's 64K
*   sub CPU 8088  file is a CP/M-86 program (.CMD: 128 byte header with group descriptors)
*
* The sub CPU runs the program unchanged.  Every BDOS call (CALL 5 / INT E0h) is handed to this program through
* a request block in the shared RAM and the doorbell of the cross link; this program does the work with OS-9
* system calls (console on the standard paths, files in the current data directory, one OS-9 file per CP/M
* file, 128 byte records) and writes the reply.  The program ends with BDOS function 0 (a warm boot, RET to 0).
* Guest side stubs: z80shim.asm, i8088shim.asm (assembled to shims.inc by mkshims.py).
*
* Implemented BDOS functions (both CPUs): 0 1 2 6 9 10 11 12 13 14 15 16 17 18 19 20 21 22 24 25 26 29 30 32
* 33 34 35 36; CP/M-86 only: 51 52 (DMA base).  Everything else answers 0.  Drive letters are ignored (one drive).
*
* The user state program reaches the cross link in the I/O page ($FFC9-$FFCD of the Level 2 machine) and the
* sub CPU memory through the window port, like `xrun`; run the simulator with -m 1M.  Register interface:
* docs/DESIGN.md.
*
* Credits: the BDOS function numbers, FCB layout and result conventions are those of Digital Research's
* CP/M 2.2 and CP/M-86 (public documentation: the CP/M 2.2 Interface Guide, the CP/M-86 System Guide); the
* .CMD header layout follows the CP/M-86 System Guide.  The module layout (mod/emod, os9 calls) follows the
* sample commands of the NitrOS-9 project (GPL v2), see sim09's misc/shutdown.asm; the definition files are
* NitrOS-9's (read with a09 -I, not copied).  The code is original.
********************************************************************

         nam   cpm
         ttl   Run CP/M-80 and CP/M-86 programs on the sub CPU

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

         use   cpmdefs.asm

         mod   eom,name,tylg,atrv,start,size

         use   cpmdata.asm

name     fcs   /cpm/
         fcb   edition

         use   shims.inc

msgusage fcc   "usage: cpm [-b -d -k -p=dir -m=B:dir] file [arguments]"
         fcb   C$CR
msgnosub fcc   "cpm: no Z80 or 8088 sub CPU"
         fcb   C$CR
msgfile  fcc   "cpm: cannot read the program file"
         fcb   C$CR
msgbad   fcc   "cpm: not a CP/M-86 .CMD file"
         fcb   C$CR
msgbig   fcc   "cpm: program too big"
         fcb   C$CR

* ------------------------------------------------------------------
start    stx   argp,u
         clr   done,u
         clr   rawf,u
         clr   srchdir,u
         lda   >XID
         cmpa  #1
         beq   idok
         cmpa  #2
         lbne  nosub
idok     sta   subty,u
         clr   xpath,u               the driver (xlink.asm): memory from OS-9, interrupt for the doorbell
         leax  x0name,pcr
         lda   #UPDAT.
         os9   I$Open
         bcs   idok2
         sta   xpath,u
idok2
         clr   >XCTL                 hold the sub CPU in reset
         clra                        the standard paths (kept in variables so that they can be redirected)
         sta   stdi,u
         inca
         sta   stdo,u
         inca
         sta   stde,u
         clr   optb,u
         clr   dbg,u
         clr   keep,u
         clr   tooldir,u
         leax  slots,u               the data area is not cleared by OS-9: free all text slots
         ldy   #clrend-slots
cls1     clr   ,x+
         leay  -1,y
         bne   cls1
         clr   srchdir,u
         ldx   argp,u
opt1     lda   ,x+
         cmpa  #' '
         beq   opt1
         cmpa  #C$CR
         lbeq  usage
         cmpa  #'-'
         lbne  opt9
         lda   ,x+
         anda  #$DF
         cmpa  #'B'
         bne   opt1d
         inc   optb,u
         bra   opt1
opt1d    cmpa  #'D'
         bne   opt1k
         inc   dbg,u
         bra   opt1
opt1k    cmpa  #'K'
         bne   opt2
         inc   keep,u
         bra   opt1
opt2     cmpa  #'M'
         bne   opt2p
         lda   ,x+                   -m=B:/d1   drive B: is the directory /d1
         lda   ,x+
         lbsr  upcase
         suba  #'A'
         lbmi  usage
         cmpa  #15
         lbhi  usage
         inca
         pshs  a
         leay  drvtab,u
         ldb   #NDRV
om1      tst   ,y
         beq   om2
         leay  DRVSZ,y
         decb
         bne   om1
         leas  1,s
         lbra  usage                 too many
om2      puls  a
         sta   ,y+
         lda   ,x+                   ':'
         ldb   #DRVSZ-2
om3      lda   ,x
         cmpa  #' '
         beq   om4
         cmpa  #C$CR
         beq   om4
         sta   ,y+
         leax  1,x
         decb
         bne   om3
om4      clr   ,y
         lbra  opt1
opt2p    cmpa  #'P'
         lbne  usage
         lda   ,x+                   '='
         leay  tooldir,u
opt3     lda   ,x
         cmpa  #' '
         beq   opt4
         cmpa  #C$CR
         beq   opt4
         sta   ,y+
         leax  1,x
         bra   opt3
opt4     clr   ,y
         lbra  opt1
opt9     leax  -1,x
         lbsr  openprog              A = path, X behind the name
         lbcs  nofile
         sta   path,u
         stx   argp,u                X is behind the file name
         lda   subty,u
         cmpa  #1
         lbne  load88
* ---------------------------------------------------------------- Z80: load the .COM file at 0100h
         clr   dseg,u
         clr   dseg+1,u
         leax  z80shim,pcr           the shim at FC00h
         ldy   #z80shimn
         ldd   #$FC00
         lbsr  setlin16
         lbsr  wrsub
         lbsr  loadfile
         lbcs  nofile
         lda   path,u
         os9   I$Close
         ldd   #$0000                zero page: 0000 JP START, 0005 JP BDOS
         lbsr  setlin16
         leax  zp0,pcr
         ldy   #8
         lbsr  wrsub
         clr   doff,u
         lda   #$80
         sta   doff+1,u
         lbsr  tailfcb               command tail and the two FCBs
         ldd   #RQZ80
         lbsr  setrq
         lbsr  clrflag
         lda   >XSTAT                a doorbell left by the previous program would look like a request
         sta   >XSTAT
         lda   #1
         sta   >XCTL                 go
         bra   serve
zp0      fcb   $C3,$C0,$FC,$00,$00,$C3,$06,$FC

* ---------------------------------------------------------------- main loop: serve BDOS calls
serve    lbsr  waitrq
         lbsr  getrq
         tst   dbg,u
         beq   sv1
         lbsr  dbgcall
sv1
         lbsr  dispatch
         lbsr  putrq
         tst   done,u
         beq   serve
         clr   >XCTL                 stop the sub CPU
         lbsr  cleanup
         tst   srchdir,u
         beq   exit0
         lda   srchdir,u
         os9   I$Close
exit0    clrb
         os9   F$Exit


nosub    leax  msgnosub,pcr
         bra   say
x0name   fcc   "/x0"
         fcb   C$CR
SS.XWait equ   $B1

usage    leax  msgusage,pcr
         bra   say
nofile   leax  msgfile,pcr
         bra   say
badcmd   leax  msgbad,pcr
         bra   say
toobig   leax  msgbig,pcr
say      lda   #2
         ldy   #80
         os9   I$WritLn
         ldb   #1
         os9   F$Exit

* ------------------------------------------------------------------
* wait for the doorbell of the sub CPU and acknowledge it
waitrq   ldy   #3000
wq1      lda   >XSTAT
         bita  #1
         bne   wq2
         leay  -1,y
         bne   wq1
         tst   xpath,u
         beq   wq0
         lda   xpath,u               sleep until the doorbell interrupt (the driver)
         ldb   #SS.XWait
         ldx   #100
         os9   I$GetStt
         bra   waitrq
wq0      ldx   #1
         os9   F$Sleep
         bra   waitrq
wq2      sta   >XSTAT                acknowledge
         rts

* request block address -> rqlin (D = low 16 bits, hi byte 0 for the Z80 and 8088)
setrq    clr   rqlin,u
         std   rqlin+1,u
         rts

* read the request: func, parameter, DS
getrq    ldd   rqlin+1,u
         std   lin+1,u
         lda   rqlin,u
         sta   lin,u
         leax  iobuf,u
         ldy   #8
         lbsr  rdsub
         lda   iobuf,u
         sta   func,u
         lda   iobuf+1,u
         sta   parl,u
         lda   iobuf+2,u
         sta   parh,u
         lda   subty,u
         cmpa  #2
         bne   gr1
         lda   iobuf+5,u             DS high
         sta   rds,u
         lda   iobuf+4,u
         sta   rds+1,u
         rts
gr1      clr   rds,u
         clr   rds+1,u
         rts

* write the reply: AL BL BH AH, then the done flag
putrq    ldd   rqlin+1,u
         addd  #8
         std   lin+1,u
         lda   rqlin,u
         sta   lin,u
         lda   r_al,u
         sta   iobuf,u
         lda   r_bl,u
         sta   iobuf+1,u
         lda   r_bh,u
         sta   iobuf+2,u
         lda   r_ah,u
         sta   iobuf+3,u
         lda   #1
         sta   iobuf+4,u
         leax  iobuf,u
         ldy   #5
         lbsr  wrsub
         rts

* clear the "done" flag of the request block before the sub CPU starts
clrflag  ldd   rqlin+1,u
         addd  #12
         std   lin+1,u
         lda   rqlin,u
         sta   lin,u
         clr   iobuf,u
         leax  iobuf,u
         ldy   #1
         lbsr  wrsub
         rts


* ------------------------------------------------------------------
* sub CPU memory access.  lin = 24 bit linear address (hi nibble, mid, low); X = buffer, Y = count
setwin   lda   lin,u
         anda  #$0F
         lsla
         lsla
         lsla
         ldb   lin+1,u
         lsrb
         lsrb
         lsrb
         lsrb
         lsrb
         stb   tmp8,u
         ora   tmp8,u                SMMU block 0..127
         ldb   #XE_MI
         stb   >XIDX
         sta   >XDAT
         ldb   #XE_MD
         stb   >XIDX
         lda   >XDAT                 physical block
         sta   tmp8,u
         ldb   #XE_WA+$80
         stb   >XIDX
         lsra
         lsra
         lsra
         sta   >XDAT                 physical address bits 20-16
         lda   tmp8,u
         anda  #7
         lsla
         lsla
         lsla
         lsla
         lsla
         sta   tmp8,u
         lda   lin+1,u
         anda  #$1F
         ora   tmp8,u
         sta   >XDAT
         lda   lin+2,u
         sta   >XDAT
         ldb   #XE_WD
         stb   >XIDX
         rts

* read Y bytes from the sub CPU at lin into ,X ; lin advances
rdsub    cmpy  #0
         beq   rds9
         pshs  x,y
         lbsr  setwin
         puls  x,y
rds2     lda   >XDAT
         sta   ,x+
         inc   lin+2,u
         bne   rds4
         inc   lin+1,u
         bne   rds3
         inc   lin,u
rds3     lda   lin+1,u
         anda  #$1F
         bne   rds4
         pshs  x,y
         lbsr  setwin
         puls  x,y
rds4     leay  -1,y
         bne   rds2
rds9     rts

* write Y bytes from ,X to the sub CPU at lin ; lin advances
wrsub    cmpy  #0
         beq   wrs9
         pshs  x,y
         lbsr  setwin
         puls  x,y
wrs2     lda   ,x+
         sta   >XDAT
         inc   lin+2,u
         bne   wrs4
         inc   lin+1,u
         bne   wrs3
         inc   lin,u
wrs3     lda   lin+1,u
         anda  #$1F
         bne   wrs4
         pshs  x,y
         lbsr  setwin
         puls  x,y
wrs4     leay  -1,y
         bne   wrs2
wrs9     rts

* ------------------------------------------------------------------
* load the rest of the program file into the sub CPU at lin = 000100 (Z80), up to the BDOS at FC00
loadfile ldd   #$0100
         lbsr  setlin16
lf1      lda   path,u
         leax  iobuf,u
         ldy   #256
         os9   I$Read
         bcs   lf8
         pshs  y
         leax  iobuf,u
         lbsr  wrsub
         puls  y
         ldd   lin+1,u
         cmpd  #$FC00
         bhs   lf9
         bra   lf1
lf8      cmpb  #E$EOF
         bne   lfe
         andcc #$FE
         rts
lf9      andcc #$FE
         rts
lfe      orcc  #1
         rts

* ------------------------------------------------------------------
* command tail and the two FCBs of the base page (offset 0 of the segment dseg; 0 for the Z80)
tailfcb  ldx   argp,u
tf1      lda   ,x
         cmpa  #' '
         bne   tf2
         leax  1,x
         bra   tf1
tf2      stx   argp,u
         leay  iobuf+2,u             tail: length, ' ', text (upper case) up to CR
         lda   #' '
         sta   iobuf+1,u
         clrb
tf3      lda   ,x+
         cmpa  #C$CR
         beq   tf4
         cmpb  #120
         bhs   tf3
         tst   keep,u
         bne   tf3a
         lbsr  upcase
tf3a     sta   ,y+
         incb
         bra   tf3
tf4      tstb
         beq   tf5
         incb
tf5      stb   iobuf,u
         bne   tf6
         clr   iobuf+1,u
tf6      ldd   #$0080
         lbsr  basepage
         leax  iobuf,u
         ldb   iobuf,u
         clra
         tfr   d,y
         leay  2,y
         lbsr  wrsub
         ldx   argp,u                FCB 1 and FCB 2
         lbsr  pfcb
         stx   argp,u
         ldd   #$005C
         lbsr  basepage
         leax  fcb,u
         ldy   #36
         lbsr  wrsub
         ldx   argp,u
         lbsr  pfcb
         ldd   #$006C
         lbsr  basepage
         leax  fcb,u
         ldy   #16                   FCB 2 is 16 bytes: the rest of it would overwrite the command tail
         lbsr  wrsub
         rts

* lin = dseg * 16 + D
basepage std   ptrp,u
         ldd   dseg,u
         std   ptrs,u
         lbra  calcptr


* parse a file name argument at ,X into fcb ; X advances behind the token
pfcb     leay  fcb,u
         ldb   #36
pf0      clr   ,y+
         decb
         bne   pf0
         leay  fcb+1,u
         ldb   #11
         lda   #' '
pf1      sta   ,y+
         decb
         bne   pf1
pf2      lda   ,x
         cmpa  #' '
         bne   pf3
         leax  1,x
         bra   pf2
pf3      lda   1,x                   drive letter?
         cmpa  #':'
         bne   pf4
         lda   ,x
         lbsr  upcase
         suba  #'A'-1
         sta   fcb,u
         leax  2,x
pf4      leay  fcb+1,u
         ldb   #8
pf5      lda   ,x
         cmpa  #C$CR
         beq   pf9
         cmpa  #' '
         beq   pf9
         cmpa  #'.'
         beq   pf6
         leax  1,x
         cmpa  #'*'
         beq   pfstar
         lbsr  upcase
         tstb
         beq   pf5
         sta   ,y+
         decb
         bra   pf5
pfstar   lda   #'?'
pfs1     tstb
         beq   pf5
         sta   ,y+
         decb
         bra   pfs1
pf6      leax  1,x                   skip '.', extension
         leay  fcb+9,u
         ldb   #3
pf7      lda   ,x
         cmpa  #C$CR
         beq   pf9
         cmpa  #' '
         beq   pf9
         leax  1,x
         cmpa  #'*'
         beq   pfstar2
         lbsr  upcase
         tstb
         beq   pf7
         sta   ,y+
         decb
         bra   pf7
pfstar2  lda   #'?'
pfs2     tstb
         beq   pf7
         sta   ,y+
         decb
         bra   pfs2
pf9      rts

* ------------------------------------------------------------------
* CP/M-86: parse the .CMD header, load the groups, set up the launch block
* header: 8 group descriptors of 9 bytes: form(1) length(2) abase(2) min(2) max(2); lengths in paragraphs.
* 8080 model: one code group, CS = DS = ES = SS = 1000h, the code is loaded at 0100h, IP = 0100h.
* small model: code group (form 1) loaded at 1000h:0000, data group (form 2) at 2000h:0100, DS = ES = SS = 2000h.
load88   leax  iobuf,u
         ldy   #128
         lda   path,u
         os9   I$Read
         lbcs  nofile
         cmpy  #128
         lbne  badcmd
         lda   iobuf,u
         cmpa  #1
         lbne  badcmd
         clr   model,u                model = 0: 8080 model
         ldd   #$1000
         std   dseg,u
         lda   iobuf+9,u
         cmpa  #2
         bne   l88a
         inc   model,u                small model
         ldd   #$2000
         std   dseg,u
l88a     lda   iobuf+2,u             code length (paragraphs, big endian in D)
         ldb   iobuf+1,u
         lbsr  paras
         std   nsize,u
         lda   iobuf+11,u            data length
         ldb   iobuf+10,u
         lbsr  paras
         std   ndata,u
         leax  i88shim,pcr           INT E0 stub at 0000:0500, start code, EXITSTUB
         ldy   #i88shimn
         ldd   #$0500
         lbsr  setlin16
         lbsr  wrsub
         ldd   #$0380                IVT entry of INT E0h
         lbsr  setlin16
         leax  ivt88,pcr
         ldy   #4
         lbsr  wrsub
         lda   #$0F                  reset vector at FFFF0
         sta   lin,u
         ldd   #$FFF0
         std   lin+1,u
         leax  i88rst,pcr
         ldy   #i88rstn
         lbsr  wrsub
         lda   #1                    code group: linear 10000h (+0100h in the 8080 model)
         sta   lin,u
         clr   lin+1,u
         clr   lin+2,u
         tst   model,u
         bne   l88b
         inc   lin+1,u
l88b     lbsr  readgrp
         lbcs  nofile
         tst   model,u
         beq   l88c
         ldd   ndata,u               data group: 20100h
         std   nsize,u
         lda   #2
         sta   lin,u
         ldd   #$0100
         std   lin+1,u
         lbsr  readgrp
         lbcs  nofile
l88c     lda   path,u
         os9   I$Close
         clr   doff,u
         lda   #$80
         sta   doff+1,u
         lbsr  tailfcb               base page of the data segment: tail and FCBs
         ldd   #$0000                INT E0 stub at DS:0000 for a near RET of the 8080 model
         lbsr  basepage
         leax  stub0,pcr
         ldy   #4
         lbsr  wrsub
         ldd   #$FFFA                initial stack
         lbsr  basepage
         leax  stk80,pcr
         ldy   #2
         tst   model,u
         beq   l88d
         leax  stk86,pcr
         ldy   #4
l88d     lbsr  wrsub
         ldd   #LB88                 launch block: IP CS DS ES SS SP
         lbsr  setlin16
         clr   iobuf,u               IP = 0100h (8080 model) or 0000h
         clr   iobuf+1,u
         tst   model,u
         bne   l88e
         inc   iobuf+1,u
l88e     clr   iobuf+2,u             CS = 1000h
         lda   #$10
         sta   iobuf+3,u
         lda   dseg+1,u
         ldb   dseg,u
         sta   iobuf+4,u             DS
         stb   iobuf+5,u
         sta   iobuf+6,u             ES
         stb   iobuf+7,u
         sta   iobuf+8,u             SS
         stb   iobuf+9,u
         lda   #$FA                  SP = FFFAh
         sta   iobuf+10,u
         lda   #$FF
         sta   iobuf+11,u
         leax  iobuf,u
         ldy   #12
         lbsr  wrsub
         ldd   #RQ88
         lbsr  setrq
         lbsr  clrflag
         lda   >XSTAT                (see the Z80 start)
         sta   >XSTAT
         lda   #1
         sta   >XCTL
         lbra  serve
ivt88    fcb   $00,$05,$00,$00
stub0    fcb   $B1,$00,$CD,$E0           mov cl,0 ; int E0h
stk80    fcb   $00,$00
stk86    fcb   $80,$05,$00,$00           RETF -> 0000:0580 (EXITSTUB)

* D = paragraphs -> D = bytes (x16, the groups are smaller than 64K)
paras    lslb
         rola
         lslb
         rola
         lslb
         rola
         lslb
         rola
         rts

* read nsize bytes of the program file into the sub CPU at lin (a short file ends the group early)
readgrp  ldd   nsize,u
         std   tmp16,u                remaining bytes
rg1      ldd   tmp16,u
         beq   rg9
         cmpd  #256
         bls   rg2
         ldd   #256
rg2      tfr   d,y
         lda   path,u
         leax  iobuf,u
         os9   I$Read
         bcs   rgerr
         cmpy  #0
         beq   rg9
         tfr   y,d
         pshs  d
         ldd   tmp16,u
         subd  ,s
         std   tmp16,u
         puls  d
         tfr   d,y
         leax  iobuf,u
         lbsr  wrsub
         bra   rg1
rg9      andcc #$FE
         rts
rgerr    cmpb  #E$EOF
         beq   rg9
         orcc  #1
         rts


         use   cpmengine.asm

         emod
eom      equ   *
         end
