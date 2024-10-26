#include <bits/stdc++.h>
using namespace std;

int calculate_numberTD(unordered_map<int, int>& amount, unordered_map<int, int>& results, int n)
{
  if(n > 1 && amount.find(n) == amount.end())
  {
    int dev_3, dev_2, min_1;
    dev_3 = dev_2 = min_1 = numeric_limits<int>::max();
    if(n % 3 == 0)
      dev_3 = 1 + calculate_numberTD(amount, results, n / 3);
    if(n % 2 == 0)
      dev_2 = 1 + calculate_numberTD(amount, results, n / 2);
    min_1 = 1 + calculate_numberTD(amount, results, n - 1);
    amount[n] = min({dev_3, dev_2, min_1});
    if(amount[n] == dev_3)
      results[n] = n / 3;
    else if(amount[n] == dev_2)
      results[n] = n / 2;
    else
      results[n] = n - 1;
  }
  return amount[n];
}

int main()
{
  int n;
  cin >> n;
  
  unordered_map<int, int> amount, results;
  amount[1] = 0;
  results[1] = -1;
  cout << calculate_numberTD(amount, results, n) << endl;
  vector<int> nums(amount[n] + 1);
  nums[nums.size() - 1] = n;
  for(int i = nums.size() - 2, p = n; i >= 0; --i, p = results[p])
    nums[i] = results[p];
  for(int num : nums)
    cout << num << ' ';
  return 0;
}