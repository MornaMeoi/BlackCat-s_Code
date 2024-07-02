#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A)
{
    if(A)
    {
        if(A->matrix)
        {
            free(A->matrix);
            printf("HELLO!\n\n\n\n");
        }
        printf("HELLO!\n\n\n\n");
        free(A);
        printf("HELLO!\n\n\n\n");
    }
}