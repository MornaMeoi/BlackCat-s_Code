#include <iostream>
#include <vector>
#include <cinttypes>

using namespace std;

int main()
{
    uint64_t X;
    cin >> X;
    
    vector<uint64_t> squares(X), cubes(X), result(X);
    for(uint64_t i = 1; i <= X; ++i)
    {
        squares[i-1] = i*i;
        cubes[i-1] = i*i*i;
    }
    for(int i = 0, first = 0, second = 0; i < X; ++i)
    {
        if(first < X && squares[first] == cubes[second])
        {
            ++first;
            --i;
        }
        else if(first < X && squares[first] < cubes[second])
            result[i] = squares[first++];
        else
            result[i] = cubes[second++];
    }
    cout << result[X-1];
    return 0;
}