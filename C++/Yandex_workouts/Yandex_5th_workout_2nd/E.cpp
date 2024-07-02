#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int n;
    inp >> n;
    vector<int> diffs(n);
    int a, b, max_height = 0, max_height_idx = 0;
    for(int i = 0; i < n; ++i)
    {
        inp >> a >> b;
        diffs[i] = a - b;
        if((diffs[i] > 0 && diffs[max_height_idx] > 0 && b > max_height - diffs[max_height_idx]) ||
           (diffs[i] <= 0 && diffs[max_height_idx] > 0 && a > max_height - diffs[max_height_idx]) ||
           (diffs[i] > 0 && diffs[max_height_idx] <= 0 && b > max_height) ||
           (diffs[i] <= 0 && diffs[max_height_idx] <= 0 && a > max_height))
        {
            max_height = a;
            max_height_idx = i;
        }
    }
    inp.close();

    int64_t result = 0;
    for(int i = 0; i < n; ++i)
        if(diffs[i] > 0 && i != max_height_idx)
            result += diffs[i];
    cout << result + max_height << endl;
    for(int i = 0; i < n; ++i)
        if(diffs[i] > 0 && i != max_height_idx)
            cout << i + 1 << ' ';
    cout << max_height_idx + 1 << ' ';
    for(int i = 0; i < n; ++i)
        if(diffs[i] <= 0 && i != max_height_idx)
            cout << i + 1 << ' ';
    return 0;
}


//12 : 989222712 955828702
//879 : 942732325 955249484