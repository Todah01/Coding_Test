#if 1
#include <stdio.h>

int test(int a)
{
	printf("test() : Hello World\n");
	return 0;
}

int main(void)
{
	// test(5);
	int (*pfTest)(int) = test;

	pfTest(5);
	return 0;
}
#endif