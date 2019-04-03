//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mergesort.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "mergesort.h"
#include "sortLE.h"
#include "scalarsthresholds_emxutil.h"

// Function Definitions

//
// Arguments    : emxArray_int32_T *idx
//                const emxArray_real_T *x
//                int n
// Return Type  : void
//
void b_mergesort(emxArray_int32_T *idx, const emxArray_real_T *x, int n)
{
  emxArray_int32_T *iwork;
  int i;
  int k;
  int i2;
  int j;
  int pEnd;
  int p;
  int q;
  int qEnd;
  int kEnd;
  emxInit_int32_T(&iwork, 1);
  i = iwork->size[0];
  iwork->size[0] = idx->size[0];
  emxEnsureCapacity_int32_T(iwork, i);
  i = n - 1;
  for (k = 1; k <= i; k += 2) {
    if (sortLE(x, k, k + 1)) {
      idx->data[k - 1] = k;
      idx->data[k] = k + 1;
    } else {
      idx->data[k - 1] = k + 1;
      idx->data[k] = k;
    }
  }

  if ((n & 1) != 0) {
    idx->data[n - 1] = n;
  }

  i = 2;
  while (i < n) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < n + 1; pEnd = qEnd + i) {
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n + 1) {
        qEnd = n + 1;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        if (sortLE(x, idx->data[p - 1], idx->data[q - 1])) {
          iwork->data[k] = idx->data[p - 1];
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork->data[k] = idx->data[q - 1];
              q++;
            }
          }
        } else {
          iwork->data[k] = idx->data[q - 1];
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork->data[k] = idx->data[p - 1];
              p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k < kEnd; k++) {
        idx->data[(j + k) - 1] = iwork->data[k];
      }

      j = qEnd;
    }

    i = i2;
  }

  emxFree_int32_T(&iwork);
}

//
// File trailer for mergesort.cpp
//
// [EOF]
//
