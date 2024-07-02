#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    string line, word, prefix;
    getline(inp, line);
    stringstream temp(line);
    unordered_set<string> dictionary;
    while(!temp.eof())
    {
        temp >> word;
        dictionary.insert(word);
    }
    getline(inp, line);
    temp = stringstream(line);
    while(!temp.eof())
    {
        bool in_dict = false;
        temp >> word;
        for(auto it = word.begin(); it != word.end(); ++it)
        {
            prefix = {word.begin(), it};
            if(dictionary.contains(prefix))
            {
                cout << prefix << ' ';
                in_dict = true;
                break;
            }
        }
        if(!in_dict)
            cout << word << ' ';
    }
    inp.close();
    return 0;
}