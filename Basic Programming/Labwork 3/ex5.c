#include <stdio.h>
#include "ex5_fibbo.h"

int main()
{
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    for (int i = 1; i<=n; i++)
        printf("%d \n", fibo(i));
    return 0;
}