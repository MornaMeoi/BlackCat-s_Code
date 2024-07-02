#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int n, k, num;
    inp >> n >> k;
    unordered_map<int, vector<int>> nums;
    bool answer = false;
    for(int i = 0; i < n; ++i)
    {
        inp >> num;
        if(nums[num].empty() || i - nums[num][nums[num].size() - 1] > k)
            nums[num].push_back(i);
        else
        {
            answer = true;
            break;
        }
    }
    inp.close();

    cout << (answer ? "YES" : "NO");
    return 0;
}