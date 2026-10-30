// SPDX-License-Identifier: MIT
// tb_xlink.cpp - Verilator test of rtl/xlink.v against the behaviour of the C simulator (src/xlink.c)
#include "Vxlink.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <vector>

static Vxlink *d;
static int fails, checks;
static std::vector<unsigned char> ram(1 << 21);
static int ack_delay = 0;

static void tick()
{
    // window memory model: acknowledge 2 clocks after the request, data valid with the ack
    d->win_ack = 0;
    if (d->win_req) {
        if (++ack_delay == 2) {
            d->win_ack = 1;
            if (d->win_wr) ram[d->win_addr] = d->win_wdata;
            d->win_rdata = ram[d->win_addr];
            ack_delay = 0;
        }
    } else ack_delay = 0;
    d->clk = 0; d->eval(); d->clk = 1; d->eval();
    d->m_re = d->m_we = d->s_re = d->s_we = 0;
}
#define EXPECT(what, got, want) do { checks++; unsigned g_ = (unsigned)(got), w_ = (unsigned)(want); \
    if (g_ != w_) { fails++; printf("FAIL %-40s got %X want %X (line %d)\n", what, g_, w_, __LINE__); } } while (0)

static void mw(int a, int v) { d->m_addr = a; d->m_wdata = v; d->m_we = 1; d->eval(); tick(); while (d->m_wait) tick(); }
static int cur_idx;
static int  mr(int a)
{
    d->m_addr = a; d->eval();
    int v = d->m_rdata;
    d->m_re = 1; d->eval(); tick();
    bool win = (a == 4 && (cur_idx & 0x7f) == 0x0d);
    while (d->m_wait) tick();
    return win ? d->win_rdata : v;
}
static void sw(int p, int v) { d->s_port = p; d->s_wdata = v; d->s_we = 1; d->eval(); tick(); }
static int  sr(int p) { d->s_port = p; d->eval(); return d->s_rdata; }
static void ext(int i, int autoinc = 0) { cur_idx = i; mw(3, i | (autoinc ? 0x80 : 0)); }

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    d = new Vxlink;
    d->rst = 1; d->sub_is_z80 = 1; d->sub_halted = 0; d->sub_clk_en = 0;
    for (int i = 0; i < 3; i++) tick();
    d->rst = 0; tick();

    d->m_addr = 2; d->eval();
    EXPECT("XID", d->m_rdata, 1);
    EXPECT("sub in reset", d->sub_rst_n, 0);
    mw(0, 0x19);                                   // RUN | FIRQ | IEN
    EXPECT("sub released", d->sub_rst_n, 1);
    EXPECT("XCTL read", ({ d->m_addr = 0; d->eval(); d->m_rdata; }), 0x19);

    // mailbox with auto increment
    ext(0, 1);
    for (int i = 0; i < 4; i++) mw(4, 0x10 + i);
    EXPECT("M2S[0] seen by sub", sr(4), 0x10); EXPECT("M2S[3] seen by sub", sr(7), 0x13);
    EXPECT("index after 4 accesses", ({ d->m_addr = 3; d->eval(); d->m_rdata; }), 0x84);

    // doorbell main -> sub
    mw(2, 0x00);
    EXPECT("sub INT asserted", d->sub_int, 1);
    EXPECT("sub stat bit0", sr(1), 0x81);
    sw(3, 0);
    EXPECT("sub INT cleared by ACK", d->sub_int, 0);
    mw(2, 0x80);
    EXPECT("NMI pulse", d->sub_nmi, 1); tick(); EXPECT("NMI pulse is one clock", d->sub_nmi, 0);

    // doorbell sub -> main (FIRQ)
    sw(8, 0xBA); sw(9, 0x13);
    EXPECT("no FIRQ yet", d->firq_o, 0);
    sw(2, 0);
    EXPECT("FIRQ after the bell", d->firq_o, 1); EXPECT("IRQ not used", d->irq_n_o, 0);
    EXPECT("XSTAT S2M", ({ d->m_addr = 1; d->eval(); d->m_rdata; }) & 1, 1);
    ext(4, 1);
    EXPECT("S2M[0] read by 6809", mr(4), 0xBA); EXPECT("S2M[1] read by 6809 (auto inc)", mr(4), 0x13);
    mw(1, 0);
    EXPECT("FIRQ cleared by ACK", d->firq_o, 0);
    mw(0, 0x01);                                   // IRQ mode, IEN off
    sw(2, 0); EXPECT("no interrupt with IEN=0", d->firq_o | d->irq_n_o, 0);
    mw(0, 0x11); EXPECT("IRQ with IEN=1", d->irq_n_o, 1);
    mw(1, 0);

    // vector byte, id, console, power
    sw(0xc, 0x20); EXPECT("svec", d->s_vec, 0x20); EXPECT("svec readback", sr(0xc), 0x20);
    EXPECT("sub id port", sr(0), 1);
    sw(0xe, 'A'); EXPECT("console strobe", d->con_we, 1); EXPECT("console data", d->con_data, 'A');
    tick(); EXPECT("console strobe one clock", d->con_we, 0);
    sw(0xf, 0xa5); EXPECT("power strobe", d->pwr_we, 1); EXPECT("power data", d->pwr_data, 0xa5);

    // SMMU
    d->sub_addr = 0x0123; d->eval();
    EXPECT("reset map block 0 -> $80", d->sub_phys, (0x80u << 13) | 0x123);
    ext(8); mw(4, 5); ext(9); mw(4, 0x42);
    d->sub_addr = 0xA123; d->eval();
    EXPECT("block 5 -> $42", d->sub_phys, (0x42u << 13) | 0x123);
    EXPECT("XE_MD read", ({ ext(9); mr(4); }), 0x42);
    d->sub_is_z80 = 0; d->sub_addr = 0xFFFF0; d->eval();
    EXPECT("8088 reset vector in block 127 -> $FF", d->sub_phys, (0xFFu << 13) | 0x1FF0);
    d->sub_is_z80 = 1;

    // window
    ext(0x0a, 1); mw(4, 0x10); mw(4, 0x01); mw(4, 0x00);   // physical $100100
    ext(0x0d);
    for (int i = 0; i < 4; i++) mw(4, 0xC0 + i);
    EXPECT("window wrote RAM", ram[0x100100], 0xC0); EXPECT("window wrote RAM +3", ram[0x100103], 0xC3);
    ext(0x0a, 1); mw(4, 0x10); mw(4, 0x01); mw(4, 0x00);
    ext(0x0d);
    EXPECT("window read 0", mr(4), 0xC0); EXPECT("window read 1", mr(4), 0xC1);
    ext(0x0a, 1);
    EXPECT("window address after 2 reads", ({ int a = mr(4); int b = mr(4); int c = mr(4); (a << 16) | (b << 8) | c; }), 0x100102);

    // clock info and counter
    ext(0x0e, 1); int hi = mr(4), lo = mr(4);
    EXPECT("XE_KHZ", (hi << 8) | lo, 7500);
    for (int i = 0; i < 1000; i++) { d->sub_clk_en = 1; tick(); }
    d->sub_clk_en = 0; tick();
    ext(0x10, 1); int b3 = mr(4), b2 = mr(4), b1 = mr(4), b0 = mr(4);
    EXPECT("clock counter", (b3 << 24) | (b2 << 16) | (b1 << 8) | b0, 1000);

    // reset pulse
    mw(0, 0x99);
    EXPECT("XC_RESET pulse", d->sub_rst_n, 0); tick(); tick();
    EXPECT("reset released again", d->sub_rst_n, 1);
    // halted / status
    d->sub_halted = 1; d->m_addr = 1; d->eval();
    EXPECT("XSTAT run+halt", d->m_rdata & 0x0c, 0x0c);

    printf("xlink RTL: %d checks, %d failed\n", checks, fails);
    delete d;
    return fails ? 1 : 0;
}
