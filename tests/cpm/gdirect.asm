; gdirect.asm - CP/M-80 test program: the Z80 writes the picture of the HDMI screen itself.  BDOS 112 operation 9 makes the blocks 5 and 6 of its memory
; ($A000-$DFFF, 8 KB each) the first two blocks of the picture; after that a store there is a store into the picture (no 6809 in between).
; Here: every byte at $A000 + i gets (i AND 255) (a gradient), then the picture is shown.
        ORG     100H
        LD      DE,M1
        LD      C,112
        CALL    5
        LD      DE,M2
        LD      C,112
        CALL    5
        LD      HL,0A000H
        LD      DE,4000H                ; 16 KB
FILL:   LD      (HL),L
        INC     HL
        DEC     DE
        LD      A,D
        OR      E
        JR      NZ,FILL
        LD      DE,SHOW
        LD      C,112
        CALL    5
        LD      DE,U1                   ; its own memory again
        LD      C,112
        CALL    5
        LD      DE,U2
        LD      C,112
        CALL    5
        JP      0
M1:     DW      9,5,0,0,0,0,0           ; block 5 -> picture block 0
M2:     DW      9,6,1,0,0,0,0
SHOW:   DW      7,1,0,0,0,0,0
U1:     DW      9,5,0FFFFH,0,0,0,0
U2:     DW      9,6,0FFFFH,0,0,0,0
