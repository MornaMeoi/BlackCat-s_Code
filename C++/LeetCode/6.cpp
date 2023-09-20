//https://leetcode.com/problems/zigzag-conversion/
#include <iostream>

using namespace std;

string convert(string s, int numRows);

int main()
{
    string encoded;
    int num;
    cin >> encoded >> num;
    cout << convert(encoded, num);
    return 0;
}

string convert(string s, int numRows)
{
    string decoded(s.size(), ' ');
    for(int i = 0; i < numRows; ++i)
    {
        if(i == 0 || i == numRows-1)
            cout << s[2*i*(numRows-1)];
        else
            cout << s[2*i*(numRows-1)-i] << s[2*i*(numRows-1)+i];
    }
}