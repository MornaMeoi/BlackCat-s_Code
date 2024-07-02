#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    long double x1, y1, x2, y2;
    inp >> x1 >> y1 >> x2 >> y2;
    inp.close();
    long double first_rad = sqrtl(x1*x1 + y1*y1), second_rad = sqrtl(x2*x2 + y2*y2);
    if(first_rad == 0 || second_rad == 0)
        cout << (second_rad == 0 ? first_rad : second_rad);
    else
    {
        long double radial = first_rad + second_rad;

        long double rounded = (x1*x2 + y1*y2)/(first_rad*second_rad);
        if(rounded > 1)
            rounded = 1;
        else if(rounded < -1)
            rounded = -1;
        rounded = fabsl(first_rad-second_rad) + acosl(rounded) * min(first_rad, second_rad);
        cout.precision(14);
        cout << min(radial, rounded);
    }
    return 0;
}