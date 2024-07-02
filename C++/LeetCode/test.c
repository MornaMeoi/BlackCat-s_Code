#include <stdio.h>

int main()
{
    char symb;
    while(scanf("%c\b", &symb) == 1 && symb != '\n')
        printf("%c", symb);
    printf("\n");
    scanf("\b\r");
    while(scanf("%c", &symb) == 1 && symb != '\n')
        printf("%c", symb);
    return 0;
}