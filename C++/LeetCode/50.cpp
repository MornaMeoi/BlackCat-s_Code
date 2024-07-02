#include <iostream>

using namespace std;

double myPow(double x, int n)
{
    bool sign = n > 0;
    double result = 1;
    n = abs(n);
    while(n > 0)
    {
        if(n % 2 == 1)
            result *= x;
        x *= x;
        n /= 2;
    }
    return sign ? result : 1 / result;
}

int main()
{
    cout << myPow(2, -2);
    return 0;
}