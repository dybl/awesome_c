#include<stdio.h>
int HelloWorld(char* string) {
  sprintf(string, "Hello World.\n");
}
int main(int argc, char* argv[]) 
{
   if(argv == 0) return 1;
   HelloWorld(argv);
   return 0;
}

