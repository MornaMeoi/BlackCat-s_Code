//Task: https://leetcode.com/problems/string-compression/
//Difficulty: Medium
#include <bits/stdc++.h>

using namespace std;

int compress(vector<char>& chars)
{
    size_t left = 0, right = 1, str_idx = 0;
    for(; right < chars.size(); ++right)
    {
        if(chars[left] != chars[right])
        {
            chars[str_idx++] = chars[left];
            if(right - left > 1)
            {
                string amount = to_string(right - left);
                for(size_t i = 0; i < amount.size(); ++i)
                    chars[str_idx++] = amount[i];
            }
            left = right;
        }
    }
    chars[str_idx++] = chars[left];
    if(right - left > 1)
    {
        string amount = to_string(right - left);
        for(size_t i = 0; i < amount.size(); ++i)
            chars[str_idx++] = amount[i];
    }
    chars.resize(str_idx);
    return chars.size();
}

int main()
{
    ifstream inp("input.txt");
    vector<char> symbols;
    inp.ignore(2);
    while(!inp.eof())
    {
        char symb;
        inp >> symb;
        symbols.push_back(symb);
        inp.ignore(3);
    }
    inp.close();

    cout << compress(symbols) << endl;
    for(char symb : symbols)
        cout << symb;
    cout << endl;
    return 0;
}