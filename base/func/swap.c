#include<stdio.h>
void swap(int &x, int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}

int main(int argc, char *argv[])
{
	int a,b;
	printf("please input a,b\n");
	scanf("a is %d,b is %d\n",&a,&b);
	swap(a,b);
	printf("now a is %d,b is %d\n");
	return 0;
}
	
