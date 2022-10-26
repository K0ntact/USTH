#include <stdio.h>
#include "ex2_prime__checker.h"

int main()
{   
    //This whole idea is based on the fact that except
    //for 2,3,5, all primes are next to a divisor of 6
    int range, up, down;
    printf("Enter range: ");
    scanf("%d", &range);
    int a = range / 6;
    if (range <= 2)
        printf("No prime number");
    if (range >= 3)
        printf("3 \n");
    if (range == 5)
        printf("5 \n");
    for (int i = 1; i<=a; i++)
    {
        up = 6*i - 1;
        down = 6*i + 1;
        //If up/down of the divisor of 6 isn't a prime, then prime_checker
        //doesn't return anything, so we don't print it
        printf("%d \n", prime_checker(up));
        printf("%d \n", prime_checker(down));
    }
    return 0;
}