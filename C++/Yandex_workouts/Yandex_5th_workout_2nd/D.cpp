#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int calculate_cell_add(const vector<vector<bool>>& board, int x, int y)
{
    if(board[x][y])
        return (x == 0 || !board[x-1][y]) + (x == 7 || !board[x+1][y]) + (y == 0 || !board[x][y-1]) + (y == 7 || !board[x][y+1]);
    return 0;
}

int main()
{
    ifstream inp("input.txt");
    int N;
    inp >> N;
    vector<vector<bool>> board(8);
    for(int i = 0; i < 8; ++i)
        board[i].resize(8, false);
    int x, y;
    for(int i = 0; i < N; ++i)
    {
        inp >> x >> y;
        board[x-1][y-1] = true;
    }
    inp.close();

    int result = 0;
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            result += calculate_cell_add(board, i, j);
    cout << result;
    return 0;
}