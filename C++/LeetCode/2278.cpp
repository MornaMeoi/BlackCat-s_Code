//task https://leetcode.com/problems/percentage-of-letter-in-string/?envType=list&envId=rbos7rxs
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int percentageLetter(string s, char letter);

int main()
{
    string a = "matirkzqfldylniwlunkqwojborxkyynhr";
    char c = 'u';
    cout << percentageLetter(a, c);
    return 0;
}

int percentageLetter(string s, char letter)
{
    return count(s.begin(), s.end(), letter)/static_cast<float>(s.size()) * 100 + 0.00001;
}