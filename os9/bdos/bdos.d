* bdos.d - the interface of the subroutine module `bdos` (CP/M BDOS for OS-9 programs), for a09
*
*   BDOSSZ      the size of the work area that the caller reserves (bytes)
*
* The calling program (user state, 6809):
*
*           lda   #Sbrtn+Objct
*           clrb
*           leax  bdosname,pcr           fcs /bdos/
*           pshs  u                      F$Link returns the address of the module in U: keep the data pointer
*           os9   F$Link                 Y = the entry address of the module
*           puls  u
*           sty   bdosent,u              (a 2 byte variable)
*     ...
*           leay  bdoswk,u               the work area: BDOSSZ bytes in the data area of the caller
*           lda   #BDOSINIT              once, before the first call
*           jsr   [bdosent,u]
*     ...
*           leay  bdoswk,u
*           lda   #9                     the BDOS function number (C of CALL 5)
*           ldx   #parameter             DE of CALL 5: a pointer into the memory of the caller (FCB, string, DMA)
*           jsr   [bdosent,u]            A = A of CP/M, X = HL, B = H
*     ...
*           leay  bdoswk,u
*           lda   #BDOSEXIT              before the program ends: closes the files, writes back the text files
*           jsr   [bdosent,u]
*
* U (the data pointer of the caller) is kept; Y is the work area and is not changed.  The module needs about 400 bytes of
* the stack of the caller.  The standard input / output / error paths of the caller are the console of the BDOS functions.
* The functions are those of `cpm` (docs/DESIGN.md, chapter 12): console 1 2 6 9 10 11, files 15 16 17 18 19 20 21 22 23
* 26 33 34 35 36, 12 version (0022h); the FCB, the string and the DMA address are pointers into the memory of the caller.
* The DMA address is 0 until function 26 sets it.  A native program has no CP/M memory: no program is loaded, no CALL 5.
BDOSSZ   equ   2500
BDOSINIT equ   $FF
BDOSEXIT equ   $FE
