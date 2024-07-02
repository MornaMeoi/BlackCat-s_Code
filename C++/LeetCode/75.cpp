#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums)
{
    int zeros = 0, ones = 0;
    for(int i = 0; i < nums.size(); ++i)
        if(nums[i] == 0)
            ++zeros;
        else if(nums[i] == 1)
            ++ones;
    for(int i = 0; i < zeros; ++i)
        nums[i] = 0;
    for(int i = zeros; i < zeros+ones; ++i)
        nums[i] = 1;
    for(int i = zeros+ones; i < nums.size(); ++i)
        nums[i] = 2;
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(int num : nums)
        cout << num << ' ';
    return 0;
}