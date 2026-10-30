/* SPDX-License-Identifier: MIT */
/*
 * z80.c - Zilog Z80 CPU core (sub CPU backend of the Matenro machine)
 *
 * Credits / references
 * --------------------
 * Written from the public descriptions of the Z80 instruction set:
 *   - Zilog "Z80 CPU User Manual" (UM0080): instruction set, flags, T states
 *   - Sean Young, "The Undocumented Z80 Documented" (X/Y flags, IXH/IXL,
 *     DDCB register copies, SLL, IN F,(C), OUT (C),0, block I/O flags, MEMPTR)
 *   - Decoding by x/y/z/p/q bit fields as described in Cristian Dinu's
 *     "Decoding Z80 opcodes" (z80.info/decoding.htm)
 * No code of any other Z80 emulator was copied; this is an independent
 * implementation.  The overall interface (step() returns the clocks used,
 * level sensitive INT, edge triggered NMI, one instruction per call) follows
 * the style of the sim09 MC6809 core (m6809.c).
 *
 * Not modelled: bus request / wait states, exact timing of the repeated
 * block instructions' X/Y flags and of the INIR/OTIR family flag side
 * effects.  T states follow the Zilog manual.
 */
#include <stdlib.h>
#include <string.h>
#include "subcpu.h"

#define SF 0x80
#define ZF 0x40
#define YF 0x20
#define HF 0x10
#define XF 0x08
#define PF 0x04
#define NF 0x02
#define CF 0x01

enum { R_B, R_C, R_D, R_E, R_H, R_L, R_M, R_A };

typedef struct z80 {
    uint8_t  r[8];           /* B C D E H L (unused) A */
    uint8_t  r2[8];          /* shadow set             */
    uint8_t  f, f2;
    uint16_t ix, iy, sp, pc, wz;
    uint8_t  i, rr;          /* I, R                   */
    uint8_t  iff1, iff2, im;
    uint8_t  halted;
    uint8_t  ei_delay;
    uint8_t  int_line, nmi_line, nmi_edge;
    uint8_t  q_flags_valid;
    sub_bus_t bus;
    uint64_t insns;
    int      t;              /* clocks of the current step */
    /* decode state of the current instruction */
    uint16_t *idx;           /* NULL, &ix or &iy */
    int      disp;
} z80_t;

static uint8_t parity_tab[256];
static int parity_init;

static void init_tables(void)
{
    if (parity_init) return;
    for (int i = 0; i < 256; i++) {
        int p = 1;
        for (int b = 0; b < 8; b++) if (i & (1 << b)) p ^= 1;
        parity_tab[i] = p ? PF : 0;
    }
    parity_init = 1;
}

#define RD(a)    (z->bus.mem_read(z->bus.ctx, (uint16_t)(a)))
#define WR(a, v) (z->bus.mem_write(z->bus.ctx, (uint16_t)(a), (uint8_t)(v)))

static inline uint16_t rd16(z80_t *z, uint16_t a)
{
    uint16_t lo = RD(a);
    return (uint16_t)(lo | (RD((uint16_t)(a + 1)) << 8));
}
static inline void wr16(z80_t *z, uint16_t a, uint16_t v)
{
    WR(a, v & 0xff);
    WR((uint16_t)(a + 1), v >> 8);
}
static inline uint8_t fetch(z80_t *z) { return RD(z->pc++); }
static inline uint16_t fetch16(z80_t *z)
{
    uint16_t lo = fetch(z);
    return (uint16_t)(lo | (fetch(z) << 8));
}
static inline void push(z80_t *z, uint16_t v)
{
    z->sp--; WR(z->sp, v >> 8);
    z->sp--; WR(z->sp, v & 0xff);
}
static inline uint16_t pop(z80_t *z)
{
    uint16_t v = rd16(z, z->sp);
    z->sp += 2;
    return v;
}

#define BC(z) (uint16_t)(((z)->r[R_B] << 8) | (z)->r[R_C])
#define DE(z) (uint16_t)(((z)->r[R_D] << 8) | (z)->r[R_E])
#define HL(z) (uint16_t)(((z)->r[R_H] << 8) | (z)->r[R_L])
static inline void set_bc(z80_t *z, uint16_t v) { z->r[R_B] = v >> 8; z->r[R_C] = (uint8_t)v; }
static inline void set_de(z80_t *z, uint16_t v) { z->r[R_D] = v >> 8; z->r[R_E] = (uint8_t)v; }
static inline void set_hl(z80_t *z, uint16_t v) { z->r[R_H] = v >> 8; z->r[R_L] = (uint8_t)v; }

/* HL, or IX/IY when a DD/FD prefix is active */
static inline uint16_t get_hlx(z80_t *z) { return z->idx ? *z->idx : HL(z); }
static inline void set_hlx(z80_t *z, uint16_t v) { if (z->idx) *z->idx = v; else set_hl(z, v); }

