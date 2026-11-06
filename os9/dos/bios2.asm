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

; INT 10h, the video BIOS of the IBM PC that the programs of PC DOS (DEBUG) ask for: get the mode (80 columns, mode 3,
; page 0) and teletype output; everything else is ignored
INT10:  CMP     AH,0Fh
        JNE     I10A
        MOV     AX,5003h
        XOR     BH,BH
        IRET
I10A:   CMP     AH,0Eh
        JNE     I10B
        REQ     3
I10B:   IRET

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
CRLOOP: REQ     2
        MOV     AL,CS:[RQ+16]
        STOSB
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
CWLOOP: MOV     AL,ES:[DI]
        INC     DI
        REQ     3
        LOOP    CWLOOP
CWDONE: JMP     DEXIT

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
        PUSH    CS
        POP     DS
        MOV     AL,[UNITS]
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
