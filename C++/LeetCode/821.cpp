//task https://leetcode.com/problems/shortest-distance-to-a-character/?envType=list&envId=rb946505
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> shortestToChar(string s, char c);

int main()
{
    string s = "loveleetcode";
    char c = 'e';
    for(int num : shortestToChar(s, c))
        cout << num << ' ';
    return 0;
}

vector<int> shortestToChar(string s, char c)
{
    vector<int> indices;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == c)
            indices.push_back(i);
    vector<int> result;
    for(int i = 0; i < s.size(); ++i)
    {
        int temp = s.size();
        for(int idx : indices)
            if(abs(idx-i) < temp)
                temp = abs(idx-i);
        result.push_back(temp);
    }
    return result;
}