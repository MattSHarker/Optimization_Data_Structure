
#include <iostream>
#include "testDataset.h"
#include "optimizationAlgorithm.h"

using namespace std;

void run(){ testDatasetClass(); }

int main(int argc, char* argv[])
{
    // run();
    char* baseDir;

    // check for args
    if (argc == 0)
        baseDir = "test";
    else
        baseDir = argv[0];

cout << "baseDir: " << baseDir << endl;

    // setup dataset
    Dataset<double>* data = new Dataset<double>(100, 10);

    runOptimization(data, baseDir);

    // destroy dataset
    delete data;

    return 0;
}
