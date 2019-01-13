#include<stdio.h>
void main()
{
	int b=3;
	if(b <= 10)
	    b++;
    if(b%3==1)
        b+=3;
	printf("%d\n",b);
}
