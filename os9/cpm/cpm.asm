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

XCTL     equ   $FFC9
XSTAT    equ   $FFCA
XID      equ   $FFCB
XIDX     equ   $FFCC
XDAT     equ   $FFCD
XE_MI    equ   $08
XE_MD    equ   $09
XE_WA    equ   $0A
XE_WD    equ   $0D

* offsets in the local FCB copy
F_DR     equ   0
F_NAME   equ   1
F_EXT    equ   9
F_EX     equ   12
F_S2     equ   14
F_RC     equ   15
F_PATH   equ   16                our OS-9 path number lives in the allocation map (d0)
F_SLOT   equ   17                our text file slot (1-based, 0 = binary file)
F_TSLOT  equ   18                our text temp file entry (1-based, 0 = none)
F_CR     equ   32
F_R0     equ   33
F_R1     equ   34
F_R2     equ   35

* request block (shared RAM)
NSLOT    equ   6
NT       equ   4                 text files open at the same time
SLOTSZ   equ   136               slot: path, mode, flags, rdlen, rdpos, 3 spare, 128 bytes buffer
S_PATH   equ   0
S_MODE   equ   1                 0 free, 1 text read, 2 text write
S_FLAGS  equ   2                 bit0 last CR, bit1 pending LF, bit2 no close, bit3 read with ReadLn
S_RDLEN  equ   3
S_RDPOS  equ   4
S_BUF    equ   8

RQZ80    equ   $FC80
RQ88     equ   $0600
LB88     equ   $0620

         mod   eom,name,tylg,atrv,start,size

         org   0
subty    rmb   1                 1 = Z80, 2 = 8088
path     rmb   1                 the program file
nsize    rmb   2
ndata    rmb   2
argp     rmb   2                 argument text
lin      rmb   3                 sub CPU linear address for rdsub / wrsub / setwin
fcblin   rmb   3
rqlin    rmb   3                 linear address of the request block
dseg     rmb   2                 DMA segment (0 for the Z80)
doff     rmb   2                 DMA offset
ptrp     rmb   2                 parameter of calcptr (big endian)
ptrs     rmb   2                 segment of calcptr (big endian)
tmp8     rmb   1
tmp8b    rmb   1
tmp16    rmb   2
rec      rmb   2
posx     rmb   2
posu     rmb   2
func     rmb   1
parh     rmb   1                 request parameter DE / DX
parl     rmb   1
rds      rmb   2                 request DS (big endian)
r_al     rmb   1                 reply
r_bl     rmb   1
r_bh     rmb   1
r_ah     rmb   1
done     rmb   1                 program ended
stdi      rmb   1                 our own copies of the standard paths (see start)
stdo     rmb   1
stde     rmb   1
model    rmb   1                 CP/M-86: 0 = 8080 model, 1 = small model
fcb      rmb   36
pname    rmb   80
pathbuf  rmb   96
optb     rmb   1
dbg      rmb   1
keep     rmb   1                 -k: the command tail keeps its case
tooldir  rmb   48
slotp    rmb   2
tcnt     rmb   1
tlast    rmb   1
tdst     rmb   2
slots    rmb   816                  NSLOT * SLOTSZ
tslots   rmb   16                   NT * 4: real path, temp path, flags (bit7 used, bit1 writable, bit0 modified)
tname    rmb   12
cbuf     rmb   256
cvlast   rmb   1
cvz      rmb   1
cvn      rmb   1
cvr      rmb   1
cvt      rmb   1
cvw      rmb   1
cvfl     rmb   1
srchpat  rmb   12                search first pattern
srchdir  rmb   1                 path of the directory being searched (0 = none)
srchcnt  rmb   1
dirent   rmb   32
sect     rmb   128
iobuf    rmb   256
         rmb   256               stack
size     equ   .

name     fcs   /cpm/
         fcb   edition

         use   shims.inc

msgusage fcc   "usage: cpm [-b -d -k -p=dir] file [arguments]"
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
         clr   srchdir,u
         lda   >XID
         cmpa  #1
         beq   idok
         cmpa  #2
         lbne  nosub
idok     sta   subty,u
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
         ldy   #832                  NSLOT * SLOTSZ + NT * 4
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
         bne   opt9
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
opt2     cmpa  #'P'
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
         bra   opt1
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
zp0      fcb   $C3,$40,$FC,$00,$00,$C3,$06,$FC

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

* the program ended: close the text files it left open (a changed writable one is converted back first)
cleanup  ldb   #1
cl1      pshs  b
         lbsr  tsx
         lda   2,x
         beq   cl9
         sta   cvfl,u
         lda   ,x
         sta   cvr,u
         lda   1,x
         sta   cvt,u
         clr   2,x
         lda   cvfl,u
         anda  #3
         cmpa  #3
         bne   cl2
         lbsr  cvtout
cl2      lda   cvt,u
         os9   I$Close
         ldb   ,s
         lbsr  tmpname
         lda   #UPDAT.
         leax  tname,u
         os9   I$Delete
         lda   cvr,u
         os9   I$Close
cl9      puls  b
         incb
         cmpb  #NT+1
         bne   cl1
         rts

nosub    leax  msgnosub,pcr
         bra   say
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
         ldx   #1
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

* lin = 00:D
setlin16 clr   lin,u
         std   lin+1,u
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

* lin = ptrs * 16 + ptrp   (24 bit, wraps at 1MB)
calcptr  lda   ptrs,u
         lsra
         lsra
         lsra
         lsra
         sta   lin,u
         ldd   ptrs,u
         lslb
         rola
         lslb
         rola
         lslb
         rola
         lslb
         rola
         addd  ptrp,u
         bcc   cp1
         inc   lin,u
cp1      std   lin+1,u
         lda   lin,u
         anda  #$0F
         sta   lin,u
         rts

