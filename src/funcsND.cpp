#include <cmath>

#include "funcsND.h"

// n-D functions (n >= 2)

// [-500, 500]
template <class T>
T schwefel(T* arr, int dims)
{
    T val = 418.9829 * dims;

    for (int i = 0; i < dims; ++i)
        val -= arr[i] * sin(sqrt(abs(arr[i])));

    return val;
}

// [-2.048, 2.048]
template <class T>
T rosenbrock(T* arr, int dims)
{
    T val = 0;

    for (int i = 0; i < dims-1; ++i)
    {
        T temp = 100* pow(arr[i+1] - pow(arr[i], 2.0), 2.0);
        val   -= temp + pow(arr[i] - 1, 2.0);
    }

    return val;
}

// [-10, 10]
template <class T>
T levy(T* arr, int dims)
{
    // get w(d) (here as it will never change)
    // w(i) = 1 + ((x(i) -1) / 4) for all i = 1, ..., d
    T wd = 1 + ((arr[dims-1] -1) / 4);

    // start the calculation
    T val = pow(sin(M_PI * w(arr[0])), 2.0);

    // calculate the sigma for 1,...,d
    for (int i = 0 ; i < dims-1; ++i)
    {
        // get w(i)
        T wi = 1 + ((arr[i] - 1)/4);

        // calculate the iteration's sigma
        T sigma = pow(wi-1, 2.0) * (1+10*pow(sin(M_PI*wi+1), 2.0));
        sigma  += pow(wi, 2.0) * (1+pow(sin(2*M_PI*wd), 2.0));

        // apply the delta
        val += sigma;
    }

    return val;
}
