//task https://leetcode.com/problems/concatenation-of-array/?envType=list&envId=rydfq9ic
#include <vector>

using namespace std;

vector<int> getConcatenation(vector<int>& nums)
{
    nums.resize(nums.size()*2);
    for(int i = nums.size()/2; i < nums.size(); ++i)
        nums[i] = nums[i-nums.size()/2];
    return nums;
}