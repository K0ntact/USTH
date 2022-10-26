#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum = 0;
int recuSum(int n)
{
    if(n<10)
    {
        return sum+n;
    }
    else{
        sum += n%10;
        return recuSum(n/10);
    }
}

int main()
{   
    int num;
    printf("Give number: ");
    scanf("%d", &num);
    printf("Digit sum: %d", recuSum(num));
}
//Total complexity: O(1)