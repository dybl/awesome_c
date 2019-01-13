#include<stdio.h>
long sum(int n)
{
	long s=0;
	int i;
	for(i=0;i<=n;i+=2)
		s+=i;
	return s;
}
void main()
{
	printf("%ld\n",sum(99));
}