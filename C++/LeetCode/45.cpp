#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums)
{
    int result = 0, cur = 0;
    while(cur < nums.size()-1)
    {
        if(cur + nums[cur] < nums.size()-1)
        {
            int bound = cur + nums[cur] + 1;
            bound = bound > nums.size() ? nums.size() : bound;
            int next_jump = bound-1;
            for(int i = next_jump-1; i > cur; --i)
                if(nums[next_jump] < nums[i] - (next_jump - i))
                    next_jump = i;
            cur = next_jump;
        }
        else
            cur = nums.size()-1;
        ++result; 
    }
    return result;
}

int main()
{
    vector<int> nums = {1,2,1,1,1};
    cout << jump(nums);
    return 0;
}