//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: abs.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "abs.h"
#include "scalarsthresholds_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
//                emxArray_real_T *y
// Return Type  : void
//
void b_abs(const emxArray_real_T *x, emxArray_real_T *y)
{
  int nx;
  unsigned short x_idx_0;
  int k;
  nx = x->size[0];
  x_idx_0 = (unsigned short)x->size[0];
  k = y->size[0];
  y->size[0] = x_idx_0;
  emxEnsureCapacity_real_T(y, k);
  for (k = 0; k < nx; k++) {
    y->data[k] = std::abs(x->data[k]);
  }
}

//
// File trailer for abs.cpp
//
// [EOF]
//
