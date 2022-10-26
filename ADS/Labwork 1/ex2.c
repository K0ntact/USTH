//Pseudocode
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
// 	loop (from i=1 to i<=n)
// 		if (sphenic_check(i) == true)
// 			print("i")
// 	endloop

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//check comments at Labwork 1 ex1.c
bool prime_check(int x)
{   
    int count = 0;
    for (int i = 2; i<=x/2; i++)
    {
        if (x % i == 0)
        {
            count++;
            break;
        }
    }
    return count == 0;
} 

bool sphenic_check(int x)
{
    int count = 2, prime = 0;
    for (int i = 2; i<=x/2; i++)
    {
        if (x % i == 0)
        {
            count++;
            if(prime_check(i) == true)
            {
                prime++;
            }
        }
    }
    return (count == 8 && prime == 3);
}



void main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 1; i<=n; i++)
    {
        if(sphenic_check(i) == true)
        {
            printf("%d ",i);
        }
    }
}
//total complexity: O(n^3) because of 3 loops