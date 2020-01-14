#include <iostream>
#include "dataset.h"
#include "parameters.h"

using namespace std;

template <class T>
Dataset<T>::Dataset(int newRows, int newCols, float newLow, float newHigh)
{
    // set the size variables
    rows      = newRows;
    cols      = newCols;
    rangeLow  = newLow;
    rangeHigh = newHigh;

    // set initial funcCalls to 0, as no
        //function calls have been made
    funcCalls = 0;

    // initialize the matrix
    data = new Matrix<T>(rows, cols);

    // initialize fitness array
    fitness = new T[rows];
}

template <class T>
Dataset<T>::Dataset()
{
    // read the row and column info from the parameter file
    parameters::setPopulationParameters(rows, cols, rangeLow, rangeHigh);

    // set initial funcCalls to 0, as no
        // function calls have been made
    funcCalls = 0;

    // initialize the matrix
    data = new Matrix<T>(rows, cols);

    // initialize fitness array
    fitness = new T[rows];
}


template <class T>
Dataset<T>::~Dataset()
{
    if (data != nullptr)
        delete data;

    if (fitness != nullptr)
        delete[] fitness;
}


template <class T>
int Dataset<T>::getRows()
{
    return rows;
}


template <class T>
int Dataset<T>::getCols()
{
    return cols;
}



template <class T>
float Dataset<T>::getRangeLow()
{
    return rangeLow;
}

template <class T>
float Dataset<T>::getRangeHigh()
{
    return rangeHigh;
}

template <class T>
void Dataset<T>::incrimentFuncCalls()
{
    ++funcCalls;
}

template <class T>
void Dataset<T>::resetFuncCalls()
{
    funcCalls = 0;
}


template <class T>
uint Dataset<T>::getFuncCalls()
{
    return funcCalls;
}

template <class T>
void Dataset<T>::setFitness(int position, T value)
{
    // check for bounds
    if (0 > position || position >= rows)
        throw out_of_range ("Dataset.setFitness");

    // set the value
    fitness[position] = value;
}


template <class T>
T Dataset<T>::getFitness(int position)
{
    // check for bounds
    if (0 > position || position >= rows)
        throw out_of_range ("Dataset.getFitness");

    // return the value
    return fitness[position];
}

template <class T>
void Dataset<T>::setData(const uint row, const uint col, T value)
{
    // check for bounds
    if (row >= data->getRows())
        if (row == data->getRows())
            throw out_of_range ("Dataset.setData: rows (check for off by 1 error");
        else
            throw out_of_range ("Dataset.setData: rows");
    
    if (col >= data->getCols())
        if (col == data->getCols())
            throw out_of_range ("Dataset.setData: cols (check for off by 1 error");
        else
            throw out_of_range ("Dataset.setData: cols");

    // set the value
    data->setValue(row, col, value);
}

template <class T>
T Dataset<T>::getData(const uint row, const uint col)
{
    // check for bounds
    if (row > data->getRows())
        throw out_of_range ("Dataset.setData: Setting a row that is out of range.");
    
    if (col > data->getCols())
        throw out_of_range ("Dataset.setData: Setting a col that is out of range.");

    // return the value
    return data->getValue(row, col);
}

template <class T>
T* Dataset<T>::getDataRow(const uint row)
{
    return data->getValueRow(row);
}


template <class T>
int Dataset<T>::partitionLowToHigh(int left, int right)
{
    // the element placed at the right position
    int pivot = fitness[right];

    // index of smaller element
    int small = left - 1;

    for (int i = left; i < right; ++i)
    {
        // if the current element is smaller than the pivot
        if (fitness[i] < pivot)
        {
            // incriment index of smaller element
            ++small;

            // swap the fitness at small and i
            T temp = fitness[small];
            fitness[small] = fitness[i];
            fitness[i] = temp;

            // deep swap the entire row at data[small] and data[i] 
            for (int j = 0; j < cols; ++j)
            {
                T temp = data->getValue(small, j);
                data->setValue(small, j, data->getValue(i, j));
                data->setValue(i, j, temp);
            }
                
        }
    }

    T temp = fitness[small+1];
    fitness[small+1] = fitness[right];
    fitness[right] = temp;

    for (int i = 0; i < cols; ++i)
    {
        T temp = data->getValue(small+1, i);
        data->setValue(small+1, i, data->getValue(right, i));
        data->setValue(right, i, temp);
    }

    return (small + 1);
}

template <class T>
int Dataset<T>::partitionHighToLow(int left, int right)
{
    // the element placed at the right position
    int pivot = fitness[right];

    // index of smaller element
    int small = left - 1;

    for (int i = left; i < right; ++i)
    {
        // if the current element is larger than the pivot
        if (fitness[i] > pivot)
        {
            // incriment index of smaller element
            ++small;

            // swap the fitness at small and i
            T temp = fitness[small];
            fitness[small] = fitness[i];
            fitness[i] = temp;

            // deep swap the entire row at data[small] and data[i] 
            for (int j = 0; j < cols; ++j)
            {
                T temp = data->getValue(small, j);
                data->setValue(small, j, data->getValue(i, j));
                data->setValue(i, j, temp);
            }
        }
    }

    T temp = fitness[small+1];
    fitness[small+1] = fitness[right];
    fitness[right] = temp;

    for (int i = 0; i < cols; ++i)
    {
        T temp = data->getValue(small+1, i);
        data->setValue(small+1, i, data->getValue(right, i));
        data->setValue(right, i, temp);
    }

    return (small + 1);
}

template <class T>
void Dataset<T>::sortFitnessLowToHigh()
{
    sortFitnessLowToHigh(0, rows-1);
}

template <class T>
void Dataset<T>::sortFitnessLowToHigh(int left, int right)
{
    if (left < right)
    {
        int part = partitionLowToHigh(left, right);

        sortFitnessLowToHigh(left, part-1);
        sortFitnessLowToHigh(part+1, right);
    }
}

template <class T>
void Dataset<T>::sortFitnessHighToLow()
{
    sortFitnessHighToLow(0, rows-1);
}

template <class T>
void Dataset<T>::sortFitnessHighToLow(int left, int right)
{
    if (left < right)
    {
        int part = partitionHighToLow(left, right);

        sortFitnessHighToLow(left, part-1);
        sortFitnessHighToLow(part+1, right);
    }
}


template <class T>
void Dataset<T>::printData()
{
    data->print();
}

template <class T>
void Dataset<T>::printFitness()
{
    for (int i = 0; i < rows; ++i)
        cout << fitness[i] << " ";
    
    cout << endl;
}

// allow only floating point types
template class Dataset<float>;
template class Dataset<double>;
template class Dataset<long double>;
