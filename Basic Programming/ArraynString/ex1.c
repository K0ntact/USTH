// Input a string s from the keyboard, then:
// ● Calculates the size of that string (in charaters)
// ● Insert string “usth” in the end of that string

#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);

    int size;
    size = strlen(string);
    printf("Size of string is: %d \n", size);

    printf("%s", strcat(string, "usth"));

    return 0;
}