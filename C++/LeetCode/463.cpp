//task https://leetcode.com/problems/island-perimeter/?envType=list&envId=rjy5c3hg
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> a = {{0,1,0,0},
                             {1,1,1,0},
                             {0,1,0,0},
                             {1,1,0,0}};
    vector<vector<int>> b = {{1}};
    vector<vector<int>> c = {{1, 0}};
    vector<vector<int>> d = {{1, 1},
                             {1, 1}};
    cout << islandPerimeter(d);
    return 0;
}

int islandPerimeter(vector<vector<int>>& grid)
{
    queue<pair<int, int>> island;
    for(int i = 0; i < grid.size() && island.empty(); ++i)
        for(int j = 0; j < grid[0].size() && island.empty(); ++j)
            if(grid[i][j] == 1)
            {
                island.push({i, j});
                grid[i][j] = -1;
            }
    int offsets[] = {0, 1, 0, -1, 0}, result = 0;

    while(!island.empty())
    {
        pair<int, int> current = island.front();
        island.pop();

        for(int i = 0; i < 4; ++i)
            if(current.first+offsets[i] < 0 || current.first+offsets[i] >= grid.size() ||
            current.second+offsets[i+1] < 0 || current.second+offsets[i+1] >= grid[0].size() ||
            grid[current.first+offsets[i]][current.second+offsets[i+1]] == 0)
                ++result;
            else if(grid[current.first+offsets[i]][current.second+offsets[i+1]] == 1)
            {
                island.push({current.first+offsets[i], current.second+offsets[i+1]});
                grid[current.first+offsets[i]][current.second+offsets[i+1]] = -1;
            }
    }
    return result;
}