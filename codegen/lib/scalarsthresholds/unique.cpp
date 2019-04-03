//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unique.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "unique.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *b
//                int nb
//                int *nMInf
//                int *nFinite
//                int *nPInf
//                int *nNaN
// Return Type  : void
//
void count_nonfinites(const emxArray_real_T *b, int nb, int *nMInf, int *nFinite,
                      int *nPInf, int *nNaN)
{
  int k;
  k = 0;
  while ((k + 1 <= nb) && rtIsInf(b->data[k]) && (b->data[k] < 0.0)) {
    k++;
  }

  *nMInf = k;
  k = nb;
  while ((k >= 1) && rtIsNaN(b->data[k - 1])) {
    k--;
  }

  *nNaN = nb - k;
  while ((k >= 1) && rtIsInf(b->data[k - 1]) && (b->data[k - 1] > 0.0)) {
    k--;
  }

  *nPInf = (nb - k) - *nNaN;
  *nFinite = k - *nMInf;
}

//
// File trailer for unique.cpp
//
// [EOF]
//
