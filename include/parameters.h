#pragma once

namespace parameters
{
    struct optimizationParameters { int iterations; };

    void setDatasetParameters(int &populationSize, int &dimensions, float &rangeLow, float &rangeHigh);
    void setOptimizationParameters(optimizationParameters &optimizationParameters);
}
