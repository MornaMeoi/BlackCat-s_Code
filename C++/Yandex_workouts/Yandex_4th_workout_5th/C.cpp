#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <limits>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N, M;
    inp >> N >> M;
    vector<map<int, pair<int, int>>> connected(N+1);
    for(int i = 0; i < M; ++i)
    {
        int a, b, t, w;
        inp >> a >> b >> t >> w;
        connected[a][b] = {t, -w};
        connected[b][a] = {t, -w};
    }
    inp.close();

    vector<pair<int, int>> dist(N+1, {1440, 0});
    vector<bool> visited(N+1, false);
    multimap<int, int> unvisited;
    dist[1] = {0,0};
    unvisited.insert({0, 1});

    for(int i = 0; i < M; ++i)
    {
        if(unvisited.empty())
            break;
        int v = unvisited.begin()->second;
        unvisited.erase(unvisited.begin());
        if(dist[v].first > 1440)
            continue;
        if(v == N)
            break;
        visited[v] = true;
        for(const auto& point : connected[v])
            if(!visited[point.first])
                {
                    dist[point.first] = {dist[v].first + point.second.first, point.second.second};
                    unvisited.insert({dist[point.first].second, point.first});
                }
    }
    cout << (-dist[N].second-3'000'000)/100;
    return 0;
}