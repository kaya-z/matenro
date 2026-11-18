; SPDX-License-Identifier: MIT
; bios2.asm - the BIOS (IO.SYS) of MS-DOS 2.0 on the 8088 of 摩天楼 (Matenro); UASM (MASM compatible), flat binary
; Credits: the structure of the drivers (the device headers, the strategy and interrupt entries, the command tables, the
; request packet, the BPB) is that of MS-DOS 2.0 (the skeleton BIOS SKELIO.ASM and DEVDRIV.DOC that Microsoft published,
; MIT license).  The code is original.
;
; The image = this BIOS + SYSINIT of Microsoft (the patched copy of SYSINIT.ASM, tools/dos/patch_sysinit.py) + the
; messages.  It is loaded at 0040:0000 (linear 0400h) by the OS-9 command `dos -v=2`; the kernel (the published MSDOS.SYS)
; follows it at the next paragraph.  The BIOS asks the 6809 for the console, the disks, the printer, the aux port and the
; clock through the request block RQ like the BIOS of 1.25 (bios88.asm, the same function numbers):
;   RQ+0 function  +1 AX  +4 BX  +6 CX  +8 DX  +10 DS      (request)
;   RQ+16 AL  +17 AH  +18 BX  +20 CX  +22 DX  +24 flags (CF)  +26 time (year-1900 month day hour minute second)  +32 done
; Functions: 1 console status, 2 input, 3 output, 4 printer, 5 aux in, 6 aux out, 7 disk read, 8 disk write, 12 get time,
; 13 flush.
        .8086
        OPTION  OLDSTRUCTS

; the fixed places that the 6809 knows (os9/dos/dos.asm): the request block and the boot data
RQ_OFS  EQU     10h                     ; request block (48 bytes)
LB_OFS  EQU     40h                     ; +0 memory size (paragraphs), +2 number of units, +4 the BPBs (13 bytes each)

CODE    SEGMENT PARA PUBLIC 'CODE'
        ASSUME  CS:CODE,DS:CODE,ES:CODE,SS:CODE
        ORG     0
INIT:   JMP     HWINIT
        ORG     RQ_OFS
RQ      DB      48 DUP (0)
        ORG     LB_OFS
MEMSIZ  DW      0
UNITS   DB      0,0
BPBTAB  DB      4*13 DUP (0)
        ORG     78h
PCFLAG  DB      0                       ; set by the 6809 (dos -w=): the console and INT 10h are the text screen of the PC at B800h
        ORG     80h

; register block -> request, ring the bell, wait.  The registers are kept.
REQ     MACRO   fn
        MOV     BYTE PTR CS:[RQ+0],fn
        CALL    SENDREQ
        ENDM

SENDREQ:
        MOV     WORD PTR CS:[RQ+1],AX
        MOV     WORD PTR CS:[RQ+4],BX
        MOV     WORD PTR CS:[RQ+6],CX
        MOV     WORD PTR CS:[RQ+8],DX
        MOV     WORD PTR CS:[RQ+10],DS
SENDRQ: PUSH    AX
        MOV     BYTE PTR CS:[RQ+32],0
        XOR     AL,AL
        OUT     2,AL                    ; ring the 6809
SNDWT:  CMP     BYTE PTR CS:[RQ+32],0
        JE      SNDWT
        POP     AX
        RET

; INT 10h, the video BIOS of the IBM PC that the programs of PC DOS (DEBUG) ask for: get the mode (80 columns, mode 3, page 0)
; and teletype output; everything else is ignored.  With PCFLAG (dos -w=): the text screen of the PC, 80 x 25 cells {character, attribute} at
; B800:0000 (the HDMI screen of the Tang Nano 20K shows that memory: docs/TN20K.md 2.5), and the functions that Turbo Pascal and the programs
; that write the screen themselves need: 00 set mode (clears), 01 cursor shape, 02 set cursor, 03 get cursor, 06 / 07 scroll, 08 read, 09 / 0Ah
; write, 0Eh teletype; the cursor goes to the 6809 (request 31) after each change.
INT10:  CMP     AH,0Fh
        JNE     I10A
        MOV     AX,5003h
        XOR     BH,BH
        IRET
I10A:   CMP     BYTE PTR CS:[PCFLAG],0
        JNE     I10P
        CMP     AH,0Eh
        JNE     I10B
        REQ     3
I10B:   IRET
I10P:   STI
        CMP     AH,0Eh
        JE      I10TTY
        CMP     AH,2
        JE      I10SC
        CMP     AH,3
        JE      I10GC
        CMP     AH,9
        JE      I10WA
        CMP     AH,0Ah
        JE      I10WC
        CMP     AH,6
        JE      I10SU
        CMP     AH,7
        JE      I10SD
        CMP     AH,8
        JE      I10RD
        CMP     AH,0
        JE      I10MD
        CMP     AH,1
        JNE     I10X
        MOV     CS:[CURSHP],CX
I10X:   IRET
I10TTY: PUSH    AX
        PUSH    DX
        CALL    TTYCH
        CALL    SETCUR
        POP     DX
        POP     AX
        IRET
