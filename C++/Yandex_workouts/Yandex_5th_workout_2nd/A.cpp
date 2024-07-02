#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int K;
    inp >> K;
    int min_x, min_y;
    inp >> min_x >> min_y;
    int max_x = min_x, max_y = min_y, x, y;
    for(int i = 0; i < K - 1; ++i)
    {
        inp >> x >> y;
        if(x < min_x)
            min_x = x;
        else if(x > max_x)
            max_x = x;
        if(y < min_y)
            min_y = y;
        else if(y > max_y)
            max_y = y;
    }
    inp.close();

    cout << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y;
    return 0;
}