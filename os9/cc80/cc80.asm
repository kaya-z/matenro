* SPDX-License-Identifier: MIT
********************************************************************
* cc80 - compile a C program for CP/M-80 from OS-9 Level 2, written for 摩天楼 (Matenro)
*
*   cc80 [-s] [-c] [-r] [-k] [-v] [-lf] [-t=dir] [-Dname[=value]] [-Idir] file.c
*
* One command drives the whole chain of two operating systems:
*
*     OS-9 (6809)     cpp80  file.c            the C preprocessor of this project (os9/cpp)
*     CP/M-80 (Z80)   p1, cgen               the HI-TECH C compiler passes, run by `cpm` on the Z80
*     CP/M-80 (Z80)   zas, linq              the assembler and the linker of the same compiler
*
* and leaves file.com, a CP/M-80 program, in the current directory.  With -r it is started at once (`cpm`).
*   -s  stop after the code generator (file.as)      -c  stop after the assembler (file.obj)
*   -r  run the program                              -k  keep the intermediate files (.i .p1 .as .obj)
*   -v  show the commands                            -t=dir  the directory of the compiler (default /v0/htc)
*   -lf link the floating point library (libf.lib, like the -LF of the HI-TECH driver).  It is added by itself when
*       the code generator has called a routine of it (fladd, flmul, aitof ...).
* The HI-TECH C compiler (CPP.COM is not needed, P1.COM CGEN.COM ZAS.COM LINQ.COM, CRTCPM.OBJ, LIBC.LIB, LIBF.LIB and the
* header files) is not part of this project: it has to be copied to the directory by the user.
*
* Credits: the order of the compiler passes and the options of the passes follow the verbose output and the
* option description (OPTIONS) of HI-TECH C 3.09 for CP/M-80 as published by Tony Nicholson
* (github.com/agn453/HI-TECH-Z80-C).  No code of that compiler is used here.  The module layout follows the
* sample commands of the NitrOS-9 project (see os9/xrun.asm).
********************************************************************

         nam   cc80
         ttl   C compiler driver

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

F_S      equ   1
F_C      equ   2
F_R      equ   4
F_V      equ   8
F_K      equ   16
F_F      equ   32

         mod   eom,name,tylg,atrv,start,size

         org   0
argp     rmb   2
flags    rmb   1
cop      rmb   2                 end of the text in copts
tool     rmb   48
copts    rmb   160
src      rmb   64
stem     rmb   10
pbuf     rmb   420
nmp      rmb   2
plen     rmb   2
tmp16    rmb   2
szh      rmb   2                 the size of a stage's output file (chk)
szl      rmb   2
status   rmb   1
fpth     rmb   1
lbuf     rmb   80
         rmb   200               stack
size     equ   .

name     fcs   /cc80/
         fcb   edition

msgusage fcc   "usage: cc80 [-s -c -r -k -v -lf] [-t=dir] [-Dname[=value]] [-Idir] file.c"
         fcb   C$CR
msgfail  fcc   "cc80: failed: "
         fcb   0
msgrun   fcc   "cc80: cannot run "
         fcb   0
msgout   fcc   "cc80: no output: "
         fcb   0
msgsrc   fcc   "cc80: cannot open "
         fcb   0
msgplus  fcc   "+ "
         fcb   0
msgsp    fcc   " "
         fcb   0
msgnl    fcb   C$CR
deftool  fcc   "/v0/htc"
         fcb   0

n_cpp    fcc   "cpp80"
         fcb   C$CR
n_cpm    fcc   "cpm"
         fcb   C$CR

t_cpp    fcc   "-DCPM -DHI_TECH_C -Dz80 -I@ ^-o%.i #"
         fcb   0
t_p1     fcc   "-k -p=@ p1 %.i %.p1 %.p2"
         fcb   0
t_cgen   fcc   "-k -p=@ cgen %.p1 %.as"
         fcb   0
t_zas    fcc   "-k -p=@ zas -J -N -O%.obj %.as"
         fcb   0
t_link   fcc   "-k -p=@ linq -Z -Ptext=0,data,bss -C100H -O%.com crtcpm.obj %.obj libc.lib"
         fcb   0
