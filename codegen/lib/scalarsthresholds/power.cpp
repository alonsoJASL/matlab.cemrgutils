//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: power.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "power.h"

// Function Definitions

//
// Arguments    : const double a[65536]
//                double y[65536]
// Return Type  : void
//
void power(const double a[65536], double y[65536])
{
  int k;
  for (k = 0; k < 65536; k++) {
    y[k] = a[k] * a[k];
  }
}

//
// File trailer for power.cpp
//
// [EOF]
//
