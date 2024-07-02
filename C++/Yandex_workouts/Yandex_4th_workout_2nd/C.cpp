#include <iostream>
#include <cstdint>
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
    vector<int> Z(len);
    Z[0] = 0;

    int left = 0, right = 0;
    for(int i = 1; i < len; ++i)
    {
        Z[i] = max(0, min(right-i, Z[i-left]));
        while(i + Z[i] < len && S[Z[i]] == S[i + Z[i]])
            ++Z[i];
        if(i + Z[i] > right)
        {
            left = i;
            right = i + Z[i];
        }
    }

    for(int num : Z)
        cout << num << ' ';
    return 0;
}