#include <stdio.h>

#include "ods.h"
#include "baseFunction.h"

// initializes an ODS object
void initODS(ODS* ods, unsigned int r, unsigned int c)
{
    ods->popSize = r;
    ods->dims    = c;

    ods->funcCalls = 0;

    initMatrix(ods->data, r, c);

    ods->fitness = (double *)calloc(r * sizeof(double));
}

// frees an ODS object from memory
void destructODS(ODS* ods)
{
    if (ods->fitness != NULL)
    {
        free(ods->fitness);
    }

    destructMatrix(ods->data);
}

// sets a value in the matrix object
void setODSValue(ODS* ods, unsigned int r, unsigned int c, double val)
{
    ods->data->array[r * ods->dims + c] = val;
}

// returns the value from the matrix object
double getODSValue(ODS* ods, unsigned int r, unsigned int c)
{
    return ods->data->array[r * ods->dims + c];
}

void incrimentFuncCalls(ODS* ods)
{
    ++ods->funcCalls;
}

void calculateFitness(ODS* ods)
{
    baseFunctionFull(ods);
}

void calculateOneFitness(ODS* ods, unsigned int row)
{
    baseFunctionOnce(ods, row);
}
