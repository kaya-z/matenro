; drive.asm - CP/M-80 test: drives and user areas.  Run as  cpm -p=dir -m=B:/d1/drvb drive.com  in /d1 (RBF):
;   BDOS 25 = A: at first; BDOS 14 selects B: (mapped, 0) and C: (not mapped, 255); BDOS 24 = 0003h (A and B);
;   a file made with the drive byte 2 (B:) is in /d1/drvb, not in the current directory; a drive that is not mapped has
;   no files; BDOS 32 (user 3): a file made in the user area 3 is not seen in the user area 0.
;   Prints "DRIVE OK" or "DRIVE FAIL n".
BDOS    EQU     5
        ORG     100H
        LD      C,25            ; the current drive: A
        CALL    BDOS
        OR      A
        LD      B,1
        JP      NZ,FAIL
        LD      E,1             ; select B:
        LD      C,14
        CALL    BDOS
        OR      A
        LD      B,2
        JP      NZ,FAIL
        LD      C,25
        CALL    BDOS
        CP      1
        LD      B,3
        JP      NZ,FAIL
        LD      E,2             ; select C: (not mapped)
        LD      C,14
        CALL    BDOS
        CP      0FFH
        LD      B,4
        JP      NZ,FAIL
        LD      C,24            ; the login vector
        CALL    BDOS
        LD      A,H
        OR      A
        LD      B,5
        JP      NZ,FAIL
        LD      A,L
        CP      3
        LD      B,6
        JP      NZ,FAIL
        LD      E,0             ; back to A:
        LD      C,14
        CALL    BDOS
; a file made on B: (drive byte 2)
        LD      A,2
        CALL    SETFCB
        LD      DE,FCB
        LD      C,19            ; (an old one)
        CALL    BDOS
        LD      A,2
        CALL    SETFCB
        LD      DE,FCB
        LD      C,22
        CALL    BDOS
        INC     A
        LD      B,7
        JP      Z,FAIL
        LD      DE,FCB
        LD      C,16
        CALL    BDOS
        LD      A,0             ; not on A:
        CALL    SETFCB
        LD      DE,FCB
        LD      C,15
        CALL    BDOS
        INC     A
        LD      B,8
        JP      NZ,FAIL
        LD      A,2             ; on B:
        CALL    SETFCB
        LD      DE,FCB
        LD      C,15
        CALL    BDOS
        INC     A
        LD      B,9
        JP      Z,FAIL
        LD      DE,FCB
        LD      C,16
        CALL    BDOS
        LD      A,3             ; C: has nothing
        CALL    SETFCB
        LD      DE,FCB
        LD      C,15
        CALL    BDOS
        INC     A
        LD      B,10
        JP      NZ,FAIL
        LD      A,2             ; delete it on B:
        CALL    SETFCB
        LD      DE,FCB
        LD      C,19
        CALL    BDOS
        OR      A
        LD      B,11
        JP      NZ,FAIL
; the user area 3
        LD      E,3
        LD      C,32
        CALL    BDOS
        LD      E,0FFH
        LD      C,32
        CALL    BDOS
        CP      3
        LD      B,12
        JP      NZ,FAIL
        LD      A,0
        CALL    SETFCB
        LD      DE,FCB
        LD      C,22            ; made in the user area 3 (its directory U3 is made too)
        CALL    BDOS
        INC     A
        LD      B,13
        JP      Z,FAIL
        LD      DE,FCB
        LD      C,16
        CALL    BDOS
        LD      E,0             ; user 0: the file is not here
        LD      C,32
        CALL    BDOS
        LD      A,0
        CALL    SETFCB
        LD      DE,FCB
        LD      C,15
        CALL    BDOS
        INC     A
        LD      B,14
        JP      NZ,FAIL
        LD      E,3             ; user 3: it is
        LD      C,32
        CALL    BDOS
        LD      A,0
        CALL    SETFCB
        LD      DE,FCB
        LD      C,15
        CALL    BDOS
        INC     A
        LD      B,15
        JP      Z,FAIL
        LD      DE,FCB
        LD      C,16
        CALL    BDOS
        LD      A,0
        CALL    SETFCB
        LD      DE,FCB
        LD      C,19
        CALL    BDOS
        OR      A
        LD      B,16
        JP      NZ,FAIL
        LD      E,0
        LD      C,32
        CALL    BDOS
        LD      DE,OK
        LD      C,9
        CALL    BDOS
        RET
FAIL:   LD      A,'0'
        ADD     A,B
        CP      ':'
        JR      C,F1
        ADD     A,7
F1:     LD      (NUM),A
        LD      DE,BAD
        LD      C,9
        CALL    BDOS
        RET
; the FCB for DRV.TMP with the drive byte A
SETFCB: LD      (DR),A
        LD      HL,FCB
        LD      A,(DR)
        LD      (HL),A
        INC     HL
        LD      B,35
SF1:    LD      (HL),0
        INC     HL
        DJNZ    SF1
        LD      HL,NAME
        LD      DE,FCB+1
        LD      BC,11
        LDIR
        RET
NAME:   DB      'DRV     TMP'
DR:     DB      0
OK:     DB      'DRIVE OK',13,10,'$'
BAD:    DB      'DRIVE FAIL '
NUM:    DB      '0',13,10,'$'
FCB:    DS      36
