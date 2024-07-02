#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int t;
    inp >> t;
    int64_t n, a, b;
    for(int i = 0; i < t; ++i)
    {
        inp >> n >> a >> b;
        cout << (n%a > (n/a)*(b-a) ? "NO" : "YES") << endl;
    }
    inp.close();
    return 0;
}