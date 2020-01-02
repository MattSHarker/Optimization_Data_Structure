#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "csvWriter.h"

using namespace std;

namespace csvWriter
{
    template <class T>
    void writeData(Dataset<T>* dataset)
    {
        // write to results/data/data-iteration
        string pathname = "results/data/data-" + dataset.getIteration().toString() + ".csv";
        cout << pathname << "/n";

        ofstream csv(pathname);

        // write the entirety of dataset.matrix
        for (int i = 0; i < dataset->getPopSize(); ++i)
        {
            // write the first element to prevent extra commas
            csv  << dataset->matrix[i][0];
            cout << dataset->matrix[i][0];

            for (int j = 0; j < dataset->getDimensions(); ++i)
            {
                csv  << "," << dataset->matrix[i][j];
                cout << " " << dataset->matrix[i][j];
            }

            // add a newline
            csv  << '\n';
            cout << '\n';
        }

        // close the file
        csv.close();
    }

    template <class T>
    void writeFitness(Dataset<T> dataset)
    {
        // write to results/fitness/fitness-$iteration
        pathname = "results/fitness/fitness-" + dataset.getIteration().toString();
        cout << "fitness pathname: " << pathname << "\n";

        // create and open the file
        ofstream csv(pathname);

        // one fitness per line
            // makes it line up with the data in results/data
        for (int i = 0; i < popSize; ++i)
        {
            csv << dataset->getFitness(i) << '\n';
        }

        // close the file
        csv.close();
    }


    template <class T>
    void writeAll(Dataset<T> dataset)
    {
        writeData(dataset);
        writeFitness(dataset);
    }
}
