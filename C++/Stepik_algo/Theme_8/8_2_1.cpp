#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

int get_length_of_longest_divisible_subsequence(const std::vector<int> &numbers)
{
  std::vector<int> D(numbers.size(), 1);
  for(size_t i = 1; i < D.size(); ++i)
    for(size_t j = 0; j < i; ++j)
      if(numbers[i] % numbers[j] == 0 && D[j] + 1 > D[i])
        D[i] = D[j] + 1;
  return *std::max_element(D.begin(), D.end());
}

int main()
{
  size_t number_count;
  std::cin >> number_count;
  std::vector<int> numbers(number_count);
  for (auto &number:numbers) {
    std::cin >> number;
  }

  std::cout << get_length_of_longest_divisible_subsequence(numbers) << std::endl;
  return 0;
}