#include <cmath>
#include "baseFunction.h"

/**
 * @brief Runs the base function to be optimized.
 * 
 * @tparam T    The type of data being used (float, double, etc.).
 * @param data  A vector of values to be ran through the base function.
 * @return T    The result of running the vector through the base function.
 */
template <class T>
void baseFunction(Dataset<T>* data)
{
    for (int i = 0; i < data->getRows(); ++i)
        data->setFitness(i, baseFunction(data->getDataRow(i), data->getCols()));
}

template <class T>
T baseFunction(T* arr, int size)
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

template void baseFunction(Dataset<float>*       data);
template void baseFunction(Dataset<double>*      data);
template void baseFunction(Dataset<long double>* data);

template float       baseFunction(float*       arr, int size);
template double      baseFunction(double*      arr, int size);
template long double baseFunction(long double* arr, int size);

template float       schwefel(float*       arr, int size);
template double      schwefel(double*      arr, int size);
template long double schwefel(long double* arr, int size);
