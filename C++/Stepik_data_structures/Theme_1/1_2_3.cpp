#include <bits/stdc++.h>
using namespace std;

int main()
{
  int size, n;
  cin >> size >> n;
  queue<int> buffer;
  while(--n >= 0)
  {
    int arrival, duration;
    cin >> arrival >> duration;
    while(!buffer.empty() && buffer.front() <= arrival)
      buffer.pop();
    if(buffer.size() == size)
      cout << -1 << endl;
    else
    {
      if(buffer.empty())
      {
        buffer.push(arrival + duration);
        cout << arrival << endl;
      }
      else
      {
        cout << buffer.back() << endl;
        buffer.push(buffer.back() + duration);
      }
    }
  }
  return 0;
}