#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>

using namespace std;

int count_soldiers_progresion(int x, int p)
{
    int answer = 0;
    while(x > 0 && p > 0)
    {
        ++answer;
        x -= p;
        p -= x;
    }
    if(p <= 0)
        return answer + 1;
    else
        return -1;
}

int main()
{
    ifstream inp("input.txt");
    double x, y, p;
    inp >> x >> y >> p;
    inp.close();

    y -= x;
    if(y <= 0)
        cout << 1;
    else if(p >= x && y - x <= 0)
    {
        int i = 0;
        p -= x - y;
        int prog = count_soldiers_progresion(x, p);
        if(prog != -1)
            cout << prog + 1;
        else
            cout << prog;
    }
    else if(x > p)
    {
        int answer = numeric_limits<int>::max(), counter = 1, prog = -1;
        while(y > 0)
        {
            if(y < x)
            {
                p -= x - y;
                prog = count_soldiers_progresion(x, p);
                p += x - y;
            }
            if(prog != -1)
                answer = min(answer, counter + prog);
            y -= x - p;
            ++counter;
        }
        if(answer != numeric_limits<int>::max())
            cout << answer;
        else
            cout << counter + 1;
    }
    else
        cout << -1;
    return 0;
}