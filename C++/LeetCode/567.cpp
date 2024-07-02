//task https://leetcode.com/problems/permutation-in-string/?envType=list&envId=rb946505
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isMapsEqual(map<char, int>& lhs, map<char, int>& rhs);
bool checkInclusion(string s1, string s2);

int main()
{
    string s1 = "ab", s2 = "eidboaoo";
    cout << checkInclusion(s1, s2);
    return 0;
}

bool isMapsEqual(map<char, int>& lhs, map<char, int>& rhs)
{
    for(auto const& [key, value] : lhs)
        if(rhs[key] != value)
            return false;
    return true;
}

bool checkInclusion(string s1, string s2)
{
    map<char, int> dict, s1_symbs;
    for(const char& symb : s1)
        ++s1_symbs[symb];

    int j = 0;
    for(int i = 0; i < s2.size(); ++i)
    {
        while(j < s2.size() && j-i < s1.size())
            ++dict[s2[j++]];
        if(isMapsEqual(s1_symbs, dict))
            return true;
        if(dict[s2[i]] == 0)
            dict.erase(s2[i]);
        else
            --dict[s2[i]];
    }
    return false;
}