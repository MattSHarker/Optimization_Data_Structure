#pragma once

namespace parameters
{
    struct algorithmParameters { int iterations; };

    void setPopulationParameters(int &populationSize, int &dimensions);
    void setAlgorithmParameters(algorithmParameters &algorithmParams);
}
