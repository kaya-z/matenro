/* SPDX-License-Identifier: MIT */
/*
 * subcpu.h - pluggable second ("sub") CPU interface of the Matenro machine
 *
 * The Matenro machine is a tightly coupled heterogeneous dual CPU system:
 * the MC6809 (running OS-9 Level 2) is the main CPU, a second CPU with an
 * 8 bit data bus (Z80, 8088, ...) is plugged in behind this interface and
 * shares the physical RAM with the 6809.
 *
 * A CPU backend implements `sub_cpu_ops_t`.  It never touches the machine
 * directly: all memory / I/O accesses go through the `sub_bus_t` callbacks,
 * so that a new CPU needs only one source file and one line in the table of
 * subcpu.c.
 *
 * Idea of the machine: the Fujitsu FM-11 "Manhattan System", where an 8088
 * (or Z80 on other models) card shared the main memory with the MC6809.
 * No Fujitsu documentation or code was used; the register interface of this
 * project (see docs/DESIGN.md) is an original design.
 */
#ifndef SUBCPU_H
#define SUBCPU_H

#include <stdint.h>
#include <stdio.h>

/* interrupt inputs of a sub CPU */
enum { SUB_INT = 0, SUB_NMI = 1 };

typedef struct sub_bus {
    void *ctx;
    /* memory space: `addr` has at most ops->addr_bits significant bits */
    uint8_t (*mem_read)(void *ctx, uint32_t addr);
    void    (*mem_write)(void *ctx, uint32_t addr, uint8_t v);
    /* I/O space (16 bit port number; only the low 8 bits are decoded) */
    uint8_t (*io_read)(void *ctx, uint16_t port);
    void    (*io_write)(void *ctx, uint16_t port, uint8_t v);
    /* maskable interrupt acknowledge: returns the vector / opcode byte */
    uint8_t (*int_ack)(void *ctx);
} sub_bus_t;

typedef struct sub_cpu_ops {
    const char *name;           /* "z80", "8088"                                     */
    const char *desc;           /* one line description                              */
    int         id;             /* value of the XID register                         */
    int         addr_bits;      /* 16 (Z80), 20 (8088)                               */
    uint32_t    max_hz;         /* highest clock of the historical part grade        */
    void   *(*create)(const sub_bus_t *bus);
    void    (*destroy)(void *cpu);
    void    (*reset)(void *cpu);
    /* execute one instruction (or one interrupt entry, or one idle slot of a
     * halted CPU).  Returns the number of CPU clocks (T states) used. */
    int     (*step)(void *cpu);
    void    (*set_line)(void *cpu, int line, int level);
    int     (*is_halted)(void *cpu);        /* executed HLT, waiting for an interrupt */
    int     (*int_pending_ok)(void *cpu);   /* would a pending INT be accepted now?   */
    uint32_t (*pc)(void *cpu);              /* linear address of the next instruction */
    uint64_t (*insn_count)(void *cpu);
    void    (*dump)(void *cpu, FILE *f);    /* one line register dump                  */
    /* optional: the timing of the real bus (the board's time, simulator option -hw).  set_timing(1) turns the bus interface
     * unit of the CPU on (prefetch queue); bus_cycles() gives the byte-wide bus cycles of the last step: reads (opcode
     * prefetches and data) and writes. */
    void    (*set_timing)(void *cpu, int on);
    void    (*bus_cycles)(void *cpu, unsigned *rd, unsigned *wr);
} sub_cpu_ops_t;

extern const sub_cpu_ops_t sub_cpu_z80;
extern const sub_cpu_ops_t sub_cpu_i8088;

/* registry */
const sub_cpu_ops_t *sub_cpu_find(const char *name);
const sub_cpu_ops_t *sub_cpu_by_index(int i);

#endif
