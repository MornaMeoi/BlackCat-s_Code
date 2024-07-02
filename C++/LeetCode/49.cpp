#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    bool empty = true;
    for(const string& word : strs)
        if(!word.empty())
        {
            empty = false;
            break;
        }
    if(empty)
    {
        vector<string> temp(strs.size(), "");
        return {temp};
    }
    vector<map<char, int>> words(strs.size());
    for(int i = 0; i < strs.size(); ++i)
        for(int j = 0; j < strs[i].size(); ++j)
            ++words[i][strs[i][j]];
    for(int i = 0; i < words.size() - 1; ++i)
        for(int j = i + 1; j < words.size(); ++j)
            if(words[i] == words[j])
            {
                swap(words[i+1], words[j]);
                swap(strs[i+1], strs[j]);
                break;
            }
    vector<vector<string>> result;
    int first = 0, second = 0;
    while(second < words.size())
    {
        while(second < words.size() && words[first] == words[second])
            ++second;
        vector<string> temp(second-first);
        for(int i = first; i < second; ++i)
            temp[i-first] = strs[i];
        result.push_back(temp);
        first = second;
    }
    return result;
}

int main()
{
    vector<string> strs = {"",""};
    for(const vector<string>& anagrams : groupAnagrams(strs))
    {
        for(const string& anagram : anagrams)
            cout << anagram << ' ';
        cout << endl;
    }
    return 0;
}