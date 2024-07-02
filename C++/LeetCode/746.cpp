//task https://leetcode.com/problems/min-cost-climbing-stairs/?envType=daily-question&envId=2023-10-13
#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost);

int main()
{
    vector<int> a = {10,15,20};
    vector<int> b = {1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs(a);
    return 0;
}

int minCostClimbingStairs(vector<int>& cost)
{
    for(int i = cost.size()-2; i >= 0; --i)
        cost[i] = min(cost[i+1], cost[i+2]) + cost[i];
    return cost[0];
}