/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mergesort.c
 *
 * Code generation for function 'mergesort'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "mergesort.h"
#include "scalarsthresholds_emxutil.h"
#include "sortLE.h"

/* Variable Definitions */
static emlrtRTEInfo u_emlrtRTEI = { 1, /* lineNo */
  20,                                  /* colNo */
  "mergesort",                         /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 52,/* lineNo */
  1,                                   /* colNo */
  "mergesort",                         /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

/* Function Definitions */
void b_mergesort(const emlrtStack *sp, emxArray_int32_T *idx, const
                 emxArray_real_T *x, int32_T n)
{
  emxArray_int32_T *iwork;
  int32_T i;
  int32_T k;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &iwork, 1, &vb_emlrtRTEI, true);
  i = iwork->size[0];
  iwork->size[0] = idx->size[0];
  emxEnsureCapacity_int32_T(sp, iwork, i, &u_emlrtRTEI);
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
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mergesort.c) */
