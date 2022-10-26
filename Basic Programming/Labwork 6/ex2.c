#include <stdio.h>
#include "ex2_swap.h"

int main()
{   
    int a=1, b=2;
    int *c = &a, *d = &b;
    swap(c, d);
    printf("Value of a: %d \n", *c);
    printf("Value of b: %d \n", *d);
    return 0;
}