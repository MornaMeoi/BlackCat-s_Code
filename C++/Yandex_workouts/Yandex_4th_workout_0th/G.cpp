#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool IsVerticalSquare(vector<vector<int>>& carrots, int N, int y, int x_first, int x_second)
{
    int counter = 1, distance = x_second - x_first + 1;
    bool flag = true;
    for(int i = y+1; i < N && flag && counter != distance; ++i)
    {
        for(int j = x_first; j <= x_second && flag; ++j)
            if(carrots[i][j] == 0)
                flag = false;
        if(flag)
            ++counter;
    }
    flag = true;
    for(int i = y-1; i >= 0 && flag && counter != distance; --i)
    {
        for(int j = x_first; j <= x_second && flag; ++j)
            if(carrots[i][j] == 0)
                flag = false;
        if(flag)
            ++counter;
    }
    return counter == distance;
}

bool IsHorizontalSquare(vector<vector<int>>& carrots, int M, int x, int y_first, int y_second)
{
    int counter = 1, distance = y_second - y_first + 1;
    bool flag = true;
    for(int j = x+1; j < M && flag && counter != distance; ++j)
    {
        for(int i = y_first; i <= y_second && flag; ++i)
            if(carrots[i][j] == 0)
                flag = false;
        if(flag)
            ++counter;
    }
    flag = true;
    for(int j = x-1; j >= 0 && flag && counter != distance; --j)
    {
        for(int i = y_first; i <= y_second && flag; ++i)
            if(carrots[i][j] == 0)
                flag = false;
        if(flag)
            ++counter;
    }
    return counter == distance;
}

int main()
{
    ifstream inp("input.txt");
    int N, M;
    inp >> N >> M;
    vector<vector<int>> carrots(N);
    for(int i = 0; i < N; ++i)
    {
        carrots[i].resize(M);
        for(int j = 0; j < M; ++j)
            inp >> carrots[i][j];
    }
    inp.close();
    int current_max = 0;
    for(int i = 0; i < N; ++i)
    {
        int first_idx = -1;
        for(int j = 0; j < M; ++j)
        {
            if(carrots[i][j] == 1 && first_idx == -1)
            {
                first_idx = j;
                if(current_max == 0)
                    ++current_max;
            }
            else if(carrots[i][j] == 0 && first_idx != -1)
            {
                if(current_max < j - first_idx && IsVerticalSquare(carrots, N, i, first_idx, j-1))
                    current_max = j - first_idx;
                first_idx = -1;
            }
        }
        if(first_idx != -1 && carrots[i][M-1] == 1 && current_max < M - first_idx && IsVerticalSquare(carrots, N, i, first_idx, M-1))
            current_max = M - first_idx;
    }

    for(int j = 0; j < M; ++j)
    {
        int first_idx = -1;
        for(int i = 0; i < N; ++i)
        {
            if(carrots[i][j] == 1 && first_idx == -1)
            {
                first_idx = i;
                if(current_max == 0)
                    ++current_max;
            }
            else if(carrots[i][j] == 0 && first_idx != -1)
            {
                if(current_max < i - first_idx && IsHorizontalSquare(carrots, M, j, first_idx, i-1))
                    current_max = i - first_idx;
                first_idx = -1;
            }
        }
        if(first_idx != -1 && carrots[N-1][j] == 1 && current_max < N - first_idx && IsHorizontalSquare(carrots, M, j, first_idx, N-1))
            current_max = N - first_idx;
    }

    cout << current_max;
    return 0;
}