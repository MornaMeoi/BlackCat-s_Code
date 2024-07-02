#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int64_t n, k, d;
    inp >> n >> k >> d;
    inp.close();

    bool found = false;
    n *= 10;
    for(int i = 0; i < 10 && !found; ++i)
        if((n + i) % k == 0)
        {
            n += i;
            found = true;
        }
    if(found)
    {
        stringstream ss;
        ss << n;
        string num;
        ss >> num;
        int n_len = num.size();
        num.resize(n_len + d-1, '0');
        cout << num;
    }
    else
        cout << -1;
    return 0;
}