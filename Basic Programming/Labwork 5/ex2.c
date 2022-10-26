#include <stdio.h>
#include <math.h>

int odd_sum();
int even_sum();

int main()
{
    int n;
    scanf("%d", &n);
    printf("Odd sum = %d \n", odd_sum(n));
    printf("Even sum = %d", even_sum(n));
    return 0;
}

int even_sum(int n)
{   
    int sum = 0;
    for (int i = 1; i < floor(n/2) + 1; i++)
    {
        sum = sum + 2*i;
    }
    return sum;
}
int odd_sum(int n)
{   
    int sum = 1;
    for (int i = 1; i < floor((n-1)/2) + 1; i++)
    {
        sum = sum + (2*i+1);
    }
    return sum;
}