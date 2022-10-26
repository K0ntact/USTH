// ● For people that are using Google Meet, they usually will
// be given a meeting code such as: sjg-wked-cnf
// Given a string in that format (3-4-3, 10 charaters) erase
// the ‘-’ charater to get the simplified code.

#include <stdio.h>
#include "ex2_strrem.h"

void main()
{
    char string[50];
    char re;

    printf("Enter string: ");
    scanf("%s", &string);

    printf("Enter character needs to remove: ");
    scanf(" %c", &re);

    charremover(string, re);
    printf("Result: %s", string);
}