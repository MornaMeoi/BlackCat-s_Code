#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <limits>
#include <cinttypes>
#include <utility>

using namespace std;

int main()
{
    ifstream inp("06");
    int N, K;
    inp >> N >> K;
    vector<map<int, int>> connected(N+1);
    for(int i = 0; i < K; ++i)
    {
        int a, b, l;
        inp >> a >> b >> l;
        connected[a][b] = l;
        connected[b][a] = l;
    }
    int A, B;
    inp >> A >> B;
    inp.close();

    vector<int64_t> dist(N+1, numeric_limits<int64_t>::max());
    vector<bool> visited(N+1, false);
    multimap<int64_t, int> unvisited;
    dist[A] = 0;
    unvisited.insert({0, A});

    for(int i = 0; i < K; ++i)
    {
        if(unvisited.empty())
            break;
        int v = unvisited.begin()->second;
        cout << "current min on step " << i << ": " << unvisited.begin() -> second << ' ' << unvisited.begin()->first << endl;
        cout << endl;
        if(v == B)
            break;
        unvisited.erase(unvisited.begin());
        visited[v] = true;
        for(const auto& point : connected[v])
            if(!visited[point.first] && point.second + dist[v] < dist[point.first])
                {
                    dist[point.first] = dist[v] + point.second;
                    unvisited.insert({dist[point.first], point.first});
                }
    }
    for(const auto point: unvisited)
        cout << point.second << ' ' << point.first << endl;
    cout << "N: " << N << " K: " << K << " A: " << A << " B: " << B << endl;
    cout << (dist[B] == numeric_limits<int64_t>::max() ? -1 : dist[B]);
    return 0;
}