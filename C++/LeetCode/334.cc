#include <bits/stdc++.h>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
  if(nums.size() < 3)
    return false;
  int first = 0, second = 0;
  while(first != nums.size()-2 && nums[first] >= nums[first+1])
    ++first;
  while(first < nums.size()-1) {
    second = first+1;
    int temp = second;
    while (second < nums.size()-1 && nums[second] >= nums[second+1]) {
      ++second;
      if(nums[first] < nums[second])
        temp = second;
    }
    if(second < nums.size()-1 && (nums[temp] < nums[second+1] || nums[first] < nums[second]))
      return true;
    first = second;
  }
  return false;
}

int main() {
  vector<int> test1 = {1,2,3,4,5};
  cout << increasingTriplet(test1);
  return 0;
}