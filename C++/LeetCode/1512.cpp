//task https://leetcode.com/problems/number-of-good-pairs/?envType=daily-question&envId=2023-10-03
#include <iostream>
#include <vector>

using namespace std;

int numIdenticalPairs(vector<int>& nums);

int main()
{
    vector<int> n = {1,2,3,1,1,3};
    cout << numIdenticalPairs(n);
    return 0;
}

int numIdenticalPairs(vector<int>& nums)
{
    int result = 0;
    for(char i = 0; i < nums.size()-1; ++i)
        for(char j = i+1; j < nums.size(); ++j)
            if(nums[i] == nums[j])
                ++result;
    return result;
}