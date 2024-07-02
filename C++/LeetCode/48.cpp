#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int len = matrix.size();
    for(int i = 0; i < len; ++i)
        for(int j = i; j < len-i-1; ++j)
        {
            int temp1, temp2;
            for(int k = 0; k < 4; ++k)
                if(k == 0)
                {
                    temp1 = matrix[j][len-i-1];
                    matrix[j][len-i-1] = matrix[i][j];
                }
                else if(k == 1)
                {
                    temp2 = matrix[len-i-1][len-j-1];
                    matrix[len-i-1][len-j-1] = temp1;
                }
                else if(k == 2)
                {
                    temp1 = matrix[len-j-1][i];
                    matrix[len-j-1][i] = temp2;
                }
                else if(k == 3)
                    matrix[i][j] = temp1;
        }
                
}

void printMatrix(const vector<vector<int>>& matrix)
{
    for(int i = 0; i < matrix.size(); ++i)
        for(int j = 0; j < matrix.size(); ++j)
        {
            cout << matrix[i][j] << ' ';
            if(j == matrix.size() - 1)
                cout << endl;
        }
}

int main()
{
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix);
    printMatrix(matrix);
    return 0;
}