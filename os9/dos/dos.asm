* SPDX-License-Identifier: MIT
********************************************************************
* dos - run MS-DOS 1.25 on the 8088 of 摩天楼 (Matenro) from OS-9 Level 2
*
*   dos [-k=kernel] -a=image [-b=image] [-c=image] [-d=image] [-p=printer] [-i=auxin] [-o=auxout]
*
*   -k=file   the MS-DOS kernel (default msdos.sys in the current data directory)
*   -a=file   the disk image of drive A: (a FAT12 image: tools/mkdosimg.py; COMMAND.COM must be on it); -b -c -d: B: C: D:
*             the size of the file decides the format: 160 KB, 320 KB (IBM formats) or 8 MB (hard disk)
*   -v=2      MS-DOS 2.0: the BIOS is the file -s=bios (default bios2.bin; tools/build_dosbin2.sh), -k the kernel MSDOS.SYS
*   -p=path   the printer (PRN): the output is appended to the file or device (nothing without it)
*   -o=path   the aux port output (AUX), appended;  -i=path  the aux port input, read from the start (1Ah at the end)
*
* The 8088 runs the kernel and COMMAND of MS-DOS 1.25 unchanged (assembled from the source that Microsoft published,
* tools/build_dosbin.sh).  The BIOS (IO.SYS) is ours (bios88.asm, embedded): every call of the kernel becomes a request
* block in the shared RAM and a doorbell of the cross link; this program does the work with OS-9 system calls and
* writes the reply.  The console is the standard input and output, in the raw mode (DOS echoes and edits itself).
* The key ^] (1Dh) leaves DOS: the 8088 is stopped and the terminal is put back.
* Stage 7 of docs/DESIGN.md chapter 18: console, time (DATE and TIME are an offset kept by the BIOS), disk images (COMMAND.COM
* is read from drive A by the BIOS), printer and aux port.
*
* The user state program reaches the cross link in the I/O page ($FFC9-$FFCD of the Level 2 machine) and the
* sub CPU memory through the window port, like `cpm`; the sub CPU must be the 8088 (-sub 8088; -m 1M without the
* driver xlink).
*
* Credits: the module layout follows the sample commands of the NitrOS-9 project (GPL v2), see os9/cpm/cpm.asm.  The
* BIOS entries are those of MS-DOS 1.25 (see bios88.asm).  The code is original.
********************************************************************

         nam   dos
         ttl   Run MS-DOS on the 8088

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

         use   cpmdefs.asm

SS.XWait equ   $B1
BIOSLIN  equ   $0400             linear address of the BIOS (segment 0040h)
RQLIN    equ   $0800             request block: BIOS + 400h
LBLIN    equ   $0840             BIOS + 440h: memory size in paragraphs, +4 the INITTAB
DOSLIN   equ   $0900             kernel (segment 0090h)
INITBIOS equ   $0444             the INITTAB as seen by the BIOS (an offset in segment 0040h)
RQLIN2   equ   $0410             2.0: the request block at 10h of the BIOS (bios2.asm)
LBLIN2   equ   $0440             2.0: +0 memory size, +2 number of units, +4 the BPBs
MEMPARA  equ   $4000             256 KB: what the 8088 gets with the driver xlink (32 blocks)
EXITKEY  equ   $1D               ^]

         mod   eom,name,tylg,atrv,start,size

         org   0
path     rmb   1                 kernel file
dsp      rmb   1                 the image of the disk call
nimg     rmb   1                 drives with an image
dpath    rmb   4                 the paths of the images
dname    rmb   8                 the names (pointers into the parameters), 0 = none
szh      rmb   2                 size of an image
szl      rmb   2
seeklo   rmb   2
dcnt     rmb   2                 sectors to do
itab     rmb   53                the INITTAB with the disk parameter tables
xpath    rmb   1                 /x0 (the xlink driver), 0 = not loaded
argp     rmb   2
kname    rmb   2                 the name of the kernel (in the parameters or the default)
ver      rmb   1                 1: MS-DOS 1.25 (the BIOS is in this module), 2: MS-DOS 2.0 (bios2.bin, -v=2)
bnm      rmb   2                 -s=: the file with the BIOS of 2.0
rqad     rmb   2                 the request block in the sub CPU memory
bpath    rmb   1                 the file of the BIOS of 2.0
blen     rmb   2                 the length of the BIOS image of 2.0
tmpy     rmb   2
bpbs     rmb   52                the BPBs of the drives (13 bytes each) for 2.0
pnm      rmb   2                 the names of the printer (-p=), the aux input (-i=) and the aux output (-o=), 0 = none
inm      rmb   2
onm      rmb   2
ppath    rmb   1                 their paths, 0 = none
ipath    rmb   1
opath    rmb   1
lin      rmb   3                 sub CPU linear address for rdsub / wrsub / setwin
tmp8     rmb   1
cnt      rmb   2
kbv      rmb   1                 a key is waiting in kbc
kbc      rmb   1
rawf     rmb   1                 the terminal is in the raw mode
done     rmb   1                 leave
rq       rmb   12                request: 0 func, 1 AX, 4 BX, 6 CX, 8 DX, 10 DS (low byte first)
rp       rmb   17                reply: 0 AL, 1 AH, 2 BX, 4 CX, 6 DX, 8 flags, 10 time (6), 16 done
oldopt   rmb   32
iobuf    rmb   256
sbuf     rmb   512
         rmb   200               stack
