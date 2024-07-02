#include <stdio.h>

int myMin(int lhs, int rhs)
{
    return lhs < rhs ? lhs : rhs;
}

int maxArea(int* height, int heightSize)
{
    int left = 0, right = heightSize-1, result = myMin(height[0], height[1]);
    while(left < right)
    {
        int current_volume = myMin(height[left], height[right]) * (right - left);
        if(current_volume > result)
            result = current_volume;
        if(height[left] < height[right])
            ++left;
        else
            --right;
    }
    return result;
}

int main()
{
    int nums[] = {1,8,6,2,5,4,8,3,7};
    printf("%d", maxArea(nums, 9));
    return 0;
}