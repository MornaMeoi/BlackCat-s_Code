#include <cassert>
#include <iostream>
#include <unordered_map>

class Fibonacci final
{
public:
    static int get(int n)
    {
        assert (n >= 0);
        
        static std::unordered_map<int, int> cache;
        cache[0] = 0;
        cache[1] = 1;
        for(int i = 2; i <= n; ++i)
            cache[n] = cache[n-1] + cache[n-2];

        return cache[n];
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get(n) << std::endl;
    return 0;
}

//g++-11 -std=c++11 -Wall -Wextra -O2 3_2_3.cpp
//time ./a.out 30000000 ~ 0.037s