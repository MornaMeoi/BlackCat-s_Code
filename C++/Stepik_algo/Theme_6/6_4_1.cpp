//Task: https://stepik.org/lesson/13248/step/5?unit=3433
#include <iostream>
#include <vector>
#include <queue>
#include <cinttypes>

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right, uint64_t& inversions)
{
  std::vector<int> result(left.size() + right.size());
  for(size_t i = 0, j = 0, k = 0; k < result.size(); ++k)
  {
    if(j >= right.size() || (i < left.size() && left[i] <= right[j]))
      result[k] = left[i++];
    else
    {
      result[k] = right[j++];
      inversions += left.size() - i;
    }
  }
  return result;
}

uint64_t merge_sort(std::vector<int>& nums)
{
  uint64_t result = 0;
  std::queue<std::vector<int>> nums_queue;
  for(int num : nums)
    nums_queue.push({num});
  while(nums_queue.size() != 1)
  {
    std::vector<int> left = std::move(nums_queue.front());
    nums_queue.pop();
    if(left.size() < nums_queue.front().size())
    {
      nums_queue.push(left);
      left = std::move(nums_queue.front());
      nums_queue.pop();
    }
    std::vector<int> right = std::move(nums_queue.front());
    nums_queue.pop();
    nums_queue.push(merge(left, right, result));
  }
  nums = nums_queue.front();
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for(int& num : nums)
    std::cin >> num;

  std::cout << "Befor sort: ";
  for(int num : nums)
    std::cout << num << ' ';
  std::cout << std::endl;

  std::cout << "Amount of inversions: " << merge_sort(nums) << std::endl;

  std::cout << "After sort: ";
  for(int num : nums)
    std::cout << num << ' ';
  std::cout << std::endl;
  return 0;
}