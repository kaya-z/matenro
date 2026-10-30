// SPDX-License-Identifier: MIT
// tb_z80_soc.cpp - the 6809 side of the Matenro machine in a test bench: runs the Z80 demo (os9/sub/sumz80.py, the
// binary that the C simulator runs too) on rtl/z80_soc.v the way the OS-9 command xrun does:
//   load through the window port, release the Z80, wait for "ready", send n in M2S[0], ring, read S2M[0..1].
#include "Vz80_soc.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>

static Vz80_soc *d;
static int fails, checks;
static int cur_idx;

static void tick()
{
    d->clk = 0; d->eval(); d->clk = 1; d->eval();
    d->m_re = d->m_we = 0;
}
#define EXPECT(what, got, want) do { checks++; unsigned g_ = (unsigned)(got), w_ = (unsigned)(want); \
    if (g_ != w_) { fails++; printf("FAIL %-44s got %X want %X (line %d)\n", what, g_, w_, __LINE__); } } while (0)

static void mw(int a, int v) { d->m_addr = a; d->m_wdata = v; d->m_we = 1; d->eval(); tick(); while (d->m_wait) tick(); if (a == 3) cur_idx = v; }
static int  mr(int a)
{
    d->m_addr = a; d->m_re = 1; d->eval(); tick();
    while (d->m_wait) tick();
    d->m_addr = a; d->eval();
    return d->m_rdata;                              // after the stall of a window read the data is there
}
static void ext(int i, int autoinc = 0) { mw(3, i | (autoinc ? 0x80 : 0)); }
static void setwin(unsigned a) { ext(0x0a); mw(4, a >> 16); ext(0x0b); mw(4, a >> 8); ext(0x0c); mw(4, a); ext(0x0d); }
static int  waitbell(long clocks)
{
    for (long i = 0; i < clocks; i++) {
        d->m_addr = 1; d->eval();
        if (d->m_rdata & 1) return 1;
        tick();
    }
    return 0;
}
static int s2m(int i) { ext(4 + i); return mr(4); }

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    FILE *f = argc > 1 ? fopen(argv[1], "rb") : nullptr;
    if (!f) { printf("usage: Vz80_soc sumz80.bin\n"); return 2; }
    unsigned char img[256];
    int n = (int)fread(img, 1, sizeof img, f);
    fclose(f);

    d = new Vz80_soc;
    d->rst = 1;
    for (int i = 0; i < 3; i++) tick();
    d->rst = 0; tick();
    EXPECT("XID", ({ d->m_addr = 2; d->eval(); d->m_rdata; }), 1);
    EXPECT("Z80 held in reset", d->z80_halted, 0);

    setwin(0x100000);                               // sub CPU address 0 = physical block $80
    for (int i = 0; i < n; i++) mw(4, img[i]);
    setwin(0x100000);                               // read the image back through the window
    int bad = 0;
    for (int i = 0; i < n; i++) if (mr(4) != img[i]) bad++;
    EXPECT("image written and read back by the window", bad, 0);

    mw(0, 0x11);                                    // RUN | IEN
    EXPECT("ready doorbell from the Z80", waitbell(400000), 1);
    for (int i = 0; i < 1000; i++) tick();           // the Z80 rings, then executes HALT
    EXPECT("Z80 halted, waiting for the interrupt", d->z80_halted, 1);
    mw(1, 0);                                       // acknowledge

    static const int ns[2] = {100, 10};
    static const int want[2] = {5050, 55};
    for (int k = 0; k < 2; k++) {
        ext(0); mw(4, ns[k]);                       // M2S[0] = n
        mw(2, 0);                                   // ring the Z80 (maskable interrupt, IM 1 -> RST 38h)
        char what[64];
        snprintf(what, sizeof what, "reply for n=%d", ns[k]);
        EXPECT(what, waitbell(4000000), 1);
        int lo = s2m(0), hi = s2m(1);
        snprintf(what, sizeof what, "1+..+%d in S2M[0..1]", ns[k]);
        EXPECT(what, lo | (hi << 8), want[k]);
        setwin(0x100100);                           // the result is also in the shared RAM at sub CPU address $0100
        int rl = mr(4), rh = mr(4);
        snprintf(what, sizeof what, "1+..+%d in the shared RAM", ns[k]);
        EXPECT(what, rl | (rh << 8), want[k]);
        mw(1, 0);
    }
    printf("z80_soc: %d checks, %d failed\n", checks, fails);
    delete d;
    return fails ? 1 : 0;
}
