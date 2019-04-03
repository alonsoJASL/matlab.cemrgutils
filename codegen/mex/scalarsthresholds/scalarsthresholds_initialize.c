/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * scalarsthresholds_initialize.c
 *
 * Code generation for function 'scalarsthresholds_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "scalarsthresholds_initialize.h"
#include "_coder_scalarsthresholds_mex.h"
#include "scalarsthresholds_data.h"

/* Function Declarations */
static void scalarsthresholds_once(void);

/* Function Definitions */
static void scalarsthresholds_once(void)
{
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/jsl19/Documents/MATLAB/matlab.scarmeasures/scalarsthresholds.m",
                  0U, 1U, 2U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "scalarsthresholds", 0, -1, 208);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 171, -1, 196);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 41, -1, 142);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 145, 167, 201);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void scalarsthresholds_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Image_Toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    scalarsthresholds_once();
  }
}

/* End of code generation (scalarsthresholds_initialize.c) */
