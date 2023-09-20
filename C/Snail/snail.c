#include <stdio.h>

int main()
{
    int h, a, b;
    scanf("%d %d %d", &h, &a, &b);
    printf("%d", (h/(a+1)+h-1)/h * ((h-a-1)/(a-b)+2) + (a/h+a-1)/a);
    return 0;
}