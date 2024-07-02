#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int n, k;
    inp >> n;
    map<string, int> albums;
    string temp;
    for(int i = 0; i < n; ++i)
    {
        inp >> k;
        for(int j = 0; j < k; ++j)
        {
            inp >> temp;
            ++albums[temp];
        }
    }
    inp.close();

    int amount = 0;
    for(const auto& album : albums)
        if(album.second == n)
            ++amount;
    cout << amount << endl;
    for(const auto& album : albums)
        if(album.second == n)
            cout << album.first << ' ';
    return 0;
}