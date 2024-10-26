#include <cassert>
#include <iostream>
#include <cstdint>
#include <utility>

template <class Int>
Int gcd(Int a, Int b)
{
    assert(a > 0 && b > 0);

    while(b > 0)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main()
{
    std::int64_t a, b;
    std::cin >> a >> b;
    const int RUNS_COUNT = 1'000'000;
    for(int i = 0; i < RUNS_COUNT; ++i)
        gcd(a, b);
    std::cout << gcd(a, b) << std::endl;
    return 0;
}

//g++-11 -std=c++11 -Wall -Wextra -O2 3_3_5.cpp
//time ./a.out 1'000'000 gcd of 2 nums: fib(n) == 10^18 ~ 1.03s