/* register pair tables: rp (BC DE HL SP) and rp2 (BC DE HL AF) */
static uint16_t get_rp(z80_t *z, int p)
{
    switch (p) { case 0: return BC(z); case 1: return DE(z); case 2: return get_hlx(z); default: return z->sp; }
}
static void set_rp(z80_t *z, int p, uint16_t v)
{
    switch (p) { case 0: set_bc(z, v); break; case 1: set_de(z, v); break; case 2: set_hlx(z, v); break; default: z->sp = v; }
}
static uint16_t get_rp2(z80_t *z, int p)
{
    switch (p) { case 0: return BC(z); case 1: return DE(z); case 2: return get_hlx(z); default: return (uint16_t)((z->r[R_A] << 8) | z->f); }
}
static void set_rp2(z80_t *z, int p, uint16_t v)
{
    switch (p) { case 0: set_bc(z, v); break; case 1: set_de(z, v); break; case 2: set_hlx(z, v); break;
                 default: z->r[R_A] = v >> 8; z->f = (uint8_t)v; }
}

/* effective address of the (HL) / (IX+d) operand; with an index prefix the displacement is fetched here */
static uint16_t ea_mem(z80_t *z)
{
    if (z->idx) {
        int8_t d = (int8_t)fetch(z);
        z->wz = (uint16_t)(*z->idx + d);
        z->t += 8;               /* d fetch (3) + 5 internal T states of (IX+d) */
        return z->wz;
    }
    return HL(z);
}

/* 8 bit register read/write with IXH/IXL substitution (only used when no memory operand is involved) */
static uint8_t get_r(z80_t *z, int n)
{
    if (z->idx) {
        if (n == R_H) return (uint8_t)(*z->idx >> 8);
        if (n == R_L) return (uint8_t)*z->idx;
    }
    return z->r[n];
}
static void set_r(z80_t *z, int n, uint8_t v)
{
    if (z->idx) {
        if (n == R_H) { *z->idx = (uint16_t)((*z->idx & 0x00ff) | (v << 8)); return; }
        if (n == R_L) { *z->idx = (uint16_t)((*z->idx & 0xff00) | v); return; }
    }
    z->r[n] = v;
}

/* ---------------------------------------------------------------- */
/* ALU                                                               */
/* ---------------------------------------------------------------- */
static void alu(z80_t *z, int op, uint8_t b)
{
    uint8_t a = z->r[R_A];
    int r;
    switch (op) {
    case 0: case 1: {                            /* ADD ADC */
        int c = (op == 1) ? (z->f & CF) : 0;
        r = a + b + c;
        z->f = (uint8_t)((r & (SF | YF | XF)) | ((r & 0xff) ? 0 : ZF) | ((a ^ b ^ r) & HF) |
               (((a ^ r) & (b ^ r) & 0x80) ? PF : 0) | ((r > 0xff) ? CF : 0));
        z->r[R_A] = (uint8_t)r;
        break; }
    case 2: case 3: case 7: {                    /* SUB SBC CP */
        int c = (op == 3) ? (z->f & CF) : 0;
        r = a - b - c;
        z->f = (uint8_t)(NF | (r & SF) | ((r & 0xff) ? 0 : ZF) | ((a ^ b ^ r) & HF) |
               (((a ^ b) & (a ^ r) & 0x80) ? PF : 0) | ((r < 0) ? CF : 0));
        if (op == 7) z->f = (uint8_t)((z->f & ~(YF | XF)) | (b & (YF | XF)));
        else { z->f |= (uint8_t)(r & (YF | XF)); z->r[R_A] = (uint8_t)r; }
        break; }
    case 4: r = a & b; z->f = (uint8_t)((r & (SF | YF | XF)) | (r ? 0 : ZF) | HF | parity_tab[r]); z->r[R_A] = (uint8_t)r; break;
    case 5: r = a ^ b; z->f = (uint8_t)((r & (SF | YF | XF)) | (r ? 0 : ZF) | parity_tab[r]); z->r[R_A] = (uint8_t)r; break;
    default: r = a | b; z->f = (uint8_t)((r & (SF | YF | XF)) | (r ? 0 : ZF) | parity_tab[r]); z->r[R_A] = (uint8_t)r; break;
    }
}

static uint8_t inc8(z80_t *z, uint8_t v)
{
    uint8_t r = v + 1;
    z->f = (uint8_t)((z->f & CF) | (r & (SF | YF | XF)) | (r ? 0 : ZF) | ((v ^ r) & HF) | (v == 0x7f ? PF : 0));
    return r;
}
static uint8_t dec8(z80_t *z, uint8_t v)
{
    uint8_t r = v - 1;
    z->f = (uint8_t)((z->f & CF) | NF | (r & (SF | YF | XF)) | (r ? 0 : ZF) | ((v ^ r) & HF) | (v == 0x80 ? PF : 0));
    return r;
}

