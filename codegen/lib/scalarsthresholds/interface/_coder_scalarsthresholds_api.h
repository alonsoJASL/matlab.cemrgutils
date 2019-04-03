/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_scalarsthresholds_api.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 03-Apr-2019 12:46:07
 */

#ifndef _CODER_SCALARSTHRESHOLDS_API_H
#define _CODER_SCALARSTHRESHOLDS_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_scalarsthresholds_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void scalarsthresholds(real_T c[53008], real_T cq[53008]);
extern void scalarsthresholds_api(const mxArray * const prhs[1], int32_T nlhs,
  const mxArray *plhs[1]);
extern void scalarsthresholds_atexit(void);
extern void scalarsthresholds_initialize(void);
extern void scalarsthresholds_terminate(void);
extern void scalarsthresholds_xil_terminate(void);

#endif

/*
 * File trailer for _coder_scalarsthresholds_api.h
 *
 * [EOF]
 */
