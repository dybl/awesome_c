#include<stdio.h>
int main()
{
	int i,s;
	for(i = 1,s = 0;i <= 100;++ i)
	{
		if(i % 10 == 6 || i / 10 == 6)
		    s += i;
	}
	printf("%d\n",s);
	return 0;
}
