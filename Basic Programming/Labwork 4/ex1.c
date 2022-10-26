#include <stdio.h>
#include "ex1_GCD.h"

int main()
{   
    int n, m;
    printf("Enter number: \n");
    scanf("%d%d", &n, &m);
    printf("%d", GCD(n,m));
    return 0;
}