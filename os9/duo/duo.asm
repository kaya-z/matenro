* SPDX-License-Identifier: MIT
********************************************************************
* duo - a Mandelbrot picture drawn by both CPUs of the Matenro machine at the same time
*
*   duo [-1] [-z] [-n] [-i]
*
*   The 6809 and the Z80 take the 25 rows of the picture one by one from a common counter: when the Z80 has
*   finished a row it gets the next one, the 6809 computes a row itself in the meantime.  The Z80 program
*   (duoz80.asm) is part of this module; it runs the picture rows in the shared RAM, the 6809 collects them
*   through the window of the cross link.  Both use the same fixed point arithmetic (8 fraction bits), so the picture does
*   not depend on who computed a row.  The picture is written after the computation, the rows of the Z80 in cyan, the rows
*   of the 6809 in yellow, then the number of rows of each CPU and the time of the computation.
*
*   -1   the 6809 only (the time to compare)      -z   the Z80 only      -n   no colours (plain text)
*   -i   also write the number of doorbell interrupts that the xlink driver (/x0) has serviced
*
* The doorbell of the Z80 interrupts the Z80 (it halts between two rows); the doorbell of the Z80 wakes the 6809 through the driver
* /x0 (SS.XWait) when it is loaded; without the driver the 6809 sleeps one tick at a time and looks at the doorbell flag.
*
* The time comes from the microsecond counter XE_US of the cross link (see etime).
* Credits: the module layout follows the sample commands of the NitrOS-9 project (GPL v2), as in os9/xrun.asm.  The code is original.
********************************************************************

         nam   duo
         ttl   Mandelbrot on both CPUs

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
XE_MI    equ   $08
XE_MD    equ   $09
XE_WA    equ   $0A
XE_WD    equ   $0D
XE_US    equ   $14
SS.XInfo equ   $B0
SS.XWait equ   $B1
NROWS    equ   25
NCOLS    equ   79

         mod   eom,name,tylg,atrv,start,size

         org   0
mode     rmb   1                 bit 0: the 6809 works, bit 1: the Z80 works
color    rmb   1
xpath    rmb   1                 path of /x0 (the xlink driver), 0 = not loaded
showi    rmb   1                 -i
irqs     rmb   2
next     rmb   1                 the next row nobody has taken
cur      rmb   1
zrow     rmb   1                 the row of the Z80
zbusy    rmb   1
n68      rmb   1
nz80     rmb   1
blk      rmb   1
xc       rmb   1
it       rmb   1
sg       rmb   1
dst      rmb   2
ca       rmb   2
cb       rmb   2
aa       rmb   2
bb       rmb   2
a2       rmb   2
b2       rmb   2
pp       rmb   2
qq       rmb   2
acc      rmb   2
t0       rmb   4
t1       rmb   4
num      rmb   4
rem      rmb   2
dig      rmb   10
owner    rmb   NROWS
out      rmb   120
rows     rmb   NROWS*NCOLS
         rmb   250               stack
size     equ   .

name     fcs   /duo/
         fcb   edition

msgnosub fcc   "duo: no Z80 sub CPU"
         fcb   C$CR
msgtmo   fcc   "duo: the Z80 did not answer, XCTL XSTAT row: "
         fcb   0
msgusage fcc   "usage: duo [-1] [-z] [-n] [-i]"
         fcb   C$CR
msg68    fcc   "6809: "
         fcb   0
msgz     fcc   " rows   Z80: "
         fcb   0
msgrows  fcc   " rows   "
         fcb   0
msgs     fcc   " s"
         fcb   0
msgi     fcc   "doorbell interrupts: "
         fcb   0
x0name   fcc   "/x0"
         fcb   C$CR

         use   duoz80.inc

* ------------------------------------------------------------------
start    lda   #3
         sta   mode,u
         lda   #1
         sta   color,u
         clr   showi,u
         clr   next,u
         clr   zbusy,u
         clr   n68,u
         clr   nz80,u
opt      lda   ,x+
         cmpa  #' '
         beq   opt
         cmpa  #'-'
         bne   optend
         lda   ,x+
         cmpa  #'1'
         bne   o2
         lda   #1
         sta   mode,u
         bra   opt
o2       cmpa  #'z'
         bne   o3
         lda   #2
         sta   mode,u
         bra   opt
o3       cmpa  #'n'
         bne   o4
         clr   color,u
         bra   opt