I10SC:  MOV     CS:[CURPOS],DX
        PUSH    AX
        CALL    SETCUR
        POP     AX
        IRET
I10GC:  MOV     DX,CS:[CURPOS]
        MOV     CX,CS:[CURSHP]
        XOR     AX,AX
        IRET
I10MD:  CALL    CLRSCR
        IRET
; 09 / 0Ah: the character AL (attribute BL for 09) CX times from the cursor, the cursor stays
I10WA:  PUSH    AX
        PUSH    BX
        MOV     BH,BL
        MOV     AH,1
        JMP     SHORT I10W
I10WC:  PUSH    AX
        PUSH    BX
        XOR     AH,AH
I10W:   PUSH    CX
        PUSH    DX
        PUSH    DI
        PUSH    ES
        PUSH    AX
        MOV     DX,CS:[CURPOS]
        CALL    CELLDI
        MOV     AX,0B800h
        MOV     ES,AX
        POP     AX
        JCXZ    I10WE
I10WL:  CMP     DI,4000
        JAE     I10WE
        MOV     ES:[DI],AL
        OR      AH,AH
        JZ      I10WN
        MOV     ES:[DI+1],BH
I10WN:  ADD     DI,2
        LOOP    I10WL
I10WE:  POP     ES
        POP     DI
        POP     DX
        POP     CX
        POP     BX
        POP     AX
        IRET
; 08: AL the character and AH the attribute at the cursor
I10RD:  PUSH    BX
        PUSH    DX
        PUSH    DI
        PUSH    ES
        MOV     DX,CS:[CURPOS]
        CALL    CELLDI
        MOV     AX,0B800h
        MOV     ES,AX
        MOV     AX,ES:[DI]
        POP     ES
        POP     DI
        POP     DX
        POP     BX
        IRET
; 06 / 07: scroll the window CH,CL - DH,DL up / down by AL lines (0: clear it), the new lines get the attribute BH
I10SU:  CALL    SCRLWIN
        IRET
I10SD:  CALL    SCRLWIN
        IRET

; DI = the offset of the cell (DH row, DL column) in the text memory; the registers are kept
CELLDI: PUSH    AX
        PUSH    CX
        MOV     AL,DH
        MOV     AH,80
        MUL     AH
        XOR     CX,CX
        MOV     CL,DL
        ADD     AX,CX
        SHL     AX,1
        MOV     DI,AX
        POP     CX
        POP     AX
        RET

; the cursor to the 6809: request 31, AL = 2, DX = row / column
SETCUR: PUSH    AX
        PUSH    DX
        MOV     DX,CS:[CURPOS]
        MOV     AX,2
        REQ     31
        POP     DX
        POP     AX
        RET

; clear the text screen (blank cells, attribute 07h) and home the cursor
CLRSCR: PUSH    AX
        PUSH    CX
        PUSH    DX
        PUSH    DI
        PUSH    ES
        MOV     AX,0B800h
        MOV     ES,AX
        XOR     DI,DI
        MOV     AX,0720h
        MOV     CX,2000
        CLD
        REP     STOSW
        XOR     DX,DX
        MOV     CS:[CURPOS],DX
        CALL    SETCUR
        POP     ES
        POP     DI
        POP     DX
        POP     CX
        POP     AX
        RET

; teletype: the character AL at the cursor (CR, LF, BS, BEL are control characters), the attribute of the cell stays; the cursor is advanced,
; the screen scrolls up at the bottom.  The 6809 is not told (SETCUR does it).
TTYCH:  PUSH    BX
        PUSH    DI
        PUSH    DX
        PUSH    ES
        MOV     DX,CS:[CURPOS]
        CMP     AL,0Dh
        JE      TTCR
        CMP     AL,0Ah
        JE      TTLF
        CMP     AL,8
        JE      TTBS
        CMP     AL,7
        JE      TTEND
        CALL    CELLDI
        MOV     BX,0B800h
        MOV     ES,BX
        MOV     ES:[DI],AL
        INC     DL
        CMP     DL,80
        JB      TTEND
        XOR     DL,DL
        JMP     SHORT TTLF
TTCR:   XOR     DL,DL
        JMP     SHORT TTEND
TTBS:   OR      DL,DL
        JZ      TTEND
        DEC     DL
        JMP     SHORT TTEND
TTLF:   INC     DH
        CMP     DH,25
        JB      TTEND
        MOV     DH,24
        PUSH    AX
        PUSH    CX
        PUSH    DX
        MOV     AX,0601h                ; scroll the whole screen up by one line
        MOV     BH,07h
        XOR     CX,CX
        MOV     DX,184Fh
        CALL    SCRLWIN
        POP     DX
        POP     CX
        POP     AX
TTEND:  MOV     CS:[CURPOS],DX
        POP     ES
        POP     DX
        POP     DI
        POP     BX
        RET