size     equ   .

name     fcs   /dos/
         fcb   edition

         use   bios.inc

defk     fcc   "msdos.sys"
         fcb   C$CR
x0name   fcc   "/x0"
         fcb   C$CR
lbdata   fcb   $00,$40                 MEMPARA
rstvec   fcb   $EA,$00,$00,$40,$00      JMP FAR 0040:0000 (the BIOS) at FFFF0
* the formats: the size of the image (high word, low word), the disk parameter table: sector size, sectors per cluster,
* reserved sectors, FATs, directory entries, sectors (low byte first; tools/mkdosimg.py makes the images)
* (after the table: the media byte and the sectors of a FAT, for the BPB of 2.0)
fmts     fcb   $00,$02,$80,$00,$00,$02,$01,$01,$00,$02,$40,$00,$40,$01,$FE,$01,$00      160 KB
         fcb   $00,$05,$00,$00,$00,$02,$02,$01,$00,$02,$70,$00,$80,$02,$FF,$01,$00      320 KB
         fcb   $00,$80,$00,$00,$00,$02,$08,$01,$00,$02,$00,$02,$00,$40,$F8,$06,$00      8 MB
defb2    fcc   "bios2.bin"
         fcb   C$CR
msgusage fcc   "usage: dos [-k=kernel] -a=image [-b=image -c=image -d=image] [-p=printer -i=auxin -o=auxout] [-v=2 -s=bios2.bin]"
         fcb   C$CR
msgnosub fcc   "dos: the sub CPU is not an 8088"
         fcb   C$CR
msgfile  fcc   "dos: cannot open the kernel or an image file"
         fcb   C$CR
msgbig   fcc   "dos: the kernel is too big"
         fcb   C$CR
msgsize  fcc   "dos: an image must be 160 KB, 320 KB or 8 MB"
         fcb   C$CR

* ------------------------------------------------------------------
start    stx   argp,u
         clr   done,u
         clr   rawf,u
         clr   kbv,u
         lda   >XID
         cmpa  #2
         lbne  nosub
         clr   xpath,u               the driver (xlink.asm): memory from OS-9, interrupt for the doorbell
         leax  x0name,pcr
         lda   #UPDAT.
         os9   I$Open
         bcs   st1
         sta   xpath,u
st1      clr   >XCTL                 hold the 8088 in reset
         leax  icpt,pcr              signals (^E): put the terminal back
         os9   F$Icpt
         clr   kname,u               the options: -k=kernel -a=image -b= -c= -d=
         clr   kname+1,u
         lda   #1
         sta   ver,u
         ldd   #RQLIN
         std   rqad,u
         ldd   #0
         std   bnm,u
         clr   ppath,u
         clr   ipath,u
         clr   opath,u
         ldd   #0
         std   pnm,u
         std   inm,u
         std   onm,u
         leax  dname,u
         ldb   #8
op0      clr   ,x+
         decb
         bne   op0
         ldx   argp,u
op1      lbsr  skipsp
         cmpa  #C$CR
         beq   opend
         cmpa  #'-'
         lbne  usage
         leax  1,x
         lda   ,x+                   the option letter
         anda  #$DF
         ldb   ,x+
         cmpb  #'='
         lbne  usage
         cmpa  #'K'
         bne   op2
         stx   kname,u
         bra   op4
op2      cmpa  #'P'
         bne   op2a
         stx   pnm,u
         bra   op4
