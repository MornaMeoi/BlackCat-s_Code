#include <bits/stdc++.h>
using namespace std;

int main()
{
  stack<pair<char, int>> brackets;
  char symbol;
  int idx = 1;
  bool is_incorrect = false;
  cin >> symbol;
  while(!cin.eof())
  {
    if(symbol == '(' || symbol == '[' || symbol == '{')
      brackets.push({symbol, idx});
    else if(symbol == ')' || symbol == ']' || symbol == '}')
    {
      if(!brackets.empty() && ((brackets.top().first == '(' && symbol == ')') || (brackets.top().first == symbol-2)))
        brackets.pop();
      else
      {
        is_incorrect = true;
        break;
      }
    }
    ++idx;
    cin >> symbol;
  }
  if(is_incorrect)
    cout << idx;
  else if(!brackets.empty())
    cout << brackets.top().second;
  else
    cout << "Success";
  cout << endl;
  return 0;
}