t_linkf  fcc   "-k -p=@ linq -Z -Ptext=0,data,bss -C100H -O%.com crtcpm.obj %.obj libf.lib libc.lib"
         fcb   0
t_run    fcc   "%.com"
         fcb   0

d_i      fcc   "%.i"
         fcb   0
d_p1     fcc   "%.p1"
         fcb   0
d_p2     fcc   "%.p2"
         fcb   0
d_as     fcc   "%.as"
         fcb   0
d_obj    fcc   "%.obj"
         fcb   0
d_com    fcc   "%.com"
         fcb   0

* ------------------------------------------------------------------
start    stx   argp,u
         clr   flags,u
         clr   src,u
         leax  copts,u
         stx   cop,u
         clr   ,x
         leax  deftool,pcr
         leay  tool,u
         lbsr  app
         clr   ,y
* ---- the command line
nxt      ldx   argp,u
nx1      lda   ,x+
         cmpa  #' '
         beq   nx1
         cmpa  #C$CR
         lbeq  parsed
         cmpa  #'-'
         lbne  getsrc
         lda   ,x
         anda  #$DF
         cmpa  #'S'
         bne   o1
         ldb   #F_S
         bra   flag
o1       cmpa  #'C'
         bne   o2
         ldb   #F_C
         bra   flag
o2       cmpa  #'R'
         bne   o3
         ldb   #F_R
         bra   flag
o3       cmpa  #'K'
         bne   o4
         ldb   #F_K
         bra   flag
o4       cmpa  #'V'
         bne   o5
         ldb   #F_V
flag     orb   flags,u
         stb   flags,u
         leax  1,x
         stx   argp,u
         bra   nxt
o5       cmpa  #'T'
         bne   o6
         leax  1,x
         lda   ,x
         cmpa  #'='
         bne   o5a
         leax  1,x
o5a      leay  tool,u
o5b      lda   ,x
         cmpa  #' '
         beq   o5c
         cmpa  #C$CR
         beq   o5c
         sta   ,y+
         leax  1,x
         bra   o5b
o5c      clr   ,y
         stx   argp,u
         bra   nxt
o6       cmpa  #'L'
         bne   o6a
         lda   1,x                   -lf: the floating point library
         anda  #$DF
         cmpa  #'F'
         lbne  usage
         lda   flags,u
         ora   #F_F
         sta   flags,u
         leax  2,x
         stx   argp,u
         lbra  nxt
o6a      cmpa  #'D'
         beq   o7
         cmpa  #'I'
         lbne  usage
o7       leax  -1,x                  the whole word goes to the options of the preprocessor
         ldy   cop,u
o7a      lda   ,x
         cmpa  #' '
         beq   o7b
         cmpa  #C$CR
         beq   o7b
         sta   ,y+
         leax  1,x
         bra   o7a
o7b      lda   #' '
         sta   ,y+
         clr   ,y
         sty   cop,u
         stx   argp,u
         lbra  nxt
getsrc   leax  -1,x                  the source file
         leay  src,u
gs1      lda   ,x
         cmpa  #' '
         beq   gs2
         cmpa  #C$CR
         beq   gs2
         sta   ,y+
         leax  1,x
         bra   gs1
gs2      clr   ,y
         stx   argp,u
         lbra  nxt
* ---- the name of the intermediate files: the file name without directory and extension (8 characters at most)
parsed   tst   src,u
         lbeq  usage
         leax  src,u
         leay  src,u                 Y = start of the base name
pa1      lda   ,x+
         beq   pa3
         cmpa  #'/'
         bne   pa1
         tfr   x,y
         bra   pa1
pa3      leax  stem,u
         ldb   #8
pa4      lda   ,y+
         beq   pa5
         cmpa  #'.'
         beq   pa5
         sta   ,x+
         decb
         bne   pa4
pa5      clr   ,x
         tst   stem,u
         lbeq  usage
* ---- the source must be there before anything is deleted: the old results below are the files of the same name
* (hello.c -> hello.com), a wrong directory or a wrong name would delete a program that has nothing to do with this
         leax  src,u
         leay  pbuf,u
