/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "mean.h"

/* Function Definitions */
void mean(const emxArray_real_T *x, real_T y[2])
{
  int32_T vlen;
  int32_T k;
  int32_T xpageoffset;
  vlen = x->size[0];
  if (x->size[0] == 0) {
    y[0] = 0.0;
    y[1] = 0.0;
  } else {
    y[0] = x->data[0];
    for (k = 2; k <= vlen; k++) {
      y[0] += x->data[k - 1];
    }

    xpageoffset = x->size[0];
    y[1] = x->data[xpageoffset];
    for (k = 2; k <= vlen; k++) {
      y[1] += x->data[(xpageoffset + k) - 1];
    }
  }

  vlen = x->size[0];
  y[0] /= (real_T)vlen;
  y[1] /= (real_T)vlen;
}

/* End of code generation (mean.c) */
