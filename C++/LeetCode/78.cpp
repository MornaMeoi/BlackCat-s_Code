//task https://leetcode.com/problems/subsets/?envType=list&envId=rydfq9ic
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> result;
    for(int num : nums)
    {
        vector<vector<int>> temp;
        temp.push_back({num});
        for(const auto& sub : result)
        {
            vector<int> new_sub(sub);
            new_sub.push_back(num);
            temp.push_back(new_sub);
        }
        for(const auto& sub : temp)
            result.push_back(sub);
    }
    result.push_back({});
    return result;
}