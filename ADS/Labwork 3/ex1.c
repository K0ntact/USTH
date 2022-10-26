// How it should works:
// 1. Add items and their stock
// 2. Add customer
// 3. Start dequeue

// Extra features: remove a product, display all product and their stock

// I will use: 
//  + Linked list to store product information
//  + Linked list queue for customer queue

// Item linked list
//   addpord: Recieve products (including name and stock)
//   removeprod: Remove the product specified
//   displayprod: Print out all products and their quantity
//                Warn the user if a product is out of stock

// Linked list queue
//   enqueue: Takes in product to buy and how many
//   dequeue: Remove the first customer in the queue, decrease the stock of the product bought
//   runqueue: Run the queue and print out the receipt



#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//====================================================================
//                        ITEM LINKED LIST
//====================================================================

typedef struct node
{
    int quantity;
    char name[100];
    struct node* next;
}item;

item* head = NULL;

int length(){
    int c=0;
    item *temp=head;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

void addprod()  //initialize and add item to end of list
{   
    int d;
    char name[100] = {"\0"};
    item* temp;

    printf("Enter product name: ");
    fgets(name, 100, stdin);    //fgets will take in the newline character as well
    name[strcspn(name, "\n")] = 0;   //remove newline character
    //strcspn counts the number of characters until it hits "\n" 

    printf("Enter quantity: ");
    scanf("%d", &d);

    item* newnode=(item *)malloc(sizeof(item));
    newnode->quantity = d;
    strcpy(newnode->name,name);
    newnode->next = NULL;

    if(head==NULL)
    {
        head = newnode;
        return; //break after adding first item, no else needed
    }
    
    temp = head;

    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void removeprod()
{
    item *prev,*temp;
    temp = head;
    prev = head;
    char name[100];

    printf("Remove product: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    while(temp!=NULL){
        if(strcmp(temp->name,name) == 0){
            if(temp == head){
                printf("%s removed\n",temp->name);
                head = temp->next;
                free(temp);
                temp = head;
                prev = head;
            }
            else{
                printf("%s removed\n",temp->name);
                prev->next = temp->next;
                free(temp);
                temp = prev->next;    
            }
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
}

void displayprod()
{
    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
    }

    item *temp=head;
    printf("Total number of products: %d\n", length());
    while(temp!=NULL)
    {
        if(temp->quantity == 0){
            printf("Out of stock: %s\n", temp->name);
            break;
        }
        else{
            printf("%s: %d left\n",temp->name, temp->quantity);
            temp=temp->next;
        }
    }
}

//====================================================================
//                        LINKED LIST QUEUE
//====================================================================

typedef struct Node{
    char prodname[100];
    int quantity;
    struct Node* next;
}custm;

custm* front = NULL;
custm* back = NULL;

void enqueue()
{   
    //initialize custm node
    int quant;
    char prodname[100] = {"\0"};

    printf("Enter product to buy: ");
    fgets(prodname, 100, stdin);
    prodname[strcspn(prodname, "\n")] = 0;
    printf("Enter quantity: ");
    scanf("%d", &quant);
    
    custm* temp = front;

    custm* new = (custm *)malloc(sizeof(custm));
    new->quantity = quant;
    strcpy(new->prodname, prodname);
    new->next = NULL;

    //add node to end of list
    if(front == NULL)
    {
        front = new;
        back = new;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    back = new;
}

int dequeue(custm* ctemp)
{
    //run a loop through item list
    //ctemp = front;
    item* itemp = head;
    while (itemp != NULL)
    {   
        //if the prod is found & enough in stock, decrease prod quantity, free custm*
        if ((strcmp(ctemp->prodname, itemp->name) == 0) && (ctemp->quantity <= itemp->quantity))
        {   
            itemp->quantity -= ctemp->quantity; //decrease number of prod by quantity bought
            front = ctemp->next;
            free(ctemp);    //dequeue the customer

            if(itemp->quantity == 0)    
            {
                printf("Out of stock: %s\n", itemp->name);
            }
            
            return 1;
        }
        
        itemp = itemp->next;

    }
    //if prod not enough/not found, also dequeue that customer
    front = ctemp->next;
    free(ctemp);
    return 0;
}

void runqueue()
{
    //loop through customer queue
    custm* temp = front;
    printf("%s\n", temp->prodname);
    while (temp != NULL)
    {
        if(dequeue(temp))
        {   
            //print out garbage product name at the first customer?
            printf("%s sold %d items\n", temp->prodname, temp->quantity);
        }
        temp = temp->next;
    }
    printf("End of queue\n");
}

//====================================================================
//                         MAIN FUNCTION
//====================================================================

void main()
{   
    int choice;
    printf("0-Exit  1-Add item  2-Display items  3-Remove product\n");
    printf("4-Add customer  5-Start dequeue\n");
    scanf("%d", &choice);
    fflush(stdin);  //clear newline char left in stdin by scanf, so fgets works

    while(choice != 0){
        switch(choice){
            default:
                printf("Invalid choice\n");
            case 1:
                addprod();
                break;
            case 2:
                displayprod();
                break;
            case 3:
                removeprod();
                break;
            case 4:
                enqueue();
                break;
            case 5:
                runqueue();
                break;
        }
        printf("\n0-Exit  1-Add item  2-Display items  3-Remove product\n");
        printf("4-Add customer  5-Start dequeue\n");
        scanf("%d", &choice);
        fflush(stdin);
    }
}