* lin = request parameter (DE / DX) in the segment of the caller
ptrparm  lda   parh,u
         ldb   parl,u
         std   ptrp,u
         ldd   rds,u
         std   ptrs,u
         lbra  calcptr

* lin = DMA address
ptrdma   ldd   doff,u
         std   ptrp,u
         ldd   dseg,u
         std   ptrs,u
         lbra  calcptr

* lin += D
linadd   addd  lin+1,u
         std   lin+1,u
         bcc   la1
         inc   lin,u
la1      rts

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

upcase   cmpa  #'a'
         blo   up9
         cmpa  #'z'
         bhi   up9
         suba  #$20
up9      rts

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


* ------------------------------------------------------------------
* opening files: the current data directory first, then the tool directory (-p=)
* pname = name (CR terminated), A = mode -> A = path, carry set if both fail (B = error)
openany  sta   tmp8b,u
         leax  pname,u
         os9   I$Open
         bcc   oa9
         tst   tooldir,u
         beq   oaf
         lbsr  mkprefix
         leax  pathbuf,u
         lda   tmp8b,u
         os9   I$Open
oa9      rts
oaf      orcc  #1
         rts

* pathbuf = tooldir + "/" + pname
mkprefix leax  tooldir,u
         leay  pathbuf,u
mkp0      lda   ,x+
         beq   mkp1
         sta   ,y+
         bra   mkp0
mkp1      lda   -2,x
         cmpa  #'/'
         beq   mkp2
         lda   #'/'
         sta   ,y+
mkp2      leax  pname,u
mkp3      lda   ,x+
         sta   ,y+
         cmpa  #C$CR
         bne   mkp3
         rts

* the program file named at ,X: copy the name to pname, try it, then with ".COM" / ".CMD" appended.
* argp = the text behind the name.  Returns A = path (carry clear), X = argp.
openprog leay  pname,u
         clr   tmp8,u
op1      lda   ,x
         cmpa  #' '
         beq   op2
         cmpa  #C$CR
         beq   op2
         cmpa  #'.'
         bne   op1a
         inc   tmp8,u
op1a     sta   ,y+
         leax  1,x
         bra   op1
op2      stx   argp,u
         lda   #C$CR
         sta   ,y
         lda   #READ.
         lbsr  openany
         bcc   op9
         tst   tmp8,u
         bne   opf
         leax  pname,u               append the default extension
op3      lda   ,x+
         cmpa  #C$CR
         bne   op3
         leax  -1,x
         lda   subty,u
         cmpa  #2
         beq   op4
         leay  extcom,pcr
         bra   op5
op4      leay  extcmd,pcr
op5      ldb   #5
op6      lda   ,y+
         sta   ,x+
         decb
         bne   op6
         lda   #READ.
         lbsr  openany
op9      ldx   argp,u
         rts
opf      orcc  #1
         rts
extcom   fcc   ".COM"
         fcb   C$CR
extcmd   fcc   ".CMD"
         fcb   C$CR

* ------------------------------------------------------------------
* text files: CP/M text has CR LF line ends and ends with ^Z, OS-9 text has CR (the host: LF or CR LF).
* A text file gets a slot: the FCB field F_SLOT holds the slot number.
textext  fcc   "C  "
         fcc   "H  "
         fcc   "I  "
         fcc   "S  "
         fcc   "AS "
         fcc   "ASM"
         fcc   "MAC"
         fcc   "TXT"
         fcc   "DOC"
         fcc   "LST"
         fcc   "PRN"
         fcc   "BAS"
         fcc   "SUB"
         fcc   "HEX"
         fcb   0

* is the file of the FCB a text file?  Z set (carry clear) = text
istext   tst   optb,u
         bne   it_no
         leay  textext,pcr
it1      lda   ,y
         beq   it_no
         leax  fcb+F_EXT,u
         ldb   #3
it2      lda   ,x+
         anda  #$7F
         cmpa  ,y+
         bne   it3
         decb
         bne   it2
         andcc #$FE
         rts
it3      decb
         leay  b,y                  skip the rest of this entry
         bra   it1
it_no    orcc  #1
         rts

* a free slot: X = slot, B = number (1..NSLOT); carry set if none
allocslot leax slots,u
         ldb   #1
as1      tst   S_MODE,x
         beq   as2
         leax  SLOTSZ,x
         incb
         cmpb  #NSLOT+1
         bne   as1
         orcc  #1
         rts
as2      andcc #$FE
         rts

* X = slot number B (1-based)
slotx    leax  slots,u
         decb
         beq   sx9
sx1      leax  SLOTSZ,x
         decb
         bne   sx1
sx9      rts

* give the open path (A) of the FCB a text slot if its extension says so.  A = path, tmp8b = mode (1 read, 2 write)
mkslot   pshs  a
         lbsr  istext
         bcs   ms_no
         lbsr  allocslot
         bcs   ms_no
         stb   fcb+F_SLOT,u
         puls  a
         sta   S_PATH,x
         lda   tmp8b,u
         sta   S_MODE,x
         clr   S_FLAGS,x
         clr   S_RDLEN,x
         clr   S_RDPOS,x
         rts
ms_no    puls  a
         clr   fcb+F_SLOT,u
         rts

* the FCB names STDIN, STDOUT, STDERR select the OS-9 standard paths (text mode, never closed).
* returns carry clear and A = path number if it is one of them
isstd    leax  fcb+F_NAME,u
         leay  nmin,pcr
         lbsr  cmp8
         bne   is1
         clra
         ldb   #1
         stb   tmp8b,u
         andcc #$FE
         rts
is1      leax  fcb+F_NAME,u
         leay  nmout,pcr
         lbsr  cmp8
         bne   is2
         lda   #1
         ldb   #2
         stb   tmp8b,u
         andcc #$FE
         rts
