#include <bits/stdc++.h>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
  int second = 0;
  double average = 0., max_val = 0., div = static_cast<double>(k);
  while(second < k) {
    average += nums[second++];
  }
  average /= div;
  max_val = average;
  for(int first = 0; second < nums.size(); ++first, ++second) {
    average += (nums[second] - nums[first]) / div;
    if(average > max_val)
      max_val = average;
  }
  return max_val;
}

int main() {
  vector<int> test1 = {1,12,-5,-6,50,3};
  int k1 = 4;
  cout << findMaxAverage(test1, k1) << endl;
  return 0;
}