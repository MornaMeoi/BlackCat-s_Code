#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <limits>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N, A, B, R;
    inp >> N >> A >> B >> R;
    vector<multimap<int, pair<int, int>>> connected(N+1);
    for(int i = 0; i < R; ++i)
    {
        int a, start, b, finish;
        inp >> a >> start >> b >> finish;
        connected[a].insert({b, {start, finish}});
    }
    inp.close();

    /*for(int i = 1; i <= N; ++i)
    {
        cout << "Route from " << i << " to:" << endl;
        for(const auto& route : connected[i])
            cout << route.first << " starts at: " << route.second.first << ", ends at: " << route.second.second << endl;
    }*/
    vector<int> dist(N+1, numeric_limits<int>::max());
    vector<bool> visited(N+1, false);
    multimap<int, int> unvisited;
    dist[A] = 0;
    unvisited.insert({0, A});

    for(int i = 0; i < N; ++i)
    {
        if(unvisited.empty())
            break;
        int v = unvisited.begin()->second;
        /*cout << "current min on step " << i << ": " << unvisited.begin() -> second << ' ' << unvisited.begin()->first << endl;
        cout << endl;*/
        if(v == B)
            break;
        unvisited.erase(unvisited.begin());
        visited[v] = true;
        for(const auto& point : connected[v])
            if(!visited[point.first] && dist[v] <= point.second.first && point.second.second < dist[point.first])
                {
                    dist[point.first] = point.second.second;
                    unvisited.insert({dist[point.first], point.first});
                }
    }
    /*for(const auto point: unvisited)
        cout << point.second << ' ' << point.first << endl;*/
    cout << (dist[B] == numeric_limits<int>::max() ? -1 : dist[B]);
    return 0;
}