is2      leax  fcb+F_NAME,u
         leay  nmerr,pcr
         lbsr  cmp8
         bne   is3
         lda   #2
         ldb   #2
         stb   tmp8b,u
         andcc #$FE
         rts
is3      orcc  #1
         rts
nmin     fcc   "STDIN   "
nmout    fcc   "STDOUT  "
nmerr    fcc   "STDERR  "

* compare 8 bytes at ,X with ,Y (bit 7 ignored); Z set if equal
cmp8     ldb   #8
c81      lda   ,x+
         anda  #$7F
         cmpa  ,y+
         bne   c89
         decb
         bne   c81
         clra                          Z set
c89      rts

* a std path: slot with no close.  A keyboard (SCF device) as standard input is read line by line with ReadLn,
* a file or a pipe with Read.
mkstd    sta   tmp8,u                standard path number 0, 1, 2
         lbsr  allocslot
         lbcs  fo_err
         stb   fcb+F_SLOT,u
         pshs  x
         leax  stdi,u                 the real path number: our copy
         ldb   tmp8,u
         lda   b,x
         sta   tmp16,u
         puls  x
         sta   S_PATH,x
         lda   tmp8b,u
         sta   S_MODE,x
         clr   S_RDLEN,x
         clr   S_RDPOS,x
         lda   #4
         sta   S_FLAGS,x
         tst   tmp8,u
         bne   mk1
         lda   tmp16,u
         ldb   #SS.Opt
         leax  iobuf,u
         os9   I$GetStt
         bcs   mk1
         lda   iobuf,u               PD.DTP: 0 = SCF
         bne   mk1
         ldb   fcb+F_SLOT,u
         lbsr  slotx
         lda   #$0C
         sta   S_FLAGS,x
mk1      lda   tmp8,u
         ora   #$80                  (path 0 must not look like "not open")
         sta   fcb+F_PATH,u
         rts

* next source byte of the text slot in slotp: A = byte; carry set at the end of the file
getsrc   ldx   slotp,u
         ldb   S_RDPOS,x
         cmpb  S_RDLEN,x
         blo   gs1
         ldb   S_FLAGS,x
         lda   S_PATH,x
         leax  S_BUF,x
         ldy   #128
         bitb  #8
         bne   gsl
         os9   I$Read
         bra   gsb
gsl      os9   I$ReadLn
gsb      bcc   gsc
         cmpb  #E$EOF                (a short last block may come with an end of file error)
         bne   gs_eof
gsc      cmpy  #0
         beq   gs_eof
         tfr   y,d
         ldx   slotp,u
         stb   S_RDLEN,x
         clr   S_RDPOS,x
         ldb   #0
gs1      leay  S_BUF,x
         lda   b,y
         incb
         stb   S_RDPOS,x
         andcc #$FE
         rts
gs_eof   orcc  #1
         rts

* fill sect with the next 128 bytes of the text file (X = slot): line ends become CR LF, the end is padded
* with ^Z.  Carry set if there is nothing left.
rdtext   stx   slotp,u
         leax  sect,u
         stx   tdst,u
         clr   tcnt,u
rt1      lda   tcnt,u
         cmpa  #128
         bhs   rt9
         ldx   slotp,u
         lda   S_FLAGS,x
         bita  #2
         beq   rt2
         anda  #$FD
         sta   S_FLAGS,x
         lda   #10
         bra   rtput
rt2      lbsr  getsrc
         bcs   rt_eof
         ldx   slotp,u
         ldb   S_FLAGS,x
         cmpa  #10
         bne   rt3
         bitb  #1
         beq   rt4
         andb  #$FE                    LF behind a CR: already done
         stb   S_FLAGS,x
         bra   rt1
rt3      cmpa  #13
         bne   rt5
         orb   #3
         stb   S_FLAGS,x
         lda   #13
         bra   rtput
rt4      orb   #2                      a lone LF is a line end too
         andb  #$FE
         stb   S_FLAGS,x
         lda   #13
         bra   rtput
rt5      andb  #$FE
         stb   S_FLAGS,x
rtput    ldx   tdst,u
         sta   ,x+
         stx   tdst,u
         inc   tcnt,u
         bra   rt1
rt_eof   lda   tcnt,u
         beq   rt_none
rtf      lda   tcnt,u
         cmpa  #128
         bhs   rt9
         ldx   tdst,u
         lda   #$1A
         sta   ,x+
         stx   tdst,u
         inc   tcnt,u
         bra   rtf
rt9      andcc #$FE
         rts
rt_none  orcc  #1
         rts

* write the 128 bytes in sect to the text file (X = slot): CR LF becomes CR, ^Z ends the data
wrtext   stx   slotp,u
         lda   S_FLAGS,x
         anda  #1
         sta   tlast,u
         leax  sect,u
         leay  iobuf,u
         lda   #128
         sta   tcnt,u
wt1      lda   ,x+
         cmpa  #$1A
         beq   wt9
         cmpa  #13
         bne   wt2
         sta   ,y+
         lda   #1
         sta   tlast,u
         bra   wtn
wt2      cmpa  #10
         bne   wt3
         tst   tlast,u
         beq   wt2b
         clr   tlast,u
         bra   wtn
wt2b     lda   #13
         sta   ,y+
         bra   wtn
wt3      sta   ,y+
         clr   tlast,u
wtn      dec   tcnt,u
         bne   wt1
wt9      ldx   slotp,u
         lda   S_FLAGS,x
         anda  #$FE
         ora   tlast,u
         sta   S_FLAGS,x
         tfr   y,d
         leax  iobuf,u
         pshs  x
         subd  ,s++
         tfr   d,y
         cmpy  #0
         beq   wt_ok
         ldx   slotp,u
         lda   S_PATH,x
         leax  iobuf,u
         os9   I$Write
