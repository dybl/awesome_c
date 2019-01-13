#include<stdio.h>
void main()
{
	char str[81],*p=str,*q,t;
	gets(str);
	printf("The origenal string:\n");
	puts(str);
	for(p=str;*(p+1);p++)
		for(q=p+1;*q;q++)
			if(*q<*p)
			{
				t=*p;
				*p=*q;
				*q=t;
			}
	printf("The result string:\n");
	puts(str);
}