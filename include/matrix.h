#ifndef MATRIX_H
#define MATRIX_H

template <class T>
class Matrix
{
private:
    // size variables
    int rows;
    int cols;

    // holds the data
    T** matrix;

public:
    // constructors
    Matrix(int size);
    Matrix(int rows, int cols);

    // destructor
    ~Matrix();

    // funcs for Matrix.matrix
    void setValue(int row, int col, T value);
    T    getValue(int row, int col);

    // funcs for Matrix.rows and Matrix.cols
    int getRows();
    int getCols();

    // print to console
    void print();
};

#endif
