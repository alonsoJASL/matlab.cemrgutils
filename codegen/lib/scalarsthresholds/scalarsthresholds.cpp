//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: scalarsthresholds.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "scalarsthresholds_emxutil.h"
#include "multithresh.h"

// Function Definitions

//
// Arguments    : const double c[53008]
//                double cq[53008]
// Return Type  : void
//
void scalarsthresholds(const double c[53008], double cq[53008])
{
  int trueCount;
  int i;
  emxArray_uint16_T *r0;
  emxArray_real_T *b_c;
  double ot1;
  emxArray_uint16_T *r1;
  double levs[2];
  emxArray_uint16_T *r2;
  int ix;
  trueCount = 0;
  for (i = 0; i < 53008; i++) {
    if (c[i] > 0.0) {
      trueCount++;
    }
  }

  emxInit_uint16_T(&r0, 1);
  i = r0->size[0];
  r0->size[0] = trueCount;
  emxEnsureCapacity_uint16_T(r0, i);
  trueCount = 0;
  for (i = 0; i < 53008; i++) {
    if (c[i] > 0.0) {
      r0->data[trueCount] = (unsigned short)(i + 1);
      trueCount++;
    }
  }

  emxInit_real_T(&b_c, 1);
  i = b_c->size[0];
  b_c->size[0] = r0->size[0];
  emxEnsureCapacity_real_T(b_c, i);
  trueCount = r0->size[0];
  for (i = 0; i < trueCount; i++) {
    b_c->data[i] = c[r0->data[i] - 1];
  }

  emxFree_uint16_T(&r0);
  ot1 = multithresh(b_c);
  trueCount = 0;
  for (i = 0; i < 53008; i++) {
    if (c[i] > ot1) {
      trueCount++;
    }
  }

  emxInit_uint16_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = trueCount;
  emxEnsureCapacity_uint16_T(r1, i);
  trueCount = 0;
  for (i = 0; i < 53008; i++) {
    if (c[i] > ot1) {
      r1->data[trueCount] = (unsigned short)(i + 1);
      trueCount++;
    }
  }

  i = b_c->size[0];
  b_c->size[0] = r1->size[0];
  emxEnsureCapacity_real_T(b_c, i);
  trueCount = r1->size[0];
  for (i = 0; i < trueCount; i++) {
    b_c->data[i] = c[r1->data[i] - 1];
  }

  emxFree_uint16_T(&r1);
  b_multithresh(b_c, levs);
  emxFree_real_T(&b_c);
  memset(&cq[0], 0, 53008U * sizeof(double));
  emxInit_uint16_T(&r2, 1);
  for (ix = 0; ix < 2; ix++) {
    trueCount = 0;
    for (i = 0; i < 53008; i++) {
      if (c[i] > levs[ix]) {
        trueCount++;
      }
    }

    i = r2->size[0];
    r2->size[0] = trueCount;
    emxEnsureCapacity_uint16_T(r2, i);
    trueCount = 0;
    for (i = 0; i < 53008; i++) {
      if (c[i] > levs[ix]) {
        r2->data[trueCount] = (unsigned short)(i + 1);
        trueCount++;
      }
    }

    trueCount = r2->size[0];
    for (i = 0; i < trueCount; i++) {
      cq[r2->data[i] - 1] = 1.0 + (double)ix;
    }
  }

  emxFree_uint16_T(&r2);
}

//
// File trailer for scalarsthresholds.cpp
//
// [EOF]
//
