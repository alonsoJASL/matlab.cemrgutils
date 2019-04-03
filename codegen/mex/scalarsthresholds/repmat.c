/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "repmat.h"

/* Function Definitions */
void repmat(const real_T a[256], real_T b[65536])
{
  int32_T jtilecol;
  for (jtilecol = 0; jtilecol < 256; jtilecol++) {
    memcpy(&b[jtilecol << 8], &a[0], sizeof(real_T) << 8);
  }
}

/* End of code generation (repmat.c) */
