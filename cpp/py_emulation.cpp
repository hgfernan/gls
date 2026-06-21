/** *
 * File: py_emulation.cpp
 * Created: 2026-06-20 16:40:20
 * Purpose: Emulation of the file `main.py` by Rodrigo F. Díaz @exord
 * 
 * @author: @hgfernan
 */

#include <cmath> /// M_PI

#include <vector>
#include <numeric> /// std::iota()
#include <algorithm>
#include <iostream>

#include "vec_utils.hpp" /// several utilities for vectors

#include "arange.hpp" // arange()
#include "vec_stats.hpp" /// several statistical operations on vectors
#include "vec_operator.hpp" /// several operations on vectors and scalars

    // if prange is None:
    //     ## Construct prange from time array as in yorbit
    //     tsorted = np.sort(t)
    //     Pmax = 2*(t.max() - t.min())
    //     Pmin = np.max([0.25, np.median(np.diff(tsorted))])
    //     dnu = 0.25*np.min(np.diff( tsorted ) )

    //     NU = np.arange(1/Pmax, 1/Pmin, dnu)
    //     prange = 1/NU
    //     #np.arange(Pmin, Pmax + dnu, dnu)

    //     print('Using default values: Pmin: {pmin}; Pmax: {pmax}; '
    //           'dnu : {dnu}; {N} frequencies.'.format(pmin = Pmin, pmax = Pmax, 
    //                                                  dnu = dnu, N = len(prange)))

int main()
{
    std::vector<double> t(10);
    std::iota(t.begin(), t.end(), 0.0);
    print_vector(t, "After std::iota(): t");

    t = t * (2 * M_PI / 10);
    print_vector(t, "After multiplication by 2*pi/10: t");

    double p_max = 2.0 * ( *std::max_element(t.begin(), t.end()) );
    double p_min = std::max(0.25, median(self_difference(t)));
    std::cout << "p_max: " << p_max << "; p_min: " << p_min << std::endl;

    // std::vector<double> temp2(t.begin(), t.end() - 1);
    // print_vector(temp2, "t shortened: ");

    // std::vector<double> temp3(t.begin() + 1, t.end());
    // print_vector(temp3, "t lagged by 1: ");

    // std::vector<double> temp4 = difference(temp2, temp3);
    // print_vector(temp4, "differences of t and lag 1");

    std::vector<double> temp = self_difference(t);
    print_vector(temp, "After self_difference(t): ");

    double dnu = 0.25 * ( *std::min_element(temp.begin(), temp.end()) );
    std::cout << "dnu: " << dnu << std::endl;

    std::vector<double> nu = 
        arange(1.0 / p_max, 1.0 / p_min, dnu);
    print_vector(nu, "nu: ");

    std::vector<double> prange = 1.0 / nu;
    print_vector(prange, "prange: ");
    
    /// @remark Normal function termination
    return 0;
}