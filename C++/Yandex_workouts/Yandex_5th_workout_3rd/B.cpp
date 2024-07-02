#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    unordered_map<char, int> first, second;
    string word;
    inp >> word;
    for(char symb : word)
        ++first[symb];
    inp >> word;
    for(char symb : word)
        ++second[symb];
    inp.close();

    cout << (first == second ? "YES" : "NO");
    return 0;
}