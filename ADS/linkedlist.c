#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int data;
    struct _Node* pnext;
}Node;


typedef struct _List{
    int size;
    Node* pHead;
}List;

void init(List* I)
{
    I->size = 0;
    I->pHead = NULL;
}

Node* initNode(int val) //returns a Node pointer, hence Node*
{
    Node* a = (Node*)malloc(sizeof *a);
    a->data = val;
    return a;
}

void _remove(List* I, int val)
{
    Node* p = I->pHead;     //creates a pointer to the head of the list
    if (p->data == val)
    {
        I->pHead = p->pnext;
        free(p);    //delete head node
        I->size--;
        return;
    }

    //pointer to pointer to pointer to pointer to pointer to value because why not
    Node* q = p->pnext; 
    int cnt = 1;
    while (cnt < I->size) //loop until the node is found (if there are any left)
    {
        p = q;
        q = q->pnext;
        cnt++;
        //if the node is found, remove it
        if (p->data == val)
        {
            p->pnext = q->pnext;
            free(q);
            I->size--;
            return;
        }
    }
}

int isEmpty(List* I)
{
    return I->size == 0;
}

void insertFirst(Node* pnew, List* I)   //insert the first node of list
{
    if(isEmpty(I))
    {
        I->pHead = pnew;
        I->size++;
    }
}

void insert(Node* pnew, Node* ptr, List* I) //insert to anywhere on list
        //new node, the node before, and the list
{
    pnew->pnext = ptr->pnext;   
    ptr->pnext = pnew;
    I->size++;
}

void display(List* I)
{
    Node* p = I->pHead;
    int cnt = 0;
    while (cnt < I->size)
    {
        printf("%d ", p->data);
        p = p->pnext;
        cnt++;
    }
}
void main()
{
    List A;
    List* B = &A;
    init(B);
    Node* n1 = initNode(1); //initialize n1 with value = 1
    insertFirst(n1, B); //insert node n1 to head of list B
    Node* n2 = initNode(2);
    insert(n2, n1, B);  //insert node n2 after node n1
    Node* n3 = initNode(3);
    insert(n3, n2, B);  //insert node n3 after node n2
    display(B);
}