#include <iostream>
#include <vector>

using namespace std;

bool checkRows(vector<vector<char>>& board)
{
    bool good = true;
    for(int i = 0; i < board.size() && good; ++i)
    {
        vector<bool> hash(9, false);
        for(int j = 0; j < board.size(); ++j)
        {
            if(board[i][j] != '.')
            {
                int num_hash = board[i][j] - '0' - 1;
                if(hash[num_hash])
                {
                    good = false;
                    break;
                }
                else
                    hash[num_hash] = true;
            }
        }
    }
    return good;
}

bool checkColumns(vector<vector<char>>& board)
{
    bool good = true;
    for(int j = 0; j < board.size() && good; ++j)
    {
        vector<bool> hash(9, false);
        for(int i = 0; i < board.size(); ++i)
        {
            if(board[i][j] != '.')
            {
                int num_hash = board[i][j] - '0' - 1;
                if(hash[num_hash])
                {
                    good = false;
                    break;
                }
                else
                    hash[num_hash] = true;
            }
        }
    }
    return good;
}

bool checkSquares(vector<vector<char>>& board)
{
    bool good = true;
    for(int k = 0; k < 9 && good; ++k)
    {
        vector<bool> hash(9, false);
        for(int i = k / 3 * 3; i < k / 3 * 3 + 3 && good; ++i)
        {
            for(int j = k % 3 * 3; j < k % 3 * 3 + 3 && good; ++j)
            {
                if(board[i][j] != '.')
                {
                    int num_hash = board[i][j] - '0' - 1;
                    if(hash[num_hash])
                        good = false;
                    else
                        hash[num_hash] = true;
                }
            }
        }
    }
    return good;
}

bool isValidSudoku(vector<vector<char>>& board)
{
    return checkRows(board) && checkColumns(board) && checkSquares(board);
}

int main()
{
    vector<vector<char>> board = {{'5','3','.','.','7','5','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','.','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    cout << isValidSudoku(board);
    return 0;
}