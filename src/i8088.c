/* SPDX-License-Identifier: MIT */
/*
 * i8088.c - Intel 8088 CPU core (sub CPU backend of the Matenro machine)
 *
 * Credits / references
 * --------------------
 * Written from the public Intel documentation:
 *   - "MCS-86 / iAPX 86,88 User's Manual" (instruction set, flags, EA and
 *     execution unit clock counts, interrupt sequence, reset state)
 *   - "The 8086/8088 Primer" style opcode tables (the undocumented 8086
 *     aliases 60-6F = 70-7F, C0/C1/C8/C9, F1, 82 and the /6 shift are
 *     implemented as on the real 8086/8088, SALC D6 as well)
 * No code of any other x86 emulator was copied; this is an independent
 * implementation.  The step() interface follows the sim09 MC6809 core.
 *
 * Timing model: the execution unit clock counts of the 8086 manual (base +
 * effective address calculation) plus 4 clocks for every 16 bit memory /
 * stack / vector transfer, which is the rule Intel gives for the 8-bit bus
 * of the 8088.  The prefetch queue and the bus interface unit are NOT
 * modelled, so the clock counts are an approximation (typically within a few
 * percent for data-bound code, optimistic for code that is bound by
 * instruction fetch).
 */
#include <stdlib.h>
#include <string.h>
#include "subcpu.h"

#define CF 0x0001
#define PF 0x0004
#define AF 0x0010
#define ZF 0x0040
#define SF 0x0080
#define TF 0x0100
#define IFL 0x0200
#define DF 0x0400
#define OF 0x0800

enum { AX, CX, DX, BX, SP, BP, SI, DI };
enum { ES, CS, SS, DS };

typedef struct i8088 {
    uint16_t w[8];
    uint16_t seg[4];
    uint16_t ip;
    uint16_t fl;
    sub_bus_t bus;
    uint8_t  int_line, nmi_line, nmi_edge;
    uint8_t  halted;
    uint8_t  inhibit;          /* no interrupt after MOV SS / POP SS / STI */
    uint8_t  rep_resume;       /* the REP instruction is continuing        */
    uint64_t insns;
    int      t;                /* clocks of this step                      */
    /* decoded modrm */
    int      mod, reg, rm;
    uint16_t ea_off;
    int      ea_seg;           /* segment register index of the operand    */
    int      ovr;              /* segment override: -1 none                */
    uint16_t start_ip;
    uint32_t cs_ip_start;
    /* bus interface unit (set_timing): the prefetch queue of the 8088 holds 4 bytes, a bus cycle on the 8 bit bus takes 4 clocks */
    int      biu;
    int      q;                /* bytes in the queue                        */
    int      credit;           /* clocks of the byte that the BIU is fetching */
    int      nfetch, ndr, ndw; /* instruction bytes, data reads, data writes of this step */
    unsigned bus_rd, bus_wr;   /* bus cycles of the last step               */
} i8088_t;

static uint8_t parity_tab[256];
static int tab_init;

static void init_tab(void)
{
    if (tab_init) return;
    for (int i = 0; i < 256; i++) {
        int p = 1;
        for (int b = 0; b < 8; b++) if (i & (1 << b)) p ^= 1;
        parity_tab[i] = p ? PF : 0;
    }
    tab_init = 1;
}

/* ---------------------------------------------------------------- */
/* memory                                                            */
/* ---------------------------------------------------------------- */
static inline uint32_t lin(uint16_t seg, uint16_t off) { return (((uint32_t)seg << 4) + off) & 0xfffff; }
static inline uint8_t  rd8(i8088_t *z, uint16_t seg, uint16_t off) { z->ndr++; return z->bus.mem_read(z->bus.ctx, lin(seg, off)); }
static inline void     wr8(i8088_t *z, uint16_t seg, uint16_t off, uint8_t v) { z->ndw++; z->bus.mem_write(z->bus.ctx, lin(seg, off), v); }
static inline uint16_t rd16(i8088_t *z, uint16_t seg, uint16_t off)
{
    z->t += 4;                               /* 8 bit bus: second bus cycle */
    return (uint16_t)(rd8(z, seg, off) | (rd8(z, seg, (uint16_t)(off + 1)) << 8));
}
static inline void wr16(i8088_t *z, uint16_t seg, uint16_t off, uint16_t v)
{
    z->t += 4;
    wr8(z, seg, off, (uint8_t)v);
    wr8(z, seg, (uint16_t)(off + 1), (uint8_t)(v >> 8));
}
static inline uint8_t fetch8(i8088_t *z) { z->nfetch++; return z->bus.mem_read(z->bus.ctx, lin(z->seg[CS], z->ip++)); }
static inline uint16_t fetch16(i8088_t *z)
{
    uint16_t lo = fetch8(z);
    return (uint16_t)(lo | (fetch8(z) << 8));
}
static inline void push16(i8088_t *z, uint16_t v)
{
    z->w[SP] = (uint16_t)(z->w[SP] - 2);
    wr16(z, z->seg[SS], z->w[SP], v);
}
static inline uint16_t pop16(i8088_t *z)
{
    uint16_t v = rd16(z, z->seg[SS], z->w[SP]);
    z->w[SP] = (uint16_t)(z->w[SP] + 2);
    return v;
}

/* ---------------------------------------------------------------- */
/* registers                                                         */
/* ---------------------------------------------------------------- */
static inline uint8_t get_r8(i8088_t *z, int n)
{
    return (n & 4) ? (uint8_t)(z->w[n & 3] >> 8) : (uint8_t)z->w[n & 3];
}
static inline void set_r8(i8088_t *z, int n, uint8_t v)
{
    if (n & 4) z->w[n & 3] = (uint16_t)((z->w[n & 3] & 0x00ff) | (v << 8));
    else       z->w[n & 3] = (uint16_t)((z->w[n & 3] & 0xff00) | v);
}
#define AL(z) get_r8(z, 0)
#define AH(z) get_r8(z, 4)

