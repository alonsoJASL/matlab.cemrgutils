/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * im2uint8.c
 *
 * Code generation for function 'im2uint8'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "im2uint8.h"
#include "libmwgrayto8.h"

/* Function Definitions */
void im2uint8(const emxArray_real_T *img, uint8_T u_data[], int32_T u_size[1])
{
  u_size[0] = img->size[0];
  grayto8_real64(&img->data[0], &u_data[0], (real_T)img->size[0]);
}

/* End of code generation (im2uint8.c) */
