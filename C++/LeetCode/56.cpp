#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    stable_sort(intervals.begin(), intervals.end(), [](auto& lhs, auto& rhs){ return lhs[0] < rhs[0]; });
    int last = 0;
    for(int j = 0; j < intervals.size(); ++j)
    {
        if(intervals[last][1] >= intervals[j][0])
            intervals[last][1] = max(intervals[j][1], intervals[last][1]);
        else
            intervals[++last] = intervals[j];
    }
    return {intervals.begin(), intervals.begin()+last+1};
}

int main()
{
    vector<vector<int>> nums = {{1, 4}, {2, 3}};
    cout << '[';
    for(const auto& arr : merge(nums))
        cout << '[' << arr[0] << ',' << arr[1] << "],";
    cout << ']';
    return 0;
}