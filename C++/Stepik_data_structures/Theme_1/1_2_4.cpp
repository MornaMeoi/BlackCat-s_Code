#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q;
  cin >> q;
  stack<int> nums, maxes;
  string query;
  while(--q >= 0)
  {
    cin >> query;
    if(query == "push")
    {
      int num;
      cin >> num;
      nums.push(num);
      if(maxes.empty())
        maxes.push(num);
      else
        maxes.push(max(num, maxes.top()));
    }
    else if(query == "pop")
    {
      nums.pop();
      maxes.pop();
    }
    else
      cout << maxes.top() << endl;
  }
  return 0;
}