/* ---------------------------------------------------------------- */
/* modrm                                                             */
/* ---------------------------------------------------------------- */
static void modrm(i8088_t *z)
{
    uint8_t m = fetch8(z);
    z->mod = m >> 6; z->reg = (m >> 3) & 7; z->rm = m & 7;
    if (z->mod == 3) return;
    uint16_t off = 0;
    int dseg = DS, clk = 0;
    switch (z->rm) {
    case 0: off = (uint16_t)(z->w[BX] + z->w[SI]); clk = 7; break;
    case 1: off = (uint16_t)(z->w[BX] + z->w[DI]); clk = 8; break;
    case 2: off = (uint16_t)(z->w[BP] + z->w[SI]); clk = 8; dseg = SS; break;
    case 3: off = (uint16_t)(z->w[BP] + z->w[DI]); clk = 7; dseg = SS; break;
    case 4: off = z->w[SI]; clk = 5; break;
    case 5: off = z->w[DI]; clk = 5; break;
    case 6: off = z->w[BP]; clk = 5; dseg = SS; break;
    default: off = z->w[BX]; clk = 5; break;
    }
    if (z->mod == 0 && z->rm == 6) { off = fetch16(z); clk = 6; dseg = DS; }
    else if (z->mod == 1) { off = (uint16_t)(off + (int8_t)fetch8(z)); clk += (z->rm < 4) ? 4 : 4; }
    else if (z->mod == 2) { off = (uint16_t)(off + fetch16(z)); clk += 4; }
    z->ea_off = off;
    z->ea_seg = (z->ovr >= 0) ? z->ovr : dseg;
    if (z->ovr >= 0) clk += 2;
    z->t += clk;
}

static inline uint8_t  ev8(i8088_t *z)  { return z->mod == 3 ? get_r8(z, z->rm) : rd8(z, z->seg[z->ea_seg], z->ea_off); }
static inline void     sev8(i8088_t *z, uint8_t v) { if (z->mod == 3) set_r8(z, z->rm, v); else wr8(z, z->seg[z->ea_seg], z->ea_off, v); }
static inline uint16_t ev16(i8088_t *z) { return z->mod == 3 ? z->w[z->rm] : rd16(z, z->seg[z->ea_seg], z->ea_off); }
static inline void     sev16(i8088_t *z, uint16_t v) { if (z->mod == 3) z->w[z->rm] = v; else wr16(z, z->seg[z->ea_seg], z->ea_off, v); }

/* ---------------------------------------------------------------- */
/* ALU                                                               */
/* ---------------------------------------------------------------- */
static inline void set_szp(i8088_t *z, uint32_t r, int w16)
{
    uint32_t mask = w16 ? 0xffff : 0xff, sign = w16 ? 0x8000 : 0x80;
    z->fl &= ~(ZF | SF | PF);
    if (!(r & mask)) z->fl |= ZF;
    if (r & sign) z->fl |= SF;
    z->fl |= parity_tab[r & 0xff];
}

/* op: 0 ADD 1 OR 2 ADC 3 SBB 4 AND 5 SUB 6 XOR 7 CMP; returns result (CMP: unchanged a, caller must not store) */
static uint16_t alu(i8088_t *z, int op, uint16_t a, uint16_t b, int w16)
{
    uint32_t mask = w16 ? 0xffff : 0xff, sign = w16 ? 0x8000 : 0x80;
    uint32_t r;
    int c = (z->fl & CF) ? 1 : 0;
    switch (op) {
    case 0: case 2:
        if (op == 0) c = 0;
        r = (uint32_t)a + b + c;
        z->fl &= ~(CF | AF | OF);
        if (r > mask) z->fl |= CF;
        if ((a ^ b ^ r) & 0x10) z->fl |= AF;
        if ((a ^ r) & (b ^ r) & sign) z->fl |= OF;
        break;
    case 3: case 5: case 7:
        if (op != 3) c = 0;
        r = (uint32_t)a - b - c;
        z->fl &= ~(CF | AF | OF);
        if ((uint32_t)a < (uint32_t)b + c) z->fl |= CF;
        if ((a ^ b ^ r) & 0x10) z->fl |= AF;
        if ((a ^ b) & (a ^ r) & sign) z->fl |= OF;
        break;
    case 1: r = a | b; z->fl &= ~(CF | OF | AF); break;
    case 4: r = a & b; z->fl &= ~(CF | OF | AF); break;
    default: r = a ^ b; z->fl &= ~(CF | OF | AF); break;
    }
    set_szp(z, r, w16);
    return (uint16_t)(r & mask);
}

static uint16_t incdec(i8088_t *z, uint16_t a, int dec, int w16)
{
    uint32_t sign = w16 ? 0x8000 : 0x80, mask = w16 ? 0xffff : 0xff;
    uint32_t r = dec ? (uint32_t)a - 1 : (uint32_t)a + 1;
    z->fl &= ~(AF | OF);
    if ((a ^ 1 ^ r) & 0x10) z->fl |= AF;
    if (dec ? ((a & sign) && !(r & sign)) : (!(a & sign) && (r & sign))) z->fl |= OF;
    set_szp(z, r, w16);
    return (uint16_t)(r & mask);
}

/* shifts and rotates (group D0-D3) */
static uint16_t shift(i8088_t *z, int op, uint16_t v, unsigned cnt, int w16)
{
    uint32_t mask = w16 ? 0xffff : 0xff, sign = w16 ? 0x8000 : 0x80;
    uint32_t a = v;
    if (!cnt) return v;
    for (unsigned i = 0; i < cnt; i++) {
        uint32_t oldsign = a & sign;
        switch (op) {
        case 0: {                                       /* ROL */
            uint32_t c = a & sign ? 1 : 0;
            a = ((a << 1) | c) & mask;
            z->fl = (z->fl & ~(CF | OF)) | (c ? CF : 0) | (((a & sign) ? 1u : 0u) ^ c ? OF : 0);
            break; }
        case 1: {                                       /* ROR */
            uint32_t c = a & 1;
            a = (a >> 1) | (c ? sign : 0);
            z->fl = (z->fl & ~(CF | OF)) | (c ? CF : 0) | (((a & sign) ? 1u : 0u) ^ ((a & (sign >> 1)) ? 1u : 0u) ? OF : 0);
            break; }
        case 2: {                                       /* RCL */
            uint32_t c = a & sign ? 1 : 0;
            a = ((a << 1) | (z->fl & CF ? 1 : 0)) & mask;
            z->fl = (z->fl & ~(CF | OF)) | (c ? CF : 0) | (((a & sign) ? 1u : 0u) ^ c ? OF : 0);
            break; }
        case 3: {                                       /* RCR */
            uint32_t c = a & 1;
            uint32_t oldcf = z->fl & CF ? 1 : 0;
            a = (a >> 1) | (oldcf ? sign : 0);
            z->fl = (z->fl & ~(CF | OF)) | (c ? CF : 0) | (((a & sign) ? 1u : 0u) ^ ((a & (sign >> 1)) ? 1u : 0u) ? OF : 0);
            break; }
        case 4: case 6: {                               /* SHL / SAL (/6 is an alias) */
            uint32_t c = a & sign ? 1 : 0;
            a = (a << 1) & mask;
            z->fl = (z->fl & ~(CF | OF | AF)) | (c ? CF : 0) | ((((a & sign) ? 1u : 0u) ^ c) ? OF : 0);
            set_szp(z, a, w16);
            break; }
        case 5: {                                       /* SHR */
            uint32_t c = a & 1;
            a >>= 1;
            z->fl = (z->fl & ~(CF | OF | AF)) | (c ? CF : 0) | (oldsign ? OF : 0);
            set_szp(z, a, w16);
            break; }
        default: {                                      /* SAR */
            uint32_t c = a & 1;
            a = (a >> 1) | oldsign;
            z->fl = (z->fl & ~(CF | OF | AF)) | (c ? CF : 0);
            set_szp(z, a, w16);
            break; }
        }
    }
    return (uint16_t)a;
}

