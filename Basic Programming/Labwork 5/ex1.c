#include <stdio.h>

int main()
{   
    int a[5] = {4,5,3,1,7};
    for (int i = 1; i <= sizeof(*a); i++)
    {
        for (int j = 0; j < sizeof(*a) - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                a[j] = a[j+1] + a[j];
                a[j+1] = a[j] - a[j+1];
                a[j] = a[j] - a[j+1];
            }
        }
    }
    int size = sizeof(a)/sizeof(*a);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}