op2a     cmpa  #'I'
         bne   op2b
         stx   inm,u
         bra   op4
op2b     cmpa  #'O'
         bne   op2c
         stx   onm,u
         bra   op4
op2c     cmpa  #'S'
         bne   op2d
         stx   bnm,u
         bra   op4
op2d     cmpa  #'V'
         bne   op2e
         lda   ,x
         suba  #'0'
         cmpa  #2
         lbhi  usage
         lbeq  op2v
         lda   #1
op2v     sta   ver,u
         bra   op4
op2e     suba  #'A'
         lbmi  usage
         cmpa  #3
         lbhi  usage
         lsla
         leay  dname,u
         stx   a,y
op4      lda   ,x+                   skip the name
         cmpa  #' '
         beq   op5
         cmpa  #C$CR
         bne   op4
op5      leax  -1,x
         lbra  op1
opend    ldd   dname,u               drive A: is needed
         lbeq  usage
         ldd   kname,u
         bne   op6
         leax  defk,pcr
         stx   kname,u
op6      ldx   kname,u
         lda   #READ.
         os9   I$Open
         lbcs  nofile
         sta   path,u
         lbsr  openaux
* the images of the drives: open them, find the format from the size, make the INITTAB
         clr   nimg,u
dv1      ldb   nimg,u
         cmpb  #4
         lbeq  dv9
         aslb
         leax  dname,u
         ldx   b,x
         lbeq  dv9
         lda   #UPDAT.
         os9   I$Open
         lbcs  nofile
         ldb   nimg,u
         leay  dpath,u
         sta   b,y
         pshs  u                     the size of the file comes back in X:U
         ldb   #SS.Size
         os9   I$GetStt
         pshs  x,u
         ldu   4,s
         ldd   ,s
         std   szh,u
         ldd   2,s
         std   szl,u
         leas  6,s
         leay  fmts,pcr
         ldb   #3
fm1      ldd   ,y
         cmpd  szh,u
         bne   fm2
         ldd   2,y
         cmpd  szl,u
         beq   fm3
fm2      leay  17,y
         decb
         bne   fm1
         lbra  badsize
fm3      leay  4,y                   the disk parameter table: 10 bytes at itab + 13 + 10 * drive
         sty   tmpy,u
         ldb   nimg,u
         lda   #10
         mul
         leax  itab+13,u
         leax  d,x
         ldb   #10
fm4      lda   ,y+
         sta   ,x+
         decb
         bne   fm4
         ldb   nimg,u                the BPB (13 bytes): the table and the media byte and the sectors of a FAT
         lda   #13
         mul
         leax  bpbs,u
         leax  d,x
         pshs  y
         ldy   tmpy,u
         ldb   #10
fm5      lda   ,y+
         sta   ,x+
         decb
         bne   fm5
         puls  y
         ldb   #3
fm6      lda   ,y+
         sta   ,x+
         decb
         bne   fm6
         inc   nimg,u
         lbra  dv1
dv9      lda   nimg,u
         sta   itab,u
         leax  itab+1,u              the entries: unit, the offset of the table in the BIOS segment
         ldy   #INITBIOS+13
         clr   tmp8,u
dv10     lda   tmp8,u
         sta   ,x+
         tfr   y,d
         exg   a,b                   low byte first, for the 8088
         std   ,x++
         leay  10,y
         inc   tmp8,u
         lda   tmp8,u
         cmpa  nimg,u
         bne   dv10
* ---------------------------------------------------------------- load: BIOS, kernel, memory size, reset vector
         lda   ver,u
         cmpa  #2
         lbeq  load2
         clr   lin,u
         ldd   #BIOSLIN
         std   lin+1,u
         leax  bios,pcr
         ldy   #biosn
         lbsr  wrsub
         ldd   #LBLIN
         lbsr  setlin16
         leax  lbdata,pcr
         ldy   #2
         lbsr  wrsub
         ldd   #LBLIN+4
         lbsr  setlin16
         ldb   nimg,u               the INITTAB: 13 bytes and a table of 10 bytes for each drive
         lda   #10
         mul
         addd  #13
         tfr   d,y
         leax  itab,u
         lbsr  wrsub
         ldd   #DOSLIN
         lbsr  setlin16
         lbra  ld0
* 2.0: the BIOS image (bios2.asm with SYSINIT) from the file, the boot data (memory size, units, BPBs), the kernel after the image
load2    ldd   #RQLIN2
         std   rqad,u
         ldx   bnm,u
         bne   l2a
         leax  defb2,pcr
