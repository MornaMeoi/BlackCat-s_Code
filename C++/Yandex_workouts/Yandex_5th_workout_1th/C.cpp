#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N, spaces, remaining;
    uint64_t result = 0;
    inp >> N;
    for(int i = 0; i < N; ++i)
    {
        inp >> spaces;
        result += spaces / 4;
        remaining = spaces % 4;
        if(remaining)
            result += remaining / 2 + 1;
    }
    inp.close();
    cout << result;
    return 0;
}