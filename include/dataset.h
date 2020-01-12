#pragma once

#include <vector>
#include "matrix.h"

using namespace std;

template <class T>
class Dataset
{
private:
    int rows;    // # of sets of data (rows)
    int cols; // size of each set  (columns)

    uint funcCalls;  // number of function calls that have been performed

    T *fitness;     // the fitness of each set of values (fitness.length == popSize)

    Matrix<T> *data; // holds the numbers to optimize
                     // rows: popSize      cols: dims

    // functions for sorting fitness and data (quick sort)
    int partitionLowToHigh(int left, int right);
    int partitionHighToLow(int left, int right);
    void sortFitnessLowToHigh(int left, int right);
    void sortFitnessHighToLow(int left, int right);

public:
    // constructors and destructors
    Dataset(int populationSize, int dimensions);
    ~Dataset();

    // functions for cols and sets
    int getRows();
    int getCols();

    // functions for funcCalls
    void incrimentFuncCalls();
    void resetFuncCalls();
    uint getFuncCalls();

    // functions for fitness
    void setFitness(const int position, T newValue);
    T    getFitness(const int position);

    // functions for data
    void setData(const uint population, const uint dimension, T value);
    T    getData(const uint population, const uint dimension);
    T*   getDataRow(const uint population);

    // sort population by fitness (sorts rows as well)
    void sortFitnessLowToHigh();
    void sortFitnessHighToLow();

    // print functions
    void printData();
    void printFitness();
};
