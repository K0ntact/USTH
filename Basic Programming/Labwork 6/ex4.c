#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *p = calloc(n, sizeof(int));
    for (int j = 0; j < n; j++)
    {
        scanf("%d", p+j);
    }
    for (int i = 0; i<n; i++)
    {
        printf("%d", *(p+i));
    }
}