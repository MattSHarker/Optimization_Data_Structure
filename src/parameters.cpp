#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

#include "parameters.h"

using namespace std;

namespace parameters
{
    void setPopulationParameters(int &rows, int &cols, float &low, float &high)
    {
        string trash, tmpCols, tmpRows, tmpLow, tmpHigh;

        ifstream file;
        file.open("parameters/dataset.txt");
        
        // retreive the number of dimensions
        file >> trash;    // trash skips description
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
            cols = stoi(tmpCols);
            rows = stoi(tmpRows);

            if (tmpLow == "PI")
                low = M_PI;
            else if (tmpLow == "-PI")
                low = -M_PI;
            else
            {
                low  = stof(tmpLow.substr(1, tmpLow.length() - 2));

                // adjust value for exclusive bounds (parenthesis)
                if (tmpLow.at(0) == '(')
                    low = nextafter(low, 1.0);
            }
            
            if (tmpHigh == "PI")
                high = M_PI;
            else if (tmpHigh == "-PI")
                high = -M_PI;
            else
            {
                high = stof(tmpHigh.substr(0, tmpHigh.length() - 1));

                // adjust value for exclusive bounds (parenthesis)
                if (tmpHigh.at(tmpHigh.length() - 1) == ')')
                    high = nextafter(high, -1.0);
            }
        }
        catch(const exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        file.close();
    }

    void setAlgorithmParameters(algorithmParameters &algParams)
    {
        string tmpIterations;

        ifstream file;
        file.open("parameters/optimization_algorithm.txt");

        // retreive the iterations
        file >> tmpIterations;
        file >> tmpIterations;

        try
        {
            algParams.iterations = stoi(tmpIterations);
        }
        catch(const exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        file.close();
    }
}
