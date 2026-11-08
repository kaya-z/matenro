* SPDX-License-Identifier: MIT
********************************************************************
* etime - run a command and show how long it took
*
*   etime [-c] command [arguments]
*
*   Elapsed 12.345678 s                                          the real time (microseconds)
*   Sub CPU 90123456 clocks (12016 ms at 7500 kHz)               with -c: what the sub CPU (Z80 / 8088) executed
*
* The time comes from the microsecond counter of the cross link (XE_US, the extended registers $14-$17 behind
* XIDX / XDAT at $FFCD / $FFCE of the I/O page that every task sees): the clock of OS-9 (F$Time) counts only whole
* seconds.  The counter wraps after 71 minutes; a longer command shows a wrong time.  With -c the clock counter of
* the sub CPU (XE_CLK, also 32 bits: 9.5 minutes at 7.5 MHz) is read before and after; the milliseconds are
* clocks / kHz.  The exit status is that of the command.
*
* The built-in commands of the shell (chd, chx, ...) are not programs: `etime shell <file` runs a procedure file.
*
* Credits: the module layout follows the sample commands of the NitrOS-9 project (GPL v2), as in os9/xrun.asm.
* The code is original.
********************************************************************

         nam   etime
         ttl   Time a command

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

XID      equ   $FFCC
XIDX     equ   $FFCD
XDAT     equ   $FFCE
XE_KHZ   equ   $0E
XE_CLK   equ   $10
XE_US    equ   $14

         mod   eom,name,tylg,atrv,start,size

         org   0
flagc    rmb   1                 -c given
cnt      rmb   1
t0       rmb   4                 microseconds at the start / the end
t1       rmb   4
c0       rmb   4                 sub CPU clocks at the start / the end
c1       rmb   4
khz      rmb   2
nm       rmb   2                 the command name
pp       rmb   2                 the parameters behind the name
plen     rmb   2
status   rmb   1
num      rmb   4                 the number to print
ck       rmb   4
rem      rmb   2
dig      rmb   10
out      rmb   100
         rmb   200               stack
size     equ   .

name     fcs   /etime/
         fcb   edition

msgusage fcc   "usage: etime [-c] command [arguments]"
         fcb   C$CR
msgnox   fcc   "etime: no cross link (no timer)"
         fcb   C$CR
msgel    fcc   "Elapsed "
         fcb   0
msgs     fcc   " s"
         fcb   0
msgsub   fcc   "Sub CPU "
         fcb   0
msgclk   fcc   " clocks ("
         fcb   0
msgms    fcc   " ms at "
         fcb   0
msgkhz   fcc   " kHz)"
         fcb   0

start    clr   flagc,u
         lda   >XID                  0 or $FF: not the Matenro machine
         lbeq  nox
         cmpa  #$FF
         lbeq  nox
         lbsr  skipsp
         cmpa  #C$CR
         lbeq  usage
         cmpa  #'-'
         bne   cmd
         lda   1,x
         anda  #$DF
         cmpa  #'C'
         lbne  usage
         lda   2,x
         cmpa  #' '
         lbne  usage
         lda   #1
         sta   flagc,u
         leax  2,x
         lbsr  skipsp
         cmpa  #C$CR
         lbeq  usage
cmd      stx   nm,u                  the name of the command
cm1      lda   ,x+
         cmpa  #' '
         beq   cm2
         cmpa  #C$CR
         bne   cm1
cm2      leax  -1,x                  X = the character behind the name (a blank or the CR)
         stx   pp,u
         leay  ,x
cm3      lda   ,y+
         cmpa  #C$CR
         bne   cm3
         tfr   y,d
         subd  pp,u                  the length of the parameters with the CR
         std   plen,u
* the sub CPU clock in kHz, once
         lda   #$80+XE_KHZ
         sta   >XIDX
         lda   >XDAT
         sta   khz,u
         lda   >XDAT
         sta   khz+1,u
         lbsr  rdclk0
         lbsr  rdus0
* run the command and wait
         ldx   nm,u
         ldy   plen,u
         pshs  u
         ldu   pp,u
         lda   #Prgrm+Objct
         clrb
         os9   F$Fork
         puls  u
         bcs   ferr
         os9   F$Wait
         stb   status,u
         lbsr  rdus1
         lbsr  rdclk1
         lbsr  report
         bra   fin
ferr     stb   status,u              (the shell shows the error: it is the exit status)
fin      ldb   status,u
         os9   F$Exit

