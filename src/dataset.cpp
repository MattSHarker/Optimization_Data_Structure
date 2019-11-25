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

    // initialize fitness array
    // fitness.length == popSize;
    fitness = new T[popSize];

    
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
void Dataset<T>::setFitness(int position, T value)
{
    // check for bounds
    if (0 > position || position >= popSize)
        throw out_of_range ("Dataset.setFitness");

    // set the value
    fitness[position] = value;
}


template <class T>
T Dataset<T>::getFitness(int position)
{
    // check for bounds
    if (0 > position || position >= popSize)
        throw out_of_range ("Dataset.getFitness");

    // return the value
    return fitness[position];
}


// allow only floats and doubles
template class Dataset<float>;
template class Dataset<double>;
