#include<stdio.h>
int main()
{
	int a,b,c,t,s;
	scanf("%d,%d,%d",&a,&b,&c);
	t = b;
	b = a;
	s = c;
	c = b;
	a = c;
	c = t;
	a = s;
	printf("a=%d,b=%d,c=%d\n",a,b,c);
	return 0;
}
