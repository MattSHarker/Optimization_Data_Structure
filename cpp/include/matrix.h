#pragma once

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
    T*   getValueRow(int row);

    // funcs for Matrix.rows and Matrix.cols
    int getRows();
    int getCols();

    // print to console
    void print();
};
