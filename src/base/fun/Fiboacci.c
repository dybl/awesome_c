#include<stdio.h>
long F(int n);
void main()
{
	int n;
	scanf("%d",&n);
	printf("%ld\n",F(n));
}
long F(int n)
{
	long y;
	if(n<=0)
		y=0;
	else
		if(n==1 || n==2)
			y=1;
		else
			y=F(n-1)+F(n-2);
	return y;
}