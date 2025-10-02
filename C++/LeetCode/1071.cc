#include <iostream>

using namespace std;

bool isDivided(const string& divider, const string& source) {
  if(source.size() % divider.size() != 0) {
    return false;
  }
  for(int i = 0; i < source.size(); i += divider.size()) {
    if(string(source.begin() + i, source.begin() + i + divider.size()) != divider) {
      return false;
    }
  }
  return true;
}

string gcdOfStrings(string str1, string str2) {
  if(str1.size() > str2.size())
    std::swap(str1, str2);
  for(int i = str1.size(); i > 0; --i) {
    string temp = string(str1.begin(), str1.begin() + i);
    if(isDivided(temp, str2))
      return temp;
  }
  return "";
}