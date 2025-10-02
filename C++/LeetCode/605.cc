#include <bits/stdc++.h>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
  if(flowerbed.size() == 1)
    return n <= 0 || (n == 1 && flowerbed[0] == 0);
  if(flowerbed[0] == 0 && flowerbed[1] == 0) {
    flowerbed[0] = 1;
    --n;
  }
  if(flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0) {
    flowerbed[flowerbed.size()-1] = 1;
    --n;
  }
  for(size_t i = 1; i < flowerbed.size() - 1; ++i) {
    if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
      flowerbed[i] = 1;
      --n;
      ++i;
    }
  }
  return n <= 0;
}