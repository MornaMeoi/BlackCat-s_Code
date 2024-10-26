#include <cassert>
#include <iostream>
#include <vector>

class Fibonacci final
{
public:
    static int get(int n)
    {
        assert (n >= 0);
        
        static std::vector<int> cache(n+1);
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

//g++-11 -std=c++11 -Wall -Wextra -O2 3_2_4.cpp
//time ./a.out 1000000000 ~ 1.6s