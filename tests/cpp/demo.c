/* seamless demo: the OS-9 preprocessor (cpp80) feeds the CP/M-80 C compiler (HI-TECH C) */
#include <stdio.h>
#define SQ(x) ((x)*(x))
#define N 5
#if N > 3 && !defined(SMALL)
#define MSG "big"
#else
#define MSG "small"
#endif
main()
{
	printf("%s %d\n", MSG, SQ(N+1));
	return 0;
}
