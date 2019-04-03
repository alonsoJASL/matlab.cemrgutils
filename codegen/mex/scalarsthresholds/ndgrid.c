/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ndgrid.c
 *
 * Code generation for function 'ndgrid'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "ndgrid.h"

/* Function Definitions */
void ndgrid(const real_T varargin_1[256], const real_T varargin_2[256], real_T
            varargout_1[65536], real_T varargout_2[65536])
{
  int32_T k;
  int32_T b_k;
  for (k = 0; k < 256; k++) {
    for (b_k = 0; b_k < 256; b_k++) {
      varargout_1[b_k + (k << 8)] = varargin_1[b_k];
    }
  }

  for (k = 0; k < 256; k++) {
    for (b_k = 0; b_k < 256; b_k++) {
      varargout_2[b_k + (k << 8)] = varargin_2[k];
    }
  }
}

/* End of code generation (ndgrid.c) */
