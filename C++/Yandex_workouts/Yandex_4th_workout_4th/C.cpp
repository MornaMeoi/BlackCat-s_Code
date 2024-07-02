#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N;
    inp >> N;
    vector<vector<int>> connected(N);
    for(int i = 0; i < N; ++i)
    {
        connected[i].resize(N);
        for(int j = 0; j < N; ++j)
            inp >> connected[i][j];
    }
    inp.close();

    int best = 0;
    vector<bool> first(N, false), second(N, false);
    for(int i = 0; !second[i] && i < N; ++i)
    {
        int current_max = 0, max_idx = 0;
        for(int j = 0; j < N; ++j)
            if(connected[i][j] > current_max && !second[j])
                current_max = connected[i][j];
        first[i] = true;
        second[max_idx] = true;
        best += current_max;
    }
    cout << best << endl;
    for(int i = 0; i < N; ++i)
    {
        if(first[i])
            cout << 1 << ' ';
        else
            cout << 2 << ' ';
    }
    /*for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            cout << connected[i][j] << ' ';
        cout << endl;
    }*/
    return 0;
}