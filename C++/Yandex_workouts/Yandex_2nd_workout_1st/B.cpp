#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct point
{
    point()
    {
        x = 0;
        y = 0;
    }
    point(int x_val, int y_val)
    {
        x = x_val;
        y = y_val;
    }
    int x;
    int y;
};

ifstream& operator >> (ifstream& input, point& p)
{
    input >> p.x >> p.y;
    return input;
}

bool operator == (const point& lhs, const point& rhs)
{
    return lhs.x == rhs.x && lhs.y && rhs.y;
}

int operator % (const point& lhs, const point& rhs)
{
    int temp1 = min(lhs.x, rhs.x) != 0 ? max(lhs.x, rhs.x)%min(lhs.x, rhs.x) : 0;
    int temp2 = min(lhs.y, rhs.y) != 0 ? max(lhs.y, rhs.y)%min(lhs.y, rhs.y) : 0;
    return temp1 + temp2;
}

point direction(const point& lhs, const point& rhs)
{
    return point(abs(lhs.x-rhs.x), abs(lhs.y-rhs.y));
}

int distance(const point& lhs, const point& rhs)
{
    point temp = direction(lhs, rhs);
    return temp.x*temp.x + temp.y*temp.y;
}

bool parallel_and_equality_check(const point& first, const point& second, const point& third, const point& fourth)
{
    point temp1 = direction(first, second), temp2 = direction(third, fourth);
    return temp1%temp2 == 0 && distance(first, second) == distance(third, fourth);
}

int main()
{
    ifstream inp("input.txt");
    int N;
    inp >> N;
    for(int i = 0; i < N; ++i)
    {
        vector<point> points;
        for(int i = 0; i < 4; ++i)
        {
            point temp;
            inp >> temp;
            points.push_back(temp);
        }
        bool flag = true;
        for(int i = 0; i < 3 && flag; ++i)
            for(int j = i+1; j < 4 && flag; ++j)
                if(points[i] == points[j])
                    flag = false;
        if(flag)
        {
            if(parallel_and_equality_check(points[0], points[1], points[2], points[3]) ||
            parallel_and_equality_check(points[0], points[2], points[1], points[3]) ||
            parallel_and_equality_check(points[0], points[3], points[1], points[2]))
                flag = true;
            else
                flag = false;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    inp.close();
    return 0;
}