wt_ok    rts


* -d: "[fn pppp]" on the error path
dbgcall  leax  iobuf+64,u
         lda   #'['
         sta   ,x+
         lda   func,u
         lbsr  puthex
         lda   #' '
         sta   ,x+
         lda   parh,u
         lbsr  puthex
         lda   parl,u
         lbsr  puthex
         lda   #']'
         sta   ,x+
         lda   #C$CR
         sta   ,x+
         bra   dbgout

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

* -d: the 11 characters of the FCB name
dbgname  leax  iobuf+64,u
         lda   #'<'
         sta   ,x+
         leay  fcb+1,u
         ldb   #11
dn_1     lda   ,y+
         anda  #$7F
         sta   ,x+
         decb
         bne   dn_1
         lda   #'>'
         sta   ,x+
         lda   #C$CR
         sta   ,x+
dbgout   leay  iobuf+64,u
         pshs  y
         tfr   x,d
         subd  ,s++
         tfr   d,y
         lda   stde,u
         leax  iobuf+64,u
         os9   I$Write
         rts


* ------------------------------------------------------------------
* Text files are converted as a whole.  When a text file is opened, its CP/M form (CR LF line ends, padded with
* ^Z to a multiple of 128 bytes) is built in a temporary file $CPMTn; all reads and writes of the program use
* that file (so sequential and random access both work).  When a file that was changed is closed, the
* temporary file is converted back (CR LF -> CR, up to the first ^Z) into the real file.
tmpname  leax  tname,u               name of temp file number B
         lda   #'$'
         sta   ,x+
         lda   #'C'
         sta   ,x+
         lda   #'P'
         sta   ,x+
         lda   #'M'
         sta   ,x+
         lda   #'T'
         sta   ,x+
         addb  #'0'
         stb   ,x+
         lda   #C$CR
         sta   ,x
         rts

* a free entry of the text table: X = entry, B = number (1..NT); carry set if none
alloct   leax  tslots,u
         ldb   #1
al1      lda   2,x
         bpl   al2
         leax  4,x
         incb
         cmpb  #NT+1
         bne   al1
         orcc  #1
         rts
al2      andcc #$FE
         rts

* X = entry for number B
tsx      leax  tslots,u
         decb
         beq   ts9
ts1      leax  4,x
         decb
         bne   ts1
ts9      rts

* the FCB just got a real path in F_PATH: if it is a text file, build the temporary CP/M form.
* tmp8b = 1 for an existing file (convert it), 2 for a new file.  Carry set: not made (the file stays binary).
mktslot  lbsr  istext
         bcs   mt_no
         lbsr  alloct
         bcs   mt_no
         stb   fcb+F_TSLOT,u
         lda   fcb+F_PATH,u
         sta   cvr,u
         sta   ,x
         lda   #$80
         tst   cvw,u
         beq   mt1
         lda   #$82
mt1      sta   2,x
         ldb   fcb+F_TSLOT,u
         lbsr  tmpname
         lda   #UPDAT.
         ldb   #READ.+WRITE.+PREAD.+PWRIT.
         leax  tname,u
         os9   I$Create
         bcc   mt2
         lda   #UPDAT.                (left over from an earlier run)
         leax  tname,u
         os9   I$Delete
         lda   #UPDAT.
         ldb   #READ.+WRITE.+PREAD.+PWRIT.
         leax  tname,u
         os9   I$Create
         bcs   mt_fail
mt2      sta   cvt,u
         ldb   fcb+F_TSLOT,u
         lbsr  tsx
         lda   cvt,u
         sta   1,x
         sta   fcb+F_PATH,u
         lda   tmp8b,u
         cmpa  #1
         bne   mt3
         lbsr  cvtin
mt3      andcc #$FE
         rts
mt_fail  ldb   fcb+F_TSLOT,u
         lbsr  tsx
         clr   2,x
         lda   cvr,u
         sta   fcb+F_PATH,u
mt_no    clr   fcb+F_TSLOT,u
         orcc  #1
         rts

* OS-9 text (path cvr) -> CP/M text (path cvt): CR, LF or CR LF become CR LF, the end is padded with ^Z
cvtin    clr   cvlast,u
         clr   cvn,u
ci1      lda   cvr,u
         leax  sect,u
         ldy   #128
         os9   I$Read
         bcc   ci2
         bra   ci_end
ci2      cmpy  #0
         beq   ci_end
         tfr   y,d
         stb   tcnt,u
         leax  sect,u
         leay  cbuf,u
ci3      lda   ,x+
         cmpa  #13
         bne   ci4
         ldb   #13
         stb   ,y+
         ldb   #10
         stb   ,y+
         lda   #1
         sta   cvlast,u
         bra   ci6
ci4      cmpa  #10
         bne   ci5
         tst   cvlast,u
         beq   ci4b
         clr   cvlast,u
         bra   ci6
ci4b     ldb   #13
         stb   ,y+
         ldb   #10
         stb   ,y+
         bra   ci6
ci5      sta   ,y+
         clr   cvlast,u
ci6      dec   tcnt,u
         bne   ci3
         lbsr  cvwrite
         bra   ci1
ci_end   ldb   cvn,u
         beq   ci_seek
         ldb   #128
         subb  cvn,u
         stb   tcnt,u
         leay  cbuf,u
         lda   #$1A
ci7      sta   ,y+
         dec   tcnt,u
         bne   ci7
         lbsr  cvwrite
ci_seek  lda   cvt,u
         ldx   #0
         pshs  u
         ldu   #0
         os9   I$Seek
         puls  u
         rts

