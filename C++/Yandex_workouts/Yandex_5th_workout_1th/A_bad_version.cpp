#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int P, V, Q, M;
    inp >> P >> V >> Q >> M;
    inp.close();

    cout << max(P + V, Q + M) - min(P - V, Q - M) + 1 - (min(Q + M + 1, P + V + 1) < max(Q - M, P - V)) * (max(P - V, Q - M) - min(P + V, Q + M));
    return 0;
}