#include <iostream>

using namespace std;

string countAndSay(int n)
{
    if(n == 1)
        return "1";
    else
    {
        string result = "", prev = countAndSay(n - 1);
        int repeats = 1;
        for(int i = 1; i < prev.size(); ++i)
        {
            if(prev[i] == prev[i-1])
                ++repeats;
            else
            {
                result.push_back(repeats + '0');
                result.push_back(prev[i-1]);
                repeats = 1;
            }
        }
        result.push_back(repeats + '0');
        result.push_back(prev[prev.size()-1]);
        return result;
    }
}

int main()
{
    cout << countAndSay(3);
    return 0;
}