//task https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/?envType=list&envId=rydfq9ic
#include <vector>

using namespace std;

int oddCells(int m, int n, vector<vector<int>>& indices)
{
    vector<vector<int>> nums;
    nums.resize(m);
    for(int i = 0; i < m; ++i)
        nums[i].resize(n, 0);
    
    for(const auto& inc : indices)
    {
        for(int j = 0; j < n; ++j)
            ++nums[inc[0]][j];
        for(int i = 0; i < m; ++i)
            ++nums[i][inc[1]];
    }

    int result = 0;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            result += nums[i][j] % 2;
    return result;
}