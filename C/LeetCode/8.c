#include <stdio.h>
#include <string.h>
#include <limits.h>

int myAtoi(char* s)
{
    while(*s == ' ')
        ++s;
    int sign = 0;
    if(*s == '-' || *s == '+')
    {
        if(*s == '-')
            ++sign;
        ++s;
    }
    while(*s == '0')
        ++s;
    for(int i = 0; s[i] != '\0'; ++i)
        if(!(s[i] >= '0' && s[i] <= '9'))
        {
            s[i] = '\0';
        }

    int len = strlen(s);
    if(len > 10)
        if(sign)
            return INT_MIN;
        else
            return INT_MAX;
    
    long result = 0;
    for(long i = len-1, j = 1; i >= 0; --i, j *= 10)
        result += (s[i] - '0') * j;
    result = sign ? -result : result;
    if(result > INT_MAX)
        return INT_MAX;
    else if(result < INT_MIN)
        return INT_MIN;
    else
        return result;
}

int main()
{
    printf("%d", myAtoi("-143243243223"));
    return 0;
}