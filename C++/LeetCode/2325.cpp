//task https://leetcode.com/problems/decode-the-message/?envType=list&envId=rbos7rxs
#include <iostream>
#include <string>
#include <map>

using namespace std;

string decodeMessage(string key, string message);

int main()
{
    string a = "the quick brown fox jumps over the lazy dog", b = "vkbs bs t suepuv";
    cout << decodeMessage(a, b);
    return 0;
}

string decodeMessage(string key, string message)
{
    map<char, char> dict;
    char s = 'a'-1;
    for(const char& symb : key)
        if(symb != ' ' && !dict.contains(symb))
            dict[symb] = ++s;
    for(int i = 0; i < message.size(); ++i)
        if(message[i] != ' ')
            message[i] = dict[message[i]];
    return message;
}