o4       cmpa  #'i'
         lbne  usage
         lda   #1
         sta   showi,u
         bra   opt
optend   cmpa  #C$CR
         lbne  usage
         clr   xpath,u             the driver: the doorbell wakes the process
         leax  x0name,pcr
         lda   #UPDAT.
         os9   I$Open
         bcs   noxd
         sta   xpath,u
noxd
         lda   >XID
         cmpa  #1                  1: Z80 sub CPU
         beq   hasz
         lda   mode,u
         anda  #1
         sta   mode,u
         lbeq  nosub
         bra   go
hasz     lbsr  loadz
         lbsr  waitrx              the "ready" doorbell
         lbcs  timeout
go       lbsr  rdus0
* --- the scheduler: the Z80 gets a row when it is idle, the 6809 computes a row when the Z80 is busy
main     lbsr  zpoll
         lda   next,u
         cmpa  #NROWS
         bhs   fin
         lda   mode,u
         bita  #2
         beq   do68
         tst   zbusy,u
         bne   zb
         lbsr  zgive
         bra   main
zb       lda   mode,u
         bita  #1
         bne   do68
         lbsr  waitrx              the Z80 only: wait for it
         lbcs  timeout
         lbsr  zget
         bra   main
do68     lbsr  row68
         bra   main
fin      tst   zbusy,u
         beq   done
         lbsr  waitrx
         lbcs  timeout
         lbsr  zget
         bra   fin
done     lbsr  rdus1
         clr   >XCTL               stop the Z80
         lbsr  picture
         lbsr  report
         tst   showi,u
         beq   done2
         lbsr  repirq
done2
         clrb
         os9   F$Exit

nosub    leax  msgnosub,pcr
         bra   perr
timeout  leay  out,u              what the cross link says: XCTL XSTAT and the row of the Z80
         leax  msgtmo,pcr
         lbsr  puts
         lda   >XCTL
         lbsr  put2h
         lda   #' '
         sta   ,y+
         lda   >XSTAT
         lbsr  put2h
         lda   #' '
         sta   ,y+
         lda   zrow,u
         lbsr  put2h
         lda   #C$CR
         sta   ,y+
         clr   >XCTL
         leax  out,u
         lda   #2
         ldy   #80
         os9   I$WritLn
         ldb   #1
         os9   F$Exit
usage    leax  msgusage,pcr
perr     lda   #2
         ldy   #80
         os9   I$WritLn
         ldb   #1
         os9   F$Exit

* ---------------------------------------------------------------- the Z80
* hold it in reset, copy its program to the sub CPU address 0, release it
loadz    clr   >XCTL
         clra
         ldx   #0
         lbsr  setwin
         leax  duoz80,pcr
         ldy   #duoz80n
lz1      lda   ,x+
         sta   >XDAT
         leay  -1,y
         bne   lz1
         lda   #1
         sta   >XCTL
         rts

* give the next row to the Z80
zgive    lda   #XE_M2S
         sta   >XIDX
         lda   next,u
         sta   >XDAT
         sta   zrow,u
         clra
         sta   >XID                ring the Z80
         inc   next,u
         lda   #1
         sta   zbusy,u
         rts

* if the Z80 has finished its row: take it
zpoll    tst   zbusy,u
         beq   zp9
         lda   >XSTAT
         bita  #1
         beq   zp9
         sta   >XSTAT              acknowledge
         bra   zget
zp9      rts

* the row of the Z80 (sub CPU address $0200, 79 characters) -> rows[zrow]
zget     lda   zrow,u
         ldb   #NCOLS
         mul
         leax  rows,u
         leax  d,x
         pshs  x
         clra
         ldx   #$0200
         lbsr  setwin
         puls  x
         ldb   #NCOLS
zg1      lda   >XDAT
         sta   ,x+
         decb
         bne   zg1
         leax  owner,u
         ldb   zrow,u
         lda   #1
         sta   b,x
         inc   nz80,u
         clr   zbusy,u
         rts

* wait until the Z80 rang the doorbell, acknowledge it.  C set on timeout.
waitrx   ldy   #1500
w1       lda   >XSTAT
         bita  #1
         bne   w2
         pshs  y
         tst   xpath,u
         beq   w3
         lda   xpath,u
         ldb   #SS.XWait
         ldx   #3
         os9   I$GetStt
         bra   w4
