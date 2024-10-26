//task: https://stepik.org/lesson/13238/step/9?unit=3424
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using Segment = std::pair<int, int>;

std::vector <int> get_covering_set(std::vector <Segment> segments) {
  std::vector <int> result;
  std::sort(segments.begin(), segments.end(), [](Segment& lhs, Segment& rhs){
    return lhs.first < rhs.first;
  });

  int min_end = segments[0].second;
  for (auto s : segments) {
    if(s.second < min_end)
      min_end = s.second;
    else if(s.first > min_end) {
      result.push_back(min_end);
      min_end = s.second;
    }
  }
  if(result.empty() || result[result.size()-1] != min_end)
    result.push_back(min_end);
  return result;
}

int main(void) {
  int segments_count;
  std::cin >> segments_count;
  std::vector <Segment> segments(segments_count);
  for (auto &s:segments) {
    std::cin >> s.first >> s.second;
  }

  auto points = get_covering_set(std::move(segments));
  std::cout << points.size() << std::endl;
  for (auto point:points) {
    std::cout << point << " ";
  }
  std::cout << std::endl;
}