static uint16_t add16(z80_t *z, uint16_t a, uint16_t b)
{
    uint32_t r = (uint32_t)a + b;
    z->wz = (uint16_t)(a + 1);
    z->f = (uint8_t)((z->f & (SF | ZF | PF)) | ((r >> 8) & (YF | XF)) | (((a ^ b ^ r) >> 8) & HF) | ((r > 0xffff) ? CF : 0));
    return (uint16_t)r;
}
static uint16_t adc16(z80_t *z, uint16_t a, uint16_t b, int sub)
{
    int c = z->f & CF;
    uint32_t r;
    z->wz = (uint16_t)(a + 1);
    if (!sub) {
        r = (uint32_t)a + b + c;
        z->f = (uint8_t)(((r >> 8) & (SF | YF | XF)) | ((r & 0xffff) ? 0 : ZF) | (((a ^ b ^ r) >> 8) & HF) |
               ((((a ^ r) & (b ^ r)) & 0x8000) ? PF : 0) | ((r > 0xffff) ? CF : 0));
    } else {
        r = (uint32_t)a - b - c;
        z->f = (uint8_t)(NF | ((r >> 8) & (SF | YF | XF)) | ((r & 0xffff) ? 0 : ZF) | (((a ^ b ^ r) >> 8) & HF) |
               ((((a ^ b) & (a ^ r)) & 0x8000) ? PF : 0) | ((r & 0x10000) ? CF : 0));
    }
    return (uint16_t)r;
}

static void daa(z80_t *z)
{
    uint8_t a = z->r[R_A], corr = 0, f = z->f, c = f & CF;
    if ((f & HF) || (a & 0x0f) > 9) corr |= 0x06;
    if (c || a > 0x99) { corr |= 0x60; c = CF; }
    uint8_t r = (f & NF) ? (uint8_t)(a - corr) : (uint8_t)(a + corr);
    uint8_t h = (f & NF) ? (((f & HF) && (a & 0x0f) < 6) ? HF : 0) : (((a & 0x0f) > 9) ? HF : 0);
    z->f = (uint8_t)((r & (SF | YF | XF)) | (r ? 0 : ZF) | (f & NF) | h | parity_tab[r] | c);
    z->r[R_A] = r;
}

/* rotate / shift group (CB prefix y = 0..7) */
static uint8_t rot(z80_t *z, int y, uint8_t v)
{
    uint8_t c, r;
    switch (y) {
    case 0: c = v >> 7; r = (uint8_t)((v << 1) | c); break;                    /* RLC */
    case 1: c = v & 1;  r = (uint8_t)((v >> 1) | (c << 7)); break;             /* RRC */
    case 2: c = v >> 7; r = (uint8_t)((v << 1) | (z->f & CF)); break;          /* RL  */
    case 3: c = v & 1;  r = (uint8_t)((v >> 1) | ((z->f & CF) << 7)); break;   /* RR  */
    case 4: c = v >> 7; r = (uint8_t)(v << 1); break;                          /* SLA */
    case 5: c = v & 1;  r = (uint8_t)((v >> 1) | (v & 0x80)); break;           /* SRA */
    case 6: c = v >> 7; r = (uint8_t)((v << 1) | 1); break;                    /* SLL (undocumented) */
    default: c = v & 1; r = (uint8_t)(v >> 1); break;                          /* SRL */
    }
    z->f = (uint8_t)((r & (SF | YF | XF)) | (r ? 0 : ZF) | parity_tab[r] | c);
    return r;
}

static int cond(z80_t *z, int cc)
{
    switch (cc) {
    case 0: return !(z->f & ZF);
    case 1: return  (z->f & ZF);
    case 2: return !(z->f & CF);
    case 3: return  (z->f & CF);
    case 4: return !(z->f & PF);
    case 5: return  (z->f & PF);
    case 6: return !(z->f & SF);
    default: return (z->f & SF);
    }
}

/* ---------------------------------------------------------------- */
/* CB prefix                                                         */
/* ---------------------------------------------------------------- */
static void exec_cb(z80_t *z)
{
    uint8_t op;
    uint16_t ea = 0;
    int mem;
    if (z->idx) {
        /* DD CB d op : displacement comes before the opcode */
        int8_t d = (int8_t)fetch(z);
        ea = (uint16_t)(*z->idx + d);
        z->wz = ea;
        op = fetch(z);
        mem = 1;
    } else {
        op = fetch(z);
        z->rr = (uint8_t)((z->rr & 0x80) | ((z->rr + 1) & 0x7f));
        mem = ((op & 7) == R_M);
        if (mem) ea = HL(z);
    }
    int x = op >> 6, y = (op >> 3) & 7, zz = op & 7;
    uint8_t v = mem ? RD(ea) : z->r[zz];
    uint8_t r;
    switch (x) {
    case 0:
        r = rot(z, y, v);
        break;
    case 1:                                          /* BIT */
        r = v & (1 << y);
        {
            uint8_t xy = (mem) ? (uint8_t)(z->wz >> 8) : v;
            z->f = (uint8_t)((z->f & CF) | HF | (r ? 0 : (ZF | PF)) | ((y == 7 && r) ? SF : 0) | (xy & (YF | XF)));
        }
        z->t += mem ? (z->idx ? 16 : 12) : 8;
        return;
    case 2: r = v & ~(1 << y); break;                /* RES */
    default: r = v | (1 << y); break;                /* SET */
    }
    if (mem) {
        WR(ea, r);
        if (z->idx && zz != R_M) z->r[zz] = r;       /* undocumented: result also copied to a register */
        z->t += z->idx ? 19 : 15;          /* DD CB d op: 23 with the prefix */
    } else {
        z->r[zz] = r;
        z->t += 8;
    }
}

