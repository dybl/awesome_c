#include<stdio.h>
void main()
{
	int s[4][5]={1,2,3,4,5,2,3,4,5,6,3,4,5,6,7,4,5,6,7,8};
	int i,j;
	int s1[4]={0,0,0,0},s2[5]={0,0,0,0,0};
	for(i=0;i<4;i++)
		for(j=0;j<5;j++)
			s1[i]+=s[i][j];
	for(i=0;i<5;i++)
		for(j=0;j<4;j++)
			s2[i]+=s[j][i];
	printf("The sum of row:\n");
	for(i=0;i<4;i++)
		printf("%5d\n",s1[i]);
	printf("\n The sum of col:\n");
	for (i=0;i<5;i++)
		printf("%5d\n",s2[i]);
} 
