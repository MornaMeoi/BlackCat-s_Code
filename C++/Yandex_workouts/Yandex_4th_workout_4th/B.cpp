#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> dinos(N);
    iota(dinos.begin(), dinos.end(), 0);
    int perms_amount = static_cast<int>(tgamma(N+1)), result = 0;
    for(int i = 0; i < perms_amount; ++i)
    {
        vector<bool> main(N, false), side(N, false);
        bool good_perm = true;
        for(int j = 0; good_perm && j < N; ++j)
        {
            int main_idx = dinos[j]-j+N-1, side_idx = dinos[j]+j;
            if(main[main_idx] || side[side_idx])
                good_perm = false;
            else
            {
                main[main_idx] = true;
                side[side_idx] = true;
            }
        }
        if(good_perm)
            ++result;
        next_permutation(dinos.begin(), dinos.end());
    }
    cout << result;
    return 0;
}