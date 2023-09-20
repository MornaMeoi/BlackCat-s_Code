//https://leetcode.com/problems/longest-palindromic-substring/
//unsolved
#include <iostream>
#include <utility>

using namespace std;

string longestPalindrome(string s);
bool isPalindrome(const string &s, int first, int last);
const pair<int, int>& Max(const pair<int, int>& first, const pair<int, int>& second);
const pair<int, int> recursive_check(const string& s, int first, int last);

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}

string longestPalindrome(string s) {
    auto indices = recursive_check(s, 0, s.size());
    return string(begin(s)+indices.first, begin(s)+indices.second);
}

const pair<int, int>& Max(const pair<int, int>& first, const pair<int, int>& second)
{
    return first.second-first.first < second.second-second.first ? second : first;
}

const pair<int, int> recursive_check(const string& s, int first, int last)
{
    if(isPalindrome(s, first, last))
        return pair<int, int>(first, last);
    else
    {
        auto temp1 = recursive_check(s, first+1, last),
             temp2 = recursive_check(s, first, last-1);
        temp1 = Max(temp1, temp2);
        if(first+1 < last)
        {
            temp2 = recursive_check(s, first+1, last-1);
            temp1 = Max(temp1, temp2);
        }
        return temp1;
    }
}

bool isPalindrome(const string &s, int first, int last)
{
    for(int i = first; i < (first+last)/2; ++i)
        if(s[i] != s[first+last-i-1])
            return false;
    return true;
}