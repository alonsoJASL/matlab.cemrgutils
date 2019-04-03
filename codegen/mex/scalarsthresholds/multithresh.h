/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * multithresh.h
 *
 * Code generation for function 'multithresh'
 *
 */

#ifndef MULTITHRESH_H
#define MULTITHRESH_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "scalarsthresholds_types.h"

/* Function Declarations */
extern void b_multithresh(scalarsthresholdsStackData *SD, const emlrtStack *sp,
  const emxArray_real_T *varargin_1, real_T thresh[2]);
extern real_T multithresh(const emlrtStack *sp, const emxArray_real_T
  *varargin_1);

#endif

/* End of code generation (multithresh.h) */
