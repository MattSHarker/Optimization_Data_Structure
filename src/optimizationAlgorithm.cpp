#include <iostream>
#include <random>


#include "optimizationAlgorithm.h"
#include "baseFunction.h"
#include "timer.h"
#include "csvWriter.h"

using namespace std;

template <class T>
void runOptimization(Dataset<T>* data, char* baseDir)
{
    
    string dir(baseDir);
    blindWalk(data);
}

template <class T>
void blindWalk(Dataset<T>* data)
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
                data->setData(j, k, distribution(genertor));

        // run the base function
        baseFunction::runBaseFunction(data);

        // stop the timer
        timer->stop();

        // write the data
        csvWriter::writeAll(data, timer, "test", i);
    }
}
