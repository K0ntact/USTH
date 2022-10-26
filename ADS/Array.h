#include <stdio.h>

struct _List
{
    int size;
    int data[1000];
};

typedef struct _List List;

void init(List* I)     //List *I is a pointer to a List
{
    I->size = 0;    // I->size is the same as (*I).size
}

int isEmpty(List *I)
{
    return I->size == 0;
}

int Length(List *I)
{
    return I->size;
}

void add(List *I, int location, int value)
{
    if (Length(I) == 1000)   //if the list is full (data limit is 1000)
        printf("Cannot add more value!\n");
    if (location<0 || location>I->size)  //if the location is invalid
        printf("Invalid location!\n");
    else
    {
        for (int i = I->size; i>location; i--)
            I->data[i] = I->data[i - 1];
        I->data[location] = value;
        I->size++;
    }
}

void Remove(List *I, int location)
{
    if (isEmpty(I))   //if the list is empty
        printf("Cannot remove value!\n");
    if (location<0 || location>I->size)  //if the location is invalid
        printf("Invalid location!\n");
    else
    {
        for (int i = location; i<I->size; i++)
            I->data[i] = I->data[i + 1];
        I->size--;
    }
}

void Display(List *I)
{   
    if (Length(I) == 0)
        printf("Element is empty!\n");
    for(int a = 0; a < I->size; a++)
    {
        printf("Element %d: %d\n", a, I->data[a]);
    }
}