#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void rec_back(const vector<int>& candidates, int target, vector<int> current, int current_sum, set<vector<int>>& result)
{
    if(current_sum == target)
    {
        stable_sort(current.begin(), current.end());
        result.insert(current);
    }
    else if(current_sum < target)
        for(int num : candidates)
        {
            current.push_back(num);
            rec_back(candidates, target, current, current_sum + num, result);
            current.pop_back();
        }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    set<vector<int>> result;
    for(int num : candidates)
        rec_back(candidates, target, {num}, num, result);
    vector<vector<int>> res(result.size());
    int idx = 0;
    for(const vector<int>& group : result)
    {
        res[idx].resize(group.size());
        for(int i = 0; i < group.size(); ++i)
            res[idx][i] = group[i];
        ++idx;
    }
    return res;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    for(const auto& el : combinationSum(candidates, 7))
    {
        for(int num : el)
            cout << num << ' ';
        cout << endl;
    }
    return 0;
}