l2a      lda   #READ.
         os9   I$Open
         lbcs  nofile
         sta   bpath,u
         clr   lin,u
         ldd   #BIOSLIN
         std   lin+1,u
         ldd   #0
         std   blen,u
l2b      lda   bpath,u
         leax  iobuf,u
         ldy   #256
         os9   I$Read
         bcs   l2c
         pshs  y
         leax  iobuf,u
         lbsr  wrsub
         puls  y
         tfr   y,d
         addd  blen,u
         std   blen,u
         bra   l2b
l2c      cmpb  #E$EOF
         lbne  nofile
         lda   bpath,u
         os9   I$Close
         ldd   #LBLIN2
         lbsr  setlin16
         leax  lbdata,pcr
         ldy   #2
         lbsr  wrsub
         leax  nimg,u
         ldy   #1
         lbsr  wrsub
         ldd   #LBLIN2+4
         lbsr  setlin16
         ldb   nimg,u
         lda   #13
         mul
         tfr   d,y
         leax  bpbs,u
         lbsr  wrsub
         ldd   blen,u                the kernel: the next paragraph after the image
         addd  #15
         andb  #$F0
         addd  #BIOSLIN
         lbsr  setlin16
ld0
ld1      lda   path,u
         leax  iobuf,u
         ldy   #256
         os9   I$Read
         bcs   ld8
         pshs  y
         leax  iobuf,u
         lbsr  wrsub
         puls  y
         lda   lin,u                 the kernel must stay below the memory size
         bne   toobig
         bra   ld1
ld8      cmpb  #E$EOF
         lbne  nofile
         lda   path,u
         os9   I$Close
         lda   #$0F                  the reset vector
         sta   lin,u
         ldd   #$FFF0
         std   lin+1,u
         leax  rstvec,pcr
         ldy   #5
         lbsr  wrsub
         clr   rp+16,u               the done flag of the request block
         ldd   rqad,u
         addd  #16
         lbsr  setlin16
         leax  rp+16,u
         ldy   #1
         lbsr  wrsub
         lbsr  rawon
         lda   >XSTAT                a doorbell left by the previous program would look like a request
         sta   >XSTAT
         lda   #1
         sta   >XCTL                 go
* ---------------------------------------------------------------- main loop: serve the BIOS calls
serve    lbsr  waitrq
         lbsr  getrq
         lbsr  dispatch
         lbsr  putrq
         tst   done,u
         beq   serve
         clr   >XCTL                 stop the 8088
         lbsr  rawoff
         clrb
         os9   F$Exit

nosub    leax  msgnosub,pcr
         bra   say
usage    leax  msgusage,pcr
         bra   say
nofile   leax  msgfile,pcr
         bra   say
badsize  leax  msgsize,pcr
         bra   say
toobig   leax  msgbig,pcr
say      lbsr  rawoff
         lda   #2
         ldy   #120
         os9   I$WritLn
         ldb   #1
         os9   F$Exit

* a signal (^E, kill): put the terminal back and leave; the wake-up signal is no reason to leave
icpt     cmpb  #S$Wake
         beq   ic9
         lbsr  rawoff
         clr   >XCTL
         clrb
         os9   F$Exit
ic9      rti

* the files or devices of the printer and the aux port: the output is appended (a file is created if it is not there)
openaux  ldx   pnm,u
         beq   oa1
         lbsr  openapp
         lbcs  nofile
         sta   ppath,u
oa1      ldx   onm,u
         beq   oa2
         lbsr  openapp
         lbcs  nofile
         sta   opath,u
oa2      ldx   inm,u
         beq   oa3
         lda   #READ.
         os9   I$Open
         lbcs  nofile
         sta   ipath,u
oa3      rts

openapp  lda   #WRITE.
         os9   I$Open
         bcc   oap1
         lda   #WRITE.
         ldb   #$0B                  read, write, public read
         os9   I$Create
         rts
oap1     pshs  a,u
         ldb   #SS.Size
         os9   I$GetStt              the size comes back in X:U
         bcs   oap2
         lda   ,s
         os9   I$Seek                to the end (a device has no size: nothing to do)
oap2     puls  a,u
         andcc #$FE
         rts

skipsp   lda   ,x+
         cmpa  #' '
         beq   skipsp
         leax  -1,x
         rts

* ------------------------------------------------------------------
* wait for the doorbell of the 8088 and acknowledge it
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

