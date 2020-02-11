#include <math.h>

#include "baseFunction.h"


void baseFunctionFull(ODS* ods)
{
    for (int i = 0; i < ods->popSize; ++i)
    {
        baseFunctionOnce(ods, i);
    }
}

void baseFunctionOnce(ODS* ods, unsigned int row)
{
    ods->fitness[row] = schwefel(ods, row);
}

double schwefel(ODS* ods, unsigned int row)
{
    double val = 418.9829 * ods->dims;

    for (int i = 0; i < ods->dims; ++i)
    {
        val -= (0 - getODSValue(ods, row, i)) * sin(sqrt(fabs(getODSValue(ods, row, i))));
    }

    return val;
}
