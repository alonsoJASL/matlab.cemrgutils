/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * scalarsthresholds.c
 *
 * Code generation for function 'scalarsthresholds'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "scalarsthresholds_emxutil.h"
#include "multithresh.h"
#include "scalarsthresholds_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 4,     /* lineNo */
  "scalarsthresholds",                 /* fcnName */
  "/home/jsl19/Documents/MATLAB/matlab.scarmeasures/scalarsthresholds.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 5,   /* lineNo */
  "scalarsthresholds",                 /* fcnName */
  "/home/jsl19/Documents/MATLAB/matlab.scarmeasures/scalarsthresholds.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  17,                                  /* colNo */
  "scalarsthresholds",                 /* fName */
  "/home/jsl19/Documents/MATLAB/matlab.scarmeasures/scalarsthresholds.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 4, /* lineNo */
  19,                                  /* colNo */
  "scalarsthresholds",                 /* fName */
  "/home/jsl19/Documents/MATLAB/matlab.scarmeasures/scalarsthresholds.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 5, /* lineNo */
  20,                                  /* colNo */
  "scalarsthresholds",                 /* fName */
  "/home/jsl19/Documents/MATLAB/matlab.scarmeasures/scalarsthresholds.m"/* pName */
};

/* Function Definitions */
void scalarsthresholds(scalarsthresholdsStackData *SD, const emlrtStack *sp,
  const real_T c[53008], real_T cq[53008])
{
  int32_T trueCount;
  int32_T i;
  emxArray_uint16_T *r0;
  emxArray_real_T *b_c;
  real_T ot1;
  emxArray_uint16_T *r1;
  real_T levs[2];
  emxArray_uint16_T *r2;
  int32_T ix;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /*   */
  trueCount = 0;
  for (i = 0; i < 53008; i++) {
    if (c[i] > 0.0) {
      trueCount++;
    }
  }

  emxInit_uint16_T(sp, &r0, 1, &emlrtRTEI, true);
  i = r0->size[0];
  r0->size[0] = trueCount;
  emxEnsureCapacity_uint16_T(sp, r0, i, &emlrtRTEI);
  trueCount = 0;
  for (i = 0; i < 53008; i++) {
    if (c[i] > 0.0) {
      r0->data[trueCount] = (uint16_T)(i + 1);
      trueCount++;
    }
  }

  emxInit_real_T(sp, &b_c, 1, &b_emlrtRTEI, true);
  i = b_c->size[0];
  b_c->size[0] = r0->size[0];
  emxEnsureCapacity_real_T(sp, b_c, i, &b_emlrtRTEI);
  trueCount = r0->size[0];
  for (i = 0; i < trueCount; i++) {
    b_c->data[i] = c[r0->data[i] - 1];
  }

  emxFree_uint16_T(&r0);
  st.site = &emlrtRSI;
  ot1 = multithresh(&st, b_c);
  trueCount = 0;
  for (i = 0; i < 53008; i++) {
    if (c[i] > ot1) {
      trueCount++;
    }
  }

  emxInit_uint16_T(sp, &r1, 1, &emlrtRTEI, true);
  i = r1->size[0];
  r1->size[0] = trueCount;
  emxEnsureCapacity_uint16_T(sp, r1, i, &emlrtRTEI);
  trueCount = 0;
  for (i = 0; i < 53008; i++) {
    if (c[i] > ot1) {
      r1->data[trueCount] = (uint16_T)(i + 1);
      trueCount++;
    }
  }

  i = b_c->size[0];
  b_c->size[0] = r1->size[0];
  emxEnsureCapacity_real_T(sp, b_c, i, &c_emlrtRTEI);
  trueCount = r1->size[0];
  for (i = 0; i < trueCount; i++) {
    b_c->data[i] = c[r1->data[i] - 1];
  }

  emxFree_uint16_T(&r1);
  st.site = &b_emlrtRSI;
  b_multithresh(SD, &st, b_c, levs);
  emxFree_real_T(&b_c);
  memset(&cq[0], 0, 53008U * sizeof(real_T));
  emxInit_uint16_T(sp, &r2, 1, &emlrtRTEI, true);
  for (ix = 0; ix < 2; ix++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
    trueCount = 0;
    for (i = 0; i < 53008; i++) {
      if (c[i] > levs[ix]) {
        trueCount++;
      }
    }

    i = r2->size[0];
    r2->size[0] = trueCount;
    emxEnsureCapacity_uint16_T(sp, r2, i, &emlrtRTEI);
    trueCount = 0;
    for (i = 0; i < 53008; i++) {
      if (c[i] > levs[ix]) {
        r2->data[trueCount] = (uint16_T)(i + 1);
        trueCount++;
      }
    }

    trueCount = r2->size[0];
    for (i = 0; i < trueCount; i++) {
      cq[r2->data[i] - 1] = 1.0 + (real_T)ix;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_uint16_T(&r2);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (scalarsthresholds.c) */
