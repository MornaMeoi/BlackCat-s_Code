//task https://leetcode.com/problems/decompress-run-length-encoded-list/?envType=list&envId=rydfq9ic
#include <vector>

using namespace std;

vector<int> decompressRLElist(vector<int>& nums)
{
    vector<int> decompressed;
    for(int i = 0; i < nums.size(); i += 2)
        decompressed.resize(decompressed.size() + nums[i], nums[i+1]);
    return decompressed;
}