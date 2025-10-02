#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

string reverseWords(string s) {
  int res_idx = 0, first = 0, last = s.size()-1;
  while (last > 0 && s[last] == ' ')
    --last;
  if(last == 0)
    return {s[0]};
  string result(s.size(), ' ');
  while(last > 0) {
    first = last;
    while(first > 0 && s[first-1] != ' ')
      --first;
    last = first;
    while(first < s.size() && s[first] != ' ')
      result[res_idx++] = s[first++];
    ++res_idx;
    while(last > 0 && s[last-1] == ' ')
      --last;
  }
  result.resize(res_idx-1);
  return result;
}

int main() {
  string test1 = "t ";
  cout << reverseWords(test1);
  return 0;
}