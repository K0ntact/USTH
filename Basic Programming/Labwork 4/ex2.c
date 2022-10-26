#include <stdio.h>
#include "ex1_GCD.h"

int main()
{   
    int a, b, c, d, x, y, z;
    printf("Enter number: \n");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    x = GCD(a,b);
    y = GCD(c,d);
    z = GCD(x,y);
    printf("%d", z);
    return 0;
}