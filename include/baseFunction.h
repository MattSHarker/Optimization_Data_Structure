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
template <class T>
T summation(T* arr, int size);
