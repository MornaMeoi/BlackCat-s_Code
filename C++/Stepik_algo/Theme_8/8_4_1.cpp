#include <bits/stdc++.h>

int find_max_weight_ub(std::unordered_map<int, int>& answer, std::vector<int> weights, int w)
{
  if(answer.find(w) == answer.end())
  {
    int v = 0;
    for(size_t i = 0; i < weights.size(); ++i)
      if(weights[i] <= w)
      {
        int c = weights[i];
        weights[i] = std::numeric_limits<int>::max();
        v = std::max(v, find_max_weight_ub(answer, weights, w - c) + c);
      }
    answer[w] = v;
  } 
  return answer[w];
}

int main()
{
  int W, n;
  std::cin >> W >> n;
  std::vector<int> weights(n);
  for(int& weight : weights)
    std::cin >> weight;

  std::unordered_map<int, int> answer;
  std::cout << find_max_weight_ub(answer, weights, W) << std::endl;
  return 0;
}