#include <cassert>
#include <iostream>
#include <cstdint>

template <class Int>
Int gcd(Int a, Int b)
{
    assert(a > 0 && b > 0);

    Int current_gcd = 1;
    for(Int d = 2; d <= a && d <= b; ++d)
        if(a % d == 0 && b % d == 0)
            current_gcd = d;
    return current_gcd;
}

int main()
{
    std::int64_t a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}

//g++-11 -std=c++11 -Wall -Wextra -O2 3_3_2.cpp
//time ./a.out 2 nums: fib(n) == 10^10 ~ 30s