/* ---------------------------------------------------------------- */
/* interrupts                                                        */
/* ---------------------------------------------------------------- */
static void do_int(i8088_t *z, int vec)
{
    push16(z, (uint16_t)(z->fl | 0xf002));
    z->fl &= ~(IFL | TF);
    push16(z, z->seg[CS]);
    push16(z, z->ip);
    z->ip = rd16(z, 0, (uint16_t)(vec * 4));
    z->seg[CS] = rd16(z, 0, (uint16_t)(vec * 4 + 2));
}

static int cc_test(i8088_t *z, int cc)
{
    int r;
    switch (cc >> 1) {
    case 0: r = z->fl & OF; break;
    case 1: r = z->fl & CF; break;
    case 2: r = z->fl & ZF; break;
    case 3: r = (z->fl & CF) || (z->fl & ZF); break;
    case 4: r = z->fl & SF; break;
    case 5: r = z->fl & PF; break;
    case 6: r = ((z->fl & SF) != 0) != ((z->fl & OF) != 0); break;
    default: r = (z->fl & ZF) || (((z->fl & SF) != 0) != ((z->fl & OF) != 0)); break;
    }
    return (cc & 1) ? !r : !!r;
}

static void divide_error(i8088_t *z) { do_int(z, 0); z->t += 51; }

/* ---------------------------------------------------------------- */
/* group 3 (F6/F7): TEST NOT NEG MUL IMUL DIV IDIV                    */
/* ---------------------------------------------------------------- */
static void group3(i8088_t *z, int w16)
{
    int mem = z->mod != 3;
    switch (z->reg) {
    case 0: case 1: {                                   /* TEST Ev,imm */
        uint16_t a = w16 ? ev16(z) : ev8(z);
        uint16_t b = w16 ? fetch16(z) : fetch8(z);
        alu(z, 4, a, b, w16);
        z->t += mem ? 11 : 5;
        break; }
    case 2: {                                           /* NOT */
        if (w16) sev16(z, (uint16_t)~ev16(z)); else sev8(z, (uint8_t)~ev8(z));
        z->t += mem ? 16 : 3;
        break; }
    case 3: {                                           /* NEG */
        uint16_t a = w16 ? ev16(z) : ev8(z);
        uint16_t r = alu(z, 5, 0, a, w16);
        if (a) z->fl |= CF; else z->fl &= ~CF;
        if (w16) sev16(z, r); else sev8(z, (uint8_t)r);
        z->t += mem ? 16 : 3;
        break; }
    case 4: {                                           /* MUL */
        if (w16) {
            uint32_t r = (uint32_t)z->w[AX] * ev16(z);
            z->w[AX] = (uint16_t)r; z->w[DX] = (uint16_t)(r >> 16);
            z->fl &= ~(CF | OF); if (z->w[DX]) z->fl |= CF | OF;
            z->t += mem ? 124 : 118;
        } else {
            uint16_t r = (uint16_t)(AL(z) * ev8(z));
            z->w[AX] = r;
            z->fl &= ~(CF | OF); if (r >> 8) z->fl |= CF | OF;
            z->t += mem ? 76 : 70;
        }
        break; }
    case 5: {                                           /* IMUL */
        if (w16) {
            int32_t r = (int32_t)(int16_t)z->w[AX] * (int16_t)ev16(z);
            z->w[AX] = (uint16_t)r; z->w[DX] = (uint16_t)((uint32_t)r >> 16);
            z->fl &= ~(CF | OF); if (r != (int16_t)r) z->fl |= CF | OF;
            z->t += mem ? 134 : 128;
        } else {
            int16_t r = (int16_t)((int8_t)AL(z) * (int8_t)ev8(z));
            z->w[AX] = (uint16_t)r;
            z->fl &= ~(CF | OF); if (r != (int8_t)r) z->fl |= CF | OF;
            z->t += mem ? 86 : 80;
        }
        break; }
    case 6: {                                           /* DIV */
        if (w16) {
            uint16_t d = ev16(z);
            uint32_t n = ((uint32_t)z->w[DX] << 16) | z->w[AX];
            if (!d || n / d > 0xffff) { divide_error(z); return; }
            z->w[AX] = (uint16_t)(n / d); z->w[DX] = (uint16_t)(n % d);
            z->t += mem ? 150 : 144;
        } else {
            uint8_t d = ev8(z);
            uint16_t n = z->w[AX];
            if (!d || n / d > 0xff) { divide_error(z); return; }
            set_r8(z, 0, (uint8_t)(n / d)); set_r8(z, 4, (uint8_t)(n % d));
            z->t += mem ? 86 : 80;
        }
        break; }
    default: {                                          /* IDIV */
        if (w16) {
            int16_t d = (int16_t)ev16(z);
            int32_t n = (int32_t)(((uint32_t)z->w[DX] << 16) | z->w[AX]);
            if (!d) { divide_error(z); return; }
            int64_t q = (int64_t)n / d;
            if (q > 32767 || q < -32767) { divide_error(z); return; }
            z->w[AX] = (uint16_t)q; z->w[DX] = (uint16_t)(n % d);
            z->t += mem ? 172 : 166;
        } else {
            int8_t d = (int8_t)ev8(z);
            int16_t n = (int16_t)z->w[AX];
            if (!d) { divide_error(z); return; }
            int q = n / d;
            if (q > 127 || q < -127) { divide_error(z); return; }
            set_r8(z, 0, (uint8_t)q); set_r8(z, 4, (uint8_t)(n % d));
            z->t += mem ? 112 : 106;
        }
        break; }
    }
}

