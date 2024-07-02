#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums)
{
    int jumps = nums[0];
    bool result = true;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(jumps < 0)
            return false;
        else if(nums[i] > jumps)
            jumps = nums[i];
        else
            --jumps;
    }
    return true;
}

int main()
{
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums);
    return 0;
}