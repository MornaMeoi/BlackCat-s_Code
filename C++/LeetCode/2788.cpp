//task https://leetcode.com/problems/split-strings-by-separator/?envType=list&envId=rbos7rxs
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitWordsBySeparator(vector<string>& words, char separator);

int main()
{
    vector<string> a = {"one.two.three","four.five","six"};
    char sep = '.';
    for(const string& word : splitWordsBySeparator(a, sep))
        cout << word << ", ";
    return 0;
}

vector<string> splitWordsBySeparator(vector<string>& words, char separator)
{
    vector<string> result;
    for(const string& el : words)
    {
        string temp;
        for(const char& symb : el)
            if(symb == separator)
            {
                if(!temp.empty())
                    result.push_back(temp);
                temp.clear();
            }
            else
                temp.push_back(symb);
        if(!temp.empty())
            result.push_back(temp);
    }
    return result;
}