#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N;
    inp >> N;
    vector<int64_t> nums(N);
    for(int i = 0; i < N; ++i)
        inp >> nums[i];
    int64_t x;
    inp >> x;
    inp.close();

    int counter = 0;
    for(int64_t& num : nums)
        if(num < x)
            ++counter;
    cout << counter << endl << N-counter;
    return 0;
}