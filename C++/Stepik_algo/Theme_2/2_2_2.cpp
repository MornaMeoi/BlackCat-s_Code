#include <cassert>
#include <iostream>
#include <vector>

class Fibonacci final {
 public:
  static int get_last_digit(int n) {
    assert(n >= 1);
    std::vector<int> fib_last_digits(n, 1);
    for(int i = 2; i < n; ++i)
        fib_last_digits[i] = (fib_last_digits[i-1] + fib_last_digits[i-2]) % 10;
    return fib_last_digits[n-1];
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get_last_digit(n) << std::endl;
  return 0;
}