#include <iostream>
#include <vector>
#include <limits>

int binary_search(const std::vector<int>& nums, int num)
{
  int left = 0, right = nums.size();
  while(left < right)
  {
    int mid = (left + right) / 2;
    if(num <= nums[mid])
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

std::vector<int> findLnIS(const std::vector<int>& nums)
{
  int length = 0;
  std::vector<int> d(nums.size() + 1, std::numeric_limits<int>::min()), pos(nums.size() + 1), prev(nums.size());
  pos[0] = -1;
  d[0] = std::numeric_limits<int>::max();
  for(size_t i = 0; i < nums.size(); ++i)
  {
    int j = binary_search(d, nums[i]);
    if (d[j-1] >= nums[i] && d[j] <= nums[i])
    {
      d[j] = nums[i];
      pos[j] = i;
      prev[i] = pos[j - 1];
      length = std::max(length, j);
    }
  }

  std::vector<int> answer;
  int p = pos[length];
  while(p != -1)
  {
    answer.push_back(p + 1);
    p = prev[p];
  }
  for(size_t i = 0; i < answer.size() / 2; ++i)
    std::swap(answer[i], answer[answer.size()-i-1]);
  return answer;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> nums(n), answers(n, 1);
  for(int& num : nums)
    std::cin >> num;

  std::vector<int> answer = std::move(findLnIS(nums));
  std::cout << answer.size() << std::endl;
  for(int num : answer)
    std::cout << num << ' ';
  return 0;
}