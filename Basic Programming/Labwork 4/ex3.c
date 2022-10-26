#include <stdio.h>

float fx();
int gxy();
int main()
{   
    int a,b;
    printf("Enter 2 integer: ");
    scanf("%d%d", &a, &b);
    printf("%.1f \n", fx(a));
    printf("%d \n", gxy(a,b));
    return 0;
}

float fx(int n)
{
    return 2.5*n; 
}

int gxy(int n, int m)
{
    return n*m;
}