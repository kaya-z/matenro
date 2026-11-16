; gdemo.asm - CP/M-80 test program: the graphics of the HDMI screen of the Tang Nano 20K (BDOS 112, see os9/cpm/cpmgfx.asm): a picture with a box, a frame,
; two lines, a point and a text; the same picture as gdemo86.asm
        ORG     100H
        LD      HL,TAB
        LD      B,8
LOOP:   LD      E,(HL)
        INC     HL
        LD      D,(HL)
        INC     HL
        PUSH    HL
        PUSH    BC
        LD      C,112
        CALL    5
        POP     BC
        POP     HL
        DJNZ    LOOP
        JP      0
TAB:    DW      B1,B2,B3,B4,B5,B6,B7,B8
B1:     DW      6,0,0,0,0,0,0           ; fill 0
B2:     DW      4,10,10,50,30,28,0      ; box 10 10 50 30 28
B3:     DW      3,5,5,100,60,255,0      ; rect 5 5 100 60 255
B4:     DW      2,0,0,319,239,7,0       ; line 0 0 319 239 7
B5:     DW      2,319,0,0,239,224,0     ; line 319 0 0 239 224
B6:     DW      1,160,120,0,0,255,0     ; pix 160 120 255
B7:     DW      5,8,160,0,0,255,16      ; text 8 160 255 16
        DB      'Hello from CP/M-80',0
B8:     DW      7,3,0,0,0,0,0           ; mode: the picture with the text over it
