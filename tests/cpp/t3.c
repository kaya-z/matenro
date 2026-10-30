#if 0 == 0
c1
#endif
#if 0 + 1
c2
#endif
#if 0 || 7
c3
#endif
#if 10 / 3 == 3 && 10 % 3 == 1 && -7 / 2 == -3 && -7 % 2 == -1
c4
#endif
#if 100 + 23 == 123 && 12 * 12 == 144
c5
#endif
#if (1 << 4) == 16 && (256 >> 4) == 16 && 5 > 3 && 3 < 5 && 3 <= 3 && 3 >= 3
c6
#endif
#if (5 & 3) == 1 && (5 | 3) == 7 && (5 ^ 3) == 6 && ~0 == -1
c7
#endif
#if 0x1F == 31 && 017 == 15 && 'A' == 65
c8
#endif
#if 1 ? 0 : 1
bad9
#else
c9
#endif
#if 5 != 5
bad10
#else
c10
#endif
#if 3 - 5 < 0 && 2 * 3 - 1 == 5
c11
#endif
#if 0 || 0
bad12
#endif
#if 1000 / 10 == 100
c13
#endif