w3       ldx   #1
         os9   F$Sleep
w4       puls  y
         leay  -1,y
         bne   w1
         orcc  #1
         rts
w2       sta   >XSTAT
         andcc #$FE
         rts

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

* ---------------------------------------------------------------- the 6809: one row, fixed point (Q8) like duoz80.asm
row68    lda   next,u
         sta   cur,u
         inc   next,u
         ldb   #NCOLS
         mul
         leax  rows,u
         leax  d,x
         stx   dst,u
         lda   cur,u
         ldb   #21
         mul
         subd  #252
         std   cb,u
         ldd   #-468
         std   ca,u
         lda   #NCOLS
         sta   xc,u
pix      ldd   ca,u
         std   aa,u
         tfr   d,x
         lbsr  mulq
         std   a2,u
         ldd   cb,u
         std   bb,u
         tfr   d,x
         lbsr  mulq
         std   b2,u
         clr   it,u
iter     ldd   a2,u                t = a2 - b2 + ca
         subd  b2,u
         addd  ca,u
         pshs  d
         ldd   aa,u                b = 2*a*b + cb
         ldx   bb,u
         lbsr  mulq
         lslb
         rola
         addd  cb,u
         std   bb,u
         puls  d
         std   aa,u                a = t
         tfr   d,x
         lbsr  mulq
         std   a2,u
         ldd   bb,u
         tfr   d,x
         lbsr  mulq
         std   b2,u
         ldd   a2,u
         addd  b2,u
         cmpd  #1025               a*a+b*b > 4
         bhs   esc
         inc   it,u
         lda   it,u
         cmpa  #16
         blo   iter
esc      lda   it,u
         cmpa  #10
         blo   dgt
         cmpa  #16
         beq   blank
         adda  #'A'-10
         bra   put
dgt      adda  #'0'
         bra   put
blank    lda   #' '
put      ldx   dst,u
         sta   ,x+
         stx   dst,u
         ldd   ca,u
         addd  #12
         std   ca,u
         dec   xc,u
         lbne  pix
         leax  owner,u
         ldb   cur,u
         clr   b,x
         inc   n68,u
         rts

* D = D*X >> 8, signed Q8 (the values are below 4096 in magnitude)
mulq     std   pp,u
         stx   qq,u
         lda   pp,u
         eora  qq,u
         anda  #$80
         sta   sg,u
         tst   pp,u
         bpl   mq1
         ldd   pp,u
         coma
         comb
         addd  #1
         std   pp,u
mq1      tst   qq,u
         bpl   mq2
         ldd   qq,u
         coma
         comb
         addd  #1
         std   qq,u
mq2      lda   pp+1,u              pl*ql >> 8
         ldb   qq+1,u
         mul
         tfr   a,b
         clra
         std   acc,u
         lda   pp,u                + ph*ql
         ldb   qq+1,u
         mul
         addd  acc,u
         std   acc,u
         lda   pp+1,u              + pl*qh
         ldb   qq,u
         mul
         addd  acc,u
         std   acc,u
         lda   pp,u                + ph*qh << 8
         ldb   qq,u
         mul
         tfr   b,a
         clrb
         addd  acc,u
         tst   sg,u
         beq   mq3
         coma
         comb
         addd  #1
mq3      rts

* ---------------------------------------------------------------- the output
picture  clr   cur,u
pc1      leay  out,u
         tst   color,u
         beq   pc2
         lda   #27                 ESC [ 3 x m: 6 = cyan (Z80), 3 = yellow (6809)
         sta   ,y+
         lda   #'['
         sta   ,y+
         lda   #'3'
         sta   ,y+
         leax  owner,u
         ldb   cur,u
         lda   b,x
         beq   pc3
         lda   #'6'
         bra   pc4
pc3      lda   #'3'
pc4      sta   ,y+
         lda   #'m'
         sta   ,y+
pc2      lda   cur,u
         ldb   #NCOLS
         mul
         leax  rows,u
         leax  d,x
         ldb   #NCOLS
pc5      lda   ,x+
         sta   ,y+
         decb
         bne   pc5
         tst   color,u
         beq   pc6
         lda   #27
         sta   ,y+
         lda   #'['
         sta   ,y+
         lda   #'0'
         sta   ,y+
         lda   #'m'
         sta   ,y+
