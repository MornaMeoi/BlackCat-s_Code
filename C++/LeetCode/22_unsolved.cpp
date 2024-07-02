// https://leetcode.com/problems/generate-parentheses/?envType=list&envId=pk7n9gli
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string generateString(string& str, int num)
{
    if(num == 1)
    {
        str.push_back('(');
        str.push_back(')');
    }
    else
    {
        
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    if(n == 1)
    return result;
}

int main()
{
    return 0;
}