/* ---------------------------------------------------------------- */
/* string instructions: one iteration                                */
/* ---------------------------------------------------------------- */
static void set_flags_from(i8088_t *z, uint16_t v) { z->fl = (uint16_t)(v & (CF | PF | AF | ZF | SF | TF | IFL | DF | OF)); }


/* one iteration of a string instruction; returns 1 when a REP loop has to continue */
static int string_op(i8088_t *z, uint8_t op, int rep)
{
    int w16 = op & 1;
    int step = (z->fl & DF) ? -1 : 1;
    int sz = w16 ? 2 : 1;
    int srcseg = (z->ovr >= 0) ? z->ovr : DS;
    int cmpkind = (op & 0xfe) == 0xa6 || (op & 0xfe) == 0xae;     /* CMPS SCAS */
    uint16_t a, b;

    if (rep && z->w[CX] == 0) return 0;
    switch (op & 0xfe) {
    case 0xa4:                                          /* MOVS */
        a = w16 ? rd16(z, z->seg[srcseg], z->w[SI]) : rd8(z, z->seg[srcseg], z->w[SI]);
        if (w16) wr16(z, z->seg[ES], z->w[DI], a); else wr8(z, z->seg[ES], z->w[DI], (uint8_t)a);
        z->w[SI] = (uint16_t)(z->w[SI] + step * sz); z->w[DI] = (uint16_t)(z->w[DI] + step * sz);
        z->t += rep ? 17 : 18;
        break;
    case 0xa6:                                          /* CMPS */
        a = w16 ? rd16(z, z->seg[srcseg], z->w[SI]) : rd8(z, z->seg[srcseg], z->w[SI]);
        b = w16 ? rd16(z, z->seg[ES], z->w[DI]) : rd8(z, z->seg[ES], z->w[DI]);
        alu(z, 7, a, b, w16);
        z->w[SI] = (uint16_t)(z->w[SI] + step * sz); z->w[DI] = (uint16_t)(z->w[DI] + step * sz);
        z->t += 22;
        break;
    case 0xaa:                                          /* STOS */
        if (w16) wr16(z, z->seg[ES], z->w[DI], z->w[AX]); else wr8(z, z->seg[ES], z->w[DI], AL(z));
        z->w[DI] = (uint16_t)(z->w[DI] + step * sz);
        z->t += rep ? 10 : 11;
        break;
    case 0xac:                                          /* LODS */
        if (w16) z->w[AX] = rd16(z, z->seg[srcseg], z->w[SI]); else set_r8(z, 0, rd8(z, z->seg[srcseg], z->w[SI]));
        z->w[SI] = (uint16_t)(z->w[SI] + step * sz);
        z->t += rep ? 13 : 12;
        break;
    default:                                            /* SCAS */
        b = w16 ? rd16(z, z->seg[ES], z->w[DI]) : rd8(z, z->seg[ES], z->w[DI]);
        alu(z, 7, w16 ? z->w[AX] : AL(z), b, w16);
        z->w[DI] = (uint16_t)(z->w[DI] + step * sz);
        z->t += 15;
        break;
    }
    if (!rep) return 0;
    z->w[CX]--;
    if (z->w[CX] == 0) return 0;
    if (cmpkind) {
        if (rep == 1 && !(z->fl & ZF)) return 0;        /* REPE : stop when not equal */
        if (rep == 2 &&  (z->fl & ZF)) return 0;        /* REPNE: stop when equal     */
    }
    return 1;
}

/* execute the instruction `op`; prefixes were consumed by the caller.  *repeat = 1 asks the
 * caller to execute the same instruction again (REP).  */
