#include <iostream>
#include <fstream>
#include <string>
#include <cinttypes>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    string S;
    inp >> S;
    inp.close();

    uint64_t len = S.size(), j = 0, result = len;
    for(; j < len-2; ++j)
    {
        if(S[j] == S[j+2] && S[j] != S[j+1])
            for(int first = j, second = j+2; first >= 0 && second < len && S[first] == S[second]; --first, ++second)
                ++result;
        else if(S[j] == S[j+1])
        {
            int current = j;
            for(;j < len-1 && S[j] == S[j+1]; ++j);
            result += (j-current)*(j-current+1)/2;
            for(int first = current-1, second = j+1; first >= 0 && second < len && S[first] == S[second]; --first, ++second)
                ++result;
            --j;
        }
    }
    if(j == len-2)
        result += S[len-2] == S[len-1];
    cout << result;
    return 0;
}