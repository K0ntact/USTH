/* 
    Pseudocode: 

    function digitSum(int n)
        int sum = 0
        while n > 0:
            sum = sum + n mod 10
            n = n / 10
        end
        return sum
    end

    function main
        int n
        print "Enter a number"
        n = input

        print "Sum of digits: "
        print digitSum(n)
    end
*/

#include <stdio.h>

int digitSum(int n)
{
    int sum = 0;
    while(n>0)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

void main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum of digits: %d", digitSum(n));
}