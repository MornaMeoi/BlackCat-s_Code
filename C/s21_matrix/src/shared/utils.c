#include "utils.h"

void _PrintMatrix(const matrix_t *matrix)
{
    for(int i = 0; i < matrix->rows; ++i)
    {
        for(int j = 0; j < matrix->columns; ++j)
        {
            printf("%lf", matrix->matrix[i][j]);
            if(j != matrix->columns-1)
                printf(" ");
        }
        if(i != matrix->rows-1)
            printf("\n");
    }
}