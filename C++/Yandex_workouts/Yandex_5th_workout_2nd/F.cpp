#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int max_in_range(const vector<int>& nums, int start, int finish)
{
    int max_val = nums[start];
    for(int i = start; i < finish; ++i)
        if(nums[i] > max_val)
            max_val = nums[i];
    return max_val;
}

int main()
{
    ifstream inp("input.txt");
    int n;
    inp >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
        inp >> nums[i];
    int a, b, k;
    inp >> a >> b >> k;
    inp.close();

    if((b - a) / (n * k) > 0)
        cout << max_in_range(nums, 0, nums.size());
    else
    {
        a %= n * k;
        b %= n * k;
        if(b < a)
            cout << max({max_in_range(nums, 0, (b - 1) / k + 1), max_in_range(nums, (a - 1) / k, nums.size()),
                         max_in_range(nums, 0, nums.size() - (a - k - 1) / k + 1), max_in_range(nums, nums.size() - (b - k - 1) / k, nums.size())});
        else
            cout << max(max_in_range(nums, a % k, b % k + 1), max_in_range(nums, nums.size() - (b - k - 1) / k - 1, nums.size() - (a - k - 1) / k));
    }
    return 0;
}