/* ---------------------------------------------------------------- */
/* ED prefix                                                         */
/* ---------------------------------------------------------------- */
static void block_op(z80_t *z, int y, int zz)
{
    int dir = (y & 1) ? -1 : 1;                      /* y=4 inc, 5 dec, 6 inc+repeat, 7 dec+repeat */
    int rep = y >= 6;
    uint16_t hl = HL(z);
    int again = 0;
    switch (zz) {
    case 0: {                                        /* LDI LDD LDIR LDDR */
        uint8_t v = RD(hl);
        WR(DE(z), v);
        set_hl(z, (uint16_t)(hl + dir));
        set_de(z, (uint16_t)(DE(z) + dir));
        set_bc(z, (uint16_t)(BC(z) - 1));
        uint8_t n = (uint8_t)(v + z->r[R_A]);
        z->f = (uint8_t)((z->f & (SF | ZF | CF)) | ((n & 2) ? YF : 0) | (n & XF) | (BC(z) ? PF : 0));
        again = rep && BC(z);
        z->t += again ? 17 : 12;           /* 21 / 16 with the ED fetch */
        break; }
    case 1: {                                        /* CPI CPD CPIR CPDR */
        uint8_t v = RD(hl);
        uint8_t a = z->r[R_A];
        uint8_t r = (uint8_t)(a - v);
        uint8_t h = ((a ^ v ^ r) & HF);
        set_hl(z, (uint16_t)(hl + dir));
        set_bc(z, (uint16_t)(BC(z) - 1));
        uint8_t n = (uint8_t)(r - (h ? 1 : 0));
        z->f = (uint8_t)((z->f & CF) | NF | (r & SF) | (r ? 0 : ZF) | h | (BC(z) ? PF : 0) | ((n & 2) ? YF : 0) | (n & XF));
        z->wz = (uint16_t)(z->wz + dir);
        again = rep && BC(z) && r;
        z->t += again ? 17 : 12;           /* 21 / 16 with the ED fetch */
        break; }
    case 2: {                                        /* INI IND INIR INDR */
        uint8_t v = z->bus.io_read(z->bus.ctx, BC(z));
        WR(hl, v);
        z->wz = (uint16_t)(BC(z) + dir);
        z->r[R_B]--;
        set_hl(z, (uint16_t)(hl + dir));
        uint8_t b = z->r[R_B];
        unsigned k = v + (uint8_t)(z->r[R_C] + dir);
        z->f = (uint8_t)((b & (SF | YF | XF)) | (b ? 0 : ZF) | ((v & 0x80) ? NF : 0) | ((k > 255) ? (HF | CF) : 0) |
               parity_tab[(k & 7) ^ b]);
        again = rep && b;
        z->t += again ? 17 : 12;           /* 21 / 16 with the ED fetch */
        break; }
    default: {                                       /* OUTI OUTD OTIR OTDR */
        uint8_t v = RD(hl);
        z->r[R_B]--;
        z->bus.io_write(z->bus.ctx, BC(z), v);
        z->wz = (uint16_t)(BC(z) + dir);
        set_hl(z, (uint16_t)(hl + dir));
        uint8_t b = z->r[R_B];
        unsigned k = v + z->r[R_L];
        z->f = (uint8_t)((b & (SF | YF | XF)) | (b ? 0 : ZF) | ((v & 0x80) ? NF : 0) | ((k > 255) ? (HF | CF) : 0) |
               parity_tab[(k & 7) ^ b]);
        again = rep && b;
        z->t += again ? 17 : 12;           /* 21 / 16 with the ED fetch */
        break; }
    }
    if (again) { z->pc = (uint16_t)(z->pc - 2); z->wz = (uint16_t)(z->pc + 1); }
}

