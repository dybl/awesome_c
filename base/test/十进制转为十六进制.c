#include<stdio.h>
void D2H(long Dec,char Hex[]);
void main()
{
	long dec;
	char  Hex[100];
	int i=0;
	printf("Input a data:");
	scanf("%ld",&dec);
	D2H(dec,Hex);
	printf("%s\n",Hex);
}
void D2H(long Dec,char Hex[])
{
	int i,j;
	char HS[16]={"0123456789ABCDEF"};
	char c;
	i=0;
	while(Dec>0)
	{
		Hex[i]=HS[Dec%16];
		Dec/=16;
		i++;
	}
	Hex[i]='\0';
	j=0;
	i--;
	while(j<i)
	{
	
		c=Hex[j];
		Hex[j]=Hex[i];
		Hex[i]=c;
		i--;
		j++;
	}
}