; the scroll of INT 10h 06 / 07 (AH = 6 up, 7 down; AL lines, 0 = all; BH attribute; CH,CL top left; DH,DL bottom right)
SCRLWIN:
        PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX
        PUSH    SI
        PUSH    DI
        PUSH    BP
        PUSH    DS
        PUSH    ES
        MOV     BP,AX                   ; BP: AH = the direction, AL = the lines
        MOV     AX,0B800h
        MOV     DS,AX
        MOV     ES,AX
        CLD
        ; CH = top row, DH = bottom row, CL = left, DL = right; BL = the number of lines
        MOV     AX,BP
        MOV     BL,AL
        MOV     AL,DH
        SUB     AL,CH
        INC     AL                      ; the height
        OR      BL,BL
        JZ      SCALL
        CMP     BL,AL
        JB      SCNOT
SCALL:  MOV     BL,AL                   ; all of it: clear the window
SCNOT:  ; the loop over the rows to move: (height - lines) rows
        MOV     BYTE PTR CS:[SCRLN],BL
        MOV     CS:[SCRBH],BH
        MOV     CS:[SCRDIR],BP
        SUB     AL,BL                   ; AL = the rows to move
        MOV     AH,AL
        ; the width of a row in words: DL - CL + 1
        XOR     BX,BX
        MOV     BL,DL
        SUB     BL,CL
        INC     BL
        MOV     CS:[SCRW],BX
        MOV     CS:[SCRL],CL
        MOV     CS:[SCRT],CH
        MOV     CS:[SCRB],DH
        ; AH = the rows to move
        CMP     BYTE PTR CS:[SCRDIR+1],6
        JNE     SCDOWN
        ; up: for r = top .. top + rows - 1: row r <- row r + lines
        MOV     DH,CH
SCUPL:  OR      AH,AH
        JZ      SCFILLU
        MOV     DL,CS:[SCRL]
        CALL    CELLDI
        MOV     BX,DI                   ; the destination
        PUSH    DX
        MOV     AL,CS:[SCRLN]
        ADD     DH,AL
        CALL    CELLDI
        MOV     SI,DI
        POP     DX
        MOV     DI,BX
        MOV     CX,CS:[SCRW]
        REP     MOVSW
        INC     DH
        DEC     AH
        JMP     SHORT SCUPL
SCFILLU:                                ; DH = the first row to clear
        MOV     BL,CS:[SCRLN]
SCFLU:  OR      BL,BL
        JZ      SCEND
        MOV     DL,CS:[SCRL]
        CALL    CELLDI
        CALL    SCRFILL
        INC     DH
        DEC     BL
        JMP     SHORT SCFLU
SCDOWN: ; down: for r = bottom .. bottom - rows + 1: row r <- row r - lines
        MOV     DH,CS:[SCRB]
SCDNL:  OR      AH,AH
        JZ      SCFILLD
        MOV     DL,CS:[SCRL]
        CALL    CELLDI
        MOV     BX,DI
        PUSH    DX
        MOV     AL,CS:[SCRLN]
        SUB     DH,AL
        CALL    CELLDI
        MOV     SI,DI
        POP     DX
        MOV     DI,BX
        MOV     CX,CS:[SCRW]
        REP     MOVSW
        DEC     DH
        DEC     AH
        JMP     SHORT SCDNL
SCFILLD:
        MOV     BL,CS:[SCRLN]
SCFLD:  OR      BL,BL
        JZ      SCEND
        MOV     DL,CS:[SCRL]
        CALL    CELLDI
        CALL    SCRFILL
        DEC     DH
        DEC     BL
        JMP     SHORT SCFLD
SCEND:  POP     ES
        POP     DS
        POP     BP
        POP     DI
        POP     SI
        POP     DX
        POP     CX
        POP     BX
        POP     AX
        RET
; fill SCRW cells from ES:DI with a blank and the attribute SCRBH
SCRFILL:
        PUSH    AX
        PUSH    CX
        PUSH    DI
        MOV     AH,CS:[SCRBH]
        MOV     AL,20h
        MOV     CX,CS:[SCRW]
        REP     STOSW
        POP     DI
        POP     CX
        POP     AX
        RET

CURPOS  DW      0                       ; the cursor: DH row, DL column
CURSHP  DW      0607h                   ; its shape
SCRLN   DB      0                       ; the scroll in progress
SCRBH   DB      0
SCRDIR  DW      0
SCRW    DW      0
SCRL    DB      0
SCRT    DB      0
SCRB    DB      0
XPEND   DB      0               ; the scan code of an extended key, still to be given by the console after its 0

; INT 16h, the keyboard of the IBM PC (Turbo Pascal reads its keys with it): AH = 0 waits for a key (AL the character, AH 0), 1 asks whether there is
; one (ZF = 0 and AX the key if so; the key stays), 2 the shift flags (0).  The keys come from the 6809 like those of the console (requests 1 and 2).
INT16:  STI
        OR      AH,AH
        JZ      I16RD
        CMP     AH,1
        JE      I16ST
        CMP     AH,2
        JNE     I16X
        XOR     AL,AL
I16X:   IRET
I16RD:  REQ     2
        MOV     AL,CS:[RQ+16]
        MOV     AH,CS:[RQ+18]       ; an extended key: AL = 0, AH = its scan code
        IRET
