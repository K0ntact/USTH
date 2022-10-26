#include <stdio.h>
int main()
{   
    int size, total=0;
    printf("Enter size: ");
    scanf("%d", &size);

    char string[size];
    printf("Enter the string: ");
    scanf("%s", &string);


    //doesnt work
    
    // printf("Location of a in string: \n");
    // for (int i = 0; i<size; i++)
    // {   
    //     if (string[i] == 'a')
    //         total += 1;
    //         printf("%d ", i);
    // }

    if (total == 0)
        printf("None");
    return 0;
}