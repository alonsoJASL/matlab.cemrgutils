//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortLE.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "sortLE.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *v
//                int idx1
//                int idx2
// Return Type  : bool
//
bool sortLE(const emxArray_real_T *v, int idx1, int idx2)
{
  bool p;
  if ((v->data[idx1 - 1] <= v->data[idx2 - 1]) || rtIsNaN(v->data[idx2 - 1])) {
    p = true;
  } else {
    p = false;
  }

  return p;
}

//
// File trailer for sortLE.cpp
//
// [EOF]
//
