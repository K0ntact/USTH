#include <stdio.h>
#include <stdlib.h>

/*
    I will use static array list to store the data because it's easier to implement and its
    behaviour is very similar to normal array, so i don't have to edit the sorting algorithm much.
*/

typedef struct List{
    int size;
    int data[1000];
} list;

void init(list *l){
    l->size = 0;
}

void add(list *l, int value){
    l->data[l->size] = value;
    l->size++;
}

void print(list *l){
    for(int i = 0; i < l->size; i++){
        printf("%d ", l->data[i]);
    }
    printf("\n");
}

int swap_check = 1;
void insertion_sort(list* l)
{   
    for( int i = 0; i < l->size ; i++ ) {
        int temp = l->data[i];    
        int j = i;
        swap_check = 0;

        while(j > 0  && temp < l->data[j -1]) {

            l->data[j] = l->data[j] + l->data[j-1];
            l->data[j-1] = l->data[j] - l->data[j-1];
            l->data[j] = l->data[j] - l->data[j-1];  
            j = j - 1;
            swap_check = 1;
        }
        l->data[j] = temp;       
    }  
}

void rev_bubble_sort(list* l)
{
    for (int j = l->size - 1; j > 0; j--)
    {
        swap_check = 0;
        if (l->data[j] < l->data[j-1])
        {   
            l->data[j] = l->data[j-1] + l->data[j];
            l->data[j-1] = l->data[j] - l->data[j-1];
            l->data[j] = l->data[j] - l->data[j-1];
            swap_check = 1;
        }
    }
}

void special_sort(list* l)
{
    while(swap_check)
    {
        insertion_sort(l);
        rev_bubble_sort(l);
    }

    printf("The sorted list is: ");
    for (int i = 0; i < l->size; i++)
    {
        printf("%d ", l->data[i]);
    }
    printf("\n");
}

int main()
{
    list l;
    list* a = &l;
    init(a);
    add(a, 5);
    add(a, 4);
    add(a, 7);
    add(a, 0);
    add(a, 9);
    special_sort(a);
    return 0;
}