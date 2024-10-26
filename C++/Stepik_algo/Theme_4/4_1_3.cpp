#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums;
    for(int i = 1; n > 0; ++i)
    {
      if(n >= i)
      {
        n -= i;
        nums.push_back(i);
      }
      else
      {
        int temp = n + nums[nums.size()-1];
        nums.pop_back();
        nums.push_back(temp);
        n = 0;
      }
    }
    std::cout << nums.size() << std::endl;
    for(int num : nums)
      std::cout << num << ' ';
    return 0;
}