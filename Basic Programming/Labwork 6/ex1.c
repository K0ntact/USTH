#include <stdio.h>
#include "ex1_add.h"

int main()
{   
    int a=1, b=2;
    int *c = &a, *d = &b;
    printf("The sum is: %d", add(c,d));
    return 0;
}