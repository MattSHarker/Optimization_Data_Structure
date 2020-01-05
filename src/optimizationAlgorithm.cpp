#include <iostream>
#include <random>
#include <string>

#include "optimizationAlgorithm.h"
#include "baseFunction.h"
#include "timer.h"
#include "csvWriter.h"

using namespace std;

template <class T>
void runOptimization(Dataset<T>* data, string baseDir)
{
    // run the optimization here
    blindWalk(data, baseDir);
}

template <class T>
void blindWalk(Dataset<T>* data, string baseDir)
{
    Timer* timer = new Timer();

    // set up MT19937ar for randomization, with bounds set
        // by the base function
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<T> distribution(-512, 512);

    // 30 iterations (arbitrary)
    for (int i = 0; i < 30; ++i)
    {
        // start the timer
        timer->start();

        // randomize the values in data
        for (int j = 0; j < data->getRows(); ++j)
            for (int k = 0; k < data->getCols(); ++k)
                data->setData(j, k, distribution(generator));

        // run the base function
        baseFunction(data);

        // stop the timer
        timer->stop();

        // write the data
        // change i+1 to i to index iterations at 0
        csvWriter::writeAll(data, timer, baseDir, i+1);
    }
}

template void runOptimization(Dataset<float>*  data, string baseDir);
template void runOptimization(Dataset<double>* data, string baseDir);

template void blindWalk(Dataset<float>*  data, string baseDir);
template void blindWalk(Dataset<double>* data, string baseDir);

// keep doing this to the other files as needed (ಥ﹏ಥ)