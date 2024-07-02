#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N, S, F;
    inp >> N >> S >> F;
    vector<vector<int>> graph(N);
    for(int i = 0; i < N; ++i)
    {
        graph[i].resize(N);
        for(int j = 0; j < N; ++j)
            inp >> graph[i][j];
    }
    inp.close();

    --F;
    --S;
    vector<bool> visited(N, false);
    vector<int> dist(N, numeric_limits<int>::max()), prev(N);
    dist[S] = 0;
    prev[S] = -1;

    for(int i = 0; i < N; ++i)
    {
        int v = -1;
        for(int j = 0; j < N; ++j)
            if(!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        if(dist[v] == numeric_limits<int>::max())
            break;
        visited[v] = true;
        for(int j = 0; j < N; ++j)
            if(graph[v][j] != -1 && graph[v][j] + dist[v] < dist[j])
            {
                dist[j] = dist[v] + graph[v][j];
                prev[j] = v;
            }
    }
    if(dist[F] == numeric_limits<int>::max())
        cout << -1;
    else
    {
        vector<int> points;
        points.push_back(F);
        for(int i = F; prev[i] != -1; i = prev[i])
            points.push_back(prev[i]);
        for(int i = points.size()-1; i >= 0; --i)
            cout << points[i]+1 << ' ';
    }
    return 0;
}