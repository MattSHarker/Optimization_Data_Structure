
#include <iostream>
#include <string> 

#include "dataset.h"
#include "testDataset.h"
#include "optimizationAlgorithm.h"

using namespace std;

// void run(){ testDatasetClass(); }

int main(int argc, char* argv[])
{
    string baseDir;

    // check for args
    if (argc >= 2)
        baseDir = argv[1];
    else
        baseDir = "default";

    // setup dataset
    Dataset<double>* data = new Dataset<double>(100, 10);

    runOptimization(data, baseDir);

    // destroy dataset
    delete data;

    return 0;
}
