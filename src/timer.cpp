#include <cfloat>
#include <ctime>
#include <iostream>

#include "timer.h"

using namespace std;

Timer::Timer()
{
    active = true;
}


void Timer::startTimer()
{
    if (active)
        time = clock();
}

void Timer::endTimer()
{
    if (active)
        time = clock() - time;
}

// returns the elapsed time in milliseconds
double Timer::getTimeMS()
{
    if (active)
        return double(time*1000)/CLOCKS_PER_SEC;
}

// returns the elapsed time in clock ticks
clock_t Timer::getTimeTicks()
{
    if (active)
        return time;
}

void Timer::activate()
{
    active = true;
}

void Timer::deactivate()
{
    active = false;
}
