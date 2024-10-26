#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int get_pos(const std::vector<int> &numbers, int number) {
  size_t left = 0, right = numbers.size();
  while(left < right)
  {
    size_t mid = (left + right - 1) / 2;
    if(numbers[mid] < number)
      left = mid + 1;
    else
      right = mid;
  }
  return numbers[left] == number ? left + 1 : -1;
}

int main(void) {
  size_t number_count;
  std::cin >> number_count;
  std::vector<int> numbers(number_count);
  for (auto &number:numbers) {
    std::cin >> number;
  }
  assert(std::is_sorted(numbers.begin(), numbers.end()));

  size_t query_count;
  std::cin >> query_count;
  while (query_count-- > 0) {
    int number;
    std::cin >> number;
    std::cout << get_pos(numbers, number) << " ";
  }
  std::cout << std::endl;
}