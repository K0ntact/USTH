#include <stdio.h>
#include "ex4_product_digit.h"
int main()
{   
    int n;
    printf("Enter number: \n");
    scanf("%d", &n);
    printf("%d", product(n));
    return 0;
}