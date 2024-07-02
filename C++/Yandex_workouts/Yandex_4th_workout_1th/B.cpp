#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int64_t partition(vector<int64_t>& nums, int low, int high)
{
    srand(time(NULL));
    int64_t pivot = nums[rand() % (high - low) + low];
    while(true)
    {
        for(;nums[low] < pivot; ++low); 
        for(;nums[high] > pivot; --high);
        if(low >= high)
            return high;
        swap(nums[low++], nums[high--]);
    }
}

void quick_sort(vector<int64_t>& nums, int low, int high)
{
    if(low < high)
    {
        int64_t p = partition(nums, low, high);
        quick_sort(nums, low, p);
        quick_sort(nums, p+1, high);
    }
}

int main()
{
    ifstream inp("input.txt");
    int N;
    inp >> N;
    vector<int64_t> nums(N);
    for(int i = 0; i < N; ++i)
        inp >> nums[i];
    inp.close();

    quick_sort(nums, 0, N-1);
    for(int64_t num : nums)
        cout << num << ' ';
    return 0;
}