setlin16 clr   lin,u
         std   lin+1,u
         rts

* read the request (12 bytes) and write the reply (17 bytes: the done flag is the last)
getrq    clr   lin,u
         ldd   rqad,u
         std   lin+1,u
         leax  rq,u
         ldy   #12
         lbra  rdsub

putrq    clr   lin,u
         ldd   rqad,u
         addd  #16
         std   lin+1,u
         lda   #1
         sta   rp+16,u
         leax  rp,u
         ldy   #17
         lbra  wrsub

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
* the BIOS calls.  The reply starts as zeros (CX = the CX of the request: the sectors not done)
dispatch leax  rp,u
         ldb   #17
dp0      clr   ,x+
         decb
         bne   dp0
         lda   rq+6,u
         sta   rp+4,u
         lda   rq+7,u
         sta   rp+5,u
         lda   rq,u
         cmpa  #1
         beq   f_stat
         cmpa  #2
         beq   f_inp
         cmpa  #3
         beq   f_outp
         cmpa  #4
         lbeq  f_prt
         cmpa  #5
         lbeq  f_auxi
         cmpa  #6
         lbeq  f_auxo
         cmpa  #7
         lbeq  f_disk
         cmpa  #8
         lbeq  f_disk
         cmpa  #12
         lbeq  f_time
         cmpa  #13
         lbeq  f_flush
         rts

* 1: console status, AH = 1 and AL = the key if there is one (the key stays for INP)
f_stat   tst   kbv,u
         bne   fs2
         lbsr  keyrdy
         bcs   fs9
fs2      lda   kbc,u
         sta   rp,u
         lda   #1
         sta   rp+1,u
fs9      rts

* 2: console input (waits)
f_inp    tst   kbv,u
         bne   fi2
fi1      lda   #0
         leax  iobuf,u
         ldy   #1
         os9   I$Read
         bcs   fi3
         lda   iobuf,u
         cmpa  #EXITKEY
         bne   fi4
fi3      inc   done,u                the exit key (or the end of the input): leave
         rts
fi2      clr   kbv,u
         lda   kbc,u
fi4      sta   rp,u
         rts

* 3: console output, AL
f_outp   lda   rq+1,u
         sta   iobuf,u
         lda   #1
         leax  iobuf,u
         ldy   #1
         os9   I$Write
         rts

* 4: printer, 6: aux output: the character AL to the file or device (nothing without the option)
f_prt    lda   ppath,u
         bra   wr1
f_auxo   lda   opath,u
wr1      beq   wr9
         pshs  a
         lda   rq+1,u
         sta   iobuf,u
         puls  a
         leax  iobuf,u
         ldy   #1
         os9   I$Write
wr9      rts

* 5: aux input: the next byte of the file, 1Ah (end of file) at its end or without the option
f_auxi   lda   ipath,u
         beq   ai8
         leax  iobuf,u
         ldy   #1
         os9   I$Read
         bcs   ai8
         lda   iobuf,u
         sta   rp,u
         rts
ai8      lda   #$1A
         sta   rp,u
         rts

* 7, 8: disk read / write.  unit AL, transfer address DS:BX, CX sectors, record number DX.  A transfer reads or writes
* the sectors of the image one by one; the reply: CX = the sectors not done, on an error flag 1 and AL = the error code
* (2 not ready, 8 sector not found, 12 other)
f_disk   lda   rq+1,u
         cmpa  #4
         lbhs  fd_nr
         leax  dpath,u
         lda   a,x
         lbeq  fd_nr
         sta   dsp,u
         lbsr  dslin                 lin = DS * 16 + BX
         lda   lin+2,u
         adda  rq+4,u
         sta   lin+2,u
         lda   lin+1,u
         adca  rq+5,u
         sta   lin+1,u
         lda   lin,u
         adca  #0
         anda  #$0F
         sta   lin,u
         lda   rq+9,u                the offset in the image: record * 512 (X = record / 128, U = record mod 128 * 512)
         ldb   rq+8,u
         lsra
         rorb
         lsra
         rorb
         lsra
         rorb
         lsra
         rorb
         lsra
         rorb
         lsra
         rorb
         lsra
         rorb
         tfr   d,x
         lda   rq+8,u
         anda  #$7F
         lsla
         sta   seeklo,u
         clr   seeklo+1,u
         lda   dsp,u
         pshs  u
         ldu   seeklo,u
         os9   I$Seek
         puls  u
         bcs   fd_err
         ldd   rq+6,u
         exg   a,b                   CX is low byte first
         std   dcnt,u
