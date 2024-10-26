#include <iostream>
#include <vector>

int main()
{
  int n = 0, num = 0;
  std::cin >> n;
  std::vector<int> digits(11, 0);
  while(--n >= 0)
  {
    std::cin >> num;
    ++digits[num];
  }
  for(int i = 1; i < 11; ++i) 
    while(--digits[i] >= 0)
      std::cout << i << ' ';
  return 0;
}