#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int first_prev = 0, second_prev = 0, current = 0;
  cin >> second_prev;
  current = second_prev;
  while(--n >= 1)
  {
    cin >> current;
    current += max(first_prev, second_prev);
    first_prev = second_prev;
    second_prev = current;
  }
  cout << current << endl;
  return 0;
}