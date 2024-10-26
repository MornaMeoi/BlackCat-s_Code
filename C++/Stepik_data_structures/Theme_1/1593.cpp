//Task:       https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
//Difficulty: Medium
#include <bits/stdc++.h>
using namespace std;

int maxUniqueSplit(string s)
{
  unordered_set<string> substrings;
  for(size_t i = 0; i < s.size(); ++i)
  {
    if(!substrings.contains(to_string(s[i])))
      substrings.insert(to_string(s[i]));
    else
    {
      for(size_t j = 1; i - j >= 0 && i + j < s.size(); ++j)
      {
        if(!)
      }
    }
  }
  return substrings.size();
}

int main()
{
  string s;
  cin >> s;

  cout << maxUniqueSplit(s);
}