// ● Considers the side lengths of a triangle as an array [a, b,c], input these values and:
// ● Find the area of that triangle
// ● Check if that triangle is normal or right

#include <stdio.h>
#include "ex3_triangle.h"
void main()
{
    float a,b,c;
    printf("Enter lengths of 3 sides: ");
    scanf("%f%f%f", &a, &b, &c);
    if (isTriangle(a,b,c))
    {
        if (isRightTri(a,b,c))
            printf("This is a right triangle \n");
        else
            printf("This is not a right triangle \n");
        printf("Area of triangle: %.2f", area(a,b,c));
    }
    else
        printf("Not a triangle");
}