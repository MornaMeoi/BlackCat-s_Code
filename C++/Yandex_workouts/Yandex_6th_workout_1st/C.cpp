#include <bits/stdc++.h>
using namespace std;

void print_matrix(const vector<vector<bool>>& mat)
{
  for(const auto& row : mat)
  {
    for(bool el : row)
      cout << el;
    cout << endl;
  }
}

pair<int, int> find_next_corner(const vector<vector<bool>>& mat, int x, int y)
{
  int res_x = 0, res_y = 0;
  for(res_y = y; res_y < mat.size() && !mat[res_y][x]; ++res_y);
  --res_y;
  for(res_x = x; res_x < mat[0].size() && !mat[res_y][res_x]; ++res_x);
  return {res_x - 1, res_y};
}

pair<int, int> recursive_find_glow_corner(const vector<vector<bool>>& mat, int x, int y)
{
  pair<int, int> first = {x, y}, second = {x, y};
  if(x + 1 < mat.size() && mat[y][x + 1])
    first = recursive_find_glow_corner(mat, x + 1, y);
  if(y + 1 < mat.size() && mat[y + 1][x])
    second = recursive_find_glow_corner(mat, x, y + 1);
  return first.first + first.second > second.first + second.second ? first : second;
}

bool check_horizontal_sides_of_rectangle(const vector<vector<bool>>& matrix, pair<int, int> left_up_corner, pair<int, int> right_down_corner)
{
  bool type = matrix[left_up_corner.second][left_up_corner.first];
  for(int i = left_up_corner.second; i <= right_down_corner.second; ++i)
  {
    for(int j = 0; j < left_up_corner.first; ++j)
      if(matrix[i][j] == type)
        return false;
    for(int j = right_down_corner.first + 1; j < matrix[0].size(); ++j)
      if(matrix[i][j] == type)
        return false;
  }
  return true;
}

bool check_bottom_under_y(const vector<vector<bool>>& matrix, int y, bool type)
{
  for(int i = y + 1; i < matrix.size(); ++i)
    for(int j = 0; j < matrix[0].size(); ++j)
      if(matrix[i][j] == type)
        return false;
  return true;
}

bool check_full_dark_rectangle(const vector<vector<bool>>& matrix, pair<int, int> left_up_corner, pair<int, int> right_down_corner)
{
  for(int i = left_up_corner.second; i <= right_down_corner.second; ++i)
    for(int j = left_up_corner.first; j <= right_down_corner.first; ++j)
      if(matrix[i][j])
        return false;
  return true;
}

pair<pair<int, int>, pair<int, int>> find_rectangle_cords(const vector<vector<bool>>& matrix, int y)
{
  for(int i = y; i < matrix.size(); ++i)
      for(int j = 0; j < matrix[0].size(); ++j)
        if(!matrix[i][j])
        {
          auto corner = find_next_corner(matrix, j, i);
          return {{j, i}, corner};
        }
  return {{-1, -1}, {-1, -1}};
}

