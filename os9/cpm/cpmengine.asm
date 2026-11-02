* cpmengine.asm - the BDOS engine shared by cpm.asm and bdos.asm: the address calculation of the guest pointers, the BDOS
* functions, the files, the text conversion, the BIOS entries.  The guest memory is reached through rdsub / wrsub (cpm.asm:
* the sub CPU through the window; bdos.asm: the memory of the calling OS-9 program).

* lin = 00:D
setlin16 clr   lin,u
         std   lin+1,u
         rts

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
* opening files: the current data directory first, then the tool directory (-p=)
* pname = name (CR terminated), A = mode -> A = path, carry set if both fail (B = error)
openany  sta   tmp8b,u
         leax  pname,u
         os9   I$Open
         bcc   oa9
         tst   pfxlen,u
         bne   oaf
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
         fcc   "PAS"
         fcc   "INC"
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

* X = the name of the text file number B
tnx      leax  tnames,u
         decb
         beq   tn9
tn1      leax  11,x
         decb
         bne   tn1
tn9      rts

* BDOS 23: a program that has read a file and does not close it (Turbo Pascal) renames it next; an open path would keep
* OS-9 from reading and deleting it.  Close the open text file with the name of the FCB (its temporary copy is
* converted back first if it was changed).
rnclose  ldb   #1
rc1      pshs  b
         lbsr  tsx
         lda   2,x
         bpl   rc4
         ldb   ,s
         lbsr  tnx
         leay  fcb+F_NAME,u
         ldb   #11
rc2      lda   ,x+
         eora  ,y+
         anda  #$7F
         bne   rc4
         decb
         bne   rc2
         ldb   ,s
         lbsr  tcls
rc4      puls  b
         incb
         cmpb  #NT+1
         bne   rc1
         rts

* close the text file number B
tcls     pshs  b
         lbsr  tsx
         lda   2,x
         sta   cvfl,u
         lda   ,x
         sta   cvr,u
         lda   1,x
         sta   cvt,u
         clr   2,x
         lda   cvfl,u
         anda  #3
         cmpa  #3
         bne   tcl2
         lbsr  cvtout
tcl2     lda   cvt,u
         os9   I$Close
         ldb   ,s
         lbsr  tmpname
         lda   #UPDAT.
         leax  tname,u
         os9   I$Delete
         lda   cvr,u
         os9   I$Close
         puls  b
         rts

* X = entry for number B
tsx      leax  tslots,u
         decb
         beq   ts9
ts1      leax  4,x
         decb
         bne   ts1
ts9      rts

* A .BAS file is text only when it is an ASCII listing: the program SAVE of MBASIC writes the tokenized form, which starts
* with FFh (and has no line ends).  A new file is binary (the text is then not converted), an old one is looked at.
* Carry set: binary.
isbas    leax  fcb+F_EXT,u
         lda   ,x+
         anda  #$7F
         cmpa  #'B'
         bne   ib_txt
         lda   ,x+
         anda  #$7F
         cmpa  #'A'
         bne   ib_txt
         lda   ,x
         anda  #$7F
         cmpa  #'S'
         bne   ib_txt
         lda   tmp8b,u
         cmpa  #1
         bne   ib_bin                 a new file
         lda   fcb+F_PATH,u
         leax  iobuf,u
         ldy   #1
         os9   I$Read
         bcs   ib_txt
         lda   fcb+F_PATH,u
         ldx   #0                     back to the start
         pshs  u
         ldu   #0
         os9   I$Seek
         puls  u
         lda   iobuf,u
         cmpa  #$FF
         beq   ib_bin
ib_txt   andcc #$FE
         rts
ib_bin   orcc  #1
         rts

* the FCB just got a real path in F_PATH: if it is a text file, build the temporary CP/M form.
* tmp8b = 1 for an existing file (convert it), 2 for a new file.  Carry set: not made (the file stays binary).
mktslot  lbsr  istext
         lbcs  mt_no
         lbsr  isbas
         lbcs  mt_no
         lbsr  alloct
         lbcs  mt_no
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
         lbsr  tnx
         leay  fcb+F_NAME,u
         ldb   #11
mt1n     lda   ,y+
         sta   ,x+
         decb
         bne   mt1n
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
         cmpa  #$80
         lbhs  bios
         cmpa  #36
         bhi   dsp2
         leax  jtab,pcr
         ldb   func,u
         clra
         lslb
         rola
         ldd   d,x
         jmp   d,x
