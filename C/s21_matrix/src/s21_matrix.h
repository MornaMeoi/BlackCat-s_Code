#ifndef S21_MATRIX_H
#define S21_MATRIX_H

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

#include <stdio.h>
#include <stdlib.h>

#define CODE_OK 0
#define CODE_INCORRECT_MATRIX_ERROR 1
#define CODE_CALCULATION_ERROR 2

#define SUCCESS 1
#define FAILURE 0

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif