#include "shared/utils.h"

int main()
{
    matrix_t *test;
    printf("%d\n", s21_create_matrix(4, 5, test));
    for(int i = 0; i < test->rows; ++i)
        for(int j = 0; j < test->columns; ++j)
            test->matrix[i][j] = i * 4 + j;
    _PrintMatrix(test);
    s21_remove_matrix(test);
    return 0;
}