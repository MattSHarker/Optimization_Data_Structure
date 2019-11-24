#include <iostream>
#include <vector>

#include "dataset.h"

using namespace std;


template <class T>
Dataset<T>::Dataset(int newPopSize, int newDims)
{
    // set the size variables
    popSize    = newPopSize;
    dimensions = newDims;

    // initialize the matrix
    data = new Matrix<T>(popSize, dimensions);

    // initialize results array
    results = new T[popSize];
}


template <class T>
Dataset<T>::~Dataset()
{
    cout << "Deleting data...\n";
    if (data != nullptr)
        delete data;
    cout << "Data deleted\n\n";


    cout << "Deleting results...\n";
    if (results != nullptr)
        delete[] results;
    cout << "Results deleted\n\n";
}


template <class T>
int Dataset<T>::getDimensions()
{
    return dimensions;
}


template <class T>
int Dataset<T>::getPopSize()
{
    return popSize;
}


template <class T>
void Dataset<T>::setResults(int position, T value)
{
    // check for bounds
    if (0 > position || position >= popSize)
        throw out_of_range ("Dataset.setResults");

    // set the value
    results[position] = value;
}


template <class T>
T Dataset<T>::getResults(int position)
{
    // check for bounds
    if (0 > position || position >= popSize)
        throw out_of_range ("Dataset.getResults");

    // return the value
    return results[position];
}


template class Dataset<short int>;
template class Dataset<int>;
template class Dataset<long int>;
template class Dataset<float>;
template class Dataset<double>;
