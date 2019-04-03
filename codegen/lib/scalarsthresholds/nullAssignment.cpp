//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nullAssignment.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "nullAssignment.h"
#include "scalarsthresholds_emxutil.h"

// Function Definitions

//
// Arguments    : emxArray_real_T *x
//                const bool idx_data[]
//                const int idx_size[2]
// Return Type  : void
//
void nullAssignment(emxArray_real_T *x, const bool idx_data[], const int
                    idx_size[2])
{
  int nxin;
  int k0;
  int i8;
  int k;
  int nxout;
  nxin = x->size[1];
  k0 = 0;
  i8 = idx_size[1];
  for (k = 0; k < i8; k++) {
    k0 += idx_data[k];
  }

  nxout = x->size[1] - k0;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > idx_size[1]) || (!idx_data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  if (1 > nxout) {
    x->size[1] = 0;
  } else {
    i8 = x->size[0] * x->size[1];
    x->size[1] = nxout;
    emxEnsureCapacity_real_T(x, i8);
  }
}

//
// File trailer for nullAssignment.cpp
//
// [EOF]
//
