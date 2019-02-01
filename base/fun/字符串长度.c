#include<stdio.h>
#include<string.h>
int len(char *s);
void main()
{
	char s[100];
	printf("Please input a string:");
	gets(s);
	printf("string\'s length is %d\n",len(s));	
}
int len(char *s)
{
	int length=0;
	while(*(s+length)!='\0')
		length++;
	return length;
}