
#include<stdio.h>
main()
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			if((i+j)%2==0)
				printf("%c%c\n",218,218);
			else
				printf("  ");
			printf("\n");
	}
}
