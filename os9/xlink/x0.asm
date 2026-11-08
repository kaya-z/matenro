* SPDX-License-Identifier: MIT
****************************************
* x0 - device descriptor of the cross link driver (xlink.asm)
*
* Credits: the layout follows sim09's level2/pty-dd.asm (Soren Roug), read as a model; the values are chosen for a
* device that is only opened to ask for the sub CPU memory and the doorbell.
****************************************
         ifp1
         use   defsfile
         endc

         nam   x0
         ttl   Cross link descriptor

         mod   XEND,XNAM,DEVIC+OBJCT,REENT+1,XMGR,XDRV
         fcb   READ.+WRITE.+SHARE.
         fcb   $FF               IOBlock (unused)
         fdb   $FFCA             hardware address: XCTL
         fcb   XNAM-*-1          option byte count
         fcb   $00               SCF device
         fcb   $00,$00,$00,$00,$00,$00,$00
         fcb   24
         fcb   $08,$18,$0D,$1B,$04,$01,$17,$03,$05,$08,$07
         fcb   $00,$00
         fdb   XNAM
         fdb   $0000
XNAM     fcs   "x0"
XMGR     fcs   "SCF"
XDRV     fcs   "xlink"
         emod
XEND     equ   *
         end
