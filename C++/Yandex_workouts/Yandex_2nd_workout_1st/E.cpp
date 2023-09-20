#include <iostream>

using namespace std;

int main()
{
    int K1, M, K2, P2, N2, P1, N1;
    cin >> K1 >> M >> K2 >> P2 >> N2;
    if(N2 > M || (P2 - 1) * M  + N2 > K2)
        cout << "-1 -1";
    else if(P2 == 1 && N2 <= 2)
        if(K1 <= M)
            cout << "1 0";
        else if(M == 1)
            cout << "0 1";
        else
            cout << "0 0";
    else
    {
        int x = (K2 - 1) / ((N2 - 1) + M * (P2 -1));
        int y = x * M;
        P1 = ((K1 - 1) / y) + 1;
        N1 = (((K1 - (P1 - 1) * y) - 1) / x) + 1;
        cout << P1 << ' ' << N1;
    }
    return 0;
}