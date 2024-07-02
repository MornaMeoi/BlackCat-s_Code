#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    vector<int> prefsums(nums.size()+2, 0);
    int max_num = nums[0];
    for(int i = 0; i < nums.size(); ++i)
    {
        if(max_num < nums[i])
            max_num = nums[i];
        prefsums[i+1] = prefsums[i] + nums[i];
    }
    prefsums[prefsums.size()-1] = numeric_limits<int>::min();

    int result = nums[0], result_idx = 0, growth_idx = 0;
    bool growth = false;
    for(int i = 1; i < prefsums.size(); ++i)
    {
        if(!growth && prefsums[i] > prefsums[i-1])
        {
            growth_idx = i-1;
            growth = true;
        }
        else if(growth && prefsums[i] < prefsums[i-1])
        {
            int growth_sum = prefsums[i-1] - prefsums[growth_idx], all_sum = prefsums[i-1] - prefsums[result_idx];
            if(growth_sum > result && growth_sum > all_sum)
            {
                result = growth_sum;
                result_idx = growth_idx;
            }
            else if(all_sum > result)
                result = all_sum;
            growth = false;
        }
    }
    return result > max_num ? result : max_num;
}

int main()
{
    vector<int> nums = {-2, -1};
    cout << maxSubArray(nums);
    return 0;
}