static void exec_ed(z80_t *z)
{
    uint8_t op = fetch(z);
    z->rr = (uint8_t)((z->rr & 0x80) | ((z->rr + 1) & 0x7f));
    int x = op >> 6, y = (op >> 3) & 7, zz = op & 7, p = y >> 1, q = y & 1;
    z->t += 4;                                       /* the ED fetch */
    if (x == 2) {
        if (zz <= 3 && y >= 4) { block_op(z, y, zz); return; }
        z->t += 4; return;                           /* NOP */
    }
    if (x != 1) { z->t += 4; return; }               /* NOP (2 byte) */
    switch (zz) {
    case 0: {                                        /* IN r,(C) */
        uint8_t v = z->bus.io_read(z->bus.ctx, BC(z));
        z->wz = (uint16_t)(BC(z) + 1);
        z->f = (uint8_t)((z->f & CF) | (v & (SF | YF | XF)) | (v ? 0 : ZF) | parity_tab[v]);
        if (y != 6) z->r[y] = v;
        z->t += 8; break; }
    case 1:                                          /* OUT (C),r */
        z->bus.io_write(z->bus.ctx, BC(z), y == 6 ? 0 : z->r[y]);
        z->wz = (uint16_t)(BC(z) + 1);
        z->t += 8; break;
    case 2:                                          /* SBC/ADC HL,rp */
        { uint16_t hl = HL(z), v = get_rp(z, p);
          set_hl(z, adc16(z, hl, v, q == 0)); }
        z->t += 11; break;
    case 3: {                                        /* LD (nn),rp / LD rp,(nn) */
        uint16_t nn = fetch16(z);
        z->wz = (uint16_t)(nn + 1);
        if (q == 0) wr16(z, nn, get_rp(z, p)); else set_rp(z, p, rd16(z, nn));
        z->t += 16; break; }
    case 4: {                                        /* NEG */
        uint8_t a = z->r[R_A];
        z->r[R_A] = 0; alu(z, 2, a);
        z->t += 4; break; }
    case 5:                                          /* RETN / RETI */
        z->iff1 = z->iff2;
        z->pc = pop(z); z->wz = z->pc;
        z->t += 10; break;
    case 6:
        z->im = (uint8_t)((y & 3) == 2 ? 1 : ((y & 3) == 3 ? 2 : 0));
        z->t += 4; break;
    default:
        switch (y) {
        case 0: z->i = z->r[R_A]; z->t += 5; break;
        case 1: z->rr = z->r[R_A]; z->t += 5; break;
        case 2: z->r[R_A] = z->i;
                z->f = (uint8_t)((z->f & CF) | (z->i & (SF | YF | XF)) | (z->i ? 0 : ZF) | (z->iff2 ? PF : 0)); z->t += 5; break;
        case 3: z->r[R_A] = z->rr;
                z->f = (uint8_t)((z->f & CF) | (z->rr & (SF | YF | XF)) | (z->rr ? 0 : ZF) | (z->iff2 ? PF : 0)); z->t += 5; break;
        case 4: { uint16_t hl = HL(z); uint8_t m = RD(hl), a = z->r[R_A];       /* RRD */
                  WR(hl, (m >> 4) | (a << 4));
                  a = (uint8_t)((a & 0xf0) | (m & 0x0f)); z->r[R_A] = a;
                  z->f = (uint8_t)((z->f & CF) | (a & (SF | YF | XF)) | (a ? 0 : ZF) | parity_tab[a]);
                  z->wz = (uint16_t)(hl + 1); z->t += 14; break; }
        case 5: { uint16_t hl = HL(z); uint8_t m = RD(hl), a = z->r[R_A];       /* RLD */
                  WR(hl, (uint8_t)((m << 4) | (a & 0x0f)));
                  a = (uint8_t)((a & 0xf0) | (m >> 4)); z->r[R_A] = a;
                  z->f = (uint8_t)((z->f & CF) | (a & (SF | YF | XF)) | (a ? 0 : ZF) | parity_tab[a]);
                  z->wz = (uint16_t)(hl + 1); z->t += 14; break; }
        default: z->t += 4; break;
        }
    }
}

