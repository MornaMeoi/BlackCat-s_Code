//task https://leetcode.com/problems/pacific-atlantic-water-flow/?envType=list&envId=rjy5c3hg
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);

int main()
{
    vector<vector<int>> a = {{1,2,2,3,5},
                             {3,2,3,4,4},
                             {2,4,5,3,1},
                             {6,7,1,4,5},
                             {5,1,1,2,4}};
    vector<vector<int>> b = {{1}};
    for(const auto& row : pacificAtlantic(a))
    {
        for(int cord : row)
            cout << cord << ' ';
        cout << endl;
    }
    return 0;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
    int offsets[] = {0, 1, 0, -1, 0};
    vector<vector<int>> result;
    queue<pair<int, int>> points;
    points.push({0, heights[0].size()-1});
    if(!(heights.size() == 1 && heights[0].size() == 1))
        points.push({heights.size()-1, 0});

    while(!points.empty())
    {
        pair<int, int> current = points.front();
        result.push_back({current.first, current.second});
        points.pop();

        for(int i = 0; i < 4; ++i)
            if(current.first+offsets[i] >= 0 && current.first+offsets[i] < heights.size() &&
            current.second+offsets[i+1] >= 0 && current.second+offsets[i+1] < heights[0].size() &&
            heights[current.first+offsets[i]][current.second+offsets[i+1]] >= heights[current.first][current.second])
                points.push({current.first+offsets[i], current.second+offsets[i+1]});
        heights[current.first][current.second] = 0;
    }
    return result;
}