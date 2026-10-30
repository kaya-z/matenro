* SPDX-License-Identifier: MIT
********************************************************************
* cpp - a C preprocessor for OS-9 Level 2 (6809), written for 摩天楼 (Matenro)
*
*   cpp [-Dname[=value]] [-Idir] [-ofile] [file]   (the result goes to the standard output or to the new file)
*
* Handles comments, line splicing (backslash at the end of a line), #include "file" / <file>, #define (with and
* without parameters), #undef, #ifdef, #ifndef, #if / #elif with integer expressions (defined, ?: || && | ^ &
* == != < > <= >= << >> + - * / % ! ~), #else, #endif, #error, #line and #pragma (the last two are dropped).
* Macros are expanded in the text, but not inside strings and character constants.  The # and ## operators work in
* function-like macros (not in object-like ones).  The output has one line for each input line (blank lines where a directive or a
* comment was), lines end with CR (the OS-9 text format).  `cpm` converts the line ends of the text files it
* hands to a CP/M program by itself.
*
* Typical use (docs/DESIGN.md, chapter 13):
*     cpp -I/dd/htc prog.c >prog.i       the preprocessor on OS-9
*     cpm -p=/dd/htc ... prog.i          a CP/M-80 compiler, running on the Z80
*
* Credits: the behaviour follows the C preprocessor of K&R C / ANSI C (X3.159, the parts listed above); no code
* of another preprocessor was used.  The module layout follows the sample commands of the NitrOS-9 project
* (see os9/xrun.asm).
********************************************************************

         nam   cpp
         ttl   C preprocessor

         ifp1
         use   defsfile
         endc

tylg     set   Prgrm+Objct
atrv     set   ReEnt+rev
rev      set   $00
edition  set   1

QUOT     equ   $22
APOS     equ   $27
BSL      equ   $5C
IFSZ     equ   264               include file record: fd, eof, pos(2), len(2), lineno(2), spare, buffer 256
MAXLN    equ   510

         mod   eom,name,tylg,atrv,start,size

         org   0
