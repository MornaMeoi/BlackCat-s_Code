#include <iostream>
#include <vector>

using namespace std;

int pivot_bin_search(const vector<int>& nums, int left, int right)
{
    while(left < right)
    {
        int middle = (right + left) / 2;
        if(nums[middle] < nums[0])
            right = middle;
        else
            left = middle + 1;
    }
    return left;
}

int bin_search(const vector<int>& nums, int left, int right, int target)
{
    while(left < right)
    {
        int middle = (right + left) / 2;
        if(nums[middle] >= target)
            right = middle;
        else
            left = middle + 1;
    }
    return left;
}

int search(vector<int>& nums, int target)
{
    int pivot = 0;
    if(nums[0] > nums[nums.size()-1])
        pivot = pivot_bin_search(nums, 0, nums.size()-1);
    int result = bin_search(nums, 0, pivot, target);
    if(nums[result] != target)
        result = bin_search(nums, pivot, nums.size()-1, target);
    return nums[result] == target ? result : -1;
}

int main()
{
    vector<int> nums = {3, 4, 5, 6, 7, 1, 2};
    cout << search(nums, 5);
    return 0;
}