* write cbuf .. Y to the path cvt and count the bytes (modulo 128) in cvn
cvwrite  leax  cbuf,u
         pshs  x
         tfr   y,d
         subd  ,s++
         tfr   d,y
         cmpy  #0
         beq   cw9
         tfr   y,d
         addb  cvn,u
         andb  #$7F
         stb   cvn,u
         lda   cvt,u
         leax  cbuf,u
         os9   I$Write
cw9      rts

* CP/M text (path cvt) -> OS-9 text (path cvr): CR LF -> CR, a lone LF -> CR, the data ends at the first ^Z
cvtout   lda   cvr,u
         ldx   #0
         pshs  u
         ldu   #0
         os9   I$Seek
         puls  u
         lda   cvr,u
         ldb   #SS.Size
         ldx   #0
         pshs  u
         ldu   #0
         os9   I$SetStt
         puls  u
         lda   cvt,u
         ldx   #0
         pshs  u
         ldu   #0
         os9   I$Seek
         puls  u
         clr   cvlast,u
         clr   cvz,u
co1      tst   cvz,u
         lbne  co_end
         lda   cvt,u
         leax  sect,u
         ldy   #128
         os9   I$Read
         bcs   co_end
         cmpy  #0
         beq   co_end
         tfr   y,d
         stb   tcnt,u
         leax  sect,u
         leay  cbuf,u
co2      lda   ,x+
         cmpa  #$1A
         bne   co3
         inc   cvz,u
         bra   co5
co3      cmpa  #13
         bne   co4
         sta   ,y+
         lda   #1
         sta   cvlast,u
         bra   co6
co4      cmpa  #10
         bne   co4b
         tst   cvlast,u
         beq   co4a
         clr   cvlast,u
         bra   co6
co4a     lda   #13
         sta   ,y+
         bra   co6
co4b     sta   ,y+
         clr   cvlast,u
co6      dec   tcnt,u
         bne   co2
co5      leax  cbuf,u
         pshs  x
         tfr   y,d
         subd  ,s++
         tfr   d,y
         cmpy  #0
         beq   co1
         lda   cvr,u
         leax  cbuf,u
         os9   I$Write
         lbra  co1
co_end   rts

* ------------------------------------------------------------------
* BDOS dispatcher: func in func,u ; result in r_al r_bl r_bh r_ah
dispatch clr   r_al,u
         clr   r_bl,u
         clr   r_bh,u
         clr   r_ah,u
         lda   func,u
         cmpa  #36
         bhi   dsp2
         leax  jtab,pcr
         ldb   func,u
         clra
         lslb
         rola
         ldd   d,x
         jmp   d,x
dsp2     cmpa  #51
         lbeq  f_sdmab
         cmpa  #52
         lbeq  f_gdmab
         rts
jtab     fdb   f_boot-jtab,f_conin-jtab,f_conout-jtab,f_nop-jtab,f_nop-jtab,f_nop-jtab,f_dio-jtab
         fdb   f_nop-jtab,f_nop-jtab,f_prstr-jtab,f_rdbuf-jtab,f_const-jtab,f_vers-jtab,f_nop-jtab
         fdb   f_seldsk-jtab,f_open-jtab,f_close-jtab,f_sfirst-jtab,f_snext-jtab,f_delete-jtab
         fdb   f_rdseq-jtab,f_wrseq-jtab,f_make-jtab,f_unsup-jtab,f_login-jtab,f_curdsk-jtab
         fdb   f_sdma-jtab,f_nop-jtab,f_nop-jtab,f_ro-jtab,f_nop-jtab,f_nop-jtab,f_user-jtab
         fdb   f_rdrnd-jtab,f_wrrnd-jtab,f_fsize-jtab,f_setrnd-jtab

f_nop    rts

* function 0: system reset / program end
f_boot   lda   #1
         sta   done,u
         rts

* return A (r_al) as the byte result: BL = AL, BH = 0
retA     lda   r_al,u
         sta   r_bl,u
         rts

f_conin  lda   stdi,u
         leax  iobuf,u
         ldy   #1
         os9   I$Read
         bcs   ci_e
         lda   iobuf,u
         sta   r_al,u
         bra   retA
ci_e     lda   #$1A
         sta   r_al,u
         bra   retA

f_conout lda   parl,u
         sta   iobuf,u
         lda   stdo,u
         leax  iobuf,u
         ldy   #1
         os9   I$Write
         rts

f_dio    lda   parl,u
         cmpa  #$FF
         beq   dio_in
         cmpa  #$FE
         beq   dio_st
         bra   f_conout
dio_st   lda   stdi,u
         ldb   #SS.Ready
         os9   I$GetStt
         bcs   dio_no
         lda   #$FF
         sta   r_al,u
         bra   retA
dio_no   rts
dio_in   lda   stdi,u
         ldb   #SS.Ready
         os9   I$GetStt
         bcs   dio_no
         bra   f_conin

f_const  bra   dio_st

f_prstr  lbsr  ptrparm
ps1      leax  sect,u
         ldy   #128
         lbsr  rdsub                  lin advanced by 128
         leax  sect,u
         ldy   #0
ps2      lda   ,x+
         cmpa  #'$'
         beq   ps3
         leay  1,y
         cmpy  #128
         bne   ps2
         lda   stdo,u                  the whole chunk, then the next one
         leax  sect,u
         ldy   #128
         os9   I$Write
         bra   ps1
ps3      cmpy  #0
         beq   ps9
         lda   stdo,u
         leax  sect,u
         os9   I$Write
ps9      rts


* function 10: read console buffer.  The buffer in the sub CPU: [max] [len] [chars...]
f_rdbuf  lbsr  ptrparm
         ldd   lin+1,u
         std   fcblin+1,u
         lda   lin,u
         sta   fcblin,u
         leax  sect,u
         ldy   #1
         lbsr  rdsub                  maximum length
         ldb   sect,u
         bne   rb0
         incb
