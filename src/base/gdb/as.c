#include <stdio.h>

int gvar = 0;

int tempFunction(int a, int b)
{
    printf("tempFunction is called, a = %d, b = %d\n", a, b);
    return (a + b);
}

int main()
{
    int n;
    n = 1;
    n++;
    n--;

    gvar += 100;
    gvar -= 12;

    printf("n = %d, gvar = %d\n", n, gvar);

    n = tempFunction(1, 2);
    printf("n = %d\n", n);

    return 0;
}