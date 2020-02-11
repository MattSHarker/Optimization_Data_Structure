#include <stdio.h>

#include "matrix.h"

// initializes a matrix object's sizes and array, and sets the values to 0
void initMatrix(Matrix* mtx, unsigned int rows, unsigned int cols)
{
    // set the values for the size variables
    mtx->rows = rows;
    mtx->cols = cols;

    mtx->array = (double *)calloc(rows * cols * sizeof(double));
}

// frees a matrix object from memory
void destructMatrix(Matrix* mtx)
{
    if (mtx != NULL)
    {
        free(mtx);
    }
}
