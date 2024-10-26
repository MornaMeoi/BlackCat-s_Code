//Task: https://leetcode.com/problems/subarray-sum-equals-k
//Difficulty: Medium
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    int module_sum_check = 0;
    for(int num : nums)
        module_sum_check += abs(num);
    if(module_sum_check < k)
        return 0;

    vector<int> prefix_sums(nums.size()+1, 0);
    for(int i = 0; i < nums.size(); ++i)
        prefix_sums[i+1] = prefix_sums[i] + nums[i];    
    
    int result = 0;
    for(int step = 1; step < prefix_sums.size(); ++step)
        for(int i = 0; i + step < prefix_sums.size(); ++i)
            if(prefix_sums[i+step] - prefix_sums[i] == k)
                ++result; 
    return result;
}

int main()
{
    ifstream inp("input.txt");
    vector<int> nums;
    int k;
    inp.ignore(8);
    while(inp.peek() != ',')
    {
        int num;
        inp >> num;
        nums.push_back(num);
        inp.ignore(1);
    }
    inp.ignore(6);
    inp >> k;
    inp.close();

    cout << subarraySum(nums, k) << endl;
    return 0;
}