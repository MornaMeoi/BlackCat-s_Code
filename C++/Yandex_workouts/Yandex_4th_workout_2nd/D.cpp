#include <iostream>
#include <fstream>
#include <vector>
#include <cinttypes>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N, M;
    inp >> N >> M;
    vector<int> cubes(N);
    for(int i = 0; i < N; ++i)
        inp >> cubes[i];
    inp.close();

    vector<uint64_t> hash(N+1), reversed_hash(N+1), X(N+1);
    hash[0] = 0;
    reversed_hash[0] = 0;
    X[0] = 1;
    int x = M + 1, p = 1'000'000'007;
    for(int i = 1; i <= N; ++i)
    {
        hash[i] = (hash[i-1] * x + cubes[i-1]) % p;
        reversed_hash[i] = (reversed_hash[i-1] * x + cubes[N-i]) % p;
        X[i] = (X[i-1] * x) % p;
    }

    for(int i = N/2; i >= 0; --i)
        if((hash[i] + reversed_hash[N-2*i] * X[i]) % p == reversed_hash[N-i] % p)
            cout << N-i << ' ';
    return 0;
}