static void exec(i8088_t *z, uint8_t op, int rep, int *repeat)
{
    int mem;
    uint16_t a, b, r;
    int w16 = op & 1;

    if (op >= 0x60 && op <= 0x6f) op = (uint8_t)(op + 0x10);          /* 8086/8088: alias of Jcc */
    switch (op) {
    /* ---- ALU Eb,Gb ... AX,Iv ---- */
    case 0x00: case 0x01: case 0x02: case 0x03: case 0x08: case 0x09: case 0x0a: case 0x0b:
    case 0x10: case 0x11: case 0x12: case 0x13: case 0x18: case 0x19: case 0x1a: case 0x1b:
    case 0x20: case 0x21: case 0x22: case 0x23: case 0x28: case 0x29: case 0x2a: case 0x2b:
    case 0x30: case 0x31: case 0x32: case 0x33: case 0x38: case 0x39: case 0x3a: case 0x3b: {
        int aop = (op >> 3) & 7, to_reg = op & 2;
        modrm(z);
        mem = z->mod != 3;
        if (w16) { a = to_reg ? z->w[z->reg] : ev16(z); b = to_reg ? ev16(z) : z->w[z->reg]; }
        else     { a = to_reg ? get_r8(z, z->reg) : ev8(z); b = to_reg ? ev8(z) : get_r8(z, z->reg); }
        r = alu(z, aop, a, b, w16);
        if (aop != 7) {
            if (to_reg) { if (w16) z->w[z->reg] = r; else set_r8(z, z->reg, (uint8_t)r); }
            else if (w16) sev16(z, r); else sev8(z, (uint8_t)r);
        }
        z->t += mem ? ((to_reg || aop == 7) ? 9 : 16) : 3;
        break; }
    case 0x04: case 0x0c: case 0x14: case 0x1c: case 0x24: case 0x2c: case 0x34: case 0x3c: {
        int aop = (op >> 3) & 7;
        r = alu(z, aop, AL(z), fetch8(z), 0);
        if (aop != 7) set_r8(z, 0, (uint8_t)r);
        z->t += 4; break; }
    case 0x05: case 0x0d: case 0x15: case 0x1d: case 0x25: case 0x2d: case 0x35: case 0x3d: {
        int aop = (op >> 3) & 7;
        r = alu(z, aop, z->w[AX], fetch16(z), 1);
        if (aop != 7) z->w[AX] = r;
        z->t += 4; break; }
    case 0x06: case 0x0e: case 0x16: case 0x1e:
        push16(z, z->seg[(op >> 3) & 3]); z->t += 10; break;
    case 0x07: case 0x0f: case 0x17: case 0x1f:
        z->seg[(op >> 3) & 3] = pop16(z); z->t += 8;
        if (((op >> 3) & 3) == SS) z->inhibit = 1;
        break;
    case 0x27: case 0x2f: {                             /* DAA DAS */
        uint8_t al = AL(z), old = al;
        int oldcf = z->fl & CF, sub = (op == 0x2f);
        int cf = 0, af = 0;
        if ((al & 0x0f) > 9 || (z->fl & AF)) {
            al = (uint8_t)(sub ? al - 6 : al + 6);
            cf = oldcf || (sub ? old < 6 : (old + 6) > 0xff);
            af = 1;
        }
        if (old > 0x99 || oldcf) { al = (uint8_t)(sub ? al - 0x60 : al + 0x60); cf = 1; }
        z->fl &= ~(CF | AF);
        if (cf) z->fl |= CF;
        if (af) z->fl |= AF;
        set_r8(z, 0, al); set_szp(z, al, 0);
        z->t += 4; break; }
    case 0x37: case 0x3f: {                             /* AAA AAS */
        int sub = (op == 0x3f);
        uint8_t al = AL(z);
        if ((al & 0x0f) > 9 || (z->fl & AF)) {
            if (sub) { al = (uint8_t)(al - 6); z->w[AX] = (uint16_t)(z->w[AX] - 0x100); }
            else     { al = (uint8_t)(al + 6); z->w[AX] = (uint16_t)(z->w[AX] + 0x100); }
            z->fl |= CF | AF;
        } else z->fl &= ~(CF | AF);
        set_r8(z, 0, (uint8_t)(al & 0x0f));
        z->t += 4; break; }
    case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47:
        z->w[op & 7] = incdec(z, z->w[op & 7], 0, 1); z->t += 2; break;
    case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f:
        z->w[op & 7] = incdec(z, z->w[op & 7], 1, 1); z->t += 2; break;
    case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57:
        a = (op == 0x54) ? (uint16_t)(z->w[SP] - 2) : z->w[op & 7];      /* PUSH SP pushes the new value */
        push16(z, a); z->t += 11; break;
    case 0x58: case 0x59: case 0x5a: case 0x5b: case 0x5c: case 0x5d: case 0x5e: case 0x5f:
        a = pop16(z); z->w[op & 7] = a; z->t += 8; break;
    case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77:
    case 0x78: case 0x79: case 0x7a: case 0x7b: case 0x7c: case 0x7d: case 0x7e: case 0x7f: {
        int8_t d = (int8_t)fetch8(z);
        if (cc_test(z, op & 15)) { z->ip = (uint16_t)(z->ip + d); z->t += 16; } else z->t += 4;
        break; }
    case 0x80: case 0x81: case 0x82: case 0x83: {
        int aop;
        w16 = op & 1;
        modrm(z);
        aop = z->reg;
        mem = z->mod != 3;
        a = w16 ? ev16(z) : ev8(z);
        b = (op == 0x81) ? fetch16(z) : (op == 0x83 ? (uint16_t)(int16_t)(int8_t)fetch8(z) : fetch8(z));
        r = alu(z, aop, a, b, w16);
        if (aop != 7) { if (w16) sev16(z, r); else sev8(z, (uint8_t)r); }
        z->t += mem ? (aop == 7 ? 10 : 17) : 4;
        break; }
    case 0x84: case 0x85:
        modrm(z); mem = z->mod != 3;
        if (w16) alu(z, 4, ev16(z), z->w[z->reg], 1); else alu(z, 4, ev8(z), get_r8(z, z->reg), 0);
        z->t += mem ? 9 : 3; break;
    case 0x86: case 0x87:
        modrm(z); mem = z->mod != 3;
        if (w16) { a = ev16(z); sev16(z, z->w[z->reg]); z->w[z->reg] = a; }
        else     { uint8_t x = ev8(z); sev8(z, get_r8(z, z->reg)); set_r8(z, z->reg, x); }
        z->t += mem ? 17 : 4; break;
    case 0x88: case 0x89:
        modrm(z); mem = z->mod != 3;
        if (w16) sev16(z, z->w[z->reg]); else sev8(z, get_r8(z, z->reg));
        z->t += mem ? 9 : 2; break;
    case 0x8a: case 0x8b:
        modrm(z); mem = z->mod != 3;
        if (w16) z->w[z->reg] = ev16(z); else set_r8(z, z->reg, ev8(z));
        z->t += mem ? 8 : 2; break;
    case 0x8c:
        modrm(z); mem = z->mod != 3;
        if (mem) wr16(z, z->seg[z->ea_seg], z->ea_off, z->seg[z->reg & 3]); else z->w[z->rm] = z->seg[z->reg & 3];
        z->t += mem ? 9 : 2; break;
    case 0x8d:
        modrm(z);
        if (z->mod != 3) z->w[z->reg] = z->ea_off;
        z->t += 2 - (z->mod != 3 ? 0 : 0); break;
    case 0x8e:
        modrm(z); mem = z->mod != 3;
        a = ev16(z);
        z->seg[z->reg & 3] = a;
        if ((z->reg & 3) == SS) z->inhibit = 1;
        z->t += mem ? 8 : 2; break;
    case 0x8f:
        modrm(z); a = pop16(z); sev16(z, a);
        z->t += z->mod != 3 ? 17 : 8; break;
    case 0x90: z->t += 3; break;
    case 0x91: case 0x92: case 0x93: case 0x94: case 0x95: case 0x96: case 0x97:
        a = z->w[AX]; z->w[AX] = z->w[op & 7]; z->w[op & 7] = a; z->t += 3; break;
    case 0x98: z->w[AX] = (uint16_t)(int16_t)(int8_t)AL(z); z->t += 2; break;
    case 0x99: z->w[DX] = (z->w[AX] & 0x8000) ? 0xffff : 0; z->t += 5; break;
    case 0x9a: {                                        /* CALL far */
        uint16_t off = fetch16(z), seg = fetch16(z);
        push16(z, z->seg[CS]); push16(z, z->ip);
        z->seg[CS] = seg; z->ip = off; z->t += 28; break; }
    case 0x9b: z->t += 4; break;                        /* WAIT: TEST pin is assumed low */
    case 0x9c: push16(z, (uint16_t)(z->fl | 0xf002)); z->t += 10; break;
    case 0x9d: set_flags_from(z, pop16(z)); z->t += 8; break;
    case 0x9e: z->fl = (uint16_t)((z->fl & ~(SF | ZF | AF | PF | CF)) | (AH(z) & (SF | ZF | AF | PF | CF))); z->t += 4; break;
    case 0x9f: set_r8(z, 4, (uint8_t)((z->fl & (SF | ZF | AF | PF | CF)) | 0x02)); z->t += 4; break;
    case 0xa0: case 0xa1: case 0xa2: case 0xa3: {
        uint16_t off = fetch16(z);
        int sg = (z->ovr >= 0) ? z->ovr : DS;
        switch (op & 3) {
        case 0: set_r8(z, 0, rd8(z, z->seg[sg], off)); break;
        case 1: z->w[AX] = rd16(z, z->seg[sg], off); break;
        case 2: wr8(z, z->seg[sg], off, AL(z)); break;
        default: wr16(z, z->seg[sg], off, z->w[AX]); break;
        }
        z->t += 10; break; }
    case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf:
        if (rep && !z->rep_resume) z->t += 9;
        *repeat = string_op(z, op, rep);
        break;
    case 0xa8: alu(z, 4, AL(z), fetch8(z), 0); z->t += 4; break;
    case 0xa9: alu(z, 4, z->w[AX], fetch16(z), 1); z->t += 4; break;
    case 0xb0: case 0xb1: case 0xb2: case 0xb3: case 0xb4: case 0xb5: case 0xb6: case 0xb7:
        set_r8(z, op & 7, fetch8(z)); z->t += 4; break;
    case 0xb8: case 0xb9: case 0xba: case 0xbb: case 0xbc: case 0xbd: case 0xbe: case 0xbf:
        z->w[op & 7] = fetch16(z); z->t += 4; break;
    case 0xc0: case 0xc2: a = fetch16(z); z->ip = pop16(z); z->w[SP] = (uint16_t)(z->w[SP] + a); z->t += 20; break;
    case 0xc1: case 0xc3: z->ip = pop16(z); z->t += 16; break;
    case 0xc4: case 0xc5:                               /* LES LDS */
        modrm(z);
        if (z->mod != 3) {
            z->w[z->reg] = rd16(z, z->seg[z->ea_seg], z->ea_off);
            z->seg[op == 0xc4 ? ES : DS] = rd16(z, z->seg[z->ea_seg], (uint16_t)(z->ea_off + 2));
        }
        z->t += 16; break;
    case 0xc6: case 0xc7:
        modrm(z); mem = z->mod != 3;
        if (w16) sev16(z, fetch16(z)); else sev8(z, fetch8(z));
        z->t += mem ? 10 : 4; break;
    case 0xc8: case 0xca: a = fetch16(z); z->ip = pop16(z); z->seg[CS] = pop16(z); z->w[SP] = (uint16_t)(z->w[SP] + a); z->t += 25; break;
    case 0xc9: case 0xcb: z->ip = pop16(z); z->seg[CS] = pop16(z); z->t += 26; break;
    case 0xcc: do_int(z, 3); z->t += 52; break;
    case 0xcd: do_int(z, fetch8(z)); z->t += 51; break;
    case 0xce: if (z->fl & OF) { do_int(z, 4); z->t += 53; } else z->t += 4; break;
    case 0xcf: z->ip = pop16(z); z->seg[CS] = pop16(z); set_flags_from(z, pop16(z)); z->t += 32; break;
    case 0xd0: case 0xd1: case 0xd2: case 0xd3: {
        unsigned cnt = (op & 2) ? (unsigned)get_r8(z, 1) : 1;
        modrm(z); mem = z->mod != 3;
        if (w16) sev16(z, shift(z, z->reg, ev16(z), cnt, 1)); else sev8(z, (uint8_t)shift(z, z->reg, ev8(z), cnt, 0));
        z->t += (op & 2) ? ((mem ? 20 : 8) + 4 * (int)cnt) : (mem ? 15 : 2);
        break; }
    case 0xd4: {                                        /* AAM */
        uint8_t base = fetch8(z), al = AL(z);
        if (!base) { divide_error(z); break; }
        set_r8(z, 4, (uint8_t)(al / base)); set_r8(z, 0, (uint8_t)(al % base));
        set_szp(z, AL(z), 0); z->t += 83; break; }
    case 0xd5: {                                        /* AAD */
        uint8_t base = fetch8(z);
        uint8_t al = (uint8_t)(AL(z) + AH(z) * base);
        set_r8(z, 0, al); set_r8(z, 4, 0);
        set_szp(z, al, 0); z->t += 60; break; }
    case 0xd6: set_r8(z, 0, (z->fl & CF) ? 0xff : 0x00); z->t += 4; break;      /* SALC */
    case 0xd7: {                                        /* XLAT */
        int sg = (z->ovr >= 0) ? z->ovr : DS;
        set_r8(z, 0, rd8(z, z->seg[sg], (uint16_t)(z->w[BX] + AL(z)))); z->t += 11; break; }
    case 0xd8: case 0xd9: case 0xda: case 0xdb: case 0xdc: case 0xdd: case 0xde: case 0xdf:
        modrm(z); z->t += 8; break;                     /* ESC: no coprocessor */
    case 0xe0: case 0xe1: case 0xe2: case 0xe3: {
        int8_t d = (int8_t)fetch8(z);
        int take;
        if (op == 0xe3) take = (z->w[CX] == 0);
        else {
            z->w[CX]--;
            take = z->w[CX] != 0;
            if (op == 0xe1) take = take && (z->fl & ZF);
            if (op == 0xe0) take = take && !(z->fl & ZF);
        }
        if (take) { z->ip = (uint16_t)(z->ip + d); z->t += (op == 0xe2) ? 17 : (op == 0xe3 ? 18 : (op == 0xe1 ? 18 : 19)); }
        else z->t += (op == 0xe2) ? 5 : (op == 0xe3 ? 6 : (op == 0xe1 ? 6 : 5));
        break; }
    case 0xe4: case 0xe5: {
        uint16_t port = fetch8(z);
        if (w16) { z->w[AX] = (uint16_t)(z->bus.io_read(z->bus.ctx, port) | (z->bus.io_read(z->bus.ctx, (uint16_t)(port + 1)) << 8)); z->t += 4; }
        else set_r8(z, 0, z->bus.io_read(z->bus.ctx, port));
        z->t += 10; break; }
    case 0xe6: case 0xe7: {
        uint16_t port = fetch8(z);
        z->bus.io_write(z->bus.ctx, port, AL(z));
        if (w16) { z->bus.io_write(z->bus.ctx, (uint16_t)(port + 1), AH(z)); z->t += 4; }
        z->t += 10; break; }
    case 0xe8: { int16_t d = (int16_t)fetch16(z); push16(z, z->ip); z->ip = (uint16_t)(z->ip + d); z->t += 19; break; }
    case 0xe9: { int16_t d = (int16_t)fetch16(z); z->ip = (uint16_t)(z->ip + d); z->t += 15; break; }
    case 0xea: { uint16_t off = fetch16(z), seg = fetch16(z); z->ip = off; z->seg[CS] = seg; z->t += 15; break; }
    case 0xeb: { int8_t d = (int8_t)fetch8(z); z->ip = (uint16_t)(z->ip + d); z->t += 15; break; }
    case 0xec: case 0xed:
        if (w16) { z->w[AX] = (uint16_t)(z->bus.io_read(z->bus.ctx, z->w[DX]) | (z->bus.io_read(z->bus.ctx, (uint16_t)(z->w[DX] + 1)) << 8)); z->t += 4; }
        else set_r8(z, 0, z->bus.io_read(z->bus.ctx, z->w[DX]));
        z->t += 8; break;
    case 0xee: case 0xef:
        z->bus.io_write(z->bus.ctx, z->w[DX], AL(z));
        if (w16) { z->bus.io_write(z->bus.ctx, (uint16_t)(z->w[DX] + 1), AH(z)); z->t += 4; }
        z->t += 8; break;
    case 0xf4: z->halted = 1; z->t += 2; break;
    case 0xf5: z->fl ^= CF; z->t += 2; break;
    case 0xf6: case 0xf7: modrm(z); group3(z, w16); break;
    case 0xf8: z->fl &= ~CF; z->t += 2; break;
    case 0xf9: z->fl |= CF; z->t += 2; break;
    case 0xfa: z->fl &= ~IFL; z->t += 2; break;
    case 0xfb: z->fl |= IFL; z->inhibit = 1; z->t += 2; break;
    case 0xfc: z->fl &= ~DF; z->t += 2; break;
    case 0xfd: z->fl |= DF; z->t += 2; break;
    case 0xfe: case 0xff: {
        modrm(z); mem = z->mod != 3;
        switch (z->reg) {
        case 0: case 1:
            if (w16) sev16(z, incdec(z, ev16(z), z->reg, 1)); else sev8(z, (uint8_t)incdec(z, ev8(z), z->reg, 0));
            z->t += mem ? 15 : (w16 ? 3 : 3);
            break;
        case 2:                                         /* CALL near */
            a = ev16(z); push16(z, z->ip); z->ip = a; z->t += mem ? 21 : 16; break;
        case 3:                                         /* CALL far */
            if (mem) {
                uint16_t off = rd16(z, z->seg[z->ea_seg], z->ea_off), seg = rd16(z, z->seg[z->ea_seg], (uint16_t)(z->ea_off + 2));
                push16(z, z->seg[CS]); push16(z, z->ip);
                z->seg[CS] = seg; z->ip = off;
            }
            z->t += 37; break;
        case 4: z->ip = ev16(z); z->t += mem ? 18 : 11; break;
        case 5:
            if (mem) {
                uint16_t off = rd16(z, z->seg[z->ea_seg], z->ea_off), seg = rd16(z, z->seg[z->ea_seg], (uint16_t)(z->ea_off + 2));
                z->seg[CS] = seg; z->ip = off;
            }
            z->t += 24; break;
        default:
            a = ev16(z); push16(z, a); z->t += mem ? 16 : 11; break;
        }
        break; }
    default:
        z->t += 2;                                      /* unassigned: behaves as NOP */
        break;
    }
}

