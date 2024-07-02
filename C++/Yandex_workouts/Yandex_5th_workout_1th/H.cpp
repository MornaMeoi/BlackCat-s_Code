#include <iostream>
#include <fstream>
#include <cinttypes>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

long double calculate_intersection(int64_t L, int64_t x1, int64_t v1, int64_t x2, int64_t v2)
{
    long double v = static_cast<long double>(v1);
    if(v1 * v2 >= 0)
    {
        if((abs(v2) > abs(v1) && v2 > 0) || (abs(v2) < abs(v1) && v1 < 0))
            return (x1 + L - x2) / abs(abs(v) - abs(v2));
        else
            return (x2 - x1) / abs(abs(v) - abs(v2));
    }
    else
    {
        if(v1 > 0 && v2 < 0)
            return (x2 - x1) / (abs(v) + abs(v2));
        else
            return (x1 + L - x2) / abs(abs(v) + abs(v2));
    }
}

int main()
{
    ifstream inp("input.txt");
    int64_t L, x1, v1, x2, v2;
    inp >> L >> x1 >> v1 >> x2 >> v2;
    inp.close();

    if(x1 > x2)
    {
        swap(x1, x2);
        swap(v1, v2);
    }
    
    if(x1 == x2 || x1 == L - x2)
        cout << "YES\n" << 0;
    else if(v1 == 0 && v2 == 0)
        cout << "NO\n";
    else if(v1 == v2)
    {
        cout << "YES\n";
        cout << setprecision(12);
        x2 = L - x2;
        v2 *= -1;
        if(x1 > x2)
        {
            swap(x1, x2);
            swap(v1, v2);
        }
        cout << calculate_intersection(L, x1, v1, x2, v2);
    }
    else
    {
        cout << "YES\n";
        cout << setprecision(12);
        long double time_to_encounter = calculate_intersection(L, x1, v1, x2, v2);

        x2 = L - x2;
        v2 *= -1;
        if(x1 > x2)
        {
            swap(x1, x2);
            swap(v1, v2);
        }
        long double time_to_even = calculate_intersection(L, x1, v1, x2, v2);
        cout << min(time_to_encounter, time_to_even);
    }
    return 0;
}