dsp2     cmpa  #37
         lbeq  f_nop                  reset drive: nothing to do
         cmpa  #40
         lbeq  f_wrrnd                write random with zero fill
         cmpa  #51
         lbeq  f_sdmab
         cmpa  #52
         lbeq  f_gdmab
         rts
jtab     fdb   f_boot-jtab,f_conin-jtab,f_conout-jtab,f_rdr-jtab,f_nop-jtab,f_nop-jtab,f_dio-jtab
         fdb   f_getio-jtab,f_setio-jtab,f_prstr-jtab,f_rdbuf-jtab,f_const-jtab,f_vers-jtab,f_reset-jtab
         fdb   f_seldsk-jtab,f_open-jtab,f_close-jtab,f_sfirst-jtab,f_snext-jtab,f_delete-jtab
         fdb   f_rdseq-jtab,f_wrseq-jtab,f_make-jtab,f_rename-jtab,f_login-jtab,f_curdsk-jtab
         fdb   f_sdma-jtab,f_alloc-jtab,f_nop-jtab,f_ro-jtab,f_sattr-jtab,f_dpb-jtab,f_user-jtab
         fdb   f_rdrnd-jtab,f_wrrnd-jtab,f_fsize-jtab,f_setrnd-jtab

f_nop    rts

* 3 reader input: nothing is there (end of file)
f_rdr    lda   #$1A
         sta   r_al,u
         lbra  retA

* 7 / 8 the IOBYTE
f_getio  lda   iobyte,u
         sta   r_al,u
         lbra  retA
f_setio  lda   parl,u
         sta   iobyte,u
         rts

* 31 the disk parameter block of the drive: a disk of 4 MB (2K blocks, 512 directory entries), at FD00h of the Z80
* (the Z80 programs read it: STAT).  HL = 0 for CP/M-86 and for the module bdos.
f_dpb    lda   subty,u
         cmpa  #1
         bne   dpb9
         tst   islib,u
         bne   dpb9
         ldd   #$FD00
         lbsr  setlin16
         leax  dpbtab,pcr
         ldy   #15
         lbsr  wrsub
         ldd   #$FD00
         sta   r_bh,u
         stb   r_bl,u
         stb   r_al,u
dpb9     rts
dpbtab   fcb   128,0                SPT: records per track (little endian: the Z80 reads it)
         fcb   4,15,1                BSH, BLM, EXM: blocks of 2K
         fcb   $FF,$07               DSM = 2047: 2048 blocks = 4 MB
         fcb   $FF,$01               DRM = 511: 512 directory entries
         fcb   $FF,$00               AL0, AL1: the first 8 blocks are the directory
         fcb   0,0                   CKS
         fcb   0,0                   OFF

* 27 the allocation vector of the drive: one bit per block of 2K, the blocks of the directory and of the files (counted
* from the sizes of the files in the directory of the drive, and put one behind the other from the start), at FD20h
f_alloc  lda   subty,u
         cmpa  #1
         lbne  fa_no
         tst   islib,u
         lbne  fa_no
         clr   fcb+F_DR,u            the current drive
         ldd   #8                    the directory
         std   rec,u
         lbsr  calcdir
         lda   #DIR.+READ.
         leax  dirpath,u
         os9   I$Open
         lbcs  fa3
         pshs  a
fa1      lda   ,s
         leax  dirent,u
         ldy   #32
         os9   I$Read
         bcs   fa9
         cmpy  #32
         bne   fa9
         lda   dirent,u
         beq   fa1
         lbsr  dir2cpm
         bcs   fa1
         lbsr  calcpfx
         lbsr  addpfx
         lda   #READ.
         leax  pname,u
         os9   I$Open
         bcs   fa1
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
         ldd   posu,u                blocks = (size + 2047) / 2048
         addd  #2047
         std   posu,u
         bcc   fa2
         ldx   posx,u
         leax  1,x
         stx   posx,u
fa2      lda   posu,u
         lsra
         lsra
         lsra
         tfr   a,b
         clra
         std   tmp16,u               posu / 2048
         ldd   posx,u                + posx * 32
         lslb
         rola
         lslb
         rola
         lslb
         rola
         lslb
         rola
         lslb
         rola
         addd  tmp16,u
         addd  rec,u
         std   rec,u
         lbra  fa1
