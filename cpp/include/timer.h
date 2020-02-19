#pragma once

class Timer
{
private:
    clock_t time;    // records the elapsed taken

public:
    Timer();
    ~Timer();

    void start();
    void stop();

    double  getTimeMS();
    clock_t getTimeTicks();
};
