#include <iostream>
#include <limits>

using namespace std;

int divide(int dividend, int divisor)
{
    int result = 0, sign = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
    if(divisor == numeric_limits<int>::min())
        if(dividend == numeric_limits<int>::min())
            return 1;
        else
            return 0;
    divisor = abs(divisor);
    if(divisor == 1)
    {
        if(dividend == numeric_limits<int>::min())
            return numeric_limits<int>::max();
        return (sign ? -1 : 1) * abs(dividend);
    }
    dividend = abs(dividend);
    while((dividend -= divisor) >= 0)
        ++result;
    return sign ? -result : result;
}

int main()
{
    cout << divide(numeric_limits<int>::min(), -1);
    return 0;
}