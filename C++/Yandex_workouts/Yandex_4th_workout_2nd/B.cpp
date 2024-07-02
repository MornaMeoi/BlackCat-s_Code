#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    string S;
    inp >> S;
    inp.close();

    int len = S.size();
    vector<int64_t> part_sum(len+1, 0);
    for(int i = 1; i < part_sum.size(); ++i)
    {
        int64_t hash = 0;
        if(S[i-1] >= 'A' && S[i-1] <= 'Z')
            hash = S[i-1] - 'A' + 1;
        else
            hash = S[i-1] - 'a' + 27;
        part_sum[i] = part_sum[i-1] + hash;
    }

    int i = 1;
    for(; i < len; ++i)
    {
        bool good = true;
        if(len%i != 0)
        {
            if(part_sum[len] - part_sum[len/i*i] == part_sum[len%i] - part_sum[0])
            {
            for(int j = 0; good && j < len%i; ++j)
                if(S[j] != S[len/i*i+j])
                    good = false;
            }
            else
                good = false;
        }
        int64_t hash = part_sum[i] - part_sum[0];
        for(int j = i; good && (j + i <= len); j += i)
            if(part_sum[j+i] - part_sum[j] != hash)
                good = false;
        for(int j = 0; good && j < i; ++j)
            for(int k = j+i; good && k < len/i * i; k += i)
                if(S[k] != S[j])
                    good = false;
        if(good)
            break;
    }
    cout << i;
    return 0;
}