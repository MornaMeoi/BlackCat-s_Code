#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    int result = 0;
    if(m == 1 || n == 1)    
        return 1;
    else
        result += uniquePaths(m-1, n) + uniquePaths(m, n-1);
    return result;
}

int main()
{
    cout << uniquePaths(51, 9);
    return 0;
}