ck1      lda   ,x+
         sta   ,y+
         bne   ck1
         lda   #C$CR
         sta   -1,y
         leax  pbuf,u
         lda   #READ.
         os9   I$Open
         bcc   ck2
         leax  msgsrc,pcr
         lbsr  wrstr
         leax  pbuf,u
         lbsr  wrstr
         lbsr  newline
         ldb   #1
         os9   F$Exit
ck2      os9   I$Close
* ---- run the passes
         leax  d_i,pcr               old results would stop the CP/M programs ("make" fails if the file exists)
         lbsr  delete
         leax  d_p1,pcr
         lbsr  delete
         leax  d_p2,pcr
         lbsr  delete
         leax  d_as,pcr
         lbsr  delete
         leax  d_obj,pcr
         lbsr  delete
         leax  d_com,pcr
         lbsr  delete
         leax  t_cpp,pcr
         leay  n_cpp,pcr
         lbsr  stage
         leax  d_i,pcr
         lbsr  chk
         leax  t_p1,pcr
         leay  n_cpm,pcr
         lbsr  stage
         leax  d_p1,pcr
         lbsr  chk
         leax  t_cgen,pcr
         leay  n_cpm,pcr
         lbsr  stage
         leax  d_as,pcr
         lbsr  chk
         lda   flags,u
         bita  #F_S
         bne   fin
         leax  t_zas,pcr
         leay  n_cpm,pcr
         lbsr  stage
         leax  d_obj,pcr
         lbsr  chk
         lda   flags,u
         bita  #F_C
         bne   fin
         lbsr  scanfl
         leax  t_link,pcr
         lda   flags,u
         bita  #F_F
         beq   ln1
         leax  t_linkf,pcr
ln1      leay  n_cpm,pcr
         lbsr  stage
         leax  d_com,pcr
         lbsr  chk
         lda   flags,u
         bita  #F_R
         beq   fin
         leax  t_run,pcr
         leay  n_cpm,pcr
         lbsr  stage
fin      lda   flags,u
         bita  #F_K
         bne   done
         leax  d_i,pcr
         lbsr  delete
         leax  d_p1,pcr
         lbsr  delete
         leax  d_p2,pcr
         lbsr  delete
         lda   flags,u
         bita  #F_S
         bne   done
         leax  d_as,pcr
         lbsr  delete
         lda   flags,u
         bita  #F_C
         bne   done
         leax  d_obj,pcr
         lbsr  delete
done     clrb
         os9   F$Exit

usage    leax  msgusage,pcr
         lda   #2
         ldy   #80
         os9   I$WritLn
         ldb   #1
         os9   F$Exit

* ------------------------------------------------------------------
* append the NUL terminated text at X to Y (the NUL is not copied)
app      lda   ,x+
         beq   ap9
         sta   ,y+
         bra   app
ap9      rts

* append the template at X to Y and end it with CR: % = the base name, @ = the compiler directory,
* ^ = the options of the preprocessor, # = the source file
appt     lda   ,x+
         beq   at9
         cmpa  #'%'
         bne   at1
         pshs  x
         leax  stem,u
         bra   at4
at1      cmpa  #'@'
         bne   at2
         pshs  x
         leax  tool,u
         bra   at4
at2      cmpa  #'^'
         bne   at3
         pshs  x
         leax  copts,u
         bra   at4
at3      cmpa  #'#'
         bne   at5
         pshs  x
         leax  src,u
at4      lbsr  app
         puls  x
         bra   appt
at5      sta   ,y+
         bra   appt
at9      lda   #C$CR
         sta   ,y+
         rts

* delete the file of the template at X (no complaint if there is none)
delete   leay  pbuf,u
         lbsr  appt
         leax  pbuf,u
         lda   #UPDAT.
         os9   I$Delete
         rts

* look in file.as (the output of the code generator) for a call of a routine of the floating point library:
* the lines "call<TAB>name", name = fladd flsub flmul fldiv (fl...), asfl..., frelop, ftol, aitof, altof, lltof.  If there is
* one, F_F is set (libf.lib in front of libc.lib).  Nothing to do when -lf is given already.
scanfl   lda   flags,u
         bita  #F_F
         bne   sf9
         leax  d_as,pcr
         leay  pbuf,u
         lbsr  appt
         leax  pbuf,u
         lda   #READ.
         os9   I$Open
         bcs   sf9
         sta   fpth,u
