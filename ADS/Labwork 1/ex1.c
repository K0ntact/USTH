//Pseudocode:
// function prime_check
// 	input n
// 	loop (from i = 2 to i<=x/2)
// 		if (n%i == 0)
// 			return false
// 		i = i + 1
// 	endloop
// 	return true

// function sphenic_check
// 	input x
// 	count = 2; prime = 0
// 	loop (from i=2 to i<=x/2)
// 		if (x%i == 0)
// 			count = count + 1
// 			if (prime_check(i) == true)
// 				prime = prime + 1
// 	endloop
// 	if (count == 8 and prime == 3)
// 		return true
// 	else
// 		return false

// function main
// 	input n
// 	if (sphenic_check(n) == true)
// 		print("N is a sphenic number")
// 	else
// 		print("N is not a sphenic number")

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
//complexity: O(n)


int sphenic_check(int x)
{
    int count = 2, prime = 0; //count = 2 because every number is divisible by 1 and itself
    for (int i = 2; i<=x/2; i++)
    {
        if (x % i != 0)
        {
            return 0;
        }
        
        count++;
        if(prime_check(i))
        {
            prime++;
        }
    }
    return (count == 8 && prime == 3);
}
//complexity: O(n^2)


void main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if(sphenic_check(n))
    {
        printf("%d is a sphenic number\n",n);
    }
    else
    {
        printf("%d is not a sphenic number\n",n);
    }
}

//total complexity = O(n^2)