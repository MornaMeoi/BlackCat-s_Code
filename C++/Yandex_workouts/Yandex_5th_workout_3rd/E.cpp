#include <iostream>
#include <fstream>
#include <unordered_set>
#include <set>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int n, num;
    set<int> nums;
    unordered_set<int> first, second, third;
    for(int i = 0; i < 3; ++i)
    {
        inp >> n;
        for(int j = 0; j < n; ++j)
        {
            inp >> num;
            nums.insert(num);
            if(i == 0)
                first.insert(num);
            else if(i == 1)
                second.insert(num);
            else
                third.insert(num);
        }
    }
    inp.close();

    for(int number : nums)
    {
        n = first.contains(number) + second.contains(number) + third.contains(number);
        if(n > 1)
            cout << number << ' ';
    }
    return 0;
}