
#include<stdio.h>
main()
{
	int i,j;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=i;j++)
		printf("%d",(1+(i-1)*i/2+j-1)%10);
	    printf("\n");
	}
}