/* ---------------------------------------------------------------- */
/* main instruction decode                                           */
/* ---------------------------------------------------------------- */
static void exec_main(z80_t *z, uint8_t op)
{
    int x = op >> 6, y = (op >> 3) & 7, zz = op & 7, p = y >> 1, q = y & 1;
    int8_t d;
    uint16_t nn, ea;
    uint8_t v;

    switch (x) {
    case 0:
        switch (zz) {
        case 0:
            switch (y) {
            case 0: z->t += 4; break;
            case 1: { uint8_t t8 = z->r[R_A], t9 = z->f; z->r[R_A] = z->r2[R_A]; z->f = z->f2; z->r2[R_A] = t8; z->f2 = t9; z->t += 4; break; }
            case 2: d = (int8_t)fetch(z);
                    if (--z->r[R_B]) { z->pc = (uint16_t)(z->pc + d); z->wz = z->pc; z->t += 13; } else z->t += 8;
                    break;
            case 3: d = (int8_t)fetch(z); z->pc = (uint16_t)(z->pc + d); z->wz = z->pc; z->t += 12; break;
            default: d = (int8_t)fetch(z);
                    if (cond(z, y - 4)) { z->pc = (uint16_t)(z->pc + d); z->wz = z->pc; z->t += 12; } else z->t += 7;
                    break;
            }
            break;
        case 1:
            if (q == 0) { set_rp(z, p, fetch16(z)); z->t += 10; }
            else { set_hlx(z, add16(z, get_hlx(z), get_rp(z, p))); z->t += 11; }
            break;
        case 2:
            if (q == 0) {
                switch (p) {
                case 0: WR(BC(z), z->r[R_A]); z->wz = (uint16_t)(((BC(z) + 1) & 0xff) | (z->r[R_A] << 8)); z->t += 7; break;
                case 1: WR(DE(z), z->r[R_A]); z->wz = (uint16_t)(((DE(z) + 1) & 0xff) | (z->r[R_A] << 8)); z->t += 7; break;
                case 2: nn = fetch16(z); wr16(z, nn, get_hlx(z)); z->wz = (uint16_t)(nn + 1); z->t += 16; break;
                default: nn = fetch16(z); WR(nn, z->r[R_A]); z->wz = (uint16_t)(((nn + 1) & 0xff) | (z->r[R_A] << 8)); z->t += 13; break;
                }
            } else {
                switch (p) {
                case 0: z->r[R_A] = RD(BC(z)); z->wz = (uint16_t)(BC(z) + 1); z->t += 7; break;
                case 1: z->r[R_A] = RD(DE(z)); z->wz = (uint16_t)(DE(z) + 1); z->t += 7; break;
                case 2: nn = fetch16(z); set_hlx(z, rd16(z, nn)); z->wz = (uint16_t)(nn + 1); z->t += 16; break;
                default: nn = fetch16(z); z->r[R_A] = RD(nn); z->wz = (uint16_t)(nn + 1); z->t += 13; break;
                }
            }
            break;
        case 3:
            set_rp(z, p, (uint16_t)(get_rp(z, p) + (q ? -1 : 1)));
            z->t += 6;
            break;
        case 4: case 5:
            if (y == R_M) {
                ea = ea_mem(z);
                v = RD(ea);
                WR(ea, zz == 4 ? inc8(z, v) : dec8(z, v));
                z->t += 11;                        /* (IX+d): 23 = prefix 4 + ea_mem 8 + 11 */
            } else {
                v = get_r(z, y);
                set_r(z, y, zz == 4 ? inc8(z, v) : dec8(z, v));
                z->t += 4;
            }
            break;
        case 6:
            if (y == R_M) {
                ea = ea_mem(z);
                v = fetch(z);
                WR(ea, v);
                z->t += z->idx ? 7 : 10;           /* LD (IX+d),n = 19 */
            } else {
                set_r(z, y, fetch(z));
                z->t += 7;
            }
            break;
        default:
            switch (y) {
            case 0: { uint8_t a = z->r[R_A], c = a >> 7; a = (uint8_t)((a << 1) | c);
                      z->r[R_A] = a; z->f = (uint8_t)((z->f & (SF | ZF | PF)) | (a & (YF | XF)) | c); break; }
            case 1: { uint8_t a = z->r[R_A], c = a & 1; a = (uint8_t)((a >> 1) | (c << 7));
                      z->r[R_A] = a; z->f = (uint8_t)((z->f & (SF | ZF | PF)) | (a & (YF | XF)) | c); break; }
            case 2: { uint8_t a = z->r[R_A], c = a >> 7; a = (uint8_t)((a << 1) | (z->f & CF));
                      z->r[R_A] = a; z->f = (uint8_t)((z->f & (SF | ZF | PF)) | (a & (YF | XF)) | c); break; }
            case 3: { uint8_t a = z->r[R_A], c = a & 1; a = (uint8_t)((a >> 1) | ((z->f & CF) << 7));
                      z->r[R_A] = a; z->f = (uint8_t)((z->f & (SF | ZF | PF)) | (a & (YF | XF)) | c); break; }
            case 4: daa(z); break;
            case 5: z->r[R_A] ^= 0xff; z->f = (uint8_t)((z->f & (SF | ZF | PF | CF)) | HF | NF | (z->r[R_A] & (YF | XF))); break;
            case 6: z->f = (uint8_t)((z->f & (SF | ZF | PF)) | CF | (z->r[R_A] & (YF | XF))); break;
            default: z->f = (uint8_t)((z->f & (SF | ZF | PF)) | ((z->f & CF) ? HF : CF) | (z->r[R_A] & (YF | XF))); break;
            }
            z->t += 4;
            break;
        }
        break;

    case 1:
        if (op == 0x76) { z->halted = 1; z->t += 4; break; }
        if (y == R_M) {                                  /* LD (HL),r  -- r is never IXH/IXL here */
            ea = ea_mem(z);
            WR(ea, z->r[zz]);
            z->t += z->idx ? 7 : 7;
        } else if (zz == R_M) {                          /* LD r,(HL)  */
            ea = ea_mem(z);
            z->r[y] = RD(ea);
            z->t += 7;
        } else {
            set_r(z, y, get_r(z, zz));
            z->t += 4;
        }
        break;

    case 2:
        if (zz == R_M) { ea = ea_mem(z); v = RD(ea); z->t += 7; }
        else { v = get_r(z, zz); z->t += 4; }
        alu(z, y, v);
        break;

    default:
        switch (zz) {
        case 0:
            if (cond(z, y)) { z->pc = pop(z); z->wz = z->pc; z->t += 11; } else z->t += 5;
            break;
        case 1:
            if (q == 0) { set_rp2(z, p, pop(z)); z->t += 10; }
            else switch (p) {
            case 0: z->pc = pop(z); z->wz = z->pc; z->t += 10; break;
            case 1: for (int k = 0; k < 6; k++) { uint8_t t = z->r[k]; z->r[k] = z->r2[k]; z->r2[k] = t; } z->t += 4; break;
            case 2: z->pc = get_hlx(z); z->t += 4; break;
            default: z->sp = get_hlx(z); z->t += 6; break;
            }
            break;
        case 2:
            nn = fetch16(z); z->wz = nn;
            if (cond(z, y)) z->pc = nn;
            z->t += 10;
            break;
        case 3:
            switch (y) {
            case 0: nn = fetch16(z); z->pc = nn; z->wz = nn; z->t += 10; break;
            case 1: break;                               /* CB: handled by the caller */
            case 2: v = fetch(z); z->bus.io_write(z->bus.ctx, (uint16_t)((z->r[R_A] << 8) | v), z->r[R_A]);
                    z->wz = (uint16_t)(((v + 1) & 0xff) | (z->r[R_A] << 8)); z->t += 11; break;
            case 3: v = fetch(z); nn = (uint16_t)((z->r[R_A] << 8) | v);
                    z->r[R_A] = z->bus.io_read(z->bus.ctx, nn); z->wz = (uint16_t)(nn + 1); z->t += 11; break;
            case 4: { uint16_t t = rd16(z, z->sp); wr16(z, z->sp, get_hlx(z)); set_hlx(z, t); z->wz = t; z->t += 19; break; }
            case 5: { uint16_t t = DE(z); set_de(z, HL(z)); set_hl(z, t); z->t += 4; break; }   /* EX DE,HL ignores prefixes */
            case 6: z->iff1 = z->iff2 = 0; z->t += 4; break;
            default: z->iff1 = z->iff2 = 1; z->ei_delay = 1; z->t += 4; break;
            }
            break;
        case 4:
            nn = fetch16(z); z->wz = nn;
            if (cond(z, y)) { push(z, z->pc); z->pc = nn; z->t += 17; } else z->t += 10;
            break;
        case 5:
            if (q == 0) { push(z, get_rp2(z, p)); z->t += 11; }
            else if (p == 0) { nn = fetch16(z); z->wz = nn; push(z, z->pc); z->pc = nn; z->t += 17; }
            break;                                       /* DD ED FD: handled by the caller */
        case 6:
            v = fetch(z); alu(z, y, v); z->t += 7; break;
        default:
            push(z, z->pc); z->pc = (uint16_t)(y * 8); z->wz = z->pc; z->t += 11; break;
        }
        break;
    }
}

