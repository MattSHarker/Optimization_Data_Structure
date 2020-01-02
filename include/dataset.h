#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include "matrix.h"

using namespace std;

template <class T>
class Dataset
{
private:
    int popSize;    // # of sets of data (rows)
    int dimensions; // size of each set  (columns)

    int funcCalls;  // number of function calls to perform
    int bestInd;      // the index of the current best fitness

    T *fitness;     // the fitness of each set of values (fitness.length == popSize)

public:
    Matrix<T> *data; // holds the numbers to optimize
                     // rows: popSize      cols: dims
    
    // constructors and destructors
    Dataset(int rows, int cols);
    ~Dataset();

    // functions for dimensions and sets
    int getDimensions();
    int getPopSize();

    // functions for fitness
    void setFitness(const int position, T value);
    T    getFitness(const int position);

    // operator overlaods
    Dataset<T> operator = (Dataset const &first);
};

#endif

//TODO: Add an assignment operator (=) overload for deep copies
