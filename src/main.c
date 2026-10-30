/* SPDX-License-Identifier: MIT */
/*
 * main.c - Matenro machine driver (MC6809 + pluggable sub CPU)
 *
 * Derived from sim09's main.c (MC6809 / OS-9 simulator driver) of
 * https://github.com/shinji-kono/sbc09 style projects; extended with the
 * sub CPU options (-sub -subclock -xbase -xload -xt -xcon -xrun -xquantum).
 *
 * Credits: the command line (-rom -0 -1 -v -t -tl -th -nt -e -l -m) and the
 * overall behaviour follow sbc09 src/v09.c by L.C. Benschop / Shinji Kono
 * (GPL v2); the CPU core is modelled after sbc09 v09s.c and MAME m6809.cpp
 * (see m6809.h).
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <time.h>

#include "machine.h"
#include "console.h"
#include "net.h"
#include "dbg.h"

extern int vdisk_debug;
extern int vdisk_kanji_names;

static void usage(const char *prog)
{
    fprintf(stderr,
"摩天楼 (Matenro): MC6809 (OS-9 Level 2) + pluggable Z80 / 8088 sub CPU sharing the RAM\n"
"Usage: %s [options]\n"
"  -2                 Level 2 machine (CoCo style MMU, 2MB)  [default]\n"
"  -L1                Level 1 machine (flat 64KB, no sub CPU)\n"
"  -sub name          plug in a sub CPU: z80 or 8088 (shares the RAM with the 6809)\n"
"  -subclock hz       sub CPU clock (default: the maximum of the part, 8 MHz)\n"
"  -xbase blk         first physical 8KB block of the sub CPU memory (default 0x80 = 1MB)\n"
"  -xload file@addr   load a binary into the sub CPU address space (hex addr, repeatable)\n"
"  -xrun              release the sub CPU from reset at power on\n"
"  -xt file           sub CPU instruction trace    -xcon file  sub CPU debug console (default stderr)\n"
"  -xquantum n        6809 cycles between two synchronisations of the CPUs (default 16)\n"
"  -xwatch lo[-hi]    log every sub CPU write to an address range (hex)\n"
"  -rom file          ROM image (default: v09.rom monitor)\n"
"  -l addr            ROM start address (Level 1)\n"
"  -m bytes           RAM of the 6809 (Level 2, default 2M); the rest up to 2M is the sub CPU pool\n"
"  -0 img -1 img      raw disk images for /d0 /d1\n"
"  -v dir             host directory exported as /v0   (-v1 .. -v3 for more)\n"
"  -t file            instruction trace file   -tl lo  -th hi   limit trace range\n"
"  -nt                start in the monitor, timer off\n"
"  -e char            escape character that enters the monitor (default 0x1d)\n"
"  -hz n              timer interrupt rate (default 50)\n"
"  -clock hz          6809 clock in Hz (default 2000000, MC68B09E)\n"
"  -max               run at full host speed (no real time pacing)\n"
"  -kanji mode        guest character set: raw (as the terminal, default), utf8, euc, sjis\n"
"  -hostcs name       character set of the host terminal / files (default: from the locale)\n"
"  -kname             allow 8-bit (Japanese) file names on /v0\n"
"  -script file       drive the console from an expect/send script\n"
"  -net spec          network port, e.g. 1=listen:6809  2=modem  3=tcp:host:port\n"
"  -icount n          (debug) timer tick every n instructions instead of cycles\n"
"  -maxcount n        (debug) stop after n instructions (with -icount: cross check runs)\n"
"  -dettype start gap text  (debug) type text, one character every gap instructions from instruction start\n"
"  -os9trace          log every OS-9 system call to stderr\n"
"  -stats             print instruction / cycle counts and speed at exit\n"
"  -watch lo[-hi]     log every CPU write to an address range\n"
"  -vdebug            trace the virtual disk\n", prog);
    exit(1);
}

static long parse_size(const char *s)
{
    char *e;
    long v = strtol(s, &e, 0);
    if (*e == 'k' || *e == 'K') v *= 1024;
    else if (*e == 'm' || *e == 'M') v *= 1024 * 1024;
    return v;
}

int main(int argc, char **argv)
{
    int level2 = 1, i;
    const char *subname = NULL, *xt = NULL, *xcon = NULL, *xload[8];
    int nxload = 0, xrun = 0, xbase = 0x80, xquantum = 16;
    long subclock = 0;
    const char *xwatch = NULL;
    const char *rom = NULL, *img[2] = { NULL, NULL };
    const char *tracefn = NULL, *script = NULL;
    long romstart = 0x8000, memsize = 2048 * 1024;
    long hz = 50, clock_hz = 2000000;
    int start_mon = 0, notimer = 0, realtime = 1, kanji = KANJI_RAW, escch = 0x1d;
    long tl = 0, th = 0xffff;
    long icount = 0;
    char *base = strdup(argv[0]);
    const char *bn = basename(base);
    machine_t *m;
    const char *hostcs = NULL, *watch = NULL;
    int stats = 0;
    unsigned long m_dettype_start = 0, m_dettype_gap = 0;
    const char *m_dettype_text = NULL;
    unsigned long maxcount = 0;
    struct timespec t0, t1;
    const char *netspec[8];
    int nnet = 0;

    (void)bn;

    for (i = 1; i < argc; i++) {
        char *a = argv[i];
#define NEXT() (i + 1 < argc ? argv[++i] : (usage(argv[0]), (char *)0))
        if (!strcmp(a, "-2")) level2 = 1;
        else if (!strcmp(a, "-L1")) level2 = 0;
        else if (!strcmp(a, "-sub")) subname = NEXT();
        else if (!strcmp(a, "-subclock")) subclock = parse_size(NEXT());
        else if (!strcmp(a, "-xbase")) xbase = (int)strtol(NEXT(), 0, 0);
        else if (!strcmp(a, "-xload")) { if (nxload < 8) xload[nxload++] = NEXT(); else NEXT(); }
        else if (!strcmp(a, "-xrun")) xrun = 1;
        else if (!strcmp(a, "-xt")) xt = NEXT();
        else if (!strcmp(a, "-xcon")) xcon = NEXT();
        else if (!strcmp(a, "-xquantum")) xquantum = (int)strtol(NEXT(), 0, 0);
        else if (!strcmp(a, "-xwatch")) xwatch = NEXT();
        else if (!strcmp(a, "-rom")) rom = NEXT();
        else if (!strcmp(a, "-l")) romstart = strtol(NEXT(), 0, 0);
        else if (!strcmp(a, "-m")) memsize = parse_size(NEXT());
        else if (!strcmp(a, "-0")) img[0] = NEXT();
        else if (!strcmp(a, "-1")) img[1] = NEXT();
        else if (!strncmp(a, "-v", 2) && a[2] >= '0' && a[2] <= '3' && !a[3]) vdisk_set_root(a[2] - '0', NEXT());
        else if (!strcmp(a, "-v")) vdisk_set_root(0, NEXT());
        else if (!strcmp(a, "-t")) tracefn = NEXT();
        else if (!strcmp(a, "-tl")) tl = strtol(NEXT(), 0, 0);
        else if (!strcmp(a, "-th")) th = strtol(NEXT(), 0, 0);
        else if (!strcmp(a, "-nt")) { start_mon = 1; notimer = 1; }
        else if (!strcmp(a, "-e")) escch = (int)strtol(NEXT(), 0, 0);
        else if (!strcmp(a, "-hz")) hz = strtol(NEXT(), 0, 0);
        else if (!strcmp(a, "-clock")) clock_hz = parse_size(NEXT());
        else if (!strcmp(a, "-max")) realtime = 0;
        else if (!strcmp(a, "-kanji")) {
            char *k = NEXT();
            if (!strcmp(k, "euc") || !strcmp(k, "eucjp")) kanji = KANJI_EUC;
            else if (!strcmp(k, "sjis") || !strcmp(k, "cp932")) kanji = KANJI_SJIS;
            else if (!strcmp(k, "utf8") || !strcmp(k, "utf-8")) kanji = KANJI_UTF8;
            else kanji = KANJI_RAW;
        }
        else if (!strcmp(a, "-hostcs")) hostcs = NEXT();
        else if (!strcmp(a, "-kname")) vdisk_kanji_names = 1;
        else if (!strcmp(a, "-script")) script = NEXT();
        else if (!strcmp(a, "-net")) { if (nnet < 8) netspec[nnet++] = NEXT(); else NEXT(); }
        else if (!strcmp(a, "-icount")) icount = strtol(NEXT(), 0, 0);
        else if (!strcmp(a, "-vdebug")) vdisk_debug = 1;
        else if (!strcmp(a, "-vdebug2")) vdisk_debug = 2;
        else if (!strcmp(a, "-os9trace")) { dbg_os9trace = 1; }
        else if (!strcmp(a, "-watch")) { watch = NEXT(); }
        else if (!strcmp(a, "-stats")) stats = 1;
        else if (!strcmp(a, "-maxcount")) maxcount = strtoul(NEXT(), 0, 0);
        else if (!strcmp(a, "-dettype")) {
            m_dettype_start = strtoul(NEXT(), 0, 0);
            m_dettype_gap = strtoul(NEXT(), 0, 0);
            m_dettype_text = NEXT();
        }
        else usage(argv[0]);
    }

    if (!rom) {
        static const char *cands[] = { "v09.rom", "os9/v09.rom", "../v09.rom", NULL };
        for (int k = 0; cands[k]; k++) if (access(cands[k], R_OK) == 0) { rom = cands[k]; break; }
        if (!rom) { fprintf(stderr, "no ROM image (use -rom)\n"); return 2; }
    }

    m = machine_create(level2, (size_t)memsize);
    if (!m) { fprintf(stderr, "out of memory\n"); return 2; }
    m->clock_hz = clock_hz;
    m->realtime = realtime;
    if (icount) { m->det_icount = (int)icount; m->det_next = (uint64_t)icount; }
    if (machine_load_rom(m, rom, romstart)) { perror(rom); return 2; }
    if (subname && strcmp(subname, "none")) {
        if (!level2) { fprintf(stderr, "a sub CPU needs the Level 2 machine\n"); return 2; }
        m->xl = xlink_create(m, subname, (uint32_t)subclock);
        if (!m->xl) { fprintf(stderr, "unknown sub CPU '%s' (z80, 8088)\n", subname); return 2; }
        for (i = 0; i < XL_BLOCKS; i++) m->xl->map[i] = (uint8_t)(xbase + i);
        m->xl->quantum = xquantum > 0 ? xquantum : 16;
        if (xwatch) {
            char *e;
            m->xl->watch_lo = (int)strtol(xwatch, &e, 16);
            m->xl->watch_hi = *e == '-' ? (int)strtol(e + 1, 0, 16) : m->xl->watch_lo;
        }
        if (xt && !(m->xl->trace = fopen(xt, "w"))) { perror(xt); return 2; }
        if (xcon && !(m->xl->con = fopen(xcon, "w"))) { perror(xcon); return 2; }
        for (int k = 0; k < nxload; k++) {
            char *spec = strdup(xload[k]), *at = strrchr(spec, '@');
            uint32_t addr = 0;
            FILE *f;
            static uint8_t buf[1 << 20];
            size_t n;
            if (at) { *at = 0; addr = (uint32_t)strtoul(at + 1, 0, 16); }
            if (!(f = fopen(spec, "rb"))) { perror(spec); return 2; }
            n = fread(buf, 1, sizeof buf, f);
            fclose(f);
            xlink_load(m->xl, addr, buf, n);
            free(spec);
        }
    }
    for (i = 0; i < 2; i++)
        if (img[i] && !(m->disk[i] = fopen(img[i], "r+"))) { perror(img[i]); return 2; }

    if (notimer) machine_set_timer(m, hz, M6809_IRQ_LINE, 1);
    else if (strcmp(rom, "v09.rom") && !strstr(rom, "v09.rom")) machine_set_timer(m, hz, M6809_IRQ_LINE, 2);
    else machine_set_timer(m, hz, M6809_FIRQ_LINE, 0);

    if (tracefn) {
        m->tracefile = fopen(tracefn, "w");
        if (!m->tracefile) { perror(tracefn); return 2; }
        m->trace = 1;
    }
    m->trace_lo = (uint16_t)tl; m->trace_hi = (uint16_t)th;

    console_init_locale();
    if (hostcs) console_set_hostcs(hostcs);
    console_set_escape(escch);
    console_set_kanji(kanji);
    if (script && console_load_script(script)) { perror(script); return 2; }
    console_setup(m);
    for (i = 0; i < nnet; i++)
        if (net_config(m, netspec[i])) fprintf(stderr, "bad -net spec: %s\n", netspec[i]);

    if (watch) {
        char *e;
        m->watch_lo = (int)strtol(watch, &e, 0);
        m->watch_hi = *e == '-' ? (int)strtol(e + 1, 0, 0) : m->watch_lo;
        if (!m->watch_hi) m->watch_hi = m->watch_lo;
    }
    m->max_count = maxcount;
    if (m_dettype_text) {
        m->dettype_start = m_dettype_start; m->dettype_gap = m_dettype_gap;
        m->dettype_text = m_dettype_text;
    }
    machine_reset(m);
    if (m->xl && xrun) m->xl->ctl |= XC_RUN;
    if (icount) m->cpu.cc = 0;          /* the reference simulator starts with CC = 0 (cross check runs) */
    m->want_monitor = start_mon;
    clock_gettime(CLOCK_MONOTONIC, &t0);

    for (;;) {
        if (m->want_monitor) { dbg_monitor(m); if (m->quit) break; }
        machine_run(m, 0);
        if (m->quit) break;
        if (!m->want_monitor) break;
    }

    clock_gettime(CLOCK_MONOTONIC, &t1);
    console_shutdown();
    net_shutdown(m);
    if (stats) {
        double sec = (double)(t1.tv_sec - t0.tv_sec) + (double)(t1.tv_nsec - t0.tv_nsec) / 1e9;
        fprintf(stderr, "\n%llu instructions, %llu cycles (%.2f s of emulated time at %ld Hz) in %.2f s host time: %.1f MIPS, %.1fx real time\n",
                (unsigned long long)m->cpu.insn_count, (unsigned long long)m->cpu.total_cycles,
                (double)m->cpu.total_cycles / (double)m->clock_hz, m->clock_hz, sec,
                (double)m->cpu.insn_count / sec / 1e6, ((double)m->cpu.total_cycles / (double)m->clock_hz) / sec);
    }
    if (m->tracefile && m->tracefile != stdout) fclose(m->tracefile);
    return m->exit_code;
}