static int i8088_step_eu(void *vz)
{
    i8088_t *z = vz;
    int inh = z->inhibit;
    int tf = (z->fl & TF) != 0;
    z->t = 0;
    z->inhibit = 0;

    if (z->nmi_edge) {
        z->nmi_edge = 0; z->halted = 0;
        do_int(z, 2); z->t += 51;
        return z->t;
    }
    if (z->int_line && (z->fl & IFL) && !inh) {
        uint8_t vec = z->bus.int_ack(z->bus.ctx);
        z->halted = 0;
        do_int(z, vec); z->t += 61;
        return z->t;
    }
    if (z->halted) return 2;

    {
        int rep = 0, repeat = 0, done = 0;
        uint8_t op;
        z->ovr = -1;
        z->start_ip = z->ip;
        z->insns++;
        for (;;) {
            op = fetch8(z);
            switch (op) {
            case 0x26: z->ovr = ES; continue;
            case 0x2e: z->ovr = CS; continue;
            case 0x36: z->ovr = SS; continue;
            case 0x3e: z->ovr = DS; continue;
            case 0xf0: case 0xf1: z->t += 2; continue;      /* LOCK */
            case 0xf2: rep = 2; continue;
            case 0xf3: rep = 1; continue;
            default: break;
            }
            break;
        }
        exec(z, op, rep, &repeat);
        z->rep_resume = 0;
        if (repeat) {
            z->ip = z->start_ip;                            /* execute the next iteration with a new step */
            z->rep_resume = 1;
            done = 1;
        }
        (void)done;
        if (tf && !z->halted && !repeat) { do_int(z, 1); z->t += 51; }
    }
    return z->t;
}

