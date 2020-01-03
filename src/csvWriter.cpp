#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "csvWriter.h"

using namespace std;

namespace csvWriter
{
    template <class T>
    void writeData(Dataset<T>* dataset, string dir, int iter)
    {
        // write to $dir/results/data/data-iteration
        string pathname = dir + "/results/data/data-"
                        + dataset.getIteration().toString() + ".csv";

        cout << pathname << "/n";

        ofstream csv(pathname, ios::app);

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
    void writeFitness(Dataset<T> dataset, string dir)
    {
        // write to $dir/results/fitness/fitness-$iteration
        string pathname = dir + "/results/fitness/fitness-" + dataset.getIteration().toString();
        cout << "fitness pathname: " << pathname << "\n";

        // create and open the file
        ofstream csv(pathname, ios::app);   // append to file

        // write the fitness to one line
        csv << dataset->getFitness(0);  // write first line for no extra commas
        for (int i = 1; i < dataset->popSize(); ++i)
            csv << "," << dataset->getFitness(i);

        csv << '\n';

        // close the file
        csv.close();
    }

    void writeIterationTime(Timer* timer, string dir)
    {
        // only write if the timer is active
        if (timer->activated())
        {
            // write to $dir/results/iterationTime/fitness-$iteration
            string pathname = dir + "/results/iterationTime/iterationTime.csv";
            cout << "iteration time pathname: " << pathname << "\n";

            // open the file in append mode
            ofstream csv(pathname, ios::app);

            csv << timer->getTimeMS() << '\n';

            csv.close();
        }
    }


    template <class T>
    void writeAll(Dataset<T> dataset, Timer* timer, string dir, int iteration)
    {
        writeData(dataset, dir);
        writeFitness(dataset, dir);
        writeIterationTime(timer, dir);
    }
}
