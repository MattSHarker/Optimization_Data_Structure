#pragma once
        
#include <string>
#include "timer.h"
#include "dataset.h"

namespace csvWriter
{
    // write the dataset matrix to a file
    template <class T>
    void writeData(Dataset<T>* dataset, std::string dir, int iteration);

    // write the fitness array to a file
    template <class T>
    void writeFitness(Dataset<T>* dataset, std::string dir, int iteration);

    // write the iteration's function calls to a file
    template <class T>
    void writeFuncCalls(Dataset<T>* dataset, std::string baseDir, int iteration);

    // write each iteration's elapsed time to a file
    void writeIterationTime(Timer* timer, std::string dir, int iteration);

    // write all of the files
    template <class T>
    void writeAll(Dataset<T>* dataset, Timer* timer, std::string dir, int iteration);
}

// Things to write to files:
    // the full contents of Dataset:data per iteration
        // each row will be the entire population

    // the full contents of Dataset:fitness per iteration
        // each row will be the entire population

    // how many function calls were performed per iteration
        // each line will have one point of data per iteration

    // the time each iteration took
        // each line will have one data point per iteration

// Formatting considerations
    // each row will be one iteration
        // this will make writing to the files much easier
    