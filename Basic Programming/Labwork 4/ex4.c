#include<stdio.h>

int fac();
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d! is %d", n, fac(n));
    return 0;
}

int fac(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fac(n-1);
}