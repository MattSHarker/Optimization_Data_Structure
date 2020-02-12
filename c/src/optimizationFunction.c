#include <stdio.h>
#include <stdlib.h> // for rand

#include "optimizationFunction.h"
#include "baseFunction.h"
// #include "timer.h"
// #include "csvWriter.h"

void runOptimization(ODS* ods, char* baseDir)
{
    // get parameters here

    // run the optimization
    blindWalk(ODS* ods, char* baseDir);
}

void blindWalk(ODS* ods, char* baseDir)
{
    iterations = 50;

    // set up randomization (MT19937ar preferably)
    srand(time(NULL));

    // setup and start the timer
    double timeTaken;
    clock_t start = clock();

    // for each iteration
    for (int i = 0; i < iterations; ++i)
    {
        // randomize the values in ods->data
        for (int r = 0; r < ods->popSize; ++r)
        {
            for (int c = 0; c < ods->dims; ++c)
            {
                randomVal = (double)rand() / ((double)RAND_MAX + 1);
                setODSValue(ods, r, c, randomVal);
            }
        }
    }

    // stop the timer, and get the time taken
    timer = clock() - timer;
    timeTaken = ((double) timer) / CLOCKS_PER_SEC;

    // run the base function to calculate fitness
    baseFunctionFull(ods);


    // write the iteration's data


    // reset the function call count
    ods->funcCalls = 0;
}

