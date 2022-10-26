#include <stdio.h>

int main()
{
    int n, a[n], sum = 0;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("\nEnter array element \n");
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i<n; i++)
    {
        sum = sum + a[i];
    }
    printf("%d", sum);
    return 0;
}   