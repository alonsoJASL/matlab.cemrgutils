/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortLE.c
 *
 * Code generation for function 'sortLE'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "sortLE.h"

/* Function Definitions */
boolean_T sortLE(const emxArray_real_T *v, int32_T idx1, int32_T idx2)
{
  boolean_T p;
  if ((v->data[idx1 - 1] <= v->data[idx2 - 1]) || muDoubleScalarIsNaN(v->
       data[idx2 - 1])) {
    p = true;
  } else {
    p = false;
  }

  return p;
}

/* End of code generation (sortLE.c) */
