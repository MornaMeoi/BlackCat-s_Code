//Task: https://leetcode.com/problems/move-zeroes
//Difficulty: Easy
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums)
{
    size_t j = 0;
    for(size_t i = 0; i < nums.size(); ++i)
        if(nums[i] != 0)
            nums[j++] = nums[i];
    for(size_t i = j; i < nums.size(); ++i)
        nums[i] = 0;
}

int main()
{
    ifstream inp("input.txt");
    vector<int> nums;
    inp.ignore(8);
    while(!inp.eof())
    {
        int num;
        inp >> num;
        if(!inp.eof())
            nums.push_back(num);
        inp.ignore(1);
    }
    inp.close();

    for(int num : nums)
        cout << num << ' ';
    cout << endl;

    moveZeroes(nums);

    for(int num : nums)
        cout << num << ' ';
    cout << endl;
    return 0;
}