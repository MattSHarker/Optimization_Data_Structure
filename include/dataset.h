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

    int funcCalls;  // number of function calls to perform

    T bestInd;      // the index of the current best fitness
    
    T *fitness;     // the fitness of each set of values


public:
    // holds the numbers to optimize
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