/* The bus interface unit: the clock counts of the execution unit (Intel's tables) assume that the instruction bytes are in the
 * queue.  The BIU fills the 4 byte queue with one bus cycle (4 clocks) per byte in the clocks in which the EU does not use the
 * bus, so short instructions are limited by the fetch (NOP: 4 clocks, not 3), and a jump empties the queue (Intel's counts for
 * the jumps include the fetch of the first byte at the target). */
static int i8088_step(void *vz)
{
    i8088_t *z = vz;
    int cont = z->rep_resume;                       /* the next round of a REP: the instruction bytes are not fetched again */
    uint32_t before = lin(z->seg[CS], z->ip);
    int e, nf, nd, stall = 0, idle, flush;
    unsigned fetched = 0;
    z->nfetch = z->ndr = z->ndw = 0;
    e = i8088_step_eu(vz);
    if (!z->biu) return e;
    nf = cont ? 0 : z->nfetch;
    nd = z->ndr + z->ndw;
    flush = !z->rep_resume && !z->halted && lin(z->seg[CS], z->ip) != ((before + (uint32_t)z->nfetch) & 0xfffff);
    if (nf > z->q) {                                /* the EU waits for the rest: the BIU may have started the next byte already */
        int need = nf - z->q;
        fetched = (unsigned)need;
        stall = 4 * need - z->credit;
        if (stall < 0) stall = 0;
        z->q = 0; z->credit = 0;
    } else z->q -= nf;
    idle = e - 4 * nd;
    if (idle < 0) idle = 0;
    if (flush) { z->q = 1; z->credit = 0; }
    else {
        z->credit += idle;
        while (z->credit >= 4 && z->q < 4) { z->q++; z->credit -= 4; fetched++; }
        if (z->q >= 4) z->credit = 0;
    }
    z->bus_rd = fetched + (unsigned)z->ndr;
    z->bus_wr = (unsigned)z->ndw;
    return e + stall;
}

