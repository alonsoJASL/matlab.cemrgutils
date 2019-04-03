//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eps.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include <cmath>
#include <math.h>
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "eps.h"

// Function Definitions

//
// Arguments    : double x
// Return Type  : double
//
double eps(double x)
{
  double r;
  double absxk;
  int exponent;
  absxk = std::abs(x);
  if ((!rtIsInf(absxk)) && (!rtIsNaN(absxk))) {
    if (absxk <= 2.2250738585072014E-308) {
      r = 4.94065645841247E-324;
    } else {
      frexp(absxk, &exponent);
      r = std::ldexp(1.0, exponent - 53);
    }
  } else {
    r = rtNaN;
  }

  return r;
}

//
// File trailer for eps.cpp
//
// [EOF]
//
