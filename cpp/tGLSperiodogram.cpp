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
#include <algorithm> // fill()

#include "GLSperiodogram.h" // GLS()

int main(int argc, char* const* argv)
{
    size_t nfreq = 10;
    size_t ndata = 100;
    double* prange;
    double* x;
    double* y;
    double* w;
    double* gls;

    // void GLS  (double* prange, int nfreq, double* x, double *y, double* w, int ndata, double* gls);

    /// @remark set RNG seed for repeatable pseudorandom number generation
    std::mt19937 gen((1 << 23) - 1);

    std::uniform_real_distribution<> dis(-0.5, +0.5);

    for (int n = 0; n < 10; ++n) {
        std::cout << dis(gen) << ' ';
    }

    std::cout << '\n';

    /// @remark Allocate memory for arrays
    prange = new double[nfreq];
    x    = new double[ndata]; 
    y    = new double[ndata];
    w    = new double[ndata];
    gls  = new double[nfreq];

    /// @todo initialize arrays with values
    std::fill(w, w + ndata, 1);
    std::fill(gls, gls + nfreq, 0);

    size_t ind;
    for (ind = 0; ind < ndata; ++ind) {
        x[ind] = (3 * M_PI * ind) / (ndata - 1);
        y[ind] = 4*sin(x[ind]) + dis(gen); 
    }

    for (ind = 0; ind < nfreq; ++ind) {
        prange[ind] = 1.0 / (ind + 1);
    }

    /// @todo estimate the periodogram using GLS()
    GLS(prange, nfreq, x, y, w, ndata, gls);

    std::cout << "Periodogram results\n" 
              << "Sequence\tFrequency\tSpectrum" 
              << std::endl
    ;
    /// @todo print the results
    for (ind = 0; ind < nfreq; ind++) {
        std::cout << '\t' << ind << '\t' 
                  << (1.0 / prange[ind]) << '\t' << gls[ind]
                  << std::endl
        ;
    }

    /// @todo plot the results

    /// @remark Deallocate memory of the arrays
    delete[] prange;
    delete[] x;
    delete[] y;
    delete[] w;
    delete[] gls;

    /// @remark Normal function termination
    return 0;
}

