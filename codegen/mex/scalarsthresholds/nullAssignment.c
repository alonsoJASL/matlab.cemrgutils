/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nullAssignment.c
 *
 * Code generation for function 'nullAssignment'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "nullAssignment.h"
#include "scalarsthresholds_emxutil.h"

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = { 12, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 16, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 183,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 84,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

/* Function Definitions */
void nullAssignment(const emlrtStack *sp, emxArray_real_T *x, const boolean_T
                    idx_data[], const int32_T idx_size[2])
{
  int32_T k;
  int32_T nxin;
  int32_T k0;
  int32_T nxout;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
  k = idx_size[1];
  while ((k >= 1) && (!idx_data[k - 1])) {
    k--;
  }

  if (k > x->size[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &ec_emlrtRTEI,
      "MATLAB:subsdeldimmismatch", "MATLAB:subsdeldimmismatch", 0);
  }

  st.site = &cd_emlrtRSI;
  nxin = x->size[1];
  k0 = 0;
  nxout = idx_size[1];
  for (k = 0; k < nxout; k++) {
    k0 += idx_data[k];
  }

  nxout = x->size[1] - k0;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > idx_size[1]) || (!idx_data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  if (nxout > nxin) {
    emlrtErrorWithMessageIdR2018a(&st, &dc_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > nxout) {
    x->size[1] = 0;
  } else {
    k0 = x->size[0] * x->size[1];
    x->size[1] = nxout;
    emxEnsureCapacity_real_T(&st, x, k0, &wb_emlrtRTEI);
  }
}

/* End of code generation (nullAssignment.c) */
