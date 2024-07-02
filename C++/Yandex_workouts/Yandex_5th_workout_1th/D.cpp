#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int rook(vector<vector<char>>& board, int row, int col)
{
    int result = 1;
    for(int i = row+1; i < board.size() && board[i][col] != 'R' && board[i][col] != 'B'; ++i)
        if(board[i][col] == '*')
        {
            board[i][col] = '+';
            ++result;
        }
    for(int i = row-1; i >= 0 && board[i][col] != 'R' && board[i][col] != 'B'; --i)
        if(board[i][col] == '*')
        {
            board[i][col] = '+';
            ++result;
        }
    for(int j = col+1; j < board[0].size() && board[row][j] != 'R' && board[row][j] != 'B'; ++j)
        if(board[row][j] == '*')
        {
            board[row][j] = '+';
            ++result;
        }
    for(int j = col-1; j >= 0 && board[row][j] != 'R' && board[row][j] != 'B'; --j)
        if(board[row][j] == '*')
        {
            board[row][j] = '+';
            ++result;
        }
    return result;
}

int bishop(vector<vector<char>>& board, int row, int col)
{
    int result = 1;
    for(int i = row+1, j = col+1; i < board.size() && j < board[0].size() && board[i][j] != 'R' && board[i][j] != 'B'; ++i, ++j)
        if(board[i][j] == '*')
        {
            board[i][j] = '+';
            ++result;
        }
    for(int i = row-1, j = col-1; i >= 0 && j >= 0 && board[i][j] != 'R' && board[i][j] != 'B'; --i, --j)
        if(board[i][j] == '*')
        {
            board[i][j] = '+';
            ++result;
        }
    for(int i = row-1, j = col+1; i >= 0 && j < board[0].size() && board[i][j] != 'R' && board[i][j] != 'B'; ++j, --i)
        if(board[i][j] == '*')
        {
            board[i][j] = '+';
            ++result;
        }
    for(int i = row+1, j = col-1; j >= 0 && i < board.size() && board[i][j] != 'R' && board[i][j] != 'B'; --j, ++i)
        if(board[i][j] == '*')
        {
            board[i][j] = '+';
            ++result;
        }
    return result;
}

int main()
{
    ifstream inp("input.txt");
    vector<vector<char>> board(8);
    for(int i = 0; i < 8; ++i)
    {
        board[i].resize(8);
        for(int j = 0; j < 8; ++j)
            inp >> board[i][j];
        while(inp.peek() == ' ')
            inp.ignore(1);
        inp.ignore(1);
    }
    inp.close();

    int result = 0;
    for(int i = 0; i < board.size(); ++i)
        for(int j = 0; j < board[0].size(); ++j)
        {
            if(board[i][j] == 'R')
                result += rook(board, i, j);
            else if(board[i][j] == 'B')
                result += bishop(board, i, j);
        }
    cout << 64 - result;
    return 0;
}