I16ST:  PUSH    BP
        MOV     BP,SP
        REQ     1
        CMP     BYTE PTR CS:[RQ+17],0
        JE      I16NO
        MOV     AL,CS:[RQ+16]
        MOV     AH,CS:[RQ+18]
        AND     WORD PTR [BP+6],0FFBFh  ; ZF = 0: a key
        POP     BP
        IRET
I16NO:  OR      WORD PTR [BP+6],40h     ; ZF = 1: no key
        POP     BP
        IRET

; INT 1Ah, the clock of the IBM PC: AH = 0 gives the ticks since midnight (18.2 per second) in CX:DX and AL = 0 (no midnight).  The first call takes the
; time of the day from the 6809 (whole seconds: seconds * 18 + seconds / 5) and the microsecond counter of the cross link (request 32); after that the ticks
; are that base plus the microseconds since / 54925, so the ticks go on in steps of 55 ms (Turbo Pascal times its delay loop with it).  The other functions do nothing.
INT1A:  STI
        OR      AH,AH
        JZ      I1A0
        IRET
I1A0:   PUSH    BX
        PUSH    SI
        PUSH    DI
        CMP     BYTE PTR CS:[UINIT],0
        JNE     I1AGO
        REQ     12                      ; the first call: RQ+26: year-1900 month day hour minute second
        MOV     AL,CS:[RQ+29]           ; the hour * 3600
        XOR     AH,AH
        MOV     BX,3600
        MUL     BX
        MOV     SI,AX
        MOV     DI,DX
        MOV     AL,CS:[RQ+30]           ; + minutes * 60 + seconds
        XOR     AH,AH
        MOV     BL,60
        MUL     BL
        MOV     BL,CS:[RQ+31]
        XOR     BH,BH
        ADD     AX,BX
        ADD     SI,AX
        ADC     DI,0                    ; DI:SI = the seconds
        MOV     AX,SI
        MOV     BX,18
        MUL     BX                      ; DX:AX = low word * 18
        MOV     CX,DX
        PUSH    AX
        MOV     AX,DI
        MUL     BX                      ; AX = high word * 18
        ADD     CX,AX                   ; CX:(saved AX) = seconds * 18
        MOV     AX,SI
        MOV     DX,DI
        MOV     BX,5
        DIV     BX                      ; AX = seconds / 5
        MOV     BX,AX
        POP     DX                      ; the low word of seconds * 18
        ADD     DX,BX
        ADC     CX,0
        MOV     CS:[TBASE],DX
        MOV     CS:[TBASE+2],CX
        REQ     32                      ; the counter now is the origin
        MOV     AX,WORD PTR CS:[RQ+22]
        MOV     CS:[UBASE],AX
        MOV     AX,WORD PTR CS:[RQ+20]
        MOV     CS:[UBASE+2],AX
        MOV     BYTE PTR CS:[UINIT],1
        JMP     SHORT I1AOUT
I1AGO:  REQ     32
        MOV     SI,WORD PTR CS:[RQ+22]           ; the counter now: DI:SI
        MOV     DI,WORD PTR CS:[RQ+20]
        MOV     DX,SI
        MOV     CX,DI
        SUB     DX,CS:[UBASE]
        SBB     CX,CS:[UBASE+2]         ; the microseconds since the origin: CX:DX
        MOV     AX,DX
        MOV     DX,CX
        MOV     BX,54925                ; one tick in microseconds
        PUSH    AX
        MOV     AX,DX
        XOR     DX,DX
        DIV     BX
        MOV     CX,AX                   ; the high word of the ticks
        POP     AX
        DIV     BX                      ; AX the low word of the ticks, DX the rest
        ADD     CS:[TBASE],AX
        ADC     CS:[TBASE+2],CX         ; the base moves on by the whole ticks
        MOV     AX,SI                   ; the origin: the counter now minus the rest
        SUB     AX,DX
        MOV     CS:[UBASE],AX
        MOV     AX,DI
        SBB     AX,0
        MOV     CS:[UBASE+2],AX
I1AOUT: MOV     DX,CS:[TBASE]
        MOV     CX,CS:[TBASE+2]
        XOR     AL,AL
        POP     DI
        POP     SI
        POP     BX
        IRET
TBASE   DW      0,0                     ; the ticks at the origin of the counter
UBASE   DW      0,0                     ; the counter at the origin
UINIT   DB      0

; INT E2h: the graphics of the HDMI screen of the Tang Nano 20K (the 6809 draws: os9/cpm/cpmgfx.asm, the block of DS:BX), AL = 0 done, FFh no frame buffer
GFXINT: REQ     30
        MOV     AL,CS:[RQ+16]
        IRET

;-----------------------------------------------------------------------------------------------------------------
; the device headers: link, attribute, strategy, interrupt, name
DEVSTART LABEL  WORD
BCON  DW      BAUX,0                ; the segment is filled in by HWINIT
        DW      8003h                   ; console input and output
        DW      STRATEGY
        DW      CON_INT
        DB      "CON     "
BAUX  DW      BPRN,0
        DW      8000h
        DW      STRATEGY
        DW      AUX_INT
        DB      "AUX     "
