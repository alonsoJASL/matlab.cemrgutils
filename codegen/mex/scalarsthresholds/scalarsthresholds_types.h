/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * scalarsthresholds_types.h
 *
 * Code generation for function 'scalarsthresholds'
 *
 */

#ifndef SCALARSTHRESHOLDS_TYPES_H
#define SCALARSTHRESHOLDS_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef struct_emxArray_uint16_T
#define struct_emxArray_uint16_T

struct emxArray_uint16_T
{
  uint16_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint16_T*/

#ifndef typedef_emxArray_uint16_T
#define typedef_emxArray_uint16_T

typedef struct emxArray_uint16_T emxArray_uint16_T;

#endif                                 /*typedef_emxArray_uint16_T*/

#ifndef typedef_scalarsthresholdsStackData
#define typedef_scalarsthresholdsStackData

typedef struct {
  struct {
    real_T mu_0_t[65536];
    real_T omega1[65536];
    real_T allPixC[65536];
    real_T b_allPixC[65536];
    real_T mu_1_t[65536];
    real_T dv3[65536];
    real_T sigma_b_squared[65536];
    real_T omega2[65536];
  } f0;

  struct {
    real_T sigma_b_squared[65536];
    boolean_T b_sigma_b_squared[65536];
  } f1;
} scalarsthresholdsStackData;

#endif                                 /*typedef_scalarsthresholdsStackData*/
#endif

/* End of code generation (scalarsthresholds_types.h) */
