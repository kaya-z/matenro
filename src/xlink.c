/* SPDX-License-Identifier: MIT */
/*
 * xlink.c - cross link of the Matenro machine: shared RAM, SMMU, mailbox,
 *           doorbells and scheduling of the sub CPU
 *
 * Credits: the idea (two different CPUs sharing the main memory of an
 * MC6809 machine) is that of the Fujitsu FM-11 "Manhattan System"; the
 * register interface below is an original design.  The time-sliced
 * scheduling (the CPU that is behind in time runs next, the peripherals are
 * advanced by the cycles actually consumed) follows the structure of the
 * sim09 run loop (machine.c), itself modelled after MAME's device scheduler.
 */
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "machine.h"
#include "xlink.h"

/* ------------------------------------------------------------------ */
/* registry of the pluggable CPUs                                      */
/* ------------------------------------------------------------------ */
static const sub_cpu_ops_t *const registry[] = { &sub_cpu_z80, &sub_cpu_i8088 };

const sub_cpu_ops_t *sub_cpu_by_index(int i)
{
    return (i >= 0 && i < (int)(sizeof registry / sizeof registry[0])) ? registry[i] : NULL;
}

const sub_cpu_ops_t *sub_cpu_find(const char *name)
{
    for (int i = 0; sub_cpu_by_index(i); i++) {
        const sub_cpu_ops_t *o = sub_cpu_by_index(i);
        if (!strcasecmp(o->name, name)) return o;
        if (!strcasecmp(name, "i8088") && o->id == 2) return o;
    }
    return NULL;
}

/* ------------------------------------------------------------------ */
/* physical memory as seen by the sub CPU                              */
/* ------------------------------------------------------------------ */
#define IOPAGE_PHYS 0x7fe00u        /* the 6809 I/O page: not RAM */

uint8_t xlink_phys_read(xlink_t *x, uint32_t p)
{
    machine_t *m = x->m;
    if (p >= m->physsize) return 0xff;
    if (p >= IOPAGE_PHYS && p < 0x80000u) return 0xff;
    return m->phymem[p];
}

void xlink_phys_write(xlink_t *x, uint32_t p, uint8_t v)
{
    machine_t *m = x->m;
    if (p >= m->physsize) return;
    if (p >= IOPAGE_PHYS && p < 0x80000u) return;
    m->phymem[p] = v;
}

static inline uint32_t sub_phys(xlink_t *x, uint32_t a)
{
    a &= (x->ops->addr_bits == 16) ? 0xffffu : 0xfffffu;
    return ((uint32_t)x->map[a >> 13] << 13) | (a & 0x1fff);
}

static uint8_t sub_mem_read(void *ctx, uint32_t a)
{
    xlink_t *x = ctx;
    x->sub_reads++;
    return xlink_phys_read(x, sub_phys(x, a));
}

static void sub_mem_write(void *ctx, uint32_t a, uint8_t v)
{
    xlink_t *x = ctx;
    x->sub_writes++;
    if (x->watch_hi >= 0 && (int)a >= x->watch_lo && (int)a <= x->watch_hi)
        fprintf(stderr, "XWATCH write [%05X]=%02X by pc=%05X\n", a, v, x->ops->pc(x->cpu));
    xlink_phys_write(x, sub_phys(x, a), v);
}

/* ------------------------------------------------------------------ */
/* interrupt lines                                                     */
/* ------------------------------------------------------------------ */
static void sub_lines_update(xlink_t *x)
{
    x->ops->set_line(x->cpu, SUB_INT, x->pend_m2s);
}

int xlink_main_irq(const xlink_t *x)
{
    if (x->pend_s2m && (x->ctl & XC_IEN)) return (x->ctl & XC_FIRQ) ? 1 : 0;
    return -1;
}

static int running(const xlink_t *x) { return (x->ctl & XC_RUN) && !(x->ctl & XC_HOLD); }

/* ------------------------------------------------------------------ */
/* sub CPU I/O ports                                                   */
/* ------------------------------------------------------------------ */
static uint8_t sub_stat(const xlink_t *x)
{
    /* sub's view: bit0 = the main CPU rang (M2S), bit1 = my own ring is not acknowledged yet (S2M) */
    return (uint8_t)((x->pend_m2s ? 0x01 : 0) | (x->pend_s2m ? 0x02 : 0) | 0x80);
}

static uint8_t sub_io_read(void *ctx, uint16_t port)
{
    xlink_t *x = ctx;
    int p = port & 0xff;
    if (p & 0xf0) return 0xff;
    if (p == XP_ID) return (uint8_t)x->ops->id;
    if (p == XP_STAT) return sub_stat(x);
    if (p >= XP_M2S && p < XP_M2S + 4) return x->m2s[p - XP_M2S];
    if (p >= XP_S2M && p < XP_S2M + 4) return x->s2m[p - XP_S2M];
    if (p == XP_VEC) return x->svec;
    return 0xff;
}

