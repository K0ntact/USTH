#include <stdio.h>
#include <math.h>

typedef struct Polynominal
{   
    int term;
    int constant[1000];
    int degree[1000];
}poly;

int checkExists(poly* A, int n)       //check if degree n exists in polynominal A
{   
    for (int i = 0; i < A->term; i++)
    {
        if (n == A->degree[i])      //if there is degree n in poly
            return 1;               //return 1, which works as true boolean value                 
    }
    return 0;
}

int checkLoc(poly* A, int n)        //return the location if the degree exists
{
    if(checkExists(A, n))
    {
        for (int i = 0; i < A->term; i++)
        {
            if (n == A->degree[i])
                return i;
        }
    }
}

void init(poly* A)
{
    A->term = 0;    //initialize Polynominal A with 0 term
}

int isEmpty(poly* A)
{
    return A->term == 0;
}

int length(poly* A)
{
    return A->term;
}

void termadd(poly* A, int con, int deg)
{
    if (A->term == 1000)
        printf("Limit reached!");
    else if (checkExists(A, deg))      //0 = false, 1 = true
        {
            A->constant[checkLoc(A,deg)] += con;   //If true, the constant at the location of old degree += new constant
        }
    else
        {
            A->degree[A->term] = deg;
            A->constant[A->term] = con;
            A->term++;
        }
}

void _remove(poly* A, int deg)   //Remove the term with included degree
{
    if (isEmpty(A))
        printf("Cannot remove value!\n");
    else
    {
        for (int i = checkLoc(A, deg); i < A->term; i++)        //use checkLoc() to find location of the degree to remove
        {          
            A->degree[i] = A->degree[i+1];      
            A->constant[i] = A->constant[i+1];
        }
        A->term--;
    }
}

int display(poly* A)    
{   
    if (length(A) == 0)
    {
        printf("Polynominal is empty!\n");
        return 0;
    }
    
    printf("Polynominal: ");
    for(int a = 0; a <= A->term - 2; a++)    //run to 2nd term before the end because we dont want " + " sign in the end
    {   
        if (A->constant[a] == 0)    //if constant is 0, dont print it
            continue;
        else if (A->degree[a] == 0)     //if degree is 0, dont print it
            printf("%d + ", A->constant[a]);
        else if (A->degree[a] == 1)     //if degree is 1, dont print the degree
            printf("%dx + ", A->constant[a]);
        else
            printf("%dx^%d + ", A->constant[a], A->degree[a]);  
    }
    printf("%dx^%d\n", A->constant[A->term - 1], A->degree[A->term - 1]);
        

}

float calculate(poly* A, int x)
{
    int total = 0;
    for(int i = 0; i < A->term; i++)
    {
        total += A->constant[i] * pow(x,A->degree[i]);
    }
    return total;
}

int main()
{   
    poly B;
    poly* A = &B;
    init(A);
    termadd(A, 4, 5); //should print 4x^5
    //_remove(A, 4);
    termadd(A, 4, 5);
    termadd(A, 0, -6);
    termadd(A, -13, 8);
    display(A);
    printf("Total x=6: %.2f", calculate(A, 6));
    return 0;
}