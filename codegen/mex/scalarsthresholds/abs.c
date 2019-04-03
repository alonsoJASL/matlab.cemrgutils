/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "abs.h"
#include "scalarsthresholds_emxutil.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = { 16,  /* lineNo */
  "abs",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elfun/abs.m"/* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elfun/abs.m"/* pName */
};

/* Function Definitions */
void b_abs(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T nx;
  uint16_T x_idx_0;
  int32_T k;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &r_emlrtRSI;
  nx = x->size[0];
  x_idx_0 = (uint16_T)x->size[0];
  k = y->size[0];
  y->size[0] = x_idx_0;
  emxEnsureCapacity_real_T(&st, y, k, &k_emlrtRTEI);
  for (k = 0; k < nx; k++) {
    y->data[k] = muDoubleScalarAbs(x->data[k]);
  }
}

/* End of code generation (abs.c) */
