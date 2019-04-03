//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: im2uint8.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "im2uint8.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *img
//                unsigned char u_data[]
//                int u_size[1]
// Return Type  : void
//
void im2uint8(const emxArray_real_T *img, unsigned char u_data[], int u_size[1])
{
  int i3;
  int b_index;
  double val;
  u_size[0] = img->size[0];
  i3 = img->size[0];
  for (b_index = 0; b_index < i3; b_index++) {
    val = img->data[b_index] * 255.0;
    if (val < 0.0) {
      u_data[b_index] = 0U;
    } else if (val > 255.0) {
      u_data[b_index] = MAX_uint8_T;
    } else {
      u_data[b_index] = (unsigned char)(val + 0.5);
    }
  }
}

//
// File trailer for im2uint8.cpp
//
// [EOF]
//