sf1      lda   fpth,u
         leax  lbuf,u
         ldy   #80
         os9   I$ReadLn
         bcs   sf8
         leax  lbuf,u
         ldd   ,x
         cmpd  #$6361                "ca"
         bne   sf1
         ldd   2,x
         cmpd  #$6C6C                "ll"
         bne   sf1
         lda   4,x
         cmpa  #9                    TAB
         bne   sf1
         leax  5,x                   the name
         leay  fpfx,pcr
sf2      tst   ,y
         lbeq  sf1                   no prefix matches: the next line
         pshs  x
sf3      lda   ,y+
         beq   sf5
         cmpa  ,x+
         beq   sf3
sf4      lda   ,y+                   skip the rest of this prefix
         bne   sf4
         puls  x
         bra   sf2
sf5      puls  x
         lda   flags,u
         ora   #F_F
         sta   flags,u
sf8      lda   fpth,u
         os9   I$Close
sf9      rts

fpfx     fcc   "fl"
         fcb   0
         fcc   "asfl"
         fcb   0
         fcc   "frelop"
         fcb   0
         fcc   "ftol"
         fcb   0
         fcc   "ait"
         fcb   0
         fcc   "alt"
         fcb   0
         fcc   "llt"
         fcb   0
         fcb   0

* write the text at X (up to CR or NUL) to the standard error path
wrstr    pshs  x
         ldy   #0
ws1      lda   ,x+
         beq   ws2
         cmpa  #C$CR
         beq   ws2
         leay  1,y
         bra   ws1
ws2      puls  x
         cmpy  #0
         beq   ws9
         lda   #2
         os9   I$Write
ws9      rts

* run a program: X = the template of its parameters, Y = its name (CR terminated)
stage    sty   nmp,u
         leay  pbuf,u
         lbsr  appt                  Y is behind the CR
         leax  pbuf,u
         stx   tmp16,u
         tfr   y,d
         subd  tmp16,u
         std   plen,u                the length of the parameters
         lda   flags,u
         bita  #F_V
         beq   st1
         leax  msgplus,pcr
         lbsr  wrstr
         ldx   nmp,u
         lbsr  wrstr
         leax  msgsp,pcr
         lbsr  wrstr
         leax  pbuf,u
         lbsr  wrstr
         lbsr  newline
st1      ldx   nmp,u
         ldy   plen,u
         pshs  u
         leau  pbuf,u
         lda   #Prgrm+Objct
         clrb
         os9   F$Fork
         puls  u
         bcs   st_nofork
         os9   F$Wait
         bcs   st_nofork
         tstb
         bne   st_fail
         rts
st_fail  stb   status,u
         leax  msgfail,pcr
         bra   st_msg
st_nofork stb  status,u
         leax  msgrun,pcr
st_msg   lbsr  wrstr
         ldx   nmp,u
         lbsr  wrstr
         lbsr  newline
         ldb   status,u
         os9   F$Exit

* the output file of a stage must be there and not empty (a CP/M program that cannot write its output - disk full, no
* such file - reports it and returns as if nothing had happened, and the next stage, or the program itself, would run
* with nothing): X = the template of its name.  If not: say so and leave with status 1
chk      leay  pbuf,u
         lbsr  appt
         leax  pbuf,u
         lda   #READ.
         os9   I$Open
         bcs   ck_bad
         sta   fpth,u
         pshs  u                     the size comes back in X:U
         ldb   #SS.Size
         os9   I$GetStt
         pshs  x,u,cc
         ldu   5,s
         ldd   1,s
         std   szh,u
         ldd   3,s
         std   szl,u
         puls  cc
         leas  4,s
         puls  u
         lda   fpth,u
         os9   I$Close
         ldd   szh,u
         bne   ck_ok
         ldd   szl,u
         bne   ck_ok
ck_bad   leax  msgout,pcr
         lbsr  wrstr
         leax  pbuf,u
         lbsr  wrstr
         lbsr  newline
         ldb   #1
         os9   F$Exit
ck_ok    rts

newline  leax  msgnl,pcr
         lda   #2
         ldy   #1
         os9   I$WritLn
         rts

         emod
eom      equ   *
         end
