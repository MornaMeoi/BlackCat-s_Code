#include <cassert>
#include <iostream>
#include <unordered_map>

class Fibonacci final
{
public:
    static int get(int n)
    {
        assert (n >= 0);
        if(n == 0 || n == 1)
            return n;

        static std::unordered_map<int, int> cache;
        auto &result = cache[n];
        if(result == 0)
            result = get(n-1) + get(n-2);
        return result;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get(n) << std::endl;
    return 0;
}

//g++-11 -std=c++11 -Wall -Wextra -O2 3_2_2.cpp
//time ./a.out 1000000 ~ 0.003s
//time ./a.out 5000000 -- Segmentation fault (core dumped)