#include <math.h>
int product(int n)
{   
    int remainder, quotient;
    int length = floor(log10(n));
    if (length > 1)
        remainder = n%10;
        quotient = floor(n/10);
        return remainder * product(quotient);
    if (length == 1)
    {   
        remainder = n;
        return remainder;
    }
}