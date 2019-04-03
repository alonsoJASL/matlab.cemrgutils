/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_scalarsthresholds_api.c
 *
 * Code generation for function '_coder_scalarsthresholds_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "_coder_scalarsthresholds_api.h"
#include "scalarsthresholds_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[53008];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[53008];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *c, const
  char_T *identifier))[53008];
static const mxArray *emlrt_marshallOut(const real_T u[53008]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[53008]
{
  real_T (*y)[53008];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[53008]
{
  real_T (*ret)[53008];
  static const int32_T dims[1] = { 53008 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[53008])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *c, const
  char_T *identifier))[53008]
{
  real_T (*y)[53008];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(c), &thisId);
  emlrtDestroyArray(&c);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u[53008])
{
  const mxArray *y;
  const mxArray *m7;
  static const int32_T iv9[1] = { 0 };

  static const int32_T iv10[1] = { 53008 };

  y = NULL;
  m7 = emlrtCreateNumericArray(1, iv9, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m7, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m7, iv10, 1);
  emlrtAssign(&y, m7);
  return y;
}

void scalarsthresholds_api(scalarsthresholdsStackData *SD, const mxArray * const
  prhs[1], int32_T nlhs, const mxArray *plhs[1])
{
  real_T (*cq)[53008];
  real_T (*c)[53008];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  cq = (real_T (*)[53008])mxMalloc(sizeof(real_T [53008]));

  /* Marshall function inputs */
  c = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "c");

  /* Invoke the target function */
  scalarsthresholds(SD, &st, *c, *cq);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*cq);
}

/* End of code generation (_coder_scalarsthresholds_api.c) */
