
 #include<stdio.h>
 main()
 {
 	int i,s=0;
 	for(i=1;i<=99;i=i+2)
 		s=s+i;
 	for(i=2;i<=100;i=i+2)
 		s=s-i;
 	printf("s=%d\n",s);
 }
