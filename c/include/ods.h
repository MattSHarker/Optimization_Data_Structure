#ifndef ODS_H
#define ODS_H

#include "matrix.h"

typedef struct ods
{
    unsigned int popSize;    // rows
    unsigned int dims;       // cols

    unsigned int funcCalls;

    Matrix* data;

    double* fitness;    // size: popSize (rows)

} ODS;

void initODS(ODS* ods, unsigned int rows, unsigned int cols);
void destructODS(ODS* ods);

// makes doing pointer arithmetic easier
void   setODSValue(ODS* ods, unsigned int row, unsigned int col, double val);
double getODSValue(ODS* ods, unsigned int row, unsigned int col);

double* getODSRow(ODS* ods, unsigned int row);

// not necessary, get rid of?
void incrementFuncCalls(ODS* ods);

// also sort fitness accordingly
void sortODSLowFirst (ODS* ods);
void sortODSHighFirst(ODS* ods);

// calculates the fitness of the full
void calculateAllFitness(ODS* ods);
void calculateOneFitness(ODS* ods, unsigned int row);

#endif /* ODS_H */
