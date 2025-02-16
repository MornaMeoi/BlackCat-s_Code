#include <bits/stdc++.h>
using namespace std;

int main()
{
  double x1, y1, x2, y2, x, y;
  cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

  if(y >= y2)
  {
    if(x <= x1)
      cout << "NW";
    else if(x > x1 && x < x2)
      cout << "N";
    else
      cout << "NE";
  }
  else if(y < y2 && y > y1)
  {
    if(x < x1)
      cout << "W";
    else
      cout << "E";
  }
  else
  {
    if(x <= x1)
      cout << "SW";
    else if(x > x1 && x < x2)
      cout << "S";
    else
      cout << "SE";
  }
  return 0;
}