/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort1.c
 *
 * Code generation for function 'sort1'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "sort1.h"
#include "sortIdx.h"
#include "scalarsthresholds_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalarsthresholds_data.h"

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = { 72,  /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 105, /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 308,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 316,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 317,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 325,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 392,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 420,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 427,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 56,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 105,/* lineNo */
  40,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 308,/* lineNo */
  14,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 308,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

/* Function Definitions */
void sort(const emlrtStack *sp, emxArray_real_T *x)
{
  emxArray_int32_T *idx;
  int32_T i7;
  int32_T ib;
  int32_T n;
  int32_T b_n;
  real_T x4[4];
  uint16_T idx4[4];
  emxArray_int32_T *iwork;
  uint16_T unnamed_idx_0;
  emxArray_real_T *xwork;
  int32_T nNaNs;
  int32_T k;
  int8_T perm[4];
  int32_T quartetOffset;
  int32_T i1;
  int32_T i2;
  int32_T i4;
  real_T d3;
  real_T d4;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &idx, 2, &sb_emlrtRTEI, true);
  st.site = &x_emlrtRSI;
  i7 = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(&st, idx, i7, &pb_emlrtRTEI);
  ib = x->size[1];
  for (i7 = 0; i7 < ib; i7++) {
    idx->data[i7] = 0;
  }

  b_st.site = &y_emlrtRSI;
  n = x->size[1];
  c_st.site = &ab_emlrtRSI;
  b_n = x->size[1];
  x4[0] = 0.0;
  idx4[0] = 0U;
  x4[1] = 0.0;
  idx4[1] = 0U;
  x4[2] = 0.0;
  idx4[2] = 0U;
  x4[3] = 0.0;
  idx4[3] = 0U;
  emxInit_int32_T(&c_st, &iwork, 1, &tb_emlrtRTEI, true);
  unnamed_idx_0 = (uint16_T)x->size[1];
  i7 = iwork->size[0];
  iwork->size[0] = unnamed_idx_0;
  emxEnsureCapacity_int32_T(&c_st, iwork, i7, &qb_emlrtRTEI);
  ib = unnamed_idx_0;
  for (i7 = 0; i7 < ib; i7++) {
    iwork->data[i7] = 0;
  }

  emxInit_real_T(&c_st, &xwork, 1, &ub_emlrtRTEI, true);
  unnamed_idx_0 = (uint16_T)x->size[1];
  i7 = xwork->size[0];
  xwork->size[0] = unnamed_idx_0;
  emxEnsureCapacity_real_T(&c_st, xwork, i7, &rb_emlrtRTEI);
  ib = unnamed_idx_0;
  for (i7 = 0; i7 < ib; i7++) {
    xwork->data[i7] = 0.0;
  }

  nNaNs = 0;
  ib = -1;
  d_st.site = &fb_emlrtRSI;
  for (k = 0; k < b_n; k++) {
    if (muDoubleScalarIsNaN(x->data[k])) {
      i7 = (b_n - nNaNs) - 1;
      idx->data[i7] = k + 1;
      xwork->data[i7] = x->data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib] = (uint16_T)(k + 1);
      x4[ib] = x->data[k];
      if (ib + 1 == 4) {
        quartetOffset = k - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          ib = 3;
          i4 = 4;
        } else {
          ib = 4;
          i4 = 3;
        }

        d3 = x4[i1 - 1];
        d4 = x4[ib - 1];
        if (d3 <= d4) {
          if (x4[i2 - 1] <= d4) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i2;
            perm[2] = (int8_T)ib;
            perm[3] = (int8_T)i4;
          } else if (x4[i2 - 1] <= x4[i4 - 1]) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else {
          d4 = x4[i4 - 1];
          if (d3 <= d4) {
            if (x4[i2 - 1] <= d4) {
              perm[0] = (int8_T)ib;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i2;
              perm[3] = (int8_T)i4;
            } else {
              perm[0] = (int8_T)ib;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i4;
              perm[3] = (int8_T)i2;
            }
          } else {
            perm[0] = (int8_T)ib;
            perm[1] = (int8_T)i4;
            perm[2] = (int8_T)i1;
            perm[3] = (int8_T)i2;
          }
        }

        i7 = perm[0] - 1;
        idx->data[quartetOffset - 3] = idx4[i7];
        i4 = perm[1] - 1;
        idx->data[quartetOffset - 2] = idx4[i4];
        i1 = perm[2] - 1;
        idx->data[quartetOffset - 1] = idx4[i1];
        ib = perm[3] - 1;
        idx->data[quartetOffset] = idx4[ib];
        x->data[quartetOffset - 3] = x4[i7];
        x->data[quartetOffset - 2] = x4[i4];
        x->data[quartetOffset - 1] = x4[i1];
        x->data[quartetOffset] = x4[ib];
        ib = -1;
      }
    }
  }

  i7 = (b_n - nNaNs) - 1;
  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib + 1 == 1) {
      perm[0] = 1;
    } else if (ib + 1 == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    d_st.site = &gb_emlrtRSI;
    if (ib + 1 > 2147483646) {
      e_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 0; k <= ib; k++) {
      i4 = perm[k] - 1;
      i1 = (i7 - ib) + k;
      idx->data[i1] = idx4[i4];
      x->data[i1] = x4[i4];
    }
  }

  ib = (nNaNs >> 1) + 1;
  d_st.site = &hb_emlrtRSI;
  for (k = 0; k <= ib - 2; k++) {
    i1 = (i7 + k) + 1;
    i2 = (uint16_T)idx->data[i1];
    i4 = (b_n - k) - 1;
    idx->data[i1] = (uint16_T)idx->data[i4];
    idx->data[i4] = i2;
    x->data[i1] = xwork->data[i4];
    x->data[i4] = xwork->data[i1];
  }

  if ((nNaNs & 1) != 0) {
    i7 += ib;
    x->data[i7] = xwork->data[i7];
  }

  i2 = n - nNaNs;
  ib = 2;
  if (i2 > 1) {
    if (n >= 256) {
      i1 = i2 >> 8;
      if (i1 > 0) {
        c_st.site = &bb_emlrtRSI;
        for (ib = 0; ib < i1; ib++) {
          c_st.site = &cb_emlrtRSI;
          merge_pow2_block(idx, x, ib << 8);
        }

        ib = i1 << 8;
        i1 = i2 - ib;
        if (i1 > 0) {
          c_st.site = &db_emlrtRSI;
          merge_block(&c_st, idx, x, ib, i1, 2, iwork, xwork);
        }

        ib = 8;
      }
    }

    c_st.site = &eb_emlrtRSI;
    merge_block(&c_st, idx, x, 0, i2, ib, iwork, xwork);
  }

  emxFree_real_T(&xwork);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&idx);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sort1.c) */