nox      leax  msgnox,pcr
         bra   perr
usage    leax  msgusage,pcr
perr     lda   #2
         ldy   #80
         os9   I$WritLn
         ldb   #1
         os9   F$Exit

* skip blanks at X; A = the first other character
skipsp   lda   ,x+
         cmpa  #' '
         beq   skipsp
         leax  -1,x
         rts

* ---------------------------------------------------------------- the counters (byte 0 latches the value)
rdus0    leay  t0,u
         bra   rdus
rdus1    leay  t1,u
rdus     lda   #$80+XE_US
         bra   rd4
rdclk0   tst   flagc,u
         beq   rdn
         leay  c0,u
         bra   rdclk
rdclk1   tst   flagc,u
         beq   rdn
         leay  c1,u
rdclk    lda   #$80+XE_CLK
rd4      sta   >XIDX
         lda   >XDAT
         sta   ,y
         lda   >XDAT
         sta   1,y
         lda   >XDAT
         sta   2,y
         lda   >XDAT
         sta   3,y
rdn      rts

* ---------------------------------------------------------------- the report
report   leay  out,u
         leax  msgel,pcr
         lbsr  puts
         lda   t1+3,u                num = t1 - t0
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
         lbsr  u32dec                10 digits: 4 for the seconds, 6 for the microseconds
         leax  dig,u
         ldb   #3                    the leading zeros of the seconds are not written (one digit stays)
rp1      lda   ,x
         cmpa  #'0'
         bne   rp2
         leax  1,x
         decb
         bne   rp1
rp2      incb                        the digits of the seconds that are left
rp3      lda   ,x+
         sta   ,y+
         decb
         bne   rp3
         lda   #'.'
         sta   ,y+
         ldb   #6
rp4      lda   ,x+
         sta   ,y+
         decb
         bne   rp4
         leax  msgs,pcr
         lbsr  puts
         lbsr  wrline
         tst   flagc,u
         beq   rpn
* the sub CPU: num = c1 - c0
         leay  out,u
         leax  msgsub,pcr
         lbsr  puts
         lda   c1+3,u
         suba  c0+3,u
         sta   num+3,u
         lda   c1+2,u
         sbca  c0+2,u
         sta   num+2,u
         lda   c1+1,u
         sbca  c0+1,u
         sta   num+1,u
         lda   c1,u
         sbca  c0,u
         sta   num,u
         ldd   num,u                 keep a copy for the milliseconds
         std   ck,u
         ldd   num+2,u
         std   ck+2,u
         lbsr  u32dec
         lbsr  putdec
         leax  msgclk,pcr
         lbsr  puts
         ldd   ck,u                  ms = clocks / kHz
         std   num,u
         ldd   ck+2,u
         std   num+2,u
         lbsr  divkhz
         lbsr  u32dec
         lbsr  putdec
         leax  msgms,pcr
         lbsr  puts
         clr   num,u                 the kHz
         clr   num+1,u
         ldd   khz,u
         std   num+2,u
         lbsr  u32dec
         lbsr  putdec
         leax  msgkhz,pcr
         lbsr  puts
         lbsr  wrline
rpn      rts

* copy the NUL terminated text at X to Y
puts     lda   ,x+
         beq   pu9
         sta   ,y+
         bra   puts
pu9      rts

* write the digits of dig to Y without the leading zeros (the last digit stays)
putdec   leax  dig,u
         ldb   #9
pd1      lda   ,x
         cmpa  #'0'
         bne   pd2
         leax  1,x
         decb
         bne   pd1
pd2      incb
pd3      lda   ,x+
         sta   ,y+
         decb
         bne   pd3
         rts

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

* num / khz -> num (a 32 bit number divided by a 16 bit one; 0 when khz is 0)
divkhz   ldd   khz,u
         bne   dk0
         clr   num,u
         clr   num+1,u
         clr   num+2,u
         clr   num+3,u
         rts
dk0      clr   rem,u
         clr   rem+1,u
         lda   #32
         sta   cnt,u
dk1      asl   num+3,u
         rol   num+2,u
         rol   num+1,u
         rol   num,u
         rol   rem+1,u
         rol   rem,u
         ldd   rem,u
         cmpd  khz,u
         blo   dk2
         subd  khz,u
         std   rem,u
         inc   num+3,u
dk2      dec   cnt,u
         bne   dk1
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
