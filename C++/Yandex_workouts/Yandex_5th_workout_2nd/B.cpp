#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N, K;
    inp >> N >> K;
    vector<int> prices(N);
    for(int i = 0; i < N; ++i)
        inp >> prices[i];
    inp.close();

    int current_min_idx = 0, current_max_idx = 0, result = 0;
    for(int last = 0; last < N; ++last)
    {
        if(prices[last] > prices[current_max_idx])
        {
            current_max_idx = last;
            result = max(result, prices[current_max_idx] - prices[current_min_idx]);
        }
        if(prices[last] < prices[current_min_idx])
        {
            current_min_idx = last;
            current_max_idx = last;
        }
        if(last - current_min_idx == K)
        {
            ++current_min_idx;
            for(int i = current_min_idx; i < current_max_idx; ++i)
                if(prices[i] < prices[current_min_idx])
                    current_min_idx = i;
        }

    }
    cout << result;
    return 0;
}