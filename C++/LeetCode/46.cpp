#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void rec_back(const vector<int>& nums, vector<bool> current_idxes, vector<int> current, int idx)
{
    if(idx == nums.size())
    {
        answer.push_back(current);
        return ;
    }
    for(int i = 0; i < current_idxes.size(); ++i)
    {
        if(current_idxes[i])
        {
            current_idxes[i] = false;
            current[idx] = nums[i];
            rec_back(nums, current_idxes, current, idx + 1);
            current_idxes[i] = true;
            current[idx] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<bool> idxes(nums.size(), true);
    vector<int> combs(nums.size());
    rec_back(nums, idxes, combs, 0);
    return answer;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    for(const vector<int>& perm : permute(nums))
    {
        for(int num : perm)
            cout << num << ' ';
        cout << endl;
    }
    return 0;
}