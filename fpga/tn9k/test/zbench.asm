; zbench.asm - Z80 benchmark for the timing of the Matenro SoC (run by timing6809.asm): six loops of 2000 rounds, after
; each one the Z80 rings the 6809 (OUT (02)).  L0 is the loop itself (DEC DE, LD A,D, OR E, JR NZ); the others add 8 instructions to it:
;   L1 NOP   L2 LD A,(HL)   L3 LD (HL),A   L4 INC (HL)   L5 LD A,n      (HL = 0200h, in the RAM)
        ORG     0
        LD      SP,4000H
        LD      HL,0200H
        XOR     A
        OUT     (03H),A
        OUT     (02H),A         ; ready: the 6809 starts its clock
        LD      DE,2000
S0:     DEC     DE
        LD      A,D
        OR      E
        JR      NZ,S0
        OUT     (02H),A
        LD      DE,2000
S1:     NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        DEC     DE
        LD      A,D
        OR      E
        JR      NZ,S1
        OUT     (02H),A
        LD      DE,2000
S2:     LD      A,(HL)
        LD      A,(HL)
        LD      A,(HL)
        LD      A,(HL)
        LD      A,(HL)
        LD      A,(HL)
        LD      A,(HL)
        LD      A,(HL)
        DEC     DE
        LD      A,D
        OR      E
        JR      NZ,S2
        OUT     (02H),A
        LD      DE,2000
S3:     LD      (HL),A
        LD      (HL),A
        LD      (HL),A
        LD      (HL),A
        LD      (HL),A
        LD      (HL),A
        LD      (HL),A
        LD      (HL),A
        DEC     DE
        LD      A,D
        OR      E
        JR      NZ,S3
        OUT     (02H),A
        LD      DE,2000
S4:     INC     (HL)
        INC     (HL)
        INC     (HL)
        INC     (HL)
        INC     (HL)
        INC     (HL)
        INC     (HL)
        INC     (HL)
        DEC     DE
        LD      A,D
        OR      E
        JR      NZ,S4
        OUT     (02H),A
        LD      DE,2000
S5:     LD      A,1
        LD      A,1
        LD      A,1
        LD      A,1
        LD      A,1
        LD      A,1
        LD      A,1
        LD      A,1
        DEC     DE
        LD      A,D
        OR      E
        JR      NZ,S5
        OUT     (02H),A
HALTED: HALT
        JR      HALTED
