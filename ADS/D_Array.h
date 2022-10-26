#include <stdio.h>
#include <stdlib.h>

struct _DList
{
    int size;
    int capacity;
    int *p;
};

typedef struct _DList DList;

void init(DList *I, int N)     //List *I is a pointer to a List
{
    I->size = 0;    // I->size is the same as (*I).size
    I->capacity = N;   
    I->p = (int *)malloc(N * sizeof(int));
}

int isEmpty(DList *I)
{
    return I->size == 0;
}

int Length(DList *I)
{
    return I->size;
}
