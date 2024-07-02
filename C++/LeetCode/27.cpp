//task https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val);

int main()
{
    vector<int> a = {1};
    int b = 2;
    cout << removeElement(a, b) << endl;
    for(int num : a)
        cout << num << ' ';
    return 0;
}

int removeElement(vector<int>& nums, int val)
{
    int k = nums.size();
    for(int i = 0; i < k; ++i)
        if(nums[i] == val)
        {
            while(k != 0 && i != k && nums[--k] == val);
            nums[i] = nums[k];
        }
    return k;
}