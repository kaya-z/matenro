* SPDX-License-Identifier: MIT
********************************************************************
* dos - run MS-DOS 1.25 on the 8088 of 摩天楼 (Matenro) from OS-9 Level 2
*
*   dos [-k=kernel] -a=image [-b=image] [-c=image] [-d=image] [-p=printer] [-i=auxin] [-o=auxout]
*
*   -k=file   the MS-DOS kernel (default msdos.sys in the current data directory)
*   -a=file   the disk image of drive A: (a FAT12 image: tools/mkdosimg.py; COMMAND.COM must be on it); -b -c -d: B: C: D:
*             the size of the file decides the format: 160 KB, 320 KB, 360 KB (IBM formats) or 8 MB (hard disk)
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
* The user state program reaches the cross link in the I/O page ($FFCA-$FFCE of the Level 2 machine) and the
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
tnm      rmb   2                 -t=: the work image of the run mode (default dostmp.img in the current directory)
cmdp     rmb   2                 run mode: the command line (a program and its arguments), 0 = none
scrp     rmb   2                 run mode: the keys typed ahead for DOS (0 = none)
quiet    rmb   1                 run mode: the console output of DOS is dropped until HOSTIN has started
hdir     rmb   1                 run mode: the OS-9 directory that HOSTIN is reading
hfile    rmb   1                 run mode: the OS-9 file that HOSTIN / HOSTOUT transfer
hp       rmb   1
hcnt     rmb   2
hname    rmb   11                the DOS name (FCB form) that is wanted
dirent   rmb   32
pname    rmb   40
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
         fcb   $00,$05,$A0,$00,$00,$02,$02,$01,$00,$02,$70,$00,$D0,$02,$FD,$02,$00      360 KB (9 sectors per track)
         fcb   $00,$80,$00,$00,$00,$02,$08,$01,$00,$02,$00,$02,$00,$40,$F8,$06,$00      8 MB
defb2    fcc   "bios2.bin"
         fcb   C$CR
msgusage fcc   "usage: dos [-v=2] [-a=image ...] [program arguments]   (see docs/MANUAL.md 6.8)"
         fcb   C$CR
msgnosub fcc   "dos: the sub CPU is not an 8088"
         fcb   C$CR
msgfile  fcc   "dos: cannot open the kernel or an image file"
         fcb   C$CR
msgbig   fcc   "dos: the kernel is too big"
         fcb   C$CR
msgsize  fcc   "dos: an image must be 160 KB, 320 KB, 360 KB or 8 MB"
         fcb   C$CR

* ------------------------------------------------------------------
start    stx   argp,u
         clr   done,u
         ldd   #0
         std   tnm,u
         std   cmdp,u
         std   scrp,u
         clr   quiet,u
         clr   hdir,u
         clr   hfile,u
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
         lbeq  opend
         cmpa  #'-'
         lbne  runarg
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
op2e     cmpa  #'T'
         bne   op2f
         stx   tnm,u
         bra   op4
op2f     suba  #'A'
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
runarg   stx   cmdp,u                run mode: the rest of the line is the command
opend    ldd   dname,u               drive A: is needed (run mode: the image dosrun.img)
         bne   opd1
         ldd   cmdp,u
         lbeq  usage
         leax  defrun,pcr
         stx   dname,u
opd1     ldd   cmdp,u
         beq   opd2
         lbsr  mktemp                run mode: work on a copy of the image
opd2
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
         ldb   #4
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
         lbne  toobig
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
         ldd   cmdp,u                run mode: DOS gets its first keys from here (the dates, HOSTIN, RUNJOB)
         beq   nr1
         leax  scrtxt,pcr
         stx   scrp,u
         lda   #1
         sta   quiet,u
nr1      lbsr  rawon
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
         ldd   cmdp,u
         beq   sv9
         lbsr  hclose                run mode: the work image goes away
         lda   dpath,u
         os9   I$Close
         ldx   tnm,u
         lda   #UPDAT.
         os9   I$Delete
