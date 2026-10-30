/* test of the OS-9 preprocessor */
#include "t1.h"
#define TWO 2
#define ADD(a,b) ((a)+(b))
#define STR "not /* a comment */ TWO"
#define EMPTY
int x = TWO + ONE;  /* trailing comment */
int y = ADD(TWO, ADD(1, 2));
char *s = STR;
char c = 'T';
#ifdef FOO
int foo = FOO;
#else
int nofoo;
#endif
#ifndef BAR
int nobar;
#endif
#if TWO == 2 && !defined(BAR) && (3 * 4 - 2) / 5 == 2
int calc_ok;
#else
int calc_bad;
#endif
#if 0
int dead;
#elif ONE + 1 > 1
int elif_ok;
#endif
#undef TWO
int z = TWO;
long l = 0x10 + 010 + 'a';
#define LONGMACRO(x) \
    (x) * \
    2
int w = LONGMACRO(5);
#if defined FOO || defined(ONE)
int either;
#endif
last line
