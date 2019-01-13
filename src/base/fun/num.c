
#include<stdio.h>
main()
{
	int i=1,j,k=1;
	while(i<=10)
	{
		for(j=1;j<=k;j++,i++)
			printf("%d",i%10);
		k++;
		printf("\n");
	}
}
