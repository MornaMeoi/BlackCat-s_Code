#include <iostream>
#include <vector>
#include <exception>

using namespace std;

void EnsurePositivity(const int& num_rows, const int& num_cols)
{
    if(num_rows < 0 || num_cols < 0)
    {
        throw out_of_range("EnsurePositivity()");
    }
}

void EnsureLessThanMatrixSize(const vector<int>& m, const int& columns, const int& num_row, const int& num_col)
{
    if(num_row >= m.size() / columns || num_col >= columns)
    {
        throw out_of_range("EnsureLessThanMatrixSize()");
    }
}

class Matrix
{
public:
    Matrix()
    {
        vector<int> m;
    }

    Matrix(const int& num_rows, const int& num_cols)
    {
        EnsurePositivity(num_rows, num_cols);
        columns = num_cols;
        vector<int> m(num_rows * num_cols);
    }

    void Reset(const int& num_rows, const int& num_cols)
    {
        EnsurePositivity(num_rows, num_cols);
        columns = num_cols;
        vector<int> m(num_rows * num_cols);
    }

    int At(const int& num_row, const int& num_col) const
    {
        EnsureLessThanMatrixSize(m, columns, num_row, num_col);
        return m[num_row * columns + num_col];
    }

    int& At(const int& num_row, const int& num_col)
    {
        EnsureLessThanMatrixSize(m, columns, num_row, num_col);
        return m[num_row * columns + num_col];
    }

    int GetNumRows() const
    {
        return m.size() / columns;
    }

    int GetNumColumns() const
    {
        return columns;
    }

private:
    int columns;
    vector<int> m;
};

istream& operator >> (istream& stream, Matrix& matrix)
{
    int num_rows, num_cols;
    stream >> num_rows >> num_cols;
    matrix.Reset(num_rows, num_cols);
    for(int i = 0; i < num_rows; i++)
    {
        for(int j = 0; i < num_cols; j++)
        {
            stream >> matrix.At(i, j);
        }
    }
    return stream;
}

ostream& operator << (ostream& stream, const Matrix& matrix)
{
    stream << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << endl;
    for(int i = 0; i < matrix.GetNumRows(); i++)
    {
        for(int j = 0; i < matrix.GetNumColumns(); j++)
        {
            stream << matrix.At(i, j) << ' ';
        }
        stream << endl;
    }
}

bool operator == (const Matrix& lhs, const Matrix& rhs)
{
    for(int i = 0; i < lhs.GetNumRows(); i++)
    {
        for(int j = 0; j < lhs.GetNumColumns(); j++)
        {
            if(lhs.At(i, j) != rhs.At(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

Matrix operator + (const Matrix& lhs, const Matrix& rhs)
{
    Matrix tmp(lhs.GetNumRows(), lhs.GetNumColumns());
    for(int i = 0; i < lhs.GetNumRows(); i++)
    {
        for(int j = 0; j < lhs.GetNumColumns(); j++)
        {
            tmp.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return tmp;
}

int main()
{
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
