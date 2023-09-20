#include <stdio.h>

int main()
{
    unsigned long long a, b, i, result = 0;
    scanf("%lld %lld", &a, &b);
    for(i = a; i%4 != 0 && i <= b; ++i)
        result ^= i;
    for(i = i == b+1 ? i : b-b%4; i <= b; ++i)
        result ^= i;
    printf("%lld", result);
    return 0;
}