pc6      lbsr  wrline
         inc   cur,u
         lda   cur,u
         cmpa  #NROWS
         blo   pc1
         rts

* "6809: n rows   Z80: m rows   12.345678 s"
report   leay  out,u
         leax  msg68,pcr
         lbsr  puts
         lda   n68,u
         lbsr  put2
         leax  msgz,pcr
         lbsr  puts
         lda   nz80,u
         lbsr  put2
         leax  msgrows,pcr
         lbsr  puts
         lda   t1+3,u              num = t1 - t0
         suba  t0+3,u
         sta   num+3,u
         lda   t1+2,u
         sbca  t0+2,u
         sta   num+2,u
         lda   t1+1,u
         sbca  t0+1,u
         sta   num+1,u
         lda   t1,u
         sbca  t0,u
         sta   num,u
         lbsr  u32dec              10 digits: 4 for the seconds, 6 for the microseconds
         leax  dig,u
         ldb   #3                  the leading zeros of the seconds are not written (one digit stays)
rp1      lda   ,x
         cmpa  #'0'
         bne   rp2
         leax  1,x
         decb
         bne   rp1
rp2      incb
rp3      lda   ,x+
         sta   ,y+
         decb
         bne   rp3
         lda   #'.'
         sta   ,y+
         ldb   #3                  milliseconds are enough
rp4      lda   ,x+
         sta   ,y+
         decb
         bne   rp4
         leax  msgs,pcr
         lbsr  puts
         lbra  wrline

* "doorbell interrupts: n" (SS.XInfo of the driver: R$U)
repirq   tst   xpath,u
         beq   ri9
         lda   xpath,u
         ldb   #SS.XInfo
         pshs  u
         os9   I$GetStt
         tfr   u,d
         puls  u
         std   irqs,u
         leay  out,u
         leax  msgi,pcr
         lbsr  puts
         ldd   irqs,u
         std   num+2,u
         clr   num,u
         clr   num+1,u
         lbsr  u32dec
         leax  dig,u
         ldb   #9
ri1      lda   ,x
         cmpa  #'0'
         bne   ri2
         leax  1,x
         decb
         bne   ri1
ri2      incb
ri3      lda   ,x+
         sta   ,y+
         decb
         bne   ri3
         lbra  wrline
ri9      rts

* A as two hex digits at Y
put2h    pshs  a
         lsra
         lsra
         lsra
         lsra
         bsr   p2h
         puls  a
         anda  #$0F
p2h      adda  #'0'
         cmpa  #'9'
         bls   p2h2
         adda  #7
p2h2     sta   ,y+
         rts

* A (0-99) as one or two digits at Y
put2     clrb
p2a      cmpa  #10
         blo   p2b
         suba  #10
         incb
         bra   p2a
p2b      pshs  a
         tstb
         beq   p2c
         addb  #'0'
         stb   ,y+
p2c      puls  a
         adda  #'0'
         sta   ,y+
         rts

* copy the NUL terminated text at X to Y
puts     lda   ,x+
         beq   pu9
         sta   ,y+
         bra   puts
pu9      rts

* end the line at Y with a CR and write it
wrline   lda   #C$CR
         sta   ,y+
         leax  out,u
         pshs  x
         tfr   y,d
         subd  ,s++
         tfr   d,y
         lda   #1
         os9   I$WritLn
         rts

* the microsecond counter (byte 0 latches the value)
rdus0    leay  t0,u
         bra   rdus
rdus1    leay  t1,u
rdus     lda   #$80+XE_US
         sta   >XIDX
         lda   >XDAT
         sta   ,y
         lda   >XDAT
         sta   1,y
         lda   >XDAT
         sta   2,y
         lda   >XDAT
         sta   3,y
         rts

* the 32 bit number num -> 10 decimal digits in dig (ASCII with leading zeros); num is used up
u32dec   leax  dig+10,u
         ldb   #10
ud1      pshs  b,x
         clr   rem,u
         ldb   #32
ud2      asl   num+3,u
         rol   num+2,u
         rol   num+1,u
         rol   num,u
         rol   rem,u
         lda   rem,u
         cmpa  #10
         blo   ud3
         suba  #10
         sta   rem,u
         inc   num+3,u
ud3      decb
         bne   ud2
         puls  b,x
         lda   rem,u
         adda  #'0'
         sta   ,-x
         decb
         bne   ud1
         rts

         emod
eom      equ   *
         end
