//task https://leetcode.com/problems/shortest-path-in-binary-matrix/?envType=list&envId=rj4up7id
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> a = {{0,1},
                             {1,0}};
    cout << shortestPathBinaryMatrix(a);
    return 0;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    if(grid[0][0] == 1 || grid[grid.size()-1][grid.size()-1] == 1)
        return -1;
    
    grid[0][0] = 2;
    queue<pair<int, int>> new_points;
    new_points.push({0, 0});

    while(!new_points.empty())
    {
        pair<int, int> current = new_points.front();
        new_points.pop();
        for(int i = current.first-1; i <= current.first+1; ++i)
            for(int j = current.second-1; j <= current.second+1; ++j)
            {
                if(i >= 0 && i < grid.size() && j >= 0 && j < grid.size() && grid[i][j] == 0)
                {
                    grid[i][j] = grid[current.first][current.second]+1;
                    new_points.push({i, j});
                }
            }
    }
    return grid[grid.size()-1][grid.size()-1] == 0 ? -1 : grid[grid.size()-1][grid.size()-1]-1;
}