#include<stdio.h>
int main()
{
	int i=1,j=1,k=1;
	while(i<=1000)
	{
		for(j = 1;j <= k;j ++,i ++)
		printf("%d",i % 10);
		printf("\n");
		k ++;
	}
	return 0;
}
