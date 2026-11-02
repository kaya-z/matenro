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
    """assemble the OS-9 commands cpm, xrun, reboot, etime, bdos and cpp (tools/build_cpm.sh); returns the output directory"""
    out = os.path.join(tmp, 'cpmbuild')
    r = run([os.path.join(ROOT, 'tools', 'build_cpm.sh'), out])
    if r.returncode != 0 or r.stdout.count(b'0 Pass 2 errors') != 10:
        raise RuntimeError('build_cpm.sh failed: ' + r.stdout.decode(errors='replace'))
    return out


def z80_com(name, tmp):
    """assemble tests/cpm/<name>.asm with tools/z80asm.py -> bytes"""
    sys.path.insert(0, os.path.join(ROOT, 'tools'))
    import z80asm
    base, img = z80asm.assemble(open(os.path.join(HERE, 'cpm', name + '.asm'), encoding='utf-8').read())
    assert base == 0x100, hex(base)
    return img


def os9_session(tmp, tag, cpu, files, script_lines, timeout=180, driver=False):
    """boot OS-9 Level 2 with the sub CPU `cpu`, /v0 holds the cmds directory and `files`; run the script; return the output"""
    d = os.path.join(tmp, 'sess_' + tag)
    os.mkdir(d)
    for f in ('OS9.dsk', 'WORK.dsk'):
        shutil.copy(os.path.join(OS9, f), d)
    shutil.copytree(os.path.join(OS9, 'level2', 'cmds'), os.path.join(d, 'v0', 'cmds'))
    for n in ('cpm', 'xrun', 'cpp', 'xlink', 'x0', 'reboot', 'etime', 'bdos'):
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
        'send "cpp t1.c >t1.o\\r"', 'expect "OS9:"', 'send "cpp t2.c >t2.o\\r"', 'expect "OS9:"',
        'send "cpp t3.c >t3.o\\r"', 'expect "OS9:"', 'send "cpp t4.c >t4.o\\r"', 'expect "OS9:"', 'send "cpp -DFOO=5 -DBAR t1.c >t1d.o\\r"', 'expect "OS9:"'])
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
    for n in ('cpm', 'cpp', 'cc80'):
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
    """power-on memory test of the sim09 board: "Memory " + 24 x ">" + " OK 2048K" / " NG @aaaaaa" """
    rom = os.path.join(OS9, 'os9v2.rom')
    if not os.path.exists(rom):
        print('skip memtest (no %s)' % rom)
        return
    base = [SIM, '-max', '-nt', '-maxcount', '10', '-rom', rom]
    out = run(base).stdout.decode(errors='replace')
    check('memory test: Memory %s OK 2048K' % ('>' * 24), out.startswith('Memory ' + '>' * 24 + ' OK 2048K\r\n'), out[:80])
    out = run(base + ['-memfault', '123456']).stdout.decode(errors='replace')
    check('memory test: a stuck bit is reported with its address', out.startswith('Memory ' + '>' * 24 + ' NG @123456\r\n'), out[:80])
    out = run(base + ['-nomemtest']).stdout.decode(errors='replace')
    check('memory test: -nomemtest prints nothing', not out.startswith('Memory'), out[:80])
    out = run(base + ['-L1', '-rom', os.path.join(OS9, 'v09.rom')]).stdout.decode(errors='replace')
    check('memory test: Level 1 tests its 64KB', out.startswith('Memory >>> OK 64K\r\n'), out[:80])


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
        os9_reboot(tmp)
        os9_cc80(tmp)
        os9_turbo(tmp)
        os9_driver(tmp)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    print('%d tests, %d failed' % (total, fails))
    return 1 if fails else 0


if __name__ == '__main__':
    sys.exit(main())
