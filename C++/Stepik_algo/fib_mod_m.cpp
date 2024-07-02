#include <iostream>
#include <vector>

int get_remainder(long long n, int m)
{
    std::vector<int> fibs = {0, 1};
    for(int i = 2; i <= n; ++i)
    {
        fibs.push_back((fibs[i-1] + fibs[i-2]) % m);
        if(fibs[i] == 1 && fibs[i-1] == 1 && fibs[i] == 0)
            return fibs[n % (i-3)];
    }
    return fibs[n];
}

int main()
{
    std::cout << get_remainder(10, 4);
    return 0;
}