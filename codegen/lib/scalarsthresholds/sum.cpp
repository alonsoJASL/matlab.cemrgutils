//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sum.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "sum.h"

// Function Definitions

//
// Arguments    : const double x[256]
// Return Type  : double
//
double sum(const double x[256])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 255; k++) {
    y += x[k + 1];
  }

  return y;
}

//
// File trailer for sum.cpp
//
// [EOF]
//
