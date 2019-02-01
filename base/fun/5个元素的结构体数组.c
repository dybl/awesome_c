#include<stdio.h>
void main()
{
	struct student
	{
		char name[10];
		char sex;
		float score;
	}st[5];
	int i;
	float f,average=0;
	for(i=0;i<5;i++)
	{
		printf("Input %d\'s name,sex,score:\n",i+1);
		scanf("%s",&st[i].name);
		getchar();
		scanf("%c",&st[i].sex);
		getchar();
		scanf("%f",&f);
		st[i].score=f;
		average+=st[i].score;
	}
	average/=5;
	printf("Name\t\tSex\t\tScore\n");
	for(i=0;i<5;i++)
		if(st[i].score>average)
			printf("%s\t\t%c\t\t%5.lf\n",st[i].name,st[i].sex,st[i].score);
}