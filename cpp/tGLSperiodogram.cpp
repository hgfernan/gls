/** *
 * File: tGLSperiodogram.cpp
 * Created: 2026-06-15 23:34:24
 * Purpose: Testing of the C++ implementation of Generalised Lomb-Scargle Periodogram
 * 
 * @author: @hgfernan
 */
#include <cmath> // M_PI, cos(), sin()

#include <vector>
#include <random> // class random_device, class mt19937, class uniform_real_distribution
#include <iostream>

#include "GLSperiodogram.h" // GLS()

int main(int argc, char* const* argv)
{
    // void GLS  (double* prange, int nfreq, double* x, double *y, double* w, int ndata, double* gls);

    /// @remark set RNG seed for repeatable pseudorandom number generation
    std::mt19937 gen((1 << 23) - 1);

    std::uniform_real_distribution<> dis(-0.5, +0.5);

    for (int n = 0; n < 10; ++n) {
        std::cout << dis(gen) << ' ';
    }

    std::cout << '\n';

    /// @remark Normal function termination
    return 0;
}

