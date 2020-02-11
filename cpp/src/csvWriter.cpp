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
        string pathname = "results/" + dir + "/data/raw_data-" + to_string(iter) + ".csv";
        ofstream csv(pathname, ios::app);

        // write the entirety of dataset.matrix
        for (int i = 0; i < dataset->getRows(); ++i)
        {
            // write the first element to prevent extra commas
            csv  << dataset->getData(i, 0);

            for (int j = 1; j < dataset->getCols(); ++j)
                csv  << "," << dataset->getData(i, j);

            // add a newline
            csv  << '\n';
        }

        csv.close();
    }

    template <class T>
    void writeFuncCalls(Dataset<T>* dataset, string dir, int iter)
    {
        // write to $dir/results/fitness/fitness-$iteration
        string pathname = "results/" + dir + "/function_calls/function_calls.csv";

        // create and open the file
        ofstream csv(pathname, ios::app);   // append to file

        // append the iteration and function calls to the file
        csv << to_string(iter) << "," << dataset->getFuncCalls();

        csv << '\n';

        // close the file
        csv.close();
    }

    template <class T>
    void writeFitness(Dataset<T>* dataset, string dir, int iter)
    {
        // write to $dir/results/fitness/fitness-$iteration
        string pathname = "results/" + dir + "/fitness/fitness.csv";

        // create and open the file
        ofstream csv(pathname, ios::app);   // append to file

        // write the iteration and fitnesses to the file
        csv << to_string(iter);
        for (int i = 0; i < dataset->getRows(); ++i)
            csv << "," << dataset->getFitness(i);

        csv << '\n';

        // close the file
        csv.close();
    }

    void writeIterationTime(Timer* timer, string dir, int iter)
    {
        // only write if the timer is active
        if (timer->activated())
        {
            // write to $dir/results/iterationTime/fitness-$iteration
            string pathname = "results/" + dir + "/time/iteration_time.csv";

            // open the file in append mode
            ofstream csv(pathname, ios::app);

            // write the data to the file
            csv << to_string(iter) << "," << timer->getTimeMS() << '\n';

            // close the file
            csv.close();
        }
    }

    template <class T>
    void writeAll(Dataset<T>* dataset, Timer* timer, string dir, int iter)
    {
        // run each individual function
        writeData(dataset, dir, iter);
        writeFitness(dataset, dir, iter);
        writeFuncCalls(dataset, dir, iter);
        writeIterationTime(timer, dir, iter);
    }
}

// create each possible Type usage for each function
template void csvWriter::writeData(Dataset<float>*  data, string dir, int iter);
template void csvWriter::writeData(Dataset<double>* data, string dir, int iter);
template void csvWriter::writeData(Dataset<long double>* data, string dir, int iter);

template void csvWriter::writeFuncCalls(Dataset<float>*  data, string dir, int iter);
template void csvWriter::writeFuncCalls(Dataset<double>* data, string dir, int iter);
template void csvWriter::writeFuncCalls(Dataset<long double>* data, string dir, int iter);

template void csvWriter::writeFitness(Dataset<float>*  data, string dir, int iter);
template void csvWriter::writeFitness(Dataset<double>* data, string dir, int iter);
template void csvWriter::writeFitness(Dataset<long double>* data, string dir, int iter);

template void csvWriter::writeAll(Dataset<float>*  dataset, Timer* timer, std::string dir, int iter);
template void csvWriter::writeAll(Dataset<double>* dataset, Timer* timer, std::string dir, int iter);
template void csvWriter::writeAll(Dataset<long double>* dataset, Timer* timer, std::string dir, int iter);
