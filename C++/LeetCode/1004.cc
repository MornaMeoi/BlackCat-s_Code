#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
  int max_ones_amount = 0, first = 0, second = 0;
  for(;second < nums.size() && max_ones_amount < k; ++second) {
    if(nums[second] == 0) {
      ++max_ones_amount;
    }
  }
  cout << "Init second: " << second << endl;
  max_ones_amount = second - first + (second == nums.size());
  ++second;
  for(;second < nums.size(); ++first, ++second) {
    while(first < nums.size() && nums[first] != 0) {
      ++first;
    }
    while(second < nums.size() && nums[second] != 0) {
      ++second;
    }
    cout << "first: " << first << " second: " << second << " current max: " << max_ones_amount << endl;
    // if(second == nums.size()) {
    //   ++second;
    // }
    if(max_ones_amount < second - first - 1) {
      max_ones_amount = second - first - 1;
    }
  }
  return max_ones_amount;
}

void TestCheck(vector<int>& test_nums, int test_k, int answer, int test_num) {
  int result = longestOnes(test_nums, test_k);
  cout << "Test " << test_num << ": ";
  if(result == answer) {
    cout << "PASSED";
  } else {
    cout << "FAILED: output " << result << " != expected " << answer;
  }
  cout << endl;
}

int main() {
  vector<int> test1 = {1,1,1,0,0,0,1,1,1,1,0};
  int k1 = 2, answer1 = 6;
  TestCheck(test1, k1, answer1, 1);

  vector<int> test2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
  int k2 = 2, answer2 = 10;
  TestCheck(test2, k2, answer2, 2);

  return 0;
}