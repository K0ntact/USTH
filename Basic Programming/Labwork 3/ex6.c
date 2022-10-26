#include <stdio.h>
#include "ex6_facto.h"
int main()
{
    int n;
    printf("Type the number: ");
    scanf("%d", &n);
    printf("%d", fac(n));
    return 0;
}