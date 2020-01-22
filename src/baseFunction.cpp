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
    return summation(arr, size);
}

/**
 * @brief Finds the sum of an array's elements
 * 
 * @tparam T    The type of data being used (float, double, etc.).
 * @param data  A vector of values to be ran through the function.
 * @return T    The result of running the vector through the function.
 */
template <class T>
T summation(T* arr, int size)
{
    T val = 0.0;

    for (int i = 0; i < size; ++i)
    {
        val += arr[i];
    }

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

template float       summation(float*       arr, int size);
template double      summation(double*      arr, int size);
template long double summation(long double* arr, int size);
