#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int n, num;
    inp >> n;
    unordered_map<int, int> groups;
    for(int i = 0; i < n; ++i)
    {
        inp >> num;
        ++groups[num];
        ++groups[num+1];
    }
    inp.close();

    cout << n - (*max_element(groups.begin(), groups.end(), [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; })).second;
    return 0;
}