BPRN  DW      BTIM,0
        DW      8000h
        DW      STRATEGY
        DW      PRN_INT
        DB      "PRN     "
BTIM  DW      BDSK,0
        DW      8008h                   ; the clock
        DW      STRATEGY
        DW      TIM_INT
        DB      "CLOCK   "
BDSK  DW      -1,-1                   ; the last device
        DW      2000h                   ; block device, not IBM format (the transfer address is a scratch sector)
        DW      STRATEGY
        DW      DSK_INT
DRVMAX  DB      1
        DB      7 DUP (0)

; the command tables: the commands 0 .. 12
DSKTBL  DW      DSK_INIT, MEDIAC, GET_BPB, CMDERR, DSK_RED, BUS_EXIT, DEXIT, DEXIT, DSK_WRT, DSK_WRT, DEXIT, DEXIT, DEXIT
CONTBL  DW      DEXIT, DEXIT, DEXIT, CMDERR, CON_READ, CON_RDND, DEXIT, CON_FLSH, CON_WRIT, CON_WRIT, DEXIT, DEXIT, DEXIT
AUXTBL  DW      DEXIT, DEXIT, DEXIT, CMDERR, AUX_READ, AUX_RDND, DEXIT, CON_FLSH, AUX_WRIT, AUX_WRIT, DEXIT, DEXIT, DEXIT
TIMTBL  DW      DEXIT, DEXIT, DEXIT, CMDERR, TIM_RED, BUS_EXIT, DEXIT, DEXIT, TIM_WRT, TIM_WRT, DEXIT, DEXIT, DEXIT
PRNTBL  DW      DEXIT, DEXIT, DEXIT, CMDERR, DEXIT, BUS_EXIT, DEXIT, DEXIT, PRN_WRT, PRN_WRT, DEXIT, DEXIT, DEXIT

; the request packet: 0 length, 1 unit, 2 command, 3 status (word), 13 media, 14 transfer address (dword), 18 count, 20 start
PK_UNIT   EQU   1
PK_CMD    EQU   2
PK_STATUS EQU   3
PK_MEDIA  EQU   13
PK_TRANS  EQU   14
PK_COUNT  EQU   18
PK_START  EQU   20

PTRSAV  DD      0

STRATEGY PROC   FAR
        MOV     WORD PTR CS:[PTRSAV],BX
        MOV     WORD PTR CS:[PTRSAV+2],ES
        RET
STRATEGY ENDP

CON_INT:
        PUSH    SI
        MOV     SI,OFFSET CONTBL
        JMP     SHORT ENTRY
AUX_INT:
        PUSH    SI
        MOV     SI,OFFSET AUXTBL
        JMP     SHORT ENTRY
PRN_INT:
        PUSH    SI
        MOV     SI,OFFSET PRNTBL
        JMP     SHORT ENTRY
TIM_INT:
        PUSH    SI
        MOV     SI,OFFSET TIMTBL
        JMP     SHORT ENTRY
DSK_INT:
        PUSH    SI
        MOV     SI,OFFSET DSKTBL

; the common part: AL = unit, AH = media, CX = count, DX = start, ES:DI = the transfer address, DS = CS
ENTRY:  PUSH    AX
        PUSH    CX
        PUSH    DX
        PUSH    DI
        PUSH    BP
        PUSH    DS
        PUSH    ES
        PUSH    BX
        LDS     BX,CS:[PTRSAV]
        MOV     AL,[BX+PK_UNIT]
        MOV     AH,[BX+PK_MEDIA]
        MOV     CX,[BX+PK_COUNT]
        MOV     DX,[BX+PK_START]
        XCHG    DI,AX                   ; unit and media into DI for a moment
        MOV     AL,[BX+PK_CMD]
        XOR     AH,AH
        ADD     SI,AX
        ADD     SI,AX
        CMP     AL,12
        JA      CMDERR
        XCHG    AX,DI
        LES     DI,[BX+PK_TRANS]
        PUSH    CS
        POP     DS
        JMP     WORD PTR [SI]

BUS_EXIT:
        MOV     AH,03h                  ; busy and done
        JMP     SHORT DEXIT1
CMDERR: MOV     AL,3                    ; unknown command
ERR_EXIT:
        MOV     AH,81h                  ; error and done
        STC
        JMP     SHORT DEXIT1
DEXIT:   MOV     AH,01h                  ; done
DEXIT1:  LDS     BX,CS:[PTRSAV]
        MOV     [BX+PK_STATUS],AX
        POP     BX
        POP     ES
        POP     DS
        POP     BP
        POP     DI
        POP     DX
        POP     CX
        POP     AX
        POP     SI
        RETF

;-----------------------------------------------------------------------------------------------------------------
; the console: AL from the 6809 (REQ 2 waits for a key), the typeahead of one character is kept by the 6809
CON_READ:
        JCXZ    CRDONE
CRLOOP: CMP     BYTE PTR CS:[XPEND],0
        JE      CRNEW
        MOV     AL,CS:[XPEND]       ; the scan code after the 0 of an extended key
        MOV     BYTE PTR CS:[XPEND],0
        JMP     SHORT CRPUT
