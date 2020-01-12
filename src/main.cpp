#include <iostream>
#include <string> 

#include "dataset.h"
#include "testDataset.h"
#include "optimizationAlgorithm.h"
#include "parameters.h"

using namespace std;

// void run(){ testDatasetClass(); }

int main(int argc, char* argv[])
{
    string baseDir;

    // check for args
    baseDir = (argc >= 2) ? argv[1] : "default";

    // setup dataset
    Dataset<double>* data = new Dataset<double>();

    runOptimization(data, baseDir);

    // destroy dataset
    delete data;

    return 0;
}
