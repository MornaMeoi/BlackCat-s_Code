//task https://leetcode.com/problems/check-if-the-sentence-is-pangram/?envType=list&envId=rbos7rxs
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool checkIfPangram(string sentence);

int main()
{
    string a = "leetcode";
    cout << checkIfPangram(a);
    return 0;
}

bool checkIfPangram(string sentence)
{
    unordered_map<char, int> dict;
    for(const char& symb : sentence)
        ++dict[symb];
    for(char symb = 'a'; symb <= 'z'; ++symb)
        if(dict[symb] == 0)
            return false;
    return true;
}