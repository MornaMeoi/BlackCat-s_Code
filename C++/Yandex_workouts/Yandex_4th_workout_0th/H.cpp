#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int a, b, n;
    inp >> a >> b >> n;
    inp.close();
    cout << (a > ((b-1) / n) + 1 ? "Yes" : "No");
    return 0;
}