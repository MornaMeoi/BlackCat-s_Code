#include <bits/stdc++.h>
#include <cstddef>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> left(nums.size(), 1), right(nums.size(), 1);
  for(int i = 1; i < left.size(); ++i)
    left[i] = left[i-1] * nums[i-1];
  for(int i = right.size()-2; i >= 0; --i)
    right[i] = right[i+1] * nums[i+1];
  for(int i = 0; i < left.size(); ++i)
    left[i] *= right[i];
  return left;
}