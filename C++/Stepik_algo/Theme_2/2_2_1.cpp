#include <cassert>
#include <iostream>

class Fibonacci
{
 public:
  static int get(int n)
  {
    assert(n >= 0);
    if(n == 1 || n == 2)
        return 1;
    else
        return get(n-1) + get(n-2);
  }
};

int main() {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}