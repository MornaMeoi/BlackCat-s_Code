#include <stdio.h>

int recursive_horse(int num, int depth, int N)
{
    if((depth == N-1 || num == 5))
        return 1;
    else if(num == 1)
        return recursive_horse(8, depth+1, N) + recursive_horse(6, depth+1, N);
    else if(num == 2)
        return recursive_horse(7, depth+1, N) + recursive_horse(9, depth+1, N);
    else if(num == 3)
        return recursive_horse(4, depth+1, N) + recursive_horse(8, depth+1, N);
    else if(num == 4)
        return recursive_horse(9, depth+1, N) + recursive_horse(3, depth+1, N) + recursive_horse(0, depth+1, N);
    else if(num == 6)
        return recursive_horse(7, depth+1, N) + recursive_horse(1, depth+1, N) + recursive_horse(0, depth+1, N);
    else if(num == 7)
        return recursive_horse(2, depth+1, N) + recursive_horse(6, depth+1, N);
    else if(num == 8)
        return recursive_horse(1, depth+1, N) + recursive_horse(3, depth+1, N);
    else if(num == 9)
        return recursive_horse(4, depth+1, N) + recursive_horse(2, depth+1, N);
    else if(num == 0)
        return recursive_horse(4, depth+1, N) + recursive_horse(6, depth+1, N);
}

int main()
{
    int N, result = 0;
    scanf("%d", &N);
    for(int i = 0; i <= 9; ++i)
        if(i == 0 || i == 5 || i == 8)
            continue;
        else
            result += recursive_horse(i, 0, N);
    if(N == 1)
        ++result;
    printf("%d\n", result);
    return 0;
}