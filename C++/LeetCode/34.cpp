#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    if(nums.empty())
        return {-1, -1};
    int left_result, left = 0, right = nums.size()-1;
    while(left < right)
    {
        int middle = (left + right) / 2;
        if(nums[middle] >= target)
            right = middle;
        else
            left = middle + 1;
    }
    if(nums[left] != target)
        return {-1, -1};
    left_result = left;
    right = nums.size()-1;
    while(left < right)
    {
        int middle = (left + right + 1) / 2;
        if(nums[middle] <= target)
            left = middle;
        else
            right = middle - 1;
    }
    return {left_result, left};
}

int main()
{
    vector<int> nums = {};
    for(int idx : searchRange(nums, 0))
        cout << idx << ' ';
    cout << endl;
}