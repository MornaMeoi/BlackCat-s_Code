#include <bits/stdc++.h>

using namespace std;

int maxOperations(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  int counter = 0;
  for(int first = 0, second = nums.size()-1; first <= second; ++first) {
    while(second > 0 && nums[first] + nums[second] > k) {
      --second;
    }
    if(nums[first] + nums[second] == k) {
      int first_amount = 1, second_amount = 1;
      while(first != nums.size()-1 && nums[first] == nums[first+1]) {
        ++first;
        ++first_amount;
      }
      while(second != 0 && nums[second] == nums[second-1]) {
        --second;
        ++second_amount;
      }
      if(nums[first] == nums[second]) {
        counter += first_amount / 2;
      } else {
        counter += min(first_amount, second_amount);
      }
      --second;
    }
  }
  return counter;
}

int main() {
  vector<int> test2 = {3,1,5,1,1,1,1,1,2,2,3,2,2};
  int k_2 = 1;
  cout << maxOperations(test2,k_2) << endl;
  return 0;
}