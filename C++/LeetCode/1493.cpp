#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

int longestSubarray(vector<int>& nums)
{
    int sum_of_elements = accumulate(nums.begin(), nums.end(), 0);
    if(sum_of_elements == nums.size())
        return sum_of_elements-1;
    else if(sum_of_elements == 0)
        return 0;
    
    int left_len = 0, right_len = 0, max_len = 0;
    for(int i = 0; i < nums.size(); ++i)
        if(nums[i] != 0)
            ++right_len;
        else
        {
            if(i != nums.size()-1 && nums[i+1] == 0)
            {
                if(right_len != 0)
                {
                    max_len = max_len > right_len + left_len ? max_len : left_len + right_len;
                    right_len = 0;
                    left_len = 0;
                }
            }
            else
            {
                max_len = max_len > right_len + left_len ? max_len : left_len + right_len;
                left_len = right_len;
                right_len = 0;
            }
        }
    return max_len > right_len + left_len ? max_len : right_len + left_len;
        
}

int main()
{
    ifstream inp("input.txt");
    vector<int> test;
    while(!inp.eof())
    {
        int num;
        inp >> num;
        inp.ignore(1);
        test.push_back(num);
    }
    inp.close();

    cout << longestSubarray(test);
    return 0;
}