rb0      clra
         tfr   d,y
         lda   stdi,u
         leax  iobuf,u
         os9   I$ReadLn
         bcs   rb8
         tfr   y,d                    count including the CR
         tstb
         beq   rb8
         decb                         length without the CR
         stb   sect,u
         leax  iobuf,u
         leay  sect+1,u
         tstb
         beq   rb2
rb1      lda   ,x+
         sta   ,y+
         decb
         bne   rb1
rb2      bra   rb9
rb8      clr   sect,u
rb9      ldd   fcblin+1,u             write [len][chars] at buffer+1
         addd  #1
         std   lin+1,u
         lda   fcblin,u
         sta   lin,u
         ldb   sect,u
         clra
         tfr   d,y
         leay  1,y
         leax  sect,u
         lbra  wrsub

f_vers   lda   subty,u
         cmpa  #2
         bne   v80
         ldd   #$1022                 CP/M-86 1.1: BX = 1022h
         bra   v1
v80      ldd   #$0022                 CP/M 2.2
v1       sta   r_bh,u
         stb   r_bl,u
         stb   r_al,u
         rts

f_seldsk rts
f_curdsk rts
f_user   rts
f_ro     rts
f_login  lda   #1
         sta   r_al,u
         sta   r_bl,u
         rts
f_unsup  lda   #$FF
         sta   r_al,u
         sta   r_bl,u
         rts

f_sdma   lda   parh,u
         ldb   parl,u
         std   doff,u
         rts

f_sdmab  lda   parh,u
         ldb   parl,u
         std   dseg,u
         rts

f_gdmab  ldd   dseg,u
         sta   r_bh,u
         stb   r_bl,u
         rts

* ------------------------------------------------------------------
* FCB handling.  The FCB is copied to the local buffer `fcb` (36 bytes) and written back after the call.
getfcb   lbsr  ptrparm
         ldd   lin+1,u
         std   fcblin+1,u
         lda   lin,u
         sta   fcblin,u
         leax  fcb,u
         ldy   #36
         lbsr  rdsub
         tst   dbg,u
         beq   gf9
         lbsr  dbgname
gf9      rts

putfcb   ldd   fcblin+1,u
         std   lin+1,u
         lda   fcblin,u
         sta   lin,u
         leax  fcb,u
         ldy   #36
         lbra  wrsub

* NAME.EXT from the FCB -> pname (CR terminated)
mkname   leax  fcb+F_NAME,u
         leay  pname,u
         ldb   #8
mn1      lda   ,x+
         anda  #$7F
         cmpa  #' '
         beq   mn3
         sta   ,y+
         decb
         bne   mn1
mn3      leax  fcb+F_EXT,u
         lda   ,x
         anda  #$7F
         cmpa  #' '
         beq   mn9
         lda   #'.'
         sta   ,y+
         ldb   #3
mn4      lda   ,x+
         anda  #$7F
         cmpa  #' '
         beq   mn9
         sta   ,y+
         decb
         bne   mn4
mn9      lda   #C$CR
         sta   ,y
         rts

* rec = ((s2 * 32 + ex) * 128) + cr   (sequential position of the FCB)
recseq   lda   fcb+F_S2,u
         anda  #$0F
         ldb   #32
         mul                          D = s2 * 32
         std   tmp16,u
         lda   fcb+F_EX,u
         anda  #$1F
         ora   tmp16+1,u
         sta   tmp16+1,u
         ldd   tmp16,u                D = extent number
         ldy   #7
rs1      lslb
         rola
         leay  -1,y
         bne   rs1
         pshs  d
         ldb   fcb+F_CR,u
         clra
         addd  ,s++
         std   rec,u
         rts

* rec = random record number r1:r0 of the FCB; carry set if r2 != 0
recrnd   lda   fcb+F_R1,u
         ldb   fcb+F_R0,u
         std   rec,u
         tst   fcb+F_R2,u
         beq   rr9
         orcc  #1
         rts
rr9      andcc #$FE
         rts

* set cr / ex / s2 of the FCB from rec
setpos   ldd   rec,u
         pshs  d
         andb  #$7F
         stb   fcb+F_CR,u
         puls  d
         lslb
         rola                         A = extent number (low 8 bits), carry = bit 8
         tfr   cc,b
         andb  #1
         stb   tmp8,u
         tfr   a,b
         andb  #$1F
         stb   fcb+F_EX,u
         lsra
         lsra
         lsra
         lsra
         lsra
         ldb   tmp8,u
         beq   sp1
         ora   #8
sp1      sta   fcb+F_S2,u
         rts

* advance the sequential position by one record
advpos   inc   fcb+F_CR,u
         lda   fcb+F_CR,u
         cmpa  #128
         blo   ap9
         clr   fcb+F_CR,u
         inc   fcb+F_EX,u
         lda   fcb+F_EX,u
         cmpa  #32
         blo   ap9
         clr   fcb+F_EX,u
         inc   fcb+F_S2,u
ap9      rts

* seek the file of the FCB to record `rec` (byte position rec * 128)
seekrec  ldd   rec,u
         lsra
         tfr   a,b
         clra
         tfr   d,x                    X = rec >> 9 (high word of the position)
         ldd   rec,u
         anda  #1
         ldy   #7
sk1      lslb
         rola
         leay  -1,y
         bne   sk1                    D = (rec & 1FFh) << 7 (low word)
         std   tmp16,u
         lda   fcb+F_PATH,u
         pshs  u
         ldu   tmp16,u
         os9   I$Seek
         puls  u
         rts

* read record `rec` into the DMA buffer.  Carry set at the end of the file.
rdrec    lbsr  seekrec
         leax  sect,u                 fill with ^Z
         ldb   #128
         lda   #$1A
