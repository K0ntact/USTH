#include <math.h>
#include <stdbool.h>

float area(float a, float b, float c)
{
    double area, s;
    s = (a+b+c)/2; //semi parameter
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

bool isTriangle(float a, float b, float c)
{
    if (a+b>c && a+c>b && b+c>a)
        return true;
    else
        return false;
}

bool isRightTri(int a, int b, int c)
{
    if (pow(a,2) + pow(b,2) == pow(c,2) || pow(a,2) + pow(c,2) == pow(b,2) || pow(c,2) + pow(b,2) == pow(a,2))
        return true;
    else
        return false;
}