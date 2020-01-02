#ifndef BASE_FUNCTION_H
#define BASE_FUNCTION_H

#include <vector>

namespace funcRunner
{
    // int func, T data, int size
    template <class T>
    T runFunction(int func, std::vector<T> data, int size);
}

#endif
