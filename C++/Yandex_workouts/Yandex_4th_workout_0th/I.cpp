#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    stack<char> brackets;
    bool good = true;
    char bracket;
    inp >> bracket;
    while(bracket >= 20 && bracket <= 125)
    {
        if(bracket == '(' || bracket == '{' || bracket == '[')
            brackets.push(bracket);
        else
        {
            if(!brackets.empty())
            {
                bool temp = (bracket == ')' && brackets.top() == '(') || 
                            (bracket == '}' && brackets.top() == '{') || 
                            (bracket == ']' && brackets.top() == '[');
                if(temp)
                    brackets.pop();
                else
                    good = false;
            }
            else
                good = false;
        }
        inp >> bracket;
    }
    inp.close();
    if(!brackets.empty())
        good = false;
    cout << (good ? "yes" : "no");
    return 0;
}