//3 kyu task  https://www.codewars.com/kata/5518a860a73e708c0a000027/train/c
//STATUS: failed for now
#include <stdio.h>

/* 
   0 1 5 6 have period=1
   2 3 7 8 have period=4
   4 9     have period=2
*/

int exp_mod_4(int base_last_digs, int exp_mod_4)
{
    for(int i = 0; i < exp_mod_4; ++i)
        base_last_digs *= base_last_digs;
    return base_last_digs%100%4;
}

int base_digit(int base, int exp_mod_4)
{
    for(int i = 0; i < exp_mod_4; ++i)
        base *= base;
    return base%10;
}

int digits_periods(int base_last_digit, int exp_mod_4)
{
    if(base_last_digit == 0 || base_last_digit == 1 || base_last_digit == 5 || base_last_digit == 6)
        return base_last_digit;
    else if(base_last_digit == 2 || base_last_digit == 3 || base_last_digit == 7 || base_last_digit == 8)
        return base_digit(base_last_digit, exp_mod_4);
    else if(base_last_digit == 4 || base_last_digit == 9)
        return base_digit(base_last_digit, exp_mod_4%2);
}

int last_digit(const unsigned long int *arr, size_t arr_size)
{
    int result = arr_size ? arr[arr_size-1]%100%4 : 1;
    for(int i = arr_size-2; i > 0; --i)
        if(arr[i] == 0 && result)
            result = 1;
        else
            result = digits_periods(arr[i]%100, result);
    if(arr[0] == 0 && result == 0)
        result = 1;
    else
        result = arr_size == 1 ? arr[0]%10 : digits_periods(arr[0]%10, result);
    return result;
}

int main()
{
    const unsigned long int nums[] = {0, 0, 0};
    printf("%d\n", last_digit(nums, 3));
    return 0;
}