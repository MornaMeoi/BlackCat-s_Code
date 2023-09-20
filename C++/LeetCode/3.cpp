//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s);

int main()
{
    string s;
    cin >> s;    
    cout << lengthOfLongestSubstring(s);
    return 0;
}

int lengthOfLongestSubstring(string s) {
    int max = 0;
    auto first = begin(s);
    for(auto last = begin(s); last < end(s); ++last)
    {
        auto temp = find(first, last, *last);
        if(temp != last)
        {
            max = last-first > max ? last-first : max;
            first = temp+1;
        }
    }
    return max > end(s)-first ? max : end(s)-first;
}