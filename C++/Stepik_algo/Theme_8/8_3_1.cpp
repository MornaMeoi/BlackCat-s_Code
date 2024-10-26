#include<bits/stdc++.h>

int get_levenshtein_distance(const std::string& a, const std::string& b)
{
  std::vector<int> prev(b.size() + 1), curr(b.size() + 1);
  for(size_t i = 0; i < prev.size(); ++i)
    prev[i] = i;
  for(size_t i = 1; i <= a.size(); ++i)
  {
    curr[0] = i;
    for(size_t j = 1; j < curr.size(); ++j)
      curr[j] = std::min({curr[j-1] + 1, prev[j] + 1, prev[j-1] + static_cast<int>(a[i-1] != b[j-1])});
    std::swap(prev, curr);
  }
  return prev[prev.size()-1];
}

int main()
{
  std::string a, b;
  std::cin >> a >> b;

  std::cout << get_levenshtein_distance(a, b) << std::endl;;
  return 0;
}