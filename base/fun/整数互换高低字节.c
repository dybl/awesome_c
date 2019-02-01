#include<stdio.h>
union key
{
	short int a;
	char cc[2];
}uc;
void main()
{
	char t;
	uc.a=0x1234;
	uc.cc[0]=uc.cc[1];
	uc.cc[1]=t;
	printf("%x\n",uc.a);
}
