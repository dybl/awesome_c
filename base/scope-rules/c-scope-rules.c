#include <stdio.h>
int a = 40;
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	int sum(int, int);
	printf("a value in main= %d\n", a);
	c = sum(a, b);
	printf("c value in main= %d\n", c);
	return 0;
}

int sum(int a, int b)
{
	printf("a valie in sum= %d\n", a);
	printf("b value in sum= %d\n", b);
	return a+b;
}
