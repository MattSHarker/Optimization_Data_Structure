#ifndef __DATASET__
#define __DATASET__

#include <vector>
#include "matrix.h"

using namespace std;

template <class T>
class Dataset
{
private:
    // holds the size of the matrix and results
    int popSize;    // # of rows
    int dimensions; // # of columns

    int iterations; // number of function calls

    T bestInd;     // the index of the current best fitness
    T 

    T *results;     // results of the optimation algorithm


public:
    // holds the random numbers
    Matrix<T> *data;

    // constructors and destructors
    Dataset(int rows, int cols);
    ~Dataset();

    // getters for dimensions and sets
    int getDimensions();
    int getPopSize();

    // setters and getters for results
    void setResults(int position, T value);
    T    getResults(int position);
};

#endif