rd1      sta   ,x+
         decb
         bne   rd1
         lda   fcb+F_PATH,u
         leax  sect,u
         ldy   #128
         os9   I$Read
         bcs   rdeof
         cmpy  #0
         beq   rdeof
         lbsr  ptrdma
         leax  sect,u
         ldy   #128
         lbsr  wrsub
         andcc #$FE
         rts
rdeof    orcc  #1
         rts

* write the DMA buffer as record `rec`
wrrec    lbsr  ptrdma
         leax  sect,u
         ldy   #128
         lbsr  rdsub
         lbsr  seekrec
         lda   fcb+F_PATH,u
         leax  sect,u
         ldy   #128
         os9   I$Write
         pshs  cc
         ldb   fcb+F_TSLOT,u
         beq   wr9
         lbsr  tsx
         lda   2,x
         ora   #1
         sta   2,x
wr9      puls  cc
         rts

err9     lda   #9                     invalid FCB
         sta   r_al,u
         lbra  retA

f_open   lbsr  getfcb
         clr   fcb+F_SLOT,u
         clr   fcb+F_TSLOT,u
         lbsr  isstd
         bcs   fo0
         lbsr  mkstd
         lbra  fo2
fo0      lbsr  mkname
         clr   cvw,u
         lda   #UPDAT.
         lbsr  openany
         bcs   fo0r
         inc   cvw,u
         bra   fo1
fo0r     lda   #READ.
         lbsr  openany
         lbcs  fo_err
fo1      sta   fcb+F_PATH,u
         lda   #1
         sta   tmp8b,u
         lbsr  mktslot
fo2      clr   fcb+F_CR,u
         lbra  putfcb
fo_err   lda   #$FF
         sta   r_al,u
         lbra  retA

f_close  lbsr  getfcb
         lda   fcb+F_PATH,u
         beq   fc9
         ldb   fcb+F_TSLOT,u
         bne   tclose
         ldb   fcb+F_SLOT,u
         beq   fc1
         lbsr  slotx
         lda   S_FLAGS,x
         pshs  a
         clr   S_MODE,x
         lda   S_PATH,x
         ldb   ,s+
         bitb  #4
         bne   fc2
         lda   fcb+F_PATH,u
fc1      os9   I$Close
fc2      clr   fcb+F_PATH,u
         clr   fcb+F_SLOT,u
         lbsr  putfcb
fc9      rts
tclose   lbsr  tsx
         lda   2,x
         sta   cvfl,u
         lda   ,x
         sta   cvr,u
         lda   1,x
         sta   cvt,u
         clr   2,x
         lda   cvfl,u
         anda  #3
         cmpa  #3                    changed and writable: convert back into the real file
         bne   tc2
         lbsr  cvtout
tc2      lda   cvt,u
         os9   I$Close
         ldb   fcb+F_TSLOT,u
         lbsr  tmpname
         lda   #UPDAT.
         leax  tname,u
         os9   I$Delete
         lda   cvr,u
         os9   I$Close
         clr   fcb+F_PATH,u
         clr   fcb+F_TSLOT,u
         lbra  putfcb

f_make   lbsr  getfcb
         clr   fcb+F_SLOT,u
         clr   fcb+F_TSLOT,u
         lbsr  isstd
         bcs   mk0
         lbsr  mkstd
         bra   mk3
mk0      lbsr  mkname
         lda   #UPDAT.
         ldb   #READ.+WRITE.+PREAD.+PWRIT.
         leax  pname,u
         os9   I$Create
         lbcs  fo_err
         sta   fcb+F_PATH,u
         lda   #1
         sta   cvw,u
         lda   #2
         sta   tmp8b,u
         lbsr  mktslot
mk3      clr   fcb+F_CR,u
         clr   fcb+F_EX,u
         clr   fcb+F_RC,u
         lbra  putfcb

f_delete lbsr  getfcb
         lbsr  mkname
         lda   #UPDAT.
         leax  pname,u
         os9   I$Delete
         lbcs  fo_err
         rts

f_rdseq  lbsr  getfcb
         lda   fcb+F_PATH,u
         lbeq  err9
         ldb   fcb+F_SLOT,u
         beq   rs_bin
         lbsr  slotx
         lbsr  rdtext
         bcs   eof1
         lbsr  ptrdma
         leax  sect,u
         ldy   #128
         lbsr  wrsub
         lbsr  advpos
         lbra  putfcb
rs_bin   lbsr  recseq
         lbsr  rdrec
         bcs   eof1
         lbsr  advpos
         lbra  putfcb
eof1     lda   #1
         sta   r_al,u
         lbra  retA

f_wrseq  lbsr  getfcb
         lda   fcb+F_PATH,u
         lbeq  err9
         ldb   fcb+F_SLOT,u
         beq   ws_bin
         pshs  b
         lbsr  ptrdma
         leax  sect,u
         ldy   #128
         lbsr  rdsub
         puls  b
         lbsr  slotx
         lbsr  wrtext
         lbsr  advpos
         lbra  putfcb
ws_bin   lbsr  recseq
         lbsr  wrrec
         bcs   werr
         lbsr  advpos
         lbra  putfcb
werr     lda   #2                     disk full
         sta   r_al,u
         lbra  retA

f_rdrnd  lbsr  getfcb
         lda   fcb+F_PATH,u
         lbeq  err9
         lbsr  recrnd
         bcs   oor
         lbsr  rdrec
         bcs   eof1
         lbsr  setpos
         lbra  putfcb
oor      lda   #6                     record number out of range
         sta   r_al,u
         lbra  retA

f_wrrnd  lbsr  getfcb
         lda   fcb+F_PATH,u
         lbeq  err9
         lbsr  recrnd
         bcs   oor
         lbsr  wrrec
         bcs   werr
         lbsr  setpos
         lbra  putfcb

