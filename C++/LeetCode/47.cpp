#include <iostream>
#include <vector>
#include <set>

using namespace std;

void bt(set<vector<int>>& answer, const vector<int>& nums, vector<bool>& current_idxes, vector<int>& current)
{
    if(current.size() == nums.size())
        answer.insert(current);
    else
        for(int i = 0; i < current_idxes.size(); ++i)
            if(current_idxes[i])
            {
                current_idxes[i] = false;
                current.push_back(nums[i]);
                bt(answer, nums, current_idxes, current);
                current_idxes[i] = true;
                current.pop_back();
            }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    set<vector<int>> answer;
    vector<bool> idxes(nums.size(), true);
    vector<int> comb;
    bt(answer, nums, idxes, comb);
    vector<vector<int>> result(answer.size());
    int idx = 0;
    for(const vector<int>& group : answer)
    {
        result[idx].resize(group.size());
        for(int i = 0; i < group.size(); ++i)
            result[idx][i] = group[i];
        ++idx;
    }
    return result;
}

int main()
{
    vector<int> nums = {1,1,2};
    for(vector<int> comb : permuteUnique(nums))
    {
        for(int num : comb)
            cout << num << ' ';
        cout << endl;
    }
    return 0;
}