static void sub_io_write(void *ctx, uint16_t port, uint8_t v)
{
    xlink_t *x = ctx;
    int p = port & 0xff;
    if (p & 0xf0) return;
    switch (p) {
    case XP_BELL:
        x->pend_s2m = 1;
        machine_update_irq(x->m);
        break;
    case XP_ACK:
        x->pend_m2s = 0;
        sub_lines_update(x);
        break;
    case XP_VEC: x->svec = v; break;
    case XP_CON:
        if (x->con) { fputc(v, x->con); fflush(x->con); }
        break;
    case XP_PWR:
        if (v == 0xa5 || v == 0xa6) { x->m->stop = 1; x->m->quit = 1; x->m->exit_code = (v == 0xa6); }
        break;
    default:
        if (p >= XP_S2M && p < XP_S2M + 4) x->s2m[p - XP_S2M] = v;
        break;
    }
}

static uint8_t sub_int_ack(void *ctx)
{
    xlink_t *x = ctx;
    return x->svec;
}

/* ------------------------------------------------------------------ */
/* lifecycle                                                           */
/* ------------------------------------------------------------------ */
xlink_t *xlink_create(machine_t *m, const char *name, uint32_t hz)
{
    const sub_cpu_ops_t *ops = sub_cpu_find(name);
    xlink_t *x;
    sub_bus_t bus;
    if (!ops) return NULL;
    x = calloc(1, sizeof *x);
    if (!x) return NULL;
    x->ops = ops;
    x->m = m;
    x->hz = hz ? hz : ops->max_hz;
    x->period_ps = 1000000000000ull / x->hz;
    x->quantum = 16;
    x->watch_lo = 0; x->watch_hi = -1;
    x->con = stderr;
    bus.ctx = x;
    bus.mem_read = sub_mem_read;
    bus.mem_write = sub_mem_write;
    bus.io_read = sub_io_read;
    bus.io_write = sub_io_write;
    bus.int_ack = sub_int_ack;
    x->cpu = ops->create(&bus);
    if (!x->cpu) { free(x); return NULL; }
    for (int i = 0; i < XL_BLOCKS; i++) x->map[i] = (uint8_t)(0x80 + i);   /* upper 1MB of the physical RAM */
    x->svec = 0xff;
    ops->reset(x->cpu);
    return x;
}

void xlink_destroy(xlink_t *x)
{
    if (!x) return;
    x->ops->destroy(x->cpu);
    free(x);
}

void xlink_reset(xlink_t *x)
{
    x->ctl = 0;
    x->pend_m2s = x->pend_s2m = 0;
    x->nmi_req = 0;
    x->m->mainlimit = (uint32_t)x->m->memsize;
    x->ops->reset(x->cpu);
    x->ops->set_line(x->cpu, SUB_INT, 0);
    x->ops->set_line(x->cpu, SUB_NMI, 0);
    x->t_ps = machine_time_ps(x->m);
}

void xlink_load(xlink_t *x, uint32_t addr, const uint8_t *data, size_t len)
{
    for (size_t i = 0; i < len; i++)
        xlink_phys_write(x, sub_phys(x, (uint32_t)(addr + i)), data[i]);
}

/* ------------------------------------------------------------------ */
/* the 6809 side                                                       */
/* ------------------------------------------------------------------ */
static uint8_t ext_read(xlink_t *x, int i)
{
    switch (i) {
    case XE_MI:       return x->mi;
    case XE_MD:       return x->map[x->mi & (XL_BLOCKS - 1)];
    case XE_WA:       return (uint8_t)(x->win >> 16);
    case XE_WA + 1:   return (uint8_t)(x->win >> 8);
    case XE_WA + 2:   return (uint8_t)x->win;
    case XE_WD: {
        uint8_t v = xlink_phys_read(x, x->win);
        x->win = (x->win + 1) & 0x1fffff;
        return v; }
    case XE_KHZ:      return (uint8_t)((x->hz / 1000) >> 8);
    case XE_KHZ + 1:  return (uint8_t)(x->hz / 1000);
    case XE_CLK:      x->clk_latch = (uint32_t)x->clocks; return (uint8_t)(x->clk_latch >> 24);
    case XE_CLK + 1:  return (uint8_t)(x->clk_latch >> 16);
    case XE_CLK + 2:  return (uint8_t)(x->clk_latch >> 8);
    case XE_CLK + 3:  return (uint8_t)x->clk_latch;
    case XE_US:       x->us_latch = (uint32_t)(machine_time_ps(x->m) / 1000000ull);
                      return (uint8_t)(x->us_latch >> 24);
    case XE_US + 1:   return (uint8_t)(x->us_latch >> 16);
    case XE_US + 2:   return (uint8_t)(x->us_latch >> 8);
    case XE_US + 3:   return (uint8_t)x->us_latch;
    default: break;
    }
    if (i >= XE_M2S && i < XE_M2S + 4) return x->m2s[i - XE_M2S];
    if (i >= XE_S2M && i < XE_S2M + 4) return x->s2m[i - XE_S2M];
    return 0xff;
}

