//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: repmat.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "repmat.h"

// Function Definitions

//
// Arguments    : const double a[256]
//                double b[65536]
// Return Type  : void
//
void repmat(const double a[256], double b[65536])
{
  int jtilecol;
  for (jtilecol = 0; jtilecol < 256; jtilecol++) {
    memcpy(&b[jtilecol << 8], &a[0], sizeof(double) << 8);
  }
}

//
// File trailer for repmat.cpp
//
// [EOF]
//
