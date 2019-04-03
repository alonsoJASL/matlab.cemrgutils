//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ndgrid.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "ndgrid.h"

// Function Definitions

//
// Arguments    : const double varargin_1[256]
//                const double varargin_2[256]
//                double varargout_1[65536]
//                double varargout_2[65536]
// Return Type  : void
//
void ndgrid(const double varargin_1[256], const double varargin_2[256], double
            varargout_1[65536], double varargout_2[65536])
{
  int k;
  int b_k;
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

//
// File trailer for ndgrid.cpp
//
// [EOF]
//
