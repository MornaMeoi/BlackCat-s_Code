#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int G1, G2, G3, G4, home;
    inp >> G1;
    inp.ignore(1);
    inp >> G2 >> G3;
    inp.ignore(1);
    inp >> G4 >> home;
    --home;
    inp.close();

    int result = G2 - G1 + G4 - G3, guest = home ? G4 - G1 : G2 - result - G3;
    if(guest >= 0)
        ++result;
    cout << (result < 0 ? 0 : result);
    return 0;
}