sv9      clrb
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
         lbeq  f_outp
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
         cmpa  #20
         lbeq  f_hdir
         cmpa  #21
         lbeq  f_hopen
         cmpa  #22
         lbeq  f_hread
         cmpa  #23
         lbeq  f_hwrite
         cmpa  #24
         lbeq  f_hclose
         cmpa  #25
         lbeq  f_hdone
         cmpa  #26
         lbeq  f_hcmd
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
         lbsr  scrkey                run mode: the keys typed ahead
         bcc   fi2
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
f_outp   tst   quiet,u
         bne   fo9
         lda   rq+1,u
         sta   iobuf,u
         lda   #1
         leax  iobuf,u
         ldy   #1
         os9   I$Write
fo9      rts

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
keyrdy   lbsr  scrkey
         bcc   kr0
         lda   #0
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
kr0      rts

* run mode: the next typed-ahead key into kbc / kbv (C clear), or C set if there is none
scrkey   ldx   scrp,u
         beq   sk8
         lda   ,x
         beq   sk8
         leax  1,x
         stx   scrp,u
         sta   kbc,u
         lda   #1
         sta   kbv,u
         andcc #$FE
         rts
sk8      orcc  #1
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


* ------------------------------------------------------------------
* run mode:  dos [options] program arguments
* DOS boots from a copy of the image (dosrun.img: COMMAND.COM, HOSTIN.COM, HOSTOUT.COM).
* The first keys come from this program (scrtxt: the answers to the date and time, HOSTIN,
* RUNJOB).
* HOSTIN asks for the command line (26), copies the files of the current OS-9 directory to the
* disk of DOS (20 - 24) and writes RUNJOB.BAT (the command line, then HOSTOUT); HOSTOUT copies
* the files of the disk back (21 - 24) and ends (25).

* a copy of the image dname[0] in the file dostmp.img (it becomes drive A:)
mktemp   ldx   tnm,u
         bne   mt0
         leax  tmpnm,pcr
         stx   tnm,u
mt0      ldx   dname,u
         lda   #READ.
         os9   I$Open
         lbcs  nofile
         sta   hp,u
         ldx   tnm,u
         lda   #UPDAT.
         os9   I$Delete              (a left-over copy)
         ldx   tnm,u
         lda   #UPDAT.
         ldb   #$0B
         os9   I$Create
         lbcs  nofile
         sta   hfile,u
mt1      lda   hp,u
         leax  sbuf,u
         ldy   #512
         os9   I$Read
         bcs   mt2
         lda   hfile,u
         leax  sbuf,u
         ldy   #512
         os9   I$Write
         lbcs  nofile
         bra   mt1
mt2      cmpb  #E$EOF
         lbne  nofile
         lda   hp,u
         os9   I$Close
         lda   hfile,u
         os9   I$Close
         clr   hfile,u
         ldx   tnm,u
         stx   dname,u
         rts

* close what the host calls have open
hclose   lda   hfile,u
         beq   hc1
         os9   I$Close
         clr   hfile,u
hc1      lda   hdir,u
         beq   hc2
         os9   I$Close
         clr   hdir,u
hc2      rts

* lin = DS * 16 + BX
dsbx     lbsr  dslin
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
         rts

* 26: the command line (up to the CR) to DS:BX
f_hcmd   clr   quiet,u               from here on the console output of DOS is shown
         ldx   cmdp,u
         leay  sbuf,u
         ldb   #127
hm1      lda   ,x+
         sta   ,y+
         cmpa  #C$CR
         beq   hm2
         decb
         bne   hm1
         lda   #C$CR
         sta   ,y+
hm2      leax  sbuf,u
         pshs  x
         tfr   y,d
         subd  ,s++
         pshs  d
         lbsr  dsbx
         puls  y
         leax  sbuf,u
         lbra  wrsub

* 20: the files of the current directory.  CX = 0: start;  CX = 1: the next one: DS:BX gets
* 11 bytes (the name in FCB form,
* upper case) and 4 bytes (the size, low byte first).  AL = 1: no more.  Directories and
* other names DOS cannot hold are skipped.
f_hdir   tst   rq+6,u
         bne   hd1
         lda   hdir,u
         beq   hd0
         os9   I$Close
         clr   hdir,u
