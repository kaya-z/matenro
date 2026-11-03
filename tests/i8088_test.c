/* SPDX-License-Identifier: MIT */
/*
 * i8088_test.c - tests of the 8088 core (src/i8088.c)
 *   1. runs the self checking program tests/i8088/core.bin (built from core.asm with nasm)
 *   2. clock counts of single instructions (Intel 8088: 8086 EU clocks + 4 per word transfer)
 *   3. reset state, interrupts (INTR, NMI, STI delay, HLT wake up, REP interruption, trap flag)
 * Build: make test-8088
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../src/subcpu.h"

uint32_t i8088_get_reg(void *z, const char *name);
void     i8088_set_reg(void *z, const char *name, uint32_t v);

static uint8_t mem[1 << 20];
static uint8_t ports[256];
static int power = -1;
static char conout[64];
static int nconout;
static uint8_t int_vec = 0x20;
static void *cpu;
static const sub_cpu_ops_t *ops;
static int fails, checks;

static uint8_t mrd(void *c, uint32_t a) { return mem[a & 0xfffff]; }
static void mwr(void *c, uint32_t a, uint8_t v) { mem[a & 0xfffff] = v; }
static uint8_t ird(void *c, uint16_t p) { return ports[p & 0xff]; }
static void iwr(void *c, uint16_t p, uint8_t v)
{
    p &= 0xff;
    if (p == 0x0e) { if (nconout < 63) conout[nconout++] = (char)v; }
    else if (p == 0x0f) power = v;
    else ports[p] = v;
}
static uint8_t iack(void *c) { return int_vec; }

#define EXPECT(what, got, want) do { checks++; unsigned g_ = (unsigned)(got), w_ = (unsigned)(want); \
    if (g_ != w_) { fails++; printf("FAIL %-36s got %05X want %05X (line %d)\n", what, g_, w_, __LINE__); } } while (0)
#define R(n) i8088_get_reg(cpu, n)

static void setup(void)
{
    memset(mem, 0, sizeof mem);
    memset(ports, 0, sizeof ports);
    power = -1; nconout = 0;
    ops->reset(cpu);
    i8088_set_reg(cpu, "cs", 0); i8088_set_reg(cpu, "ip", 0x100);
    i8088_set_reg(cpu, "ss", 0); i8088_set_reg(cpu, "sp", 0xf000);
    i8088_set_reg(cpu, "ds", 0); i8088_set_reg(cpu, "es", 0);
}

/* execute one instruction made of the given bytes, return its clocks */
static int clk_of(const uint8_t *code, int len)
{
    memcpy(mem + 0x100, code, len);
    i8088_set_reg(cpu, "cs", 0); i8088_set_reg(cpu, "ip", 0x100);
    return ops->step(cpu);
}
#define CLK(...) ({ static const uint8_t c_[] = { __VA_ARGS__ }; clk_of(c_, sizeof c_); })

