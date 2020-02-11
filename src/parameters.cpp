#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

#include "parameters.h"

using namespace std;

namespace parameters
{
    // Retrieve and set values for the dataset from a file
    void setDatasetParameters(int &rows, int &cols, float &low, float &high)
    {
        string trash, tmpCols, tmpRows, tmpLow, tmpHigh;

        // open the dataset parameter file
        ifstream file;
        file.open("parameters/dataset.txt");
        
        // retreive the number of dimensions
        file >> trash;  // trash skips description
        file >> tmpCols;

        // retreive the population size
        file >> trash;
        file >> tmpRows;

        // retreive the low and high ranges
        file >> trash;
        file >> tmpLow;
        file >> tmpHigh;

        try
        {
            // convert rows and cols from string to int
            cols = stoi(tmpCols);
            rows = stoi(tmpRows);

            // convert the lower bound to float
            // check for special cases (e.g. PI)
            if (tmpLow.substr(1, tmpLow.length()-2) == "PI")
                low = M_PI;
            else if (tmpLow.substr(1, tmpLow.length()-2) == "-PI")
                low = -M_PI;
            else
                // remove leading (/[ and trailing comma, convert to float
                low  = stof(tmpLow.substr(1, tmpLow.length()-2));

            // adjust value for exclusive bounds (parenthesis)
            if (tmpLow.at(0) == '(')
                low = nextafter(low, 1.0);
            
            // convert the upper bound to float
            // check for special cases (e.g. PI)
            if (tmpHigh.substr(0, tmpHigh.length()-1) == "PI")
                high = M_PI;
            else if (tmpHigh.substr(0, tmpHigh.length()-1) == "-PI")
                high = -M_PI;
            else
                high = stof(tmpHigh.substr(0, tmpHigh.length()-1));

            // adjust value for exclusive bounds (parenthesis)
            if (tmpHigh.at(tmpHigh.length() - 1) == ')')
                high = nextafter(high, -1.0);
        }
        catch(const exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        file.close();
    }

    void setOptimizationParameters(optimizationParameters &algParams)
    {
        string trash, tmpIterations;

        // open the optimization parameter file
        ifstream file;
        file.open("parameters/optimization_algorithm.txt");

        // retreive the iterations
        file >> trash;
        file >> tmpIterations;

        try
        {
            // convert string to int
            algParams.iterations = stoi(tmpIterations);
        }
        catch(const exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        file.close();
    }
}
