#include <bits/stdc++.h>

using namespace std;

bool isVowel(char symb) {
  return symb == 'a' || symb == 'e' || symb == 'i' || symb == 'o' || symb == 'u' || symb == 'A' || symb == 'E' || symb == 'I' || symb == 'O' || symb == 'U';
}

string reverseVowels(string s) {
  size_t first = 0, second = s.size()-1;
  while(first < second) {
    while(first != s.size()-1 && !isVowel(s[first]))
      ++first;
    while(second != 0 && !isVowel(s[second]))
      --second;
    if(first < second)
      swap(s[first++], s[second--]);
  }
  return s;
}