#include <iostream>

#include "testDataset.h"
#include "dataset.h"

using namespace std;

// this file is going to be gross

void testDatasetClass()
{
    // test constructors
cout << "Creating dataset...\n";
    Dataset<double> *ds = new Dataset<double>(3, 5, 0, 10);
cout << "Dataset created\n\n";

cout << "Rows: " << ds->getRows() << endl;
cout << "Cols: " << ds->getCols() << endl << endl;

    // test accessing *data
    int rows = 2;
    int cols = 4;
    int val  = 5;
    
cout << "Setting value of (" << rows << ", " << cols << ") to " << val << "\n";
    ds->setData(rows, cols, val);
cout << "Value of (" << rows << ", " << cols << ") has been" << " set to " << ds->getData(rows, cols) << "\n\n";
    
    // test accessing *results
    int pos = 2;
        val = 4;

cout << "Setting value of results[" << pos << "] to " << val << "\n";
    ds->setFitness(pos, val);
cout << "Value of results[" << pos << "] set to " << ds->getFitness(pos) << "\n\n";

    // test destructor
cout << "Destroying dataset...\n";
    delete ds;
cout << "Dataset destroyed\n";




    // set values to test sorting
    Dataset<double> *ds2 = new Dataset<double>(4, 4, -20, 20);
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            ds2->setData(i-1, j-1, j + (i*100));

    ds2->setFitness(0, 25.7);
    ds2->setFitness(1, 10.6);
    ds2->setFitness(2, 72.3);
    ds2->setFitness(3, 27.9);

    // test sorting methods
cout << "\nSorting from low to high\n";
    ds2->sortFitnessLowToHigh();
    ds2->printFitness();
    ds2->printData();

cout << "\nSorting from high to low\n";
    ds2->sortFitnessHighToLow();
    ds2->printFitness();
    ds2->printData();

cout << "\nSorting methods have been ran\n\n";



}
