#pragma once

namespace parameters
{
    struct algorithmParameters { int iterations; };

    void setPopulationParameters(int &populationSize, int &dimensions, float &rangeLow, float &rangeHigh);
    void setAlgorithmParameters(algorithmParameters &algorithmParams);
}
