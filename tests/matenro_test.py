#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""Integration tests of the Matenro machine: MC6809 + Z80 / 8088 sharing the RAM.

  python3 tests/matenro_test.py            (make test-mh)

The 6809 test programs are assembled with a09 of the sbc09 project (tools only, read only):
set A09=/path/to/a09 if it is not in the default place.
"""
import os, subprocess, sys, tempfile, shutil

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SIM = os.path.join(ROOT, 'matenro')
A09 = os.environ.get('A09', '/export/nas/archives/MC6809/new-sbc09/tools/a09')
OS9 = os.environ.get('OS9DIR', '/export/nas/archives/MC6809/new-sbc09/os9')
HERE = os.path.join(ROOT, 'tests')
fails = 0
total = 0


def check(name, ok, detail=''):
    global fails, total
    total += 1
    if not ok:
        fails += 1
    print('%s %s' % ('ok  ' if ok else 'FAIL', name))
    if not ok and detail:
        print('     ' + str(detail).encode('ascii', 'replace').decode().replace('\n', '\n     '))


def run(cmd, timeout=60, **kw):
    env = dict(os.environ, LC_ALL='C')
    return subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=timeout, env=env, **kw)


def chunk(phys, data):
    lines = ['        fcb $%02X,$%02X,$%02X' % (phys >> 16, (phys >> 8) & 255, phys & 255),
             '        fdb %d' % len(data)]
    for i in range(0, len(data), 16):
        lines.append('        fcb ' + ','.join('$%02X' % b for b in data[i:i + 16]))
    return '\n'.join(lines)


def asm6809(src, out):
    r = run([A09, '-o', out, src])
    if r.returncode != 0 or b'0 Pass 2 errors' not in r.stdout:
        raise RuntimeError('a09 failed: ' + r.stdout.decode())


def z80_program():
    sys.path.insert(0, os.path.join(ROOT, 'os9', 'sub'))
    import sumz80
    return sumz80.chunks()


def i8088_program(tmp):
    asm = os.path.join(ROOT, 'os9', 'sub', 'sum8088.asm')
    out = os.path.join(tmp, 'sub8088.bin')
    r = run(['nasm', '-f', 'bin', asm, '-o', out])
    if r.returncode:
        raise RuntimeError(r.stdout.decode())
    code = open(out, 'rb').read()
    stub = bytes([0xEA, 0x00, 0x04, 0x00, 0x00])           # JMP FAR 0000:0400 at the reset vector FFFF0
    return [(0x100400, code), (0x1FFFF0, stub)]


def integration(cpu, chunks, tmp):
    n = {'z80': 1, '8088': 2}[cpu]
    src = open(os.path.join(HERE, 'mh', 'xlink_test.asm')).read()
    src = src.replace('@SUBID@', str(n)).replace('@CHUNKS@', '\n'.join(chunk(p, d) for p, d in chunks))
    sp = os.path.join(tmp, 'it_%s.asm' % cpu)
    rom = os.path.join(tmp, 'it_%s.rom' % cpu)
    open(sp, 'w').write(src)
    asm6809(sp, rom)
    r = run([SIM, '-max', '-m', '1M', '-rom', rom, '-sub', cpu], timeout=60)
    check('6809 <-> %s : mailbox, doorbell interrupts, shared RAM, window, SMMU' % cpu,
          b'PASS' in r.stdout and r.returncode == 0, r.stdout.decode(errors='replace') + ' rc=%d' % r.returncode)


def standalone(cpu, tmp):
    # a 6809 ROM that does nothing; the sub CPU runs from -xload
    sp = os.path.join(tmp, 'idle.asm')
    rom = os.path.join(tmp, 'idle.rom')
    open(sp, 'w').write('        org $E000\nstart   bra start\n        org $FFFE\n        fdb start\n')
    asm6809(sp, rom)
    if cpu == 'z80':
        msg = b'hello from the Z80\n\0'
        code = bytes([0x21, 0x12, 0x00,                    # 0000 LD HL,msg (0012h)
                      0x7E,                                # 0003 loop: LD A,(HL)
                      0xB7,                                # 0004 OR A
                      0x28, 0x06,                          # 0005 JR Z,end (000Dh)
                      0xD3, 0x0E,                          # 0007 OUT (0E),A
                      0x23,                                # 0009 INC HL
                      0x18, 0xF7,                          # 000A JR loop (0003h)
                      0x00,                                # 000C
                      0x3E, 0xA5,                          # 000D end: LD A,A5h
                      0xD3, 0x0F,                          # 000F OUT (0F),A
                      0x76]) + msg                         # 0011 HALT ; msg at 0012h
        binf = os.path.join(tmp, 'hello_z80.bin')
        open(binf, 'wb').write(code)
        xl = [binf + '@0']
        want = b'hello from the Z80'
    else:
        asm = os.path.join(HERE, 'hello8088.asm')
        binf = os.path.join(tmp, 'hello8088.bin')
        r = run(['nasm', '-f', 'bin', asm, '-o', binf])
        if r.returncode:
            raise RuntimeError(r.stdout.decode())
        stub = os.path.join(tmp, 'stub8088.bin')
        open(stub, 'wb').write(bytes([0xEA, 0x00, 0x04, 0x00, 0x00]))
        xl = [binf + '@400', stub + '@FFFF0']
        want = b'hello from the 8088'
    con = os.path.join(tmp, 'xcon_%s.txt' % cpu)
    trace = os.path.join(tmp, 'xt_%s.txt' % cpu)
    cmd = [SIM, '-max', '-m', '1M', '-rom', rom, '-sub', cpu, '-xrun', '-xcon', con, '-xt', trace]
    for x in xl:
        cmd += ['-xload', x]
    r = run(cmd, timeout=60)
    out = open(con, 'rb').read() if os.path.exists(con) else b''
    check('standalone %s from -xload: debug console and power off' % cpu, want in out and r.returncode == 0,
          'console=%r rc=%d %s' % (out, r.returncode, r.stdout.decode(errors='replace')))
    tr = open(trace).read().splitlines() if os.path.exists(trace) else []
    check('%s instruction trace (-xt)' % cpu, len(tr) > 10 and ('PC=' in tr[0] or 'IP=' in tr[0]), tr[:2])


def os9_regression(tmp):
    if not os.path.isdir(OS9):
        print('skip OS-9 regression (no %s)' % OS9)
        return
    d = os.path.join(tmp, 'os9')
    os.mkdir(d)
    for f in ('OS9.dsk', 'WORK.dsk'):
        shutil.copy(os.path.join(OS9, f), d)
    shutil.copytree(os.path.join(OS9, 'level2', 'cmds'), os.path.join(d, 'v0', 'cmds'))
    script = os.path.join(d, 'script.txt')
    open(script, 'w').write('timeout 30000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\n'
                            'send "mdir\\r"\nexpect "OS9:"\nsend "date\\r"\nexpect "OS9:"\nquit\n')
    for sub in (None, 'z80', '8088'):
        cmd = [SIM, '-max', '-rom', os.path.join(OS9, 'os9v2.rom'), '-0', os.path.join(d, 'OS9.dsk'),
               '-1', os.path.join(d, 'WORK.dsk'), '-v', os.path.join(d, 'v0'), '-script', script]
        if sub:
            cmd += ['-sub', sub, '-m', '1M']
        r = run(cmd, timeout=120)
        out = r.stdout.decode(errors='replace')
        check('OS-9 Level 2 boots%s and lists its modules' % (' with an idle %s sub CPU' % sub if sub else ''),
              'Krn' in out and 'SysGo' in out and out.count('OS9:') >= 4, out[-400:])


def os9_xrun(tmp):
    """OS-9 Level 2 user program xrun: load a sub CPU program from /v0 and talk to it"""
    if not os.path.isdir(OS9):
        return
    defs = os.path.join(OS9, 'nitros9-code', 'defs') + '/'
    xrun = os.path.join(tmp, 'xrun')
    r = run([A09, '-I', defs, '-o', xrun, os.path.join(ROOT, 'os9', 'xrun.asm')], cwd=os.path.join(ROOT, 'os9'))
    if r.returncode != 0 or b'0 Pass 2 errors' not in r.stdout:
        check('assemble os9/xrun.asm', False, r.stdout.decode(errors='replace'))
        return
    sys.path.insert(0, os.path.join(ROOT, 'os9', 'sub'))
    import sumz80
    for cpu, binname in (('z80', 'sumz80.bin'), ('8088', 'sum8088.bin')):
        d = os.path.join(tmp, 'x_' + cpu)
        os.mkdir(d)
        for f in ('OS9.dsk', 'WORK.dsk'):
            shutil.copy(os.path.join(OS9, f), d)
        shutil.copytree(os.path.join(OS9, 'level2', 'cmds'), os.path.join(d, 'v0', 'cmds'))
        shutil.copy(xrun, os.path.join(d, 'v0', 'cmds', 'xrun'))
        if cpu == 'z80':
            open(os.path.join(d, 'v0', binname), 'wb').write(sumz80.image())
        else:
            r = run(['nasm', '-f', 'bin', os.path.join(ROOT, 'os9', 'sub', 'sum8088.asm'), '-o', os.path.join(d, 'v0', binname)])
            assert r.returncode == 0, r.stdout
        script = os.path.join(d, 'script.txt')
        open(script, 'w').write('timeout 30000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\n'
                                'send "xrun /v0/%s 100\\r"\nexpect "OS9:"\nsend "xrun /v0/%s 10\\r"\nexpect "OS9:"\nquit\n' % (binname, binname))
        cmd = [SIM, '-max', '-m', '1M', '-sub', cpu, '-rom', os.path.join(OS9, 'os9v2.rom'), '-0', os.path.join(d, 'OS9.dsk'),
               '-1', os.path.join(d, 'WORK.dsk'), '-v', os.path.join(d, 'v0'), '-script', script]
        r = run(cmd, timeout=120)
        out = r.stdout.decode(errors='replace')
        check('OS-9 Level 2: xrun loads and talks to the %s (100 -> 5050 = BA 13, then 10 -> 55 = 37 00)' % cpu,
              'reply: BA 13 00 00' in out and 'reply: 37 00 00 00' in out and
              out.index('reply: BA 13') < out.index('reply: 37 00'), out[-600:])


def build_cpm(tmp):
    """assemble the OS-9 commands cpm, xrun, reboot, etime, subsel, bdos, cpp80 and dos (tools/build_cpm.sh); returns the output directory"""
    out = os.path.join(tmp, 'cpmbuild')
    r = run([os.path.join(ROOT, 'tools', 'build_cpm.sh'), out])
    if r.returncode != 0 or r.stdout.count(b'0 Pass 2 errors') != 15:
        raise RuntimeError('build_cpm.sh failed: ' + r.stdout.decode(errors='replace'))
    return out


def z80_com(name, tmp):
    """assemble tests/cpm/<name>.asm with tools/z80asm.py -> bytes"""
    sys.path.insert(0, os.path.join(ROOT, 'tools'))
    import z80asm
    base, img = z80asm.assemble(open(os.path.join(HERE, 'cpm', name + '.asm'), encoding='utf-8').read())
    assert base == 0x100, hex(base)
    return img


def os9_session(tmp, tag, cpu, files, script_lines, timeout=180, driver=False, keep=(), d1=None):
    """boot OS-9 Level 2 with the sub CPU `cpu`, /v0 holds the cmds directory and `files`; run the script; return the output"""
    d = os.path.join(tmp, 'sess_' + tag)
    os.mkdir(d)
    for f in ('OS9.dsk', 'WORK.dsk'):
        shutil.copy(os.path.join(OS9, f), d)
    if d1:                                              # another disk image as /d1
        shutil.copy(d1, os.path.join(d, 'WORK.dsk'))
    shutil.copytree(os.path.join(OS9, 'level2', 'cmds'), os.path.join(d, 'v0', 'cmds'))
    for n in ('cpm', 'xrun', 'cpp80', 'xlink', 'x0', 'reboot', 'etime', 'bdos', 'duo', 'dos', 'subsel', 'kanjild', 'gfx'):
        if n in keep:                                   # keep the command of the OS-9 disk of new-sbc09 (the same name)
            continue
        shutil.copy(os.path.join(tmp, 'cpmbuild', n), os.path.join(d, 'v0', 'cmds', n))
    for n, data in files.items():
        open(os.path.join(d, 'v0', n), 'wb').write(data)
    script = os.path.join(d, 'script.txt')
    pre = 'send "load xlink\\r"\nexpect "OS9:"\nsend "load x0\\r"\nexpect "OS9:"\n' if driver else ''
    open(script, 'w').write('timeout 60000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\nsend "chd /v0\\r"\nexpect "OS9:"\n' + pre
                            + '\n'.join(script_lines) + '\nquit\n')
    cmd = [SIM, '-max'] + ([] if driver else ['-m', '1M']) + ['-sub', cpu, '-rom', os.path.join(OS9, 'os9v2.rom'), '-0', os.path.join(d, 'OS9.dsk'),
           '-1', os.path.join(d, 'WORK.dsk'), '-v', os.path.join(d, 'v0'), '-script', script]
    r = run(cmd, timeout=timeout)
    return r.stdout.decode(errors='replace'), d


def os9_cpmapps(tmp):
    """real CP/M programs, unchanged (not part of this project: set MATENRO_CPM to a directory with the Digital Research
    tools ASM.COM LOAD.COM PIP.COM STAT.COM ED.COM DDT.COM and MBASIC.COM)"""
    cp = os.environ.get('MATENRO_CPM')
    if not os.path.isdir(OS9):
        return
    if not cp or not os.path.isdir(cp):
        print('skip real CP/M programs (set MATENRO_CPM to the directory with ASM LOAD PIP STAT ED DDT MBASIC)')
        return
    files = {}
    for n in os.listdir(cp):
        if n.upper() in ('ASM.COM', 'LOAD.COM', 'PIP.COM', 'STAT.COM', 'ED.COM', 'DDT.COM', 'MBASIC.COM'):
            files[n.lower()] = open(os.path.join(cp, n), 'rb').read()
    files['hi.asm'] = (b'BDOS\tEQU\t5\n\tORG\t100H\n\tMVI\tC,9\n\tLXI\tD,MSG\n\tCALL\tBDOS\n\tRET\n'
                       b"MSG:\tDB\t'ASM AND LOAD WORK',13,10,'$'\n\tEND\n")
    out, d = os9_session(tmp, 'cpmapps', 'z80', files, [
        'send "cpm stat.com\\r"', 'expect "OS9:"',
        'send "cpm asm.com hi\\r"', 'expect "OS9:"', 'send "cpm load.com hi\\r"', 'expect "OS9:"', 'send "cpm hi.com\\r"', 'expect "OS9:"',
        'send "cpm pip.com copy.asm=hi.asm\\r"', 'expect "OS9:"', 'send "cpm pip.com con:=copy.asm\\r"', 'expect "OS9:"',
        'send "cpm stat.com *.asm\\r"', 'expect "OS9:"',
        'send "cpm ed.com ednew.txt\\r"', 'expect "*"', 'send "I\\r"', 'sleep 500000', 'send "Hello from ED\\r\\x1a"', 'sleep 500000',
        'send "E\\r"', 'expect "OS9:"', 'send "list ednew.txt\\r"', 'expect "OS9:"',
        'send "cpm ddt.com hi.com\\r"', 'expect "-"', 'send "L100\\r"', 'sleep 800000', 'send "G0\\r"', 'expect "OS9:"',
        'send "cpm mbasic.com\\r"', 'expect "Ok"', 'send "PRINT 2+3\\r"', 'expect "Ok"',
        'send "10 FOR I=1 TO 3: PRINT I*I: NEXT I\\r"', 'sleep 800000', 'send "RUN\\r"', 'expect "Ok"',
        'send "SAVE \\"T1.BAS\\"\\r"', 'expect "Ok"', 'send "NEW\\r"', 'expect "Ok"', 'send "LOAD \\"T1.BAS\\"\\r"', 'expect "Ok"',
        'send "LIST\\r"', 'expect "Ok"', 'send "SYSTEM\\r"', 'expect "OS9:"'], timeout=400)
    check('CP/M tools of Digital Research, unchanged: STAT (drive and free space), ASM + LOAD (an assembler source becomes a program that runs)',
          'Space:' in out and 'ASM AND LOAD WORK' in out and 'END OF ASSEMBLY' in out and 'BYTES READ' in out, out[-1000:])
    check('CP/M tools: PIP (copy a file, to the console), STAT with a pattern, ED (a new file is written and listed)',
          'ASM AND LOAD WORK' in out and "COPY.ASM" in out and 'HELLO FROM ED' in out, out[-1000:])
    check('CP/M tools: DDT (loads a program, lists it as 8080 code), MBASIC (calculates, runs a program, SAVE / LOAD of the tokenized form)',
          'DDT VERS 2.2' in out and 'MVI  C,09' in out and 'BASIC-80 Rev. 5.21' in out and ' 5 ' in out
          and ' 9 ' in out and out.count('10 FOR I=1 TO 3: PRINT I*I: NEXT I') >= 2, out[-1000:])


def os9_drive(tmp):
    """drives and user areas of cpm: B: is a directory (cpm -m=B:dir), C: is not mapped, BDOS 14 / 24 / 25 / 32, files in U3"""
    if not os.path.isdir(OS9):
        return
    out, d = os9_session(tmp, 'drive', 'z80', {'drive.com': z80_com('drive', tmp), 'attr.com': z80_com('attr', tmp), 'alloc.com': z80_com('alloc', tmp)}, [
        'send "chd /d1\\r"', 'expect "OS9:"', 'send "makdir /d1/drvb\\r"', 'expect "OS9:"',
        'send "cpm -p=/v0 -m=B:/d1/drvb drive.com\\r"', 'expect "OS9:"', 'send "dir /d1\\r"', 'expect "OS9:"',
        'send "dir /d1/drvb\\r"', 'expect "OS9:"', 'send "cpm -p=/v0 attr.com\\r"', 'expect "OS9:"', 'send "cpm -p=/v0 alloc.com\\r"', 'expect "OS9:"'])
    check('cpm: BDOS 31 (the parameter block of a 4 MB disk) and 27 (the allocation vector: a file of 5120 bytes takes 3 blocks)', 'ALLOC OK' in out, out[-800:])
    check('cpm: BDOS 30 (read only attribute, shown by BDOS 17 as the high bit of the type), BDOS 3 7 8', 'ATTR OK' in out, out[-800:])
    check('cpm: drives (-m=B:dir, BDOS 14 24 25: A and B, C is not mapped), user areas (BDOS 32: the subdirectory U3), files by drive and user',
          'DRIVE OK' in out, out[-800:])


def os9_bdos(tmp):
    """the subroutine module bdos: an OS-9 program (tests/bdos/bdostest.asm) calls the CP/M BDOS by function number (console,
    FCB files: make, write, close, rename, open, read, delete); the FCB and the data are in the memory of the program"""
    if not os.path.isdir(OS9):
        return
    out_bin = os.path.join(tmp, 'cpmbuild', 'bdostest')
    out, d = os9_session(tmp, 'bdos', 'z80', {'cmds/bdostest': open(out_bin, 'rb').read()}, [
        'send "load bdos\\r"', 'expect "OS9:"', 'send "bdostest\\r"', 'expect "OS9:"', 'send "dir /v0\\r"', 'expect "OS9:"'])
    after = out.split('dir /v0')[-1]
    check('bdos module: an OS-9 program calls the BDOS (console, make, write, close, rename, open, read, delete with FCBs in its own memory)',
          'BDOS LIB OK' in out and 'BDOS lib: BDOS 9' in out and 'BT.TMP' not in after.upper() and 'BU.TMP' not in after.upper(), out[-700:])


def os9_etime(tmp):
    """the OS-9 command etime: the time of a command from the microsecond counter of the cross link (XE_US), with -c the sub CPU clocks"""
    if not os.path.isdir(OS9):
        return
    out, d = os9_session(tmp, 'etime', 'z80', {'hello.com': z80_com('hello', tmp), 'bstress.com': z80_com('bstress', tmp)}, [
        'send "etime\\r"', 'expect "OS9:"',
        'send "etime -c cpm hello.com abc\\r"', 'expect "OS9:"',
        'send "etime nosuchcommand\\r"', 'expect "OS9:"',
        'send "etime cpm bstress.com\\r"', 'expect "OS9:"'])
    import re
    m = re.findall(r'Elapsed +(\d+)\.(\d{6}) s', out)
    c = re.search(r'Sub CPU (\d+) clocks \((\d+) ms at (\d+) kHz\)', out)
    check('etime: usage, the elapsed time of a command (seconds and microseconds), -c: Z80 clocks, milliseconds and kHz; a missing command is an error',
          'usage: etime' in out and len(m) == 2 and c is not None and int(c.group(1)) > 1000 and int(c.group(3)) == 8000
          and abs(int(c.group(1)) // int(c.group(3)) - int(c.group(2))) <= 1 and 'Error #216' in out and out.count('Error #216') == 1 and 'Hello from CP/M-80' in out, out[-900:])
    # the 3000 rounds of bstress take a measurable time (more than a tenth of a second of the machine)
    check('etime: a longer command (bstress.com, 3000 rounds) takes a measurable time',
          len(m) == 2 and (int(m[1][0]) * 1000000 + int(m[1][1])) > 100000, out[-500:])


def duo_ref():
    """the 25 rows of the picture of `duo`, in the Q8 fixed point arithmetic of os9/duo (Python integers)"""
    def mulq(p, q):
        neg = (p < 0) != (q < 0)
        r = (abs(p) * abs(q)) >> 8
        return -r if neg else r
    rows = []
    for y in range(-12, 13):
        cb = y * 21
        line = ''
        for x in range(-39, 40):
            ca = x * 12
            a, b = ca, cb
            a2, b2 = mulq(a, a), mulq(b, b)
            i = 0
            while i < 16:
                t = a2 - b2 + ca
                b = 2 * mulq(a, b) + cb
                a = t
                a2, b2 = mulq(a, a), mulq(b, b)
                if a2 + b2 >= 1025:
                    break
                i += 1
            line += '0123456789ABCDEF '[i]
        rows.append(line)
    return rows


def os9_duo(tmp):
    """the OS-9 command duo: a Mandelbrot picture computed by the 6809 and the Z80 together; same picture whoever computes a row"""
    if not os.path.isdir(OS9):
        return
    out, d = os9_session(tmp, 'duo', 'z80', {}, [
        'send "duo -n\r"', 'expect "OS9:"',
        'send "duo -1 -n\r"', 'expect "OS9:"',
        'send "duo -z -n\r"', 'expect "OS9:"',
        'send "duo -q\r"', 'expect "OS9:"'])
    import re
    ref = duo_ref()
    pics = out.split('\n')
    runs = re.findall(r'6809: (\d+) rows +Z80: (\d+) rows +(\d+)\.(\d{3}) s', out)
    found = [ln.rstrip('\r') for ln in pics if len(ln.rstrip('\r')) == 79 and set(ln.rstrip('\r')) <= set('0123456789ABCDEF ')]
    same = len(found) == 75 and all(found[k * 25:(k + 1) * 25] == ref for k in range(3))
    check('duo: the picture of both CPUs, of the 6809 only and of the Z80 only is the same as the reference in fixed point arithmetic',
          same, out[-1500:])
    check('duo: the rows are shared (6809 + Z80 = 25 rows, both work), -1: 25 rows by the 6809, -z: 25 rows by the Z80; usage for a bad option',
          len(runs) == 3 and [int(r[0]) + int(r[1]) for r in runs] == [25, 25, 25] and int(runs[0][0]) > 0 and int(runs[0][1]) > 0
          and runs[1][:2] == ('25', '0') and runs[2][:2] == ('0', '25') and 'usage: duo' in out, str(runs))
    # with the xlink driver (/x0): the memory comes from OS-9, the doorbell of the Z80 interrupts the 6809 (the IRQ polling table, the
    # Clock module calls it) and the doorbell of the 6809 interrupts the Z80
    out, d = os9_session(tmp, 'duoirq', 'z80', {}, ['send "duo -z -n -i\\r"', 'expect "OS9:"'], driver=True)
    pics = [ln.rstrip('\r') for ln in out.split('\n')]
    found = [ln for ln in pics if len(ln) == 79 and set(ln) <= set('0123456789ABCDEF ')]
    m = re.search(r'6809: (\d+) rows +Z80: (\d+) rows', out)
    n = re.search(r'doorbell interrupts: (\d+)', out)
    check('duo with the xlink driver: the same picture, the Z80 does the 25 rows, the 6809 sleeps in the driver and the doorbell interrupts wake it (one per row)',
          found == ref and m is not None and m.groups() == ('0', '25') and n is not None and int(n.group(1)) >= 25, out[-600:])


def os9_dos(tmp):
    """MS-DOS 1.25 on the 8088 (the OS-9 command dos): the kernel and COMMAND are assembled from the source that Microsoft published
    (not part of this project: set MATENRO_DOS_SRC to .../MS-DOS/v1.25/source, and UASM to a MASM compatible assembler)"""
    src = os.environ.get('MATENRO_DOS_SRC')
    uasm = os.environ.get('UASM')
    if not os.path.isdir(OS9):
        return
    if not src or not os.path.isdir(src) or not uasm:
        print('skip MS-DOS (set MATENRO_DOS_SRC to the MS-DOS 1.25 source and UASM to the assembler)')
        return
    bd = os.path.join(tmp, 'dosbin')
    r = run(['env', 'MSDOS_SRC=' + src, 'UASM=' + uasm, 'sh', os.path.join(ROOT, 'tools', 'build_dosbin.sh'), bd])
    check('MS-DOS: the kernel and COMMAND assemble from the published source', r.returncode == 0, r.stdout.decode(errors='replace')[-800:])
    if r.returncode != 0:
        return
    hello = b'Hello from a file on the DOS disk.\r\nSecond line.\r\n'
    hp = os.path.join(tmp, 'hello.txt')
    open(hp, 'wb').write(hello)
    img = os.path.join(tmp, 'a.img')
    # the programs of the published binaries (DEBUG and EDLIN of PC DOS 1.x, ../bin of the source), if they are there
    binp = [os.path.join(os.path.dirname(os.path.normpath(src)), 'bin', n) for n in ('DEBUG.COM', 'EDLIN.COM')]
    binp = binp if all(os.path.isfile(b) for b in binp) else []
    r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'mkdosimg.py'), img, '160', os.path.join(bd, 'command.com'), hp] + binp)
    assert r.returncode == 0, r.stdout
    files = {'msdos.sys': open(os.path.join(bd, 'msdos.sys'), 'rb').read(), 'a.img': open(img, 'rb').read(), 'auxin.txt': b'Aux input.\r\n'}
    n0 = 2 + len(binp)
    script = ['send "dos -a=a.img -p=prn.txt -o=auxout.txt -i=auxin.txt\\r"', 'expect "Enter new date:"', 'send "\\r"', 'expect "Enter new time:"', 'send "\\r"', 'expect "A:"',
              'send "dir\\r"', 'expect "%d File(s)"' % n0, 'send "type hello.txt\\r"', 'expect "Second line."',
              'send "copy hello.txt copy.txt\\r"', 'expect "1 File(s) copied"', 'send "dir\\r"', 'expect "%d File(s)"' % (n0 + 1),
              'send "type copy.txt\\r"', 'expect "Second line."', 'send "del copy.txt\\r"', 'sleep 1500000', 'send "dir\\r"', 'expect "%d File(s)"' % n0,
              'send "date\\r"', 'expect "Enter new date:"', 'send "12-25-2026\\r"', 'expect "A:"',
              'send "date\\r"', 'expect "Fri 12-25-2026"', 'expect "Enter new date:"', 'send "\\r"', 'expect "A:"',
              'send "time\\r"', 'expect "Enter new time:"', 'send "10:20:30\\r"', 'expect "A:"',
              'send "time\\r"', 'expect "Current time is 10:20:"', 'expect "Enter new time:"', 'send "\\r"', 'expect "A:"',
              'send "copy hello.txt prn\\r"', 'expect "1 File(s) copied"', 'send "copy hello.txt aux\\r"', 'expect "1 File(s) copied"',
              'send "copy aux fromaux.txt\\r"', 'expect "1 File(s) copied"', 'send "type fromaux.txt\\r"', 'expect "Aux input."', 'expect "A:"']
    if binp:
        script += ['send "edlin edtest.txt\\r"', 'expect "New file"', 'send "i\\r"', 'expect "1:*"', 'send "hello edlin\\r"', 'expect "2:*"',
                   'send "\\x1a\\r"', 'expect "*"', 'send "e\\r"', 'expect "A:"', 'send "type edtest.txt\\r"', 'expect "A:"',
                   'send "debug\\r"', 'expect "-"', 'send "d 100 10f\\r"', 'expect ":0100  "', 'expect "-"', 'send "q\\r"', 'expect "A:"']
    script += ['send "\\x1d"', 'expect "OS9:"']
    for tag, drv in (('dos', False), ('dosdrv', True)):
        out, d = os9_session(tmp, tag, '8088', files, script, driver=drv, timeout=500)
        out = out.replace('\r', '')
        why = ' (with the xlink driver)' if drv else ''
        check('MS-DOS 1.25 boots%s: banner, COMMAND, the clock of OS-9 (day count and time)' % why,
              'MS-DOS version 1.25' in out and 'Command v. 1.17H' in out and 'Current date is' in out and 'Current time is' in out, out[-900:])
        check('MS-DOS%s: DIR lists the files of the disk image, TYPE reads one' % why,
              'COMMAND  COM' in out and 'HELLO    TXT' in out and '%d File(s)' % n0 in out and 'Hello from a file on the DOS disk.' in out, out[-900:])
        check('MS-DOS%s: COPY writes the image (the new file is listed and can be typed), DEL removes it' % why,
              '%d File(s)' % (n0 + 1) in out and out.count('Second line.') == 2 and out.count('%d File(s)' % n0) == 2, out[-900:])
        check('MS-DOS%s: DATE and TIME set the clock of DOS (an offset to the clock of OS-9)' % why,
              'Current date is Fri 12-25-2026' in out and 'Current time is 10:20:' in out, out[-900:])
        check('MS-DOS%s: the aux input and the output of the printer and the aux port' % why, 'Aux input.' in out, out[-900:])
        if binp:
            check('MS-DOS%s: EDLIN writes a file (TYPE reads it), DEBUG dumps memory (it asks the video mode: INT 10h of the BIOS)' % why,
                  out.count('hello edlin') >= 2 and ':0100  ' in out, out[-900:])
        check('MS-DOS%s: ^] leaves DOS and the terminal is back (the next OS-9 prompt)' % why, out.rstrip().endswith('OS9:'), out[-300:])
        if not drv:
            pr = open(os.path.join(d, 'v0', 'prn.txt'), 'rb').read()
            ax = open(os.path.join(d, 'v0', 'auxout.txt'), 'rb').read()
            check('MS-DOS: the printer (-p=) and the aux output (-o=) are files of the host', pr.startswith(hello) and ax.startswith(hello), repr(pr) + repr(ax))
            back = open(os.path.join(d, 'v0', 'a.img'), 'rb').read()
            check('MS-DOS: the disk image file of the host holds the changes (COPY wrote, DEL freed the entry: marked as deleted, or used again by EDLIN)',
                  back != files['a.img'] and b'COPY    TXT' not in back and (b'EDTEST  TXT' if binp else b'\xe5OPY    TXT') in back, '')


def os9_dos2(tmp):
    """MS-DOS 2.0 on the 8088 (dos -v=2): our BIOS with SYSINIT of Microsoft (assembled with UASM from the source that Microsoft
    published), the kernel and COMMAND as Microsoft published them (not part of this project: set MATENRO_DOS2_SRC to
    .../MS-DOS/v2.0/source, and UASM to a MASM compatible assembler)"""
    src = os.environ.get('MATENRO_DOS2_SRC')
    uasm = os.environ.get('UASM')
    if not os.path.isdir(OS9):
        return
    if not src or not os.path.isdir(src) or not uasm:
        print('skip MS-DOS 2.0 (set MATENRO_DOS2_SRC to the MS-DOS 2.0 source and UASM to the assembler)')
        return
    bd = os.path.join(tmp, 'dos2bin')
    r = run(['env', 'MSDOS2_SRC=' + src, 'UASM=' + uasm, 'sh', os.path.join(ROOT, 'tools', 'build_dosbin2.sh'), bd])
    check('MS-DOS 2.0: the BIOS with SYSINIT assembles from the published source', r.returncode == 0, r.stdout.decode(errors='replace')[-800:])
    if r.returncode != 0:
        return
    hello = b'Hello from a file on the DOS 2.0 disk.\r\nSecond line.\r\n'
    hp = os.path.join(tmp, 'hello2.txt')
    open(hp, 'wb').write(hello)
    binp = [os.path.join(os.path.dirname(os.path.normpath(src)), 'bin', n) for n in ('DEBUG.COM', 'EDLIN.COM')]
    img = os.path.join(tmp, 'a2.img')
    r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'mkdosimg.py'), img, '320', os.path.join(bd, 'command.com'),
             os.path.join(os.path.dirname(hp), 'hello2.txt')] + binp)
    assert r.returncode == 0, r.stdout
    files = {'msdos.sys': open(os.path.join(bd, 'msdos.sys'), 'rb').read(), 'bios2.bin': open(os.path.join(bd, 'bios2.bin'), 'rb').read(),
             'a.img': open(img, 'rb').read(), 'auxin.txt': b'Aux input.\r\n'}
    script = ['send "dos -v=2 -a=a.img -p=prn.txt -o=auxout.txt -i=auxin.txt\\r"', 'expect "Enter new date:"', 'send "12-25-2026\\r"',
              'expect "Enter new time:"', 'send "10:20:30\\r"', 'expect "A>"',
              'send "dir\\r"', 'expect "4 File(s)"', 'send "type hello2.txt\\r"', 'expect "Second line."',
              'send "copy hello2.txt copy.txt\\r"', 'expect "1 File(s) copied"',
              'send "mkdir sub\\r"', 'expect "A>"', 'send "cd sub\\r"', 'expect "A>"', 'send "copy ..\\\\hello2.txt x.txt\\r"', 'expect "1 File(s) copied"',
              'send "dir\\r"', 'expect "X        TXT"', 'send "cd ..\\r"', 'expect "A>"', 'send "dir\\r"', 'expect "<DIR>"',
              'send "date\\r"', 'expect "Current date is Fri 12-25-2026"', 'expect "Enter new date:"', 'send "\\r"', 'expect "A>"',
              'send "time\\r"', 'expect "Current time is 10:2"', 'expect "Enter new time:"', 'send "\\r"', 'expect "A>"',
              'send "copy hello2.txt prn\\r"', 'expect "1 File(s) copied"', 'send "copy hello2.txt aux\\r"', 'expect "1 File(s) copied"',
              'send "copy aux fromaux.txt\\r"', 'expect "1 File(s) copied"', 'send "type fromaux.txt\\r"', 'expect "Aux input."',
              'send "edlin edtest.txt\\r"', 'expect "New file"', 'send "i\\r"', 'expect "1:*"', 'send "hello edlin\\r"', 'expect "2:*"',
              'send "\\x1a\\r"', 'expect "*"', 'send "e\\r"', 'expect "A>"', 'send "type edtest.txt\\r"', 'expect "hello edlin"',
              'send "debug\\r"', 'expect "-"', 'send "d 100 10f\\r"', 'expect ":0100  "', 'expect "-"', 'send "q\\r"', 'expect "A>"',
              'send "\\x1d"', 'expect "OS9:"']
    for tag, drv in (('dos2', False), ('dos2drv', True)):
        out, d = os9_session(tmp, tag, '8088', files, script, driver=drv, timeout=600)
        out = out.replace('\r', '')
        why = ' (with the xlink driver)' if drv else ''
        check('MS-DOS 2.0 boots%s: SYSINIT, COMMAND, the date and time that were typed' % why,
              'MS-DOS version 2.00' in out and 'Command v. 2.02' in out and 'A>dir' in out, out[-900:])
        check('MS-DOS 2.0%s: DIR, TYPE, COPY, MKDIR, CD and a file in the subdirectory' % why,
              'HELLO2   TXT' in out and out.count('Second line.') == 1 and 'SUB          <DIR>' in out and 'X        TXT' in out, out[-1200:])
        check('MS-DOS 2.0%s: DATE and TIME set the clock of DOS' % why, 'Current date is Fri 12-25-2026' in out and 'Current time is 10:2' in out, out[-900:])
        check('MS-DOS 2.0%s: the printer, the aux input and output' % why, 'Aux input.' in out, out[-900:])
        check('MS-DOS 2.0%s: EDLIN writes a file, DEBUG dumps memory' % why, out.count('hello edlin') >= 2 and ':0100  ' in out, out[-900:])
        check('MS-DOS 2.0%s: ^] leaves DOS and the terminal is back' % why, out.rstrip().endswith('OS9:'), out[-300:])
        if not drv:
            pr = open(os.path.join(d, 'v0', 'prn.txt'), 'rb').read()
            ax = open(os.path.join(d, 'v0', 'auxout.txt'), 'rb').read()
            back = open(os.path.join(d, 'v0', 'a.img'), 'rb').read()
            check('MS-DOS 2.0: the printer and aux output files and the disk image of the host hold the changes',
                  pr.startswith(hello) and ax.startswith(hello) and back != files['a.img'] and b'COPY    TXT' in back, repr(pr) + repr(ax))

    # the other disk formats of 2.0: 360 KB (9 sectors per track) with a CONFIG.SYS (SYSINIT reads it: FILES= is known, BOGUS= is
    # reported), and the 8 MB hard disk image
    cfg = os.path.join(tmp, 'CONFIG.SYS')
    open(cfg, 'wb').write(b'FILES=20\r\nDEVICE=MYDRV.SYS\r\nBOGUS=1\r\n')
    drv = os.path.join(tmp, 'mydrv.sys')
    r = run(['nasm', '-f', 'bin', os.path.join(ROOT, 'tests', 'dos', 'mydrv.asm'), '-o', drv])
    assert r.returncode == 0, r.stdout
    for tag, fmt, extra in (('dos2f360', '360', [cfg, drv]), ('dos2f8m', '8192', [])):
        im = os.path.join(tmp, tag + '.img')
        r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'mkdosimg.py'), im, fmt, os.path.join(bd, 'command.com'), hp] + extra)
        assert r.returncode == 0, r.stdout
        fl = {'msdos.sys': files['msdos.sys'], 'bios2.bin': files['bios2.bin'], 'a.img': open(im, 'rb').read()}
        sc = ['send "dos -v=2 -a=a.img\\r"', 'expect "Enter new date:"', 'send "\\r"', 'expect "Enter new time:"', 'send "\\r"', 'expect "A>"',
              'send "copy hello2.txt copy.txt\\r"', 'expect "1 File(s) copied"', 'send "dir\\r"', 'expect "bytes free"',
              'send "type copy.txt\\r"', 'expect "Second line."']
        if fmt == '360':
            sc += ['send "copy hello2.txt mydev\\r"', 'expect "1 File(s) copied"']
        sc += ['send "\\x1d"', 'expect "OS9:"']
        out, d = os9_session(tmp, tag, '8088', fl, sc, timeout=400)
        out = out.replace('\r', '')
        what = '360 KB disk with a CONFIG.SYS (FILES=, DEVICE=MYDRV.SYS: a device driver that is loaded and written to, BOGUS= reported)' if fmt == '360' else '8 MB hard disk image'
        ok = 'HELLO2   TXT' in out and 'COPY     TXT' in out and out.count('Second line.') == 1 and out.rstrip().endswith('OS9:')
        if fmt == '360':
            ok = ok and 'Unrecognized command in CONFIG.SYS' in out and 'MYDRV loaded' in out and out.count('1 File(s) copied') == 2
        check('MS-DOS 2.0: boot from a %s, DIR, COPY, TYPE' % what, ok, out[-900:])

    # run mode: `dos program arguments` boots DOS from a copy of dosrun2.img, HOSTIN copies the files of the OS-9 directory to the
    # disk, the command runs (here the COPY of COMMAND), HOSTOUT copies the files back
    host = os.path.join(tmp, 'host')
    os.mkdir(host)
    for n in ('hostin', 'hostout'):
        r = run(['nasm', '-f', 'bin', '-I', os.path.join(ROOT, 'os9', 'dos', 'host') + os.sep, os.path.join(ROOT, 'os9', 'dos', 'host', n + '.asm'),
                '-o', os.path.join(host, n + '.com')])
        check('MS-DOS 2.0 run mode: %s.com assembles' % n.upper(), r.returncode == 0, r.stdout.decode(errors='replace')[-300:])
        if r.returncode != 0:
            return
    im = os.path.join(tmp, 'dosrun2.img')
    r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'mkdosimg.py'), im, '360', os.path.join(bd, 'command.com'),
             os.path.join(host, 'hostin.com'), os.path.join(host, 'hostout.com')])
    assert r.returncode == 0, r.stdout
    data = bytes((i * 7 + (i >> 8)) & 0xFF for i in range(3000)) + b'\x1a' + bytes(range(256))
    fl = {'msdos.sys': files['msdos.sys'], 'bios2.bin': files['bios2.bin'], 'dosrun2.img': open(im, 'rb').read(),
          'in.txt': hello, 'in.dat': data}
    sc = ['send "dos -v=2 -a=dosrun2.img copy in.txt out.txt\\r"', 'expect "OS9:"',
          'send "dos -v=2 -a=dosrun2.img copy in.dat out.dat\\r"', 'expect "OS9:"', 'send "dir\\r"', 'expect "OS9:"']
    out, d = os9_session(tmp, 'dos2run', '8088', fl, sc, timeout=600)
    out = out.replace('\r', '')
    v0 = os.path.join(d, 'v0')
    o1 = open(os.path.join(v0, 'out.txt'), 'rb').read() if os.path.isfile(os.path.join(v0, 'out.txt')) else b''
    o2 = open(os.path.join(v0, 'out.dat'), 'rb').read() if os.path.isfile(os.path.join(v0, 'out.dat')) else b''
    check('MS-DOS 2.0 run mode: dos copy in.txt out.txt - the new file is in the OS-9 directory, equal to the original', o1 == hello, repr(o1) + out[-600:])
    check('MS-DOS 2.0 run mode: a binary file (3257 bytes, with ^Z and every byte value) comes back byte for byte', o2 == data, out[-600:])
    check('MS-DOS 2.0 run mode: the work image is gone, the files of the program are not copied back (COMMAND.COM, HOSTIN.COM, RUNJOB.BAT)',
          not os.path.exists(os.path.join(v0, 'dostmp.img')) and not any(os.path.exists(os.path.join(v0, n)) for n in ('command.com', 'runjob.bat', 'COMMAND.COM')), '')
    check('MS-DOS 2.0 run mode: DOS leaves by itself (the OS-9 prompt is back each time)', out.count('OS9:dos') == 2 and out.rstrip().endswith('OS9:'), out[-600:])

    # the text screen of the PC (dos -w=2: the BIOS's INT 10h and the console on the text memory B800h, without the HDMI registers): tests/dos/pctest.asm
    # checks the memory and the functions 00, 02, 03, 06, 07, 08, 09, 0Eh and the console of DOS, and writes PASS into PCRES.TXT
    pct = os.path.join(tmp, 'pctest.com')
    r = run(['nasm', '-f', 'bin', os.path.join(ROOT, 'tests', 'dos', 'pctest.asm'), '-o', pct])
    check('MS-DOS 2.0 text screen of the PC: pctest.com assembles', r.returncode == 0, r.stdout.decode(errors='replace')[-300:])
    if r.returncode == 0:
        fl2 = dict(fl)
        fl2['pctest.com'] = open(pct, 'rb').read()
        sc = ['send "dos -v=2 -a=dosrun2.img -w=2 pctest\\r"', 'expect "OS9:"', 'send "dos -v=2 -a=dosrun2.img -w=1 pctest\\r"', 'expect "OS9:"']
        out, d = os9_session(tmp, 'dos2pc', '8088', fl2, sc, timeout=600)
        out = out.replace('\r', '')
        res = os.path.join(d, 'v0', 'PCRES.TXT')
        res = res if os.path.isfile(res) else os.path.join(d, 'v0', 'pcres.txt')
        got = open(res, 'rb').read() if os.path.isfile(res) else b''
        check('MS-DOS 2.0 text screen of the PC: the memory at B800h, INT 10h 00 02 03 06 07 08 09 0E and the console of DOS (dos -w=2): PASS', got == b'PASS\r\n', repr(got) + out[-500:])
        check('MS-DOS 2.0 text screen of the PC: -w=1 without the HDMI registers says so and does not start', 'no text screen of the PC' in out, out[-500:])


def os9_subsel(tmp):
    """the OS-9 command subsel (register $FFCF): Z80 and 8088 chosen while OS-9 runs"""
    if not os.path.isdir(OS9):
        return

    # subsel: the Z80 and the 8088 are chosen while OS-9 runs (the register $FFCF; the FPGA of the Tang Nano 20K has both cores)
    z80com = os.path.join(tmp, 'ss_hello.com')
    r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'z80asm.py'), os.path.join(ROOT, 'tests', 'cpm', 'hello.asm'), '-o', z80com])
    assert r.returncode == 0, r.stdout
    h86 = os.path.join(tmp, 'ss_h86.bin')
    r = run(['nasm', '-f', 'bin', os.path.join(ROOT, 'tests', 'cpm', 'hello86.asm'), '-o', h86])
    assert r.returncode == 0, r.stdout
    cmd86 = os.path.join(tmp, 'ss_hello86.cmd')
    r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'mkcmd.py'), '8080', h86, cmd86])
    assert r.returncode == 0, r.stdout
    sc = ['send "subsel\\r"', 'expect "OS9:"', 'send "cpm hello86.cmd abc\\r"', 'expect "OS9:"',
          'send "subsel z80\\r"', 'expect "OS9:"', 'send "cpm hello.com abc\\r"', 'expect "OS9:"',
          'send "cpm hello86.cmd abc\\r"', 'expect "OS9:"', 'send "subsel 8088\\r"', 'expect "OS9:"',
          'send "cpm hello86.cmd xyz\\r"', 'expect "OS9:"', 'send "subsel q\\r"', 'expect "OS9:"']
    out, d = os9_session(tmp, 'subsel', '8088', {'hello.com': open(z80com, 'rb').read(), 'hello86.cmd': open(cmd86, 'rb').read()}, sc, timeout=400)
    out = out.replace('\r', '')
    check('subsel: the sub CPU is shown (8088), changed to the Z80 and back (the register SUBSEL, XID follows)', 'subsel: 8088' in out and 'subsel: Z80' in out and out.count('subsel: 8088') == 2, out[-700:])
    check('subsel: cpm runs CP/M-86 on the 8088, CP/M-80 on the Z80, and says so when a .CMD program meets the Z80',
          out.count('Hello from CP/M-86 on the 8088') == 2 and 'Hello from CP/M-80 on the Z80' in out and 'sub CPU is the Z80 (subsel 8088)' in out, out[-900:])
    check('subsel: a wrong argument is refused', 'usage: subsel' in out, out[-300:])


def os9_bigdisk(tmp):
    """/d1 as a hard disk (tools/mkrbf.py): an empty RBF volume of 24576 sectors (the allocation map fills 12 sectors, the
    old limit of tools/growdisk.py was 2048 sectors); 1 MB files beyond the first map sector, read back, deleted, the free
    sectors come back.  (A big file as the very first allocation after the mount fails once with Media Full (error 248) and the
    next one works - on the original volume of sim09 as well, so it is not a matter of the volume: a small file goes first.)"""
    if not os.path.isdir(OS9):
        return
    big = os.path.join(tmp, 'big.dsk')
    r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'mkrbf.py'), big, '24576', '1', 'd1'])
    assert r.returncode == 0, r.stdout
    out, d = os9_session(tmp, 'bigdisk', 'z80', {}, [
        'send "free /d1\\r"', 'expect "OS9:"', 'send "makdir /d1/sub\\r"', 'expect "OS9:"',
        'send "copy /d0/OS9Boot /d1/sub/small\\r"', 'expect "OS9:"',      # a small file first: see below
        'send "copy /d0@ /d1/sub/big1\\r"', 'expect "OS9:"', 'send "copy /d0@ /d1/big2\\r"', 'expect "OS9:"',
        'send "copy /d0@ /d1/big3\\r"', 'expect "OS9:"', 'send "free /d1\\r"', 'expect "OS9:"',
        'send "cmp /d0@ /d1/big3\\r"', 'expect "OS9:"', 'send "cmp /d0@ /d1/sub/big1\\r"', 'expect "OS9:"',
        'send "echo CMPEND\\r"', 'expect "CMPEND"', 'send "cmp /d0@ /d1/sub/small\\r"', 'expect "OS9:"',      # the control: they differ
        'send "attr /d1/sub/big1 w r\\r"', 'expect "OS9:"', 'send "attr /d1/big2 w r\\r"', 'expect "OS9:"',
        'send "attr /d1/big3 w r\\r"', 'expect "OS9:"',
        'send "del /d1/sub/small\\r"', 'expect "OS9:"', 'send "del /d1/sub/big1\\r"', 'expect "OS9:"', 'send "del /d1/big2\\r"', 'expect "OS9:"', 'send "del /d1/big3\\r"', 'expect "OS9:"',
        'send "free /d1\\r"', 'expect "OS9:"', 'send "echo FIN\\r"', 'expect "FIN"'], timeout=900, d1=big)
    out = out.replace('\r', '')
    import re
    free = [int(x.replace(',', '')) for x in re.findall(r'([0-9,]+) free sectors', out)]
    same = out.split('echo CMPEND')[0].count('Differences')          # cmp is silent when the files are equal
    ctrl = out.split('echo CMPEND')[-1].count('Differences')        # and shows a table when they differ
    check('OS-9: /d1 as a hard disk of 12 map sectors (mkrbf.py): big files past the first map sector, equal when read back, free sectors come back',
          len(free) == 3 and free[0] > 24000 and free[1] < free[0] - 4000 and free[2] == free[0] - 9 and same == 0 and ctrl == 1, out[-900:])


def os9_reboot(tmp):
    """the OS-9 command reboot: $A7 in the power register, the machine starts again (RAM cleared, ROM image loaded), disks stay"""
    if not os.path.isdir(OS9):
        return
    out, d = os9_session(tmp, 'reboot', 'z80', {}, [
        'send "chx /d0/cmds\\r"', 'expect "OS9:"', 'send "build /d1/mark\\r"', 'expect "?"', 'send "hello\\r"', 'expect "?"', 'send "\\r"', 'expect "OS9:"',
        'send "chx /v0/cmds\\r"', 'expect "OS9:"', 'send "reboot\\r"', 'expect "Rebooting"', 'expect "OS9:"',
        'send "chx /v0/cmds\\r"', 'expect "OS9:"', 'send "dir /d1\\r"', 'expect "OS9:"', 'send "list /d1/mark\\r"', 'expect "OS9:"',
        'send "echo REBOOTED\\r"', 'expect "OS9:"'])
    after = out.split('Rebooting')[-1]
    check('OS-9 reboot: the machine starts again (the banner twice), the disk files are still there, the shell works',
          out.count('NitrOS-9/6809 Level 2') == 2 and 'mark' in after and 'hello' in after and 'REBOOTED' in after, out[-900:])
    # the reboot command of the OS-9 disk of new-sbc09 (it writes $A6 to the power register, ours writes $A7): the same restart
    out, d = os9_session(tmp, 'reboot6', 'z80', {}, [
        'send "reboot\\r"', 'expect "Rebooting"', 'expect "OS9:"',
        'send "echo REBOOTED6\\r"', 'expect "OS9:"'], keep=('reboot',))
    check('OS-9 reboot with the command of new-sbc09 ($A6): the machine starts again, the shell works',
          out.count('NitrOS-9/6809 Level 2') == 2 and 'REBOOTED6' in out, out[-600:])


def os9_cpm80(tmp):
    """CP/M-80 programs on the Z80, started from OS-9 with the command cpm"""
    if not os.path.isdir(OS9):
        return
    files = {n + '.com': z80_com(n, tmp) for n in ('hello', 'fileio', 'line', 'stk6', 'share', 'kbpoll', 'bios', 'ren', 'wild')}
    out, d = os9_session(tmp, 'cpm80', 'z80', files, [
        'send "cpm hello.com abc def\\r"', 'expect "OS9:"',
        'send "cpm fileio.com\\r"', 'expect "OS9:"',
        'send "cpm line.com\\r"', 'expect "Name? "', 'send "xyz\\r"', 'expect "]"', 'send "q"', 'expect "OS9:"',
        'send "cpm stk6.com\\r"', 'expect "OS9:"', 'send "cpm stk6.com\\r"', 'expect "OS9:"', 'send "cpm hello.com again\\r"', 'expect "OS9:"',
        'send "cpm share.com\\r"', 'expect "OS9:"',
        'send "cpm bios.com\\r"', 'expect "BIOS 0"', 'send "x"', 'expect "y"', 'send "\\x1b"', 'expect "OS9:"', 'send "cpm ren.com\\r"', 'expect "OS9:"', 'send "cpm wild.com\\r"', 'expect "OS9:"',
        'send "chx /d0/cmds\\r"', 'expect "OS9:"', 'send "build /d0/p1\\r"', 'expect "?"', 'send "cpm kbpoll.com\\r"', 'expect "?"', 'send "echo AFTER1\\r"', 'expect "?"',
        'send "cpm kbpoll.com\\r"', 'expect "?"', 'send "echo AFTER2\\r"', 'expect "?"', 'send "\\r"', 'expect "OS9:"',
        'send "chx /v0/cmds\\r"', 'expect "OS9:"', 'send "shell </d0/p1\\r"', 'expect "AFTER2"', 'expect "OS9:"'])
    check('CP/M-80: stack at (6), JP 0 ends the program; later runs are not disturbed', out.count('stack at (6) ok') == 2 and 'AGAIN' in out, out[-600:])
    check('CP/M-80: the console through the BIOS jump table (CONST, CONIN, CONOUT; Turbo Pascal), the terminal is back to normal after',
          'BIOS 0 y' in out and 'ESC ok' in out and 'cpm ren.com' in out, out[-700:])
    check('CP/M-80: BDOS 23 (rename: new name made, old file copied and deleted; the old name is gone, a second rename fails)',
          'REN OK' in out, out[-600:])
    check('CP/M-80: wildcards: BDOS 15 opens the first file that matches, BDOS 19 deletes all that match',
          'WILD OK' in out, out[-600:])
    check('CP/M-80: the same file open through two FCBs (one shared OS-9 path, own positions)', 'SHARE OK' in out, out[-600:])
    check('CP/M-80: BDOS 6 / 11 key polls do not eat the procedure file that is the standard input (shell <file)',
          out.count('KBPOLL ok') == 2 and 'AFTER1' in out.split('shell </d0/p1')[-1] and 'AFTER2' in out.split('shell </d0/p1')[-1], out[-700:])
    check('CP/M-80 on the Z80 from OS-9: BDOS 9/2, command tail', 'Hello from CP/M-80 on the Z80' in out and ' ABC DEF' in out, out[-800:])
    check('CP/M-80: file I/O (make, write, open, read, EOF, random, size, search, delete)', 'FILEIO OK' in out, out[-800:])
    check('CP/M-80: console buffer (BDOS 10), BDOS 1 and 6', '[xyz]' in out and 'key=q' in out, out[-800:])


def cmd86(name, tmp):
    """tests/cpm/<name>.asm (nasm, 8080 model) -> .CMD bytes"""
    b = os.path.join(tmp, name + '.bin')
    c = os.path.join(tmp, name + '.cmd')
    r = run(['nasm', '-f', 'bin', os.path.join(HERE, 'cpm', name + '.asm'), '-o', b])
    assert r.returncode == 0, r.stdout
    r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'mkcmd.py'), '8080', b, c])
    assert r.returncode == 0, r.stdout
    return open(c, 'rb').read()


def cmd86_small(tmp):
    out = {}
    for n in ('small86_code', 'small86_data'):
        r = run(['nasm', '-f', 'bin', os.path.join(HERE, 'cpm', n + '.asm'), '-o', os.path.join(tmp, n + '.bin')])
        assert r.returncode == 0, r.stdout
    c = os.path.join(tmp, 'small86.cmd')
    r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'mkcmd.py'), 'small', os.path.join(tmp, 'small86_code.bin'),
             os.path.join(tmp, 'small86_data.bin'), c])
    assert r.returncode == 0, r.stdout
    return open(c, 'rb').read()


def os9_cpm86(tmp):
    """CP/M-86 programs on the 8088, started from OS-9 with the command cpm"""
    if not os.path.isdir(OS9):
        return
    files = {n + '.cmd': cmd86(n, tmp) for n in ('hello86', 'fileio86', 'line86')}
    files['small86.cmd'] = cmd86_small(tmp)
    out, d = os9_session(tmp, 'cpm86', '8088', files, [
        'send "cpm hello86.cmd abc def\\r"', 'expect "OS9:"',
        'send "cpm small86.cmd\\r"', 'expect "OS9:"',
        'send "cpm fileio86.cmd\\r"', 'expect "OS9:"',
        'send "cpm line86.cmd\\r"', 'expect "Name? "', 'send "xyz\\r"', 'expect "]"', 'send "q"', 'expect "OS9:"'])
    check('CP/M-86 on the 8088 from OS-9: 8080 model, BDOS 9/2, command tail',
          'Hello from CP/M-86 on the 8088' in out and ' ABC DEF' in out, out[-800:])
    check('CP/M-86: small model (code + data group), RETF, version', 'Hello from the small model' in out and 'version ok, RETF ends' in out, out[-800:])
    check('CP/M-86: file I/O (make, write, open, read, EOF, random, size, search, delete)', 'FILEIO86 OK' in out, out[-800:])
    check('CP/M-86: console buffer (BDOS 10), BDOS 1 and 6', '[xyz]' in out and 'key=q' in out, out[-800:])


def os9_cpm80_text(tmp):
    """text files, STDIN / STDOUT, redirection, the tool directory (-p=) and the default extension"""
    if not os.path.isdir(OS9):
        return
    files = {n + '.com': z80_com(n, tmp) for n in ('tcat', 'tcount', 'hello', 'twrite')}
    files['in.txt'] = b'aaa\rbbb\rccc\r'                    # OS-9 line ends
    files['lf.txt'] = b'one\ntwo\n'                         # host line ends
    out, d = os9_session(tmp, 'cpm80text', 'z80', files, [
        'send "cpm tcount.com\\r"', 'expect "OS9:"',                     # IN.TXT = in.txt: 3 lines
        'send "list lf.txt !cpm tcat.com >copy.txt\\r"', 'expect "OS9:"',      # an OS-9 pipe into a CP/M filter
        'send "copy out.txt out1.txt\\r"', 'expect "OS9:"', 'send "del out.txt\\r"', 'expect "OS9:"',
        'send "cpm twrite.com\\r"', 'expect "OS9:"',
        'send "makdir tools\\r"', 'expect "OS9:"', 'send "copy hello.com tools/hello.com\\r"', 'expect "OS9:"',
        'send "del hello.com\\r"', 'expect "OS9:"',
        'send "cpm -p=tools hello x\\r"', 'expect "OS9:"'])
    check('CP/M-80 text files: OS-9 CR line ends are seen as CR LF', 'CR=03 LF=03' in out, out[-600:])
    names = {n.lower(): n for n in os.listdir(os.path.join(d, 'v0'))}
    got = lambda n: open(os.path.join(d, 'v0', names[n]), 'rb').read() if n in names else None
    check('OS-9 pipe -> CP/M filter (STDIN / STDOUT FCBs) -> redirect: host LF text -> OS-9 text', got('copy.txt') == b'one\rtwo\r', repr(got('copy.txt')))
    check('a text file written by CP/M (CR LF, ^Z) has OS-9 line ends; the filter also wrote OUT.TXT', got('new.txt') == b'ab\rcd\r' and got('out1.txt') == b'one\rtwo\r',
          repr((got('new.txt'), got('out1.txt'))))
    check('cpm -p=dir: program and default extension found in the tool directory', 'Hello from CP/M-80 on the Z80' in out, out[-600:])


def os9_cpp(tmp):
    """the C preprocessor written for OS-9 (os9/cpp/cpp.asm): macros, conditionals, expressions, #include, -D"""
    if not os.path.isdir(OS9):
        return
    files = {n: open(os.path.join(HERE, 'cpp', n), 'rb').read() for n in ('t1.c', 't1.h', 't2.c', 't3.c', 't4.c')}
    out, d = os9_session(tmp, 'cpp', 'z80', files, [
        'send "cpp80 t1.c >t1.o\\r"', 'expect "OS9:"', 'send "cpp80 t2.c >t2.o\\r"', 'expect "OS9:"',
        'send "cpp80 t3.c >t3.o\\r"', 'expect "OS9:"', 'send "cpp80 t4.c >t4.o\\r"', 'expect "OS9:"', 'send "cpp80 -DFOO=5 -DBAR t1.c >t1d.o\\r"', 'expect "OS9:"'])
    names = {n.lower(): n for n in os.listdir(os.path.join(d, 'v0'))}
    def words(n):
        if n not in names:
            return None
        return [l.strip() for l in open(os.path.join(d, 'v0', names[n]), 'rb').read().decode('latin-1').split('\r') if l.strip()]
    t1 = words('t1.o')
    check('cpp: #include, object and function-like macros, nested arguments, strings, comments, #undef',
          t1 is not None and 'int x = 2 + 1;' in t1 and 'int y = ((2)+(((1)+(2))));' in t1 and
          'char *s = "not /* a comment */ TWO";' in t1 and 'int z = TWO;' in t1 and 'int w = (5) * 2;' in [' '.join(l.split()) for l in t1], repr(t1))
    check('cpp: #if / #ifdef / #ifndef / #elif / defined', t1 is not None and all(x in t1 for x in ('int nofoo;', 'int nobar;', 'int calc_ok;', 'int elif_ok;', 'int either;')), repr(t1))
    t2 = words('t2.o')
    check('cpp: #if expressions and function-like macro calls in text',
          t2 is not None and t2[-1] == '((1)+(2)) ((((1)+(2)))*(((1)+(2)))) ((3)+(((2)*(2))))' and
          all(x in t2 for x in ('a1', 'b0', 'and_ok', 'eq_ok', 'arith_ok', 'or_ok', 'def_ok', 'tern_ok', 'num_ok', 'op_ok', 'cmp_ok', 'elif_ok')), repr(t2))
    t3 = words('t3.o')
    check('cpp: operators (division, shifts, bit operations, 16 bit constants, ?:)',
          t3 == ['c1', 'c2', 'c3', 'c4', 'c5', 'c6', 'c7', 'c8', 'c9', 'c10', 'c11', 'c13'], repr(t3))
    t4 = words('t4.o')
    check('cpp: # (stringify) and ## (paste), arguments expanded first except next to # and ##',
          t4 == ['char *a = "hello world";', 'char *b = "\\"q\\\\\\"uote\\" \'c\' \\n";', 'int foobar = 1;', 'int x_y = 12;',
                 'char *c = "abc" " done";', 'char *d = "42";', 'char *e = "VAL";', 'int f = VAL1;'], repr(t4))
    t1d = words('t1d.o')
    check('cpp: -Dname=value and -Dname',
          t1d is not None and 'int foo = 5;' in t1d and 'int calc_bad;' in t1d and 'int nobar;' not in t1d, repr(t1d))


