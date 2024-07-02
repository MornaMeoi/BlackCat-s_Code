//task https://leetcode.com/problems/minesweeper/?envType=list&envId=rjy5c3hg
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click);

int main()
{
    vector<vector<char>> a1 = {{'E','E','E','E','E'},
                               {'E','E','M','E','E'},
                               {'E','E','E','E','E'},
                               {'E','E','E','E','E'}};
    vector<int> a2 = {{3, 0}};

    vector<vector<char>> b1 = {{'B','1','E','1','B'},
                               {'B','1','M','1','B'},
                               {'B','1','1','1','B'},
                               {'B','B','B','B','B'}};
    vector<int> b2 = {1, 2};
    
    for(const auto& row : updateBoard(a1, a2))
    {
        for(char symb : row)
            cout << symb << ' ';
        cout << endl;
    }
    return 0;
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
{
    
}