int main()
{
  int n;
  cin >> n;
  vector<vector<bool>> table(n);
  for(auto& row : table)
    row.resize(n);

  char symb = 0;
  for(size_t i = 0; i < table.size(); ++i)
    for(size_t j = 0; j < table.size(); ++j)
    {
      cin >> symb;
      table[i][j] = symb == '#';
    }
  
  int glow_x1 = -1, glow_y1 = -1;
  for(int i = 0; i < table.size() && glow_y1 == -1; ++i)
    for(int j = 0; j < table.size() && glow_x1 == -1; ++j)
      if(table[i][j])
      {
        glow_x1 = j;
        glow_y1 = i;
      }

  char result = 0;
  bool x_input = false;
  if(glow_x1 == -1 && glow_y1 == -1)
    x_input = true;
  if(!x_input)
  {
    int glow_x2 = glow_x1, glow_y2 = glow_y1;
    while(glow_y2 < table.size() && table[glow_y2][glow_x2])
      ++glow_y2;
    --glow_y2;
    while(glow_x2 < table.size() && table[glow_y1][glow_x2])
      ++glow_x2;
    --glow_x2;
    auto res = recursive_find_glow_corner(table, glow_x1, glow_y1);
    if(glow_x2 + glow_y2 < res.first + res.second)
    {
      glow_x2 = res.first;
      glow_y2 = res.second;
    }
    //cout << glow_y1 << ' ' << glow_x1 << ' ' << glow_y2 << ' ' << glow_x2 << endl;
    x_input = !(check_horizontal_sides_of_rectangle(table, {glow_x1, glow_y1}, {glow_x2, glow_y2}) && check_bottom_under_y(table, glow_y2, true));
    //cout << check_horizontal_sides_of_rectangle(table, {glow_x1, glow_y1}, {glow_x2, glow_y2}) << ' ' << check_bottom_under_y(table, glow_y2, true) << endl;
    if(!x_input)
    {
      vector<vector<bool>> glow_rectangle(glow_y2-glow_y1 + 1);
      for(auto& row : glow_rectangle)
        row.resize(glow_x2-glow_x1 + 1);
      for(int i = glow_y1; i <= glow_y2; ++i)
        for(int j = glow_x1; j <= glow_x2; ++j)
          glow_rectangle[i - glow_y1][j - glow_x1] = table[i][j];
      //print_matrix(glow_rectangle);
      vector<pair<pair<int, int>, pair<int, int>>> dark_cords;
      dark_cords.push_back(find_rectangle_cords(glow_rectangle, 0));
      if(dark_cords[0].first.first == -1)
        result = 'I';
      else
      {
        x_input = !check_horizontal_sides_of_rectangle(glow_rectangle, dark_cords[0].first, dark_cords[0].second) ||
                  !check_full_dark_rectangle(glow_rectangle, dark_cords[0].first, dark_cords[0].second);
        for(int j = 0; j < glow_rectangle[0].size() && !x_input; ++j)
            if(glow_rectangle[dark_cords[0].second.second+1][j] == false)
              x_input = true;
        //for(auto rec : dark_cords)
          //cout << rec.first.first << ' ' << rec.first.second << ' ' << rec.second.first << ' ' << rec.second.second << endl;
        if(!x_input)
        {
          dark_cords.push_back(find_rectangle_cords(glow_rectangle, dark_cords[0].second.second + 2));
          if(dark_cords[1].first.first != -1)
          {
            x_input = !check_horizontal_sides_of_rectangle(glow_rectangle, dark_cords[1].first, dark_cords[1].second) ||
                      !check_bottom_under_y(glow_rectangle, dark_cords[1].second.second, false) ||
                      !check_full_dark_rectangle(glow_rectangle, dark_cords[1].first, dark_cords[1].second);
            if(!x_input)
            {
              bool cond_H = 0 < dark_cords[0].first.first && dark_cords[0].first.first == dark_cords[1].first.first &&
                            dark_cords[0].first.first <= dark_cords[0].second.first && dark_cords[0].second.first == dark_cords[1].second.first &&
                            dark_cords[0].second.first < glow_rectangle[0].size()-1 &&
                            0 == dark_cords[0].first.second && dark_cords[0].first.second <= dark_cords[0].second.second &&
                            dark_cords[0].second.second < dark_cords[1].first.second && dark_cords[1].first.second <= dark_cords[1].second.second &&
                            dark_cords[1].second.second == glow_rectangle.size()-1;
              bool cond_P = 0 < dark_cords[0].first.first && dark_cords[0].first.first == dark_cords[1].first.first &&
                            dark_cords[0].first.first <= dark_cords[0].second.first && dark_cords[0].second.first < dark_cords[1].second.first &&
                            dark_cords[1].second.first == glow_rectangle[0].size()-1 &&
                            0 < dark_cords[0].first.second && dark_cords[0].first.second <= dark_cords[0].second.second &&
                            dark_cords[0].second.second < dark_cords[1].first.second && dark_cords[1].first.second <= dark_cords[1].second.second &&
                            dark_cords[1].second.second == glow_rectangle.size()-1;
              if(cond_H)
                result = 'H';
              else if(cond_P)
                result = 'P';
              else
                result = 'X';           
            }
          }
          else
          {
            dark_cords.pop_back();
            bool cond_O = 0 < dark_cords[0].first.first && dark_cords[0].first.first <= dark_cords[0].second.first && dark_cords[0].second.first < glow_rectangle[0].size()-1 &&
                          0 < dark_cords[0].first.second && dark_cords[0].first.second <= dark_cords[0].second.second && dark_cords[0].second.second < glow_rectangle.size()-1;
            bool cond_C = 0 < dark_cords[0].first.first && dark_cords[0].first.first <= dark_cords[0].second.first && dark_cords[0].second.first == glow_rectangle[0].size()-1 &&
                          0 < dark_cords[0].first.second && dark_cords[0].first.second <= dark_cords[0].second.second && dark_cords[0].second.second < glow_rectangle.size()-1;
            bool cond_L = 0 < dark_cords[0].first.first && dark_cords[0].first.first <= dark_cords[0].second.first && dark_cords[0].second.first == glow_rectangle[0].size()-1 &&
                          0 == dark_cords[0].first.second && dark_cords[0].first.second <= dark_cords[0].second.second && dark_cords[0].second.second < glow_rectangle.size()-1;
            if(cond_O)
              result = 'O';
            else if(cond_C)
              result = 'C';
            else if(cond_L)
              result = 'L';
            else
              result = 'X';
          }
        }
      }
    }
  }

  if(x_input)
    result = 'X';
  cout << result;
  return 0;
}

/*int main()
{
  while(!cin.eof())
  {
    cout << endl;
    print_symbol();
    cout << endl;
  }
  return 0;
}*/