/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsxfun.c
 *
 * Code generation for function 'bsxfun'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "bsxfun.h"

/* Function Definitions */
void b_bsxfun(const real_T a[256], const real_T b[256], real_T c[65536])
{
  int32_T k;
  int32_T b_k;
  for (k = 0; k < 256; k++) {
    for (b_k = 0; b_k < 256; b_k++) {
      c[b_k + (k << 8)] = a[k] - b[b_k];
    }
  }
}

void bsxfun(real_T a, const real_T b[256], real_T c[256])
{
  int32_T k;
  for (k = 0; k < 256; k++) {
    c[k] = a - b[k];
  }
}

void c_bsxfun(real_T a, const real_T b[65536], real_T c[65536])
{
  int32_T k;
  int32_T b_k;
  int32_T c_tmp;
  for (k = 0; k < 256; k++) {
    for (b_k = 0; b_k < 256; b_k++) {
      c_tmp = b_k + (k << 8);
      c[c_tmp] = a - b[c_tmp];
    }
  }
}

/* End of code generation (bsxfun.c) */
