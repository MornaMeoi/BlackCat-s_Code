#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
    vector<vector<double>> distances(points.size());
    vector<vector<int>> result(k);
    for(int i = 0; i < points.size(); ++i)
        distances[i] = {sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]), static_cast<double>(i)};
    sort(distances.begin(), distances.end(), [](auto lhs, auto rhs){
        return lhs[0] < rhs[0];
    });
    for(int i = 0; i < k; ++i)
        result[i] = points[static_cast<int>(distances[i][1])];
    for(const auto& idx : distances)
        cout << "distance: " << idx[0] << " with idx: " << idx[1] << endl;
    return result;
}

int main()
{
    vector<vector<int>> nums = {{-5,4},{-6,-5},{4,6}}, answer = kClosest(nums, 2);
    for(const auto& pairs : answer)
    {
        cout << '[';
        for(int num : pairs)
            cout << num << ',';
        cout << "], ";
    }
    return 0;
}