CRNEW:  REQ     2
        MOV     AL,CS:[RQ+16]
        MOV     AH,CS:[RQ+18]
        MOV     CS:[XPEND],AH
CRPUT:  STOSB
        LOOP    CRLOOP
CRDONE: JMP     DEXIT

CON_RDND:
        REQ     1
        CMP     BYTE PTR CS:[RQ+17],0
        JE      CRDNO
        MOV     AL,CS:[RQ+16]
        LDS     BX,CS:[PTRSAV]
        MOV     [BX+PK_MEDIA],AL
        JMP     DEXIT
CRDNO:  JMP     BUS_EXIT

CON_FLSH:
        REQ     13
        JMP     DEXIT

CON_WRIT:
        JCXZ    CWDONE
        CMP     BYTE PTR CS:[PCFLAG],0
        JNE     CWPC
CWLOOP: MOV     AL,ES:[DI]
        INC     DI
        REQ     3
        LOOP    CWLOOP
CWDONE: JMP     DEXIT
CWPC:   MOV     AL,ES:[DI]              ; the text screen of the PC: the characters go to the memory, the cursor to the 6809 once at the end
        INC     DI
        CALL    TTYCH
        LOOP    CWPC
        CALL    SETCUR
        JMP     DEXIT

; the aux port and the printer
AUX_READ:
        JCXZ    ARDONE
ARLOOP: REQ     5
        MOV     AL,CS:[RQ+16]
        STOSB
        LOOP    ARLOOP
ARDONE: JMP     DEXIT
AUX_RDND:
        JMP     DEXIT
AUX_WRIT:
        JCXZ    AWDONE
AWLOOP: MOV     AL,ES:[DI]
        INC     DI
        REQ     6
        LOOP    AWLOOP
AWDONE: JMP     DEXIT
PRN_WRT:
        JCXZ    PWDONE
PWLOOP: MOV     AL,ES:[DI]
        INC     DI
        REQ     4
        LOOP    PWLOOP
PWDONE: JMP     DEXIT

;-----------------------------------------------------------------------------------------------------------------
; the disks: the images of the 6809.  The BPBs are written by the 6809 into BPBTAB (13 bytes each)
BPBPTR  DW      BPBTAB, BPBTAB+13, BPBTAB+26, BPBTAB+39

DSK_INIT:
        MOV     AL,CS:[UNITS]
        LDS     BX,CS:[PTRSAV]
        MOV     [BX+13],AL              ; number of units
        MOV     WORD PTR [BX+14],OFFSET RESEND
        MOV     [BX+16],CS              ; break address
        MOV     WORD PTR [BX+18],OFFSET BPBPTR
        MOV     [BX+20],CS              ; BPB array
        JMP     DEXIT

MEDIAC: LDS     BX,CS:[PTRSAV]
        MOV     BYTE PTR [BX+14],1      ; the disk has not been changed
        JMP     DEXIT

GET_BPB:
        XOR     AH,AH                   ; AL = unit
        MOV     CL,13
        MUL     CL
        ADD     AX,OFFSET BPBTAB
        MOV     SI,AX
        LDS     BX,CS:[PTRSAV]
        MOV     [BX+18],AX
        MOV     [BX+20],CS              ; the pointer to the BPB
        MOV     AL,CS:[SI+10]
        MOV     [BX+PK_MEDIA],AL
        JMP     DEXIT

; read / write: AL = unit, CX sectors from the logical sector DX to ES:DI.  Error: AL = the code, the count = the sectors done
DSK_RED:
        MOV     BYTE PTR CS:[RQ+0],7
        JMP     SHORT DSK_COM
DSK_WRT:
        MOV     BYTE PTR CS:[RQ+0],8
DSK_COM:
        MOV     SI,CX                   ; the count asked for
        MOV     BX,DI
        PUSH    ES
        POP     DS                      ; DS:BX the buffer
        CALL    SENDREQ
        PUSH    CS
        POP     DS
        CMP     BYTE PTR CS:[RQ+24],1   ; the 6809 reports an error with 1 in the flags
        JNE     DSK_OK
        MOV     AL,CS:[RQ+16]
        MOV     CX,WORD PTR CS:[RQ+20]           ; the sectors not done
        SUB     SI,CX
        LDS     BX,CS:[PTRSAV]
        MOV     [BX+PK_COUNT],SI
        JMP     ERR_EXIT
DSK_OK: JMP     DEXIT

;-----------------------------------------------------------------------------------------------------------------
; the clock: 6 bytes = the days since 1-1-80 (word), minutes, hours, hundredths, seconds.  The clock of DOS = the clock of
; OS-9 plus an offset TOFF (seconds, 32 bits, modulo 2^32) that setting the date and time changes; the offset is kept here
; only (the clock of OS-9 is not set) and is gone when dos ends.
TOFF    DW      0,0
MLEN    DB      31,28,31,30,31,30,31,31,30,31,30,31

