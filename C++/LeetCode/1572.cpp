//task https://leetcode.com/problems/matrix-diagonal-sum/?envType=list&envId=rydfq9ic
#include <vector>

using namespace std;

int diagonalSum(vector<vector<int>>& mat)
{
    int result = 0;
    for(int i = 0; i < mat.size(); ++i)
        result += mat[i][i] + mat[i][mat.size()-1-i];
    return mat.size() % 2 ? result - mat[mat.size()/2][mat.size()/2] : result;
}