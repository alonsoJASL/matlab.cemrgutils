//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsxfun.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//
#ifndef BSXFUN_H
#define BSXFUN_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "scalarsthresholds_types.h"

// Function Declarations
extern void b_bsxfun(const double a[256], const double b[256], double c[65536]);
extern void bsxfun(double a, const double b[256], double c[256]);
extern void c_bsxfun(double a, const double b[65536], double c[65536]);

#endif

//
// File trailer for bsxfun.h
//
// [EOF]
//
