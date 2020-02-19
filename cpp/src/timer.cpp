#include <cfloat>
#include <ctime>
#include <iostream>

#include "timer.h"

using namespace std;

Timer::Timer(){}

Timer::~Timer(){}

void Timer::start()
{
    time = clock();
}

void Timer::stop()
{
    time = clock() - time;
}

// returns the elapsed time in milliseconds
double Timer::getTimeMS()
{
    return double(time*1000)/CLOCKS_PER_SEC;
}

// returns the elapsed time in clock ticks
clock_t Timer::getTimeTicks()
{
    return time;
}