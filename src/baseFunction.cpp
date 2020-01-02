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
    T runBaseFunction(std::vector<T> data) {
        return schwefel(data);
    }

    /**
     * @brief Runs the Scwefel function on a vector of data.
     * 
     * @tparam T    The type of data being used (float, double, etc.).
     * @param data  A vector of values to be ran through the Schwefel function.
     * @return T    The result of running the vector through the Schwefel function.
     */
    template <class T>
    T schwefel(std::vector<T> data) {
        T val = (418.9829 * data.size());

        for (int i = 0; i < data.size(); ++i)
            val -= (0 - data.at(i)) * sin(sqrt(std::abs(data.at(i))));

        return val;
    }
}
