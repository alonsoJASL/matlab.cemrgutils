//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: any1.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "any1.h"

// Function Definitions

//
// Arguments    : const bool x_data[]
//                const int x_size[1]
// Return Type  : bool
//
bool any(const bool x_data[], const int x_size[1])
{
  bool y;
  int ix;
  bool exitg1;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x_size[0])) {
    if (x_data[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return y;
}

//
// File trailer for any1.cpp
//
// [EOF]
//
