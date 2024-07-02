#include <iostream>
#include <vector>
#include <string>

using namespace std;

string numToLetter(char num)
{
    if(num == '2')
        return "abc";
    else if(num == '3')
        return "def";
    else if(num == '4')
        return "ghi";
    else if(num == '5')
        return "jkl";
    else if(num == '6')
        return "mno";
    else if(num == '7')
        return "pqrs";
    else if(num == '8')
        return "tuv";
    else if(num == '9')
        return "wxyz";
    return "";
}

void recursivePusher(vector<string>& result, const string& digits, string current_combination)
{
    if(current_combination.size() == digits.size())
        result.push_back(current_combination);
    else
    {
        char current_num = digits[current_combination.size()];
        for(char symb : numToLetter(current_num))
            recursivePusher(result, digits, current_combination + symb);
    }
}

vector<string> letterCombinations(string digits)
{
    if(digits.empty())
        return {};
    vector<string> result;
    recursivePusher(result, digits, "");
    return result;
}

int main()
{
    cout << "[";
    for(const auto& comb : letterCombinations("23"))
        cout << '\"' << comb << "\",";
    cout << "]";
    return 0;
}