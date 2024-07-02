#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void PrintArr(const vector<int64_t>& arr)
{
    for(const int64_t& num : arr)
        cout << num << ' ';
    cout << endl;
}

void Merge(vector<int64_t>& arr, int left, int mid, int right)
{
    int it1 = 0, it2 = 0;
    vector<int64_t> result(right - left);
    while(left + it1 < mid && mid + it2 < right)
        if(arr[left + it1] < arr[mid + it2])
        {
            result[it1 + it2] = arr[left + it1];
            ++it1;
        }
        else
        {
            result[it1 + it2] = arr[mid + it2];
            ++it2;
        }
    while(left + it1 < mid)
    {
        result[it1 + it2] = arr[left + it1];
        ++it1;
    }
    while(mid + it2 < right)
    {
        result[it1 + it2] = arr[mid + it2];
        ++it2;
    }
    for(int i = 0; i < it1 + it2; ++i)
        arr[left + i] = result[i];
}

void MergeSort(vector<int64_t>& arr, int n)
{
    for(int i = 1; i < n; i *= 2)
        for(int j = 0; j < n - i; j += 2 * i)
            Merge(arr, j, j + i, min(j + 2 * i, n));
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

    MergeSort(nums, N);
    PrintArr(nums);
    return 0;
}