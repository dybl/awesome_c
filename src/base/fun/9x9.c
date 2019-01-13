#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    for(i = 0; i < 45; i ++)
    {
        int R = (sqrt(8 * i + 1) + 1) / 2;
        int C = i + 1 - (R - 1) * R / 2;
        printf("%d*%d=%d", C, R, R * C);
        putchar(R == C ? '\n' : ' ');
    }
    return 0;
}