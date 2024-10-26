#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> partition(std::vector<int>& nums, int left, int right);
void quick_sort(std::vector<int>& segments, int left, int right);
int find_median_idx(const std::vector<int>& segments, int left, int right);
int binary_search(const std::vector<int>& nums, int num);

int find_median_idx(const std::vector<int>& nums, int left, int right) {
  int mid = (left + right) / 2, median = left;
  if(nums[left] < nums[mid]) {
    if(nums[mid] < nums[right])
      median = mid;
    else if(nums[left] < nums[right])
      median = right;
    else
      median = left;
  }
  else {
    if(nums[left] < nums[right])
      median = left;
    else if(nums[mid] < nums[right])
      median = right;
    else
      median = mid;
  }
  return median;
}

std::pair<int, int> partition(std::vector<int>& nums, int left, int right) {
  int pivot = find_median_idx(nums, left, right), end_pivot = left;
  std::swap(nums[pivot], nums[left]);
  pivot = left;
  for(int i = left + 1; i <= right; ++i)
    if(nums[i] == nums[left])
      std::swap(nums[i], nums[++end_pivot]);
    else if(nums[i] < nums[left]) {
      std::swap(nums[i], nums[++end_pivot]);
      std::swap(nums[++pivot], nums[end_pivot]);
    }
  std::swap(nums[left], nums[pivot]);
  return {pivot, end_pivot};
}

void quick_sort(std::vector<int>& nums, int left, int right) {
  while(left < right) {
    std::pair<int, int> pivots = std::move(partition(nums, left, right));
    if(right - pivots.second < pivots.first - left) {
      quick_sort(nums, pivots.second + 1, right);
      right = pivots.first - 1;
    } else {
      quick_sort(nums, left, pivots.first - 1);
      left = pivots.second + 1;
    }
  }
}

int binary_search(const std::vector<int>& nums, int num) {
  int left = 0, right = nums.size();
  while(left < right)
  {
    int mid = (left + right) / 2;
    if(num < nums[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> starts(n), ends(n), points(m);
  for(int i = 0; i < n; ++i)
    std::cin >> starts[i] >> ends[i];
  for(int& p : points)
    std::cin >> p;
  quick_sort(starts, 0, n-1);
  quick_sort(ends, 0, n-1);
  for(int p : points)
    std::cout << binary_search(starts, p) - binary_search(ends, p - 1) << ' ';
  return 0;
}