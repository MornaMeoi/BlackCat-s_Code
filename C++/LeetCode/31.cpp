#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums)
{
    if(nums.size() == 1)
        return ;
    int left = nums.size()-2, right = nums.size()-1;
    while(left > 0 && nums[left] >= nums[left+1])
        --left;
    if(left == 0 && nums[0] >= nums[1])
    {
        for(int i = 0; i + 1 < nums.size(); ++i)
            for(int j = 0; j + 1 < nums.size() - i; ++j)
                if(nums[j+1] < nums[j])
                    swap(nums[j+1], nums[j]);
    }
    else
    {
        while(right > 0 && nums[left] >= nums[right])
            --right;
        swap(nums[left++], nums[right]);
        right = nums.size()-1;
        while(left < right)
            swap(nums[left++], nums[right--]);
    }
}

int main()
{
    vector<int> nums = {4, 3, 2, 1};
    for(int i = 0; i < 1; ++i)
        nextPermutation(nums);
    for(int num : nums)
        cout << num << ' ';
    cout << endl;
    return 0;
}