def os9_cc80(tmp):
    """OS-9 cpp -> HI-TECH C passes on the Z80 -> a CP/M-80 program, started by cc80.  The compiler is not part of
    this project: set MATENRO_HTC to a directory with P1.COM CGEN.COM ZAS.COM LINQ.COM CRTCPM.OBJ LIBC.LIB LIBF.LIB and the headers."""
    htc = os.environ.get('MATENRO_HTC')
    if not os.path.isdir(OS9):
        return
    if not htc or not os.path.isdir(htc):
        print('skip cc80 (set MATENRO_HTC to the HI-TECH C directory)')
        return
    d = os.path.join(tmp, 'sess_cc80')
    os.mkdir(d)
    for f in ('OS9.dsk', 'WORK.dsk'):
        shutil.copy(os.path.join(OS9, f), d)
    v0 = os.path.join(d, 'v0')
    shutil.copytree(os.path.join(OS9, 'level2', 'cmds'), os.path.join(v0, 'cmds'))
    for n in ('cpm', 'cpp80', 'cc80'):
        shutil.copy(os.path.join(tmp, 'cpmbuild', n), os.path.join(v0, 'cmds', n))
    os.mkdir(os.path.join(v0, 'htc'))
    for n in os.listdir(htc):
        if n.upper().endswith(('.COM', '.OBJ', '.LIB', '.H')):
            shutil.copy(os.path.join(htc, n), os.path.join(v0, 'htc', n))
    shutil.copy(os.path.join(HERE, 'cpp', 'demo.c'), v0)
    shutil.copy(os.path.join(HERE, 'cpp', 'fp.c'), v0)
    script = os.path.join(d, 'script.txt')
    open(script, 'w').write('timeout 3000000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\nsend "chd /v0\\r"\nexpect "OS9:"\n'
                            'send "cc80 -r demo.c\\r"\nexpect "OS9:"\nsend "cc80 -r -DSMALL demo.c\\r"\nexpect "OS9:"\n'
                            # floating point: libf.lib is linked by itself, and by -lf
                            'send "cc80 -r fp.c\\r"\nexpect "OS9:"\nsend "cc80 -lf -r fp.c\\r"\nexpect "OS9:"\n'
                            # two cc80 in a procedure file (shell <file): the system memory of Level 2 must be enough, and the
                            # passes must not eat the second line of the file
                            'send "chx /d0/cmds\\r"\nexpect "OS9:"\nsend "build /d0/p2\\r"\nexpect "?"\nsend "cc80 -r demo.c\\r"\nexpect "?"\n'
                            'send "cc80 -r -DSMALL demo.c\\r"\nexpect "?"\nsend "\\r"\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\n'
                            'send "echo START2\\r"\nexpect "OS9:"\nsend "shell </d0/p2\\r"\nexpect "small 36"\nexpect "OS9:"\nquit\n')
    r = run([SIM, '-max', '-m', '1M', '-sub', 'z80', '-rom', os.path.join(OS9, 'os9v2.rom'), '-0', os.path.join(d, 'OS9.dsk'),
             '-1', os.path.join(d, 'WORK.dsk'), '-v', v0, '-script', script], timeout=900)
    out = r.stdout.decode(errors='replace')
    check('cc80: cpp on OS-9 -> HI-TECH C on the Z80 -> program runs (macros, #if, -D)', 'big 36' in out and 'small 36' in out, out[-800:])
    check('cc80: floating point (libf.lib is linked when the code generator calls fladd ..., or with -lf)',
          out.split('START2')[0].count('fp 1250') == 2, out[-800:])
    check('cc80 twice in a procedure file (shell <file): enough system memory, the passes leave the file alone',
          out.split('START2')[-1].count('big 36') == 1 and out.split('START2')[-1].count('small 36') == 1, out[-800:])


