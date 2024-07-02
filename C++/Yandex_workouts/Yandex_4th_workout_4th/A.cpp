#include <iostream>
#include <string>

using namespace std;

void perm(string num, int num_el)
{
    if(num_el == num.size()-1)
        cout << num << endl;
    else
        for(int i = 0; num_el < num.size()-1 && i < num.size()-num_el; ++i)
        {
            perm(num, num_el+1);
            swap(num[num_el], num[num_el+i+1]);
        }
}

int main()
{
    int N;
    cin >> N;

    string num;
    for(char i = '1'; i <= '0'+N; ++i)
        num.push_back(i);
    if(N == 1)
        cout << 1;
    perm(num, 0);
    return 0;
}