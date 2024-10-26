#include <cassert>
#include <iostream>
#include <cinttypes>

class Fibonacci final
{
public:
    static uint64_t get(uint64_t n)
    {
        if(n <= 1)
            return n;

        uint64_t previous = 0, current = 1;
        for(uint64_t i = 0; i < n-1; ++i)
        {
            uint64_t new_current = previous + current;
            previous = current;
            current = new_current;
        }
        return current;
    }
};

int main()
{
    uint64_t n;
    std::cin >> n;
    std::cout << Fibonacci::get(n) << std::endl;
    return 0;
}

//g++-11 -std=c++11 -Wall -Wextra -O2 3_2_5.cpp
//time ./a.out 1000000000 ~ 0.533s