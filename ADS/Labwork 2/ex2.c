#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Node
{   
    int passenger;
    char name[100];
    struct Node* next;   //pointer to next car
}car;


typedef struct List
{
    int size;
    car* head;  //pointer to head of the list
}train;

car* initCar(int a, char arr[])
{   
    car* C = (car*)malloc(sizeof *C);
    C->passenger = a;
    strcpy(C->name, arr);   //must use strcpy to assign string to array
    C->next = NULL;
    return C;
}

void init(train* T)
{
    T->size = 0;
    T->head = NULL;
}


int isEmptyList(train* T)
{
    return T->size==0;
}

void insertFirst(train* T, car* newC)   //insert first node of list
{
    if(isEmptyList(T))
    {   
        T->head = newC;
        T->size++;
    }
}

void insert(car* newC, car* C, train* T)    //insert newC after C
{   
    newC->next = C->next;
    C->next = newC;
    T->size++;
}

void delEmptyCar(train* T)
{
    assert(!isEmptyList(T));    //run if list not empty
    car* temp = T->head;
    car* prev = T->head;
    int count = 0;

    while(temp != NULL) //assure that the loop stop at list tail
    {
        if(temp->passenger == 0)
        {
            if(temp == T->head) //head node is 0
            {
                T->head = temp->next;
                free(temp);
                temp = T->head;
                prev = T->head;
                T->size--;
            }

            else    //other node is 0
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
                T->size--;
            }
        }

        else    //if temp is not 0, move to next node
        {
            prev = temp;
            temp = temp->next;
        }
    }
}

void display(train* T)  
{   
    int count = 0;
    //printf("1: %d\n", T);
    delEmptyCar(T);
    //printf("2: %d\n", T);
    //printf("\nSize of train: %d\n", T->size);
    if(isEmptyList(T))
    {
        printf("Train is empty");
    }
    else
    {
        car* C0 = T->head;  //must put after delEmptyCar, because T->head may change
        while (count < T->size)
        {
            printf("Car %d:\n Name: %s, %d passengers\n", count, C0->name, C0->passenger);
            C0 = C0->next;
            count++;
        }
        printf("\nSize of train: %d\n", T->size);
    }
}

void main(char argc, char* argv[])
{
    train T;
    train* A = &T;
    init(A);
    //printf("\nSize of train: %d\n", A->size);

    // BUG IF ALL CAR PASSENGER = 0, OR IF THE ONLY CAR IN LIST PASSENGER = 0

    //adding cars
    car* C1 = initCar(12, "AE"); 
    insertFirst(A, C1);
    car* C2 = initCar(3, "B");
    insert(C2, C1, A);
    car* C3 = initCar(0, "C");    //empty car, delete
    insert(C3, C2, A);
    car* C4 = initCar(6, "D");
    insert(C4, C3, A);
    car* C5 = initCar(0, "E");    //empty car, delete
    insert(C5, C4, A);
    car* C6 = initCar(0, "F");    //empty car, delete
    insert(C6, C5, A);
    car* C7 = initCar(1, "G");
    insert(C7, C6, A);
    car* C8 = initCar(0, "H");    //empty car, delete
    insert(C8, C7, A);

    //displaying cars and train length
    display(A);
}