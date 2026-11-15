/* SPDX-License-Identifier: MIT */
/*
 * xlink.h - the "cross link" between the MC6809 main CPU and the sub CPU
 *
 * Shared RAM, address mapping (SMMU), mailbox, doorbell interrupts and the
 * scheduler glue of the Matenro machine.  The register layout is
 * documented in docs/DESIGN.md.
 */
#ifndef XLINK_H
#define XLINK_H

#include <stdint.h>
#include <stdio.h>
#include "subcpu.h"

struct machine;

/* main CPU side registers: offsets from the I/O base ($FF80 on the Level 2 machine).
 *
 * The I/O page of the sim09 Level 2 machine is almost full ($FFD0-$FFFF holds the code and data of the OS-9
 * vector page, $FFC0-$FFC9 the disk registers), so the cross link needs only 5 bytes at $FFCA-$FFCE
 * (offsets $4A-$4E): three direct registers and an index / data pair for the rest.  */
#define XL_BASE   0x4a
#define XL_END    0x50            /* exclusive */
#define XR_CTL    0x4a            /* R/W control                                                    */
#define XR_STAT   0x4b            /* R status                  W acknowledge the sub CPU doorbell   */
#define XR_ID     0x4c            /* R sub CPU id (0 = none)   W ring the sub CPU doorbell          */
#define XR_IDX    0x4d            /* extended register index; bit 7 = auto increment after XR_DAT   */
#define XR_DAT    0x4e            /* extended register data                                         */
#define XR_SEL    0x4f            /* SUBSEL: R the sub CPU (1 Z80, 2 8088)   W 1 / 2: choose it (the FPGA of the Tang Nano 20K has both) */

/* extended registers (index) */
#define XE_M2S    0x00            /* 4 bytes main -> sub, read / write                              */
#define XE_S2M    0x04            /* 4 bytes sub -> main, read only                                 */
#define XE_MI     0x08            /* SMMU index (0..127)                                            */
#define XE_MD     0x09            /* SMMU data: physical 8KB block of sub block XE_MI               */
#define XE_WA     0x0a            /* 3 bytes, big endian physical address of the window             */
#define XE_WD     0x0d            /* window data, the window address increments after each access   */
#define XE_KHZ    0x0e            /* 2 bytes big endian: sub CPU clock in kHz                       */
#define XE_CLK    0x10            /* 4 bytes big endian: sub CPU clock counter (latched on a read of byte 0) */
#define XE_US     0x14            /* 4 bytes big endian: microseconds since the reset (the time of the machine, 71 minutes round), latched on a read of byte 0 */

/* XR_CTL bits */
#define XC_RUN    0x01            /* 0 = sub CPU held in reset                      */
#define XC_HOLD   0x02            /* 1 = sub CPU frozen (bus hold)                   */
#define XC_SHR    0x04            /* 1 = the 6809 MMU may map the whole physical RAM */
#define XC_FIRQ   0x08            /* sub -> main interrupt uses FIRQ instead of IRQ  */
#define XC_IEN    0x10            /* sub -> main interrupt enable                    */
#define XC_RESET  0x80            /* write 1: pulse the sub CPU reset                */
#define XB_NMI    0x80            /* XR_ID write: bit 7 set rings the NMI instead of the INT doorbell */

/* XR_STAT bits */
#define XS_S2M    0x01            /* sub rang the doorbell, not yet acknowledged     */
#define XS_M2S    0x02            /* main rang the doorbell, sub has not acked yet   */
#define XS_HALT   0x04            /* sub CPU executed HLT                            */
#define XS_RUN    0x08            /* sub CPU is running                              */

/* sub CPU side ports (low nibble of the port number) */
#define XP_ID     0x00
#define XP_STAT   0x01
#define XP_BELL   0x02            /* write: ring the main CPU                        */
#define XP_ACK    0x03            /* write: acknowledge the main CPU doorbell        */
#define XP_M2S    0x04            /* 4 bytes, read only                              */
#define XP_S2M    0x08            /* 4 bytes, read / write                           */
#define XP_VEC    0x0c            /* vector byte returned on interrupt acknowledge   */
#define XP_CON    0x0e            /* debug console: bytes go to the host             */
#define XP_PWR    0x0f            /* $A5 power off (exit 0), $A6 power off (exit 1)  */

#define XL_BLOCKS 128             /* SMMU entries: 128 x 8KB = 1MB sub CPU space     */

typedef struct xlink {
    const sub_cpu_ops_t *ops;
    void     *cpu;
    struct machine *m;
    uint8_t   map[XL_BLOCKS];     /* sub block -> physical 8KB block */
    uint8_t   ctl, svec;
    uint8_t   m2s[4], s2m[4];
    uint8_t   pend_m2s, pend_s2m;
    uint8_t   nmi_req;
    uint8_t   mi;                 /* SMMU index register */
    uint8_t   idx;                /* extended register index */
    uint32_t  win;                /* window address */
    uint32_t  clk_latch;
    uint32_t  us_latch;
    uint32_t  hz;
    uint32_t  hz_opt;             /* the clock asked for (-subclock), 0 = the maximum of the CPU */
    uint64_t  period_ps;
    uint64_t  t_ps;               /* local time of the sub CPU */
    uint64_t  clocks;             /* sub CPU clocks executed   */
    int       quantum;            /* 6809 cycles between synchronisations */
    FILE     *trace;
    FILE     *con;
    uint64_t  sub_reads, sub_writes;
    int       watch_lo, watch_hi;   /* -xwatch: log sub CPU writes to [lo,hi] of its address space (-1 = off) */
} xlink_t;

/* creation: `name` selects the backend ("z80", "8088"); NULL when unknown */
xlink_t *xlink_create(struct machine *m, const char *name, uint32_t hz);
void     xlink_destroy(xlink_t *x);
void     xlink_reset(xlink_t *x);
/* SUBSEL: replace the sub CPU by the one with this id (1 = z80, 2 = 8088); the new one starts from reset */
void     xlink_select(xlink_t *x, int id);

/* load `len` bytes into the sub CPU address space (through the SMMU) */
void     xlink_load(xlink_t *x, uint32_t addr, const uint8_t *data, size_t len);

/* 6809 side register access (offset relative to the I/O base) */
uint8_t  xlink_main_read(xlink_t *x, int off);
void     xlink_main_write(xlink_t *x, int off, uint8_t v);

/* does the sub CPU currently assert a main CPU interrupt, and on which line? returns -1 / 0 (IRQ) / 1 (FIRQ) */
int      xlink_main_irq(const xlink_t *x);

/* scheduler: run the sub CPU up to the 6809's time */
void     xlink_catch_up(xlink_t *x);
int      xlink_active(const xlink_t *x);      /* does the sub CPU need real time slices? */

/* physical memory access used by both sides */
uint8_t  xlink_phys_read(xlink_t *x, uint32_t phys);
void     xlink_phys_write(xlink_t *x, uint32_t phys, uint8_t v);

#endif