def os9_turbo(tmp):
    """Turbo Pascal 3.0 for CP/M-80 (not part of this project: set MATENRO_TP to a directory with TURBO.COM TURBO.MSG TURBO.OVR):
    load a source, compile, run, save (the BDOS renames the source to .BAK).  Turbo Pascal calls the BIOS for the console."""
    tp = os.environ.get('MATENRO_TP')
    if not os.path.isdir(OS9):
        return
    if not tp or not os.path.isdir(tp):
        print('skip Turbo Pascal (set MATENRO_TP to the directory with TURBO.COM TURBO.MSG TURBO.OVR)')
        return
    d = os.path.join(tmp, 'sess_tp')
    os.mkdir(d)
    for f in ('OS9.dsk', 'WORK.dsk'):
        shutil.copy(os.path.join(OS9, f), d)
    v0 = os.path.join(d, 'v0')
    shutil.copytree(os.path.join(OS9, 'level2', 'cmds'), os.path.join(v0, 'cmds'))
    shutil.copy(os.path.join(tmp, 'cpmbuild', 'cpm'), os.path.join(v0, 'cmds', 'cpm'))
    for n in os.listdir(tp):
        if n.upper() in ('TURBO.COM', 'TURBO.MSG', 'TURBO.OVR'):
            shutil.copy(os.path.join(tp, n), v0)
    shutil.copy(os.path.join(HERE, 'cpm', 'hello.pas'), v0)
    script = os.path.join(d, 'script.txt')
    # (Turbo Pascal reads and drops the keys that come while it draws the screen: wait for the end of every screen)
    open(script, 'w').write('timeout 9000000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\n'
                            'send "copy /v0/hello.pas /d1/hello.pas\\r"\nexpect "OS9:"\nsend "attr /d1/hello.pas -s\\r"\nexpect "OS9:"\n'
                            'send "chd /d1\\r"\nexpect "OS9:"\nsend "cpm -p=/v0 /v0/turbo.com\\r"\nexpect "(Y/N)"\nsend "n"\n'
                            'expect "F806)"\nsleep 1000000\nsend "w"\nexpect "name:"\nsleep 1000000\nsend "hello\\r"\n'
                            'expect "Loading"\nsleep 1500000\nsend "c"\nsleep 4000000\nsend "r"\nsleep 4000000\n'
                            'send "s"\nsleep 3000000\nsend "q"\nsleep 2500000\nsend "dir /d1\\r"\nsleep 1500000\n'
                            'send "echo TPDONE\\r"\nexpect "TPDONE"\nsleep 500000\nquit\n')
    r = run([SIM, '-max', '-m', '1M', '-sub', 'z80', '-rom', os.path.join(OS9, 'os9v2.rom'), '-0', os.path.join(d, 'OS9.dsk'),
             '-1', os.path.join(d, 'WORK.dsk'), '-v', v0, '-script', script], timeout=900)
    out = r.stdout.decode(errors='replace')
    check('Turbo Pascal 3.0: load, compile, run (the BIOS console, the terminal in the raw mode)',
          'Hello from Turbo Pascal 1' in out and 'Hello from Turbo Pascal 3' in out, out[-900:])
    check('Turbo Pascal 3.0: save renames the source to .BAK (BDOS 23 with the file still open)',
          'HELLO.BAK' in out.split('dir /d1')[-1] and 'HELLO.PAS' in out.split('dir /d1')[-1], out[-900:])


