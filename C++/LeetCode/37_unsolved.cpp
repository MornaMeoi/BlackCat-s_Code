#include <iostream>
#include <vector>
#include <utility>

#define LEN 9

using namespace std;

void printBoard(const vector<vector<char>>& board);
bool inRow(const vector<char>& row, char num);
bool inCol(const vector<vector<char>>& board, char num, int col_num);
bool inSquare(const vector<vector<char>>& board, char num, int row_num, int col_num);
vector<vector<char>> recursiveRunner(vector<vector<char>> board, int i, int j);
void solveSudoku(vector<vector<char>>& board);

int main()
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);
    printBoard(board);
    return 0;
}

void printBoard(const vector<vector<char>>& board)
{
    for(int i = 0; i < LEN; ++i)
    {
        for(int j = 0; j < LEN; ++j)
        {
            cout << board[i][j];
            if((j+1)%3 == 0)
                cout << "  ";
        }
        cout << endl;
        if((i+1)%3 == 0)
            cout << endl;
    }
}

bool inRow(const vector<char>& row, char num)
{
    for(int n : row)
        if(n == num)
            return true;
    return false;
}
bool inCol(const vector<vector<char>>& board, char num, int col_num)
{
    for(int i = 0; i < LEN; ++i)
        if(board[i][col_num] == num)
            return true;
    return false;
}

bool inSquare(const vector<vector<char>>& board, char num, int row_num, int col_num)
{
    int sq_row = row_num/3*3, sq_col = col_num/3*3;
    for(int i = sq_row; i < sq_row+3; ++i)
        for(int j = sq_col; j < sq_col+3; ++j)
            if(board[i][j] == num)
                return true;
    return false;
}

pair<int, int> incrementCords(int x, int y)
{
    if(y == 8)
    {
        ++x;
        y = 0;
    }
    else
        ++y;
    return {x, y};
}

vector<vector<char>> recursiveRunner(vector<vector<char>> board, pair<int, int> cords)
{
    //cout << i << ' ' << j << endl;
    //printBoard(board);
    if(board[cords.first][cords.second] != '.')
    {
        pair<int, int> new_cords = incrementCords(cords.first, cords.second);
        return recursiveRunner(board, new_cords);
    }
    else
    {
        int counter = 0;
        for(char num = '1'; num <= '9'; ++num)
        {
            //cout << i << ' ' << j << ' ' << num << endl;
            if(inRow(board[cords.first], num) || inCol(board, num, cords.second) || inSquare(board, num, cords.first, cords.second))
                ++counter;
            else
            {
                board[cords.first][cords.second] = num;
                if(cords.first == 8 && cords.second == 8)
                    return board;
                pair<int, int> new_cords = incrementCords(cords.first, cords.second);
                vector<vector<char>> new_board = recursiveRunner(board, new_cords);
                if(new_board.size() != 0)
                    return new_board;
            }
        }
        if(counter == 9)
            return {};
        return board;
    }
}

void solveSudoku(vector<vector<char>>& board)
{
    board = recursiveRunner(board, {0, 0});
}