static inline void bump_r(z80_t *z) { z->rr = (uint8_t)((z->rr & 0x80) | ((z->rr + 1) & 0x7f)); }

static int z80_irq_accept(z80_t *z, int nmi)
{
    z->halted = 0;
    z->iff1 = 0;
    bump_r(z);
    if (nmi) {
        z->iff2 = z->iff1;                          /* iff2 keeps the old iff1 below */
        push(z, z->pc); z->pc = 0x66; z->wz = 0x66;
        return 11;
    }
    z->iff2 = 0;
    uint8_t vec = z->bus.int_ack(z->bus.ctx);
    switch (z->im) {
    case 2: {
        push(z, z->pc);
        z->pc = rd16(z, (uint16_t)((z->i << 8) | (vec & 0xfe)));
        z->wz = z->pc;
        return 19; }
    case 1:
        push(z, z->pc); z->pc = 0x38; z->wz = 0x38; return 13;
    default:
        if ((vec & 0xc7) == 0xc7) { push(z, z->pc); z->pc = (uint16_t)(vec & 0x38); z->wz = z->pc; return 13; }
        push(z, z->pc); z->pc = 0x38; z->wz = 0x38; return 13;       /* no data on the bus: RST 38 */
    }
}

static int z80_step(void *vz)
{
    z80_t *z = vz;
    int ei_block = z->ei_delay;
    z->ei_delay = 0;
    z->t = 0;
    z->idx = NULL;

    if (z->nmi_edge) {
        z->nmi_edge = 0;
        uint8_t old = z->iff1;
        int t = z80_irq_accept(z, 1);
        z->iff2 = old;
        return t;
    }
    if (z->int_line && z->iff1 && !ei_block) return z80_irq_accept(z, 0);
    if (z->halted) { bump_r(z); return 4; }

    z->insns++;
    uint8_t op = fetch(z);
    bump_r(z);
    for (;;) {
        if (op == 0xdd || op == 0xfd) {
            /* index prefix: a chain of DD/FD only counts the last one; each prefix costs 4 T states */
            z->idx = (op == 0xdd) ? &z->ix : &z->iy;
            z->t += 4;
            op = fetch(z);
            bump_r(z);
            if (op == 0xdd || op == 0xfd) continue;
            if (op == 0xed) { z->idx = NULL; exec_ed(z); return z->t; }
            if (op == 0xcb) { exec_cb(z); return z->t; }
            break;
        }
        break;
    }
    if (op == 0xcb && !z->idx) { exec_cb(z); return z->t + 0; }
    if (op == 0xed) { exec_ed(z); return z->t; }
    exec_main(z, op);
    return z->t;
}

