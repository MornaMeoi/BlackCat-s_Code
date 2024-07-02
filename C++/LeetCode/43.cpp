#include <iostream>
#include <cmath>

using namespace std;

string SumStrings(string num1, string num2)
{
    string prefix(labs(num1.size() - num2.size()), '0');
    if(num1.size() < num2.size())
        num1 = prefix + num1;
    else
        num2 = prefix + num2;
    string result(num1.size() + 1, '0');
    for(int i = num1.size()-1; i >= 0; --i)
    {
        result[i+1] += num1[i] + num2[i] - 96;
        if(result[i+1] > '9')
        {
            ++result[i];
            result[i+1] -= 10;
        }
        
    }
    if(result[0] == '0')
        result.erase(0, 1);
    return result;
}

string multiply_one_dig(const string& lhs, char rhs)
{
    if(rhs == '0')
        return "0";
    string result(lhs.size()+1, 0);
    for(int i = lhs.size()-1; i >= 0; --i)
    {
        result[i+1] += (lhs[i] - '0') * (rhs - '0');
        if(result[i+1] > 0)
        {
            result[i] += result[i+1] / 10;
            result[i+1] %= 10;
        }
    }
    if(result[0] == 0)
        result.erase(0, 1);
    for(int i = 0; i < result.size(); ++i)
        result[i] += '0';
    return result;
}

string multiply(string num1, string num2)
{
    if(num1 == "0")
        return "0";
    string result = "", postfix = "";
    for(int i = num2.size()-1; i >= 0; --i)
    {
        result = SumStrings(result, multiply_one_dig(num1, num2[i]) + postfix);
        postfix.push_back('0');
    }
    return result;
}

int main()
{
    string num1 = "0", num2 = "134";
    cout << multiply(num1, num2);
    return 0;   
}