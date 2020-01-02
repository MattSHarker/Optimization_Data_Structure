#pragma once

// things to write out:
    // the general info of the experiment
        // the date
        // which function was used

    // the full contents of Dataset:data
        // filename should include the iteration

    // the full contents of Dataset:fitness
        // filename should include the iteration


namespace csvWriter
{
    // write the dataset matrix to a file
    template <class T>
    void writeData(Dataset<T> dataset);

    // write the fitness array to a file
    template <class T>
    void writeFitness(Dataset<T> dataset);

    // write all of the files
    template <class T>
    void writeAll(Dataset<T> dataset);
}