/* ---------------------------------------------------------------- */
/* plug-in interface                                                 */
/* ---------------------------------------------------------------- */
static void *z80_create(const sub_bus_t *bus)
{
    z80_t *z = calloc(1, sizeof *z);
    init_tables();
    if (!z) return NULL;
    z->bus = *bus;
    return z;
}
static void z80_destroy(void *z) { free(z); }

static void z80_reset(void *vz)
{
    z80_t *z = vz;
    memset(z->r, 0, sizeof z->r);
    memset(z->r2, 0, sizeof z->r2);
    z->f = z->f2 = 0xff;
    z->r[R_A] = z->r2[R_A] = 0xff;
    z->sp = 0xffff;
    z->ix = z->iy = 0xffff;
    z->pc = 0; z->wz = 0;
    z->i = z->rr = 0;
    z->iff1 = z->iff2 = 0; z->im = 0;
    z->halted = z->ei_delay = 0;
    z->nmi_edge = 0;
}

static void z80_set_line(void *vz, int line, int level)
{
    z80_t *z = vz;
    if (line == SUB_INT) z->int_line = (uint8_t)level;
    else {
        if (level && !z->nmi_line) z->nmi_edge = 1;       /* edge triggered */
        z->nmi_line = (uint8_t)level;
    }
}

static int z80_is_halted(void *vz) { return ((z80_t *)vz)->halted; }
static int z80_int_ok(void *vz) { z80_t *z = vz; return z->iff1 && !z->ei_delay; }
static uint32_t z80_pc(void *vz) { return ((z80_t *)vz)->pc; }
static uint64_t z80_insns(void *vz) { return ((z80_t *)vz)->insns; }

static void z80_dump(void *vz, FILE *f)
{
    z80_t *z = vz;
    fprintf(f, "PC=%04X SP=%04X AF=%02X%02X BC=%02X%02X DE=%02X%02X HL=%02X%02X IX=%04X IY=%04X I=%02X IM%d IFF=%d%d%s",
            z->pc, z->sp, z->r[R_A], z->f, z->r[R_B], z->r[R_C], z->r[R_D], z->r[R_E], z->r[R_H], z->r[R_L],
            z->ix, z->iy, z->i, z->im, z->iff1, z->iff2, z->halted ? " HALT" : "");
}

/* test access (tests/z80_test.c) */
uint16_t z80_get_reg(void *vz, const char *name)
{
    z80_t *z = vz;
    if (!strcmp(name, "a")) return z->r[R_A];
    if (!strcmp(name, "f")) return z->f;
    if (!strcmp(name, "b")) return z->r[R_B];
    if (!strcmp(name, "c")) return z->r[R_C];
    if (!strcmp(name, "d")) return z->r[R_D];
    if (!strcmp(name, "e")) return z->r[R_E];
    if (!strcmp(name, "h")) return z->r[R_H];
    if (!strcmp(name, "l")) return z->r[R_L];
    if (!strcmp(name, "bc")) return BC(z);
    if (!strcmp(name, "de")) return DE(z);
    if (!strcmp(name, "hl")) return HL(z);
    if (!strcmp(name, "ix")) return z->ix;
    if (!strcmp(name, "iy")) return z->iy;
    if (!strcmp(name, "sp")) return z->sp;
    if (!strcmp(name, "pc")) return z->pc;
    if (!strcmp(name, "wz")) return z->wz;
    if (!strcmp(name, "r")) return z->rr;
    if (!strcmp(name, "iff1")) return z->iff1;
    return 0xdead;
}
void z80_set_reg(void *vz, const char *name, uint16_t v)
{
    z80_t *z = vz;
    if (!strcmp(name, "a")) z->r[R_A] = (uint8_t)v;
    else if (!strcmp(name, "f")) z->f = (uint8_t)v;
    else if (!strcmp(name, "b")) z->r[R_B] = (uint8_t)v;
    else if (!strcmp(name, "c")) z->r[R_C] = (uint8_t)v;
    else if (!strcmp(name, "bc")) set_bc(z, v);
    else if (!strcmp(name, "de")) set_de(z, v);
    else if (!strcmp(name, "hl")) set_hl(z, v);
    else if (!strcmp(name, "ix")) z->ix = v;
    else if (!strcmp(name, "iy")) z->iy = v;
    else if (!strcmp(name, "sp")) z->sp = v;
    else if (!strcmp(name, "pc")) z->pc = v;
}

const sub_cpu_ops_t sub_cpu_z80 = {
    .name = "z80",
    .desc = "Zilog Z80H, 8 MHz, 64KB memory space",
    .id = 1,
    .addr_bits = 16,
    .max_hz = 8000000,
    .create = z80_create,
    .destroy = z80_destroy,
    .reset = z80_reset,
    .step = z80_step,
    .set_line = z80_set_line,
    .is_halted = z80_is_halted,
    .int_pending_ok = z80_int_ok,
    .pc = z80_pc,
    .insn_count = z80_insns,
    .dump = z80_dump,
};
