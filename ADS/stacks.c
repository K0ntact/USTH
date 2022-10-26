#include <stdio.h>

typedef struct _Stack
{
    int data[100];
    int top;    // index of the top element
}Stack;

void init(Stack* I)
{
    I->top = -1;
}

int isEmpty(Stack st)
{
    return st.top < 0;
}

int size(Stack st)
{
    return st.top + 1;
}

int isFull(Stack st)
{
    if (st.top == 99)
    {
        printf("Stack is full");
        return 1;
    }
}

void push(Stack* s, int val)    //aka add to stack
{
    if(isFull(*s)){
        printf("Stack is full");
    }
    else{
        s->top++;
        s->data[s->top] = val;
    }
}

void pop(Stack* s)
{
    if(isEmpty(*s)){
        printf("Stack is empty");
    }
    else{
        s->top--;
    }
}