#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result)
{
    int exit_code = rows > 0 && columns > 0 ? CODE_OK : CODE_INCORRECT_MATRIX_ERROR;
    if(!exit_code)
    {
        result = (matrix_t *)malloc(sizeof(matrix_t));
        if(result)
        {
            result->matrix = (double **)malloc(rows * sizeof(double *) + rows*columns * sizeof(double));
            for(int i = 0; i < rows; ++i)
                result->matrix[i] = (double *)(result + rows) + i*columns;
            if(!result->matrix)
            {
                free(result);
                exit_code = CODE_INCORRECT_MATRIX_ERROR;
            }
            result->rows = rows;
            result->columns = columns;
        }
        else
            exit_code = CODE_INCORRECT_MATRIX_ERROR;
    }
    return exit_code;
}