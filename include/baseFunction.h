#pragma once

#include "dataset.h"

template <class T>
void baseFunction(Dataset<T>* data);

template <class T>
T baseFunction(T* arr, int size);

// rename and redefine as necessary
// these could be merged into one, but keeping it as
    // two should improve the readability
template <class T>
T schwefel(T* arr, int size);
