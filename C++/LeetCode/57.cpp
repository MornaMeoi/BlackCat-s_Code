#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    for(int i = 0; i < intervals.size(); ++i)
        if(newInterval[0] < intervals[i][0])
        {
            intervals.insert(intervals.begin()+i, newInterval);
            return merge(intervals);
        }
    intervals.push_back(newInterval);
    return merge(intervals);

}

int main()
{
    vector<vector<int>> nums = {{1,3},{6,9}};
    vector<int> new_int = {2, 5};
    cout << '[';
    for(const auto& arr : insert(nums, new_int))
        cout << '[' << arr[0] << ',' << arr[1] << "],";
    cout << ']';
    return 0;
}