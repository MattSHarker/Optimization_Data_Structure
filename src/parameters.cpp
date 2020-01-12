#include <fstream>
#include <iostream>
#include <string>

#include "parameters.h"

using namespace std;

namespace parameters
{
    void setPopulationParameters(int &rows, int &cols)
    {
        string tmpCols, tmpRows;

        ifstream file;
        file.open("parameters/dataset.txt");
        
        // retreive the number of dimensions
        file >> tmpCols;    // twice to skip description
        file >> tmpCols;

        // retreive the population size
        file >> tmpRows;    // twice to skip description
        file >> tmpRows;

        try
        {
            cols = stoi(tmpCols);
            rows = stoi(tmpRows);
        }
        catch(const exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        file.close();
    }
}
