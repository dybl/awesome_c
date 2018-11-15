#include <stdlib.h>
#include <stdio.h>

enum color 
    {
        red=1,
        green,
        blue
    }fav_co;

int main()
{
    printf("please input your favorite color:(1.red,2.green,3.blue :");
    scanf("%d\n", &fav_co);
    switch(fav_co)
    {
        case red:
            printf("your favorite color is red");
            break;
        case green:
            printf("your favorite color is green");
            break;
        case blue:
            printf("your favorite color is blue");
            break;
    }
    return 0;
}