TIM_RED:
        CALL    GETTIME                 ; AX = days, CH = hours, CL = minutes, DH = seconds, DL = 0
        STOSW
        MOV     AL,CL
        STOSB
        MOV     AL,CH
        STOSB
        MOV     AL,DL
        STOSB
        MOV     AL,DH
        STOSB
        JMP     DEXIT

TIM_WRT:
        MOV     AX,ES:[DI]
        MOV     CL,ES:[DI+2]
        MOV     CH,ES:[DI+3]
        MOV     DH,ES:[DI+5]
        CALL    SETDATE                 ; AX = the days
        CALL    SETTIME                 ; CH:CL:DH
        JMP     DEXIT

GETTIME:
        PUSH    BX
        PUSH    SI
        CALL    EFFSEC
        CALL    SPLITSEC                ; SI = days, DX:AX = seconds of the day
        MOV     CX,3600
        DIV     CX                      ; AX = hours, DX = seconds of the hour
        MOV     CH,AL
        MOV     AX,DX
        MOV     CL,60
        DIV     CL                      ; AL = minutes, AH = seconds
        MOV     DH,AH
        MOV     CL,AL
        XOR     DL,DL
        MOV     AX,SI
        POP     SI
        POP     BX
        RET

SETDATE:
        PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX
        PUSH    SI
        MOV     BX,AX
        CALL    EFFSEC
        CALL    SPLITSEC                ; SI = the days of the clock of DOS
        SUB     BX,SI                   ; the difference in days (signed)
        MOV     AX,BX
        MOV     DX,21600
        IMUL    DX                      ; DX:AX = days * 21600 (signed: 43200 would be negative)
        SHL     AX,1
        RCL     DX,1
        SHL     AX,1
        RCL     DX,1                    ; * 86400
        ADD     CS:[TOFF],AX
        ADC     CS:[TOFF+2],DX
        JMP     SHORT TIMEND

SETTIME:
        PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX
        PUSH    SI
        CALL    TODSEC                  ; DX:AX = the new seconds of the day
        PUSH    DX
        PUSH    AX
        CALL    EFFSEC
        CALL    SPLITSEC                ; DX:AX = the seconds of the day now
        POP     BX
        POP     CX                      ; CX:BX = the new seconds of the day
        SUB     BX,AX
        SBB     CX,DX                   ; the difference
        ADD     CS:[TOFF],BX
        ADC     CS:[TOFF+2],CX
TIMEND: POP     SI
        POP     DX
        POP     CX
        POP     BX
        POP     AX
        RET

; CH:CL:DH -> DX:AX = h * 3600 + m * 60 + s
TODSEC: PUSH    BX
        MOV     BL,DH
        XOR     BH,BH
        MOV     AL,CL
        MOV     DL,60
        MUL     DL                      ; AX = m * 60
        ADD     BX,AX
        MOV     AL,CH
        XOR     AH,AH
        MOV     DX,3600
        MUL     DX                      ; DX:AX = h * 3600
        ADD     AX,BX
        ADC     DX,0
        POP     BX
        RET

; DX:AX = the seconds since 1 January 1980 of the clock of OS-9
HOSTSEC:
        PUSH    BX
        PUSH    CX
        PUSH    SI
        CALL    RAWTIME                 ; AX = days, CH:CL:DH = the time
        PUSH    CX
        PUSH    DX
        MOV     BX,43200
        MUL     BX                      ; DX:AX = days * 43200
        SHL     AX,1
        RCL     DX,1                    ; * 86400
        MOV     BX,AX
        MOV     SI,DX
        POP     DX
        POP     CX
        CALL    TODSEC
        ADD     AX,BX
        ADC     DX,SI
        POP     SI
        POP     CX
        POP     BX
        RET

; DX:AX = the seconds of the clock of DOS
EFFSEC: CALL    HOSTSEC
        ADD     AX,CS:[TOFF]
        ADC     DX,CS:[TOFF+2]
        RET

; DX:AX = seconds -> SI = days, DX:AX = the seconds of the day
SPLITSEC:
        PUSH    BX
        PUSH    CX
        XOR     BX,BX
        SHR     DX,1
        RCR     AX,1
        RCL     BX,1                    ; BX = the bit that was lost
        MOV     CX,43200
        DIV     CX                      ; AX = days, DX = the half seconds of the day (the quotient is below 49711)
        MOV     SI,AX
        MOV     AX,DX
        XOR     DX,DX
        SHL     AX,1
        RCL     DX,1
        ADD     AX,BX
        ADC     DX,0
        POP     CX
        POP     BX
        RET

; the clock of OS-9: AX = days since 1 January 1980, CH:CL = hours:minutes, DH = seconds
RAWTIME:
        REQ     12
        PUSH    BX
        PUSH    SI
        MOV     AL,CS:[RQ+26]           ; year - 1900
        SUB     AL,80
        JAE     RTY80
        XOR     AL,AL
