#include <iostream>
#include "matrix.h"

using namespace std;


// constructors
template <class T>
Matrix<T>::Matrix(int size)
{
    // set sizes
    rows = size;
    cols = size;

    // initialize the matrix
    matrix = new T*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new T[cols];
}


template <class T>
Matrix<T>::Matrix(int newRows, int newCols)
{
    // set sizes
    rows = newRows;
    cols = newCols;

    // initialize the matrix
    matrix = new T*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new T[cols];
}


// destructor
template <class T>
Matrix<T>::~Matrix()
{
    if (matrix != nullptr)
    {
        for (int i = 0; i < rows; i++)
            delete [] matrix[i];
        
        delete[] matrix;
    }
}


// setters and getters
template <class T>
void Matrix<T>::setValue(int row, int col, T value)
{
    // check for bounds
    if (0 > row || row >= rows)
        throw out_of_range ("Matrix->setValue: rows");

    if (0 > col || col >= cols)
        throw out_of_range ("Matrix->setValue: cols");

    // set value
    matrix[row][col] = value;
}


template <class T>
T Matrix<T>::getValue(int row, int col)
{
    // check for bounds
    if (0 > row || row >= rows)
        throw out_of_range ("Matrix->setValue: rows");

    if (0 > col || col >= cols)
        throw out_of_range ("Matrix->setValue: cols");

    // return value
    return matrix[row][col];
}


template <class T>
int Matrix<T>::getRows()
{
    return rows;
}


template <class T>
int Matrix<T>::getCols()
{
    return cols;
}


// print to console
template <class T>
void Matrix<T>::print()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j] << " ";

        cout << "\n";
    }
}


template class Matrix<short int>;
template class Matrix<int>;
template class Matrix<long int>;
template class Matrix<float>;
template class Matrix<double>;
