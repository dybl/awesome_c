#include<stdio.h>
void main()
{
	char str[20],*p=str;
	gets(str);
	while(*p)
		p++;
	p--;
	while(p>=str)
	{
		printf("%c\n",*p);
		p--;
	}
	printf("\n");
}