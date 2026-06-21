/** *
 * File: GLSperiodogram.h
 * Created: 2026-06-15 23:35:00
 * Purpose: C++ implementation of Generalised Lomb-Scargle Periodogram -- header
 * 
 * @author: Rodrigo F. Díaz @exord
 */

extern "C" {
    void GLS  (double* prange, int nfreq, double* x, double *y, double* w, int ndata, double* gls);
}

