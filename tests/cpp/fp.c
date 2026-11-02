/* floating point: cc80 must link libf.lib by itself (the code generator calls fladd, flmul, aitof ...) */
main()
{
	float a, b;
	int i;

	a = 1.5;
	b = a * a + 0.25;
	i = b * 100;
	if (b > 2)
		i = i + 1000;
	putch('f'); putch('p'); putch(' ');
	putch('0' + i / 1000); putch('0' + i / 100 % 10); putch('0' + i / 10 % 10); putch('0' + i % 10);
	putch('\n');
	return 0;
}