hd0      lda   #DIR.+READ.
         leax  dotname,pcr
         os9   I$Open
         bcs   hd_end
         sta   hdir,u
         rts
hd1      lda   hdir,u
         beq   hd_end
hd2      lda   hdir,u
         leax  dirent,u
         ldy   #32
         os9   I$Read
         bcs   hd_close
         cmpy  #32
         bne   hd_close
         lda   dirent,u
         beq   hd2
         lbsr  dir2dos
         bcs   hd2
         lbsr  isres
         bcs   hd2
         lda   #READ.
         leax  pname,u
         os9   I$Open
         bcs   hd2                   a directory
         sta   hp,u
         pshs  u
         ldb   #SS.Size
         os9   I$GetStt
         tfr   u,d
         puls  u
         stb   iobuf+11,u
         sta   iobuf+12,u
         tfr   x,d
         stb   iobuf+13,u
         sta   iobuf+14,u
         lda   hp,u
         os9   I$Close
         lbsr  dsbx
         leax  iobuf,u
         ldy   #15
         lbra  wrsub
hd_close lda   hdir,u
         os9   I$Close
         clr   hdir,u
hd_end   lda   #1
         sta   rp,u
         rts

* is iobuf[0..10] a name that belongs to this program (the work image)?  C set: yes
isres    leax  iobuf,u
         leay  resnm,pcr
         ldb   #11
ir1      lda   ,x+
         cmpa  ,y+
         bne   ir8
         decb
         bne   ir1
         orcc  #1
         rts
ir8      andcc #$FE
         rts

* 21: open a file. DS:BX = the name (11 bytes, FCB form), DX = 0 read, 1 create (an old
* file is replaced).  AL = 1: failed.
f_hopen  lbsr  dsbx
         leax  hname,u
         ldy   #11
         lbsr  rdsub
         lda   hfile,u
         beq   ho0
         os9   I$Close
         clr   hfile,u
ho0      lbsr  findname              C clear: pname = the OS-9 name of that file
         tst   rq+8,u
         bne   ho_w
         bcs   ho_fail
         lda   #READ.
         leax  pname,u
         os9   I$Open
         bcs   ho_fail
         sta   hfile,u
         rts
ho_w     bcs   ho_new
         lda   #UPDAT.
         leax  pname,u
         os9   I$Delete
         bra   ho_mk
ho_new   lbsr  mkoname
ho_mk    lda   #WRITE.
         ldb   #$0B
         leax  pname,u
         os9   I$Create
         bcs   ho_fail
         sta   hfile,u
         rts
ho_fail  lda   #1
         sta   rp,u
         rts

* the file of the current directory whose DOS name is hname.  C clear: found, pname = its
* OS-9 name
findname lda   #DIR.+READ.
         leax  dotname,pcr
         os9   I$Open
         bcs   fn8
         sta   hp,u
fn1      lda   hp,u
         leax  dirent,u
         ldy   #32
         os9   I$Read
         bcs   fn7
         cmpy  #32
         bne   fn7
         lda   dirent,u
         beq   fn1
         lbsr  dir2dos
         bcs   fn1
         leax  iobuf,u
         leay  hname,u
         ldb   #11
fn2      lda   ,x+
         cmpa  ,y+
         bne   fn1
         decb
         bne   fn2
         lda   hp,u
         os9   I$Close
         andcc #$FE
         rts
fn7      lda   hp,u
         os9   I$Close
fn8      orcc  #1
         rts

* a new OS-9 name (lower case) from hname into pname
mkoname  leax  hname,u
         leay  pname,u
         ldb   #8
mo1      lda   ,x+
         cmpa  #' '
         beq   mo2
         lbsr  lowcase
         sta   ,y+
         decb
         bne   mo1