static void i8088_set_timing(void *vz, int on) { i8088_t *z = vz; z->biu = on; z->q = 4; z->credit = 0; }
static void i8088_bus_cycles(void *vz, unsigned *rd, unsigned *wr) { i8088_t *z = vz; *rd = z->bus_rd; *wr = z->bus_wr; }

/* ---------------------------------------------------------------- */
/* plug-in interface                                                 */
/* ---------------------------------------------------------------- */
static void *i8088_create(const sub_bus_t *bus)
{
    i8088_t *z = calloc(1, sizeof *z);
    init_tab();
    if (!z) return NULL;
    z->bus = *bus;
    return z;
}
static void i8088_destroy(void *z) { free(z); }

static void i8088_reset(void *vz)
{
    i8088_t *z = vz;
    memset(z->w, 0, sizeof z->w);
    memset(z->seg, 0, sizeof z->seg);
    z->seg[CS] = 0xffff;
    z->ip = 0;
    z->fl = 0;
    z->halted = z->inhibit = z->rep_resume = z->nmi_edge = 0;
}

static void i8088_set_line(void *vz, int line, int level)
{
    i8088_t *z = vz;
    if (line == SUB_INT) z->int_line = (uint8_t)level;
    else {
        if (level && !z->nmi_line) z->nmi_edge = 1;
        z->nmi_line = (uint8_t)level;
    }
}

static int i8088_is_halted(void *vz) { return ((i8088_t *)vz)->halted; }
static int i8088_int_ok(void *vz) { i8088_t *z = vz; return (z->fl & IFL) && !z->inhibit; }
static uint32_t i8088_pc(void *vz) { i8088_t *z = vz; return lin(z->seg[CS], z->ip); }
static uint64_t i8088_insns(void *vz) { return ((i8088_t *)vz)->insns; }

static void i8088_dump(void *vz, FILE *f)
{
    i8088_t *z = vz;
    fprintf(f, "CS:IP=%04X:%04X AX=%04X BX=%04X CX=%04X DX=%04X SP=%04X BP=%04X SI=%04X DI=%04X DS=%04X ES=%04X SS=%04X FL=%04X%s",
            z->seg[CS], z->ip, z->w[AX], z->w[BX], z->w[CX], z->w[DX], z->w[SP], z->w[BP], z->w[SI], z->w[DI],
            z->seg[DS], z->seg[ES], z->seg[SS], z->fl | 0xf002, z->halted ? " HLT" : "");
}

/* test access (tests/i8088_test.c) */
uint32_t i8088_get_reg(void *vz, const char *n)
{
    i8088_t *z = vz;
    static const char *w16n[] = { "ax", "cx", "dx", "bx", "sp", "bp", "si", "di" };
    static const char *s16n[] = { "es", "cs", "ss", "ds" };
    for (int i = 0; i < 8; i++) if (!strcmp(n, w16n[i])) return z->w[i];
    for (int i = 0; i < 4; i++) if (!strcmp(n, s16n[i])) return z->seg[i];
    if (!strcmp(n, "ip")) return z->ip;
    if (!strcmp(n, "flags")) return z->fl | 0xf002;
    return 0xdeadbeef;
}
void i8088_set_reg(void *vz, const char *n, uint32_t v)
{
    i8088_t *z = vz;
    static const char *w16n[] = { "ax", "cx", "dx", "bx", "sp", "bp", "si", "di" };
    static const char *s16n[] = { "es", "cs", "ss", "ds" };
    for (int i = 0; i < 8; i++) if (!strcmp(n, w16n[i])) { z->w[i] = (uint16_t)v; return; }
    for (int i = 0; i < 4; i++) if (!strcmp(n, s16n[i])) { z->seg[i] = (uint16_t)v; return; }
    if (!strcmp(n, "ip")) z->ip = (uint16_t)v;
    else if (!strcmp(n, "flags")) z->fl = (uint16_t)(v & 0x0fd5);
}

const sub_cpu_ops_t sub_cpu_i8088 = {
    .name = "8088",
    .desc = "Intel 8088-2, 8 MHz, 1MB memory space",
    .id = 2,
    .addr_bits = 20,
    .max_hz = 8000000,
    .create = i8088_create,
    .destroy = i8088_destroy,
    .reset = i8088_reset,
    .step = i8088_step,
    .set_line = i8088_set_line,
    .is_halted = i8088_is_halted,
    .int_pending_ok = i8088_int_ok,
    .pc = i8088_pc,
    .insn_count = i8088_insns,
    .dump = i8088_dump,
    .set_timing = i8088_set_timing,
    .bus_cycles = i8088_bus_cycles,
};
