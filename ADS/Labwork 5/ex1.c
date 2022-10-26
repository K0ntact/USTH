/* 
Pseudocode:

int swap_check = False

FUNCTION inserion_sort(array)
    FOR i = 1 to array.length
        temp = array[i]
        j = i
        swap_check = False
        WHILE j > 0 AND temp < array[j-1]
            array[j] = array[j-1]
            j = j - 1
            swap_check = True
        END
        array[j] = temp
    END
END

FUNCTION rev_bubble_sort(array)
    FOR j = array.length - 1 to 1
        swap_check = False
        IF array[j] < array[j-1]
            temp = array[j]
            array[j] = array[j-1]
            array[j-1] = temp
            swap_check = True
        END
    END
END

FUNCTION special_sort(array)
    WHILE swap_check
        insertion_sort(array)
        rev_bubble_sort(array)
    END

    PRINT array

END

FUNCTION main()
    array = [5, 4, 3, 2, 1]
    special_sort(array)
END

*/


#include <stdio.h>

int swap_check = 1;
void insertion_sort(int *a, int size)
{   
    for( int i = 0; i < size ; i++ ) {
        int temp = a[i];    
        int j = i;
        swap_check = 0;

        while(  j > 0  && temp < a[ j -1]) {

            a[j] = a[j] + a[j-1];
            a[j-1] = a[j] - a[j-1];
            a[j] = a[j] - a[j-1];  
            j = j - 1;
            swap_check = 1;
        }
        a[j] = temp;       
    }  
}

void rev_bubble_sort(int *a, int size)
{
    for (int j = size - 1; j > 0; j--)
    {
        swap_check = 0;
        if (a[j] < a[j-1])
        {   
            a[j] = a[j-1] + a[j];
            a[j-1] = a[j] - a[j-1];
            a[j] = a[j] - a[j-1];
            swap_check = 1;
        }
    }
}

void special_sort(int *a, int size)
{
    while(swap_check)
    {
        insertion_sort(a, size);
        rev_bubble_sort(a, size);
    }

    printf("The sorted list is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {12, 11, 13, 5, 6};
    int size = sizeof(a)/sizeof(*a);
    special_sort(a, size);

    // //rev_bubble_sort(a, size);

    // //insertion_sort(a, size);

    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    return 0;
}
