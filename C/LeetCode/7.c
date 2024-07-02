#include <stdio.h>
#include <string.h>
#include <limits.h>

int reverse(int x)
{
    int sign = x < 0;
    if(x == INT_MIN)
        return 0;
    x = x < 0 ? -x : x;
    char num[10];
    sprintf(num, "%d", x);
    int len = strlen(num);
    long result = 0;

    for(long i = 0, j = 1; i < len; ++i, j *= 10)
        result += (num[i] - '0') * j;
    if(result > INT_MAX || -result < INT_MIN)
        return 0;
    else
        return sign ? -result : result;
}

int main()
{
    int a = 1534236469;
    printf("%d", reverse(a));
    return 0;
}