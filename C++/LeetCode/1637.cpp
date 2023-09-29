//task https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/?envType=list&envId=rcnviaid
#include <vector>
#include <algorithm>

using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>>& points)
{
    sort(points.begin(), points.end(), [](const auto& lhs, const auto& rhs)
                                        {
                                            return lhs[0] < rhs[0];
                                        });
    int max = 0;
    for(int i = 1; i < points.size(); ++i)
    {
        int distance = points[i][0] - points[i-1][0];
        if(distance > max)
            max = distance;
    }
    return max;
}