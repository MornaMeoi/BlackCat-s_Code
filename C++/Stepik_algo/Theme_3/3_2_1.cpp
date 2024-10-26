#include <cassert>
#include <iostream>

class Fibonacci final
{
public:
    static int get(int n)
    {
        assert (n >= 0);
        if(n == 0 || n == 1)
            return n;
        return get(n-1) + get(n-2);
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get(n) << std::endl;
    return 0;
}

//g++-11 -std=c++11 -Wall -Wextra -O2 3_2_1.cpp
//time ./a.out 47 ~ 10s