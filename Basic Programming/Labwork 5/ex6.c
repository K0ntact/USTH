#include <stdio.h>
#include <string.h>
int main()
{   
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    char string[size];
    printf("Enter the string: ");
    scanf("%s", &string);

    printf("%s", strrev(string));

    return 0;
}