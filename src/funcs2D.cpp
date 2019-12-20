#include <cmath>
#include "funcs2D.h"

// 2-D functions
namespace funcs2D
{
    // [-10, 10]
    template <typename T>
    T crossInTray(T* arr)
    {
        T val = sin(arr[0])*sin(arr[1]);
        val *= exp(abs(100 - (sqr(pow(arr[0], 2.0)+pow(arr[1], 2.0)))/M_PI));
        val = pow(abs(val) + 1, 0.1);

        val *= -0.0001;
        return val;
    }


    // [-100, 100]
    template <typename T>
    T easom(T* arr)
    {
        T val = -cos(arr[0])*cos(arr[1]);
        val *= exp(-pow((arr[0]-M_PI), 2.0) - pow(arr[1] - M_PI));

        return val;
    }
}
