#ifndef TIMER_H
#define TIMER_H

class Timer
{
private:
    bool active;    // determines whether to run the timer or not
    // for all functions, encapsulate all of it within an if statement
        // that is truee when active == true

    clock_t time;    // records the elapsed taken

public:
    Timer();

    void startTimer();
    void endTimer();

    double  getTimeMS()
    clock_t getTimeTicks();

    void activate();
    void deactivate();
}

#endif
