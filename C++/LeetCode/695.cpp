//task https://leetcode.com/problems/max-area-of-island/?envType=list&envId=rjy5c3hg
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> a = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    vector<vector<int>> b = {{0,0,0,0,0,0,0,0}};

    vector<vector<int>> c = {{0,0,0,0,1,0,1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,1,0,1,1},
                             {0,1,0,0,0,0,1,1,1,0,1,1,0,0,0,1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1},
                             {1,0,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,1,0,1,0,1,1,1,1},
                             {0,0,0,0,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,1,1,0,1,1,0,0,0,1,1},
                             {0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0,1,0,0,1},
                             {0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,0,0,1,0,1},
                             {0,1,0,1,0,0,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,0,0,0,1,1,0,1,1,0},
                             {0,1,0,0,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0},
                             {0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0}};

    vector<vector<int>> d = {{0,0,1},
                             {1,1,0}};
    cout << maxAreaOfIsland(c);
    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int result = 0, offset[] = {0, 1, 0, -1, 0}, l = 0;
    queue<pair<int,int>> current_island;

    while(l < grid.size())
    {
        for(int i = l; i < grid.size() && current_island.empty(); ++i)
            for(int j = 0; j < grid[0].size() && current_island.empty(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    l = i;
                    current_island.push({i, j});
                }
                grid[i][j] = -1;
                if(i == grid.size()-1 && j == grid[0].size()-1)
                    l = grid.size();
            }
        int current_square = 0;
        while(!current_island.empty())
        {
            pair<int, int> current = current_island.front();
            current_island.pop();
            ++current_square;
            for(int k = 0; k < 4; ++k)
            {
                int di = current.first+offset[k], dj = current.second+offset[k+1];
                if(di >= 0 && di < grid.size() && dj >= 0 && dj < grid[0].size() && grid[di][dj] == 1)
                {
                    current_island.push({di, dj});
                    grid[di][dj] = -1;
                }
            }
        }
        result = current_square > result ? current_square : result;
    }
    return result;
}