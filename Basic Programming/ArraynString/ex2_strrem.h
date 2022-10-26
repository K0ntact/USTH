#include <string.h>
void charremover(char *a, char remove)
{
    int length;
    length = strlen(a);

    for (int i = 0; i<length; i++)
    {
        if (a[i] == remove)
        {
            for (int j = i; j<length; j++)
            {
                a[j] = a[j+1];
            }
            length --;
            i --;
        }
    }
}