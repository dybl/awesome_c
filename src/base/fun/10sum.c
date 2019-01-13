
#include <stdio.h>
#include <conio.h>
main()
{
	int a,i,s1=0,s2=0;
	printf("Please input ten number:");
	for(i=1;i<11;i++)
	{
		scanf("%d",&a);
	    if(a>0)
			s1+=a;
		else 
	   		s2+=a;
	}
	printf("zheng=%d,fu=%d\n",s1,s2);
	getchar();
}