RTY80:  XOR     AH,AH                   ; AX = years since 1980
        MOV     SI,AX
        MOV     BX,365
        MUL     BX                      ; AX = years * 365
        MOV     BX,AX
        MOV     AX,SI
        ADD     AX,3
        SHR     AX,1
        SHR     AX,1                    ; leap days of the years before: (years + 3) / 4
        ADD     BX,AX
        MOV     AL,CS:[RQ+27]           ; month 1..12
        XOR     AH,AH
        DEC     AX
        CMP     AX,11
        JBE     RTMOK
        XOR     AX,AX
RTMOK:  SHL     AX,1
        MOV     SI,AX
        ADD     BX,CS:[MONTHDAYS+SI]
        MOV     AL,CS:[RQ+26]
        SUB     AL,80
        AND     AL,3
        JNZ     RTNOLEAP
        CMP     BYTE PTR CS:[RQ+27],2
        JBE     RTNOLEAP
        INC     BX                      ; 29 February of this year has passed
RTNOLEAP:
        MOV     AL,CS:[RQ+28]           ; day 1..31
        XOR     AH,AH
        DEC     AX
        ADD     AX,BX
        MOV     CH,CS:[RQ+29]
        MOV     CL,CS:[RQ+30]
        MOV     DH,CS:[RQ+31]
        XOR     DL,DL
        POP     SI
        POP     BX
        RET

MONTHDAYS:
        DW      0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334

;-----------------------------------------------------------------------------------------------------------------
RESEND  LABEL   BYTE                    ; the end of what stays in memory (the rest is the start up code, SYSINIT is moved by itself)

; start: the loader of the 6809 has written the memory size, the number of units and the BPBs, the reset vector jumps here
HWINIT: CLI
        XOR     AX,AX
        MOV     SS,AX
        MOV     SP,400h                 ; the stack is just below the BIOS
        MOV     ES,AX
        MOV     WORD PTR ES:[40h],OFFSET INT10
        MOV     ES:[42h],CS             ; INT 10h
        MOV     WORD PTR ES:[58h],OFFSET INT16
        MOV     ES:[5Ah],CS             ; INT 16h
        MOV     WORD PTR ES:[68h],OFFSET INT1A
        MOV     ES:[6Ah],CS             ; INT 1Ah
        MOV     WORD PTR ES:[388h],OFFSET GFXINT
        MOV     ES:[38Ah],CS            ; INT E2h
        PUSH    CS
        POP     DS
        CMP     BYTE PTR [PCFLAG],0     ; the text screen of the PC (dos -w=): blank cells, attribute 07h
        JE      HWNOPC
        MOV     AX,0B800h
        MOV     ES,AX
        XOR     DI,DI
        MOV     AX,0720h
        MOV     CX,2000
        CLD
        REP     STOSW
HWNOPC: MOV     AL,[UNITS]
        MOV     [DRVMAX],AL
        MOV     AX,CS                   ; the segments in the device headers
        MOV     [BCON+2],AX
        MOV     [BAUX+2],AX
        MOV     [BPRN+2],AX
        MOV     [BTIM+2],AX
        MOV     CL,4
        MOV     AX,OFFSET BIOSEND       ; the segment of SYSINIT: the next paragraph after this part
        SHR     AX,CL
        MOV     BX,CS
        ADD     BX,AX
        MOV     ES,BX
        ASSUME  ES:SYSINITSEG
        MOV     AX,OFFSET SYSSIZE + 15
        SHR     AX,CL
        ADD     AX,BX
        MOV     ES:[CURRENT_DOS_LOCATION],AX    ; where the 6809 has put the kernel
        MOV     AX,OFFSET RESEND + 15
        SHR     AX,CL
        MOV     DX,CS
        ADD     AX,DX
        MOV     ES:[FINAL_DOS_LOCATION],AX      ; right after what stays of the BIOS
        MOV     AX,[MEMSIZ]
        MOV     ES:[MEMORY_SIZE],AX
        MOV     WORD PTR ES:[DEVICE_LIST],OFFSET DEVSTART
        MOV     WORD PTR ES:[DEVICE_LIST+2],CS
        MOV     BYTE PTR ES:[DEFAULT_DRIVE],0
        PUSH    BX
        MOV     AX,OFFSET SYSINIT
        PUSH    AX
        RETF                            ; to SYSINIT
        ASSUME  ES:CODE

        ALIGN   16
BIOSEND LABEL   BYTE
CODE    ENDS

        INCLUDE SYSINIT2.ASM            ; SYSINITSEG: SYSINIT, patched

SYSINITSEG SEGMENT PUBLIC 'SYSTEM_INIT'
; the messages of SYSINIT (the SYSIMES of Microsoft is the one of an older version of SYSINIT)
BADOPM  DB      13,10,"Unrecognized command in CONFIG.SYS"
CRLFM   DB      13,10,'$'
BADSIZ_PRE DB   13,10,"Sector size too large in file $"
BADSIZ_POST DB  13,10,'$'
BADLD_PRE DB    13,10,"Bad or missing $"
BADLD_POST DB   13,10,'$'
BADCOM  DB      "Command Interpreter",0
BADCOUNTRY DB   13,10,"Bad country code",13,10,'$'
SYSSIZE LABEL   BYTE
SYSINITSEG ENDS
        END
