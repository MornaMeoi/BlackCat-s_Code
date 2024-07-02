//task https://leetcode.com/problems/adding-spaces-to-a-string/?envType=list&envId=rbos7rxs
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addSpaces(string s, vector<int>& spaces);

int main()
{
    string a = "spacing";
    vector<int> spaces = {0,1,2,3,4,5,6};
    cout << addSpaces(a, spaces);
    return 0;
}

string addSpaces(string s, vector<int>& spaces)
{
    string result;
    result.resize(s.size()+spaces.size());
    for(int i = 0, j = 0; i+j < s.size()+spaces.size(); ++i)
    {
        if(j < spaces.size() && spaces[j] == i)
            result[i+(j++)] = ' ';
        result[i+j] = s[i]; 
    }
    return result;
}