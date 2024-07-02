#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <limits>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N;
    inp >> N;
    vector<pair<int, int>> prepare_speed(N+1);
    for(int i = 1; i <= N; ++i)
    {
        int T, V;
        inp >> T >> V;
        prepare_speed[i] = {T, V};
    }
    vector<map<int, int>> connected(N+1);
    for(int i = 0; i < N-1; ++i)
    {
        int A, B, S;
        inp >> A >> B >> S;
        connected[A][B] = S;
        connected[B][A] = S;
    }
    inp.close();

    /*for(int i = 1; i <= N; ++i)
    {
        cout << "Road from city " << i << " to:" << endl;
        for(const auto& road : connected[i])
            cout << road.first << " has length " << road.second << endl;
    }*/
    vector<vector<double>> dist(N+1);
    for(int i = 1; i <= N; ++i)
    {
        dist[i].resize(N+1, numeric_limits<double>::max());
        dist[i][i] = i == 1 ? 0 : prepare_speed[i].first;
    }

    for(int i = 2; i <= N; ++i)
    {
        vector<bool> visited(N+1, false);
        multimap<int, int> unvisited;
        unvisited.insert({0, i});
        while(!unvisited.empty())
        {
            int v = unvisited.begin()->second;
            unvisited.erase(unvisited.begin());
            visited[v] = true;
            for(const auto& point : connected[v])
                if(!visited[point.first] && point.second/static_cast<double>(prepare_speed[i].second) + dist[i][v] < dist[i][point.first])
                    {
                        dist[i][point.first] = point.second/static_cast<double>(prepare_speed[i].second) + dist[i][v];
                        unvisited.insert({dist[i][point.first], point.first});
                    }
        }
    }
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
            cout << dist[i][j] << ' ';
        cout << endl;
    }
    /*for(const auto point: unvisited)
        cout << point.second << ' ' << point.first << endl;*/
    //cout << (dist[B] == numeric_limits<int>::max() ? -1 : dist[B]);
    return 0;
}