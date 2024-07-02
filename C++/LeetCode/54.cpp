#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> result(matrix.size() * matrix[0].size());
    int idx = 0, k = 0;
    while(idx < result.size())
    {
        int rot = k % 4, bound = k / 4;
        if(rot == 0)
            for(int j = bound; j < matrix[0].size()-bound; ++j)
                result[idx++] = matrix[bound][j];
        else if(rot == 1)
            for(int i = bound + 1; i < matrix.size()-bound; ++i)
                result[idx++] = matrix[i][matrix[0].size()-bound-1];
        else if(rot == 2)
            for(int j = matrix[0].size()-bound-2; j >= bound; --j)
                result[idx++] = matrix[matrix.size()-bound-1][j];
        else
            for(int i = matrix.size()-bound-2; i > bound; --i)
                result[idx++] = matrix[i][bound];
        ++k;
    }
    return result;
}

int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    for(int num : spiralOrder(mat))
        cout << num << ' ';
    return 0;
}