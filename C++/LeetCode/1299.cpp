//task https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/?envType=list&envId=rydfq9ic
#include <vector>

using namespace std;

vector<int> replaceElements(vector<int>& arr)
{
    int current_max_idx = 0, current_max = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        if(i == current_max_idx)
        {
            current_max = 0;
            for(int j = i+1; j < arr.size(); ++j)
                if(arr[j] > current_max)
                {
                    current_max = arr[j];
                    current_max_idx = j;
                }
        }
        arr[i] = current_max;
    }
    arr[arr.size()-1] = -1;
    return arr;
}