
#include <stdio.h>
main()
{
	int i,s;
	for(i=1,s=0;i<=100;i++)
	{
		if(i==6||(i%10==6||i/10==6))
			s=s+i;
	}
	printf("s=%d\n",s);
}
