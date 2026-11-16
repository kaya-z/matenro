* cpmdata.asm - the data area of the BDOS engine (cpm.asm: the data area of the program, bdos.asm: the work area of the caller)
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
wfail    rmb   1                 a write of the program failed (disk full): cpm leaves with status 1
stdi      rmb   1                 our own copies of the standard paths (see start)
stdo     rmb   1
stde     rmb   1
model    rmb   1                 CP/M-86: 0 = 8080 model, 1 = small model
fcb      rmb   36
pname    rmb   80
pathbuf  rmb   96
optb     rmb   1
dbg      rmb   1
xpath    rmb   1                 path of /x0 (the xlink driver), 0 = driver not loaded
keep     rmb   1                 -k: the command tail keeps its case
tooldir  rmb   48
slotp    rmb   2
tcnt     rmb   1
tlast    rmb   1
tdst     rmb   2
slots    rmb   816                  NSLOT * SLOTSZ
tnames   rmb   44                   NT * 11: the FCB name of each open text file (BDOS 23 closes the file that is renamed)
tslots   rmb   16                   NT * 4: real path, temp path, flags (bit7 used, bit1 writable, bit0 modified)
shtab    rmb   78                   NSH * SHSZ: shared paths (see above)
islib    rmb   1                    1: the engine runs in the module bdos (there is no guest memory to write tables into)
srchdr   rmb   1                    the drive byte of the FCB of the search (BDOS 17), for BDOS 18
iobyte   rmb   1                    the IOBYTE (BDOS 7 / 8)
curdrv   rmb   1                    the current drive, 0 = A (BDOS 14)
curuser  rmb   1                    the user number (BDOS 32)
pfxlen   rmb   1                    the length of drvdir
drvtab   rmb   NDRV*DRVSZ          the drives that are mapped: drive + 1 (0 = free), the path of the directory
drvdir   rmb   40                   the directory of the drive and the user area of the FCB, with a / behind
dirpath  rmb   40                   the same for the directory scans (no / at the end; "." for the current directory)
clrend   equ   .                    (the data area from slots to here is cleared at the start)
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
rawf     rmb   1                 the terminal is in the raw mode (see rawon)
oldopt   rmb   32                the options of the terminal before
sect     rmb   128
iobuf    rmb   256
         ifne  GFXV
         use   gfxvars.inc
         endc
         rmb   256               stack
size     equ   .