mo2      leax  hname+8,u
         lda   ,x
         cmpa  #' '
         beq   mo9
         lda   #'.'
         sta   ,y+
         ldb   #3
mo3      lda   ,x+
         cmpa  #' '
         beq   mo9
         lbsr  lowcase
         sta   ,y+
         decb
         bne   mo3
mo9      lda   #C$CR
         sta   ,y
         rts

lowcase  cmpa  #'A'
         blo   lc9
         cmpa  #'Z'
         bhi   lc9
         adda  #$20
lc9      rts

* 22: read: CX bytes (up to 512) from the file to DS:BX; the reply CX = the bytes read (0 =
* the end)
f_hread  lda   rq+7,u
         ldb   rq+6,u
         cmpd  #512
         bls   hr1
         ldd   #512
hr1      tfr   d,y
         lda   hfile,u
         beq   hr_e
         leax  sbuf,u
         os9   I$Read
         bcs   hr_e
         sty   hcnt,u
         lbsr  dsbx
         leax  sbuf,u
         ldy   hcnt,u
         lbsr  wrsub
         ldd   hcnt,u
         stb   rp+4,u
         sta   rp+5,u
         rts
hr_e     clr   rp+4,u
         clr   rp+5,u
         rts

* 23: write: CX bytes (up to 512) from DS:BX.  AL = 1: failed
f_hwrite lda   rq+7,u
         ldb   rq+6,u
         cmpd  #512
         bls   hw1
         ldd   #512
hw1      std   hcnt,u
         lbsr  dsbx
         leax  sbuf,u
         ldy   hcnt,u
         lbsr  rdsub
         lda   hfile,u
         beq   hw_e
         leax  sbuf,u
         ldy   hcnt,u
         os9   I$Write
         bcs   hw_e
         rts
hw_e     lda   #1
         sta   rp,u
         rts

* 24: close the file
f_hclose lda   hfile,u
         beq   hcl9
         os9   I$Close
         clr   hfile,u
hcl9     rts

* 25: HOSTOUT is done: leave
f_hdone  inc   done,u
         rts

* directory entry (dirent) -> pname (OS-9 name, CR terminated) and iobuf[0..10] (the DOS
* name: 8.3, upper case, blank padded).
* C set: a name that DOS cannot hold, ".", ".."
dir2dos  leax  dirent,u
         leay  pname,u
         ldb   #29
dd1      lda   ,x+
         pshs  a
         anda  #$7F
         sta   ,y+
         puls  a
         tsta
         bmi   dd2
         decb
         bne   dd1
dd2      lda   #C$CR
         sta   ,y
         leax  iobuf,u
         ldb   #11
         lda   #' '
dd3      sta   ,x+
         decb
         bne   dd3
         leax  pname,u
         lda   ,x
         cmpa  #'.'
         beq   ddbad
         leay  iobuf,u
         ldb   #8
dd4      lda   ,x+
         cmpa  #C$CR
         beq   ddgood
         cmpa  #'.'
         beq   dd5
         lbsr  upcase
         tstb
         beq   ddbad
         sta   ,y+
         decb
         bra   dd4
dd5      leay  iobuf+8,u
         ldb   #3
dd6      lda   ,x+
         cmpa  #C$CR
         beq   ddgood
         cmpa  #'.'
         beq   ddbad
         lbsr  upcase
         tstb
         beq   ddbad
         sta   ,y+
         decb
         bra   dd6
ddgood   andcc #$FE
         rts
ddbad    orcc  #1
         rts

upcase   cmpa  #'a'
         blo   up9
         cmpa  #'z'
         bhi   up9
         suba  #$20
up9      rts

defrun   fcc   "dosrun.img"
         fcb   C$CR
tmpnm    fcc   "dostmp.img"
         fcb   C$CR
resnm    fcc   "DOSTMP  IMG"
dotname  fcc   "."
         fcb   C$CR
scrtxt   fcb   13,13
         fcc   "HOSTIN"
         fcb   13
         fcc   "RUNJOB"
         fcb   13,0

         emod
eom      equ   *
         end
