#include <bits/stdc++.h>
using namespace std;

int main()
{
  size_t n = 0;
  cin >> n;
  vector<int> nums(n);
  for(int &num : nums)
    cin >> num;

  if(is_sorted(nums.begin(), nums.end()))
    cout << nums[nums.size()-1] - nums[0];
  else
    cout << -1;
  return 0;
}