#include <cfloat>
#include <ctime>
#include <iostream>

#include "timer.h"

using namespace std;

// timer defaults to activated
Timer::Timer()
{
    active = true;
}

// grab the current time
void Timer::start()
{
    if (active) time = clock();
}

// calculate difference btwn start and stop times
void Timer::stop()
{
    if (active) time = clock() - time;
}

// returns the elapsed time in milliseconds
double Timer::getTimeMS()
{
    if (active) return double(time*1000)/CLOCKS_PER_SEC;
}

// returns the elapsed time in clock ticks
clock_t Timer::getTimeTicks()
{
    if (active) return time;
}

// activates the timer
void Timer::activate()
{
    active = true;
}

// deactivates the timer
void Timer::deactivate()
{
    active = false;
}

// returns the activation state
bool Timer::activated()
{
    return active;
}
