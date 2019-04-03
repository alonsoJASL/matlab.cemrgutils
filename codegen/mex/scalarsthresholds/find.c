/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "find.h"
#include "scalarsthresholds_emxutil.h"
#include "indexShapeCheck.h"

/* Variable Definitions */
static emlrtRSInfo ld_emlrtRSI = { 147,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 252,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 251,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 250,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 147,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 250,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 251,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

/* Function Definitions */
void eml_find(const emlrtStack *sp, const boolean_T x[65536], emxArray_int32_T
              *i, emxArray_int32_T *j)
{
  int32_T idx;
  int32_T ii;
  int32_T jj;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv8[2];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ld_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idx = 0;
  ii = i->size[0];
  i->size[0] = 65536;
  emxEnsureCapacity_int32_T(&st, i, ii, &mb_emlrtRTEI);
  ii = j->size[0];
  j->size[0] = 65536;
  emxEnsureCapacity_int32_T(&st, j, ii, &mb_emlrtRTEI);
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 256)) {
    guard1 = false;
    if (x[(ii + ((jj - 1) << 8)) - 1]) {
      idx++;
      i->data[idx - 1] = ii;
      j->data[idx - 1] = jj;
      if (idx >= 65536) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
      if (ii > 256) {
        ii = 1;
        jj++;
      }
    }
  }

  if (1 > idx) {
    ii = 0;
  } else {
    ii = idx;
  }

  iv8[0] = 1;
  iv8[1] = ii;
  b_st.site = &od_emlrtRSI;
  indexShapeCheck(&b_st, 65536, iv8);
  jj = i->size[0];
  i->size[0] = ii;
  emxEnsureCapacity_int32_T(&st, i, jj, &nb_emlrtRTEI);
  if (1 > idx) {
    ii = 0;
  } else {
    ii = idx;
  }

  iv8[0] = 1;
  iv8[1] = ii;
  b_st.site = &nd_emlrtRSI;
  indexShapeCheck(&b_st, 65536, iv8);
  jj = j->size[0];
  j->size[0] = ii;
  emxEnsureCapacity_int32_T(&st, j, jj, &ob_emlrtRTEI);
  if (1 > idx) {
    idx = 0;
  }

  iv8[0] = 1;
  iv8[1] = idx;
  b_st.site = &md_emlrtRSI;
  indexShapeCheck(&b_st, 65536, iv8);
}

/* End of code generation (find.c) */
