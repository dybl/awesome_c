#include<stdio.h>
int main()
{
	int i;
	int month;
	int first=0;
	int daysmonth;
	printf("Year is 2017,Please input the month:");
	scanf("%d",&month);
	for(i=1;i<=month;i++);
	{
		switch(i)
		{
			case 2:daysmonth=29;
			break;
			case 4:
			case 6:
			case 9:
			case 11:daysmonth=30;
			break;
			default:daysmonth=31;
			break;
		}
		if(i<month)
			first=(first+daysmonth)%7;
	}
	printf("Year:2017,Month:%d,First:%d\n",month,first);
	printf("SU MO TU WE TH FR SA\n");

	for(i=0;i<first;i++)
		printf("   ");
	for(i=1;i<=daysmonth;i++)
	{
		printf("%3d",i);
		if((i+first)%7==0)
			printf("\n");
	}
	printf("\n");
}
