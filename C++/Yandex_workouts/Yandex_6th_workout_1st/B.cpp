#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  if(A == 0)
    cout << 1 << ' ' << C + 1;
  else if(B == 0)
    cout << 1 << ' ' << D + 1;
  else if(C == 0)
    cout << A + 1 << ' ' << 1;
  else if(D == 0)
    cout << B + 1 << ' ' << 1;
  else
  {
    int first = A + C,
    second = B + D,
    third = max(A, B),
    fourth = max(C, D),
    M_N = min({first, second, third, fourth});
    if(M_N == first)
      cout << A + 1 << ' ' << C + 1;
    else if(M_N == second)
      cout << B + 1 << ' ' << D + 1;
    else if(M_N == third)
      cout << third + 1 << ' ' << 1;
    else
      cout << 1 << ' ' << fourth + 1;
  }
  return 0;
}