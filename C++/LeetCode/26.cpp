//task https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums);

int main()
{
    //vector<int> a = {0};
    //vector<int> a = {0,0,1,1,1,2,2,3,3,4};
    //vector<int> a = {1, 1};
    vector<int> a = {1,2,3};
    int len = removeDuplicates(a);
    cout << len << endl;
    for(int i = 0; i < len; ++i)
        cout << a[i] << ' ';
    return 0;
}

int removeDuplicates(vector<int>& nums)
{
    int last = 0, first = 0;
    while(last != nums.size())
    {
        while(last != nums.size()-1 && nums[first] == nums[last++]);
        if(nums[first] == nums[last])
            break;
        nums[++first] = nums[last];
    }
    return first+1;
}