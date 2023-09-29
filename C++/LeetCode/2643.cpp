//task https://leetcode.com/problems/row-with-maximum-ones/?envType=list&envId=rydfq9ic
#include <vector>
#include <numeric>

using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat)
{
    int max = 0, max_idx = 0;
    for(int i = 0; i < mat.size(); ++i)
    {
        int temp = accumulate(mat[i].begin(), mat[i].end(), 0);
        if(temp > max)
        {
            max = temp;
            max_idx = i;
        }
    }
    return {max_idx, max};
}