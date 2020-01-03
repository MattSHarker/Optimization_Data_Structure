#pragma once

#include "dataset.h"

namespace baseFunction {

    template <class T>
    T runBaseFunction(Dataset<T>* data);

    // rename and redefine as necessary
    // these could be merged into one, but keeping it as
        // two should improve the readability
    template <class T>
    T schwefel(T* arr);
}
