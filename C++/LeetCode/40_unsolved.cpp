#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int>> answer;

void combination(const vector<int>& candidates, int target, int idx, vector<int> current)
{
    if(target == 0)
    {
        stable_sort(current.begin(), current.end());
        if(find(answer.begin(), answer.end(), current) == answer.end())
            answer.push_back(current);
        return ;
    }

    if(target < 0)
        return ;

    if(idx == candidates.size())
        return ;
    
    combination(candidates, target, idx + 1, current);
    current.push_back(candidates[idx]);
    combination(candidates, target - candidates[idx], idx + 1, current);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    int sum = accumulate(candidates.begin(), candidates.end(), 0);
    if(sum < target)
        return {};
    if(sum == target)
        return {candidates};
    bool equal = true;
    for(int i = 1; i < candidates.size(); ++i)
        if(candidates[i] != candidates[i-1])
        {
            equal = false;
            break;
        }
    if(equal)
        if(target % candidates[0] == 0)
        {
            vector<int> temp(target / candidates[0], candidates[0]);
            return {temp};
        }
        else
            return {};
    answer.clear();
    combination(candidates, target, 0, {});
    return answer;
}

int main()
{
    vector<int> nums = {10,1,2,7,6,1,5};
    for(const vector<int>& el : combinationSum2(nums, 8))
    {
        for(int num : el)
            cout << num << ' ';
        cout << endl;
    }
    return 0;
}