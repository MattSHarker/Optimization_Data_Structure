#ifndef BASE_FUNCTION_H
#define BASE_FUNCTION_H

#include <stdio.h>

#include "ods.h"

void baseFunctionFull(ODS* ods);
void baseFunctionOnce(ODS* ods, unsigned int row);
double schwefel(ODS* ods, unsigned int row);

#endif
