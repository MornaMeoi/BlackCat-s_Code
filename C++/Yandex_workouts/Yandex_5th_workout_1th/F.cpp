#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int n, num;
    bool odd = false;
    inp >> n >> num;
    while(--n > 0 && !(num % 2))
    {
        inp >> num;
        cout << '+';
    }
    for(int i = 0; i < n; ++i)
    {
        inp >> num;
        if(num % 2)
            cout << 'x';
        else
            cout << '+';
        
    }
    inp.close();
    return 0;
}