//task https://leetcode.com/problems/top-k-frequent-words/?envType=list&envId=rb946505
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k);

int main()
{
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    for(const auto& word : topKFrequent(words, k))
        cout << word << ' ';
    return 0;
}

vector<string> topKFrequent(vector<string>& words, int k)
{
    unordered_map<string, int> dict;
    for(const auto& word : words)
        ++dict[word];

    vector<string> result;
    for(const auto& el : dict)
        result.push_back(el.first);
    sort(result.begin(), result.end(), [&dict](const string& lhs, const string& rhs)
                                        {
                                            return dict[lhs] == dict[rhs] ? lhs < rhs : dict[lhs] > dict[rhs];
                                        });
    result.resize(k);
    return result;
}