static void ext_write(xlink_t *x, int i, uint8_t v)
{
    switch (i) {
    case XE_MI: x->mi = v; return;
    case XE_MD: x->map[x->mi & (XL_BLOCKS - 1)] = v; return;
    case XE_WA:     x->win = (x->win & 0x00ffff) | ((uint32_t)(v & 0x1f) << 16); return;
    case XE_WA + 1: x->win = (x->win & 0x1f00ff) | ((uint32_t)v << 8); return;
    case XE_WA + 2: x->win = (x->win & 0x1fff00) | v; return;
    case XE_WD:
        xlink_phys_write(x, x->win, v);
        x->win = (x->win + 1) & 0x1fffff;
        return;
    default: break;
    }
    if (i >= XE_M2S && i < XE_M2S + 4) x->m2s[i - XE_M2S] = v;
}

uint8_t xlink_main_read(xlink_t *x, int off)
{
    switch (off) {
    case XR_ID:   return (uint8_t)x->ops->id;
    case XR_CTL:  return (uint8_t)(x->ctl & ~XC_RESET);
    case XR_STAT: {
        uint8_t s = 0;
        if (x->pend_s2m) s |= XS_S2M;
        if (x->pend_m2s) s |= XS_M2S;
        if (running(x)) s |= XS_RUN;
        if (running(x) && x->ops->is_halted(x->cpu)) s |= XS_HALT;
        return s; }
    case XR_IDX:  return x->idx;
    case XR_DAT: {
        uint8_t v = ext_read(x, x->idx & 0x7f);
        if (x->idx & 0x80) x->idx = (uint8_t)(0x80 | ((x->idx + 1) & 0x7f));
        return v; }
    default: return 0;
    }
}

void xlink_main_write(xlink_t *x, int off, uint8_t v)
{
    machine_t *m = x->m;
    switch (off) {
    case XR_CTL: {
        uint8_t old = x->ctl;
        if (v & XC_RESET) {
            x->ops->reset(x->cpu);
            x->pend_m2s = 0;
            sub_lines_update(x);
            x->t_ps = machine_time_ps(m);
        }
        x->ctl = (uint8_t)(v & ~XC_RESET);
        if (!(old & XC_RUN) && (v & XC_RUN)) {          /* released from reset */
            x->ops->reset(x->cpu);
            x->t_ps = machine_time_ps(m);
        }
        m->mainlimit = (x->ctl & XC_SHR) ? (uint32_t)m->physsize : (uint32_t)m->memsize;
        machine_update_irq(m);
        return; }
    case XR_ID:                                          /* doorbell to the sub CPU */
        if (v & XB_NMI) {                                /* NMI pulse */
            x->ops->set_line(x->cpu, SUB_NMI, 1);
            x->ops->set_line(x->cpu, SUB_NMI, 0);
            x->nmi_req = 1;
        } else {
            x->pend_m2s = 1;
            sub_lines_update(x);
        }
        return;
    case XR_STAT:                                        /* acknowledge the sub CPU doorbell */
        x->pend_s2m = 0;
        machine_update_irq(m);
        return;
    case XR_IDX: x->idx = v; return;
    case XR_DAT:
        ext_write(x, x->idx & 0x7f, v);
        if (x->idx & 0x80) x->idx = (uint8_t)(0x80 | ((x->idx + 1) & 0x7f));
        return;
    default: return;
    }
}

/* ------------------------------------------------------------------ */
/* scheduler                                                           */
/* ------------------------------------------------------------------ */
static int idle_halted(const xlink_t *x)
{
    return x->ops->is_halted(x->cpu) && !x->pend_m2s && !x->nmi_req;
}

int xlink_active(const xlink_t *x)
{
    return running(x) && !idle_halted(x);
}

void xlink_catch_up(xlink_t *x)
{
    uint64_t now = machine_time_ps(x->m);
    if (!running(x)) { x->t_ps = now; return; }
    while (x->t_ps < now) {
        int c;
        if (idle_halted(x)) { x->t_ps = now; break; }       /* HLT without a pending interrupt: nothing to do */
        if (x->trace) {
            fprintf(x->trace, "%12llu ", (unsigned long long)x->clocks);
            x->ops->dump(x->cpu, x->trace);
            fputc('\n', x->trace);
        }
        c = x->ops->step(x->cpu);
        x->nmi_req = 0;
        x->t_ps += (uint64_t)c * x->period_ps;
        x->clocks += (uint64_t)c;
        if (x->m->stop) break;
    }
}
