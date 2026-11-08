* cpmdefs.asm - definitions shared by cpm.asm (the program) and bdos.asm (the subroutine module)
XCTL     equ   $FFCA
XSTAT    equ   $FFCB
XID      equ   $FFCC
XIDX     equ   $FFCD
XDAT     equ   $FFCE
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

* Shared paths: a CP/M program does not have to close a file it only reads, and linq opens the same file again and again (the
* library twice per pass, every object file in every pass).  Every OS-9 path takes a page of the system memory of Level 2,
* which is small (some 6 KB are free): an open on a name that is open already takes the same path again (every read seeks to
* the record, so the FCBs do not disturb each other).  shtab: NSH entries of path, count (0 = free) and the 11 bytes of the name.
NSH      equ   6
NDRV     equ   4                 drives B: ... that can be mapped to a directory (cpm -m=B:/d1): letter, path
DRVSZ    equ   33
SHSZ     equ   13

RQZ80    equ   $FC80
RQ88     equ   $0600
LB88     equ   $0620

