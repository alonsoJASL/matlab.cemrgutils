/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsxfun.h
 *
 * Code generation for function 'bsxfun'
 *
 */

#ifndef BSXFUN_H
#define BSXFUN_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "scalarsthresholds_types.h"

/* Function Declarations */
extern void b_bsxfun(const real_T a[256], const real_T b[256], real_T c[65536]);
extern void bsxfun(real_T a, const real_T b[256], real_T c[256]);
extern void c_bsxfun(real_T a, const real_T b[65536], real_T c[65536]);

#endif

/* End of code generation (bsxfun.h) */
