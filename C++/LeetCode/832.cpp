//task https://leetcode.com/problems/flipping-an-image/?envType=list&envId=rydfq9ic
#include <vector>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
{
    int len = image.size();
    for(int i = 0; i < len; ++i)
    {
        if(len % 2 == 1)
            image[i][len/2] = !image[i][len/2];
        for(int j = 0; j < len/2; ++j)
        {
            swap(image[i][j], image[i][len-j-1]);
            image[i][j] = !image[i][j];
            image[i][len-j-1] = !image[i][len-j-1];
        }
    }
    return image;
}