int main(void)
{
    sub_bus_t bus = { 0, mrd, mwr, ird, iwr, iack };
    ops = &sub_cpu_i8088;
    cpu = ops->create(&bus);

    /* ---- 1. the self checking program ---- */
    {
        FILE *f = fopen("tests/i8088/core.bin", "rb");
        static uint8_t prog[4096];
        size_t n;
        long steps = 0;
        if (!f) { printf("tests/i8088/core.bin missing (run: make tests/i8088/core.bin)\n"); return 2; }
        n = fread(prog, 1, sizeof prog, f);
        fclose(f);
        setup();
        memcpy(mem + 0x400, prog, n);
        i8088_set_reg(cpu, "ip", 0x400);
        while (power < 0 && steps < 2000000) { ops->step(cpu); steps++; }
        checks++;
        if (power != 0xa5) {
            fails++;
            printf("FAIL core.bin: power=%02X failing check id=%d  CS:IP=%04X:%04X  [3000]=%04X SP=%04X\n", power & 0xff,
                   nconout ? (unsigned char)conout[0] : -1, R("cs"), R("ip"), mem[0x3000] | (mem[0x3001] << 8), R("sp"));
        } else printf("core.bin: all checks passed (%ld instructions)\n", steps);
    }

    /* ---- 2. clock counts ---- */
    setup();
    EXPECT("MOV AX,BX", CLK(0x89, 0xd8), 2);
    EXPECT("ADD AX,BX", CLK(0x01, 0xd8), 3);
    EXPECT("INC AX", CLK(0x40), 2);
    EXPECT("NOP", CLK(0x90), 3);
    EXPECT("MOV AX,1234", CLK(0xb8, 0x34, 0x12), 4);
    EXPECT("PUSH AX", CLK(0x50), 15);
    EXPECT("POP AX", CLK(0x58), 12);
    EXPECT("PUSHF", CLK(0x9c), 14);
    EXPECT("POPF", CLK(0x9d), 12);
    EXPECT("XCHG AX,BX", CLK(0x93), 3);
    EXPECT("MOV AX,[BX]", CLK(0x8b, 0x07), 17);          /* 8+5 EA, +4 word */
    EXPECT("MOV AL,[BX]", CLK(0x8a, 0x07), 13);
    EXPECT("MOV [BX],AX", CLK(0x89, 0x07), 18);
    EXPECT("ADD AX,[BX]", CLK(0x03, 0x07), 18);
    EXPECT("LEA AX,[BX+SI]", CLK(0x8d, 0x00), 9);
    EXPECT("JMP short", CLK(0xeb, 0x00), 15);
    EXPECT("JMP near", CLK(0xe9, 0x00, 0x00), 15);
    EXPECT("CALL near", CLK(0xe8, 0x00, 0x00), 23);
    mem[0x1000] = 0xc3;
    i8088_set_reg(cpu, "ip", 0x1000);
    EXPECT("RET", ops->step(cpu), 20);
    EXPECT("CALL far", CLK(0x9a, 0x00, 0x10, 0x00, 0x00), 36);
    EXPECT("RETF", ({ mem[0x1000] = 0xcb; ops->step(cpu); }), 34);
    EXPECT("JZ taken", ({ i8088_set_reg(cpu, "flags", 0x40); CLK(0x74, 0x00); }), 16);
    EXPECT("JZ not taken", ({ i8088_set_reg(cpu, "flags", 0); CLK(0x74, 0x00); }), 4);
    EXPECT("LOOP taken", ({ i8088_set_reg(cpu, "cx", 2); CLK(0xe2, 0x00); }), 17);
    EXPECT("LOOP not taken", ({ i8088_set_reg(cpu, "cx", 1); CLK(0xe2, 0x00); }), 5);
    EXPECT("SHL AX,1", CLK(0xd1, 0xe0), 2);
    EXPECT("SHL AX,CL (CL=4)", ({ i8088_set_reg(cpu, "cx", 4); CLK(0xd3, 0xe0); }), 24);
    EXPECT("MUL BL", CLK(0xf6, 0xe3), 70);
    EXPECT("DIV BL", ({ i8088_set_reg(cpu, "bx", 1); i8088_set_reg(cpu, "ax", 5); CLK(0xf6, 0xf3); }), 80);
    EXPECT("CBW", CLK(0x98), 2);
    EXPECT("CWD", CLK(0x99), 5);
    EXPECT("XLAT", CLK(0xd7), 11);
    EXPECT("CLC", CLK(0xf8), 2);
    EXPECT("IN AL,n", CLK(0xe4, 0x10), 10);
    EXPECT("OUT DX,AL", CLK(0xee), 8);
    EXPECT("REP MOVSB x3", ({ i8088_set_reg(cpu, "cx", 3); i8088_set_reg(cpu, "si", 0x2000); i8088_set_reg(cpu, "di", 0x3000);
        memcpy(mem + 0x100, (uint8_t[]){ 0xf3, 0xa4 }, 2); int t = 0;
        for (int i = 0; i < 3; i++) { i8088_set_reg(cpu, "ip", 0x100); t += ops->step(cpu); } t; }), 60);
    EXPECT("INT 80h", ({ mem[0x80 * 4] = 0x00; mem[0x80 * 4 + 1] = 0x20; i8088_set_reg(cpu, "sp", 0xf000); CLK(0xcd, 0x80); }), 71);
    mem[0x2000] = 0xcf;
    EXPECT("IRET", ops->step(cpu), 44);

    /* ---- 3. reset ---- */
    setup(); ops->reset(cpu);
    EXPECT("reset CS", R("cs"), 0xffff); EXPECT("reset IP", R("ip"), 0); EXPECT("reset flags", R("flags"), 0xf002);
    EXPECT("reset linear pc", ops->pc(cpu), 0xffff0);

    /* ---- 4. interrupts ---- */
    setup();                                         /* INTR with vector 20h; STI delays by one instruction */
    mem[0x20 * 4] = 0x00; mem[0x20 * 4 + 1] = 0x30;  /* handler at 0000:3000 */
    mem[0x3000] = 0xcf;                              /* IRET */
    memcpy(mem + 0x100, (uint8_t[]){ 0xfb, 0x90, 0x90, 0x90 }, 4);   /* STI NOP NOP NOP */
    ops->set_line(cpu, SUB_INT, 1);
    EXPECT("INTR masked while IF=0", ops->step(cpu), 2);     /* STI executes, interrupt still blocked */
    EXPECT("STI delay: next insn runs", ops->step(cpu), 3);
    EXPECT("INTR accepted T (61+20)", ops->step(cpu), 81);
    EXPECT("handler address", R("cs") * 16 + R("ip"), 0x3000);
    EXPECT("IF cleared on entry", R("flags") & 0x200, 0);
    EXPECT("pushed IP", mem[0xeffa] | (mem[0xeffb] << 8), 0x102);
    ops->set_line(cpu, SUB_INT, 0);
    EXPECT("IRET T", ops->step(cpu), 44);
    EXPECT("IRET restores IP", R("ip"), 0x102); EXPECT("IRET restores IF", R("flags") & 0x200, 0x200);

    setup();                                         /* NMI: vector 2, not maskable */
    mem[2 * 4] = 0x00; mem[2 * 4 + 1] = 0x31;
    memcpy(mem + 0x100, (uint8_t[]){ 0x90, 0x90 }, 2);
    ops->set_line(cpu, SUB_NMI, 1);
    EXPECT("NMI T (51+20)", ops->step(cpu), 71); EXPECT("NMI vector", R("ip"), 0x3100);
    ops->set_line(cpu, SUB_NMI, 0);

    setup();                                         /* HLT and wake up */
    memcpy(mem + 0x100, (uint8_t[]){ 0xfb, 0xf4, 0x90 }, 3);
    mem[0x20 * 4] = 0x00; mem[0x20 * 4 + 1] = 0x30; mem[0x3000] = 0xcf;
    ops->step(cpu); ops->step(cpu);
    EXPECT("HLT halted", ops->is_halted(cpu), 1);
    EXPECT("HLT idle", ops->step(cpu), 2);
    ops->set_line(cpu, SUB_INT, 1);
    ops->step(cpu);
    EXPECT("HLT woken", ops->is_halted(cpu), 0);
    EXPECT("HLT return address (after HLT)", mem[0xeffa] | (mem[0xeffb] << 8), 0x102);
    ops->set_line(cpu, SUB_INT, 0);

    setup();                                         /* REP MOVSB interrupted between iterations */
    for (int i = 0; i < 100; i++) mem[0x4000 + i] = (uint8_t)(i + 1);
    mem[0x20 * 4] = 0x00; mem[0x20 * 4 + 1] = 0x30; mem[0x3000] = 0xcf;
    memcpy(mem + 0x100, (uint8_t[]){ 0xfb, 0xf3, 0xa4, 0x90 }, 4);
    i8088_set_reg(cpu, "cx", 100); i8088_set_reg(cpu, "si", 0x4000); i8088_set_reg(cpu, "di", 0x5000);
    ops->step(cpu);                                  /* STI */
    for (int i = 0; i < 10; i++) ops->step(cpu);
    ops->set_line(cpu, SUB_INT, 1);
    ops->step(cpu);                                  /* accepted before the next iteration */
    ops->set_line(cpu, SUB_INT, 0);
    EXPECT("REP: saved IP is the REP prefix", mem[0xeffa] | (mem[0xeffb] << 8), 0x101);
    EXPECT("REP: CX after 10 iterations", R("cx"), 90);
    for (int i = 0; i < 200 && R("ip") != 0x103; i++) ops->step(cpu);
    EXPECT("REP: all bytes copied", mem[0x5000 + 99], 100); EXPECT("REP: CX = 0", R("cx"), 0);

    setup();                                         /* trap flag */
    mem[1 * 4] = 0x00; mem[1 * 4 + 1] = 0x32;
    memcpy(mem + 0x100, (uint8_t[]){ 0xb8, 0x00, 0x01, 0x50, 0x9d, 0x90, 0x90 }, 7);   /* MOV AX,100h; PUSH AX; POPF; NOP; NOP */
    for (int i = 0; i < 3; i++) ops->step(cpu);
    EXPECT("TF: no trap after POPF itself", R("ip"), 0x105);
    ops->step(cpu);
    EXPECT("TF: single step trap after NOP", R("ip"), 0x3200);

    /* ---- 4. the bus interface unit (set_timing): the 4 byte prefetch queue, 4 clocks per byte on the 8 bit bus ---- */
    {
        int i, total;
        unsigned rd, wr, rds = 0;
        setup();
        ops->set_timing(cpu, 1);
        memset(mem + 0x100, 0x90, 64);                           /* 64 NOPs: fetch limited, 4 clocks each (3 without the BIU) */
        i8088_set_reg(cpu, "cs", 0); i8088_set_reg(cpu, "ip", 0x100);
        for (total = 0, i = 0; i < 40; i++) { total += ops->step(cpu); ops->bus_cycles(cpu, &rd, &wr); rds += rd; }
        EXPECT("BIU: 40 NOPs: 4 clocks per byte after the 4 queued", total >= 140 && total <= 152, 1);
        EXPECT("BIU: about one bus cycle per 4 clocks", rds >= 34 && rds <= 40, 1);
        setup();
        ops->set_timing(cpu, 1);
        for (i = 0; i < 20; i++) { mem[0x100 + 2 * i] = 0x89; mem[0x101 + 2 * i] = 0xd8; }     /* MOV AX,BX x 20: 2 bytes in 2 clocks */
        i8088_set_reg(cpu, "cs", 0); i8088_set_reg(cpu, "ip", 0x100);
        for (total = 0, i = 0; i < 20; i++) total += ops->step(cpu);
        EXPECT("BIU: 20 MOV AX,BX: fetch limited (2 bytes = 8 clocks each)", total >= 140 && total <= 152, 1);
    }

    printf("8088: %d checks, %d failed\n", checks, fails);
    ops->destroy(cpu);
    return fails ? 1 : 0;
}