fa9      puls  a
         os9   I$Close
fa3      ldd   rec,u                 the number of blocks (at most 2048)
         cmpd  #2048
         bls   fa3a
         ldd   #2048
fa3a     std   tmp16,u
         leax  cbuf,u
         ldy   #256
fa4      clr   ,x+
         leay  -1,y
         bne   fa4
         ldd   tmp16,u
         andb  #7
         stb   tmp8,u                the bits of the last byte
         ldd   tmp16,u
         lsra
         rorb
         lsra
         rorb
         lsra
         rorb
         tfr   d,y                   the full bytes
         leax  cbuf,u
         cmpy  #0
         beq   fa6
fa5      lda   #$FF
         sta   ,x+
         leay  -1,y
         bne   fa5
fa6      ldb   tmp8,u
         beq   fa7
         clra
fa6a     orcc  #1
         rora
         decb
         bne   fa6a
         sta   ,x
fa7      ldd   #$FD20
         lbsr  setlin16
         leax  cbuf,u
         ldy   #256
         lbsr  wrsub
         ldd   #$FD20
         sta   r_bh,u
         stb   r_bl,u
         stb   r_al,u
fa_no    rts

* 30 set file attributes: the high bit of the first character of the type (t1') = read only.  OS-9: the write
* permission of the owner and of the public (SS.FD, like the command attr).
f_sattr  lbsr  getfcb
         lbsr  mkname
         lda   #WRITE.
         leax  pname,u
         os9   I$Open
         bcc   sat1
         lda   #READ.
         leax  pname,u
         os9   I$Open
         lbcs  fo_err
sat1     sta   tmp8,u
         ldb   #SS.FD
         leax  iobuf,u
         ldy   #1
         os9   I$GetStt
         bcs   sat9
         lda   iobuf,u
         ldb   fcb+F_EXT,u
         bpl   sat2
         anda  #$ED                  read only: no write permission
         bra   sat3
sat2     ora   #$12                  read / write
sat3     sta   iobuf,u
         lda   tmp8,u
         ldb   #SS.FD
         leax  iobuf,u
         ldy   #1
         os9   I$SetStt
sat9     pshs  cc,b
         lda   tmp8,u
         os9   I$Close
         puls  cc,b
         lbcs  fo_err
         rts

* The BIOS entries of the guest (z80shim.asm): 80h + the number in the jump table.  Only the console is real.
bios     lda   func,u
         cmpa  #$80
         lbeq  f_boot
         cmpa  #$81
         lbeq  f_boot
         cmpa  #$82
         beq   bi_st
         cmpa  #$83
         beq   bi_in
         cmpa  #$84
         beq   bi_out
         cmpa  #$87
         bne   bi_nop
         lda   #$1A                  READER: end of file
         sta   r_al,u
         lbra  retA
bi_nop   rts
bi_st    lbsr  rawon
         lbra  dio_st                CONST: FFh = a key is there
bi_in    lbsr  rawon
         lbra  f_conin               CONIN: wait for a key
bi_out   lbsr  rawon
         lbra  f_conout              CONOUT: the character in C (the low byte of the parameter)

* A program that uses the BIOS for the console (Turbo Pascal) draws the screen and reads the keys itself: the terminal
* must not echo, must not translate (upper case, line feed after CR) and must pass the control characters (^C ^E ^W are
* the keys of its editor).  The options are changed when the first BIOS call comes, and put back by cleanup.
* (offsets in the options of the path: PD.UPC 1, PD.EKO 4, PD.ALF 5, PD.PAU 7, PD.EOF 12, PD.PSC 15, PD.INT 16, PD.QUT 17)
rawon    tst   rawf,u
         bne   rw9
         lda   stdi,u
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
         clr   iobuf+12,u            PD.EOF: ESC is the end of file character of OS-9, and the escape key of Turbo Pascal
         clr   iobuf+15,u
         clr   iobuf+16,u
         clr   iobuf+17,u
         lda   stdi,u
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
         lda   stdi,u
         ldb   #SS.Opt
         leax  oldopt,u
         os9   I$SetStt
rw8      rts

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
dio_st   lbsr  stdrbf
         beq   dio_nk
         lda   stdi,u
         ldb   #SS.Ready
         os9   I$GetStt
         bcs   dio_no
         lda   #$FF
         sta   r_al,u
         bra   retA
dio_no   rts
dio_nk   clr   r_al,u                 standard input is a file: no key (see stdrbf)
         bra   retA
dio_in   lbsr  stdrbf
         beq   dio_nk
         lda   stdi,u
         ldb   #SS.Ready
         os9   I$GetStt
         bcs   dio_no
         bra   f_conin

* Z set if the standard input is a file (RBF).  A program that only asks whether a key is there (BDOS 6 and 11; the HI-TECH
* programs do, to see a ^C) must not eat the file: a procedure file, `shell <file`, is the standard input of the passes of cc80
* and its lines would be gone.  A keyboard (SCF) and a pipe are read as before.
stdrbf   lda   stdi,u
         ldb   #SS.Opt
         leax  iobuf,u
         os9   I$GetStt
         bcs   sr1
         lda   iobuf,u               PD.DTP: 0 = SCF, 1 = RBF
         cmpa  #1
         rts
sr1      lda   #$FF
         cmpa  #1
         rts

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

* 13 reset disk system: the drive A
f_reset  clr   curdrv,u
         rts

* 14 select disk (E = 0 for A ... 15 for P): 0, or 255 when no directory is mapped to that drive
f_seldsk lda   parl,u
         anda  #$0F
         beq   sd_ok
         lbsr  drvfind
         bcs   sd_no
sd_ok    lda   parl,u
         anda  #$0F
         sta   curdrv,u
         rts
sd_no    lda   #$FF
         sta   r_al,u
         sta   r_bl,u
         rts

* the entry of the drive A (A = 0 ... 15) in drvtab: X = entry; carry set when it is not mapped
drvfind  inca
         leax  drvtab,u
         ldb   #NDRV
df1      cmpa  ,x
         beq   df9
         leax  DRVSZ,x
         decb
         bne   df1
         orcc  #1
         rts
df9      andcc #$FE
         rts

* 25 the current drive
f_curdsk lda   curdrv,u
         sta   r_al,u
         lbra  retA

* 32 user number: E = 255 gets it, 0 ... 15 sets it
f_user   lda   parl,u
         cmpa  #$FF
         beq   fu_get
         anda  #$0F
         sta   curuser,u
         rts
fu_get   lda   curuser,u
         sta   r_al,u
         lbra  retA

f_ro     rts

* 24 login vector: the bits of the drives that exist (A, and the mapped ones)
f_login  ldd   #1
         std   tmp16,u
         leay  drvtab,u
         lda   #NDRV
         sta   tmp8,u
fl1      ldb   ,y
         beq   fl4
         decb                        B = the number of the drive: the shift count
         ldx   #1
fl2      tstb
         beq   fl3
         pshs  b
         tfr   x,d
         lslb
         rola
         tfr   d,x
         puls  b
         decb
         bra   fl2
fl3      tfr   x,d
         ora   tmp16,u
         orb   tmp16+1,u
         std   tmp16,u
fl4      leay  DRVSZ,y
         dec   tmp8,u
         bne   fl1
         ldd   tmp16,u
         sta   r_bh,u
         stb   r_bl,u
         stb   r_al,u
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
* the directory of the drive and the user area in front of the name
         lbsr  calcpfx
addpfx   ldb   pfxlen,u                (also used by BDOS 18 after calcpfx: pname = a name found in the directory)
         beq   mn99
         leay  pname+12,u            move the name (12 characters and the CR) up by pfxlen
         leax  b,y
         ldb   #13
mn5      lda   ,y
         sta   ,x
         leay  -1,y
         leax  -1,x
         decb
         bne   mn5
         leax  drvdir,u              the prefix in front of it
         leay  pname,u
         ldb   pfxlen,u
mn6      lda   ,x+
         sta   ,y+
         decb
         bne   mn6
mn99     rts

* drvdir / pfxlen = the directory of the drive of the FCB (0 = the current drive) and of the user area, with a / behind:
*   drive A: the current directory;  a mapped drive: its directory;  a drive that is not mapped: /-/ (nothing is there)
*   user 1 ... 15: the subdirectory U1 ... U15
calcpfx  lda   fcb+F_DR,u
         beq   cx0
         deca
         anda  #$0F
         bra   cx1
cx0      lda   curdrv,u
cx1      pshs  a
         leay  drvdir,u
         inca
         leax  drvtab,u
         ldb   #NDRV
cx2      cmpa  ,x
         beq   cx5
         leax  DRVSZ,x
         decb
         bne   cx2
         tst   ,s                    not mapped: drive A is the current directory, the others are nowhere
         beq   cx6
         lda   #'/'
         sta   ,y+
         lda   #'-'
         sta   ,y+
         lda   #'/'
         sta   ,y+
         bra   cx7
cx5      leax  1,x                   the path of the drive
cx5a     lda   ,x+
         beq   cx5b
         sta   ,y+
         bra   cx5a
cx5b     lda   -1,y
         cmpa  #'/'
         beq   cx6
         lda   #'/'
         sta   ,y+
cx6      lda   curuser,u
         beq   cx7
         ldb   #'U'
         stb   ,y+
         cmpa  #10
         blo   cx6a
         ldb   #'1'
         stb   ,y+
         suba  #10
cx6a     adda  #'0'
         sta   ,y+
         lda   #'/'
         sta   ,y+
cx7      leas  1,s
         leax  drvdir,u
         tfr   y,d
         pshs  x
         subd  ,s++
         stb   pfxlen,u
         rts

* dirpath = the directory for a scan (BDOS 17, 19, 15 with a wildcard): the prefix without the last /, or "."
calcdir  lbsr  calcpfx
         leay  dirpath,u
         ldb   pfxlen,u
         bne   cdr1
         lda   #'.'
         sta   ,y+
         bra   cdr3
cdr1      leax  drvdir,u
         decb
         beq   cdr3
cdr2      lda   ,x+
         sta   ,y+
         decb
         bne   cdr2
cdr3      lda   #C$CR
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

* shared paths: shfind = the entry (X) whose name is the one of the FCB, carry set if none
shfind   tst   pfxlen,u               (a name with a drive / user prefix is not shared: the table knows only the 11 bytes)
         beq   shf0
         orcc  #1
         rts
shf0     leax  shtab,u
         ldb   #NSH
shq1      tst   1,x
         beq   shq3
         pshs  x,b
         leax  2,x
         leay  fcb+F_NAME,u
         ldb   #11
shq2      lda   ,x+
         cmpa  ,y+
         bne   shq4
         decb
         bne   shq2
         puls  x,b
         andcc #$FE
         rts
shq4      puls  x,b
shq3      leax  SHSZ,x
         decb
         bne   shq1
         orcc  #1
         rts

* shadd: enter the path of the FCB under its name (no free entry: it is not shared)
shadd    tst   pfxlen,u
         beq   sha0
         rts
sha0     leax  shtab,u
         ldb   #NSH
shw1      tst   1,x
         beq   shw2
         leax  SHSZ,x
         decb
         bne   shw1
         rts
shw2      lda   fcb+F_PATH,u
         sta   ,x
         lda   #1
         sta   1,x
         leay  fcb+F_NAME,u
         leax  2,x
         ldb   #11
shw3      lda   ,y+
         sta   ,x+
         decb
         bne   shw3
         rts

* shdrop: A = path being closed.  Carry set: not shared.  Else one FCB less; Z set if it was the last one (A is kept)
shdrop   leax  shtab,u
         ldb   #NSH
shd1      tst   1,x
         beq   shd2
         cmpa  ,x
         beq   shd3
shd2      leax  SHSZ,x
         decb
         bne   shd1
         orcc  #1
         rts
shd3      dec   1,x
         andcc #$FE
         rts

* shkill: the file of this name is made or deleted: forget the entry (the FCBs that have the path close it as usual)
shkill   lbsr  shfind
         bcs   shk9
         clr   1,x
shk9      rts

f_open   lbsr  getfcb
         clr   fcb+F_SLOT,u
         clr   fcb+F_TSLOT,u
         lbsr  isstd
         bcs   fo0
         lbsr  mkstd
         lbra  fo2
fo0      lbsr  haswild
         bcc   fo0w
         lbsr  wildfind               a wildcard: the first file that matches
         lbcs  fo_err
fo0w     lbsr  mkname
         lbsr  shfind                 the name is open already: take its path
         bcs   fo0n
         lda   ,x
         inc   1,x
         sta   fcb+F_PATH,u
         bra   fo2
fo0n     clr   cvw,u
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
         tst   fcb+F_SLOT,u           a binary file can be shared
         bne   fo2
         tst   fcb+F_TSLOT,u
         bne   fo2
         lbsr  shadd
fo2      clr   fcb+F_CR,u
         lbra  putfcb
fo_err   tst   dbg,u                 -d: show the OS-9 error code (B) of the failed open / make
         beq   fe1
         pshs  b
         tfr   b,a
         lsra
         lsra
         lsra
         lsra
         bsr   fe_hex
         lda   ,s
         anda  #$0F
         bsr   fe_hex
         lda   #C$CR
         sta   iobuf,u
         bsr   fe_wr
         puls  b
fe1      lda   #$FF
         sta   r_al,u
         lbra  retA
fe_hex   cmpa  #10
         blo   fe_h1
         adda  #7
fe_h1    adda  #'0
         sta   iobuf,u
fe_wr    lda   #2
         leax  iobuf,u
         ldy   #1
         os9   I$Write
         rts

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
fc1      lbsr  shdrop                 shared with another FCB: only the last one closes
         bcs   fc1c
         bne   fc2
fc1c     os9   I$Close
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
         lbsr  shkill
         lda   #UPDAT.
         ldb   #READ.+WRITE.+PREAD.+PWRIT.
         leax  pname,u
         os9   I$Create
         bcc   mkd1
         cmpb  #E$PNNF
         lbne  fo_err
         tst   pfxlen,u
         lbeq  fo_err
         lbsr  calcdir               the user area is a subdirectory: make it, once
         leax  dirpath,u
         ldb   #$3F
         os9   I$MakDir
         lbcs  fo_err
         lda   #UPDAT.
         ldb   #READ.+WRITE.+PREAD.+PWRIT.
         leax  pname,u
         os9   I$Create
         lbcs  fo_err
mkd1     sta   fcb+F_PATH,u
         lda   #1
         sta   cvw,u
         lda   #2
         sta   tmp8b,u
         lbsr  mktslot
mk3      clr   fcb+F_CR,u
         clr   fcb+F_EX,u
         clr   fcb+F_RC,u
         lbra  putfcb

* ? in the name of the FCB (the wildcard of CP/M; the program has put it there: * is ??? in the FCB).  Carry set: there is one.
haswild  leax  fcb+F_NAME,u
         ldb   #11
hw1      lda   ,x+
         anda  #$7F
         cmpa  #'?'
         beq   hw2
         decb
         bne   hw1
         andcc #$FE
         rts
hw2      orcc  #1
         rts

* srchpat = the name of the FCB (without the attribute bits)
loadpat  leax  fcb+F_NAME,u
         leay  srchpat,u
         ldb   #11
lp1      lda   ,x+
         anda  #$7F
         sta   ,y+
         decb
         bne   lp1
         rts

* function 15 with a wildcard opens the first file that matches: its name goes into the FCB.  Carry set: none
wildfind lbsr  loadpat
         lbsr  calcdir
         lda   #DIR.+READ.
         leax  dirpath,u
         os9   I$Open
         bcs   wf9
         pshs  a
wf1      lda   ,s
         leax  dirent,u
         ldy   #32
         os9   I$Read
         bcs   wfno
         cmpy  #32
         bne   wfno
         lda   dirent,u
         beq   wf1
         lbsr  dir2cpm
         bcs   wf1
         lbsr  matchpat
         bcs   wf1
         leax  iobuf,u
         leay  fcb+F_NAME,u
         ldb   #11
wf2      lda   ,x+
         sta   ,y+
         decb
         bne   wf2
         lda   ,s+
         os9   I$Close
         andcc #$FE
         rts
wfno     lda   ,s+
         os9   I$Close
         ldb   #E$PNNF
wf9      orcc  #1
         rts

* function 19 with a wildcard deletes every file that matches; 255 when there was none
delwild  lbsr  loadpat
         lbsr  calcdir
         lda   #DIR.+READ.
         leax  dirpath,u
         os9   I$Open
         lbcs  fo_err
         pshs  a
         clr   tmp16,u
dw1      lda   ,s
         leax  dirent,u
         ldy   #32
         os9   I$Read
         bcs   dw9
         cmpy  #32
         bne   dw9
         lda   dirent,u
         beq   dw1
         lbsr  dir2cpm
         bcs   dw1
         lbsr  matchpat
         bcs   dw1
         lda   #UPDAT.
         leax  pname,u
         os9   I$Delete
         bcs   dw1
         inc   tmp16,u
         bra   dw1
dw9      lda   ,s+
         os9   I$Close
         tst   tmp16,u
         bne   dw8
         ldb   #E$PNNF
         lbra  fo_err
dw8      rts

f_delete lbsr  getfcb
         lbsr  haswild
         lbcs  delwild
         lbsr  mkname
         lbsr  shkill
         lda   #UPDAT.
         leax  pname,u
         os9   I$Delete
         lbcs  fo_err
         rts

* function 23: rename.  The new name is in the FCB at +16 (drive, name, extension).  OS-9 renames by writing into the
* directory entry; here the new file is made, the old one is copied into it and deleted.  Result 0, or 255 (the old file
* is not there, or the new name exists already).  (Turbo Pascal renames the source to .BAK when it saves.)
f_rename lbsr  getfcb
         lbsr  rnclose
         lbsr  mkname
         lbsr  shkill
         leax  pname,u
         leay  cbuf,u
rn1      lda   ,x+
         sta   ,y+
         cmpa  #C$CR
         bne   rn1                   the old name is in cbuf
         leax  fcb+17,u              the new name goes to the name and the extension of the FCB
         leay  fcb+F_NAME,u
         ldb   #11
rn2      lda   ,x+
         sta   ,y+
         decb
         bne   rn2
         lbsr  mkname                pname = the new name
         lda   #READ.
         leax  pname,u
         os9   I$Open
         bcs   rn3
         os9   I$Close               the new name exists already
         ldb   #$FE
         lbra  fo_err
rn3      lda   #READ.
         leax  cbuf,u
         os9   I$Open
         lbcs  fo_err
         sta   tmp8,u
         lda   #UPDAT.
         ldb   #READ.+WRITE.+PREAD.+PWRIT.
         leax  pname,u
         os9   I$Create
         bcc   rn4
         pshs  b
         lda   tmp8,u
         os9   I$Close
         puls  b
         lbra  fo_err
rn4      sta   tmp8b,u
rn5      lda   tmp8,u
         leax  iobuf,u
         ldy   #256
         os9   I$Read
         bcs   rn7
         lda   tmp8b,u
         leax  iobuf,u
         os9   I$Write               Y = the length that was read
         bcc   rn5
rn7      pshs  b                     the end of the file (E$EOF), or an error
         lda   tmp8,u
         os9   I$Close
         lda   tmp8b,u
         os9   I$Close
         puls  b
         cmpb  #E$EOF
         lbne  fo_err
         lda   #UPDAT.
         leax  cbuf,u
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
         lda   fcb+F_DR,u
         sta   srchdr,u               the drive of the search (BDOS 18 uses it)
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
sf2      lbsr  calcdir
         lda   #DIR.+READ.
         leax  dirpath,u
         os9   I$Open
         lbcs  fo_err
         sta   srchdir,u
f_snext  lda   srchdir,u              (BDOS 18 has no valid FCB: STAT passes 0; the drive is that of BDOS 17)
         lbeq  fo_err
         lda   srchdr,u
         sta   fcb+F_DR,u
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
         lbsr  calcpfx
         lbsr  addpfx
         lda   #READ.
         leax  pname,u
         os9   I$Open
         bcc   sn4o
         cmpb  #E$FNA                 a directory (U1, a mapped drive, ...) is not a CP/M file: it is not listed
         lbeq  sn1
         bra   sn5
sn4o     sta   tmp8b,u
         ldb   #SS.Size
         pshs  u
         os9   I$GetStt
         tfr   u,d
         puls  u
         std   posu,u
         stx   posx,u
* a file that nobody may write is read only: R/O = the high bit of the first character of the type
         lda   tmp8b,u
         ldb   #SS.FD
         leax  iobuf+100,u
         ldy   #1
         os9   I$GetStt
         bcs   sn4r
         lda   iobuf+100,u
         bita  #$12                  the write permission of the owner or of the public
         bne   sn4r
         lda   sect+9,u
         ora   #$80
         sta   sect+9,u
sn4r     lda   tmp8b,u
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

* the program ended: close the text files it left open (a changed writable one is converted back first)
cleanup  lbsr  rawoff
         ldb   #1
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

upcase   cmpa  #'a'
         blo   up9
         cmpa  #'z'
         bhi   up9
         suba  #$20
up9      rts