def os9_driver(tmp):
    """the xlink driver (os9/xlink): the sub CPU memory comes from OS-9's own RAM (no -m 1M), the doorbell is an interrupt"""
    if not os.path.isdir(OS9):
        return
    f80 = {n + '.com': z80_com(n, tmp) for n in ('hello', 'fileio')}
    out, d = os9_session(tmp, 'drv80', 'z80', f80, [
        'send "cpm hello.com abc\\r"', 'expect "OS9:"', 'send "cpm fileio.com\\r"', 'expect "OS9:"',
        'send "cpm hello.com again\\r"', 'expect "OS9:"'], driver=True)
    check('xlink driver, Z80: memory from OS-9 (2MB machine), three runs in a row (allocate / free)',
          out.count('Hello from CP/M-80 on the Z80') == 2 and 'FILEIO OK' in out and ' AGAIN' in out, out[-700:])
    out, d = os9_session(tmp, 'drvstress', 'z80', {'bstress.com': z80_com('bstress', tmp)}, [
        'send "cpm bstress.com\\r"', 'expect "DONE"', 'expect "OS9:"'], driver=True, timeout=240)
    run_out = out.split('DONE')[0].rsplit('cpm bstress.com', 1)[-1]
    check('xlink driver, Z80: 3000 rounds of memory work and BDOS calls (tests/cpm/bstress.asm), no E',
          'DONE' in out and run_out.count('.') >= 3000 and 'E' not in run_out, out[-300:])
    f86 = {'hello86.cmd': cmd86('hello86', tmp), 'small86.cmd': cmd86_small(tmp)}
    out, d = os9_session(tmp, 'drv86', '8088', f86, [
        'send "cpm hello86.cmd abc\\r"', 'expect "OS9:"', 'send "cpm small86.cmd\\r"', 'expect "OS9:"'], driver=True)
    check('xlink driver, 8088: 32 blocks, the reset vector block mapped', 'Hello from CP/M-86 on the 8088' in out and 'Hello from the small model' in out, out[-700:])


