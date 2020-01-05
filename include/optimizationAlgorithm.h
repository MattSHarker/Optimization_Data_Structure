#pragma once

#include <string>
#include "dataset.h"

template <class T> void runOptimization(Dataset<T>* data, string baseDir);
template <class T> void blindWalk(Dataset<T>* data, string baseDir);
