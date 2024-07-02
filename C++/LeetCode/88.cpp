//task https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main()
{
    vector<int> a = {0}, b = {1};
    int first = 0, second = 1;
    merge(a, first, b, second);
    for(int num : a)
        cout << num << ' ';
    return 0;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    for(int i = m+n-1; i != 0 && m > 0 && n > 0; --i)
    {
        if(nums1[m-1] > nums2[n-1])
            nums1[i] = nums1[--m];
        else
            nums1[i] = nums2[--n];
    }
    while(--n >= 0)
        nums1[n] = nums2[n];
}