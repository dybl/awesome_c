#include<stdio.h>
void main()
{
	int a,b,c,max(int,int);
	scanf("%d,%d,%d",&a,&b,&c);
	printf("%d\n",max(max(a,b),c));
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
