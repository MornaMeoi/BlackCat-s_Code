//task https://leetcode.com/problems/number-of-islands/?envType=list&envId=rj4up7id
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numIslands(vector<vector<char>>& grid);

int main()
{
    vector<vector<char>> a = {{'1','1','1','1','0'},
                              {'1','1','0','1','0'},
                              {'1','1','0','0','0'},
                              {'0','0','0','0','0'}};
    /*vector<vector<char>> b = {{'1','1','0','0','0'},
                              {'1','1','0','0','0'},
                              {'0','0','1','0','0'},
                              {'0','0','0','1','1'}};*/
    cout << numIslands(a) << endl;
    for(int i = 0; i < a.size(); ++i)
    {
        for(int j = 0; j < a[0].size(); ++j)
            cout << static_cast<int>(a[i][j]) << ' ';
        cout << endl;
    }
    return 0;
}

int numIslands(vector<vector<char>>& grid)
{
    int amount = 0;
    queue<pair<int, int>> current_island, water;
    if(grid[0][0] == '1')
    {
        current_island.push({0, 0});
        grid[0][0] = 1;
        ++amount;
    }
    else
    {
        water.push({0, 0});
        grid[0][0] = 0;
    }

    while(!water.empty() || !current_island.empty())
    {
        while(!current_island.empty())
        {
            pair<int, int> current = current_island.front();
            current_island.pop();
            for(int i = current.first-1; i <= current.first+1; i += 2)
                if(i >= 0 && i < grid.size())
                    if(grid[i][current.second] == '1')
                    {
                        current_island.push({i, current.second});
                        grid[i][current.second] = 1;
                    }
                    else if(grid[i][current.second] == '0')
                    {
                        water.push({i, current.second});
                        grid[i][current.second] = 0;
                    }
            for(int i = current.second-1; i <= current.second+1; i += 2)
                if(i >= 0 && i < grid[0].size())
                    if(grid[current.first][i] == '1')
                    {
                        current_island.push({current.first, i});
                        grid[current.first][i] = 1;
                    }
                    else if(grid[current.first][i] == '0')
                    {
                        water.push({current.first, i});
                        grid[current.first][i] = 0;
                    }
        }
        ++amount;
        while(current_island.empty() && !water.empty())
        {
            pair<int, int> current = water.front();
            water.pop();
            for(int i = current.first-1; i <= current.first+1; i += 2)
                if(i >= 0 && i < grid.size())
                    if(grid[i][current.second] == '1' && current_island.empty())
                    {
                        current_island.push({i, current.second});
                        grid[i][current.second] = 1;
                    }
                    else if(grid[i][current.second] == '0')
                    {
                        water.push({i, current.second});
                        grid[i][current.second] = 0;
                    }
            for(int i = current.second-1; i <= current.second+1; i += 2)
                if(i >= 0 && i < grid[0].size())
                    if(grid[current.first][i] == '1' && current_island.empty())
                    {
                        current_island.push({current.first, i});
                        grid[current.first][i] = 1;
                    }
                    else if(grid[current.first][i] == '0')
                    {
                        water.push({current.first, i});
                        grid[current.first][i] = 0;
                    }
        }
    }
    return amount-1;
}