def memtest():
    """power-on memory test of the sim09 board: "Matenro Memory " + 24 x ">" + " OK 2048K" / " NG @aaaaaa" """
    rom = os.path.join(OS9, 'os9v2.rom')
    if not os.path.exists(rom):
        print('skip memtest (no %s)' % rom)
        return
    base = [SIM, '-max', '-nt', '-maxcount', '10', '-rom', rom]
    out = run(base).stdout.decode(errors='replace')
    check('memory test: Matenro Memory %s OK 2048K' % ('>' * 24), out.startswith('Matenro Memory ' + '>' * 24 + ' OK 2048K\r\n'), out[:80])
    out = run(base + ['-memfault', '123456']).stdout.decode(errors='replace')
    check('memory test: a stuck bit is reported with its address', out.startswith('Matenro Memory ' + '>' * 24 + ' NG @123456\r\n'), out[:80])
    out = run(base + ['-nomemtest']).stdout.decode(errors='replace')
    check('memory test: -nomemtest prints nothing', not out.startswith('Matenro Memory'), out[:80])
    out = run(base + ['-L1', '-rom', os.path.join(OS9, 'v09.rom')]).stdout.decode(errors='replace')
    check('memory test: Level 1 tests its 64KB', out.startswith('Matenro Memory >>> OK 64K\r\n'), out[:80])


def main():
    if not os.path.exists(SIM):
        print('build first: make')
        return 2
    tmp = tempfile.mkdtemp(prefix='mh_')
    try:
        memtest()
        integration('z80', z80_program(), tmp)
        integration('8088', i8088_program(tmp), tmp)
        standalone('z80', tmp)
        standalone('8088', tmp)
        os9_regression(tmp)
        build_cpm(tmp)
        os9_xrun(tmp)
        os9_cpm80(tmp)
        os9_cpm80_text(tmp)
        os9_cpm86(tmp)
        os9_cpp(tmp)
        os9_cpmapps(tmp)
        os9_drive(tmp)
        os9_bdos(tmp)
        os9_etime(tmp)
        os9_duo(tmp)
        os9_reboot(tmp)
        os9_cc80(tmp)
        os9_turbo(tmp)
        os9_driver(tmp)
        os9_bigdisk(tmp)
        os9_dos(tmp)
        os9_dos2(tmp)
        os9_subsel(tmp)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    print('%d tests, %d failed' % (total, fails))
    return 1 if fails else 0


if __name__ == '__main__':
    sys.exit(main())
