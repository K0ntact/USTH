/* 
    Main idea:
    given input is n

    find all prime from 0 to n, store them in a dynamic array

    runs through the list recursively, find all 3 number permutations

    check the product of each permutations, break when:
        product > n => n is not sphenic
        product = n => n is sphenic
*/

#include <stdio.h>
#include <stdlib.h>

int prime_check(int x)
{   
    for (int i = 2; i<=x/2; i++) // starts from 2 because every number is divisible by 1 and itself
    {
        if (x % i == 0)
        {
            return 0; // break out of the loop if the number has a divisor that isn't 1 or itself, therefore is not a prime
        }
    }
    return 1;
}

int* a;
int prime_arr(int x)   //assign prime array to pointer a, returns number of prime in array
{   
    int* primearr = (int*)malloc(10*sizeof(int));
    int size = 10; //max size of primearr
    int count = 0;
    for (int i = 2; i <= x/2; i++) //we only need prime from 1 to x/6. Explaination in main idea
    {   
        if (count == size)  //if array is full, reallocate memory
        {
            size = size*2;
            primearr = (int*)realloc(primearr, size*sizeof(int));
        }
        if (prime_check(i))
        {
            primearr[count] = i; //add prime to prime array
            count++;
        }
    }
    a = primearr;
    return count;
}


int isSphenic(int x, int length, int i, int j, int k)
{   
    if (x < 30)
    {
        return 0;
    }
    if (a[i] * a[j] * a[k] == x)
    {   
        printf("i: %d\n", a[i]);
        printf("j: %d\n", a[j]);
        printf("k: %d\n", a[k]);
        return 1;
    }
    else if (a[i] * a[j] * a[k] > x)
    {   
        //print array a
        for (int i = 0; i < length; i++)
        {
            printf("%d ", a[i]);
        }
        return 0;
    }
    
    //loop through all 3-permutations of prime array
    else{
        if (k < length - 1)
        {
            return isSphenic(x, length, i, j, k+1);
        }
        else if (j < length - 2)
        {
            return isSphenic(x, length, i, j+1, j+2);
        }
        else if (i < length - 3)
        {
            return isSphenic(x, length, i+1, i+2, i+3);
        }
    }
}

//Total complexity: O(n^3)

void main()
{
    int n;
    int len;
    printf("Enter n: ");
    scanf("%d", &n);
    len = prime_arr(n);
    if (isSphenic(n, len, 0, 1, 2)){
        printf("%d is sphenic\n", n);
    }
    else{
        printf("\n%d is not sphenic\n", n);
    }
}
