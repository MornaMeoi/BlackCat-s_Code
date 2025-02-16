#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n, T;
  cin >> n;
  vector<vector<int>> groups(n);
  for(auto& group : groups)
  {
    cin >> n;
    group.resize(n);
    for(int& ppl : group)
      cin >> ppl;
    nth_element(group.begin(), group.begin() + n / 2, group.end());
  }
  cin >> T;

  
  multimap<double, int> sums;
  for(size_t i = 0; i < groups.size(); ++i)
  {
    int sum_use = 0;
    for(int num : groups[i])
      sum_use += abs(num - groups[i][groups[i].size()/2]);
    sums.insert({sum_use / (groups[i][groups[i].size()/2]+1), i});
  }

  vector<int> results(groups.size());
  for(auto iter = sums.begin(); iter != sums.end(); ++iter)
  {
    int mid_idx = groups[iter->second].size() / 2;
    if(*iter == *sums.rbegin() || T - groups[iter->second][mid_idx] < 0)
    {
      results[iter->second] = T;
      T = 0;
    }
    else if(T - groups[iter->second][mid_idx] >= 0)
    {
      results[iter->second] = groups[iter->second][mid_idx];
      T -= groups[iter->second][mid_idx];
    }
  }

  for(int num : results)
    cout << num << ' ';
  return 0;
}