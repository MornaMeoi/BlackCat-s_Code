//task https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/?envType=list&envId=rb946505
#include <iostream>
#include <string>

using namespace std;

string freqAlphabets(string s);

int main()
{
    string word = "10#11#12";
    cout << freqAlphabets(word) << endl;
    return 0;
}

string freqAlphabets(string s)
{
    string result;
    for(int i = 0; i < s.size(); ++i)
    {
        if(i+2 < s.size() && (s[i] == '1' || s[i] == '2') && s[i+2] == '#')
        {
            result += 'j' + s[i+1] - '0' + (s[i] - '1') * 10;
            i += 2;
        }
        else
            result += 'a' + s[i] - '1';
    }
    return result;
}