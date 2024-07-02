#include <stdio.h>
#include <stdlib.h>

long long partition(long long *nums, int low, int high)
{
    long long pivot = nums[(low + high) / 2];
    while(1)
    {
        for(;nums[low] < pivot; ++low); 
        for(;nums[high] > pivot; --high);
        if(low >= high)
            return high;
        nums[low] ^= nums[high] ^= nums[low] ^= nums[high];
        ++low;
        --high;
    }
}

void quick_sort(long long *nums, int low, int high)
{
    if(low < high)
    {
        long long p = partition(nums, low, high);
        quick_sort(nums, low, p);
        quick_sort(nums, p+1, high);
    }
}

int main()
{
    FILE *inp = fopen("19", "r");
    int N;
    fscanf(inp, "%d", &N);
    long long *nums = (long long *)malloc(N * sizeof(long long));
    for(long long *num = nums; num - nums < N; ++num)
        fscanf(inp, "%lld", num);
    fclose(inp);

    quick_sort(nums, 0, N-1);
    for(int i = 0; i < N; ++i)
        printf("%lld ", nums[i]);
    free(nums);
    return 0;
}