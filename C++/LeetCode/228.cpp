//Task: https://leetcode.com/problems/summary-ranges/
//Difficulty: Easy
#include <bits/stdc++.h>

using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
    if(nums.size() == 1)
        return {to_string(nums[0])};
    vector<string> result;
    size_t first = 0;
    for(size_t i = 1; i < nums.size(); ++i)
    {
        if(static_cast<uint64_t>(nums[i]) - nums[first] != i - first)
        {
            if(first != i-1)
                result.push_back({to_string(nums[first]) + "->" + to_string(nums[i-1])});
            else
                result.push_back(to_string(nums[first]));
            first = i;
        }
        if(i == nums.size()-1)
        {
            if(first == i)
                result.push_back(to_string(nums[i]));
            else
                result.push_back({to_string(nums[first]) + "->" + to_string(nums[i])});
        }
    }
    return result;
}

int main()
{
    ifstream inp("input.txt");
    vector<int> nums;
    while(!inp.eof())
    {
        int num;
        inp >> num;
        nums.push_back(num);
        inp.ignore(1);
    }
    inp.close();

    for(const auto& s : summaryRanges(nums))
        cout << s << ',';
    cout << endl;
    return 0;
}