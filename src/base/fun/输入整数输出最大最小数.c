#include<stdio.h>
#include<string.h>
void main()
{
	int a[10],*p=a;
	int *pmax,*pmin;
	int i;
	for(i=0;i<10;i++)
		scanf("%d",p++)
	pmax=pmin=a;
	p=a+1;
	for(i=1;i<10;i++)
	{
		if(*p>*pmax)
			pmax=p;
		else
			if(*p<*pmin)
				pmin=p;
		p++;
	}
	printf("max is %d\n",*pmax);
	printf("min is %d\n",*pmin);
}