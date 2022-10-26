#include <stdio.h>

int no(int n);

void main()
{
    int (*p)(int) = &no;
    printf("%d", (*p)(10));
}

int no(int n)
{
    return n;
}