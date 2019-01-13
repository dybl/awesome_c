
#include <stdio.h>
main()
{
	int i,j,k;
	for(i=1;i<=9;i++)
		for(j=0;j<=9;j++)
			for(k=0;k<=9;k++)
				if(100*i+10*j+k==i*i*i+j*j*j+k*k*k)
			printf("%d%d%d\n",i,j,k);
}
