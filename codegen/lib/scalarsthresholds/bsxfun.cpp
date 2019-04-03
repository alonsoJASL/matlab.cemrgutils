//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsxfun.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "bsxfun.h"

// Function Definitions

//
// Arguments    : const double a[256]
//                const double b[256]
//                double c[65536]
// Return Type  : void
//
void b_bsxfun(const double a[256], const double b[256], double c[65536])
{
  int k;
  int b_k;
  for (k = 0; k < 256; k++) {
    for (b_k = 0; b_k < 256; b_k++) {
      c[b_k + (k << 8)] = a[k] - b[b_k];
    }
  }
}

//
// Arguments    : double a
//                const double b[256]
//                double c[256]
// Return Type  : void
//
void bsxfun(double a, const double b[256], double c[256])
{
  int k;
  for (k = 0; k < 256; k++) {
    c[k] = a - b[k];
  }
}

//
// Arguments    : double a
//                const double b[65536]
//                double c[65536]
// Return Type  : void
//
void c_bsxfun(double a, const double b[65536], double c[65536])
{
  int k;
  int b_k;
  int c_tmp;
  for (k = 0; k < 256; k++) {
    for (b_k = 0; b_k < 256; b_k++) {
      c_tmp = b_k + (k << 8);
      c[c_tmp] = a - b[c_tmp];
    }
  }
}

//
// File trailer for bsxfun.cpp
//
// [EOF]
//
