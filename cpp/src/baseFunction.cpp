#include <cmath>
#include "baseFunction.h"


template <class T>
void baseFunctionFull(Dataset<T>* data)
{
    for (int i = 0; i < data->getRows(); ++i)
    {
        baseFunctionOnce(data, i);
    }
}


/**
 * @brief Runs the base function to be optimized.
 * 
 * @tparam T    The type of data being used (float, double, etc.).
 * @param data  A vector of values to be ran through the base function.
 * @return T    The result of running the vector through the base function.
 */
template <class T>
void baseFunctionOnce(Dataset<T>* data, int row)
{
    data->setFitness(row, runBaseFunction(data->getDataRow(row), data->getCols()));
    data->incrimentFuncCalls();
}


template <class T>
T runBaseFunction(T* arr, int size)
{
    return schwefel(arr, size);
}

/**
 * @brief Runs the Scwefel function on a vector of data.
 * 
 * @tparam T    The type of data being used (float, double, etc.).
 * @param data  A vector of values to be ran through the Schwefel function.
 * @return T    The result of running the vector through the Schwefel function.
 */
template <class T>
T schwefel(T* arr, int size) {
    T val = (418.9829 * size);

    for (int i = 0; i < size; ++i)
        val -= (0 - arr[i]) * sin(sqrt(std::abs(arr[i])));

    return val;
}

template void baseFunctionFull(Dataset<float>*       data);
template void baseFunctionFull(Dataset<double>*      data);
template void baseFunctionFull(Dataset<long double>* data);

template void baseFunctionOnce(Dataset<float>*       data, int row);
template void baseFunctionOnce(Dataset<double>*      data, int row);
template void baseFunctionOnce(Dataset<long double>* data, int row);

template float       runBaseFunction(float*       arr, int size);
template double      runBaseFunction(double*      arr, int size);
template long double runBaseFunction(long double* arr, int size);

template float       schwefel(float*       arr, int size);
template double      schwefel(double*      arr, int size);
template long double schwefel(long double* arr, int size);
