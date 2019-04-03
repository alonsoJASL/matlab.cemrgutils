/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_scalarsthresholds_mex.c
 *
 * Code generation for function '_coder_scalarsthresholds_mex'
 *
 */

/* Include files */
#include "scalarsthresholds.h"
#include "_coder_scalarsthresholds_mex.h"
#include "scalarsthresholds_terminate.h"
#include "_coder_scalarsthresholds_api.h"
#include "scalarsthresholds_initialize.h"
#include "scalarsthresholds_data.h"

/* Function Declarations */
static void scalarsthresholds_mexFunction(scalarsthresholdsStackData *SD,
  int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
static void scalarsthresholds_mexFunction(scalarsthresholdsStackData *SD,
  int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[1])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        17, "scalarsthresholds");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "scalarsthresholds");
  }

  /* Call the function. */
  scalarsthresholds_api(SD, prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  scalarsthresholdsStackData *c_scalarsthresholdsStackDataGlo = NULL;
  c_scalarsthresholdsStackDataGlo = (scalarsthresholdsStackData *)emlrtMxCalloc
    (1, 1U * sizeof(scalarsthresholdsStackData));
  mexAtExit(scalarsthresholds_atexit);

  /* Module initialization. */
  scalarsthresholds_initialize();

  /* Dispatch the entry-point. */
  scalarsthresholds_mexFunction(c_scalarsthresholdsStackDataGlo, nlhs, plhs,
    nrhs, prhs);

  /* Module termination. */
  scalarsthresholds_terminate();
  emlrtMxFree(c_scalarsthresholdsStackDataGlo);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_scalarsthresholds_mex.c) */
