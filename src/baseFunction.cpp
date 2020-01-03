#include <cmath>
#include "baseFunction.h"

namespace funcRunner {
    /**
     * @brief Runs the base function to be optimized.
     * 
     * @tparam T    The type of data being used (float, double, etc.).
     * @param data  A vector of values to be ran through the base function.
     * @return T    The result of running the vector through the base function.
     */
    template <class T>
    T runBaseFunction(Dataset<T>* data)
    {
        for (int i = 0; i < data->getRows(); ++i)
            data->setFitness(i, runBaseFunction(data->getDataRow(i)));
    }

    template <class T>
    T runBaseFunction(T* arr)
    {
        return schwefel(arr);
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
}
