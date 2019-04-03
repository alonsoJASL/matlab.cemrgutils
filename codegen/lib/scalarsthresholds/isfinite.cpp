//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isfinite.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "isfinite.h"

// Function Definitions

//
// Arguments    : double x
// Return Type  : bool
//
bool b_isfinite(double x)
{
  return (!rtIsInf(x)) && (!rtIsNaN(x));
}

//
// File trailer for isfinite.cpp
//
// [EOF]
//
