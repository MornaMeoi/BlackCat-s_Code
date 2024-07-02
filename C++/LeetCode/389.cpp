//task https://leetcode.com/problems/find-the-difference/?envType=list&envId=rb946505
#include <iostream>
#include <string>
#include <map>

using namespace std;

char findTheDifference(string s, string t);

int main()
{
    string a = "", b = "y";
    cout << findTheDifference(a, b);
    return 0;
}

char findTheDifference(string s, string t)
{
    map<char, int> first, second;
    for(char symb : s)
        ++first[symb];
    for(char symb : t)
        ++second[symb];
    for(auto const& [symb, amount] : second)
        if(amount != first[symb])
            return symb;
}