fd1      ldd   dcnt,u
         beq   fd9
         lda   rq,u
         cmpa  #8
         beq   fd_w
         lda   dsp,u
         leax  sbuf,u
         ldy   #512
         os9   I$Read
         bcs   fd_err
         cmpy  #512
         bne   fd_nf
         leax  sbuf,u
         ldy   #512
         lbsr  wrsub
         bra   fd2
fd_w     leax  sbuf,u
         ldy   #512
         lbsr  rdsub
         lda   dsp,u
         leax  sbuf,u
         ldy   #512
         os9   I$Write
         bcs   fd_err
fd2      ldd   dcnt,u
         subd  #1
         std   dcnt,u
         stb   rp+4,u                the sectors left
         sta   rp+5,u
         bra   fd1
fd9      rts
fd_nr    lda   #2
         bra   fd_e
fd_nf    lda   #8
         bra   fd_e
fd_err   lda   #12
fd_e     sta   rp,u
         lda   #1
         sta   rp+8,u
         ldd   dcnt,u                the sectors left (the whole transfer if the seek failed)
         stb   rp+4,u
         sta   rp+5,u
         rts

* lin = DS * 16 (DS = the request, low byte first)
dslin    lda   rq+11,u
         lsra
         lsra
         lsra
         lsra
         sta   lin,u
         lda   rq+11,u
         lsla
         lsla
         lsla
         lsla
         sta   lin+1,u
         lda   rq+10,u
         lsra
         lsra
         lsra
         lsra
         ora   lin+1,u
         sta   lin+1,u
         lda   rq+10,u
         lsla
         lsla
         lsla
         lsla
         sta   lin+2,u
         rts

* 12: the time of OS-9 (year - 1900, month, day, hour, minute, second) for the BIOS to compute the days
f_time   leax  iobuf,u
         os9   F$Time
         ldb   #6
         leay  rp+10,u
         leax  iobuf,u
ft1      lda   ,x+
         sta   ,y+
         decb
         bne   ft1
         rts

* 13: throw the typed-ahead keys away
f_flush  clr   kbv,u
fl1      lbsr  keyrdy
         bcc   fl2
         rts
fl2      clr   kbv,u
         bra   fl1

* ------------------------------------------------------------------
* a key from the keyboard if there is one: C clear and kbv = 1, kbc = the key.  The exit key sets done.
keyrdy   lda   #0
         ldb   #SS.Ready
         os9   I$GetStt
         bcs   kr8
         lda   #0
         leax  iobuf,u
         ldy   #1
         os9   I$Read
         bcs   kr8
         lda   iobuf,u
         cmpa  #EXITKEY
         beq   kr7
         sta   kbc,u
         lda   #1
         sta   kbv,u
         andcc #$FE
         rts
kr7      inc   done,u
kr8      orcc  #1
         rts

* DOS echoes, edits and passes the control characters itself: the terminal must not echo, must not translate (upper case,
* line feed after CR) and must not take ^C ^E as signals (offsets in the options of the path: PD.UPC 1, PD.EKO 4,
* PD.ALF 5, PD.PAU 7, PD.EOF 12, PD.PSC 15, PD.INT 16, PD.QUT 17)
rawon    tst   rawf,u
         bne   rw9
         lda   #0
         ldb   #SS.Opt
         leax  oldopt,u
         os9   I$GetStt
         bcs   rw9
         leax  oldopt,u
         leay  iobuf,u
         ldb   #32
rw1      lda   ,x+
         sta   ,y+
         decb
         bne   rw1
         lda   iobuf,u               PD.DTP: only a terminal (SCF)
         bne   rw9
         clr   iobuf+1,u
         clr   iobuf+4,u
         clr   iobuf+5,u
         clr   iobuf+7,u
         clr   iobuf+12,u
         clr   iobuf+15,u
         clr   iobuf+16,u
         clr   iobuf+17,u
         lda   #0
         ldb   #SS.Opt
         leax  iobuf,u
         os9   I$SetStt
         bcs   rw9
         lda   #1
         sta   rawf,u
rw9      rts
rawoff   tst   rawf,u
         beq   rw8
         clr   rawf,u
         lda   #0
         ldb   #SS.Opt
         leax  oldopt,u
         os9   I$SetStt
rw8      rts

         emod
eom      equ   *
         end
