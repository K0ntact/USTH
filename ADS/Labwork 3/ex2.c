/*
    How ex2.c works:
    1. Takes in string from user
    2. Create a stack to store all temporary characters
    3. pop: works as undo, pop the top character from the string and put it in buffer stack
       push: works as redo, push the top character from the buffer stack and put it in the string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
    char name[100];
    int top;
}stack;

void initStack(stack* n){
    n->top = -1;
    memset(n->name, '\0', 100); //make sure the array is empty
}

void pop(char arr[], stack* s){
    if(strlen(arr) == 0){
        printf("String is empty!\n");
        return;
    }

    //copy the last element of char array, store it in the last position of redo name array
    s->name[strlen(s->name)] = arr[strlen(arr) - 1];

    //delete last element of char array
    arr[strlen(arr) - 1] = 0;
    s->top++;
}

void push(char arr[], stack* s)
{   
    if (s->top == -1)
    {
        printf("Nothing to undo!\n");
        return;
    }

    arr[strlen(arr)] = s->name[strlen(s->name) - 1];
    s->name[strlen(s->name) - 1] = 0;
    s->top--;
}


void main(){
    stack _buffer;
    stack* buffer = &_buffer;

    initStack(buffer);

    char array[100] = {'\0'};
    printf("Enter a string: ");
    fgets(array, 100, stdin);   //takes whole sentence, not just a word like scanf
    array[strcspn(array, "\n")] = 0;

    int choice;
    printf("1. Undo\n2. Redo\n3. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);
    while (choice != 3)
    {
        switch (choice)
        {
        case 1:
            pop(array, buffer);
            printf("Current string: %s\n", array);
            break;
        case 2:
            push(array, buffer);
            printf("Current string: %s\n", array);
            break;
        default:
            printf("Invalid number\n");
            break;
        }
        printf("1. Undo\n2. Redo\n3. Exit\n");
        scanf("%d", &choice);
    }
}