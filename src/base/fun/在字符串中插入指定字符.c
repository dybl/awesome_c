#include<stdio.h>
void insert(char s[],int pos,char c)
{
	int i=0;
	while(s[i]!='\0')
		i++;
	if(pos<0 || pos>i)
		return;
	while(i>=pos)
	{
		s[i+1]=s[i];
		i--;
	}
	s[pos]=c;
}
void main()
{
	char s[100]={"Hello World!"};
	insert(s,4,'o');
	printf("%s\n",s);
}