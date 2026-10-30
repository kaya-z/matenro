#define STR(x) #x
#define CAT(a,b) a ## b
#define CAT3(a, b, c) a##b##c
#define MSG(x) STR(x) " done"
#define XSTR(x) STR(x)
#define VAL 42
char *a = STR(hello world);
char *b = STR( "q\"uote" 'c' \n );
int CAT(foo, bar) = 1;
int CAT3(x, _, y) = CAT(1, 2);
char *c = MSG(abc);
char *d = XSTR(VAL);
char *e = STR(VAL);
int f = CAT(VAL, 1);
