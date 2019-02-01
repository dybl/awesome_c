#include <stdio.h>
int main()
{
    int a = 20;
    int *p;
    p = &a;
    printf("address of a: %p\n", &a);
    printf("address stored in p: %p\n", p);
    printf("value of *p: %d\n", *p);
    return 0;
}