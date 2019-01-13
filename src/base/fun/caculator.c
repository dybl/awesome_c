#include <stdio.h>
main()
{
	int x,y;
	char op;
	printf("Please input xopy:");
	scanf("%d%c%d",&x,&op,&y);
	switch(op)
	{
		case '+':printf("%d+%d=%d\n",x,y,x+y);
		break;
		case '-':printf("%d-%d=%d\n",x,y,x-y);
		break;
		case '*':printf("%d*%d=%d\n",x,y,x*y);
		break;
		case '/':printf("%d/%d=%d\n",x,y,x/y);
		break;
		
	}
}
