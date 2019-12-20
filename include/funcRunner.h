#ifndef FUNC_RUNNER_H
#define FUNC_RUNNER_H


namespace funcRunner
{
    // int func, T data, int size
    template <class T>
    T runFunc(int func, T data, int size);

    // ensures a 2D function doesn't take in a dataset of size >2
    template <class T>
    bool checkDataSize(std::string func, int size);
}

#endif
