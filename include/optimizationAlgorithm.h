#pragma once

#include <string>
#include "dataset.h"
#include "parameters.h"

template <class T> void runOptimization(Dataset<T>* data, string baseDir);
template <class T> void blindWalk(Dataset<T>* data, string baseDir, parameters::optimizationParameters algorithmParameters);
