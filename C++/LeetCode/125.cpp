//Task: https://leetcode.com/problems/valid-palindrome
//Difficulty: Easy
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    string changed_s(s.size(), ' ');
    size_t j = 0;
    for(size_t i = 0; i < s.size(); ++i)
        if(isalnum(s[i]))
            changed_s[j++] = tolower(s[i]);
    changed_s.resize(j);

    bool result = true;
    for(size_t i = 0; i < changed_s.size() / 2; ++i)
        if(changed_s[i] != changed_s[changed_s.size()-i-1])
        {
            result = false;
            break;
        }
    return result;
}

int main()
{
    ifstream inp("input.txt");
    string symbols;
    getline(inp, symbols);
    inp.close();

    cout << isPalindrome(symbols) << endl;
    /*for(char symb : symbols)
        cout << symb;
    cout << endl;*/
    return 0;
}