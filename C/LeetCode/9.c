//task https://leetcode.com/problems/palindrome-number/
#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main()
{
    int x = 121;
    printf("%d", isPalindrome(x));
    return 0;
}

bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    char num[10];
    int len = 0;
    do
        num[len++] = x%10;
    while (x /= 10);
    for(int i = 0; i < len/2; ++i)
        if(num[i] != num[len-i-1])
            return false;
    return true;
}