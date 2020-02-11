#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix
{
    // holds the sizes of the matrix
    unsigned int rows;
    unsigned int cols;

    // holds the information of the matrix (size: rows*cols)
    double* array;
} Matrix;

void initMatrix(Matrix* matrix, unsigned int rows, unsigned int cols);
void destructMatrix(Matrix*);

void   setValue(Matrix* matrix, unsigned int row, unsigned int col, double val);
double getValue(Matrix* matrix, unsigned int row, unsigned int col);

// may not be necessary
unsigned int getRows(Matrix* matrix);
unsigned int getCols(Matrix* matrix);



#endif  /* MATRIX_H */
