#include<stdio.h>
void main()
{
	struct st
	{
		int i;
		char c;
	}s,*p=&s;
	scanf("%c%d",&s.c,&s.i);
	scanf("%c,%d\n",s.c,s.i);
	printf("%c,%d\n",p->c,p->i);
}