//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "mean.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
//                double y[2]
// Return Type  : void
//
void mean(const emxArray_real_T *x, double y[2])
{
  int vlen;
  int k;
  int xpageoffset;
  vlen = x->size[0];
  if (x->size[0] == 0) {
    y[0] = 0.0;
    y[1] = 0.0;
  } else {
    y[0] = x->data[0];
    for (k = 2; k <= vlen; k++) {
      y[0] += x->data[k - 1];
    }

    xpageoffset = x->size[0];
    y[1] = x->data[xpageoffset];
    for (k = 2; k <= vlen; k++) {
      y[1] += x->data[(xpageoffset + k) - 1];
    }
  }

  vlen = x->size[0];
  y[0] /= (double)vlen;
  y[1] /= (double)vlen;
}

//
// File trailer for mean.cpp
//
// [EOF]
//
