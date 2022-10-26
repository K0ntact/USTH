#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n;
    int sum = 0;
    printf("Enter matrix size n x n: ");
    scanf("%d", &n);
    int **a = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        printf("Value for row %d: ", i);
        for (int val = 0; val < n; val++)
        {
            scanf("%d", &a[i][val]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum = sum + a[i][j];
        }
    }
    printf("%d", sum);
}