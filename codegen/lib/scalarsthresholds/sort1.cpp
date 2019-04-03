//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sort1.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "sort1.h"
#include "scalarsthresholds_emxutil.h"
#include "sortIdx.h"

// Function Definitions

//
// Arguments    : emxArray_real_T *x
// Return Type  : void
//
void sort(emxArray_real_T *x)
{
  emxArray_int32_T *idx;
  int i6;
  int ib;
  int n;
  int b_n;
  double x4[4];
  unsigned short idx4[4];
  emxArray_int32_T *iwork;
  unsigned short unnamed_idx_0;
  emxArray_real_T *xwork;
  int nNaNs;
  int k;
  signed char perm[4];
  int quartetOffset;
  int i1;
  int i2;
  int i4;
  double d3;
  double d4;
  emxInit_int32_T(&idx, 2);
  i6 = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(idx, i6);
  ib = x->size[1];
  for (i6 = 0; i6 < ib; i6++) {
    idx->data[i6] = 0;
  }

  n = x->size[1];
  b_n = x->size[1];
  x4[0] = 0.0;
  idx4[0] = 0U;
  x4[1] = 0.0;
  idx4[1] = 0U;
  x4[2] = 0.0;
  idx4[2] = 0U;
  x4[3] = 0.0;
  idx4[3] = 0U;
  emxInit_int32_T(&iwork, 1);
  unnamed_idx_0 = (unsigned short)x->size[1];
  i6 = iwork->size[0];
  iwork->size[0] = unnamed_idx_0;
  emxEnsureCapacity_int32_T(iwork, i6);
  ib = unnamed_idx_0;
  for (i6 = 0; i6 < ib; i6++) {
    iwork->data[i6] = 0;
  }

  emxInit_real_T(&xwork, 1);
  unnamed_idx_0 = (unsigned short)x->size[1];
  i6 = xwork->size[0];
  xwork->size[0] = unnamed_idx_0;
  emxEnsureCapacity_real_T(xwork, i6);
  ib = unnamed_idx_0;
  for (i6 = 0; i6 < ib; i6++) {
    xwork->data[i6] = 0.0;
  }

  nNaNs = 0;
  ib = -1;
  for (k = 0; k < b_n; k++) {
    if (rtIsNaN(x->data[k])) {
      i6 = (b_n - nNaNs) - 1;
      idx->data[i6] = k + 1;
      xwork->data[i6] = x->data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib] = (unsigned short)(k + 1);
      x4[ib] = x->data[k];
      if (ib + 1 == 4) {
        quartetOffset = k - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          ib = 3;
          i4 = 4;
        } else {
          ib = 4;
          i4 = 3;
        }

        d3 = x4[i1 - 1];
        d4 = x4[ib - 1];
        if (d3 <= d4) {
          if (x4[i2 - 1] <= d4) {
            perm[0] = (signed char)i1;
            perm[1] = (signed char)i2;
            perm[2] = (signed char)ib;
            perm[3] = (signed char)i4;
          } else if (x4[i2 - 1] <= x4[i4 - 1]) {
            perm[0] = (signed char)i1;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i1;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          d4 = x4[i4 - 1];
          if (d3 <= d4) {
            if (x4[i2 - 1] <= d4) {
              perm[0] = (signed char)ib;
              perm[1] = (signed char)i1;
              perm[2] = (signed char)i2;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)ib;
              perm[1] = (signed char)i1;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)i2;
            }
          } else {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i4;
            perm[2] = (signed char)i1;
            perm[3] = (signed char)i2;
          }
        }

        i6 = perm[0] - 1;
        idx->data[quartetOffset - 3] = idx4[i6];
        i4 = perm[1] - 1;
        idx->data[quartetOffset - 2] = idx4[i4];
        i1 = perm[2] - 1;
        idx->data[quartetOffset - 1] = idx4[i1];
        ib = perm[3] - 1;
        idx->data[quartetOffset] = idx4[ib];
        x->data[quartetOffset - 3] = x4[i6];
        x->data[quartetOffset - 2] = x4[i4];
        x->data[quartetOffset - 1] = x4[i1];
        x->data[quartetOffset] = x4[ib];
        ib = -1;
      }
    }
  }

  i6 = (b_n - nNaNs) - 1;
  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib + 1 == 1) {
      perm[0] = 1;
    } else if (ib + 1 == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (k = 0; k <= ib; k++) {
      i4 = perm[k] - 1;
      i1 = (i6 - ib) + k;
      idx->data[i1] = idx4[i4];
      x->data[i1] = x4[i4];
    }
  }

  ib = (nNaNs >> 1) + 1;
  for (k = 0; k <= ib - 2; k++) {
    i1 = (i6 + k) + 1;
    i2 = (unsigned short)idx->data[i1];
    i4 = (b_n - k) - 1;
    idx->data[i1] = (unsigned short)idx->data[i4];
    idx->data[i4] = i2;
    x->data[i1] = xwork->data[i4];
    x->data[i4] = xwork->data[i1];
  }

  if ((nNaNs & 1) != 0) {
    i6 += ib;
    x->data[i6] = xwork->data[i6];
  }

  i2 = n - nNaNs;
  ib = 2;
  if (i2 > 1) {
    if (n >= 256) {
      i1 = i2 >> 8;
      if (i1 > 0) {
        for (ib = 0; ib < i1; ib++) {
          merge_pow2_block(idx, x, ib << 8);
        }

        ib = i1 << 8;
        i1 = i2 - ib;
        if (i1 > 0) {
          merge_block(idx, x, ib, i1, 2, iwork, xwork);
        }

        ib = 8;
      }
    }

    merge_block(idx, x, 0, i2, ib, iwork, xwork);
  }

  emxFree_real_T(&xwork);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&idx);
}

//
// File trailer for sort1.cpp
//
// [EOF]
//
