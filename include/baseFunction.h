#ifndef BASE_FUNCTION_H
#define BASE_FUNCTION_H

#include <vector>

namespace funcRunner {
    // int func, T data, int size
    template <class T>
    T runBaseFunction(std::vector<T> data);

    // rename and redefine as necessary
    // these could be merged into one, but keeping it as
        // two should improve the readability
    template <class T>
    T schwefel(std::vector<T>);
}

#endif
