#ifndef ODS_H
#define ODS_H

#include "matrix.h"

typedef struct ods
{
    unsigned int popSize;   // rows
    unsigned int dims;      // cols

    unsigned int funcCalls; // init to 0 (per iteration, not total)

    Matrix* data;           // rows * cols

    double* fitness;        // size: popSize (rows)

} ODS;

void initODS(ODS* ods, unsigned int rows, unsigned int cols);
void destructODS(ODS* ods);

// makes doing pointer arithmetic easier
void   setODSValue(ODS* ods, unsigned int row, unsigned int col, double val);
double getODSValue(ODS* ods, unsigned int row, unsigned int col);

// not necessary, get rid of?
void incrementFuncCalls(ODS* ods);

// also sorts fitness accordingly
void sortODSLowToHigh(ODS* ods);    // lowest at index 0
void sortODSHighToLow(ODS* ods);    // highest at index 0

// calculates the fitness of the full
void calculateAllFitness(ODS* ods);
void calculateOneFitness(ODS* ods, unsigned int row);

#endif /* ODS_H */
