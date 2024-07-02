#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N, max_len = 0, sum_len = 0;
    inp >> N;
    int num;
    for(int i = 0; i < N; ++i)
    {
        inp >> num;
        if(num > max_len)
            max_len = num;
        sum_len += num;
    }
    inp.close();

    if(max_len > sum_len - max_len)
        cout << max_len - sum_len + max_len;
    else
        cout << sum_len;
    return 0;
}