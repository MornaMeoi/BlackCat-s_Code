#include <bits/stdc++.h>

using namespace std;

inline bool IsVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(string s, int k) {
  int curr_max = 0, res_max = 0, second = 0;
  while(second < k) {
    curr_max += IsVowel(s[second++]);
  }
  res_max = curr_max;
  for(int first = 0; second < s.size(); ++first, ++second) {
    curr_max += (IsVowel(s[second]) - IsVowel(s[first]));
    if(curr_max > res_max)
      res_max = curr_max;
  }
  return res_max;
}