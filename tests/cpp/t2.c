#define A 1
#define B 0
#if A
a1
#endif
#if B
b1
#else
b0
#endif
#if A && !B
and_ok
#endif
#if A == 1
eq_ok
#endif
#if (3 * 4 - 2) / 5 == 2
arith_ok
#endif
#if A || B
or_ok
#endif
#if defined(A) && !defined(Z)
def_ok
#endif
#if 1 ? 2 : 3
tern_ok
#endif
#if 0x10 == 16 && 010 == 8 && 'a' == 97
num_ok
#endif
#if 7 % 4 == 3 && (1 << 3) == 8 && (100 >> 2) == 25 && -5 < 0 && ~0 == -1
op_ok
#endif
#if 3 > 2 && 2 >= 2 && 1 < 2 && 2 <= 2 && 3 != 4
cmp_ok
#endif
#if 0
x
#elif A
elif_ok
#else
x
#endif
#define ADD(a,b) ((a)+(b))
#define SQ(x) ((x)*(x))
ADD(1,2) SQ(ADD(1,2)) ADD( 3 , SQ(2) )
