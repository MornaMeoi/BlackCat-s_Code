#include <bits/stdc++.h>
using namespace std;

int64_t binaryGcd(int64_t a, int64_t b)
{
  if(a == b && b == 0) 
    return a;
  if(a == 0) 
    return b;
  if(a % 2 == 0)
  {
    if(b % 2 == 0)
      return binaryGcd(a / 2, b / 2) * 2;
    else
      return binaryGcd(a / 2, b);
  }
  if(b % 2 == 0) 
    return binaryGcd(a, b / 2);
  if(a > b) 
    return binaryGcd((a - b) / 2, b);
  return binaryGcd((b - a) / 2, a);
}

uint64_t getMaxPrimeDivisor(int64_t number)
{
  for(uint64_t i = 2; i <= sqrt(number); ++i)
    if(number % i == 0)
    {
      number /= i;
      i = 1;
    }
  return number;
}

int main()
{
  int T;
  int64_t A, B;
  cin >> T;
  while(--T >= 0)
  {
    cin >> A >> B;
    if(A == B)
      cout << binaryGcd(A, B);
    else
      cout << binaryGcd(A, B) * max(getMaxPrimeDivisor(A), getMaxPrimeDivisor(B));
    cout << endl;
  }
  return 0;
}