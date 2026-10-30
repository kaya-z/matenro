* xlink_test.asm - MC6809 side of the Matenro integration test
* (MIT license)  Assembled with a09 of the sbc09 project (tools/a09, GPL v2, used as a tool only).
*
* 1. identify the sub CPU          2. load its program into the shared RAM through the window port
* 3. release it, wait for its "ready" doorbell (FIRQ)
* 4. mailbox request n=10 -> reply 55, n=100 -> reply 5050 (doorbell both ways, FIRQ, ACK)
* 5. read the result directly through the 6809 MMU (shared RAM, XC_SHR) and through the window port
* 6. SMMU registers, status bits
*
* The sub CPU program is put behind the label 'chunks' by tests/matenro_test.py.
SUBID   equ @SUBID@
XCTL    equ $FFC9
XSTAT   equ $FFCA               read: status      write: acknowledge the doorbell of the sub CPU
XID     equ $FFCB               read: sub CPU id  write: ring the sub CPU
XIDX    equ $FFCC               extended register index (bit 7: auto increment)
XDAT    equ $FFCD               extended register data
XBELL   equ XID
XACK    equ XSTAT
ACIA    equ $FF81
PWR     equ $FF8F
MMU1    equ $FFA1
FLAG    equ $0100

        org $E000
start   lds #$1F00
        clr FLAG
        andcc #$AF              enable IRQ and FIRQ
        lda XID
        cmpa #SUBID
        lbne fail1
        ldu #chunks
ld_next ldx 3,u
        beq ld_done
        lda #$8A                XE_WA, auto increment
        sta XIDX
        lda ,u
        sta XDAT
        lda 1,u
        sta XDAT
        lda 2,u
        sta XDAT
        lda #$0D                XE_WD, no auto increment
        sta XIDX
        leay 5,u
ld_byte lda ,y+
        sta XDAT
        leax -1,x
        bne ld_byte
        tfr y,u
        bra ld_next
ld_done lda #$19                RUN | FIRQ | IEN
        sta XCTL
        jsr waitf               "ready" doorbell of the sub CPU
        lda #$80                XE_M2S, auto increment
        sta XIDX
        lda #10
        sta XDAT
        clra
        sta XBELL
        jsr waitf
        lda #$84                XE_S2M
        sta XIDX
        lda XDAT
        cmpa #$37
        lbne fail2
        lda XDAT
        lbne fail2
        lda XCTL
        ora #$04                XC_SHR : the 6809 MMU may map the shared pool
        sta XCTL
        lda #$80
        sta MMU1                $2000-$3FFF -> physical block $80 (= sub CPU address 0)
        ldd $2100
        cmpd #$3700
        lbne fail3
        lda #$80
        sta XIDX
        lda #100
        sta XDAT
        clra
        sta XBELL
        jsr waitf
        lda #$84
        sta XIDX
        lda XDAT
        cmpa #$BA
        lbne fail4
        lda XDAT
        cmpa #$13
        lbne fail4
        ldd $2100
        cmpd #$BA13
        lbne fail5
        lda #$8A                window read of physical $100100
        sta XIDX
        lda #$10
        sta XDAT
        lda #$01
        sta XDAT
        clra                    (not CLR: a read-modify-write instruction would read XDAT first)
        sta XDAT
        lda #$0D
        sta XIDX
        lda XDAT
        cmpa #$BA
        lbne fail6
        lda XDAT
        cmpa #$13
        lbne fail6
        lda #$08                XE_MI : SMMU entry 0 is physical block $80
        sta XIDX
        clra
        sta XDAT
        lda #$09                XE_MD
        sta XIDX
        lda XDAT
        cmpa #$80
        lbne fail7
        lda XSTAT               the sub CPU sits in HLT, running, no doorbell pending
        anda #$0F
        cmpa #$0C
        lbne fail8
        lda #$8E                XE_KHZ
        sta XIDX
        lda XDAT
        ldb XDAT
        cmpd #8000
        lbne fail9
        ldx #msgpass
        jsr puts
        lda #$A5
        sta PWR
done    bra done

waitf   ldx #$FFFF
wf1     tst FLAG
        bne wf2
        leax -1,x
        bne wf1
        lbra fail10
wf2     clr FLAG
        rts

puts    lda ,x+
        beq puts9
        sta ACIA
        bra puts
puts9   rts

firq    pshs a
        sta XACK
        lda #1
        sta FLAG
        puls a
        rti

fail1   lda #'1'
        bra failn
fail2   lda #'2'
        bra failn
fail3   lda #'3'
        bra failn
fail4   lda #'4'
        bra failn
fail5   lda #'5'
        bra failn
fail6   lda #'6'
        bra failn
fail7   lda #'7'
        bra failn
fail8   lda #'8'
        bra failn
fail9   lda #'9'
        bra failn
fail10  lda #'T'
failn   pshs a
        ldx #msgfail
        jsr puts
        puls a
        sta ACIA
        lda #13
        sta ACIA
        lda #10
        sta ACIA
        lda #$A6
        sta PWR
halt    bra halt

msgpass fcc /PASS/
        fcb 13,10,0
msgfail fcc /FAIL /
        fcb 0

chunks
@CHUNKS@
        fdb 0,0                 terminator (length 0)

        org $FFF6
        fdb firq
        org $FFFE
        fdb start
