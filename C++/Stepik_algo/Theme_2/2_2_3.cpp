#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

class Fibonacci final {
 public:
  static int get_remainder(int64_t n, int m) {
    assert(n >= 1);
    assert(m >= 2);
    std::vector<int> fib_nums_remainders(2, 0);
    fib_nums_remainders[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        fib_nums_remainders.push_back((fib_nums_remainders[i-1] + fib_nums_remainders[i-2]) % m);
        if(fib_nums_remainders[i] == 1 && fib_nums_remainders[i-1] == 0)
        {
            fib_nums_remainders.pop_back();
            fib_nums_remainders.pop_back();
            break;
        }
    }
    return fib_nums_remainders[n % fib_nums_remainders.size()];
  }
};

int main(void) {
  int64_t n;
  int m;
  std::cin >> n >> m;
  std::cout << Fibonacci::get_remainder(n, m) << std::endl;
  return 0;
}