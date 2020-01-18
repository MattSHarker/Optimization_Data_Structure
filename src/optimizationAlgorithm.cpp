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
    // get the parameters for the optimization algorithm
    parameters::optimizationParameters optParams;
    parameters::setOptimizationParameters(optParams);

    // run the optimization here
    blindWalk(data, baseDir, optParams);
}

template <class T>
void blindWalk(Dataset<T>* data, string baseDir, parameters::optimizationParameters optParams)
{
    Timer* timer = new Timer();

    // set up MT19937ar for randomization, with bounds set by the base function
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<T> distribution(data->getRangeLow(), data->getRangeHigh());

    // for each iteration
    for (int i = 0; i < optParams.iterations; ++i)
    {
        // start the timer
        timer->start();

        // randomize the values in data
        for (int j = 0; j < data->getRows(); ++j)
            for (int k = 0; k < data->getCols(); ++k)
                data->setData(j, k, distribution(generator));

        // run the base function
        baseFunctionFull(data);

        // stop the timer
        timer->stop();

        // write the data (i+1 so iterations are indexed at 1, not 0)
        csvWriter::writeAll(data, timer, baseDir, i+1);

        data->resetFuncCalls();
    }

    delete timer;
}

template void runOptimization(Dataset<float>*  data, string baseDir);
template void runOptimization(Dataset<double>* data, string baseDir);

template void blindWalk(Dataset<float>*  data, string baseDir, parameters::optimizationParameters optParams);
template void blindWalk(Dataset<double>* data, string baseDir, parameters::optimizationParameters optParams);