ifp      rmb   2
idepth   rmb   1
pb       rmb   1
cmt      rmb   1
instr    rmb   1
extra    rmb   1
ninc     rmb   1
csp      rmb   1
olen     rmb   1
ilen     rmb   1
nargs    rmb   1
edepth   rmb   1
nerr     rmb   1
tmp8     rmb   1
tmp8b    rmb   1
dp       rmb   2                 destination pointer of expand
dlim     rmb   2
hp       rmb   2
ep       rmb   2                 expression parser pointer
tmp16    rmb   2
tmp16b   rmb   2
mulr     rmb   2
nparam   rmb   1
tmpoff_x rmb   2
pastef   rmb   1                 the last item of the body was ##
outp     rmb   1                 path of the output (1 = standard output, -ofile)
ebase    rmb   2                 number base while a constant is parsed
files    rmb   1056              4 * IFSZ
line     rmb   520
out      rmb   520
obuf     rmb   300
cstack   rmb   24
htab     rmb   128
ident    rmb   40
word     rmb   12
pbuf     rmb   100
pnames   rmb   320               8 * 40
incdirs  rmb   192               4 * 48
tmpb     rmb   4160              8 * 520: replacement buffer / argument scratch of each expansion depth
argb     rmb   16640             8 depths * 8 arguments * 130, then the same again: the arguments as written (for # and ##)
heap     rmb   6000
heapend  equ   .
         rmb   300               stack
size     equ   .

name     fcs   /cpp/
         fcb   edition

msgusage fcc   "usage: cpp [-Dname[=value]] [-Idir] [-ofile] [file]"
         fcb   C$CR
msgopen  fcc   "cpp: cannot open "
         fcb   0
msginc   fcc   "cpp: cannot find include file "
         fcb   0
msgerr   fcc   "cpp: #error "
         fcb   0
msgbadif fcc   "cpp: unbalanced #if / #endif"
         fcb   C$CR
         fcb   0
msgmem   fcc   "cpp: out of macro space"
         fcb   C$CR
         fcb   0
defpfx   fcc   "#define "
         fcb   0
nulstr   fcb   0
tmpoff   fdb   0,520,1040,1560,2080,2600,3120,3640
argoff   fdb   0,1040,2080,3120,4160,5200,6240,7280

* ------------------------------------------------------------------
start    stx   tmp16,u               parameter pointer
         lda   #1
         sta   outp,u
         clr   idepth,u
         clr   pb,u
         clr   cmt,u
         clr   extra,u
         clr   ninc,u
         clr   csp,u
         clr   olen,u
         clr   nerr,u
         clr   edepth,u
         leax  htab,u
         ldy   #128
st0      clr   ,x+
         leay  -1,y
         bne   st0
         leax  heap,u
         stx   hp,u
         leax  files,u
         stx   ifp,u
         ldx   tmp16,u
st1      lda   ,x+
         cmpa  #' '
         beq   st1
         cmpa  #C$CR
         lbeq  st_go
         cmpa  #'-'
         lbne  st_file
         lda   ,x+
         anda  #$DF
         cmpa  #'D'
         lbeq  st_d
         cmpa  #'O'
         lbeq  st_o
         cmpa  #'I'
         lbne  usage
         ldb   ninc,u                -Idir
         cmpb  #4
         bhs   st_skip
         lda   #48
         mul
         leay  incdirs,u
         leay  d,y
         inc   ninc,u
st_i1    lda   ,x
         cmpa  #' '
         beq   st_i2
         cmpa  #C$CR
         beq   st_i2
         sta   ,y+
         leax  1,x
         bra   st_i1
st_i2    clr   ,y
         bra   st1
st_o     stx   tmp16,u               -ofile: the result goes to a new file
         lda   #WRITE.
         ldb   #READ.+WRITE.+PREAD.+PWRIT.
         os9   I$Create
         lbcs  nofile
         sta   outp,u
         lbra  st1
st_skip  lda   ,x
         cmpa  #' '
         lbeq  st1
         cmpa  #C$CR
         lbeq  st1
         leax  1,x
         bra   st_skip
st_d     stx   tmp16,u               -Dname[=value]: a "#define name value" line
         leay  line,u
         leax  defpfx,pcr
st_d0    lda   ,x+
         beq   st_d1
         sta   ,y+
         bra   st_d0
st_d1    ldx   tmp16,u
st_d2    lda   ,x
         cmpa  #' '
         beq   st_d4
         cmpa  #C$CR
         beq   st_d4
         cmpa  #'='
         bne   st_d3
         lda   #' '
st_d3    sta   ,y+
         leax  1,x
         bra   st_d2
st_d4    clr   ,y
         pshs  x
         lbsr  dirline
         puls  x
         lbra  st1
st_file  leax  -1,x
         stx   tmp16,u
         lbsr  openmain
         lbcs  nofile
         bra   st_run
st_go    clra                        no file: standard input
         lbsr  initfile
st_run   lbsr  process
         lbsr  flush
         tst   csp,u
         beq   st_ok
         leax  msgbadif,pcr
         lbsr  report
st_ok    clrb
         tst   nerr,u
         beq   st_ex
         ldb   #1
st_ex    os9   F$Exit

usage    leax  msgusage,pcr
         lda   #2
         ldy   #60
         os9   I$WritLn
         ldb   #1
         os9   F$Exit
nofile   leax  msgopen,pcr
         lbsr  report
         ldx   tmp16,u
         lbsr  report2
         ldb   #1
         os9   F$Exit

* text at ,X (NUL terminated) to the standard error path; report also counts an error, report2 writes the rest of
* the message (up to a CR or a blank) and a CR
report   inc   nerr,u
         bra   rp0
report2  lbsr  rp0
         lda   #C$CR
         sta   pbuf,u
         lda   #2
         leax  pbuf,u
         ldy   #1
         os9   I$Write
         rts
rp0      lda   ,x+
         beq   rp2
         cmpa  #C$CR
         beq   rp2
         cmpa  #' '
         beq   rp2
         sta   pbuf,u
         pshs  x
         lda   #2
         leax  pbuf,u
         ldy   #1
         os9   I$Write
         puls  x
         bra   rp0
rp2      rts

* ------------------------------------------------------------------
* input files
openmain ldx   tmp16,u
         lda   #READ.
         os9   I$Open
         bcs   om9
         lbsr  initfile
         andcc #$FE
om9      rts

initfile ldx   ifp,u                 A = path
         sta   ,x
         clr   1,x
         clr   2,x
         clr   3,x
         clr   4,x
         clr   5,x
         clr   6,x
         clr   7,x
         rts

* next character: A, or carry set at the end of the input.  A finished include file returns a line end.
getc     pshs  y                     (rdline keeps its line pointer in Y)
         lbsr  getc0
         puls  y
         rts
getc0    lda   pb,u
         beq   gc0
         clr   pb,u
         andcc #$FE
         rts
gc0      ldx   ifp,u
         ldd   2,x
         cmpd  4,x
         blo   gc1
         tst   1,x
         bne   gc_e
         lbsr  fill
         bcs   gc_e
         ldx   ifp,u
         ldd   2,x
         cmpd  4,x
         bhs   gc_e
gc1      leay  8,x
         lda   d,y
         pshs  a
         ldd   2,x
         addd  #1
         std   2,x
         puls  a
         andcc #$FE
         rts
gc_e     tst   idepth,u
         beq   gc_end
         ldx   ifp,u
         lda   ,x
         os9   I$Close
         dec   idepth,u
         ldx   ifp,u
         leax  -IFSZ,x
         stx   ifp,u
         lda   #C$CR
         andcc #$FE
         rts
gc_end   orcc  #1
         rts

ungetc   sta   pb,u
         rts

fill     ldx   ifp,u
         lda   ,x
         leax  8,x
         ldy   #256
         os9   I$Read
         bcc   fl1
         ldx   ifp,u
         inc   1,x
         orcc  #1
         rts
fl1      ldx   ifp,u
         sty   4,x
         clr   2,x
         clr   3,x
         cmpy  #0
         bne   fl2
         inc   1,x
         orcc  #1
         rts
fl2      andcc #$FE
         rts

* ------------------------------------------------------------------
* one logical line into `line` (comments become one space, backslash line ends are joined).
* carry set at the end of the input (nothing read).
rdline   leay  line,u
         clr   instr,u
         clr   extra,u
         clr   tmp8,u                tmp8 = 1 once a character was read
rl1      lbsr  getc
         lbcs  rl_eof
         inc   tmp8,u
         tst   cmt,u
         lbne  rl_cm
         cmpa  #C$CR
         lbeq  rl_nl
         cmpa  #10
         lbeq  rl_nl
         cmpa  #BSL
         bne   rl2
         lbsr  getc                  a backslash: a line end behind it is joined
         lbcs  rl_bs
         cmpa  #C$CR
         beq   rl_j
         cmpa  #10
         beq   rl_j2
         pshs  a
         lda   #BSL
         lbsr  putl
         puls  a
         lbsr  putl
         lbra   rl1
rl_bs    lda   #BSL
         lbsr  putl
         lbra  rl_end
rl_j     lbsr  getc                  CR LF
         bcs   rl_j2
         cmpa  #10
         beq   rl_j2
         lbsr  ungetc
rl_j2    inc   extra,u
         lbra   rl1
rl2      tst   instr,u
         beq   rl3
         lbsr  putl
         cmpa  instr,u
         bne   rl1
         clr   instr,u
         lbra   rl1
rl3      cmpa  #QUOT
         beq   rl_q
         cmpa  #APOS
         beq   rl_q
         cmpa  #'/'
         bne   rl_put
         lbsr  getc
         bcs   rl_sl
         cmpa  #'*'
         beq   rl_c1
         lbsr  ungetc
rl_sl    lda   #'/'
rl_put   lbsr  putl
         lbra   rl1
rl_q     sta   instr,u
         lbsr  putl
         lbra   rl1
rl_c1    inc   cmt,u
         lbra  rl1
rl_cm    cmpa  #'*'                  inside a comment
         bne   rl_cn
rl_c2    lbsr  getc
         lbcs  rl_end
         cmpa  #'/'
         beq   rl_c3
         cmpa  #'*'
         beq   rl_c2
         bra   rl_cn
rl_c3    clr   cmt,u
         lda   #' '
         lbsr  putl
         lbra  rl1
rl_cn    cmpa  #C$CR
         beq   rl_cc
         cmpa  #10
         lbne  rl1
         inc   extra,u
         lbra  rl1
rl_cc    inc   extra,u
         lbsr  getc
         lbcs  rl_end
         cmpa  #10
         lbeq  rl1
         lbsr  ungetc
         lbra  rl1
rl_nl    cmpa  #C$CR                 end of the logical line; CR LF counts once
         bne   rl_end
         lbsr  getc
         bcs   rl_end
         cmpa  #10
         beq   rl_end
         lbsr  ungetc
rl_end   clr   ,y
         andcc #$FE
         rts
rl_eof   clr   ,y
         tst   tmp8,u
         bne   rl_end
         orcc  #1
         rts

putl     pshs  x                     A -> line buffer at Y (if there is room)
         leax  line+MAXLN,u
         pshs  x
         cmpy  ,s++
         bhs   pl9
         sta   ,y+
pl9      puls  x
         rts

* ------------------------------------------------------------------
* output: the text at ,X (NUL terminated) and a CR
wrline   clra
         ldb   olen,u
         leay  obuf,u
         leay  d,y
wl1      lda   ,x+
         beq   wl2
         sta   ,y+
         inc   olen,u
         lda   olen,u
         cmpa  #250
         blo   wl1
         pshs  x
         lbsr  flush
         puls  x
         leay  obuf,u
         bra   wl1
wl2      lda   #C$CR
         sta   ,y+
         inc   olen,u
         lda   olen,u
         cmpa  #200
         blo   wl3
         lbsr  flush
wl3      rts

flush    ldb   olen,u
         beq   fl_9
         clra
         tfr   d,y
         lda   outp,u
         leax  obuf,u
         os9   I$Write
         clr   olen,u
fl_9     rts

* ------------------------------------------------------------------
* the main loop
process  lbsr  rdline
         lbcs  pr_end
         lbsr  skipping              A = 1 when the text is being skipped
         sta   tmp8b,u
         leax  line,u
pr1      lda   ,x
         cmpa  #' '
         beq   pr_sp
         cmpa  #9
         bne   pr2
pr_sp    leax  1,x
         bra   pr1
pr2      cmpa  #'#'
         bne   pr_text
         lbsr  directive
         leax  nulstr,pcr
         bra   pr_nl
pr_text  tst   tmp8b,u
         bne   pr_blank
         leax  line,u
         leay  out,u
         sty   dp,u
         leay  out+MAXLN,u
         sty   dlim,u
         clr   edepth,u
         lbsr  expand
         ldy   dp,u
         clr   ,y
         leax  out,u
         lbsr  wrline
         bra   pr_ex
pr_blank leax  nulstr,pcr
pr_nl    lbsr  wrline
pr_ex    ldb   extra,u
         beq   process
pr_e1    pshs  b
         leax  nulstr,pcr
         lbsr  wrline
         puls  b
         decb
         bne   pr_e1
         bra   process
pr_end   rts

* A = 1 when inside a conditional that is not active
skipping ldb   csp,u
         beq   sk0
         decb
         leay  cstack,u
         lda   b,y
         anda  #1
         eora  #1
         rts
sk0      clra
         rts

* a directive line was assembled in `line` by the caller (-D): process it
dirline  leax  line,u
         lbra  directive

* ------------------------------------------------------------------
* helpers on identifiers
isid1    cmpa  #'_'                  carry clear if A can start an identifier
         beq   id_y
         cmpa  #'A'
         blo   id_n
         cmpa  #'Z'
         bls   id_y
         cmpa  #'a'
         blo   id_n
         cmpa  #'z'
         bhi   id_n
id_y     andcc #$FE
         rts
id_n     orcc  #1
         rts

isid     cmpa  #'0'                  carry clear if A can be in an identifier
         blo   id_n
         cmpa  #'9'
         bls   id_y
         bra   isid1

* X -> source; the identifier is copied to `ident` (31 characters at most), ilen = its length; X advances
getident leay  ident,u
         clr   ilen,u
gi1      lda   ,x
         lbsr  isid
         bcs   gi9
         ldb   ilen,u
         cmpb  #31
         bhs   gi2
         sta   ,y+
         inc   ilen,u
gi2      leax  1,x
         bra   gi1
gi9      clr   ,y
         rts

* Y = bucket of `ident`
hashid   leax  ident,u
         clrb
hs1      lda   ,x+
         beq   hs2
         pshs  a
         addb  ,s+
         bra   hs1
hs2      andb  #$3F
         clra
         aslb
         rola
         leay  htab,u
         leay  d,y
         rts

* find the macro `ident`: X = entry, carry set if there is none
lookup   lbsr  hashid
         ldx   ,y
lk1      cmpx  #0
         beq   lk_no
         lda   2,x
         bita  #4
         bne   lk_next
         lda   4,x
         cmpa  ilen,u
         bne   lk_next
         leay  6,x
         pshs  x
         leax  ident,u
         ldb   ilen,u
lk2      lda   ,x+
         cmpa  ,y+
         bne   lk3
         decb
         bne   lk2
         puls  x
         andcc #$FE
         rts
lk3      puls  x
lk_next  ldx   ,x
         bra   lk1
lk_no    orcc  #1
         rts

* ------------------------------------------------------------------
* macro definition: X -> the text behind "define"
do_define lbsr skipsp
         lda   ,x
         lbsr  isid1
         lbcs  df_end
         lbsr  getident
         pshs  x
         lbsr  hashid                Y = bucket
         puls  x
         pshs  y
         ldy   hp,u                  header at hp
         sty   tmp16,u
         leay  heapend,u
         pshs  y
         ldy   hp,u
         leay  6,y
         tfr   y,d
         addb  ilen,u
         adca  #0
         cmpd  ,s++
         lbhs  df_mem
         ldy   tmp16,u
         ldd   [,s]                  old head of the bucket
         std   ,y
         clr   2,y
         clr   3,y
         lda   ilen,u
         sta   4,y
         clr   5,y
         leay  6,y
         pshs  x
         leax  ident,u
         ldb   ilen,u
df1      lda   ,x+
         sta   ,y+
         decb
         bne   df1
         puls  x
         clr   nparam,u
         lda   ,x                    '(' right behind the name: a function-like macro
         cmpa  #'('
         bne   df_body
         pshs  y
         ldy   tmp16,u
         lda   #1
         sta   2,y
         puls  y
         leax  1,x
         lbsr  skipsp
         lda   ,x
         cmpa  #')'
         bne   df_p1
         leax  1,x
         bra   df_body
df_p1    lbsr  skipsp
         lda   ,x
         lbsr  isid1
         lbcs  df_end
         pshs  y                     getident clobbers Y (the heap pointer)
         lbsr  getident
         puls  y
         ldb   nparam,u
         cmpb  #8
         bhs   df_p3
         lda   #40
         mul
         pshs  x
         leax  pnames,u
         leax  d,x
         pshs  y
         leay  ident,u
df_p2    lda   ,y+
         sta   ,x+
         bne   df_p2
         puls  y
         puls  x
         inc   nparam,u
df_p3    lbsr  skipsp
         lda   ,x+
         cmpa  #','
         beq   df_p1
         cmpa  #')'
         lbne  df_end
df_body  pshs  y
         ldy   tmp16,u
         lda   nparam,u
         sta   3,y
         puls  y
         lbsr  skipsp
         pshs  y                     start of the body
* copy the body: parameters become the markers 1..8, strings stay as they are
df_b1    lda   ,x
         lbeq  df_b9
         cmpa  #'#'
         lbeq  df_hash
         cmpa  #QUOT
         lbeq   df_bs
         cmpa  #APOS
         lbeq   df_bs
         lbsr  isid1
         bcs   df_bc
         pshs  y
         lbsr  getident
         puls  y
         tst   nparam,u
         beq   df_bi
         pshs  x,y
         lbsr  parmidx               B = marker or 0
         puls  x,y
         tstb
         beq   df_bi
         stb   ,y+
         bra   df_b1
df_bi    pshs  x
         leax  ident,u
df_bi2   lda   ,x+
         beq   df_bi3
         sta   ,y+
         bra   df_bi2
df_bi3   puls  x
         bra   df_b1
df_bc    sta   ,y+
         leax  1,x
         bra   df_b1
* # in a body: ## = marker 30 (the blanks around it go), # param = marker 16 + number, else the character itself
df_hash  leax  1,x
         lda   ,x
         cmpa  #'#'
         bne   df_h1
         leax  1,x
df_ht    cmpy  ,s
         bls   df_h0
         lda   -1,y
         cmpa  #' '
         bne   df_h0
         leay  -1,y
         bra   df_ht
df_h0    lbsr  skipsp
         lda   #30
         sta   ,y+
         lbra  df_b1
df_h1    lbsr  skipsp
         tst   nparam,u
         beq   df_hc
         lda   ,x
         lbsr  isid1
         bcs   df_hc
         pshs  y
         lbsr  getident
         puls  y
         pshs  x,y
         lbsr  parmidx
         puls  x,y
         tstb
         beq   df_hb
         addb  #16
         stb   ,y+
         lbra  df_b1
df_hb    lda   #'#'
         sta   ,y+
         lbra  df_bi
df_hc    lda   #'#'
         sta   ,y+
         lbra  df_b1
df_bs    sta   tmp8,u                a string or character constant
         sta   ,y+
         leax  1,x
df_bs1   lda   ,x
         lbeq  df_b1
         sta   ,y+
         leax  1,x
         cmpa  #BSL
         bne   df_bs2
         lda   ,x
         lbeq  df_b1
         sta   ,y+
         leax  1,x
         bra   df_bs1
df_bs2   cmpa  tmp8,u
         bne   df_bs1
         lbra  df_b1
df_b9    puls  x                     X = start of the body, Y = end: drop trailing blanks
         stx   tmp16b,u
df_t1    cmpy  tmp16b,u
         bls   df_t2
         lda   -1,y
         cmpa  #' '
         bne   df_t2
         leay  -1,y
         bra   df_t1
df_t2    tfr   y,d
         pshs  x
         subd  ,s++
         ldx   tmp16,u
         stb   5,x                   body length
         sty   hp,u
         puls  y                     the bucket
         stx   ,y
df_end   rts
df_mem   leas  2,s                   (bucket)
         leax  msgmem,pcr
         lbra  report

* the identifier `ident` is parameter number B-1? -> B = 1..8 or 0 (flags set accordingly)
parmidx  clrb
         pshs  b
pm1      ldb   ,s
         cmpb  nparam,u
         bhs   pm_no
         lda   #40
         mul
         leax  pnames,u
         leax  d,x
         leay  ident,u
pm2      lda   ,x+
         cmpa  ,y+
         bne   pm3
         tsta
         bne   pm2
         ldb   ,s+
         incb
         rts
pm3      inc   ,s
         bra   pm1
pm_no    leas  1,s
         clrb
         rts

skipsp   lda   ,x
         cmpa  #' '
         beq   ss1
         cmpa  #9
         bne   ss9
ss1      leax  1,x
         bra   skipsp
ss9      rts

* #undef
do_undef lbsr  skipsp
         lda   ,x
         lbsr  isid1
         bcs   ud9
         lbsr  getident
         lbsr  lookup
         bcs   ud9
         lda   2,x
         ora   #4
         sta   2,x
ud9      rts

* ------------------------------------------------------------------
* macro expansion: X -> source (NUL terminated); the result is appended at dp
expand   lda   ,x
         lbeq  ex9
         cmpa  #QUOT
         lbeq  ex_str
         cmpa  #APOS
         lbeq  ex_str
         lbsr  isid1
         bcc   ex_id
         cmpa  #'0'
         blo   ex_cp
         cmpa  #'9'
         bhi   ex_cp
ex_num   lbsr  putd
         leax  1,x
         lda   ,x
         lbsr  isid
         bcc   ex_num
         bra   expand
ex_cp    lbsr  putd
         leax  1,x
         bra   expand
ex_str   sta   tmp8,u
         lbsr  putd
         leax  1,x
ex_s1    lda   ,x
         lbeq   ex9
         lbsr  putd
         leax  1,x
         cmpa  #BSL
         bne   ex_s2
         lda   ,x
         lbeq   ex9
         lbsr  putd
         leax  1,x
         bra   ex_s1
ex_s2    cmpa  tmp8,u
         bne   ex_s1
         bra   expand
ex_id    lbsr  getident
         pshs  x                     the text behind the name
         lbsr  lookup
         bcs   ex_plain
         lda   2,x
         bita  #2
         bne   ex_plain              being expanded: leave it alone
         ldb   edepth,u
         cmpb  #7
         bhs   ex_plain
         bita  #1
         beq   ex_obj
* function-like: needs "(" behind the name
         pshs  x
         ldx   2,s
         lbsr  skipsp
         lda   ,x
         cmpa  #'('
         beq   ex_f1
         puls  x
         bra   ex_plain
ex_f1    lbsr  getargs               X behind the ")"
         stx   2,s                   new source position
         lbsr  prescan               the arguments are expanded first
         puls  x                     the macro entry
         lbsr  build_f
         bra   ex_run
ex_obj   lbsr  build_o
ex_run   pshs  x
         lda   2,x
         ora   #2
         sta   2,x
         inc   edepth,u
         ldx   tmpoff_x,u
         lbsr  expand
         dec   edepth,u
         puls  x
         lda   2,x
         anda  #$FD
         sta   2,x
         puls  x
         lbra  expand
ex_plain leax  ident,u
ex_pl1   lda   ,x+
         beq   ex_pl2
         lbsr  putd
         bra   ex_pl1
ex_pl2   puls  x
         lbra  expand
ex9      rts

* A -> destination at dp (if there is room)
putd     pshs  x,y
         ldy   dp,u
         cmpy  dlim,u
         bhs   pd9
         sta   ,y+
         sty   dp,u
pd9      puls  x,y
         rts

* address of the replacement buffer of the current depth -> tmpoff_x (variable) and Y
bufaddr  ldb   edepth,u
         clra
         aslb
         rola
         leax  tmpoff,pcr
         ldd   d,x
         leay  tmpb,u
         leay  d,y
         rts

* object-like macro: copy the body (entry in X) into the buffer of the current depth
build_o  pshs  x
         lbsr  bufaddr
         sty   tmpoff_x,u
         puls  x
         pshs  x
         ldb   5,x
         leay  6,x
         clra
         ldb   4,x
         leay  d,y                   Y = body
         ldb   5,x
         tfr   y,x
         ldy   tmpoff_x,u
         tstb
         beq   bo2
bo1      lda   ,x+
         sta   ,y+
         decb
         bne   bo1
bo2      clr   ,y
         puls  x                     the entry again
         rts

* D = offset of the argument block of the current expansion depth (X and Y are kept)
argoffs  pshs  x
         ldb   edepth,u
         clra
         aslb
         rola
         leax  argoff,pcr
         ldd   d,x
         puls  x,pc

* A = argument number -> X = its text
argptr   ldb   #130
         mul
         pshs  d
         lbsr  argoffs
         addd  ,s++
         leax  argb,u
         leax  d,x
         rts

* expand every collected argument of the current depth in place (blanks at both ends are dropped); the
* expansion of an argument runs one depth deeper, its result is built in the buffer of this depth
prescan  ldx   dp,u
         ldy   dlim,u
         pshs  x,y
         clrb
         pshs  b                     argument number
ps1      ldb   ,s
         cmpb  nargs,u
         lbhs   ps9
         lbsr  bufaddr               Y = scratch
         sty   dp,u
         leay  510,y
         sty   dlim,u
         lda   ,s
         lbsr  argptr
         pshs  x
         leay  8320,x                keep the argument as written (without the blanks at both ends)
ps0a     lda   ,x
         cmpa  #' '
         bne   ps0
         leax  1,x
         bra   ps0a
ps0      lda   ,x+
         sta   ,y+
         bne   ps0
         leay  -2,y
         ldx   ,s
         leax  8320,x
ps0t     pshs  x
         cmpy  ,s++
         blo   ps0e
         lda   ,y
         cmpa  #' '
         bne   ps0e
         clr   ,y
         leay  -1,y
         bra   ps0t
ps0e     puls  x
         inc   edepth,u
         lbsr  expand
         dec   edepth,u
         ldx   dp,u
         clr   ,x
         lbsr  bufaddr
         tfr   y,x
         lbsr  skipsp
         pshs  x
         lda   2,s
         lbsr  argptr
         tfr   x,y                   Y = destination
         puls  x
         ldb   #129
ps2      lda   ,x+
         beq   ps3
         sta   ,y+
         decb
         bne   ps2
ps3      pshs  y
         lda   2,s
         lbsr  argptr
         stx   tmp16b,u
         puls  y
ps4      cmpy  tmp16b,u
         bls   ps5
         lda   -1,y
         cmpa  #' '
         bne   ps5
         leay  -1,y
         bra   ps4
ps5      clr   ,y
         inc   ,s
         lbra   ps1
ps9      leas  1,s
         puls  x,y
         stx   dp,u
         sty   dlim,u
         rts

* function-like macro: copy the body into the buffer replacing the markers by the arguments
build_f  clr   pastef,u
         pshs  x
         lbsr  bufaddr
         sty   tmpoff_x,u
         puls  x
         pshs  x
         clra
         ldb   4,x
         leay  6,x
         leay  d,y
         ldb   5,x
         tfr   y,x
         ldy   tmpoff_x,u
         tstb
         lbeq   bf9
bf1      pshs  b
         ldb   pastef,u
         stb   tmp8b,u
         clr   pastef,u
         lda   ,x+
         cmpa  #30
         beq   bf_paste
         cmpa  #24
         lbhi   bf_c
         cmpa  #17
         bhs   bf_str
         cmpa  #8
         lbhi   bf_c
         tsta
         lbeq   bf_c
         pshs  x
         deca
         lbsr  argptr
         tst   tmp8b,u               after ##: the argument as written
         bne   bf_raw
         ldb   2,s                   the item behind the marker is ##: as written too
         cmpb  #1
         bls   bf2
         lda   [,s]
         cmpa  #30
         bne   bf2
bf_raw   leax  8320,x
bf2      lda   ,x+
         beq   bf3
         sta   ,y+
         bra   bf2
bf3      puls  x
         lbra   bf_n
bf_paste cmpy  tmpoff_x,u            ## : drop the blanks before it, the next item is taken as written
         bls   bp2
         lda   -1,y
         cmpa  #' '
         bne   bp2
         leay  -1,y
         bra   bf_paste
bp2      lda   #1
         sta   pastef,u
         bra   bf_n
* # param : the argument as written, as a string constant
bf_str   suba  #17
         pshs  x
         lbsr  argptr
         leax  8320,x
         lda   #QUOT
         sta   ,y+
         clr   tmp8,u
bs0      lda   ,x
         cmpa  #' '
         bne   bs1
         leax  1,x
         bra   bs0
bs1      lda   ,x+
         beq   bs9
         ldb   tmp8,u
         bne   bs2
         cmpa  #QUOT
         beq   bs_o
         cmpa  #APOS
         bne   bs4
bs_o     sta   tmp8,u
         bra   bs3
bs2      cmpa  #BSL
         bne   bs2a
         lda   #BSL
         sta   ,y+
         sta   ,y+
         lda   ,x+
         beq   bs9
         bra   bs3
bs2a     cmpa  tmp8,u
         bne   bs3
         clr   tmp8,u
bs3      cmpa  #QUOT
         beq   bs_e
         cmpa  #BSL
         bne   bs4
bs_e     pshs  a
         lda   #BSL
         sta   ,y+
         puls  a
bs4      sta   ,y+
         bra   bs1
bs9      tst   tmp8,u
         bne   bs10
bs8      lda   -1,y
         cmpa  #' '
         bne   bs10
         leay  -1,y
         bra   bs8
bs10     lda   #QUOT
         sta   ,y+
         puls  x
         bra   bf_n
bf_c     sta   ,y+
bf_n     puls  b
         decb
         lbne  bf1
bf9      clr   ,y
         puls  x
         rts

* collect the arguments: X -> "(" ; the arguments go to argb (130 bytes each), nargs = their number; X ends behind ")"
getargs  leax  1,x
         clr   nargs,u
         lbsr  argoffs
         leay  argb,u
         leay  d,y
         ldb   #1
         stb   tmp8b,u               paren depth
ga1      lda   ,x
         lbeq  ga_end
         cmpa  #QUOT
         beq   ga_s
         cmpa  #APOS
         beq   ga_s
         cmpa  #'('
         bne   ga2
         inc   tmp8b,u
         bra   ga_c
ga2      cmpa  #')'
         bne   ga3
         dec   tmp8b,u
         beq   ga_close
         bra   ga_c
ga3      cmpa  #','
         bne   ga_c
         ldb   tmp8b,u
         cmpb  #1
         bne   ga_c
         clr   ,y
         inc   nargs,u
         lda   nargs,u
         ldb   #130
         mul
         pshs  d
         lbsr  argoffs
         addd  ,s++
         leay  argb,u
         leay  d,y
         leax  1,x
         bra   ga1
ga_c     sta   ,y+
         leax  1,x
         bra   ga1
ga_s     sta   tmp8,u
         sta   ,y+
         leax  1,x
ga_s1    lda   ,x
         beq   ga_end
         sta   ,y+
         leax  1,x
         cmpa  #BSL
         bne   ga_s2
         lda   ,x
         beq   ga_end
         sta   ,y+
         leax  1,x
         bra   ga_s1
ga_s2    cmpa  tmp8,u
         bne   ga_s1
         bra   ga1
ga_close leax  1,x
ga_end   clr   ,y
         inc   nargs,u
         rts

* ------------------------------------------------------------------
* directives: X -> '#'
directive leax 1,x
         lbsr  skipsp
         leay  word,u
         ldb   #0
dw1      lda   ,x
         cmpa  #'a'
         blo   dw2
         cmpa  #'z'
         bhi   dw2
         cmpb  #10
         bhs   dw3
         sta   ,y+
         incb
dw3      leax  1,x
         bra   dw1
dw2      clr   ,y
         stx   tmp16,u               the rest of the line
         leay  d_if,pcr
         lbsr  cmpword
         lbeq  d_doif
         leay  d_ifdef,pcr
         lbsr  cmpword
         lbeq  d_doifdef
         leay  d_ifndef,pcr
         lbsr  cmpword
         lbeq  d_doifndef
         leay  d_elif,pcr
         lbsr  cmpword
         lbeq  d_doelif
         leay  d_else,pcr
         lbsr  cmpword
         lbeq  d_doelse
         leay  d_endif,pcr
         lbsr  cmpword
         lbeq  d_doendif
         lbsr  skipping
         tsta
         bne   d_ret
         ldx   tmp16,u
         leay  d_define,pcr
         lbsr  cmpword
         bne   d_n1
         ldx   tmp16,u
         lbra  do_define
d_n1     leay  d_undef,pcr
         lbsr  cmpword
         bne   d_n2
         ldx   tmp16,u
         lbra  do_undef
d_n2     leay  d_include,pcr
         lbsr  cmpword
         bne   d_n3
         ldx   tmp16,u
         lbra  do_include
d_n3     leay  d_error,pcr
         lbsr  cmpword
         bne   d_ret
         leax  msgerr,pcr
         lbsr  report
         ldx   tmp16,u
         lbsr  skipsp
         lbra  report2
d_ret    leax  nulstr,pcr
         rts

* Y -> a NUL terminated keyword: Z set if `word` equals it
cmpword  leax  word,u
cw1      lda   ,y+
         cmpa  ,x+
         bne   cw_no
         tsta
         bne   cw1
         clra                        Z set
         rts
cw_no    lda   #1
         rts

d_if     fcc   "if"
         fcb   0
d_ifdef  fcc   "ifdef"
         fcb   0
d_ifndef fcc   "ifndef"
         fcb   0
d_elif   fcc   "elif"
         fcb   0
d_else   fcc   "else"
         fcb   0
d_endif  fcc   "endif"
         fcb   0
d_define fcc   "define"
         fcb   0
d_undef  fcc   "undef"
         fcb   0
d_include fcc  "include"
         fcb   0
d_error  fcc   "error"
         fcb   0

* the directive keeps its caller's X: after a directive the main loop writes an empty line
dirdone  leax  nulstr,pcr
         rts

* --- conditionals.  A stack byte: bit0 = this branch is active, bit1 = a branch was taken, bit2 = the enclosing text is active
cpush    sta   tmp8,u                A = condition (0/1)
         ldb   csp,u
         cmpb  #20
         bhs   cp9
         lbsr  skipping
         tsta
         bne   cp_in                 the enclosing text is skipped
         lda   #4
         ldb   tmp8,u
         beq   cp1
         ora   #3
cp1      bra   cp2
cp_in    lda   #2
cp2      ldb   csp,u
         leay  cstack,u
         sta   b,y
         inc   csp,u
cp9      rts

d_doifdef lbsr skipping
         tsta
         bne   d_pushf
         ldx   tmp16,u
         lbsr  skipsp
         lbsr  getident
         lbsr  lookup
         bcs   d_pushf
         lda   #1
         lbsr  cpush
         lbra   dirdone
d_pushf  clra
         lbsr  cpush
         lbra   dirdone
d_doifndef lbsr skipping
         tsta
         bne   d_pushf
         ldx   tmp16,u
         lbsr  skipsp
         lbsr  getident
         lbsr  lookup
         bcc   d_pushf
         lda   #1
         lbsr  cpush
         lbra   dirdone
d_doif   lbsr  skipping
         tsta
         bne   d_pushf
         ldx   tmp16,u
         lbsr  evalif
         ldd   tmp16b,u
         beq   d_pushf
         lda   #1
         lbsr  cpush
         lbra   dirdone
d_doelif ldb   csp,u
         lbeq   dirdone
         decb
         leay  cstack,u
         lda   b,y
         bita  #4
         lbeq   dirdone               enclosing text is skipped
         bita  #2
         beq   de_ev
         anda  #$FE                  already taken: stays inactive
         sta   b,y
         lbra   dirdone
de_ev    pshs  b
         ldx   tmp16,u
         lbsr  evalif
         puls  b
         leay  cstack,u
         lda   b,y
         ldx   tmp16b,u
         cmpx  #0
         beq   de_no
         ora   #3
         sta   b,y
         lbra   dirdone
de_no    anda  #$FE
         sta   b,y
         lbra   dirdone
d_doelse ldb   csp,u
         lbeq   dirdone
         decb
         leay  cstack,u
         lda   b,y
         bita  #4
         lbeq   dirdone
         bita  #2
         beq   dl1
         anda  #$FE
         sta   b,y
         lbra   dirdone
dl1      ora   #3
         sta   b,y
         lbra   dirdone
d_doendif ldb  csp,u
         lbeq   dirdone
         dec   csp,u
         lbra   dirdone

* ------------------------------------------------------------------
* #include
do_include lbsr skipsp
         lda   ,x+
         ldb   #QUOT
         cmpa  #QUOT
         beq   in1
         cmpa  #'<'
         lbne  dirdone
         ldb   #'>'
in1      stb   tmp8,u                closing character
         pshs  a
         leay  word,u
in2      lda   ,x+
         beq   in3
         cmpa  tmp8,u
         beq   in3
         sta   ,y+
         bra   in2
in3      clr   ,y
         puls  a
         cmpa  #QUOT
         bne   in_ang
         leax  word,u                "name": the current directory first
         lbsr  tryopen
         bcc   in_ok
in_ang   clr   tmp8b,u
in4      ldb   tmp8b,u
         cmpb  ninc,u
         bhs   in5
         lbsr  tryinc
         bcc   in_ok
         inc   tmp8b,u
         bra   in4
in5      leax  word,u                <name>: the plain name last
         lbsr  tryopen
         bcc   in_ok
         leax  msginc,pcr
         lbsr  report
         leax  word,u
         lbsr  report2
         lbra  dirdone
in_ok    ldb   idepth,u
         cmpb  #3
         bhs   in_full
         inc   idepth,u
         pshs  a
         ldx   ifp,u
         leax  IFSZ,x
         stx   ifp,u
         puls  a
         lbsr  initfile
in_full  lbra  dirdone

* X -> path (NUL terminated) -> I$Open: A = path, carry set on failure
tryopen  leay  pbuf,u
to1      lda   ,x+
         sta   ,y+
         bne   to1
         lda   #C$CR
         sta   -1,y
         leax  pbuf,u
         lda   #READ.
         os9   I$Open
         rts

* include directory number tmp8b + "/" + word
tryinc   lda   #48
         mul
         leax  incdirs,u
         leax  d,x
         leay  pbuf,u
ti1      lda   ,x+
         beq   ti2
         sta   ,y+
         bra   ti1
ti2      lda   #'/'
         sta   ,y+
         leax  word,u
ti3      lda   ,x+
         sta   ,y+
         bne   ti3
         lda   #C$CR
         sta   -1,y
         leax  pbuf,u
         lda   #READ.
         os9   I$Open
         rts

* ------------------------------------------------------------------
* #if expressions.  X -> the expression text.  The value goes to tmp16b.
evalif   leay  out,u                 first: "defined X" / "defined(X)" become 1 or 0
         sty   dp,u
         leay  out+MAXLN,u
         sty   dlim,u
ev1      lda   ,x
         lbeq  ev_x
         lbsr  isid1
         bcs   ev_o
         lbsr  getident
         pshs  x
         lbsr  isdef                 Z set if ident is "defined"
         puls  x
         bne   ev_cp
         lbsr  skipsp                the operand
         lda   ,x
         ldb   #0
         cmpa  #'('
         bne   ev_d1
         incb
         leax  1,x
         lbsr  skipsp
ev_d1    pshs  b
         lbsr  getident
         pshs  x                     lookup returns the entry in X
         lbsr  lookup
         puls  x
         bcs   ev_d2
         lda   #'1'
         bra   ev_d3
ev_d2    lda   #'0'
ev_d3    lbsr  putd
         puls  b
         tstb
         beq   ev1
         lbsr  skipsp
         lda   ,x
         cmpa  #')'
         bne   ev1
         leax  1,x
         bra   ev1
ev_cp    pshs  x
         leax  ident,u
ev_c2    lda   ,x+
         beq   ev_c3
         lbsr  putd
         bra   ev_c2
ev_c3    puls  x
         bra   ev1
ev_o     lbsr  putd
         leax  1,x
         bra   ev1
ev_x     ldy   dp,u
         clr   ,y
         leax  out,u                 then the macros are expanded
         leay  line,u
         sty   dp,u
         leay  line+MAXLN,u
         sty   dlim,u
         clr   edepth,u
         lbsr  expand
         ldy   dp,u
         clr   ,y
         leax  line,u
         stx   ep,u
         lbsr  ev_top
         std   tmp16b,u
         rts

d_defined fcc  "defined"
         fcb   0

* Z set if `ident` is the word "defined"
isdef    leay  d_defined,pcr
         leax  ident,u
isd1     lda   ,y+
         cmpa  ,x+
         bne   isd_no
         tsta
         bne   isd1
         clra
         rts
isd_no   lda   #1
         rts

* --- the expression parser: ep -> text; value in D
ev_skip  ldx   ep,u
ev_s1    lda   ,x
         cmpa  #' '
         beq   ev_s2
         cmpa  #9
         bne   ev_s3
ev_s2    leax  1,x
         bra   ev_s1
ev_s3    stx   ep,u
         rts

ev_top   lda   #1
         lbsr  ev_lvl
         pshs  d
         lbsr  ev_skip
         lda   ,x
         cmpa  #'?'
         bne   et9
         leax  1,x
         stx   ep,u
         lbsr  ev_top
         pshs  d
         lbsr  ev_skip
         lda   ,x
         cmpa  #':'
         bne   et_bad
         leax  1,x
         stx   ep,u
         lbsr  ev_top
         tfr   d,x
         puls  d
         std   tmp16,u
         puls  d
         cmpd  #0
         beq   et_f
         ldd   tmp16,u
         rts
et_f     tfr   x,d
         rts
et_bad   leas  4,s
         ldd   #0
         rts
et9      puls  d
         rts

* A = level 1..10 (binary operators), 11 = unary
ev_lvl   cmpa  #11
         lbeq  ev_un
         pshs  a
         inca
         lbsr  ev_lvl
el1      pshs  d
         lda   2,s
         lbsr  ev_matchop
         tstb
         beq   el_done
         pshs  b
         lda   3,s
         inca
         lbsr  ev_lvl
         tfr   d,x
         clra
         puls  b
         tfr   d,y                   Y = the operator id
         puls  d
         lbsr  ev_apply
         bra   el1
el_done  puls  d
         leas  1,s
         rts

* operator table: level, char1, char2, id
optab    fcb   1,'|','|',1
         fcb   2,'&','&',2
         fcb   6,'=','=',6
         fcb   6,'!','=',7
         fcb   7,'<','=',8
         fcb   7,'>','=',9
         fcb   8,'<','<',12
         fcb   8,'>','>',13
         fcb   3,'|',0,3
         fcb   4,'^',0,4
         fcb   5,'&',0,5
         fcb   7,'<',0,10
         fcb   7,'>',0,11
         fcb   9,'+',0,14
         fcb   9,'-',0,15
         fcb   10,'*',0,16
         fcb   10,'/',0,17
         fcb   10,'%',0,18
         fcb   0

* the operator at ep, if it has level A: B = its id and ep moves behind it; else B = 0
ev_matchop sta tmp8,u
         lbsr  ev_skip
         leay  optab,pcr
mo1      lda   ,y
         beq   mo_no
         lda   1,y
         cmpa  ,x
         bne   mo_next
         lda   2,y
         beq   mo_one
         cmpa  1,x
         bne   mo_next
         ldb   #2
         bra   mo_hit
mo_one   ldb   #1
mo_hit   lda   ,y
         cmpa  tmp8,u
         bne   mo_no
         abx
         stx   ep,u
         ldb   3,y
         rts
mo_next  leay  4,y
         bra   mo1
mo_no    clrb
         rts

* D = D op X ; Y = operator id
ev_apply cmpy  #1
         bne   ap2
         cmpd  #0
         lbne   ap_t
         cmpx  #0
         lbne   ap_t
         lbra   ap_f
ap2      cmpy  #2
         bne   ap3
         cmpd  #0
         lbeq   ap_f
         cmpx  #0
         lbeq   ap_f
         lbra   ap_t
ap3      cmpy  #3
         bne   ap4
         pshs  x
         ora   ,s+
         orb   ,s+
         rts
ap4      cmpy  #4
         bne   ap5
         pshs  x
         eora  ,s+
         eorb  ,s+
         rts
ap5      cmpy  #5
         bne   ap6
         pshs  x
         anda  ,s+
         andb  ,s+
         rts
ap6      cmpy  #6
         bne   ap7
         pshs  x
         cmpd  ,s++
         lbeq   ap_t
         lbra   ap_f
ap7      cmpy  #7
         bne   ap8
         pshs  x
         cmpd  ,s++
         lbne   ap_t
         lbra   ap_f
ap8      cmpy  #8
         bne   ap9
         pshs  x
         cmpd  ,s++
         lble   ap_t
         lbra   ap_f
ap9      cmpy  #9
         bne   ap10
         pshs  x
         cmpd  ,s++
         lbge   ap_t
         lbra   ap_f
ap10     cmpy  #10
         bne   ap11
         pshs  x
         cmpd  ,s++
         lblt   ap_t
         lbra   ap_f
ap11     cmpy  #11
         bne   ap12
         pshs  x
         cmpd  ,s++
         lbgt   ap_t
         lbra   ap_f
ap12     cmpy  #12
         bne   ap13
         stx   tmp16,u
         ldx   tmp16,u
ap12a    cmpx  #0
         beq   ap_r
         lslb
         rola
         leax  -1,x
         bra   ap12a
ap13     cmpy  #13
         bne   ap14
ap13a    cmpx  #0
         beq   ap_r
         asra
         rorb
         leax  -1,x
         bra   ap13a
ap14     cmpy  #14
         bne   ap15
         pshs  x
         addd  ,s++
         rts
ap15     cmpy  #15
         bne   ap16
         pshs  x
         subd  ,s++
         rts
ap16     cmpy  #16
         bne   ap17
         lbra  mul16
ap17     lbra  div16
ap_t     ldd   #1
         rts
ap_f     ldd   #0
ap_r     rts

mul16    std   tmp16,u
         stx   mulr,u
         ldd   #0
         ldy   #16
m1       lsr   mulr,u
         ror   mulr+1,u
         bcc   m2
         addd  tmp16,u
m2       asl   tmp16+1,u
         rol   tmp16,u
         leay  -1,y
         bne   m1
         rts

* signed division: B = 17 quotient, 18 remainder
div16    pshs  y                     the operator id: 17 quotient, 18 remainder
         clr   tmp8b,u               bit0: negate the result, bit1: the dividend was negative
         cmpd  #0
         bge   dv1
         coma
         comb
         addd  #1
         pshs  d
         lda   tmp8b,u
         ora   #3
         sta   tmp8b,u
         puls  d
dv1      pshs  d
         tfr   x,d
         cmpd  #0
         bge   dv2
         coma
         comb
         addd  #1
         tfr   d,x
         lda   tmp8b,u
         eora  #1
         sta   tmp8b,u
dv2      cmpx  #0
         bne   dv3
         leas  4,s
         ldd   #0
         rts
dv3      puls  d
         std   tmp16,u
         stx   mulr,u
         ldd   #0
         ldy   #16
dv4      asl   tmp16+1,u
         rol   tmp16,u
         rolb
         rola
         cmpd  mulr,u
         blo   dv5
         subd  mulr,u
         inc   tmp16+1,u
dv5      leay  -1,y
         bne   dv4
         tfr   d,x                   remainder
         ldb   1,s
         leas  2,s
         cmpb  #18
         bne   dv6
         tfr   x,d
         pshs  d
         lda   tmp8b,u
         bita  #2
         puls  d
         beq   dv_r
         bra   dv_neg
dv6      ldd   tmp16,u
         pshs  d
         lda   tmp8b,u
         bita  #1
         puls  d
         beq   dv_r
dv_neg   coma
         comb
         addd  #1
dv_r     rts

* the operand: unary operators, parentheses, numbers, character constants, names (value 0)
ev_un    lbsr  ev_skip
         lda   ,x
         cmpa  #'-'
         bne   un1
         leax  1,x
         stx   ep,u
         lbsr  ev_un
         coma
         comb
         addd  #1
         rts
un1      cmpa  #'+'
         bne   un2
         leax  1,x
         stx   ep,u
         lbra  ev_un
un2      cmpa  #'!'
         bne   un3
         leax  1,x
         stx   ep,u
         lbsr  ev_un
         cmpd  #0
         lbeq   ap_t
         lbra   ap_f
un3      cmpa  #'~'
         bne   un4
         leax  1,x
         stx   ep,u
         lbsr  ev_un
         coma
         comb
         rts
un4      cmpa  #'('
         bne   un5
         leax  1,x
         stx   ep,u
         lbsr  ev_top
         pshs  d
         lbsr  ev_skip
         lda   ,x
         cmpa  #')'
         bne   un4a
         leax  1,x
         stx   ep,u
un4a     puls  d
         rts
un5      cmpa  #APOS
         bne   un6
         leax  1,x
         lda   ,x+
         cmpa  #BSL
         bne   un5a
         lda   ,x+
         cmpa  #'n'
         bne   un5a
         lda   #10
un5a     tfr   a,b
         clra
         pshs  d
un5b     lda   ,x+
         beq   un5c
         cmpa  #APOS
         bne   un5b
un5c     stx   ep,u
         puls  d
         rts
un6      cmpa  #'0'
         blo   un8
         cmpa  #'9'
         bhi   un8
         ldy   #10                   a number: decimal, 0x hex or 0 octal
         cmpa  #'0'
         bne   un7
         ldy   #8
         lda   1,x
         anda  #$DF
         cmpa  #'X'
         bne   un7
         leax  2,x
         ldy   #16
un7      sty   ebase,u
         ldd   #0
un7a     pshs  d
         lda   ,x
         cmpa  #'0'
         blo   un7e
         cmpa  #'9'
         bls   un7b
         anda  #$DF
         cmpa  #'A'
         blo   un7e
         cmpa  #'F'
         bhi   un7e
         suba  #'A'-10-'0'
         adda  #'0'
         bra   un7b
un7b     suba  #'0'
         cmpa  ebase+1,u
         bhs   un7e
         sta   tmp8,u
         leax  1,x
         puls  d
         pshs  x
         ldx   ebase,u
         lbsr  mul16
         puls  x
         addb  tmp8,u
         adca  #0
         bra   un7a
un7e     puls  d
         pshs  d                     the suffixes L and U must not destroy the value
un7f     lda   ,x
         anda  #$DF
         cmpa  #'L'
         beq   un7g
         cmpa  #'U'
         bne   un7h
un7g     leax  1,x
         bra   un7f
un7h     stx   ep,u
         puls  d,pc
un8      lbsr  isid1                 a name that is not a macro: 0
         bcs   un9
         lbsr  getident
         stx   ep,u
         ldd   #0
         rts
un9      ldd   #0
         rts

         emod
eom      equ   *
         end
