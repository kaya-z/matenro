/* SPDX-License-Identifier: MIT */
/*
 * memtest.c - the memory test of the power-on sequence
 *
 * The real sim09 board (sim09, fpga/tn9k/rtl/sbc09_soc.v, parameter MEMTEST) tests its whole 2MB PSRAM
 * in hardware before the 6809 is released from reset: three passes over the RAM, each one writes every byte
 * and reads it back:
 *     pass 0: $55     pass 1: $AA     pass 2: the address folded to 8 bits (a[7:0] ^ a[15:8] ^ a[21:16])
 * The console shows "Memory " and one ">" for every 256KB read back (24 for 2MB), then " OK 2048K", or
 * " NG @aaaaaa" with the address of the first mismatch (6 hex digits); the start-up goes on in both cases.
 * Afterwards the RAM is cleared.  This file repeats that sequence and the text on the host RAM, so that the
 * console output of the simulator is the one of the board.  The algorithm and the message are taken from the
 * RTL of sim09 (the 6809 side of this project does not otherwise depend on it).
 *
 * A host RAM cannot fail, so `fault` (-memfault) injects a stuck bit 0 at one address to exercise the NG path.
 */
#include <stdio.h>
#include <string.h>
#include "machine.h"

static uint8_t pattern(int pass, uint32_t a)
{
    if (pass == 0) return 0x55;
    if (pass == 1) return 0xAA;
    return (uint8_t)((a & 0xff) ^ ((a >> 8) & 0xff) ^ ((a >> 16) & 0x3f));
}

/* Runs the test on the RAM of the machine (the Level 2 pool, or the 64KB of Level 1), clears it, and leaves the
 * console text in `out` (CR LF terminated).  Returns 0 when the memory is good, -1 on a mismatch.
 * Call it before anything is stored in the RAM (ROM, sub CPU programs).  `fault` < 0: no fault injection. */
int machine_memtest(machine_t *m, long fault, char *out, size_t outsz)
{
    uint8_t *ram = m->level2 ? m->phymem : m->mem1;
    uint32_t size = m->level2 ? (uint32_t)m->physsize : 0x10000;
    uint32_t last = size - 1, bad = 0;
    int failed = 0;
    size_t n = 0;

    n += (size_t)snprintf(out + n, outsz - n, "Matenro Memory ");
    for (int pass = 0; pass < 3; pass++) {
        for (uint32_t a = 0; a <= last; a++) ram[a] = pattern(pass, a);
        for (uint32_t a = 0; a <= last; a++) {
            uint8_t got = ram[a];
            if (fault >= 0 && (uint32_t)fault == a) got ^= 0x01;
            if (got != pattern(pass, a) && !failed) { failed = 1; bad = a; }
            if ((a & 0x3ffff) == 0x3ffff || a == last)
                if (n + 1 < outsz) out[n++] = '>';
        }
    }
    memset(ram, 0, size);
    if (failed) snprintf(out + n, outsz - n, " NG @%06X\r\n", (unsigned)bad);
    else        snprintf(out + n, outsz - n, " OK %uK\r\n", (unsigned)(size / 1024));
    return failed ? -1 : 0;
}
