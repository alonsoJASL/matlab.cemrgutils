/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unique.c
 *
 * Code generation for function 'unique'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "unique.h"

/* Function Definitions */
void count_nonfinites(const emxArray_real_T *b, int32_T nb, int32_T *nMInf,
                      int32_T *nFinite, int32_T *nPInf, int32_T *nNaN)
{
  int32_T k;
  k = 0;
  while ((k + 1 <= nb) && muDoubleScalarIsInf(b->data[k]) && (b->data[k] < 0.0))
  {
    k++;
  }

  *nMInf = k;
  k = nb;
  while ((k >= 1) && muDoubleScalarIsNaN(b->data[k - 1])) {
    k--;
  }

  *nNaN = nb - k;
  while ((k >= 1) && muDoubleScalarIsInf(b->data[k - 1]) && (b->data[k - 1] >
          0.0)) {
    k--;
  }

  *nPInf = (nb - k) - *nNaN;
  *nFinite = k - *nMInf;
}

/* End of code generation (unique.c) */
