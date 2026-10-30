/* SPDX-License-Identifier: MIT */
/*
 * z80_test.c - known answer tests of the Z80 core (src/z80.c)
 *
 * Every expected value was worked out by hand from the Zilog manual and
 * "The Undocumented Z80 Documented" (flags incl. the X/Y bits, T states), not
 * produced by running the core.  Build: make test-z80
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../src/subcpu.h"

uint16_t z80_get_reg(void *z, const char *name);
void     z80_set_reg(void *z, const char *name, uint16_t v);

static uint8_t mem[65536];
static uint8_t in_val[256];
static int out_port = -1, out_val = -1;
static uint8_t int_vec = 0xff;
static void *cpu;
static int fails, checks;

static uint8_t mrd(void *c, uint32_t a) { return mem[a & 0xffff]; }
static void mwr(void *c, uint32_t a, uint8_t v) { mem[a & 0xffff] = v; }
static uint8_t ird(void *c, uint16_t p) { return in_val[p & 0xff]; }
static void iwr(void *c, uint16_t p, uint8_t v) { out_port = p; out_val = v; }
static uint8_t iack(void *c) { return int_vec; }

static const sub_cpu_ops_t *ops;

static void setup(void)
{
    memset(mem, 0, sizeof mem);
    memset(in_val, 0, sizeof in_val);
    out_port = out_val = -1;
    ops->reset(cpu);
    z80_set_reg(cpu, "pc", 0x100);
    z80_set_reg(cpu, "sp", 0xf000);
    z80_set_reg(cpu, "f", 0);
    z80_set_reg(cpu, "a", 0);
}

static int run(const uint8_t *code, int len, int nsteps)
{
    int t = 0;
    memcpy(mem + 0x100, code, len);
    z80_set_reg(cpu, "pc", 0x100);
    for (int i = 0; i < nsteps; i++) t += ops->step(cpu);
    return t;
}
#define RUN(nsteps, ...) ({ static const uint8_t c_[] = { __VA_ARGS__ }; run(c_, sizeof c_, nsteps); })

#define EXPECT(what, got, want) do { checks++; unsigned g_ = (unsigned)(got), w_ = (unsigned)(want); \
    if (g_ != w_) { fails++; printf("FAIL %-34s got %04X want %04X (line %d)\n", what, g_, w_, __LINE__); } } while (0)

#define A z80_get_reg(cpu, "a")
#define F z80_get_reg(cpu, "f")
#define R(n) z80_get_reg(cpu, n)

int main(void)
{
    sub_bus_t bus = { 0, mrd, mwr, ird, iwr, iack };
    ops = &sub_cpu_z80;
    cpu = ops->create(&bus);

    /* ---- 8 bit arithmetic: result and flags ---- */
    setup(); z80_set_reg(cpu, "a", 0x7f); z80_set_reg(cpu, "bc", 0x0100);
    EXPECT("ADD A,B T", RUN(1, 0x80), 4); EXPECT("ADD A,B 7F+01 A", A, 0x80); EXPECT("ADD A,B 7F+01 F", F, 0x94);

    setup(); z80_set_reg(cpu, "a", 0xff); z80_set_reg(cpu, "f", 1);
    RUN(1, 0x88); EXPECT("ADC A,B FF+0+1 A", A, 0); EXPECT("ADC A,B FF+0+1 F", F, 0x51);

    setup(); z80_set_reg(cpu, "a", 0x80); z80_set_reg(cpu, "bc", 0x0100);
    RUN(1, 0x90); EXPECT("SUB B 80-01 A", A, 0x7f); EXPECT("SUB B 80-01 F", F, 0x3e);

    setup(); z80_set_reg(cpu, "a", 0); z80_set_reg(cpu, "f", 1);
    RUN(1, 0x98); EXPECT("SBC A,B 0-0-1 A", A, 0xff); EXPECT("SBC A,B 0-0-1 F", F, 0xbb);

    setup(); z80_set_reg(cpu, "a", 0xf0); z80_set_reg(cpu, "bc", 0x0f00);
    RUN(1, 0xa0); EXPECT("AND B A", A, 0); EXPECT("AND B F", F, 0x54);

    setup(); z80_set_reg(cpu, "a", 0x55);
    RUN(1, 0xaf); EXPECT("XOR A A", A, 0); EXPECT("XOR A F", F, 0x44);

    setup(); z80_set_reg(cpu, "a", 1); z80_set_reg(cpu, "bc", 0x8000);
    RUN(1, 0xb0); EXPECT("OR B A", A, 0x81); EXPECT("OR B F", F, 0x84);

    setup(); z80_set_reg(cpu, "a", 0x10); z80_set_reg(cpu, "bc", 0x2000);
    RUN(1, 0xb8); EXPECT("CP B A unchanged", A, 0x10); EXPECT("CP B F (X/Y from operand)", F, 0xa3);

    setup(); z80_set_reg(cpu, "bc", 0xff00); z80_set_reg(cpu, "f", 1);
    EXPECT("INC B T", RUN(1, 0x04), 4); EXPECT("INC B F (C kept)", F, 0x51); EXPECT("INC B", R("b"), 0);

    setup(); z80_set_reg(cpu, "bc", 0x8000);
    RUN(1, 0x05); EXPECT("DEC B 80", R("b"), 0x7f); EXPECT("DEC B F", F, 0x3e);

    setup(); z80_set_reg(cpu, "a", 0x55);
    RUN(1, 0x2f); EXPECT("CPL A", A, 0xaa); EXPECT("CPL F", F, 0x3a);

    setup(); RUN(1, 0x37); EXPECT("SCF F", F, 0x01);
    setup(); z80_set_reg(cpu, "f", 1); RUN(1, 0x3f); EXPECT("CCF F", F, 0x10);
    setup(); z80_set_reg(cpu, "a", 0x80); RUN(1, 0x17); EXPECT("RLA A", A, 0); EXPECT("RLA F", F, 0x01);
    setup(); z80_set_reg(cpu, "a", 0x85); RUN(1, 0x07); EXPECT("RLCA A", A, 0x0b); EXPECT("RLCA F", F, 0x09);

    /* DAA */
    setup(); z80_set_reg(cpu, "a", 0x3c); RUN(1, 0x27); EXPECT("DAA 3C A", A, 0x42); EXPECT("DAA 3C F", F, 0x14);
    setup(); z80_set_reg(cpu, "a", 0x9a); RUN(1, 0x27); EXPECT("DAA 9A A", A, 0x00); EXPECT("DAA 9A F", F, 0x55);
    setup(); z80_set_reg(cpu, "a", 0x2d); z80_set_reg(cpu, "f", 0x12); RUN(1, 0x27);
    EXPECT("DAA after SUB A", A, 0x27); EXPECT("DAA after SUB F", F, 0x26);

    /* 16 bit */
    setup(); z80_set_reg(cpu, "hl", 0x0fff); z80_set_reg(cpu, "bc", 1);
    EXPECT("ADD HL,BC T", RUN(1, 0x09), 11); EXPECT("ADD HL,BC", R("hl"), 0x1000); EXPECT("ADD HL,BC F", F, 0x10);
    setup(); z80_set_reg(cpu, "hl", 0x1000); z80_set_reg(cpu, "de", 1);
    EXPECT("SBC HL,DE T", RUN(1, 0xed, 0x52), 15); EXPECT("SBC HL,DE", R("hl"), 0x0fff); EXPECT("SBC HL,DE F", F, 0x1a);
    setup(); z80_set_reg(cpu, "a", 0x80);
    EXPECT("NEG T", RUN(1, 0xed, 0x44), 8); EXPECT("NEG 80 A", A, 0x80); EXPECT("NEG 80 F", F, 0x87);
    setup(); z80_set_reg(cpu, "a", 1); RUN(1, 0xed, 0x44); EXPECT("NEG 01 A", A, 0xff); EXPECT("NEG 01 F", F, 0xbb);

    /* ---- rotate / bit ---- */
    setup(); z80_set_reg(cpu, "bc", 0x8500);
    EXPECT("RLC B T", RUN(1, 0xcb, 0x00), 8); EXPECT("RLC B", R("b"), 0x0b); EXPECT("RLC B F", F, 0x09);
    setup(); z80_set_reg(cpu, "bc", 0x8100); RUN(1, 0xcb, 0x28); EXPECT("SRA B", R("b"), 0xc0); EXPECT("SRA B F", F, 0x85);
    setup(); z80_set_reg(cpu, "bc", 0x0100); RUN(1, 0xcb, 0x30); EXPECT("SLL B", R("b"), 0x03); EXPECT("SLL B F", F, 0x04);
    setup(); z80_set_reg(cpu, "bc", 0x8000); RUN(1, 0xcb, 0x78); EXPECT("BIT 7,B F", F, 0x90);
    setup(); z80_set_reg(cpu, "bc", 0x8000); RUN(1, 0xcb, 0x40); EXPECT("BIT 0,B F", F, 0x54);
    setup(); z80_set_reg(cpu, "hl", 0x2000); mem[0x2000] = 0x01;
    EXPECT("SET 7,(HL) T", RUN(1, 0xcb, 0xfe), 15); EXPECT("SET 7,(HL)", mem[0x2000], 0x81);
    setup(); z80_set_reg(cpu, "hl", 0x2000); mem[0x2000] = 0xff;
    EXPECT("BIT 0,(HL) T", RUN(1, 0xcb, 0x46), 12); EXPECT("RES 0,(HL) T", RUN(1, 0xcb, 0x86), 15); EXPECT("RES 0,(HL)", mem[0x2000], 0xfe);
    setup(); z80_set_reg(cpu, "hl", 0x2000); z80_set_reg(cpu, "a", 0x12); mem[0x2000] = 0x34;
    EXPECT("RLD T", RUN(1, 0xed, 0x6f), 18); EXPECT("RLD A", A, 0x13); EXPECT("RLD mem", mem[0x2000], 0x42);
    setup(); z80_set_reg(cpu, "hl", 0x2000); z80_set_reg(cpu, "a", 0x12); mem[0x2000] = 0x34;
    RUN(1, 0xed, 0x67); EXPECT("RRD A", A, 0x14); EXPECT("RRD mem", mem[0x2000], 0x23);

    /* ---- loads and timing ---- */
    setup(); EXPECT("NOP T", RUN(1, 0x00), 4);
    setup(); EXPECT("LD A,n T", RUN(1, 0x3e, 0x99), 7); EXPECT("LD A,n", A, 0x99);
    setup(); z80_set_reg(cpu, "hl", 0x3000); EXPECT("LD (HL),n T", RUN(1, 0x36, 0x5a), 10); EXPECT("LD (HL),n", mem[0x3000], 0x5a);
    setup(); mem[0x4000] = 0x77; EXPECT("LD A,(nn) T", RUN(1, 0x3a, 0x00, 0x40), 13); EXPECT("LD A,(nn)", A, 0x77);
    setup(); z80_set_reg(cpu, "hl", 0xbeef); EXPECT("LD (nn),HL T", RUN(1, 0x22, 0x00, 0x50), 16);
    EXPECT("LD (nn),HL lo", mem[0x5000], 0xef); EXPECT("LD (nn),HL hi", mem[0x5001], 0xbe);
    setup(); z80_set_reg(cpu, "bc", 0x1234); EXPECT("LD (nn),BC T", RUN(1, 0xed, 0x43, 0x00, 0x50), 20); EXPECT("LD (nn),BC", mem[0x5000], 0x34);
    setup(); z80_set_reg(cpu, "bc", 0x1234); EXPECT("PUSH BC T", RUN(1, 0xc5), 11);
    EXPECT("PUSH BC sp", R("sp"), 0xeffe); EXPECT("PUSH BC mem", mem[0xefff], 0x12);
    EXPECT("POP DE T", RUN(1, 0xd1), 10); EXPECT("POP DE", R("de"), 0x1234);
    setup(); EXPECT("CALL T", RUN(1, 0xcd, 0x00, 0x20), 17); EXPECT("CALL pc", R("pc"), 0x2000); EXPECT("CALL ret lo", mem[0xeffe], 0x03);
    mem[0x2000] = 0xc9; EXPECT("RET T", ops->step(cpu), 10); EXPECT("RET pc", R("pc"), 0x103);
    setup(); EXPECT("JR taken T", RUN(1, 0x18, 0x05), 12); EXPECT("JR pc", R("pc"), 0x107);
    setup(); z80_set_reg(cpu, "f", 0x40); EXPECT("JR NZ not taken T", RUN(1, 0x20, 0x05), 7);
    setup(); z80_set_reg(cpu, "bc", 0x0200);
    { static const uint8_t c[] = { 0x10, 0xfe }; memcpy(mem + 0x100, c, 2); }
    EXPECT("DJNZ taken T", ops->step(cpu), 13); EXPECT("DJNZ not taken T", ops->step(cpu), 8); EXPECT("DJNZ pc", R("pc"), 0x102);
    setup(); z80_set_reg(cpu, "hl", 0x1111); mem[0xf000] = 0x22; mem[0xf001] = 0x33;
    EXPECT("EX (SP),HL T", RUN(1, 0xe3), 19); EXPECT("EX (SP),HL hl", R("hl"), 0x3322); EXPECT("EX (SP),HL mem", mem[0xf000], 0x11);
    setup(); EXPECT("RST 28 T", RUN(1, 0xef), 11); EXPECT("RST 28 pc", R("pc"), 0x28);
    setup(); z80_set_reg(cpu, "hl", 0x1234); RUN(1, 0xe9); EXPECT("JP (HL)", R("pc"), 0x1234);

    /* ---- IX / IY ---- */
    setup(); EXPECT("LD IX,nn T", RUN(1, 0xdd, 0x21, 0x00, 0x30), 14); EXPECT("LD IX,nn", R("ix"), 0x3000);
    EXPECT("LD (IX+5),n T", RUN(1, 0xdd, 0x36, 0x05, 0x77), 19); EXPECT("LD (IX+5),n", mem[0x3005], 0x77);
    EXPECT("LD A,(IX-1) T", ({ mem[0x2fff] = 0x42; RUN(1, 0xdd, 0x7e, 0xff); }), 19); EXPECT("LD A,(IX-1)", A, 0x42);
    EXPECT("INC (IX+5) T", RUN(1, 0xdd, 0x34, 0x05), 23); EXPECT("INC (IX+5)", mem[0x3005], 0x78);
    setup(); z80_set_reg(cpu, "ix", 0x1234); EXPECT("INC IXH T", RUN(1, 0xdd, 0x24), 8); EXPECT("INC IXH", R("ix"), 0x1334);
    RUN(1, 0xdd, 0x2e, 0x99); EXPECT("LD IXL,n", R("ix"), 0x1399);
    z80_set_reg(cpu, "a", 1); RUN(1, 0xdd, 0x84); EXPECT("ADD A,IXH", A, 0x14);
    setup(); z80_set_reg(cpu, "ix", 0x1000); z80_set_reg(cpu, "bc", 0x0234); RUN(1, 0xdd, 0x09); EXPECT("ADD IX,BC", R("ix"), 0x1234);
    setup(); z80_set_reg(cpu, "iy", 0x4000); z80_set_reg(cpu, "hl", 0x1111); mem[0x4002] = 0x5a;
    RUN(1, 0xfd, 0x66, 0x02); EXPECT("LD H,(IY+2) uses real H", R("hl"), 0x5a11);
    setup(); z80_set_reg(cpu, "ix", 0x3000); mem[0x3002] = 0x80;
    EXPECT("SET 0,(IX+2) T", RUN(1, 0xdd, 0xcb, 0x02, 0xc6), 23); EXPECT("SET 0,(IX+2)", mem[0x3002], 0x81);
    EXPECT("BIT 7,(IX+2) T", RUN(1, 0xdd, 0xcb, 0x02, 0x7e), 20);
    RUN(1, 0xdd, 0xcb, 0x02, 0x00); EXPECT("RLC (IX+2),B undocumented copy", R("b"), 0x03); EXPECT("RLC (IX+2),B mem", mem[0x3002], 0x03);

    /* ---- block instructions ---- */
    setup(); z80_set_reg(cpu, "hl", 0x2000); z80_set_reg(cpu, "de", 0x3000); z80_set_reg(cpu, "bc", 2); mem[0x2000] = 0xab;
    EXPECT("LDI T", RUN(1, 0xed, 0xa0), 16); EXPECT("LDI mem", mem[0x3000], 0xab); EXPECT("LDI bc", R("bc"), 1);
    EXPECT("LDI F (PV, X, Y)", F, 0x2c);
    setup(); z80_set_reg(cpu, "hl", 0x2000); z80_set_reg(cpu, "de", 0x3000); z80_set_reg(cpu, "bc", 3);
    mem[0x2000] = 1; mem[0x2001] = 2; mem[0x2002] = 3;
    { int t = 0; static const uint8_t c[] = { 0xed, 0xb0 }; memcpy(mem + 0x100, c, 2);
      for (int i = 0; i < 3; i++) t += ops->step(cpu);
      EXPECT("LDIR 3 bytes T (21+21+16)", t, 58); EXPECT("LDIR pc", R("pc"), 0x102); EXPECT("LDIR bc", R("bc"), 0);
      EXPECT("LDIR copy", mem[0x3002], 3); EXPECT("LDIR F PV clear", F & 4, 0); }
    setup(); z80_set_reg(cpu, "hl", 0x2000); z80_set_reg(cpu, "bc", 5); z80_set_reg(cpu, "a", 9); mem[0x2000] = 1; mem[0x2001] = 2; mem[0x2002] = 9;
    { static const uint8_t c[] = { 0xed, 0xb1 }; memcpy(mem + 0x100, c, 2);
      for (int i = 0; i < 3; i++) ops->step(cpu);
      EXPECT("CPIR found: hl", R("hl"), 0x2003); EXPECT("CPIR found: bc", R("bc"), 2); EXPECT("CPIR Z", F & 0x40, 0x40); EXPECT("CPIR pc", R("pc"), 0x102); }
    setup(); z80_set_reg(cpu, "hl", 0x2000); z80_set_reg(cpu, "bc", 0x0234); in_val[0x34] = 0x5a;
    EXPECT("INI T", RUN(1, 0xed, 0xa2), 16); EXPECT("INI mem", mem[0x2000], 0x5a); EXPECT("INI b", R("b"), 1);
    setup(); z80_set_reg(cpu, "hl", 0x2000); z80_set_reg(cpu, "bc", 0x0134); mem[0x2000] = 0x66;
    RUN(1, 0xed, 0xa3); EXPECT("OUTI port", out_port, 0x0034); EXPECT("OUTI value", out_val, 0x66); EXPECT("OUTI Z", F & 0x40, 0x40);

    /* ---- I/O ---- */
    setup(); z80_set_reg(cpu, "a", 0x12); EXPECT("OUT (n),A T", RUN(1, 0xd3, 0x34), 11);
    EXPECT("OUT (n),A port", out_port, 0x1234); EXPECT("OUT (n),A value", out_val, 0x12);
    setup(); in_val[0x56] = 0xc3; EXPECT("IN A,(n) T", RUN(1, 0xdb, 0x56), 11); EXPECT("IN A,(n)", A, 0xc3);
    setup(); z80_set_reg(cpu, "bc", 0x0077); in_val[0x77] = 0x80; EXPECT("IN D,(C) T", RUN(1, 0xed, 0x50), 12);
    EXPECT("IN D,(C)", R("d"), 0x80); EXPECT("IN D,(C) F", F, 0x80);
    setup(); z80_set_reg(cpu, "bc", 0x0077); RUN(1, 0xed, 0x71); EXPECT("OUT (C),0 value", out_val, 0);

    /* ---- registers: R, I ---- */
    setup(); RUN(3, 0x00, 0x00, 0x00); EXPECT("R after 3 NOP", R("r"), 3);
    setup(); RUN(1, 0xdd, 0x23); EXPECT("R after DD 23", R("r"), 2);
    setup(); z80_set_reg(cpu, "a", 0x80); RUN(2, 0xed, 0x4f, 0x00); EXPECT("LD R,A keeps bit 7", R("r") & 0x80, 0x80);
    setup(); z80_set_reg(cpu, "a", 0x55); EXPECT("LD I,A T", RUN(1, 0xed, 0x47), 9);
    z80_set_reg(cpu, "a", 0); RUN(1, 0xed, 0x57); EXPECT("LD A,I", A, 0x55); EXPECT("LD A,I Z clear", F & 0x40, 0);
    z80_set_reg(cpu, "a", 0); RUN(1, 0xed, 0x47); RUN(1, 0xed, 0x57); EXPECT("LD A,I zero", F & 0x44, 0x40);
    setup(); z80_set_reg(cpu, "bc", 0x1234); z80_set_reg(cpu, "hl", 0x5678); z80_set_reg(cpu, "de", 0x9abc);
    RUN(1, 0xd9); EXPECT("EXX bc", R("bc"), 0); RUN(1, 0xd9); EXPECT("EXX back", R("bc"), 0x1234);
    setup(); z80_set_reg(cpu, "hl", 0x1234); z80_set_reg(cpu, "de", 0xabcd); RUN(1, 0xeb); EXPECT("EX DE,HL", R("hl"), 0xabcd);
    setup(); z80_set_reg(cpu, "a", 0x12); z80_set_reg(cpu, "f", 0x34); RUN(1, 0x08); EXPECT("EX AF,AF' a", A, 0xff); RUN(1, 0x08); EXPECT("EX AF,AF' back", A, 0x12);

    /* ---- interrupts ---- */
    setup();                                       /* IM 1 + EI delay */
    { static const uint8_t c[] = { 0xed, 0x56, 0xfb, 0x00, 0x00 }; memcpy(mem + 0x100, c, sizeof c); }
    ops->step(cpu); ops->step(cpu);                 /* IM 1, EI */
    ops->set_line(cpu, SUB_INT, 1);
    EXPECT("EI delays one instruction: executes NOP", ops->step(cpu), 4); EXPECT("pc after NOP", R("pc"), 0x104);
    EXPECT("IM1 accept T", ops->step(cpu), 13); EXPECT("IM1 vector", R("pc"), 0x38); EXPECT("IFF1 cleared", R("iff1"), 0);
    EXPECT("IM1 pushed pc", mem[0xeffe], 0x04);
    /* IM 2 */
    setup();
    { static const uint8_t c[] = { 0x3e, 0x40, 0xed, 0x47, 0xed, 0x5e, 0xfb, 0x00, 0x00 }; memcpy(mem + 0x100, c, sizeof c); }
    mem[0x4010] = 0x34; mem[0x4011] = 0x12; int_vec = 0x10;
    for (int i = 0; i < 5; i++) ops->step(cpu);       /* LD A,40; LD I,A; IM 2; EI; NOP */
    ops->set_line(cpu, SUB_INT, 1);
    EXPECT("IM2 accept T", ops->step(cpu), 19); EXPECT("IM2 vector", R("pc"), 0x1234);
    ops->set_line(cpu, SUB_INT, 0); int_vec = 0xff;
    setup();                                       /* NMI */
    { static const uint8_t c[] = { 0xfb, 0x00, 0x00 }; memcpy(mem + 0x100, c, sizeof c); }
    ops->step(cpu); ops->step(cpu);
    ops->set_line(cpu, SUB_NMI, 1);
    EXPECT("NMI T", ops->step(cpu), 11); EXPECT("NMI vector", R("pc"), 0x66); EXPECT("NMI clears IFF1", R("iff1"), 0);
    mem[0x66] = 0xed; mem[0x67] = 0x45;               /* RETN */
    EXPECT("RETN T", ops->step(cpu), 14); EXPECT("RETN pc", R("pc"), 0x102); EXPECT("RETN restores IFF1", R("iff1"), 1);
    ops->set_line(cpu, SUB_NMI, 0);
    setup();                                       /* HALT and wake up */
    { static const uint8_t c[] = { 0xfb, 0x76, 0x00 }; memcpy(mem + 0x100, c, sizeof c); }
    ops->step(cpu); ops->step(cpu);
    EXPECT("HALT state", ops->is_halted(cpu), 1); EXPECT("HALT idle T", ops->step(cpu), 4); EXPECT("HALT pc stays", R("pc"), 0x102);
    ops->set_line(cpu, SUB_INT, 1); int_vec = 0xff;
    EXPECT("HALT woken by INT (IM0 -> RST 38) T", ops->step(cpu), 13); EXPECT("HALT return address", mem[0xeffe], 0x02);
    EXPECT("HALT cleared", ops->is_halted(cpu), 0);

    printf("z80: %d checks, %d failed\n", checks, fails);
    ops->destroy(cpu);
    return fails ? 1 : 0;
}