f_setrnd lbsr  getfcb
         lbsr  recseq
         ldd   rec,u
         stb   fcb+F_R0,u
         sta   fcb+F_R1,u
         clr   fcb+F_R2,u
         lbra  putfcb

* compute file size: the record count goes to r0 r1 r2
f_fsize  lbsr  getfcb
         lbsr  mkname
         lda   #READ.
         leax  pname,u
         os9   I$Open
         lbcs  fo_err
         sta   tmp8b,u
         ldb   #SS.Size
         pshs  u
         os9   I$GetStt
         tfr   u,d
         puls  u
         std   posu,u
         stx   posx,u
         lda   tmp8b,u
         os9   I$Close
         ldd   posu,u
         addd  #127
         std   posu,u
         bcc   fs1
         ldx   posx,u
         leax  1,x
         stx   posx,u
fs1      ldd   posu,u
         lslb
         rola                         A = (size+127) >> 7 low byte part, carry = bit 8
         ldb   posx+1,u
         rolb
         sta   fcb+F_R0,u
         stb   fcb+F_R1,u
         clr   fcb+F_R2,u
         lbra  putfcb

* search for a file: first / next.  The matches are produced from the OS-9 directory `.`
f_sfirst lbsr  getfcb
         leax  fcb+F_NAME,u
         leay  srchpat,u
         ldb   #11
sf1      lda   ,x+
         anda  #$7F
         sta   ,y+
         decb
         bne   sf1
         tst   srchdir,u
         beq   sf2
         lda   srchdir,u
         os9   I$Close
         clr   srchdir,u
sf2      lda   #DIR.+READ.
         leax  dotname,pcr
         os9   I$Open
         lbcs  fo_err
         sta   srchdir,u
f_snext  lda   srchdir,u
         lbeq  fo_err
sn1      lda   srchdir,u
         leax  dirent,u
         ldy   #32
         os9   I$Read
         lbcs  sn_end
         cmpy  #32
         lbne  sn_end
         lda   dirent,u
         beq   sn1                    deleted entry
         lbsr  dir2cpm
         bcs   sn1
         lbsr  matchpat
         bcs   sn1
* a match: build the CP/M directory entry (32 bytes) in sect, rc from the file size
         leax  sect,u
         ldb   #32
         lda   #$E5
sn2      sta   ,x+
         decb
         bne   sn2
         clr   sect,u
         leax  iobuf,u
         leay  sect+1,u
         ldb   #11
sn3      lda   ,x+
         sta   ,y+
         decb
         bne   sn3
         clr   sect+12,u
         clr   sect+13,u
         clr   sect+14,u
         clr   sect+15,u
         lda   #READ.
         leax  pname,u
         os9   I$Open
         bcs   sn5
         sta   tmp8b,u
         ldb   #SS.Size
         pshs  u
         os9   I$GetStt
         tfr   u,d
         puls  u
         std   posu,u
         stx   posx,u
         lda   tmp8b,u
         os9   I$Close
         ldd   posu,u
         addd  #127
         bcc   sn4
         ldx   posx,u
         leax  1,x
         stx   posx,u
sn4      lslb
         rola
         ldb   posx+1,u
         rolb
         tsta                         record count of the first extent: at most 128
         bne   sn4a
         tstb
         bne   sn4a
         lda   #0
         bra   sn4b
sn4a     cmpb  #0
         bne   sn4c
         cmpa  #128
         bhi   sn4c
         bra   sn4b
sn4c     lda   #128
sn4b     sta   sect+15,u
sn5      lbsr  ptrdma
         leax  sect,u
         ldy   #32
         lbsr  wrsub
         clr   r_al,u                 found, entry 0 of the DMA buffer
         lbra  retA
sn_end   lda   srchdir,u
         os9   I$Close
         clr   srchdir,u
         lbra  fo_err

dotname  fcc   "."
         fcb   C$CR

* directory entry (dirent) -> pname (OS-9 name) and iobuf[0..10] (8.3 upper case, blank padded).  Carry: not usable.
dir2cpm  leax  dirent,u
         leay  pname,u
         ldb   #29
d1       lda   ,x+
         pshs  a
         anda  #$7F
         sta   ,y+
         puls  a
         tsta
         bmi   d2
         decb
         bne   d1
d2       lda   #C$CR
         sta   ,y
         leax  iobuf,u
         ldb   #11
         lda   #' '
d3       sta   ,x+
         decb
         bne   d3
         leax  pname,u
         lda   ,x
         cmpa  #'.'
         beq   dbad                   "." and ".."
         leay  iobuf,u
         ldb   #8
d4       lda   ,x+
         cmpa  #C$CR
         beq   dgood
         cmpa  #'.'
         beq   d5
         lbsr  upcase
         tstb
         beq   dbad
         sta   ,y+
         decb
         bra   d4
d5       leay  iobuf+8,u
         ldb   #3
d6       lda   ,x+
         cmpa  #C$CR
         beq   dgood
         cmpa  #'.'
         beq   dbad
         lbsr  upcase
         tstb
         beq   dbad
         sta   ,y+
         decb
         bra   d6
dgood    andcc #$FE
         rts
dbad     orcc  #1
         rts

* does iobuf[0..10] match the pattern srchpat ('?' matches any character)?  Carry set: no match
matchpat leax  iobuf,u
         leay  srchpat,u
         ldb   #11
mp1      lda   ,y+
         cmpa  #'?'
         beq   mp2
         cmpa  ,x
         bne   mpno
mp2      leax  1,x
         decb
         bne   mp1
         andcc #$FE
         rts
mpno     orcc  #1
         rts

         emod
eom      equ   *
         end
