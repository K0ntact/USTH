#include <stdio.h>

void bubble_sort();
void insertion_sort();
void selection_sort();


int main()
{
    int a[] = {3,5,3,0,9,1,2};
    int size = sizeof(a)/sizeof(*a);
    //bubble_sort(a, size);
    insertion_sort(a, size); 
    //selection_sort(a, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}


void bubble_sort(int *a, int size)
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                a[j] = a[j+1] + a[j];
                a[j+1] = a[j] - a[j+1];
                a[j] = a[j] - a[j+1];
            }
        }
    }
}



void insertion_sort(int *a, int size)
{   
    for( int i = 0; i < size ; i++ ) {
    /*storing current element whose left side is checked for its 
    correct position .*/

        int temp = a[ i ];    
        int j = i;

        /* check whether the adjacent element in left side is greater or
        less than the current element. */

        while(  j > 0  && temp < a[ j -1]) {

            a[j] = a[j] + a[j-1];
            a[j-1] = a[j] - a[j-1];
            a[j] = a[j] - a[j-1];  
            j = j - 1;

        }
         // moving current element to its  correct position.
        a[ j ] = temp;       
    }  
}

void selection_sort(int *a, int size)
{   
    int curmin;
    for (int i = 0; i < size - 1; i++)
    {
        curmin = i;
        for (int j = i+1; j < size; j++)
        {
            if (a[curmin] > a[j])
            {   
                curmin = j;
            }
        }
        
        if (curmin != i)
        {
            a[i] = a[i] + a[curmin];
            a[curmin] = a[i] - a[curmin];
            a[i] = a[i] - a[curmin];
        }
    }

    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d ", a[i]);
    // }
}