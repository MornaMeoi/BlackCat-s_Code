#include <cassert>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
  assert(a > 0 && b > 0);
  if(a < b)
    std::swap(a, b);
  while(a %= b)
    std::swap(a, b);
  return b;
}

int main(void) {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}