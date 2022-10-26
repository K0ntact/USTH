#include <stdio.h>

int normal();
int recursive();

int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    printf("normal: %d\n", normal(x,n));
    printf("recursive: %d", recursive(x,n));
    return 0;
}

int normal(int a, int b)
{   
    int x = 1;
    for (int i = 1; i <= b; i++)
    {
        x = x*a;
    }
    return x;
}

int recursive(int a, int b)
{
    if (b == 1)
        return a;
    else
        return a*recursive(a, b-1);
}