#include <iostream>
#include "dataset.h"

using namespace std;

void testMatrixClass();
void testDatasetClass();


int main()
{
    testDatasetClass();

    return 0;
}


void testDatasetClass()
{
    // test constructors
    cout << "Creating dataset...\n";
    Dataset<double> *ds = new Dataset<double>(3, 5);
    cout << "Dataset created\n\n";

    // test accessing *data
    int posX = 2;
    int posY = 3;
    int val  = 5;
    
    cout << "Setting value of (" << posX << ", " << posY
         << ") to " << val << "\n";
    ds->data->setValue(posX, posY, val);
    cout << "Value of (" << posX << ", " << posY << ") has been"
         << " set to " << ds->data->getValue(posX, posY) << "\n\n";
    
    // test accessing *results
    int pos = 2;
        val = 4;

    cout << "Setting value of results[" << pos << "] to " << val << "\n";
    ds->setResults(pos, val);
    cout << "Value of results[" << pos << "] set to " << ds->getResults(pos) << "\n\n";

    // test destructor
    cout << "Destroying dataset...\n";
    delete ds;
    cout << "Dataset destroyed\n";
}
