#pragma once

#include "dataset.h"

// runs the base function for the whole population
template <class T>
void baseFunctionFull(Dataset<T>* dataset);

// runs the base function for one specific member of the population
template <class T>
void baseFunctionOnce(Dataset<T>* dataset, uint populationMember);

// returns the value of an array passed through the base function
template <class T>
T runBaseFunction(T* arr, int size);

// rename and redefine as necessary
// these could be merged into one, but keeping it as
    // two should improve the readability
template <class T>
T schwefel(T* arr, int size);
