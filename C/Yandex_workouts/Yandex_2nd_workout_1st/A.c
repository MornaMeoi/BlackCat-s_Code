#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inp = fopen("input.txt", "r");
    int a, b, c, d;
    fscanf(inp, "%d %d %d %d", &a, &b, &c, &d);
    fclose(inp);

    if(!(c == 0 && d == 0))
        if(a == 0)
            if(b == 0)
                printf("INF");
            else
                printf("NO");
        else if(b%a == 0 && (c == 0 || b/a != d/c))
            printf("%d", -b/a);
        else
            printf("NO");
    else
        printf("NO");
    return 0;
}